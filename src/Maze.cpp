#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include "Maze.h"

Maze::Maze(int x_size, int y_size) {
  int i, j;
  x_size_ = x_size;
  y_size_ = y_size;
  maze_ = new int*[x_size_];
  for (i = 0; i < x_size_; i++) {
     maze_[i] = new int[y_size_];
  }
  for (i = 0; i < x_size_; i++) {
    for (j = 0; j < y_size_; j++) {
      if (i == 0 || j == 0 || i == (x_size_ - 1) || j == (y_size_ - 1)) {
        maze_[i][j] = -1;
      } else {
        maze_[i][j] = 0;
      }
    }
  }
  maze_[2][2] = -1;
  maze_[3][2] = -1;
  maze_[6][3] = -1;
  maze_[7][3] = -1;
  maze_[8][3] = -1;
  maze_[2][6] = -1;
  maze_[2][7] = -1;
  maze_[3][6] = -1;
  maze_[6][7] = -1;
  maze_[8][6] = 10;
}

Maze::~Maze() {
  int i;
  for (i = 0; i < x_size_; i++) {
    delete[] maze_[i];
  }
  delete[] maze_;
}

int Maze::get(int x, int y) {
  return maze_[x][y];
}

void Maze::print(std::ostream *os) {
  int i, j;
  for (i = 0; i < x_size_; i++) {
    for (j = 0; j < y_size_; j++) {
      *os << std::setw(3) << maze_[i][j];
    }
    *os << std::endl;
  }
}

std::ostream &operator<<(std::ostream &os, Maze &maze) {
  maze.print(&os);
  return os;
}

