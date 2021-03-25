#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <unistd.h>

enum CandleSign { Positive, Negative };
enum CandleKind { Long, Short };
enum CandlePatternSign { Bullish, Bearish };
enum CandlePatternShape { Engulfing, Harami };
enum Item { Square = '@', Line = '|', Space = ' ' };
enum Color { Black = 30, Red = 31, Blue = 34 };

struct Block {
  Item item = Space;
  Color color = Black;
};

void cprintf(Item item, Color color);
void clear_out();
Block **alloc_2d(Block **array, int width, int height);
void free_2d(Block **array, int width);

class CandleStick {
private:
  CandleSign c_sign;
  CandleKind c_kind;
  int high_price;
  int open_price;
  int close_price;
  int low_price;
  int center;

public:
  CandleStick(CandleSign _c_sign, CandleKind _c_kind, int _center);
  bool check_available(CandlePatternSign cp_sign, CandlePatternShape cp_shape);
  Block *give_candle(int center, int height);
};

class CandlePattern {
private:
  CandlePatternSign c_pattern_sign;
  CandlePatternShape c_pattern_shape;
  int width = 4;
  int height = 16;
  int center = 2;
  int turn = 0;
  Block **pattern;

public:
  CandlePattern(int _width, int _height, CandlePatternSign _c_pattern_sign,
                CandlePatternShape _c_pattern_shape);
  ~CandlePattern();
  void make_pattern();
  void make_column(CandleSign c_sign, CandleKind c_kind);
  Block **give_pattern();
};

class Chart {
private:
  int width = 32;
  int height = 16;
  int round = 0;
  int pattern_num = 0;
  Block **chart;

public:
  Chart(int _width, int _height);
  ~Chart();
  void print_chart();
  void add_pattern(CandlePatternSign cp_sign, CandlePatternShape cp_shape);
  void chart_game();
};