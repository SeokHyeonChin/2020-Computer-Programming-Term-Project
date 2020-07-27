#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define TRUE 1
#define FALSE 0
#define SIZE 9

int sudoku_full = 0;

void* find_sudoku(int a[][9], int t_sum[]);
int check_input_valid(int sudoku[][9],int row, int col);



int main(void)
{
	int Triple_sum[SIZE] = { 0 };
	int sudo_board[SIZE][SIZE] = { 0 };
	int i, j;


	for (i = 0; i < SIZE; i++)
		scanf("%d %d %d %d %d %d %d %d %d %d", &Triple_sum[i], &sudo_board[i][0], &sudo_board[i][1], &sudo_board[i][2], &sudo_board[i][3], &sudo_board[i][4], &sudo_board[i][5], &sudo_board[i][6], &sudo_board[i][7], &sudo_board[i][8]);
	
	int (*ptr)[SIZE] = (int(*)[SIZE])find_sudoku(sudo_board, Triple_sum);
	
	for (i = 0; i < SIZE; i++)
	{
		for (j = 0; j < SIZE; j++)
		{
			if (j == SIZE - 1)
				printf("%d", ptr[i][j]);
			else
				printf("%d ", ptr[i][j]);
		}
		puts("");
	}
}


void* find_sudoku(int a[][9], int t_sum[])
{
	//Sudoku with Backtracking Algorithm
	int i, j;
	int num;			// input number
 	
	for (i = 0; i < 9; i++) 
	{
		for (j = 0; j < 9; j++) 
		{
			if (a[i][j] == 0) 
			{
				for (num = 1; num <= 9; num++) 
				{
					a[i][j] = num;
					
					if (check_input_valid(a, i, j) == 1)
					{ 
						a = (int(*)[SIZE])find_sudoku(a, t_sum);

						if (sudoku_full == 1) 
							return a;
					}
					a[i][j] = 0;
				}
				return a;
			}
			
			// Checking Triple-sum condition
			if (j == 8)
			{
				if (a[i][0] * 1000 + a[i][1] * 100 + a[i][2] * 10 + a[i][3] + a[i][4] * 100 + a[i][5] * 10 + a[i][6] + a[i][7] * 10 + a[i][8] != t_sum[i])
				{
					return a;
				}
			}
		}
	}

	sudoku_full = 1; // for all i & j, if a[i][j] != 0, it means sudoku is full 
	return a;
}

int check_input_valid(int sudoku[][9], int row, int col)
{
	int i, j;
	int box_row, box_col;
	int check_unique = sudoku[row][col];

	//Sudoku row checking
	for (j = 0; j < 9; j++)
		if (sudoku[row][j] == check_unique && j != col)
			return FALSE;

	//Sudoku column checking
	for (i = 0; i < 9; i++) 
		if (sudoku[i][col] == check_unique && i != row) 
			return FALSE;

	//Sudoku box checking
	box_row = (row / 3) * 3;
	box_col = (col / 3) * 3;
	for (i = box_row; i < box_row + 3; i++)
		for (j = box_col; j < box_col + 3; j++)
			if (sudoku[i][j] == check_unique && i != row && j != col)
				return FALSE;

	return TRUE;
}
