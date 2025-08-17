#include <iostream>
 using namespace std;
 class date
 {
 private:
     int _year = 10;
     int _month=100;
     int _day;

 public:
     date(int year, int month, int day):_year(year),_month(month)
                                          
                                          
     {
     }
     void Print() const
     {
          cout << _year << "-" << _month << "-" << _day << endl;
         
     }
 };
 int main() {
     date d(100,100,100);
     d.Print();
     return 0;
 } 
 //在初始化列表后面有赋值的时候，会赋值，没有的话会调用声明的时候的缺省值，要是没有声明，就是随机值。