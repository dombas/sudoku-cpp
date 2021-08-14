#include "Board.h"


Board::Board()
{
	for (board_index_datatype row = 0; row < 9; row++) {
		for (board_index_datatype column = 0; column < 9; column++) {
			board[row][column] = EMPTY_FIELD;
		}
	}
}

field_datatype Board::get_value_of_field(board_index_datatype row, board_index_datatype column) {
	return board[row][column];
}

void Board::set_value_of_field(board_index_datatype row, board_index_datatype column, field_datatype value)
{
	if (value < EMPTY_FIELD || value > 9) {
		throw IncorrectFieldValueException(row, column, value);
	}
	if (row < 0 || row >= 9 || column < 0 || column >= 9) {
		throw IndexOutOfBoardException(row, column, value);
	}
	board[row][column] = value;
}
