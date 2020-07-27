#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define TRUE 1
#define FALSE 0

int check_sudoku_valid(int a[][9]);	//Function for check if sudoku is valid

int main(void)
{
	int sudo_board[9][9] = { 0 };
	int i;
	int solution;

	for (i = 0; i < 9; i++)
		scanf("%d %d %d %d %d %d %d %d %d", &sudo_board[i][0], &sudo_board[i][1], &sudo_board[i][2], &sudo_board[i][3], &sudo_board[i][4], &sudo_board[i][5], &sudo_board[i][6], &sudo_board[i][7], &sudo_board[i][8]);
	
	solution = check_sudoku_valid(sudo_board);

	//If input sudoku is valid, print true. If invalid, print false
	if (solution == TRUE)
		puts("true");
	else
		puts("false");
	
}

int check_sudoku_valid(int a[][9])
{
	int i, j, x, y;
	
	//Sudoku row checking
	for (i = 0; i < 9; i++)
	{
		int temp[10] = { 0 };
		for (j = 0; j < 9; j++)
		{
			if (temp[a[i][j]] == 0 && a[i][j] >= 1 && a[i][j] <= 9)
			{
				temp[a[i][j]] = a[i][j];
			}
			else
				return FALSE;
		}
	}

	//Sudoku column checking
	for (i = 0; i < 9; i++)
	{
		int temp[10] = { 0 };
		for (j = 0; j < 9; j++)
		{
			if (temp[a[j][i]] == 0 && a[j][i] >= 1 && a[j][i] <= 9)
			{
				temp[a[j][i]] = a[j][i];
			}
			else
				return FALSE;
		}
	}

	//Sudoku box checking
	for (i = 0; i < 9; i += 3)
	{
		for (j = 0; j < 9; j += 3)
		{
			int temp[10] = { 0 };
			for (x = i; x < i + 3; x++)
			{
				for (y = j; y < j + 3; y++)
				{
					if (temp[a[x][y]] == 0 && a[x][y] >= 1 && a[x][y] <= 9)
					{
						temp[a[x][y]] = a[x][y];
					}
					else
					{
						return FALSE;
					}
				}
			}
		}
	}

	return TRUE;
}
