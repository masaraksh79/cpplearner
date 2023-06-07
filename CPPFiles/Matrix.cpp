#include "Matrix.hpp"

// int objcount = 0;

// template <class T>
// Matrix<T>::Matrix()
// {
//    printed = 0;
//    empty(); 
// } 

// template <class T>
// Matrix<T>::~Matrix() {}

// template <class T>
// Matrix<T>::Matrix(const T value)
// {
//    cout << "Creating " << value << "// ObjCount=" << ++objcount << "\n";
//    printed = 0;
//    for (int i = 0; i < MAX_ROWS; i++)
//       for (int j = 0; j < MAX_COLS; j++)
//          mtx.at(i).at(j) = value;
// }

// template <class T>
// Matrix<T>::Matrix(const Matrix<T>& m)
// {
//    cout << "Creating by a copy constructor" << "// ObjCount=" << ++objcount << endl;
//    printed = 0;
//    mtx = m.mtx;
// }

// template <class T>
// void Matrix<T>::empty()
// {
//    for (int i = 0; i < MAX_ROWS; i++)
//       for (int j = 0; j < MAX_COLS; j++)
//          mtx.at(i).at(j) = static_cast<T>(0);
// }

// template <class T>
// void Matrix<T>::print(void) const
// {
//    cout << endl;
   
//    for (int i = 0; i < MAX_ROWS; i++)
//    {
//       for (int j = 0; j < MAX_COLS; j++)
//          cout << mtx.at(i).at(j) << " ";
   
//       cout << endl; //not just prints eol but flushes
//    }

//    cout << "Printed #" << ++printed << " times\n";
// }

// template <class T>
// void Matrix<T>::setElement(int row, int col, T value)
// {
//    assert(row >= 0);
//    assert(col >= 0);

//    if (row > MAX_ROWS || col > MAX_COLS)
//    {
//       MatrixBoundException me;
//       throw me;
//    }

//    mtx.at(row).at(col) = value;
// }

// template <class T>
// const T Matrix<T>::getElement(int row, int col) const
// {
//    assert(row >= 0);
//    assert(col >= 0);
//    assert(row < MAX_ROWS);
//    assert(col < MAX_COLS);
//    return mtx.at(row).at(col);
// }

// template <class T>
// Matrix<T> Matrix<T>::operator+(const Matrix<T>& rhs)
// {
//    Matrix lhs;

//    for (int i = 0; i < MAX_ROWS; i++) {
//       for (int j = 0; j < MAX_COLS; j++) {
//          lhs.setElement(i, j, mtx[i][j] + rhs.getElement(i,j) );
//       }
//    }
//    return lhs;
// }

// template <class T>
// Matrix<T> Matrix<T>::operator-(const Matrix<T>& rhs)
// {
//    Matrix lhs;

//    for (int i = 0; i < MAX_ROWS; i++) {
//       for (int j = 0; j < MAX_COLS; j++) {
//          lhs.setElement(i, j, mtx[i][j] - rhs.getElement(i,j) );
//       }
//    }
//    return lhs;
// }

// template <class T>
// bool Matrix<T>::operator==(const Matrix<T>& rhs) const noexcept
// {
//    for (int i = 0; i < MAX_ROWS; i++) {
//       for (int j = 0; j < MAX_COLS; j++) {
//          if (mtx[i][j] != rhs.getElement(i,j))
//          {
//             return false;
//          }
//       }
//    }
//    return true;
// }

// template <class T>
// bool Matrix<T>::operator!=(const Matrix<T>& rhs) const noexcept
// {
//    return !this->operator==(rhs);
// }

// template <class T>
// ostream& operator<<(ostream& os, const Matrix<T>& m)
// {
//    os << endl;
   
//    for (int i = 0; i < MAX_ROWS; i++)
//    {
//       for (int j = 0; j < MAX_COLS; j++)
//          os << m.getElement(i,j) << " ";
   
//       os << endl; //not just prints eol but flushes
//    }

//    os << "Printed #" << ++m.printed << " times\n";
    
//    return os;
// }

// template <class T>
// Matrix<T>& Matrix<T>::operator+=(const Matrix<T>& rhs)
// {
//     for (int i = 0; i < MAX_ROWS; i++)
//        for (int j = 0; j < MAX_COLS; j++)
//           mtx[i][j] = mtx[i][j] + rhs.getElement(i,j);

//     return *this;
// }

// template <class T>
// T& Matrix<T>::operator[](int cell) noexcept
// {
//    int curr_row = cell / (MAX_ROWS + 1);
//    int curr_off = cell % (MAX_ROWS + 1);
//    T* pr = &mtx[curr_row][0];

//    return *(pr + (curr_off * sizeof(T)));
// }

// template <class T>
// T Matrix<T>::operator[](int cell) const noexcept
// {
//    assert(cell < MAX_CELLS);

//    const int curr_row = cell / (MAX_ROWS + 1);
//    const int curr_off = cell % (MAX_ROWS + 1);
//    const T* pr = &mtx[curr_row][0];
//    const T* p = pr + (curr_off * sizeof(T));

//    return *p;
// }

// // using this operator can be done as
// // cout << m(1,0)
// // m(1,0) = 8 with this case because operator used on left it becomes the l-value
// template <class T>
// T& Matrix<T>::operator()(int row, int col)
// {
//    assert(row >= 0);
//    assert(col >= 0);
//    assert(row < MAX_ROWS);
//    assert(col < MAX_COLS);
//    return this->mtx[row][col];
// }

// template <class T>
// T Matrix<T>::operator()(int row, int col) const
// {
//    assert(row >= 0);
//    assert(col >= 0);
//    assert(row < MAX_ROWS);
//    assert(col < MAX_COLS);
//    return this->mtx[row][col];
// }

// template <class T>
// Matrix<T>& Matrix<T>::operator=(const Matrix<T>& rhs) noexcept
// {
//    for (int i = 0; i < MAX_ROWS; i++) {
//       for (int j = 0; j < MAX_COLS; j++) {
//          this->mtx[i][j] = rhs.getElement(i,j);
//       }
//    }

//    return *this;
// }

