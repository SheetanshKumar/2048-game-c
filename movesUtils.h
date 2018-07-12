//#include "BoardUtils.h"

Board * left(Board * board);
Board * right(Board * board);
Board * up(Board * board);
Board * down(Board * board);
void shift_row_col_left(Board * board);
void shift_row_col_right(Board * board);
void shift_row_col_up(Board * board);
void shift_row_col_down(Board * board);

int is_valid_input(char input);
Board * process_input(Board * board, char input);



int is_valid_input(char input)
{
	if (input == 'a' || input == 's' || input == 'd' || input == 'w' ||
		input == 'A' || input == 'S' || input == 'D' || input == 'W' ||
		input == 'Z' || input == 'z')
		return 1;
	return 0;
}

Board * process_input(Board * board, char input)
{
	if (input == 'a' || input == 'A')
		board = left(board);
	else if (input == 'd' || input == 'D')
		board = right(board);
	else if (input == 'w' || input == 'W')
		board = up(board);
	else if (input == 's' || input == 'S')
		board = down(board);
	else if (input == 'z' || input == 'Z')
		exit(0);
	return board;
}

void shift_row_col_left(Board * board)
{
	int k;
	for (int row = 0; row < board->n; row++)
	{
		for (int col = 0; col < board->n; col++)
		{
			if (board->table[row][col] == 0)
			{
				for (k = col + 1; k < board->n; k++)
				{
					board->table[row][k - 1] = board->table[row][k];
				}
				board->table[row][k-1] = -1;
				//col--;
			}
		}
	
	}
	for (int row = 0; row < board->n; row++)
		for (int col = 0; col < board->n; col++)
			if (board->table[row][col] == -1)
				board->table[row][col] = 0;
	
}
void shift_row_col_right(Board * board)
{
	int k;
	for (int row = 0; row < board->n; row++)
	{
		for (int col = board->n - 1; col >= 0; col--)
		{
			if (board->table[row][col] == 0)
			{
				for (k = col - 1; k >= 0 ; k--)
				{
					board->table[row][k + 1] = board->table[row][k];
				}
				board->table[row][0] = -1;
				//col++;
			}
		}

	}
	for (int row = 0; row < board->n; row++)
		for (int col = 0; col < board->n; col++)
			if (board->table[row][col] == -1)
				board->table[row][col] = 0;
}

void shift_row_col_up(Board * board)
{
	int k; 
	for (int row = 0; row < board->n; row++)
	{
		for (int col = 0; col < board->n; col++)
		{
			if (board->table[col][row] == 0)
			{
				for (k = col + 1; k < board->n; k++)
				{
					board->table[k - 1][row] = board->table[k][row];
				}
				board->table[k - 1][row] = -1;
				//col--;
			}
		}

	}
	for (int row = 0; row < board->n; row++)
		for (int col = 0; col < board->n; col++)
			if (board->table[row][col] == -1)
				board->table[row][col] = 0;
}

void shift_row_col_down(Board * board)
{
	int k;
	for (int row = 0; row < board->n; row++)
	{
		for (int col = board->n - 1; col >= 0; col--)
		{
			if (board->table[col][row] == 0)
			{
				for (k = col - 1; k >=0 ; k--)
				{
					board->table[k + 1][row] = board->table[k][row];
				}
				board->table[0][row] = -1;
				//col++;
			}
		}

	}
	for (int row = 0; row < board->n; row++)
		for (int col = 0; col < board->n; col++)
			if (board->table[row][col] == -1)
				board->table[row][col] = 0;
}

Board * left(Board * board)
{
	shift_row_col_left(board);
	for (int row = 0; row < board->n; row++)
	{
		for (int col = 0; col < board->n - 1; col++)
		{
			if (board->table[row][col] == board->table[row][col + 1])
			{
				board->table[row][col] += board->table[row][col + 1];
				board->table[row][col + 1] = 0;
			}
		}
	}
	shift_row_col_left(board);
	return board;
}
Board * right(Board * board)
{
	shift_row_col_right(board);
	/*for (int row = 0; row < board->n; row++)
	{
		for (int col = 0; col < board->n - 1; col++)
		{
			if (board->table[row][col] == board->table[row][col + 1])
			{
				board->table[row][col + 1] += board->table[row][col];
				board->table[row][col] = 0;
			}
		}
	}*/
	for (int row = 0; row < board->n; row++)
	{
		for (int col = board->n-1; col > 0; col--)
		{
			if (board->table[row][col] == board->table[row][col - 1])
			{
				board->table[row][col] += board->table[row][col - 1];
				board->table[row][col - 1] = 0;
			}
		}
	}
	shift_row_col_right(board);
	return board;
}
Board * up(Board * board)
{
	shift_row_col_up(board);
	for (int row = 0; row < board->n - 1; row++)
	{
		for (int col = 0; col < board->n; col++)
		{
			if (board->table[row + 1][col] == board->table[row][col])
			{
				board->table[row][col] += board->table[row + 1][col];
				board->table[row + 1][col] = 0;
			}
		}
	}
	shift_row_col_up(board);
	return board;
}
Board * down(Board * board)
{
	shift_row_col_down(board);
	/*for (int row = 0; row < board->n - 1; row++)
	{
		for (int col = 0; col < board->n ; col++)
		{
			if (board->table[row + 1][col] == board->table[row][col])
			{
				board->table[row + 1][col] += board->table[row][col];
				board->table[row][col] = 0;
			}
		}
	}*/
	for (int row = board->n -1; row > 0; row--)
	{
		for (int col = 0; col < board->n; col++)
		{
			if (board->table[row - 1][col] == board->table[row][col])
			{
				board->table[row][col] += board->table[row - 1][col];
				board->table[row - 1][col] = 0;
			}
		}
	}
	shift_row_col_down(board);
	return board;
}