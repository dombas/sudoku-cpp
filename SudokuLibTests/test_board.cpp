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

TEST(SudokuBoardTest, given_array_constructor_when_checking_fields_then_correct_values_are_returned) {
	field_datatype board_values[9][9] = {{1,2,3,4,5,6,7,8,9},
										 {2,3,4,5,6,7,8,9,1},
										 {3,4,5,6,7,8,9,1,2},
										 {4,5,6,7,8,9,1,2,3},
										 {5,6,7,8,9,1,2,3,4},
										 {6,7,8,9,1,2,3,4,5},
										 {7,8,9,1,2,3,4,5,6},
										 {8,9,1,2,3,4,5,6,7},
										 {9,1,2,3,4,5,6,7,8},};
	Board board(board_values);
	EXPECT_EQ(board.get_value_of_field(0, 0), 1);
	EXPECT_EQ(board.get_value_of_field(0, 8), 9);
	EXPECT_EQ(board.get_value_of_field(8, 0), 9);
	EXPECT_EQ(board.get_value_of_field(8, 8), 8);
	EXPECT_EQ(board.get_value_of_field(5, 6), 3);
	EXPECT_EQ(board.get_value_of_field(4, 1), 6);
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

TEST(SudokuBoardTest, given_edited_board_when_setting_value_out_of_board_then_exception_is_thrown) {
	Board board;

	EXPECT_THROW(board.set_value_of_field(-1, 0, 1), IndexOutOfBoardException);
	EXPECT_THROW(board.set_value_of_field(0, -1, 1), IndexOutOfBoardException);
	EXPECT_THROW(board.set_value_of_field(9, 0, 1), IndexOutOfBoardException);
	EXPECT_THROW(board.set_value_of_field(0, 9, 1), IndexOutOfBoardException);
}