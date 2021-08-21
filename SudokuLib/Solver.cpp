#include "Solver.h"
#include "Board.h"

bool Solver::backtrack(Board& board) {
  bool is_valid_row;
  bool is_valid_column;
  bool is_valid_square;
  if (!board.has_empty_fields()) {
    return true;
  } else {
    for (board_index_datatype row = 0; row < 9; row++) {
      for (board_index_datatype column = 0; column < 9; column++) {
        if (board.get_value_of_field(row, column) == EMPTY_FIELD) {
          for (field_datatype value = 1; value < 10; value++) {
            board.set_value_of_field(row, column, value);
            is_valid_row    = board.is_valid_group(board.get_row(row));
            is_valid_column = board.is_valid_group(board.get_col(column));
            is_valid_square = board.is_valid_group(board.get_square(row / 3, column / 3));
            if (is_valid_row && is_valid_column && is_valid_square) {
              if (backtrack(board) == true) return true;
            } else {
              board.set_value_of_field(row, column, EMPTY_FIELD);
            }
          }
          return false;
        }
      }
    }
  }
}

Board Solver::solve(Board board) { 
  backtrack(board);
  return board;
}