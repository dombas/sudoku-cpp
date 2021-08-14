#pragma once
#include "../SudokuLib/Board.h"
namespace Sudoku {

	constexpr char column_delimiter = '|';
	constexpr char row_delimiter = '-';
	constexpr char cross_delimiter = '+';
	constexpr char spacing_character = ' ';

	class ConsoleUi
	{
	protected:
		Board board;
		char get_field(board_index_datatype row, board_index_datatype column);
		void print_row(board_index_datatype row, uint8_t horizontal_spacing = 1);
		void print_delimiting_row(uint8_t horizontal_spacing = 1);
	public:
		ConsoleUi();
		void print_board();
	};
} // Sudoku
