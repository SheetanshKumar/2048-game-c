#include <stdlib.h>
#include <time.h>
#define _CRT_SECURE_NO_WARNINGS
typedef struct Board{
	int **table;
	int n;
};

Board * create_board();
Board * generate_random(Board * board);
void print_board(Board * board);
int count_available(Board * board);
int checkEqualBoards(Board * b1, Board * b2);


Board * create_board(int n)
{
	Board * board = (Board *)calloc(n, sizeof(Board));
	board->n = n;
	board->table = (int **)calloc(n, sizeof(int *));
	for (int i = 0; i < n; i++)
		board -> table[i] = (int *)calloc(n, sizeof(int));
	return generate_random(board);
}

Board * generate_random(Board * board)
{
	int *storeAvailable = (int *)calloc((board->n)*(board->n), sizeof(int));
	int count = 0;
	for (int row = 0; row < board->n; row++)
		for (int col = 0; col < board->n; col++)
			if (board->table[row][col] == 0)
				storeAvailable[count++] = row * 10 + col;
	
	if (count == 0)
		return board;

	srand(time(NULL));
	int random = rand() % count;
	random = storeAvailable[random];

	int row = random / 10;
	int col = random % 10;
	board->table[row][col] = 2;

	return board;
}

void print_board(Board * board)
{
	system("CLS");
	for (int row = 0; row < board->n; row++)
	{
		for (int col = 0; col < board->n; col++)
		{
			printf("\t%d", board->table[row][col]);
		}
		printf("\n");
	}
	fflush(stdin);
}

int count_available(Board * board)
{
	int count = 0;
	for (int row = 0; row < board->n; row++)
		for (int col = 0; col < board->n; col++)
			if (board->table[row][col] == 0)
				count++;
	return count;
}

int checkEqualBoards(Board * b1, Board * b2)
{
	int flag = 1;
	for (int i = 0; i < b1->n; i++)
	{
		for (int j = 0; j < b1->n; j++)
		{
			if (b1->table[i][j] != b2->table[i][j])
			{
				flag = 0;
				break;
			}
		}
	}
	return flag;
}
Board * copyBoard(Board * b1, Board * b2)
{
	int flag = 1;
	for (int i = 0; i < b1->n; i++)
	{
		for (int j = 0; j < b1->n; j++)
		{
			b1->table[i][j] = b2->table[i][j];
		}
	}
	return b1;
}

int checkWin(Board * b1)
{

	int n = b1->n;
	int maxnum = 2;
	for (int i = 1; i < n*n - n; i++)
		maxnum *= 2;
	if (n == 2)
		maxnum = 16;
	if (n == 3)
		maxnum = 128;
	//printf("%d", b1->table[2][2]);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			//printf("%d\n", b1->table[i][j]);
			if (b1->table[i][j] == maxnum)
				return 1;
	return 0;
}