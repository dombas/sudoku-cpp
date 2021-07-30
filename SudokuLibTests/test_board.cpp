#include "pch.h"
#include "../SudokuLib/Board.h"
#include "test.h"

// example test, Given...When...Then...
TEST(SudokuBoardTest, GivenEmptyBoardWhenCheckingEachFieldThenEmptyIsReturned) {
	Board board;

	for (int row = 0; row < 9; row++) {
		for (int column = 0; column < 9; column++) {
			// EXPECT_EQ(value to test, value that's correct)
			EXPECT_EQ(board.get_value_of_field(row, column), EMPTY_FIELD);
		}
	}
}