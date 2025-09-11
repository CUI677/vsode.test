#include <iostream>
 using namespace std;
 class date
 {
 private:
     const int _a;

 public:
     date(int a = 10): _a(a)

     {
     }
     void Print() const
     {
          cout << _a<< "-"<< endl;
         
     }
 };
 int main() {
     date d;
     d.Print();
     return 0;
 } 
 //在初始化列表后面有赋值的时候，会赋值，没有的话会调用声明的时候的缺省值，要是没有声明，就是随机值。