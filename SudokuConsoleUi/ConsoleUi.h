#pragma once
#include <memory>

#include "../SudokuLib/Board.h"
#include "SudokuCommand.h"

using std::string;
using std::unique_ptr;

namespace Sudoku {

constexpr char column_delimiter  = '|';
constexpr char row_delimiter     = '-';
constexpr char cross_delimiter   = '+';
constexpr char spacing_character = ' ';

class ConsoleUi {
 protected:
  Board board;
  char get_field(board_index_datatype row, board_index_datatype column);
  void print_sudoku_row(board_index_datatype row,
                        uint8_t horizontal_spacing = 1);
  void print_delimiting_row(uint8_t horizontal_spacing = 1);
  void print_header_row(uint8_t horizontal_spacing = 1);
  void print_board();
  void print_header_before_row(board_index_datatype row,
                               uint8_t horizontal_spacing = 1);
  string spacing(uint8_t horizontal_spacing = 1);
  void clear_screen();
  void print_message(string message);
  string get_input();
  unique_ptr<SudokuCommand> parse_input(string input);

 public:
  ConsoleUi();
  void game_loop();
};
}  // namespace Sudoku
