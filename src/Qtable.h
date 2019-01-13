#ifndef _QTABLE_H

#define _QTABLE_H

class Qtable {
public:
  Qtable(int s_size, int a_size);
  ~Qtable();
  void set(int s, int a, double q);
  double get(int s, int a);
  double max(int s);
  int select_action(int s);
  void print();
private:
  double **Qtable_;
  int num_s_, num_a_;
  int *i_max;
};

#endif
