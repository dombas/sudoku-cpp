#pragma once
#include "Common.h"
class Board
{
protected:
	field_datatype board[9][9];

public:
	Board();
	Board(field_datatype board[9][9]);
	field_datatype get_value_of_field(board_index_datatype row, board_index_datatype column);
	field_datatype *get_row(board_index_datatype row);
	field_datatype *get_col(board_index_datatype col);
	field_datatype *get_square(board_index_datatype square_row, board_index_datatype square_col);
	void set_value_of_field(board_index_datatype row, board_index_datatype column, field_datatype value);
};
