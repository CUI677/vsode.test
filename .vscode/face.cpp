#include <iostream>
 using namespace std;
 class date
 {
 private:
     int _year = 10;
     int _month=100;
     int _day;

 public:
     date(int year, int month=0, int day=0) : _year(year)
                                          
                                          
     {
     }
     void Print() const
     {
          cout << _year << "-" << _month << "-" << _day << endl;
         
     }
 };
 int main() {
     date d(100);
     d.Print();
     return 0;
 } 