#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdbool.h>
#define N 4
int is_strong(int mat[N][N], int row, int column);
int space_rank(int mat[N][N], int row, int column);


/// <the main scans the matrix from the user then checks the space rank 
/// for every element in the matrix and sum them and count how many strong
/// elements the matrix have then print the results>
int main()
{
	int matrix[4][4] = { {0} }, cnt = 0;
	int ret_val, matrix_rank = 0;
	printf("Please enter a matrix:\n");
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			scanf("%d", &matrix[i][j]);
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			ret_val = is_strong(matrix, i, j);
			matrix_rank += space_rank(matrix, i, j);
			ret_val == 1 ? cnt++ : cnt;
			ret_val = 0;
		}
	}
	printf("Strong elements: %d\n", cnt);
	printf("Space rank: %d", matrix_rank);

	return 0;
}


/// <the function "is_strong" checks if the number is begger than all of it neighboors>
/// 
/// <the func checks every neighboor individually and if they all true then it's strong>
/// < if the number has no neigboor on one side then it doesn't check because of the || >
/// <param name="mat"><the address of the matrix>
/// <param name="row"><the row of the nunber we wanna check>
/// <param name="column"><the column of the number we wanna check>
/// <returns><return true if the number is strong and if not return false>
int is_strong(int mat[N][N], int row, int column)
{
	bool option_1 = false, option_2 = false, option_3 = false, option_4 = false;
	bool strong = false;
	option_1 = mat[row][column] > mat[row][column + 1] || column == 3; //if the num doesnt have neighboors
	option_2 = mat[row][column] > mat[row][column - 1] || column == 0;
	option_3 = mat[row][column] > mat[row-1][column] || row == 0;
	option_4 = mat[row][column] > mat[row+1][column] || row == 3;
	strong = option_1 && option_2 && option_3 && option_4;
	return strong;
}
/// <the function returns the space rank of one element>
/// 
/// <if (column < 3) the function checks if the element is 
//. bigger or smaller than its neighbor (true or false) and then 
//. multiply the true and false value and sum them>
/// <param name="indicator_1"><is the element bigger than its neighboor>
/// <param name="indicator_2"><is the element smaller than its neighboor>
/// <param name="rank"><the space rank result>
/// <returns></return the space rink>
int space_rank(int mat[N][N], int row, int column)
{
	int rank = 0;
	bool indicator_1 = mat[row][column] > mat[row][column + 1] || column == 3;
	bool indicator_2 = mat[row][column] < mat[row][column + 1] || column == 3;
	rank = indicator_1 * (mat[row][column] - mat[row][column + 1]);
	rank+= indicator_2 * (mat[row][column + 1] - mat[row][column]);
	return rank;
}

