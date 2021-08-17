#include "Board.h"

using std::copy;

Board::Board()
{
	for (board_index_datatype row = 0; row < 9; row++) {
		for (board_index_datatype column = 0; column < 9; column++) {
			board[row][column] = EMPTY_FIELD;
		}
	}
}

Board::Board(field_datatype board[9][9])
{
	copy(&board[0][0], &board[0][0] + 9 * 9, &this->board[0][0]);
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
