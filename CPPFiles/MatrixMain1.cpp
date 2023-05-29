/*
 *	MatrixMain1.cpp
 *		Program to be completed by students.
 */
#include <cassert>
#include "Matrix.hpp"

int main()
{
	Matrix m1, m2, m3;

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

   if (m1 != m2)
      std::cout << "\nMatrices are different!";
   else
      std::cout << "\nMatrices are the same!";

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

   m8 += m8;
   std::cout << "\nMatrix printed is operator += to do of m8+=m8\n";
   m8.print();

   for (int i = 0; i < MAX_CELLS; ++i)
      cout << "Cell[" << i << "]=" << m8[i] << "\n";

   const Matrix zrs{0};
   cout << "Zeros value index = " << zrs[0] << '\n';

	return 0;
}
