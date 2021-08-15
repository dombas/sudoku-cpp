#pragma once
#include "../SudokuLib/Board.h"
#include <string>

using std::string;

namespace Sudoku {
	class SudokuCommand
	{
	protected:
		const string input;
		string message;
		bool valid;
		board_index_datatype row, column;
		field_datatype value;

		void parse_input();
	public:
		SudokuCommand(string input);
		bool is_valid();
		string get_message();
		void apply_to_board(Board& board);
	};
} // Sudoku

