#pragma once
#include <string>

#include "../SudokuLib/Board.h"

using std::string;

namespace Sudoku {

class ConsoleUi;

extern const string row_symbols;
extern const string column_symbols;
extern const string value_symbols;

enum class ParseState { no_row, no_column, no_value, all_found, solve };

class SudokuCommand {
 protected:
  const string input;
  string message;
  bool valid;
  ParseState state = ParseState::no_row;
  board_index_datatype row, column;
  field_datatype value;

  void parse_input();

 public:
  SudokuCommand(string input);
  bool is_valid();
  string get_message();
  void apply_to_board(ConsoleUi* consoleUi);
};
}  // namespace Sudoku
