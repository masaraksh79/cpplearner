#ifndef _MATRIX_HPP
#define _MATRIX_HPP

#include <iostream>

using namespace std;

#define MAX_ROWS (2)
#define MAX_COLS (3)

class Matrix
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
   static int objcount;
   Matrix operator+(const Matrix& rhs);
   Matrix operator-(const Matrix& rhs);
   bool operator==(const Matrix& rhs);
   bool operator!=(const Matrix& rhs);
   Matrix& operator+=(const Matrix& rhs);
   int& operator[](int row);  // return col1 value per given row
   friend ostream& operator<<(ostream& os, const Matrix& m);

private:
   int mtx[MAX_ROWS][MAX_COLS];
   mutable int printed;
};

#endif