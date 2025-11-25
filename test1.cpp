#define _CRT_SECURE_NO_WARNINGS // 禁用 strcpy 等函数的安全警告
#include <iostream>
#include <cstring>
using std::cout;
using std::endl;

// 自定义 MyString 类
class MyString
{
public:
    // 构造函数 1：从 C 字符串构造
    MyString(const char *s)
    {
        length = (int)strlen(s);     // 获取字符串长度
        sptr = new char[length + 1]; // 分配动态内存（+1 存放 '\0'）
        strcpy(sptr, s);             // 拷贝字符串内容
    }

    // 构造函数 2：拷贝构造函数
    MyString(MyString &s1)
    {
        length = s1.length;          // 复制长度
        sptr = new char[length + 1]; // 分配新的内存空间
        strcpy(sptr, s1.sptr);       // 深拷贝字符串内容
    }

    // 构造函数 3：按指定大小构造空字符串
    MyString(int size = 80)
    {
        length = size;               // 设置长度
        sptr = new char[length + 1]; // 分配内存
        *sptr = '\0';                // 初始化为空字符串
    }

    // 析构函数：释放动态内存
    ~MyString()
    {
        delete[] sptr; // 释放 sptr 指向的动态数组
    }

    // 成员函数：获取字符串长度
    int getlen()
    {
        return length;
    }

    // 成员函数：打印字符串
    void print()
    {
        cout << sptr << endl;
    }

private:
    char *sptr; // 指向动态分配的字符数组
    int length; // 字符串长度
};

// 主函数
int main()
{
    cout << "====== 字符串类测试程序 ======" << endl
         << endl;

    // 测试 1：用字符串常量构造对象 str1
    MyString str1("This is a string.");
    cout << "str1 的内容: ";
    str1.print();
    cout << "str1 的长度: " << str1.getlen() << endl
         << endl;

    // 测试 2：用 char* 构造对象 str2
    const char *s1 = "That is a program.";
    MyString str2(s1);
    cout << "str2 的内容: ";
    str2.print();
    cout << "str2 的长度: " << str2.getlen() << endl
         << endl;

    // 测试 3：用拷贝构造函数构造对象 str3
    MyString str3(str2);
    cout << "str3 的内容: ";
    str3.print();
    cout << "str3 的长度: " << str3.getlen() << endl
         << endl;

    cout << "====== 程序执行完毕 ======" << endl;

    return 0;
}
