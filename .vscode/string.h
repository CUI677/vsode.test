#pragma once
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
        const static const size_t npos = -1;

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
