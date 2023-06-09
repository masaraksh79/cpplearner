#ifndef _MATRIX_HPP
#define _MATRIX_HPP

#include <iostream>
#include <array>
#include <cassert>
#include <initializer_list>

using namespace std;

namespace utils {

template <class T, int R, int C>
class Matrix;

template <class T, int R, int C>
ostream& operator<<(ostream& os, const Matrix<T,R,C>& m)
{
   os << endl;
   
   for (int i = 0; i < R; i++)
   {
      for (int j = 0; j < C; j++)
         os << m.getElement(i,j) << " ";
   
      os << endl; //not just prints eol but flushes
   }

   os << "Printed #" << ++m.printed << " times\n";
    
   return os;
}

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

template <class T, int R, int C>
class Matrix : public Object
{
public:
   //Default constructor
   Matrix<T,R,C>();
   //Converting constructor (should be explicit)
   Matrix<T,R,C>(const T value);
   //Initializer constructor
   Matrix<T,R,C>(initializer_list<initializer_list<T>> list);
   //Copy constructor
   Matrix<T,R,C>(const Matrix& m);
   //Destructor
   ~Matrix<T,R,C>();
   //User methods
   [[deprecated]]
   void empty();
   void clear();
   void print(void) const;
   void setElement(int row, int col, T value = 0);
   const T getElement(int row, int col) const;
   Matrix<T,R,C> addMatrix(const Matrix<T,R,C> othermatrix) const;
   Matrix<T,R,C> operator+(const Matrix<T,R,C>& rhs);
   Matrix<T,R,C> operator-(const Matrix<T,R,C>& rhs);
   bool operator==(const Matrix<T,R,C>& rhs) const noexcept;
   bool operator!=(const Matrix<T,R,C>& rhs) const noexcept;
   Matrix<T,R,C>& operator+=(const Matrix<T,R,C>& rhs);
   T& operator[](int cell) noexcept;
   T operator[](int cell) const noexcept;
   T& operator()(int row, int col);
   T operator()(int row, int col) const;
   Matrix<T,R,C>& operator=(const Matrix<T,R,C>& rhs) noexcept;
   friend ostream& operator<<<T,R,C>(ostream& os, const Matrix<T,R,C>& m);
   //Overriding methods of MatrixParent
   std::string nameOf() { return "Matrix"; }
   void trace() { cout << "Here is " << nameOf() << endl; }
   static_assert(std::is_fundamental_v<T>, "T must be a fundamental type");
   //apply func
   Matrix<T,R,C>& apply(function<T (T)> f) {
      for (auto& row : mtx) 
         for (auto &data : row) 
            data = f(data);
      
      return *this;
   }
private:
   array<array <T,C>,R> mtx;
   mutable int printed;
};

int objcount = 0;

template <class T, int R, int C>
Matrix<T,R,C>::Matrix()
{
   printed = 0;
   clear(); 
} 

template <class T, int R, int C>
Matrix<T,R,C>::~Matrix() {}

template <class T, int R, int C>
Matrix<T,R,C>::Matrix(const T value)
{
   cout << "Creating " << value << "// ObjCount=" << ++objcount << "\n";
   printed = 0;
   for (auto& row : mtx) 
      for (auto &data : row) 
         data = value;
}

template <class T, int R, int C>
Matrix<T,R,C>::Matrix(const Matrix<T,R,C>& m)
{
   cout << "Creating by a copy constructor" << "// ObjCount=" << ++objcount << endl;
   printed = 0;
   mtx = m.mtx;
}

template <class T, int R, int C>
Matrix<T,R,C>::Matrix(initializer_list<initializer_list<T>> list)
{
   int r = 0, c = 0;
   cout << "Matrix list initializer constructor" << endl;

   for (const auto& elm: list)
   {
      c = 0;
      for (auto item: elm)
      {
         this->setElement(r, c, item);
         c++;
      }
      r++;
   }
}

template <class T, int R, int C>
void Matrix<T,R,C>::empty()
{
   for (auto& row : mtx) 
      for (auto &data : row) 
         data = 0;
}

template <class T, int R, int C>
void Matrix<T,R,C>::clear()
{
   for (auto& row : mtx) 
      for (auto &data : row) 
         data = 0;
}

template <class T, int R, int C>
void Matrix<T,R,C>::print(void) const
{
   cout << endl;

   for (auto& row : mtx) 
   {
      for (auto &data : row) 
      {
         cout << data << " ";
      }
      cout << endl; //not just prints eol but flushes
   }

   cout << "Printed #" << ++printed << " times\n";
}

template <class T, int R, int C>
void Matrix<T,R,C>::setElement(int row, int col, T value)
{
   assert(row >= 0);
   assert(col >= 0);

   if (row > R || col > C)
   {
      MatrixBoundException me;
      throw me;
   }

   mtx.at(row).at(col) = value;
}

template <class T, int R, int C>
const T Matrix<T,R,C>::getElement(int row, int col) const
{
   assert(row >= 0);
   assert(col >= 0);
   assert(row < R);
   assert(col < C);
   return mtx.at(row).at(col);
}

template <class T, int R, int C>
Matrix<T,R,C> Matrix<T,R,C>::operator+(const Matrix<T,R,C>& rhs)
{
   Matrix lhs;

   for (int i = 0; i < R; i++) {
      for (int j = 0; j < C; j++) {
         lhs.setElement(i, j, mtx[i][j] + rhs.getElement(i,j) );
      }
   }
   return lhs;
}

template <class T, int R, int C>
Matrix<T,R,C> Matrix<T,R,C>::operator-(const Matrix<T,R,C>& rhs)
{
   Matrix lhs;

   for (int i = 0; i < R; i++) {
      for (int j = 0; j < C; j++) {
         lhs.setElement(i, j, mtx[i][j] - rhs.getElement(i,j) );
      }
   }
   return lhs;
}

template <class T, int R, int C>
bool Matrix<T,R,C>::operator==(const Matrix<T,R,C>& rhs) const noexcept
{
   for (int i = 0; i < R; i++) {
      for (int j = 0; j < C; j++) {
         if (mtx[i][j] != rhs.getElement(i,j))
         {
            return false;
         }
      }
   }
   return true;
}

template <class T, int R, int C>
bool Matrix<T,R,C>::operator!=(const Matrix<T,R,C>& rhs) const noexcept
{
   return !this->operator==(rhs);
}

template <class T, int R, int C>
Matrix<T,R,C>& Matrix<T,R,C>::operator+=(const Matrix<T,R,C>& rhs)
{
    for (int i = 0; i < R; i++)
       for (int j = 0; j < C; j++)
          mtx[i][j] = mtx[i][j] + rhs.getElement(i,j);

    return *this;
}

template <class T, int R, int C>
T& Matrix<T,R,C>::operator[](int cell) noexcept
{
   int curr_row = cell / (R + 1);
   int curr_off = cell % (C + 1);
   T* pr = &mtx[curr_row][0];

   return *(pr + (curr_off * sizeof(T)));
}

template <class T, int R, int C>
T Matrix<T,R,C>::operator[](int cell) const noexcept
{
   assert(cell < (R*C));

   const int curr_row = cell / (R + 1);
   const int curr_off = cell % (R + 1);
   const T* pr = &mtx[curr_row][0];
   const T* p = pr + (curr_off * sizeof(T));

   return *p;
}

// using this operator can be done as
// cout << m(1,0)
// m(1,0) = 8 with this case because operator used on left it becomes the l-value
template <class T, int R, int C>
T& Matrix<T,R,C>::operator()(int row, int col)
{
   assert(row >= 0);
   assert(col >= 0);
   assert(row < R);
   assert(col < C);
   return this->mtx[row][col];
}

template <class T, int R, int C>
T Matrix<T,R,C>::operator()(int row, int col) const
{
   assert(row >= 0);
   assert(col >= 0);
   assert(row < R);
   assert(col < C);
   return this->mtx[row][col];
}

template <class T, int R, int C>
Matrix<T,R,C>& Matrix<T,R,C>::operator=(const Matrix<T,R,C>& rhs) noexcept
{
   for (int i = 0; i < R; i++) {
      for (int j = 0; j < C; j++) {
         this->mtx[i][j] = rhs.getElement(i,j);
      }
   }

   return *this;
}

} // end namespace utils

#endif