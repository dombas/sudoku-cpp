#include "SudokuCommand.h"

namespace Sudoku {
    SudokuCommand::SudokuCommand()
    {
    }

    bool SudokuCommand::is_valid()
    {
        return false;
    }
    string SudokuCommand::get_message()
    {
        return string(message);
    }
    void SudokuCommand::set_message(string message)
    {
        this->message = string("I got this: ") + message;
    }
    void SudokuCommand::apply_to_board(Board& board)
    {

    }
} // Sudoku