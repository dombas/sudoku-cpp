#include "SudokuCommand.h"
#include "ConsoleUi.h"

using std::endl;
using std::string;
using std::to_string;

namespace Sudoku {

const string row_symbols    = "abcdefghi";
const string column_symbols = "123456789";
const string value_symbols  = "123456789";
const string solve_command  = "solve";

void SudokuCommand::parse_input() {
  value = EMPTY_FIELD;
  if (0 == input.find(solve_command)) {
    state = ParseState::solve;
  } else {
    for (char c : input) {
      size_t index = string::npos;
      if ('\0' == c || state == ParseState::all_found) {
        break;
      }
      switch (state) {
        case ParseState::no_row:
          index = row_symbols.find(c);
          if (string::npos != index) {
            row   = index;
            state = ParseState::no_column;
          }
          break;
        case ParseState::no_column:
          index = column_symbols.find(c);
          if (string::npos != index) {
            column = index;
            state  = ParseState::no_value;
          }
          break;
        case ParseState::no_value:
          index = value_symbols.find(c);
          if (string::npos != index) {
            value = index + 1;
            state = ParseState::all_found;
          }
          break;
      }
    }
  }

  std::ostringstream string_stream;

  switch (state) {
    case ParseState::no_row:
    case ParseState::no_column:
      string_stream << "\tUsage:" << endl;

      string_stream << "To edit fields:" << endl;
      string_stream << "a12" << endl;
      string_stream << "a - indicator of row, any from " << row_symbols << endl;
      string_stream << "1 - indicator of column, any from " << column_symbols
                    << endl;
      string_stream << "2 - value (if omitted will clear field)" << endl;

      string_stream << endl;

      string_stream << "To solve board, type \"" << solve_command << "\""
                    << endl;

      string_stream << endl;

      string_stream << "To display this message, type \"help\"" << endl;

      message = string_stream.str();
      break;
    case ParseState::no_value:
      valid = true;

      string_stream << "Clearing field at row " << row_symbols.at(row)
                    << ", column " << column_symbols.at(column);
      message = string_stream.str();

      this->row    = row;
      this->column = column;
      this->value  = value;
      break;
    case ParseState::all_found:
      valid = true;

      string_stream << "Setting field at row " << row_symbols.at(row)
                    << ", column " << column_symbols.at(column) << " to "
                    << to_string(value).at(0);
      message = string_stream.str();

      this->row    = row;
      this->column = column;
      this->value  = value;
      break;
    case ParseState::solve:
      valid = true;

      string_stream << "Solving board";
      message = string_stream.str();
      break;
  }
}

SudokuCommand::SudokuCommand(string input) : input(input), valid(false) {
  parse_input();
}

bool SudokuCommand::is_valid() { return valid; }

string SudokuCommand::get_message() { return string(message); }

void SudokuCommand::apply_to_board(ConsoleUi* consoleUi) {
  if (ParseState::solve == state) {
    consoleUi->solve();
  } else {
    consoleUi->set_value_of_field(row, column, value);
  }
}

}  // namespace Sudoku