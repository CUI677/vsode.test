#include <iostream>
namespace MyVector
{
    template <class T>
    class Vector
    {
    public:
        typedef T *iterator;
        typedef const T *const_iterator;
        iterator begin()
        {
            return _start;
        }
        const_iterator begin() const
        {
            return _start;
        }
        iterator end()
        {
            return _finish;
        }
        const_iterator end() const
        {
            return _finish;
        }
        size_t size() const
        {
            return _finish - _start;
        }
        size_t capacity() const
        {
            return _end_of_storage - _start;
        }
        void reserve(size_t n)
        {
            if (n > capacity())
            {
                T *newstart = new T[n];
                size_t oldsize = size();
                memcpy(newstart, _start, sizeof(T) * size());
                delete[] _start;
                _start = newstart;
                _finish = _start + oldsize; // 后来检查出有问题，因为size()用的是_finish-_start，所以必须先更新size
                _end_of_storage = _start + n;
            }
        }
        void push_back(const T &val)
        {
            if (_finish != _end_of_storage)
            {
                *_finish = val;
                ++_finish;
            }
            else
            {
                reserve(capacity() == 0 ? 4 : 2 * capacity());
                *_finish = val;
                ++_finish;
            }
        }

    private:
        iterator _start = nullptr;
        iterator _finish = nullptr;
        iterator _end_of_storage = nullptr;
    };
    template <class T>
    void print_vector(const Vector<T> &v)
    {
        // 注意这里不能用v.size()，因为size()是非静态成员函数
        // 注意这里前面要加typename，因为T是模板参数，编译器不知道T是不是类型
        // 没有实例化的类模板里面去取嵌套依赖类型的时候，必须加typename
         typename Vector<T>::iterator it = v.begin();
        for (; it != v.end(); ++it)
        {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }
}
int main()
{
    return 0;
}