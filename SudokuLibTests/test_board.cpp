#include "pch.h"
#include "../SudokuLib/Board.h"
#include "test.h"

// example test, given...when...then...
TEST(SudokuBoardTest, given_empty_board_when_checking_each_field_then_empty_is_returned) {
	Board board;

	for (int row = 0; row < 9; row++) {
		for (int column = 0; column < 9; column++) {
			// EXPECT_EQ(value to test, value that's correct)
			EXPECT_EQ(board.get_value_of_field(row, column), EMPTY_FIELD);
		}
	}
}

TEST(SudokuBoardTest, given_edited_board_when_checking_fields_then_correct_values_are_returned) {
	Board board;

	board.set_value_of_field(4, 3, 9);
	board.set_value_of_field(0, 0, 3);
	board.set_value_of_field(6, 8, 5);

	EXPECT_EQ(board.get_value_of_field(4, 3), 9);
	EXPECT_EQ(board.get_value_of_field(0, 0), 3);
	EXPECT_EQ(board.get_value_of_field(6, 8), 5);
}

TEST(SudokuBoardTest, given_edited_board_when_setting_incorrect_value_then_exception_is_thrown) {
	Board board;

	EXPECT_THROW(board.set_value_of_field(0, 0, 10), IncorrectFieldValueException);
	EXPECT_THROW(board.set_value_of_field(0, 0, -1), IncorrectFieldValueException);
}