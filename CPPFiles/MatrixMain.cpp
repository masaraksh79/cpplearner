/*
 *	MatrixMain1.cpp
 *		Program to be completed by students.
 */
#include <cassert>
#include <fstream>
#include "Matrix.hpp"

#define MAX_ROWS 2
#define MAX_COLS 3
#define MAX_CELLS (MAX_ROWS*MAX_COLS)

using namespace utils;

int main()
{
	Matrix<int,MAX_ROWS,MAX_COLS> m1;
   Matrix<int,MAX_ROWS,MAX_COLS> m2; 
   Matrix<int,MAX_ROWS,MAX_COLS> m3;

   Matrix<int,MAX_ROWS,MAX_COLS> m6;
   Matrix<int,MAX_ROWS,MAX_COLS> m7(55);
   Matrix<int,MAX_ROWS,MAX_COLS> m8;

   const Matrix<int,MAX_ROWS,MAX_COLS> zeros(0);
   const Matrix<int,MAX_ROWS,MAX_COLS> zrs{0};

   ofstream outfile;

	m1.empty();
	m2.empty();

   m1(0, 0) = 10;
   m1(0, 1) = 20;
   
   try
   {
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

      if (m1 != m2)
         std::cout << "\nMatrices are different!";
      else
         std::cout << "\nMatrices are the same!";

      std::cout << "\nMatrix m7 is initialized with same value in all cells\n";
      m7.print();

      std::cout << "\nMatrix zeros is printed through marked print method\n";
      zeros.print();
      zeros.print();
      zeros.print();

      cout << m7;

      m8 = m1 - m2;
      std::cout << "\nMatrix printed is subtraction of m1-m2\n";
      m8.print();

      m8 += m8;
      std::cout << "\nMatrix printed is operator += to do of m8+=m8\n";
      m8.print();

      for (int i = 0; i < MAX_CELLS; ++i)
         cout << "Cell[" << i << "]=" << m8[i] << "\n";

      cout << "Zeros value index = " << zrs[0] << '\n';

      cout << "Matrix M1 index (1,2) = " << m1(1,2) << '\n';
      cout << "Matrix ZEROS index (1,2) = " << zeros(1,2) << '\n';

      cout << "Matrix m8 before assignment from m1\n";
      m8.print();
      m8 = m1;
      cout << "Matrix m8 after assignment from m1\n";
      m8.print();

      outfile.open("test.txt");
      outfile << m1;
      outfile.close();

      cout << "Name of derived class : " << m8.nameOf() << endl;
      m8.trace();
   }
   catch(int v)   // should print 7 (worked in one of past commits)
   {
      std::cerr << "Error=" << v << " at line " << __LINE__ <<  std::endl;
   }

   try
   {
      m1.setElement(0, 8, 30);
   }
   catch(const MatrixBoundException& e)
   {
      std::cerr << e.what() << '\n';
   }

	return 0;
}
