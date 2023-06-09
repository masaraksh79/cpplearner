#include <iostream>

typedef unsigned int uint;
#define MONTHS    12
#define MAX_DAYS_IN_MONTH 31

namespace dateutils {

class Dates
{
public:
   Dates(): day{1}, month{1}, year{1970} {}
   Dates(uint d,uint m,uint y): day{d}, month{m}, year{y} {}
   Dates(uint d): day{d}, month{0}, year{0} {}
   uint getDay() const { return day; }
   uint getMonth() const { return month; }
   uint getYear() const { return year; }
   //operators
   Dates operator+(const Dates& rhs) noexcept;
   Dates& operator=(const Dates& rhs) noexcept;
   friend std::ostream& operator<<(std::ostream& os, const Dates& d);
private:
      uint days_in_months[MONTHS + 1] = { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
      uint day, month, year;
      void setDate(Dates d) noexcept{
         day = d.day, month = d.month, year = d.year;
      }
};

std::ostream& operator<<(std::ostream& os, const Dates& d)
{
   os << "[" << d.day << "," << d.month << "," << d.year << "]";    
   return os;
}

Dates Dates::operator+(const Dates& rhs) noexcept
{
   Dates lhs, temp;
   uint d = this->day + rhs.getDay();

   assert(this->month <= MONTHS);
   assert(this->month > 0);

   if (d > days_in_months[this->month])
   {
      temp.day = this->day += (rhs.getDay() + 1 - (d - days_in_months[this->month]) );

      this->month = rhs.getMonth();

      if (++this->month >= MONTHS)
      {
         this->month = 1;
         this->year = rhs.getYear();
         temp.year = ++this->year;
      }

      temp.month = this->month;
   }
   else
   {
      temp.day += rhs.getDay();
      temp.month = rhs.getMonth();
      temp.year = rhs.getYear();
   }

   assert(temp.day <= MAX_DAYS_IN_MONTH);
   assert(temp.month <= MONTHS);

   lhs.setDate(temp);
   return lhs;
}

Dates& Dates::operator=(const Dates& rhs) noexcept
{
   this->day = rhs.getDay();
   this->month = rhs.getMonth();
   this->year = rhs.getYear();
   return *this;
}


} // namespace dateutils

using namespace dateutils;

int main()
{
   Dates d1(14, 9, 1994);
   Dates d2;

   d2 = d1 + 30;
   std::cout << "Thirty days on from " << d1 << " is " << d2 << std::endl;
}