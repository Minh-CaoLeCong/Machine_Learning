/////////////////////////////////////////////////
//                                             //
//        Created by Cao Le Cong Minh          //
//                                             //
/////////////////////////////////////////////////
//   Gmail:  caolecongminh1997@gmail.com       //
//	Github: https://github.com/Minh-CaoLeCong  //
/////////////////////////////////////////////////

#define Matrix_Operation_h

#ifdef Matrix_Operation_h

#ifndef Machine_Learning_Algorithms_h
#include "pch.h"
#include <iostream>
#include <string>
#include <fstream> // .txt file c++
#include "Machine_Learning_Algorithms.h"
#endif // Machine_Learning_Algorithms_h

#define M 3
#define N 47
#define my_sizeof(type) ((char *)(&type+1) - (char *)(&type))


/// Transpose a matrix. Using pointer. For Rectangular Matrix
void Transpose(float *src, float *dst, int m, int n);
/// Transpose a matrix. NOT Using pointer. For Rectangular Matrix
// Example: int A[M][N] = { {1, 1, 1, 1}, 
//							{2, 2, 2, 2},
//							{3, 3, 3, 3}};
//
//			// Note dimensions of B[][] 
//			int B[N][M], i, j;
//
//			transpose(A, B);
//
//			printf("Result matrix is \n");
//			for (i = 0; i < N; i++)
//			{
//				for (j = 0; j < M; j++)
//					printf("%d ", B[i][j]);
//				printf("\n");
//			}
void Transpose1(int A[][N], int B[][M]);
/// Transpose a matrix. NOT Using pointer. For Square Matrix
// Example: int A[N][N] = { {1, 1, 1, 1}, 
//							{2, 2, 2, 2},
//							{3, 3, 3, 3},
//							{4, 4, 4, 4}};
//
//			int B[N][N], i, j;
//
//			transpose(A, B);
//
//			printf("Result matrix is \n");
//			for (i = 0; i < N; i++)
//			{
//				for (j = 0; j < N; j++)
//					printf("%d ", B[i][j]);
//				printf("\n");
//
//			}
void Transpose2(int A[][N], int B[][N]);
/// Multiply two matrix. Using pointer. For Rectangular Matrix
void Multiply(float *mat1, float *mat2, float *mat3, int m1, int m2, int n1, int n2);
/// Multiply two matrix. NOT using pointer. For Square Matrix
// Example: int i, j; 
//			int res[N][N]; // To store result 
//			int mat1[N][N] = {{1, 1, 1, 1},
//							  {2, 2, 2, 2},
//							  {3, 3, 3, 3},
//							  {4, 4, 4, 4}};
//
//			int mat2[N][N] = {{1, 1, 1, 1},
//							  {2, 2, 2, 2},
//							  {3, 3, 3, 3},
//							  {4, 4, 4, 4}};
//
//			multiply(mat1, mat2, res);
//
//			cout << "Result matrix is \n";
//			for (i = 0; i < N; i++)
//			{
//				for (j = 0; j < N; j++)
//				cout << res[i][j] << " ";
//				cout << "\n";
//			}
void Multiply1(int A[][N], int B[][N], int C[][N]);
/// Multiply two matrix. Using pointer. For Rectangular Matrix
// Example: int A[][2] = { { 2, 4 }, { 3, 4 } }; 
//			int B[][2] = { { 1, 2 }, { 1, 3 } };
//			int m1 = 2, m2 = 2, n1 = 2, n2 = 2;
//			multiply(m1, m2, A, n1, n2, B);
void Multiply2(int m1, int m2, int A[][2], int n1, int n2, int B[][2]);
// Function to get cofactor of A[p][q] in temp[][]. n is current 
// dimension of A[][] 
/* Source: https://www.geeksforgeeks.org/adjoint-inverse-matrix/ */
void getCofactor(float A[N][N], float temp[N][N], int p, int q, int n);
// Recursive function for finding determinant of matrix.
// n is current dimension of A[][].
/* Source: https://www.geeksforgeeks.org/adjoint-inverse-matrix/ */
float determinant(float A[N][N], int n);
// Function to get adjoint of A[N][N] in adj[N][N].
/* Source: https://www.geeksforgeeks.org/adjoint-inverse-matrix/ */
void adjoint(float A[N][N], float adj[N][N]);
// Function to calculate and store inverse, returns false if 
// matrix is singular 
/* Source: https://www.geeksforgeeks.org/adjoint-inverse-matrix/ */
bool inverse(float A[N][N], float inverse[N][N]);






















#endif //Matrix_Operation_h

/////////////////////////////////////////////////
//                                             //
//        Created by Cao Le Cong Minh          //
//                                             //
/////////////////////////////////////////////////
//   Gmail:  caolecongminh1997@gmail.com       //
//	Github: https://github.com/Minh-CaoLeCong  //
/////////////////////////////////////////////////