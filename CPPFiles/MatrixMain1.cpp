/*
 *	MatrixMain1.cpp
 *		Program to be completed by students.
 */
#include <iostream>
#include <cassert>

using namespace std;

#define MAX_ROWS (2)
#define MAX_COLS (3)

class Matrix
{
public:
   //Default constructor
   Matrix() {printed = 0;empty(); cout << "No arg constructor!" << "// ObjCount=" << ++objcount << "\n"; } 
   //Converting constructor (should be explicit)
   Matrix(const int value);
   //Copy constructor
   Matrix(const Matrix& m);
   //Destructor
   ~Matrix() { cout << "Destroying" << "// ObjCount=" << --objcount << endl; }
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
   friend ostream& operator<<(ostream& os, const Matrix& m);

private:
   int mtx[MAX_ROWS][MAX_COLS];
   mutable int printed;
};

Matrix::Matrix(const int value)
{
   cout << "Creating " << value << "// ObjCount=" << ++objcount << "\n";
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

int Matrix::objcount = 0;

int main()
{
	Matrix m1, m2, m3;

   cout << __cplusplus << endl;

	m1.empty();
	m2.empty();

	m1.setElement(0, 0, 10);
	m1.setElement(0, 1, 20);
	m1.setElement(0, 2, 30);
	m1.setElement(1, 0, 40);
	m1.setElement(1, 1, 50);
	m1.setElement(1, 2, 60);

	m2.setElement(0, 0, 30);
	m2.setElement(0, 1, 50);
	m2.setElement(0, 2, 70);
	m2.setElement(1, 0, 10);
	m2.setElement(1, 1, 60);
   m2.setElement(1, 2, 90);

	std::cout << "\nMatrix m1 is ";
	m1.print();

	std::cout << "\nMatrix m2 is ";
	m2.print();

   m3 = m1 + m2;
	std::cout << "\nMatrix m1 is now m1+m2 is ";
	m3.print();

   if (m1 == m2)
      std::cout << "\nMatrices are the same!";
   else
      std::cout << "\nMatrices are different!";

   Matrix m6;
   Matrix m7(55);
	std::cout << "\nMatrix m7 is initialized with same value in all cells\n";
   m7.print();

   const Matrix zeros(0);
   std::cout << "\nMatrix zeros is printed through marked print method\n";
   zeros.print();
   zeros.print();
   zeros.print();

   cout << m7;

   Matrix m8 = m1 - m2;
   std::cout << "\nMatrix printed is subtraction of m1-m2\n";
   m8.print();

	return 0;
}
