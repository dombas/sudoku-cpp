#pragma once
#include "../SudokuLib/Board.h"
#include <string>
using std::string;

namespace Sudoku {
	class SudokuCommand
	{
	protected:
		string message;
	public:
		SudokuCommand();
		bool is_valid();
		string get_message();
		void set_message(string message);
		void apply_to_board(Board& board);
	};
} // Sudoku

