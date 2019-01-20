#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include "Qtable.h"
#include "Maze.h"

int move(int a, int &x, int &y, int x_size);
int xy2s(int x, int y, int x_size);
int s2x(int s, int x_size);
int s2y(int s, int x_size);
int epsilon_greedy(int epsilon, int s, int num_a, Qtable &qtable);
void print_maze_with_Q(int x_size, int y_size, Qtable &qtable, Maze &maze);

int move(int a, int &x, int &y, int x_size) {
  if (a == 0) {
    y = y + 1;
  } else if (a == 1) {
    x = x + 1;
  } else if (a == 2) {
    y = y - 1;
  } else {
    x = x - 1;
  }
  int sd;
  sd = xy2s(x, y, x_size);
  return sd;
}

int xy2s(int x, int y, int x_size) {
  int s;
  s = x + y * x_size;
  return s;
}

int s2x(int s, int x_size) {
  int x;
  x = s % x_size;
  return x;
}

int s2y(int s, int x_size) {
  int y;
  y = s / x_size;
  return y;
}

int epsilon_greedy(int epsilon, int s, int num_a, Qtable &qtable) {
  int a;
  if (rand() % 100 < epsilon) {
    a = rand() % num_a;
  } else {
    a = qtable.select_action(s);
  }
  return a;
}

void print_maze_with_Q(int x_size, int y_size, Qtable &qtable, Maze &maze) {
  for (int x = 0; x < x_size; x++) {
    for (int y = 0; y < y_size; y++) {
      int s = xy2s(x, y, x_size);
      double Qmax = qtable.max(s);
      if (Qmax == 0.0) {
        std::cout << std::setw(3) << maze.get(x, y);
      } else {
        int a = qtable.select_action(s);
        if (a == 0) {
          std::cout << "  >";
        } else if (a == 1) {
          std::cout << "  v";
        } else if (a == 2) {
          std::cout << "  <";
        } else {
          std::cout << "  ^";
        }
      }
    }
    std::cout << std::endl;
  }
}

int main() {
  int x_size = 10, y_size = 9;
  int x_init = 1, y_init = 1;
  double alpha = 0.5, gamma = 0.9;
  int x, y, s, a, sd;
  int num_step = 100, num_trial = 300;
  int num_s, num_a = 4;
  int reward;
  double Qmax;
  int epsilon = 10;

  num_s = x_size * y_size;

  srand((unsigned)time(NULL));

  Qtable qtable(num_s, num_a);

  Maze maze(x_size, y_size);

  std::cout << maze;

  x = x_init;
  y = y_init;
  s = xy2s(x, y, x_size);

  for (int i = 0; i < num_trial; i++) {
    std::cout << "trial=" << i << std::endl;
    for (int j = 0; j < num_step; j++) {
      a = epsilon_greedy(epsilon, s, num_a, qtable);
      sd = move(a, x, y, x_size);
      reward = maze.get(x, y);
      Qmax = qtable.max(sd);
      qtable.set(s, a, (1.0 - alpha) * qtable.get(s, a) + 
                     alpha * ((double)reward + gamma * Qmax));
      if (reward < 0) {
        x = x_init;
        y = y_init;
        s = xy2s(x, y, x_size);
        std::cout << "Fail" << std::endl;
        break;
      } else if (reward > 0) {
        x = x_init;
        y = y_init;
        s = xy2s(x, y, x_size);
        std::cout << "Sccess" << std::endl;
        break;
      } else {
        s = sd;
      }
    }
    print_maze_with_Q(x_size, y_size, qtable, maze);
  }
}

