#pragma once
#include "Common.h"
#include "Board.h"
class  Solver {
 private:
  bool backtrack(Board &board);

 public:
  Board solve(Board board);
};