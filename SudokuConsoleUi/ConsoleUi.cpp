#include "ConsoleUi.h"

#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::to_string;
using std::unique_ptr;

namespace Sudoku {

char ConsoleUi::get_field(board_index_datatype row,
                          board_index_datatype column) {
  int value = board.get_value_of_field(row, column);
  return to_string(value).at(0);
}

void ConsoleUi::print_row(board_index_datatype row,
                          uint8_t horizontal_spacing) {
  for (board_index_datatype column = 0; column < 9; column++) {
    if (column % 3 == 0 && column > 0) {
      cout << column_delimiter;
    }
    cout << string(horizontal_spacing, spacing_character)
         << get_field(row, column)
         << string(horizontal_spacing, spacing_character);
  }
  cout << endl;
}

void ConsoleUi::print_delimiting_row(uint8_t horizontal_spacing) {
  for (board_index_datatype column = 0; column < 9; column++) {
    if (column % 3 == 0 && column > 0) {
      cout << cross_delimiter;
    }
    cout << string(horizontal_spacing * 2 + 1, row_delimiter);
    ;
  }
  cout << endl;
}

ConsoleUi::ConsoleUi() {
  board.set_value_of_field(0, 0, 1);
  board.set_value_of_field(1, 1, 2);
  board.set_value_of_field(2, 2, 3);
  board.set_value_of_field(3, 3, 4);
  board.set_value_of_field(4, 4, 5);
  board.set_value_of_field(5, 5, 6);
  board.set_value_of_field(6, 6, 7);
  board.set_value_of_field(7, 7, 8);
  board.set_value_of_field(8, 8, 9);
}

void ConsoleUi::game_loop() {
  string message = "";
  do {
    clear_screen();

    print_board();

    print_message(message);

    auto input = get_input();

    auto command = parse_input(input);

    if (command->is_valid()) {
      command->apply_to_board(board);
    } else {
      message = command->get_message();
    }
  } while (1);
}

void ConsoleUi::print_board() {
  for (board_index_datatype row = 0; row < 9; row++) {
    if (row % 3 == 0 && row > 0) {
      print_delimiting_row();
    }
    print_row(row);
  }
}

void ConsoleUi::clear_screen() {
  // TODO: actually clear the screen
  cout << endl << string(30, '=') << endl << endl;
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

}  // namespace Sudoku