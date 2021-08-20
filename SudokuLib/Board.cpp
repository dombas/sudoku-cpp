#include "Board.h"

using std::copy;

Board::Board() {
  for (board_index_datatype row = 0; row < 9; row++) {
    for (board_index_datatype column = 0; column < 9; column++) {
      board[row][column] = EMPTY_FIELD;
    }
  }
}

Board::Board(field_datatype board[9][9]) {
  copy(&board[0][0], &board[0][0] + 9 * 9, &this->board[0][0]);
}

field_datatype Board::get_value_of_field(board_index_datatype row,
                                         board_index_datatype column) {
  return board[row][column];
}

field_datatype *Board::get_col(board_index_datatype col) {
  static field_datatype board_col[9];

  for (board_index_datatype row = 0; row < 9; row++) {
    board_col[row] = board[row][col];
  }

  return board_col;
}

field_datatype *Board::get_row(board_index_datatype row) {
  static field_datatype board_row[9];

  for (board_index_datatype col = 0; col < 9; col++) {
    board_row[col] = board[row][col];
  }

  return board_row;
}

field_datatype *Board::get_square(board_index_datatype square_row,
                                  board_index_datatype square_col) {
  static field_datatype board_square[9];

  int i = 0;
  for (board_index_datatype row = square_row * 3; row < ((square_row * 3) + 3);
       row++) {
    for (board_index_datatype col = square_col * 3;
         col < ((square_col * 3) + 3); col++) {
      board_square[i] = board[row][col];
      i++;
    }
  }

  return board_square;
}

void Board::set_value_of_field(board_index_datatype row,
                               board_index_datatype column,
                               field_datatype value) {
  if (value < EMPTY_FIELD || value > 9) {
    throw IncorrectFieldValueException(row, column, value);
  }
  if (row < 0 || row >= 9 || column < 0 || column >= 9) {
    throw IndexOutOfBoardException(row, column, value);
  }
  board[row][column] = value;
}

bool Board::is_valid_group(field_datatype *board_data) {
  bool check[10] = {false};

  for (int i = 0; i < 9; i++) {
    if (board_data[i] != EMPTY_FIELD) {
      if (check[board_data[i]] == true) {
        return false;
      } else {
        check[board_data[i]] = true;
      }
    }
  }

  return true;
}