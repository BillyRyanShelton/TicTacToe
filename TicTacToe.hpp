#pragma once
/*********************************************************************
** Author:		Billy R. Shelton
** Date:		11/22/2016
** Description: This is a header file which creates the class TicTacToe.  The
class has 2 data members, an object constructed from the board class and a char
which specifices the player turn.  The member functions are named but not defined
here.  The purpose of this file, the Board.hpp file, the TicTacToe.cpp file and 
the Bored.cpp files is to be able to play a game of tic-tac-toe.
*********************************************************************/

#include "Board.hpp"
#ifndef TICTACTOE_HPP
#define TICTACTOE_HPP
#include <string>

using namespace std;

class TicTacToe							//a class called TicTacToe is created
{
	private:
		Board game;						//board object is created 
		char playerTurn;				//a data member which keeps track of the current player's turn
		
	public:
		TicTacToe(char firstMove);		//constructor which initializes playerTurn
		void play();					//function which starts the game
		
};

#endif
