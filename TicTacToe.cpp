/*********************************************************************
** Author:		Billy R. Shelton
** Date:		3/15/2018
** Description: This is a implementation and client code file which defines the function
definitions created in the TicTacToe.hpp file.  Furthermore, this file askes the user
which player will go first, creates a TicTacToe object and starts the game.
The purpose of this file, the Board.hpp file, the TicTacToe.hpp file and the Bored.cpp 
files is to be able to play a game of tic-tac-toe.
*********************************************************************/

#include <iostream>
#include "TicTacToe.hpp"
#include "Board.hpp"
#include <string>

using namespace std;


/*********************************************************************
					TicTacToe::TicTacToe(char firstMove)
** Description:  This is the constructor which takes in 'o' or 'x' to
designate which player starts.  The variable playerTurn is initialized
and only an acceptable input is allowed.  
*********************************************************************/
TicTacToe::TicTacToe(char firstMove)
{
	while ((firstMove != 'o') && (firstMove != 'x'))			//if 'x' or 'o' is not entered
																//the user is asked to try again
	{
		cout << "Please enter o or x for the first player." << endl;
		cin >> firstMove;
		
	}
	playerTurn = firstMove;										//player turn is initialized 
}





/*********************************************************************
					void TicTacToe::play()
** Description:  This function starts the tic-tac-toe game.  It asks
the correct player for their move and sends it to the board until someone
has won or it's a draw, and then declares what the outcome was.  
*********************************************************************/
void TicTacToe::play()
{
	if (playerTurn == 'o')				//if player o starts then this go o,x,o,x... until someone wins or there is a draw
	{
		for (int i = 0; i < 6; i++)
		{
			int row, column;					//player O is asked to enter a position on the 
												//board via row and column number
			cout << "Player O: please enter your move." << endl;
			cout << "Row:";
			cin >> row;
			cout << "Column:";
			cin >> column;
			cout << endl;

												//this while loop ensures an available position is entered
			while (game.makeMove(row, column, playerTurn) == 0)
			{
				cout << "Invalid move.  Try again" << endl;
				cout << "Row:";
				cin >> row;
				cout << "Column:";
				cin >> column;
				cout << endl;
			}
			

			game.makeMove(row, column, playerTurn);		//the move is sent to the board
			game.print();								//the board is printed with the new move

			//cout << game.gameState();

			if (game.gameState() == 1)					//after player O's turn the board
														//is checked to see if Player O wins
														// or it is a draw
			{
				cout << "Player O Wins!";
				return;
			}

			else if (game.gameState() == 2)
			{
				cout << "The game is a draw.";
				return;

			}
			playerTurn = 'x';							//the next player turn is X


			for (int j = 0; j < 1; j++)
			{
													//player X is asked to enter a position on the 
													//board via row and column number
				cout << "Player X: please enter your move." << endl;
				cout << "Row:";
				cin >> row;
				cout << "Column:";
				cin >> column;
				cout << endl;

													//this while loop ensures an available position is entered
				while (game.makeMove(row, column, playerTurn) == 0)
				{
					cout << "Invalid Move.  Try again" << endl;
					cout << "Row:";
					cin >> row;
					cout << "Column:";
					cin >> column;
					cout << endl;
				}
				

				game.makeMove(row, column, playerTurn);		//the move is sent to the board
				game.print();								//the board is printed with the new move

				//cout << game.gameState();

				if (game.gameState() == 0)					//after player X's turn the board
															//is checked to see if Player X wins
															// or it is a draw
				{
					cout << "Player X Wins!";
					return;
				}

				else if (game.gameState() == 2)
				{
					cout << "The game is a draw.";
					return;

				}
				playerTurn = 'o';							//the next player turn is O
			}
		}
		

	}





	else if (playerTurn == 'x')			//if player x starts then this go x,o,x,o... until someone wins or there is a draw
	{
		for (int i = 0; i < 6; i++)
		{
										//player X is asked to enter a position on the 
										//board via row and column number
			int row, column;
			cout << "Player X: please enter your move." << endl;
			cout << "Row:";
			cin >> row;
			cout << "Column:";
			cin >> column;
			cout << endl;

										//this while loop ensures an available position is entered
			while (game.makeMove(row, column, playerTurn) == 0)
			{
				cout << "Invalid Move.  Try again" << endl;
				cout << "Row:";
				cin >> row;
				cout << "Column:";
				cin >> column;
				cout << endl;
			}
			
			game.makeMove(row, column, playerTurn);			//the move is sent to the board
			game.print();									//the board is printed with the new move

			//cout << game.gameState();
															//after player X's turn the board
															//is checked to see if Player X wins
															// or it is a draw
			if (game.gameState() == 0)
			{
				cout << "Player X Wins!";
				return;
	
			}
			else if (game.gameState() == 2)
			{
				cout << "The game is a draw.";
				return;
	
			}
			playerTurn = 'o';								//the next player turn is X


			for (int j = 0; j < 1; j++)
			{
															//player O is asked to enter a position on the 
															//board via row and column number
				cout << "Player O: please enter your move." << endl;
				cout << "Row:";
				cin >> row;
				cout << "Column:";
				cin >> column;
				cout << endl;
				cout << endl;
													//this while loop ensures an available position is entered
				while (game.makeMove(row, column, playerTurn) == 0)
				{
					cout << "Invalid Move.  Try again" << endl;
					cout << "Row:";
					cin >> row;
					cout << "Column:";
					cin >> column;
					cout << endl;
				}
				
				game.makeMove(row, column, playerTurn);		//the move is sent to the board
				game.print();								//the board is printed with the new move

				//cout << game.gameState();

															//after player O's turn the board
															//is checked to see if Player O wins
															// or it is a draw
				if (game.gameState() == 1)
				{
					cout << "Player O Wins!";
					return;
				
				}
				else if (game.gameState() == 2)
				{
					cout << "The game is a draw.";
					return;
				
				}
				playerTurn = 'x';
			}
		}


	}
	

}




						//This is the client code to play Tic-Tac-Toe
int main()
{
	char firstMove;
	cout << "Let's play a game of Tic-Tac_Toe!" << endl;
	cout << "Which player will go first, x or o?" << endl;
	cin >> firstMove;

	TicTacToe letsplay(firstMove);
	letsplay.play();
	return 0;

}
