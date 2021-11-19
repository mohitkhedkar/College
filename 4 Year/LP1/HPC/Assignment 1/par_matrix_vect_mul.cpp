// Assignment 1: Vector and Matrix Operations Design parallel algorithm to Multiply Vector and Matrix

#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <omp.h>
using namespace std;

int main()
{
	int m = 3, n = 2;
	int mat[m][n], vec[n], out[m];

	//matrix of size 3x2
	for (int row = 0; row < m; row++)
	{
		for (int col = 0; col < n; col++)
		{
			mat[row][col] = 1;
		}
	}
	//display matrix
	cout << "Input Matrix" << endl;
	for (int row = 0; row < m; row++)
	{
		for (int col = 0; col < n; col++)
		{
			cout << "\t" << mat[row][col];
		}
		cout << "" << endl;
	}

	//column vector of size 2x1
	for (int row = 0; row < n; row++)
	{
		vec[row] = 2;
	}

	//display vector
	cout << "Input Col-Vector" << endl;
	for (int row = 0; row < n; row++)
	{
		cout << vec[row] << endl;
	}

//before multiplication check condition, no_of_cols(matrix)==no_of_rows(vector)
#pragma omp parallel
	{
#pragma omp parallel for
		for (int row = 0; row < m; row++)
		{
			out[row] = 0;
			for (int col = 0; col < n; col++)
			{
				out[row] += mat[row][col] * vec[col];
				//int count=out[row];
				//printf("\n%d\n",count);
			}
		}
	}

	//display resultant vector
	cout << "Resultant Col-Vector" << endl;

	for (int row = 0; row < m; row++)
	{
		cout << "\nvec[" << row << "]:" << out[row] << endl;
	}

	return 0;
}

/*
guest-zbuacn@admin:~$ g++ par_matrix_vect_mul.cpp -fopenmp
guest-zbuacn@admin:~$ ./a.out
Input Matrix
	1	1
	1	1
	1	1
Input Col-Vector
2
2
Resultant Col-Vector

vec[0]:4

vec[1]:4

vec[2]:4








*/
