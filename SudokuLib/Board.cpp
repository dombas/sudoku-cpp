#include "Board.h"

using std::copy;

Board::Board() {
  for (board_index_datatype row = 0; row < 9; row++) {
    for (board_index_datatype column = 0; column < 9; column++) {
      board[row][column] = EMPTY_FIELD;
    }
  }
}

Board::Board(string &field_string) {
  field_datatype input_field[9][9];
  unsigned i_num = 0;
  for (int i_elem = 0; i_elem < field_string.size(); i_elem++) {
    if (isdigit(field_string[i_elem])) {
      input_field[i_num / 9][i_num % 9] = field_string[i_elem] - '0';
      i_num++;
    }
  }
  copy(&input_field[0][0], &input_field[0][0] + 9 * 9, &this->board[0][0]);
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

string Board::get_string() {
  char data[9 * 9 + 1];
  for (board_index_datatype row = 0; row < 9; row++) {
    for (board_index_datatype column = 0; column < 9; column++) {
      data[row * 9 + column] = (char)(this->board[row][column] + '0');
    }
  }
  data[81] = '\0';
  return std::string(data);
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
