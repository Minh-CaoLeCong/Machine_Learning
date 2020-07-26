/////////////////////////////////////////////////
//                                             //
//        Created by Cao Le Cong Minh          //
//                                             //
/////////////////////////////////////////////////
//   Gmail:  caolecongminh1997@gmail.com       //
//	Github: https://github.com/Minh-CaoLeCong  //
/////////////////////////////////////////////////

#ifndef Machine_Learning_Algorithms_h
#include "Machine_Learning_Algorithms.h"
#endif Machine_Learning_Algorithms_h

#ifndef Matrix_Operation_h
#include "Matrix_Operation.h"
#endif Matrix_Operation_h

using namespace std;

/// Transpose a matrix. Using pointer. For Rectangular Matix
void Transpose(float *src, float *dst, int m, int n)
{
	/*for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%f\t", *((src + i * (n)) + j));
		}
		printf("\n");
	}

	printf("\n\n\n");*/

	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			/**dst = *((src + i * m) + j);*/
			*((dst + j * (m)) + i) = *((src + i * (n)) + j);
		}

	//cout << my_sizeof(src) << endl; // 8
	//cout << my_sizeof(src) / my_sizeof(X[0][0]) << endl; // 94
	//cout << my_sizeof(X) / my_sizeof(X[0]) << endl; // 47

	/*for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%f\t", *((dst + i * (m)) + j));
		}
		printf("\n");
	}*/
}

/// Transpose a matrix. NOT Using pointer. For Rectangular Matix
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
void Transpose1(int A[][N], int B[][M])
{
	int i, j;
	for (i = 0; i < N; i++)
		for (j = 0; j < M; j++)
			B[i][j] = A[j][i];
}

/// Transpose a matrix. NOT Using pointer. For Square Matix
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
void Transpose2(int A[][N], int B[][N])
{
	int i, j;
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			B[i][j] = A[j][i];
}

/// Multiply two matrix. NOT using pointer. For Square Matrix
// Example: int i, j; 
//			int C[N][N]; // To store result 
//			int A[N][N] = {{1, 1, 1, 1},
//							  {2, 2, 2, 2},
//							  {3, 3, 3, 3},
//							  {4, 4, 4, 4}};
//
//			int B[N][N] = {{1, 1, 1, 1},
//							  {2, 2, 2, 2},
//							  {3, 3, 3, 3},
//							  {4, 4, 4, 4}};
//
//			multiply(A, B, C);
//
//			cout << "Result matrix is \n";
//			for (i = 0; i < N; i++)
//			{
//				for (j = 0; j < N; j++)
//				cout << C[i][j] << " ";
//				cout << "\n";
//			}
void Multiply1(int A[][N], int B[][N], int C[][N])
{
	int i, j, k;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			C[i][j] = 0;
			for (k = 0; k < N; k++)
				C[i][j] += A[i][k] * B[k][j];
		}
	}
}

/// Multiply two matrix. Using pointer. For Rectangular Matrix
// Example: int A[][2] = { { 2, 4 }, { 3, 4 } }; 
//			int B[][2] = { { 1, 2 }, { 1, 3 } };
//			int m1 = 2, m2 = 2, n1 = 2, n2 = 2;
//			multiply(m1, m2, A, n1, n2, B);
void Multiply2(int m1, int m2, int A[][2], int n1, int n2, int B[][2])
{
	int i, j, k;
	int C[2][2]; // int C[m1][n2];
	for (i = 0; i < m1; i++)
	{
		for (j = 0; j < n2; j++)
		{
			C[i][j] = 0;
			for (k = 0; k < m2; k++)
			{
				*(*(C + i) + j) += *(*(A + i) + k) * *(*(B + k) + j);
			}
		}
	}

	for (i = 0; i < m1; i++)
	{
		for (j = 0; j < n2; j++)
		{
			printf("%d ", *(*(C + i) + j));
		}
		printf("\n");
	}
}

/// Multiply two matrix. Using pointer. For Rectangular Matrix
void Multiply(float *mat1, float *mat2, float *mat3, int m1, int m2, int n1, int n2)
{
	int i, j, k;
	for (i = 0; i < m1; i++)
	{
		for (j = 0; j < n2; j++)
		{
			*((mat3 + i * (n2)) + j) = 0;
			for (k = 0; k < m2; k++)
			{
				*((mat3 + i * (n2)) + j) += *((mat1 + i * (m2)) + k) * *((mat2 + k * (n2)) + j);
			}
		}
	}
}

// Function to get cofactor of A[p][q] in temp[][]. n is current 
// dimension of A[][] 
/* Source: https://www.geeksforgeeks.org/adjoint-inverse-matrix/ */
void getCofactor(float A[N][N], float temp[N][N], int p, int q, int n)
{
	int i = 0, j = 0;

	// Looping for each element of the matrix 
	for (int row = 0; row < n; row++)
	{
		for (int col = 0; col < n; col++)
		{
			//  Copying into temporary matrix only those element 
			//  which are not in given row and column 
			if (row != p && col != q)
			{
				temp[i][j++] = A[row][col];

				// Row is filled, so increase row index and 
				// reset col index 
				if (j == n - 1)
				{
					j = 0;
					i++;
				}
			}
		}
	}
}

// Recursive function for finding determinant of matrix.
// n is current dimension of A[][].
/* Source: https://www.geeksforgeeks.org/adjoint-inverse-matrix/ */
float determinant(float A[N][N], int n)
{
	float D = 0; // Initialize result 

	//  Base case : if matrix contains single element 
	if (n == 1)
		return A[0][0];

	float temp[N][N]; // To store cofactors 

	int sign = 1;  // To store sign multiplier 

	 // Iterate for each element of first row 
	for (int f = 0; f < n; f++)
	{
		// Getting Cofactor of A[0][f] 
		getCofactor(A, temp, 0, f, n);
		D += sign * A[0][f] * determinant(temp, n - 1);

		// terms are to be added with alternate sign 
		sign = -sign;
	}

	return D;
}

// Function to get adjoint of A[N][N] in adj[N][N].
/* Source: https://www.geeksforgeeks.org/adjoint-inverse-matrix/ */
void adjoint(float A[N][N], float adj[N][N])
{
	if (N == 1)
	{
		adj[0][0] = 1;
		return;
	}

	// temp is used to store cofactors of A[][] 
	int sign = 1;
	float temp[N][N];

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			// Get cofactor of A[i][j] 
			getCofactor(A, temp, i, j, N);

			// sign of adj[j][i] positive if sum of row 
			// and column indexes is even. 
			sign = ((i + j) % 2 == 0) ? 1 : -1;

			// Interchanging rows and columns to get the 
			// transpose of the cofactor matrix 
			adj[j][i] = (sign)*(determinant(temp, N - 1));
		}
	}
}

// Function to calculate and store inverse, returns false if 
// matrix is singular 
/* Source: https://www.geeksforgeeks.org/adjoint-inverse-matrix/ */
bool inverse(float A[N][N], float inverse[N][N])
{
	// Find determinant of A[][] 
	float det = determinant(A, N);
	if (det == 0)
	{
		cout << "Singular matrix, can't find its inverse";
		return false;
	}

	// Find adjoint 
	float adj[N][N];
	adjoint(A, adj);

	// Find Inverse using formula "inverse(A) = adj(A)/det(A)" 
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			inverse[i][j] = adj[i][j] / float(det);

	return true;
}

















/////////////////////////////////////////////////
//                                             //
//        Created by Cao Le Cong Minh          //
//                                             //
/////////////////////////////////////////////////
//   Gmail:  caolecongminh1997@gmail.com       //
//	Github: https://github.com/Minh-CaoLeCong  //
/////////////////////////////////////////////////