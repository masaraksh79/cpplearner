#ifndef _MATRIX_HPP
#define _MATRIX_HPP

#include <iostream>
#include <array>

using namespace std;

#define MAX_ROWS (2)
#define MAX_COLS (3)
#define MAX_CELLS (MAX_ROWS*MAX_COLS)

class Object
{
public:
   virtual void trace() { cout << "Here is " << nameOf() << endl; }
   virtual string nameOf() = 0;
};

class MatrixBoundException: public exception
{
public:
   virtual const char* what() const noexcept
   {
      return "Row or Column are larger than allowed!";
   }
};

class Matrix : public Object
{
public:
   //Default constructor
   Matrix();
   //Converting constructor (should be explicit)
   Matrix(const int value);
   //Copy constructor
   Matrix(const Matrix& m);
   //Destructor
   ~Matrix();
   //User methods
   void empty();
   void print(void) const;
   void setElement(int row, int col, int value = 0);
   const int getElement(int row, int col) const;
   Matrix addMatrix(const Matrix othermatrix) const;
   Matrix operator+(const Matrix& rhs);
   Matrix operator-(const Matrix& rhs);
   bool operator==(const Matrix& rhs) const noexcept;
   bool operator!=(const Matrix& rhs) const noexcept;
   Matrix& operator+=(const Matrix& rhs);
   int& operator[](int cell) noexcept;
   int operator[](int cell) const noexcept;
   int& operator()(int row, int col);
   int operator()(int row, int col) const;
   Matrix& operator=(const Matrix& rhs) noexcept;
   //The ugly
   static int objcount;
   friend ostream& operator<<(ostream& os, const Matrix& m);
   //Overriding methods of MatrixParent
   std::string nameOf() { return "Matrix"; }
   void trace() { cout << "Here is " << nameOf() << endl; }
private:
   std::array<std::array <int,MAX_COLS>,MAX_ROWS> mtx;
   mutable int printed;
};

#endif