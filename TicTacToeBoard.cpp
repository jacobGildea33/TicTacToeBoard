#include "TicTacToeBoard.h"
/**
 * Class for representing a 3x3 Tic-Tac-Toe game board, using the Piece enum
 * to represent the spaces on the board.
**/

//Constructor sets an empty board and specifies it is X's turn first
TicTacToeBoard::TicTacToeBoard()
{
  turn = X;
  for(int i=0; i<BOARDSIZE; i++)
    for(int j=0; j<BOARDSIZE; j++)
      board[i][j] = Blank;
}

/**
 * Switches turn member variable to represent whether it's X's or O's turn
 * and returns whose turn it is
**/
Piece TicTacToeBoard::toggleTurn()
{
  int turnCount = 0;

  if (turnCount % 2 = 0){
    turn = X;
  } else{
    turn = O
  }
  if(turnCount > 9){
    turn = Invalid;
  }
  return turn;
}

/**
 * Places the piece of the current turn on the board, returns what
 * piece is placed, and toggles which Piece's turn it is. placePiece does 
 * NOT allow to place a piece in a location where there is already a piece.
 * In that case, placePiece just returns what is already at that location. 
 * Out of bounds coordinates return the Piece Invalid value. When the game
 * is over, no more pieces can be placed so attempting to place a piece
 * should neither change the board nor change whose turn it is.
**/ 
Piece TicTacToeBoard::placePiece(int row, int column)
{
  Piece result;
  
  if(row > 3 || column > 3){
    result = Invalid;
  }

  while(!gameOver){
    for(int c = 0; c<BOARDSIZE; c++{
      for(int r = 0; r<BOARDSIZE; r++){
        if(c = column && r = row){
          board[c][r] = turn;
          result = trun;
        }
      }
    })
  }
  return result;
}

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
**/
Piece TicTacToeBoard::getPiece(int row, int column)
{
  if(row > 3 || column > 3){
    return Invalid;
  }
  
  for(int c = 0; c<BOARDSIZE; c++){
    for(int r = 0; r<BOARDSIZE; r++){
      if (c == column && r == row){
        return board[c][r];
      }
    }
  }
}

/**
 * Returns which Piece has won, if there is a winner, Invalid if the game
 * is not over, or Blank if the board is filled and no one has won.
**/
Piece TicTacToeBoard::getWinner()
{
  Piece temp;
  Piece result;
  int Xr = 0;
  int Xc = 0;
  int Or = 0;
  int Oc = 0;

  for(int c = 0; c<BOARDSIZE; c++){
    for(int r = 0; r<BOARDSIZE; r++){
      temp = board[c][r].getPiece();
      
      if(temp == x){
        Xr++;
      }
      if(temp == O){
        Or++;
      }
    }
    if(Xr == 3){
      result = X;
    } else if(Or == 3){
      result = O;
    } else if (Xr >= 1){
      Xc++;
    } else if(Or >= 1){
      Oc++;
    }
  }
  if(Xc == 3){
    result = X;
  }
  if (Oc == 3){
    result = O;
  }
  if(temp == blank){
    return temp;
  }
  
  temp = board[2][2].getPiece()

  if((board[1][1].getPiece == temp && board[3][3] == temp) || (board[3][1].getPiece == temp && board[1][3] == temp)){
    result = temp;
  }

  return result;
}
