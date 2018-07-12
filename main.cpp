#include <iostream>
#include <stdio.h>
#include "BoardUtils.h"
#include "movesUtils.h"
#include <conio.h>
//#include "movesUtils.h"
#include "UserUtils.h"
using namespace std;


int main()
{
	printf("\nEnter dimension for nxn board\n");
	int n = 4;
	scanf("%d", &n);
	Board * newBoard = create_board(n);
	print_board(newBoard);
	int win = 0;
	while (1)
	{
		printf("\nEnter input\n");
		char input;
		//scanf("%c", &input);
		input = _getch();
		if (is_valid_input(input))
		{
			Board * tempBoard = create_board(n);
			tempBoard = copyBoard(tempBoard, newBoard);
			newBoard = process_input(newBoard, input);
			print_board(newBoard);
			if (!checkEqualBoards(tempBoard, newBoard))
			{
				newBoard = generate_random(newBoard);
				print_board(newBoard);
			}
			//tempBoard = copyBoard(tempBoard, newBoard);
			if (checkWin(newBoard) && win == 0)
			{
				win = 1;
				char des = afterWin();
				if (des == 'y')
					continue;
				else if ( des == 'n')
				{
					printf("\nThank you for playing.\nSee you on the Leader Board!");
					break;
				}
			}
		}
		else
			printf("\nEnter Valid Input\n");
		fflush(stdin);
	}
	cin.get();
}