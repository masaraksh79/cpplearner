#include "Matrix.hpp"

int Matrix::objcount = 0;

Matrix::Matrix() 
{
   printed = 0;
   empty(); 
   cout << "No arg constructor!" << "// ObjCount=" << ++Matrix::objcount << "\n"; 
} 

Matrix::~Matrix() { /* cout << "Destroying" << "// ObjCount=" << --Matrix::objcount << endl; */ }

Matrix::Matrix(const int value)
{
   cout << "Creating " << value << "// ObjCount=" << ++Matrix::objcount << "\n";
   printed = 0;
   for (int i = 0; i < MAX_ROWS; i++)
      for (int j = 0; j < MAX_COLS; j++)
         mtx.at(i).at(j) = value;
}

Matrix::Matrix(const Matrix& m)
{
   cout << "Creating by a copy constructor" << "// ObjCount=" << ++objcount << endl;
   printed = 0;
   mtx = m.mtx; 
}

void Matrix::empty()
{
   for (int i = 0; i < MAX_ROWS; i++)
      for (int j = 0; j < MAX_COLS; j++)
         mtx.at(i).at(j) = 0;
}

void Matrix::print(void) const
{
   cout << endl;
   
   for (int i = 0; i < MAX_ROWS; i++)
   {
      for (int j = 0; j < MAX_COLS; j++)
         cout << mtx.at(i).at(j) << " ";
   
      cout << endl; //not just prints eol but flushes
   }

   cout << "Printed #" << ++printed << " times\n";
}

void Matrix::setElement(int row, int col, int value)
{
   mtx.at(row).at(col) = value;
}

const int Matrix::getElement(int row, int col) const
{
   return mtx.at(row).at(col);
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


bool Matrix::operator==(const Matrix& rhs) const
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

bool Matrix::operator!=(const Matrix& rhs) const
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

int& Matrix::operator[](int cell)
{
   assert(cell < MAX_CELLS);

   int curr_row = cell / (MAX_ROWS + 1);
   int curr_off = cell % (MAX_ROWS + 1);
   int* pr = &mtx[curr_row][0];

   return *(pr + curr_off);
}

int Matrix::operator[](int cell) const
{
   assert(cell < MAX_CELLS);

   const int curr_row = cell / (MAX_ROWS + 1);
   const int curr_off = cell % (MAX_ROWS + 1);
   const int* pr = &mtx[curr_row][0];
   const int* p = pr + curr_off;

   return *p;
}

// using this operator can be done as
// cout << m(1,0)
// m(1,0) = 8 with this case because operator used on left it becomes the l-value
int& Matrix::operator()(int row, int col)
{
   assert(row < MAX_ROWS);
   assert(col < MAX_COLS);
   return this->mtx[row][col];
}

int Matrix::operator()(int row, int col) const
{
   assert(row < MAX_ROWS);
   assert(col < MAX_COLS);
   return this->mtx[row][col];
}

Matrix& Matrix::operator=(const Matrix& rhs)
{
   for (int i = 0; i < MAX_ROWS; i++) {
      for (int j = 0; j < MAX_COLS; j++) {
         this->mtx[i][j] = rhs.getElement(i,j);
      }
   }

   return *this;
}

