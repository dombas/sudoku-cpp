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
	void set_value_of_field(board_index_datatype row, board_index_datatype column, field_datatype value);
};

