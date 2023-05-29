#ifndef _MATRIX_HPP
#define _MATRIX_HPP

#include <iostream>

using namespace std;

#define MAX_ROWS (2)
#define MAX_COLS (3)
#define MAX_CELLS (MAX_ROWS*MAX_COLS)

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
   bool operator==(const Matrix& rhs) const;
   bool operator!=(const Matrix& rhs) const;
   Matrix& operator+=(const Matrix& rhs);
   int& operator[](int cell);
   int operator[](int cell) const;
   friend ostream& operator<<(ostream& os, const Matrix& m);

private:
   int mtx[MAX_ROWS][MAX_COLS];
   mutable int printed;
};

#endif