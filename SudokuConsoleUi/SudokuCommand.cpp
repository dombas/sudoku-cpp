#include "SudokuCommand.h"

using std::endl;
using std::string;
using std::to_string;

namespace Sudoku {
void SudokuCommand::parse_input() {
  const string row_symbols    = "abcdefghi";
  const string column_symbols = "123456789";
  const string value_symbols  = "123456789";

  enum class ParseState { no_row, no_column, no_value, all_found };
  ParseState state = ParseState::no_row;

  board_index_datatype row, column;
  field_datatype value = EMPTY_FIELD;

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

  std::ostringstream string_stream;

  switch (state) {
    case ParseState::no_row:
    case ParseState::no_column:
      string_stream << "Usage:" << endl;
      string_stream << "a12" << endl;
      string_stream << "a - indicator of row, any from " << row_symbols << endl;
      string_stream << "1 - indicator of column, any from " << column_symbols
                    << endl;
      string_stream << "2 - value (if omitted will clear field)" << endl;

      message = string_stream.str();
      break;
    case ParseState::no_value:
      valid = true;

      string_stream << "Clearing field at row " << to_string(row).at(0)
                    << ", column " << to_string(column).at(0);
      message = string_stream.str();

      this->row    = row;
      this->column = column;
      this->value  = value;
      break;
    case ParseState::all_found:
      valid = true;

      string_stream << "Setting field at row " << to_string(row).at(0)
                    << ", column " << to_string(column).at(0) << " to "
                    << to_string(value).at(0);
      message = string_stream.str();

      this->row    = row;
      this->column = column;
      this->value  = value;
      break;
  }
}

SudokuCommand::SudokuCommand(string input) : input(input), valid(false) {
  parse_input();
}

bool SudokuCommand::is_valid() { return valid; }

string SudokuCommand::get_message() { return string(message); }

void SudokuCommand::apply_to_board(Board& board) {
  board.set_value_of_field(row, column, value);
}

}  // namespace Sudoku