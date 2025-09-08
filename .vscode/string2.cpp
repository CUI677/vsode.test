
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <assert.h>
#include <string.h>
using namespace std;
namespace MyString
{
    class string
    {
    private:
        char *_str = nullptr;
        size_t _size = 0;
        size_t _capacity = 0;
        const static  size_t npos = -1;

    public:
        typedef char *iterator;
        typedef const char *const_iterator;
        string()
            : _str(new char[1]{'\0'}), _size(0), _capacity(0)
        {
        }
        string(const string &s)
            : _str(new char[s._capacity + 1]), _size(s._size), _capacity(s._capacity)
        {
            strcpy(_str, s._str);
        }
        string(const char *str) // 这里不走初始化列表初始化是因为初始化列表是根据成员变量的声明顺序来初始化的
        {
            assert(str);
            _size = strlen(str);
            _capacity = _size;
            _str = new char[_capacity + 1];
            strcpy(_str, str);
        }
        /*string(const char* str)
        {
            assert(str);
            string temp(str);
            swap(_str, temp._str);
            swap(_size, temp._size);
            swap(_capacity, temp._capacity);
        }*/
        // 现代写法
        // 赋值的新写法
        /*string& operator=(const string& s)
        {
            if (this != &s)
            {
                string temp(s);
                swap(_str, temp._str);
                swap(_size, temp._size);
                swap(_capacity, temp._capacity);
            }
            return *this;
        }*/
        /*还有一种写法一句话就可以搞定*/
        /*string& operator=(string temp)
        {
            swap(temp);
            return *this;
        }*/
        void swap(string &s)
        {
            std::swap(_str, s._str);
            std::swap(_size, s._size);
            std::swap(_capacity, s._capacity);
        }
        ~string()
        {
            delete[] _str;
            _size = 0;
            _capacity = 0;
        }
        const char *c_str() const
        {
            return _str;
        }
        size_t size() const
        {
            return _size;
        }
        size_t capacity() const
        {
            return _capacity;
        }
        char &operator[](size_t pos)
        {
            assert(pos < _size);
            return _str[pos];
        }
        const char &operator[](size_t pos) const
        {
            assert(pos < _size);
            return _str[pos];
        }
        iterator begin()
        {
            return _str;
        }
        iterator end()
        {
            return _str + _size;
        }
        const_iterator begin() const
        {
            return _str;
        }
        const_iterator end() const
        {
            return _str + _size;
        }
        void push_back(char ch);
        void reserve(size_t n);
        string &operator+=(char ch);
        void append(const char *str);
        string &operator+=(const char *str);
        void insert(size_t pos, char ch);
        void insert(size_t pos, const char *str);
        void erase(size_t pos, size_t len);
        size_t find(size_t pos, char ch);
        size_t find(size_t pos, const char *str);
        void clear();
        string substr(size_t pos, size_t len) const;
    };
    void test_string1();
    void test_string2();
}

namespace MyString
{
    void test_string1()
    {
        string s1;
        string s2("hello world");
        cout << s2.c_str() << endl;
        cout << s1.c_str() << endl;
    }
    void test_string2()
    {
        char n = 'n';
        string s2("hello world");
        s2 += n;
        cout << s2.c_str();
        s2 += "!!!";
        cout << s2.c_str() << endl;
        s2.insert(5, "abcde");
        cout << s2.c_str() << endl;
    }
    void string::reserve(size_t n)
    {
        if (n > _capacity)
        {
            char *tem = new char[n + 1];
            strcpy(tem, _str);
            delete[] _str;
            _str = tem;
            _capacity = n;
        }
    }
    void string::push_back(char ch)
    {
        if (_size == _capacity)
        {
            reserve(_capacity == 0 ? 4 : 2 * _capacity);
        }
        _str[_size] = ch;
        ++_size;
        _str[_size] = '\0';
    }
    string &string::operator+=(char ch)
    {
        push_back(ch);
        return *this;
    }
    void string::append(const char *str)
    {
        assert(str);
        size_t len = strlen(str);
        if (_size + len > _capacity)
        {
            reserve(_size + len);
        }
        strcpy(_str + _size, str);
        _size += len;
    }
    string &string::operator+=(const char *str)
    {
        append(str);
        return *this;
    }
    void MyString::string::insert(size_t pos, char ch)
    {
        assert(pos <= _size);
        if (_size == _capacity)
        {
            reserve(_capacity == 0 ? 4 : 2 * _capacity);
        }
        for (size_t i = _size; i > pos; --i)
        {
            _str[i] = _str[i - 1];
        }
        _str[pos] = ch;
        ++_size;
        _str[_size] = '\0';
    }
    void MyString::string::insert(size_t pos, const char *str)
    {
        assert(pos <= _size);
        assert(str);
        size_t len = strlen(str);
        if (_size + len > _capacity)
        {
            reserve(_size + len); // reserve在实现的时候会单开字符0的空间，所以这里不需要+1；
        }
        size_t i = _size + len;
        for (i; i > pos + len - 1; --i)
        {
            _str[i] = _str[i - len];
        }
        for (size_t j = 0; j < len; ++j)
        {
            _str[pos + j] = str[j];
        }
        _size += len; // 用memmove和memcpy效率会更高
        _str[_size] = '\0';
    }
    void MyString::string::erase(size_t pos, size_t len)
    {
        if (len >= _size - pos)
        {
            _str[pos] = '\0';
            _size = pos;
        }
        else
        {
            for (size_t i = pos; i < _size - len; ++i)
            {
                _str[i] = _str[i + len];
            }
        }
        _size -= len;
        _str[_size] = '\0';
    }
    size_t MyString::string::find(size_t pos, char ch)
    {
        for (size_t i = pos; i < _size; ++i)
        {
            if (_str[i] == ch)
            {
                cout << "find char " << ch << " in position " << i << endl;
                return i;
            }
            else
            {
                cout << "not find char " << ch << endl;
                return npos;
            }
        }
    }
    size_t MyString::string::find(size_t pos, const char *str)
    {
        strstr(_str + pos, str);
        if (strstr(_str + pos, str))
        {
            size_t index = (size_t)(strstr(_str + pos, str) - _str);
            cout << "find string " << str << " in position " << index << endl;
            return index;
        }
        else
        {
            cout << "not find string " << str << endl;
            return npos;
        }
    }
    void MyString::string::clear()
    {
        _size = 0;
        if (_str)
        {
            _str[0] = '\0';
        }
    }
    string string::substr(size_t pos, size_t len = npos) const
    {
        assert(pos < _size);
        if (len > _size - pos)
        {
            len = _size - pos;
        }
        string ret;

        ret.reserve(len);
        for (size_t i = 0; i < len; ++i)
        {
            ret.push_back(_str[pos + i]);
        }

        return ret;
    }
}
int main()
{
    MyString::test_string1();
    MyString::test_string2();
}