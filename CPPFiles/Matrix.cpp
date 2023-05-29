#include "Matrix.hpp"

int Matrix::objcount = 0;

Matrix::Matrix() 
{
   printed = 0;
   empty(); 
   cout << "No arg constructor!" << "// ObjCount=" << ++Matrix::objcount << "\n"; 
} 

Matrix::~Matrix() { cout << "Destroying" << "// ObjCount=" << --Matrix::objcount << endl; }

Matrix::Matrix(const int value)
{
   cout << "Creating " << value << "// ObjCount=" << ++Matrix::objcount << "\n";
   printed = 0;
   for (int i = 0; i < MAX_ROWS; i++)
      for (int j = 0; j < MAX_COLS; j++)
         mtx[i][j] = value;
}

Matrix::Matrix(const Matrix& m)
{
   cout << "Creating by a copy constructor" << "// ObjCount=" << ++objcount << endl;
   printed = 0;
   for (int i = 0; i < MAX_ROWS; i++)
      for (int j = 0; j < MAX_COLS; j++)
         mtx[i][j] = m.mtx[i][j];
}

void Matrix::empty()
{
   for (int i = 0; i < MAX_ROWS; i++)
      for (int j = 0; j < MAX_COLS; j++)
         mtx[i][j] = 0;
}

void Matrix::print(void) const
{
   cout << endl;
   
   for (int i = 0; i < MAX_ROWS; i++)
   {
      for (int j = 0; j < MAX_COLS; j++)
         cout << mtx[i][j] << " ";
   
      cout << endl; //not just prints eol but flushes
   }

   cout << "Printed #" << ++printed << " times\n";
}

void Matrix::setElement(int row, int col, int value)
{
   assert(row < MAX_ROWS);
   assert(col < MAX_COLS);

   mtx[row][col] = value;
}

const int Matrix::getElement(int row, int col) const
{
   assert(row < MAX_ROWS);
   assert(col < MAX_COLS);

   return mtx[row][col];
}

Matrix Matrix::operator+(const Matrix& rhs)
{
   Matrix lhs;

   for (int i = 0; i < MAX_ROWS; i++) {
      for (int j = 0; j < MAX_COLS; j++) {
         lhs.setElement(i, j, mtx[i][j] + rhs.getElement(i,j) );
      }
   }
   return lhs;
}

Matrix Matrix::operator-(const Matrix& rhs)
{
   Matrix lhs;

   for (int i = 0; i < MAX_ROWS; i++) {
      for (int j = 0; j < MAX_COLS; j++) {
         lhs.setElement(i, j, mtx[i][j] - rhs.getElement(i,j) );
      }
   }
   return lhs;
}


bool Matrix::operator==(const Matrix& rhs)
{
   for (int i = 0; i < MAX_ROWS; i++) {
      for (int j = 0; j < MAX_COLS; j++) {
         if (mtx[i][j] != rhs.getElement(i,j))
         {
            return false;
         }
      }
   }
   return true;
}

bool Matrix::operator!=(const Matrix& rhs)
{
   return !this->operator==(rhs);
}

ostream& operator<<(ostream& os, const Matrix& m)
{
   os << endl;
   
   for (int i = 0; i < MAX_ROWS; i++)
   {
      for (int j = 0; j < MAX_COLS; j++)
         os << m.getElement(i,j) << " ";
   
      os << endl; //not just prints eol but flushes
   }

   os << "Printed #" << ++m.printed << " times\n";
    
   return os;
}

Matrix& Matrix::operator+=(const Matrix& rhs)
{
    for (int i = 0; i < MAX_ROWS; i++)
       for (int j = 0; j < MAX_COLS; j++)
          mtx[i][j] = mtx[i][j] + rhs.getElement(i,j);

    return *this;
}