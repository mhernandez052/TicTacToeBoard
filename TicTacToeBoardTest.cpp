/**
 * Unit Tests for TicTacToeBoard
 **/

#include "TicTacToeBoard.h"
#include <gtest/gtest.h>

class TicTacToeBoardTest : public ::testing::Test {
protected:
  TicTacToeBoardTest() {}          // constructor runs before each test
  virtual ~TicTacToeBoardTest() {} // destructor cleans up after tests
  virtual void SetUp() {}    // sets up before each test (after constructor)
  virtual void TearDown() {} // clean up after each test, (before destructor)
};

/* EXAMPLE TEST FORMAT
TEST(TicTacToeBoardTest, unitTestName)
{
        ASSERT_TRUE(true);
}
*/

// EXAMPLE TEST FORMAT
// TEST(RandoTest, mostPopularZero) {
//   Rando rando;
//   ASSERT_EQ(rando.mostPopularDigit(0), 0);
// }

//////////// Toggle Turn Testing //////////////
TEST(TicTacToeBoardTest, toggleTurnsO) {
  TicTacToeBoard board;
  ASSERT_EQ(board.toggleTurn(), O);
}

TEST(TicTacToeBoardTest, toggleTurnsX) {
  TicTacToeBoard board;
  board.toggleTurn();
  ASSERT_EQ(board.toggleTurn(), X);
}
//////////// Piece Placing Testing //////////////
TEST(TicTacToeBoardTest, placePieceZeroZeroO) {
  TicTacToeBoard board;
  ASSERT_EQ(board.placePiece(0, 0), X);
}

TEST(TicTacToeBoardTest, placePieceZeroOneX) {
  TicTacToeBoard board;
  board.placePiece(0, 0);
  ASSERT_EQ(board.placePiece(0, 1), O);
}

TEST(TicTacToeBoardTest, placePieceOverlapX) {
  TicTacToeBoard board;
  board.placePiece(0, 0);
  ASSERT_EQ(board.placePiece(0, 0), X);
}

TEST(TicTacToeBoardTest, placePieceOverlapO) {
  TicTacToeBoard board;
  board.placePiece(0, 0);
  board.placePiece(0, 1);
  ASSERT_EQ(board.placePiece(0, 1), O);
}

TEST(TicTacToeBoardTest, placePieceOutsideNorth) {
  TicTacToeBoard board;
  ASSERT_EQ(board.placePiece(-1, 0), Invalid);
}

TEST(TicTacToeBoardTest, placePieceOutsideEast) {
  TicTacToeBoard board;
  ASSERT_EQ(board.placePiece(3, 0), Invalid);
}

TEST(TicTacToeBoardTest, placePieceOutsideSouth) {
  TicTacToeBoard board;
  ASSERT_EQ(board.placePiece(0, 3), Invalid);
}

TEST(TicTacToeBoardTest, placePieceOutsideWest) {
  TicTacToeBoard board;
  ASSERT_EQ(board.placePiece(-3, 0), Invalid);
}

TEST(TicTacToeBoardTest, placePieceBoardFilled) {
  TicTacToeBoard board;
  // Board Filler
  board.placePiece(1, 1);
  board.placePiece(1, 0);
  board.placePiece(1, 2);
  board.placePiece(2, 0);
  board.placePiece(0, 0);
  board.placePiece(2, 2);
  board.placePiece(2, 1);
  board.placePiece(0, 1);
  board.placePiece(0, 2);
  // O's turn now, but board is filled
  // Attempts to place O piece at 2,1 (2,1 is an X piece, and a winning move for
  // O)
  board.placePiece(2, 1);
  // Attempt Again, and if it wasn't overwritten, then this will return the
  // original X piece.
  ASSERT_EQ(board.placePiece(2, 1), X);
}

//////////// Piece Placing Testing //////////////

TEST(TicTacToeBoardTest, getPieceBlank) {
  TicTacToeBoard board;
  ASSERT_EQ(board.getPiece(0, 0), Blank);
}

TEST(TicTacToeBoardTest, getPieceX) {
  TicTacToeBoard board;
  board.placePiece(0, 0);
  ASSERT_EQ(board.getPiece(0, 0), X);
}

TEST(TicTacToeBoardTest, getPieceO) {
  TicTacToeBoard board;
  board.placePiece(0, 0);
  board.placePiece(0, 1);
  ASSERT_EQ(board.getPiece(0, 1), O);
}

TEST(TicTacToeBoardTest, getPieceInvalid) {
  TicTacToeBoard board;
  board.placePiece(0, 0);
  ASSERT_EQ(board.getPiece(4, 4), Invalid);
}

//////////// Winner Testing //////////////

TEST(TicTacToeBoardTest, getWinnerRow) {
  TicTacToeBoard board;
  board.placePiece(0, 0);
  board.placePiece(1, 0);
  board.placePiece(0, 1);
  board.placePiece(1, 2);
  board.placePiece(0, 2);
  ASSERT_EQ(board.getWinner(), X);
}

TEST(TicTacToeBoardTest, getWinnerColumn) {
  TicTacToeBoard board;
  board.placePiece(0, 0);
  board.placePiece(0, 1);
  board.placePiece(1, 0);
  board.placePiece(1, 1);
  board.placePiece(2, 0);
  ASSERT_EQ(board.getWinner(), X);
}

TEST(TicTacToeBoardTest, getWinnerDiagonalLR) {
  TicTacToeBoard board;
  board.placePiece(0, 0);
  board.placePiece(1, 0);
  board.placePiece(1, 1);
  board.placePiece(2, 0);
  board.placePiece(2, 2);
  ASSERT_EQ(board.getWinner(), X);
}

TEST(TicTacToeBoardTest, getWinnerDiagonalRL) {
  TicTacToeBoard board;
  board.placePiece(0, 2);
  board.placePiece(1, 0);
  board.placePiece(1, 1);
  board.placePiece(1, 2);
  board.placePiece(2, 0);
  ASSERT_EQ(board.getWinner(), X);
}

TEST(TicTacToeBoardTest, getWinnerNone) {
  TicTacToeBoard board;
  ASSERT_EQ(board.getWinner(), Invalid);
}

TEST(TicTacToeBoardTest, getWinnerCatsGame) {
  TicTacToeBoard board;
  board.placePiece(1, 1);
  board.placePiece(1, 0);
  board.placePiece(1, 2);
  board.placePiece(2, 0);
  board.placePiece(0, 0);
  board.placePiece(2, 2);
  board.placePiece(2, 1);
  board.placePiece(0, 1);
  board.placePiece(0, 2);
  ASSERT_EQ(board.getWinner(), Blank);
}
