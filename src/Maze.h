#ifndef _MAZE_H

#define _MAZE_H

#include <iostream>

class Maze {
public:
  Maze(int x_size, int y_size);
  ~Maze();
  int get(int x, int y);
  void print(std::ostream *os);

private:
  int **maze_;
  int x_size_, y_size_;
};

std::ostream &operator<<(std::ostream &os, Maze &maze);

#endif
