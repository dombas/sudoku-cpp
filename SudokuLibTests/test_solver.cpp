#include "pch.h"
#include "test.h"

TEST(SudokuSolverTest,
     given_valid_board_when_solving_board_then_solution_is_correct) {
  field_datatype board_values_input[9][9] = {
      {1, 2, 3, 4, 5, 6, 7, 8, 9},  //
      {7, 0, 9, 1, 0, 3, 4, 5, 6},  //
      {4, 5, 6, 7, 8, 9, 1, 2, 3},  //
      {3, 1, 0, 8, 4, 5, 9, 6, 7},  //
      {6, 0, 7, 3, 0, 2, 8, 4, 5},  //
      {8, 4, 5, 6, 9, 0, 0, 0, 2},  //
      {0, 0, 0, 5, 7, 4, 6, 9, 8},  //
      {9, 0, 0, 2, 3, 1, 5, 0, 4},  //
      {5, 7, 4, 9, 6, 8, 2, 3, 1},  //
  };
  field_datatype board_values_target[9][9] = {
      {1, 2, 3, 4, 5, 6, 7, 8, 9},  //
      {7, 8, 9, 1, 2, 3, 4, 5, 6},  //
      {4, 5, 6, 7, 8, 9, 1, 2, 3},  //
      {3, 1, 2, 8, 4, 5, 9, 6, 7},  //
      {6, 9, 7, 3, 1, 2, 8, 4, 5},  //
      {8, 4, 5, 6, 9, 7, 3, 1, 2},  //
      {2, 3, 1, 5, 7, 4, 6, 9, 8},  //
      {9, 6, 8, 2, 3, 1, 5, 7, 4},  //
      {5, 7, 4, 9, 6, 8, 2, 3, 1},  //
  };
  Solver solver;
  Board board_input    = Board(board_values_input);
  Board board_target   = Board(board_values_target);
  Board board_solved   = solver.solve(board_input);
  string string_solved = board_solved.get_string();
  string string_target = board_target.get_string();
  EXPECT_EQ(string_solved, string_target);
}

TEST(SudokuSolverTest,
     given_empty_board_when_solving_board_then_solution_is_correct) {
  Solver solver;
  Board board_input    = Board();
  Board board_solved   = solver.solve(board_input);
  string string_solved = board_solved.get_string();
  string string_target =
      "123456789"
      "456789123"
      "789123456"
      "214365897"
      "365897214"
      "897214365"
      "531642978"
      "642978531"
      "978531642";
  EXPECT_EQ(string_solved, string_target);
}

TEST(SudokuSolverTest,
     given_empty_board_when_solving_board_then_original_board_is_not_modified) {
  Solver solver;
  Board board_input    = Board();
  Board board_solved   = solver.solve(board_input);
  EXPECT_EQ(board_input.get_string(), Board().get_string());
}