/*********************************************************************
** Author:		Billy R. Shelton
** Date:		3/15/2018
** Description: This is an implementation file which defines the function
definitions created in the Board.hpp file.  The purpose of this file, the
Board.hpp file, the TicTacToe.hpp file and the TicTacToe.cpp files is to 
be able to play a game of tic-tac-toe.
*********************************************************************/

#include <iostream>
#include "Board.hpp"
#include <string>



/*********************************************************************
					Board::Board()
** Description:  This is the default constructor which puts periods 
in all the 9 spaces of a board when it is created. 
*********************************************************************/
Board::Board()
{												//these 2 for loops add a '.' to the board
												//array from left to right, top to bottom
	for (int i = 0; i < 3; i++)					
	{
		for (int j = 0; j < 3; j++)
		{
			board[i][j] = '.';
		}
	}
}




/*********************************************************************
		int Board::makeMove(int &x, int &y, char playerTurn)
** Description:  This function takes two coordinates x and y which 
correspond to the row and column of the a board.  It also takes in
which player's turn it is and then it appends either an 'x' or 'o'
value to the coordinates entered.  I
*********************************************************************/
int Board::makeMove(int &x, int &y, char playerTurn)
{
	int x1 = x;
	int y1 = y;
	if (board[x1][y1] == '.' && playerTurn == 'o')			//adds a 'o' to the position designated by player O
	{
		board[x1][y1] = 'o';
		return true;
	}

	else if (board[x1][y1] == '.' && playerTurn == 'x')		//adds a 'x' to the position designated by player X
	{
		board[x1][y1] = 'x';
		return true;
	}

	else													//if the space is taken, the function returns false
	{
		return false;
	}

}



/*********************************************************************
				outcome Board::gameState()
** Description:  This function determines if player X has won, player
O has won, there is a draw or if the game is unfinished.  
*********************************************************************/
outcome Board::gameState()
{

	int horizontal = 0, vertical = 0;

	for (int i = 0; i < 3; i++)				//checks to see if player o won
	{
		horizontal = 0, vertical = 0;
		for (int j = 0; j < 3; j++)
		{
			if (board[i][j] == 'o')			//counts the number of o values in each row separately
			{
				horizontal++;
			}

			if (board[j][i] == 'o')			//counts the number of o values in each column separately
			{
				vertical++;
			}
											////if there are 3 o's in diagonal 1, o wins
			if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] == 'o')
			{
				return O_WON;
			}
											//if there are 3 o's in diagonal 2, o wins
			if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[2][0] == 'o')
			{
				return O_WON;
			}

		    if (horizontal >= 3)			//if there are 3 o's in a row, o wins
			{
				return O_WON;
			}

			if (vertical >=3)				//if there are 3 o's in a column, o wins
			{
				return O_WON;
			}

		}
	}


	for(int i = 0; i < 3; i++)				//checks to see if player x won
	{
		horizontal = 0, vertical = 0;
		for (int j = 0; j < 3; j++)
		{
			if (board[i][j] == 'x')			//counts the number of x values in each row separately
			{
				horizontal++;
			}

			if (board[j][i] == 'x')			//counts the number of x values in each column separately
			{
				vertical++;
			}
											//if there are 3 x's in diagonal 1, x wins
			if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] == 'x')
			{
				return X_WON;
			}
											//if there are 3 x's in diagonal 2, x wins
			if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[2][0] == 'x')
			{
				return X_WON;
			}
							
		    if (horizontal == 3)			//if there are 3 x's in a row, x wins
			{
				return X_WON;
			}

			if (vertical == 3)				//if there are 3 x's in a column, x wins
			{
				return X_WON;
			}
		}
	}

	for (int count = 0; count < 3; count++)		 //if there are still blank spaces that means the game is unfinised
												//these 2 for loops check for any blank spaces
	{
		for (int count2 = 0; count2 < 3; count2++)
		{
			if (board[count][count2] == '.')
			{
				return UNFINISHED;
			}
		}
	}



	return DRAW;					//if nothing has been returned yet the game is a draw

}






/*********************************************************************
					void Board::print()
** Description:  This function prints out the current board to screen.
*********************************************************************/
void Board::print()
{
	cout << "  " << "0 1 2" << endl;
	cout << "0 " << board[0][0] << " " << board[0][1] << " " << board[0][2] << endl;
	cout << "1 " << board[1][0] << " " << board[1][1] << " " << board[1][2] << endl;
	cout << "2 " << board[2][0] << " " << board[2][1] << " " << board[2][2] << endl;
	cout << endl;
}

