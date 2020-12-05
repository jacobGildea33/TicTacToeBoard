/**
 * Unit Tests for TicTacToeBoard
**/

#include <gtest/gtest.h>
#include "TicTacToeBoard.h"
 
class TicTacToeBoardTest : public ::testing::Test
{
	protected:
		TicTacToeBoardTest(){} //constructor runs before each test
		virtual ~TicTacToeBoardTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

TEST(TicTacToeBoardTest, is_valid_space)
{
	TicTacToeBoard obj;
    Piece actual = obj.placePiece(2,2);
    ASSERT_TRUE(actual == X);
}
TEST(TicTacToeBoardTest, is_invalid_space)
{
	TicTacToeBoard obj;
    Piece actual = obj.placePiece(3,4);
    ASSERT_FALSE(actual == Invalid);
}

TEST(TicTacToeBoardTest, isWinner)
{
	TicTacToeBoard obj;
	obj.placePiece(1,1);
	obj.placePiece(2,1);
	obj.placePiece(1,2);
	obj.placePiece(2,2);
	obj.placePiece(1,3);
    Piece actual = obj.getWinner();
    ASSERT_TRUE(actual == X);
}
TEST(TicTacToeBoardTest, cats_game)
 {
	TicTacToeBoard obj;
	obj.placePiece(1,1);
	obj.placePiece(1,2);
	obj.placePiece(2,2);
	obj.placePiece(3,1);
	obj.placePiece(3,2);
	obj.placePiece(1,2);
	obj.placePiece(1,3);
	obj.placePiece(3,3);
	obj.placePiece(2,3);

    Piece actual = obj.getWinner();
    ASSERT_TRUE(actual == Invalid);
}

TEST(TicTacToeBoardTest, long_game)_invalid_placement
 {
	TicTacToeBoard obj;
	obj.placePiece(1,1);	
	obj.placePiece(1,2); 
	obj.placePiece(2,2);		
	obj.placePiece(3,1); 
	obj.placePiece(3,2);  
	obj.placePiece(1,2); 
	obj.placePiece(1,3); 
	obj.placePiece(3,3); 
	obj.placePiece(3,4); 

    Piece actual = obj.getWinner();
    ASSERT_TRUE(actual == Invalid);
}

TEST(TicTacToeBoardTest, long_game_winner)
 {
	TicTacToeBoard obj;
	obj.placePiece(1,1);
	obj.placePiece(1,2);
	obj.placePiece(2,2);
	obj.placePiece(3,1);
	obj.placePiece(3,2); 
	obj.placePiece(1,2);
	obj.placePiece(1,3);
	obj.placePiece(2,3);
	obj.placePiece(3,3);

    Piece actual = obj.getWinner();
    ASSERT_TRUE(actual == X);
}