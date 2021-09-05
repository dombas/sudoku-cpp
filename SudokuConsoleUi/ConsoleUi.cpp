#include "ConsoleUi.h"

#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::to_string;
using std::unique_ptr;

namespace Sudoku {
void ConsoleUi::print_frame_buffer() {
  for (size_t row = 0; row < frame_height; row++) {
    for (size_t column = 0; column < frame_width; column++) {
      cout << frame_buffer[row][column];
    }
    cout << '|' << endl;
  }
}

void ConsoleUi::clear_frame_buffer() {
  for (size_t row = 0; row < frame_height; row++) {
    for (size_t column = 0; column < frame_width; column++) {
      frame_buffer[row][column] = ' ';
    }
  }
}

char ConsoleUi::get_field(board_index_datatype row,
                          board_index_datatype column) {
  int value = board.get_value_of_field(row, column);
  return to_string(value).at(0);
}

void ConsoleUi::print_sudoku_row(board_index_datatype row) {
  int starting_row = horizontal_heading_total_size +
                     (1 + board_field_vertical_spacing) * row +
                     row / 3 * board_square_vertical_spacing;

  int starting_column = vertical_heading_total_size;
  for (board_index_datatype column = 0; column < 9; column++) {
    char character = get_field(row, column);
    int buffer_row = starting_row;
    int buffer_column =
        starting_column + (1 + board_field_horizontal_spacing) * column;
    ;
    frame_buffer[buffer_row][buffer_column] = character;
  }
}

void ConsoleUi::write_delimiting_rows() {
  int square_height   = 2 * board_field_vertical_spacing + 3;
  int starting_row    = square_height + horizontal_heading_total_size;
  int starting_column = vertical_heading_total_size;
  int row_length      = 8 * board_field_horizontal_spacing + 9;
  for (board_index_datatype row = 0; row < 2; row++) {
    for (board_index_datatype column = 0; column < row_length; column++) {
      char character    = row_delimiter;
      int buffer_row    = starting_row + (square_height + 1) * row;
      int buffer_column = starting_column + column;

      frame_buffer[buffer_row][buffer_column] = character;
    }
  }
}

void ConsoleUi::write_delimiting_columns() {
  int square_width    = 2 * board_field_horizontal_spacing + 3;
  int starting_row    = horizontal_heading_total_size;
  int starting_column = square_width + vertical_heading_total_size;
  int column_length   = 8 * board_field_vertical_spacing + 9 + 2;
  for (board_index_datatype column = 0; column < 2; column++) {
    for (board_index_datatype row = 0; row < column_length; row++) {
      char character    = column_delimiter;
      int buffer_row    = starting_row + row;
      int buffer_column = starting_column + (square_width + 1) * column;

      if (row_delimiter == frame_buffer[buffer_row][buffer_column]) {
        character = cross_delimiter;
      }

      frame_buffer[buffer_row][buffer_column] = character;
    }
  }
}

ConsoleUi::ConsoleUi() : frame_buffer() {
  field_datatype initial_board_values[9][9] = {
      {1, 2, 3, 4, 5, 6, 7, 8, 9},  //
      {7, 0, 9, 1, 0, 3, 4, 5, 6},  //
      {4, 5, 6, 7, 8, 9, 1, 2, 3},  //
      {3, 1, 0, 8, 4, 5, 9, 6, 7},  //
      {6, 0, 7, 3, 0, 2, 8, 4, 5},  //
      {8, 4, 5, 6, 9, 0, 0, 0, 2},  //
      {0, 0, 0, 5, 7, 4, 6, 9, 8},  //
      {9, 0, 0, 2, 3, 1, 5, 0, 4},  //
      {5, 7, 4, 9, 6, 8, 2, 3, 1},  //
  };
  board = Board(initial_board_values);
}

void ConsoleUi::game_loop() {
  string message = "";
  do {
    clear_screen();
    clear_frame_buffer();

    write_horizontal_header();
    write_vertical_header();
    write_board();
    write_delimiting_rows();
    write_delimiting_columns();

    print_frame_buffer();

    print_message(message);
    message = "";

    auto input = get_input();

    auto command = parse_input(input);

    if (command->is_valid()) {
      command->apply_to_board(this);
    }
    message = command->get_message();
  } while (1);
}

void ConsoleUi::write_board() {
  for (board_index_datatype row = 0; row < 9; row++) {
    print_sudoku_row(row);
  }
}

void ConsoleUi::write_horizontal_header() {
  int starting_row    = horizontal_heading_margin_top;
  int starting_column = vertical_heading_total_size;
  int spacing_between = board_field_horizontal_spacing;

  for (board_index_datatype column = 0; column < 9; column++) {
    char character    = column_symbols[column];
    int buffer_row    = starting_row;
    int buffer_column = starting_column + (1 + spacing_between) * column;
    frame_buffer[buffer_row][buffer_column] = character;
  }
}

void ConsoleUi::write_vertical_header() {
  int starting_row    = horizontal_heading_total_size;
  int starting_column = vertical_heading_margin_left;
  int spacing_between = board_field_vertical_spacing;

  for (board_index_datatype row = 0; row < 9; row++) {
    char character = row_symbols[row];
    int buffer_row = starting_row + (1 + spacing_between) * row +
                     row / 3 * board_square_vertical_spacing;
    int buffer_column                       = starting_column;
    frame_buffer[buffer_row][buffer_column] = character;
  }
}

void ConsoleUi::clear_screen() {
  // TODO: actually clear the screen
  cout << endl << string(50, '=') << endl << endl;
}

void ConsoleUi::print_message(string message) {
  if (message.length() > 0) {
    cout << endl << message << endl;
  }
}

string ConsoleUi::get_input() {
  string input;
  cout << "input:";
  cin >> input;
  return input;
}

unique_ptr<SudokuCommand> ConsoleUi::parse_input(string input) {
  return unique_ptr<SudokuCommand>(new SudokuCommand(input));
}

void ConsoleUi::set_value_of_field(board_index_datatype row,
                                   board_index_datatype column,
                                   field_datatype value) {
  board.set_value_of_field(row, column, value);
}

void ConsoleUi::solve() {
  Solver solver;
  board = solver.solve(board);
}

}  // namespace Sudoku