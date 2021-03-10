#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <unistd.h>

enum CandleSign { Positive, Negative };
enum CandleKind { Long, Short, Hammer, ReverseHammer };
enum Color { Black = 30, Red = 31, Blue = 34 };

void cprintf(std::string str, Color color);
int **alloc_2d(int **array, int width, int height);
void free_2d(int **array, int width);

class CandleStick {
private:
  CandleSign c_sign;
  CandleKind c_kind;
  int high_price;
  int open_price;
  int close_price;
  int low_price;

public:
  CandleStick(CandleSign _c_sign, CandleKind _c_kind);
};

class Chart {
private:
  int width;
  int height;
  int **matrix;
  int stretch;

public:
  Chart(int _width, int _height);
  ~Chart();
  // Print matrix
  void print_matrix();
};
