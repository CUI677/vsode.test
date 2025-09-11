#include <iostream>
 using namespace std;
 class date
 {
 private:
     int _year = 10;
     int _month=100;
     int _day=1000;

 public:
     date(int year, int month, int day) : _year(year),
                                          _month(month),
                                          _day(day)
     {
     }
     void Print() const
     {
          cout << _year << "-" << _month << "-" << _day << endl;
         
     }
 };
 int main() {
     date d(2023, 10, 5);
     d.print();
     return 0;
 } 