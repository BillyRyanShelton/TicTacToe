#pragma once
/*********************************************************************
** Author:		Billy R. Shelton
** Date:		11/22/2016
** Description: This is a header file which creates the class Board.  The
class has 1 data member which is a 3x3 array. The member functions are named
but not defined here.  The purpose of this file, the Board.cpp file, the 
TicTacToe.hpp file and the TicTacToe.cpp files is to be able to play a game 
of tic-tac-toe.  
*********************************************************************/


#ifndef BOARD_HPP
#define BOARD_HPP
#include <string>

using namespace std;

enum outcome {X_WON, O_WON, DRAW, UNFINISHED};				//data type named outcome is created

class Board													//a class called Board is created
{
	private:
		char board[3][3];									//3x3 array data member is created

	public:													//member function prototypes are created
		Board();											//default constructor
		int makeMove(int &x, int &y, char playerTurn);		
		outcome gameState();
		void print();
};

#endif
