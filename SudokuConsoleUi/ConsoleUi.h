#pragma once
#include <array>
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

constexpr int frame_width  = 40;
constexpr int frame_height = 15;

constexpr int vertical_heading_margin_left  = 1;
constexpr int vertical_heading_margin_right = 2;
constexpr int vertical_heading_total_size =
    vertical_heading_margin_left + vertical_heading_margin_right + 1;

constexpr int horizontal_heading_margin_top    = 1;
constexpr int horizontal_heading_margin_bottom = 1;
constexpr int horizontal_heading_total_size =
    horizontal_heading_margin_top + horizontal_heading_margin_bottom + 1;

constexpr int board_field_vertical_spacing   = 0;
constexpr int board_field_horizontal_spacing = 1;
constexpr int board_square_vertical_spacing  = 1;

class ConsoleUi {
 protected:
  Board board;
  std::array<std::array<char, frame_width>, frame_height> frame_buffer;

  void print_frame_buffer();
  void clear_frame_buffer();

  char get_field(board_index_datatype row, board_index_datatype column);
  void print_sudoku_row(board_index_datatype row);
  void write_delimiting_rows();
  void write_delimiting_columns();
  void write_horizontal_header();
  void write_vertical_header();
  void write_board();

  void clear_screen();
  void print_message(string message);
  string get_input();
  unique_ptr<SudokuCommand> parse_input(string input);

 public:
  ConsoleUi();
  void game_loop();
};
}  // namespace Sudoku
