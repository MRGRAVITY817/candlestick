#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <unistd.h>

enum CandleSign { Positive, Negative };
enum CandleKind { Long, Short, Hammer, ReverseHammer };
enum CandlePatternSign { Bullish, Bearish };
enum CandlePatternShape { Engulfing, Harami };
enum Color { Black = 30, Red = 31, Blue = 34 };

void cprintf(std::string str, Color color);
void clear_out();
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
  void print_candle(int mean);
};

class Chart {
private:
  CandlePatternSign c_pattern_sign;
  CandlePatternShape c_pattern_shape;
  int width;
  int height;
  int **matrix;
  int stretch;

public:
  Chart(int _width, int _height);
  ~Chart();
  // Print matrix
  void print_matrix();
  void print_column();
};
