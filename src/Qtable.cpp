#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "Qtable.h"

Qtable::Qtable(int num_s, int num_a) {
  int i, j;
  num_s_ = num_s;
  num_a_ = num_a;
  Qtable_ = new double*[num_s_];
  for (i = 0; i < num_s_; i++) {
    Qtable_[i] = new double[num_a_];
  }
  for (i = 0; i < num_s_; i++) {
    for (j = 0; j < num_a_; j++) {
      Qtable_[i][j] = 0;
    }
  }
  i_max = new int[num_a_];
}

Qtable::~Qtable() {
  int i;
  for (i = 0; i < num_s_; i++) {
    delete[] Qtable_[i];
  }
  delete[] Qtable_;
  delete[] i_max;
}

void Qtable::set(int s, int a, double q) {
  if (s < 0 || s >= num_s_ || a < 0 || a >= num_a_) {
    printf("Qtable::set: invalid value s = %d, a = %d\n", s, a);
    exit(1);
  }
  Qtable_[s][a] = q;
}

double Qtable::get(int s, int a) {
  if (s < 0 || s >= num_s_ || a < 0 || a >= num_a_) {
    printf("Qtable::get: invalid value s = %d, a = %d\n", s, a);
    exit(1);
  }
  return Qtable_[s][a];
}

double Qtable::max(int s) {
  int i;
  double max;
  if (s < 0 || s >= num_s_) {
    printf("Qtable::max: invalid value s = %d\n", s);
    exit(1);
  }
  max = Qtable_[s][0];
  for (i = 1; i < num_a_; i++) {
    if (Qtable_[s][i] > max) {
      max = Qtable_[s][i];
    }
  }
  return max;
}

int Qtable::select_action(int s) {
  double max;
  int i;
  int num_i_max = 1;
  int a;

  i_max[0] = 0;
  max = Qtable_[s][0];

  for (i = 1; i < num_a_; i++) {
    if (Qtable_[s][i] > max) {
      max = Qtable_[s][i];
      num_i_max = 1;
      i_max[0] = i;
    } else if (Qtable_[s][i] == max) {
      i_max[num_i_max++] = i;
    }
  }
  a = i_max[rand() % num_i_max];
  return a;
}

void Qtable::print() {
  int i, j;

  for (i = 0; i < num_s_; i++) {
    for (j = 0; j < num_a_; j++) {
      printf(" %lf", Qtable_[i][j]);
    }
    printf("\n");
  }
}
