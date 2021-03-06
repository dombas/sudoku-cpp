#pragma once
#include <exception>
#include <sstream>
#include <string>

typedef char field_datatype;
constexpr field_datatype EMPTY_FIELD = 0;

typedef char board_index_datatype;

using std::ostringstream;
using std::string;

class IncorrectFieldValueException : virtual public std::exception {
 protected:
  board_index_datatype row_index;
  board_index_datatype column_index;
  field_datatype field_value;

 public:
  IncorrectFieldValueException(board_index_datatype row_index,
                               board_index_datatype column_index,
                               field_datatype field_value)
      : row_index(row_index),
        column_index(column_index),
        field_value(field_value) {}

  virtual const char* what() const throw() {
    ostringstream string_stream;
    string_stream << "Error: trying to assign incorrect value (" << +field_value
                  << ") to row (" << +row_index << "), column ("
                  << +column_index << ")";
    return string_stream.str().c_str();
    ;
  }

  virtual int get_row_index() const throw() { return row_index; }

  virtual int get_column_index() const throw() { return column_index; }

  virtual int get_field_value() const throw() { return field_value; }
};

class IndexOutOfBoardException : public IncorrectFieldValueException {
 public:
  IndexOutOfBoardException(board_index_datatype row_index,
                           board_index_datatype column_index,
                           field_datatype field_value)
      : IncorrectFieldValueException(row_index, column_index, field_value) {}
  virtual const char* what() const throw() {
    ostringstream string_stream;
    string_stream << "Error: trying to assign value (" << +field_value
                  << ") to out of board: row (" << +row_index << "), column ("
                  << +column_index << ")";
    return string_stream.str().c_str();
    ;
  }
};