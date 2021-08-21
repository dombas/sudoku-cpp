#pragma once
#include "Common.h"
class Board {
 protected:
  field_datatype board[9][9];

 public:
  Board();
  Board(field_datatype board[9][9]);
  Board(string &field_string);
  field_datatype get_value_of_field(board_index_datatype row,
                                    board_index_datatype column);
  field_datatype *get_row(board_index_datatype row);
  field_datatype *get_col(board_index_datatype col);
  field_datatype *get_square(board_index_datatype square_row,
                             board_index_datatype square_col);
  string get_string();
  void set_value_of_field(board_index_datatype row, board_index_datatype column,
                          field_datatype value);
  bool is_valid_group(field_datatype *board_data);
  bool has_empty_fields();
};
