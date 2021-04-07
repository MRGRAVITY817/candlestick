#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <unistd.h>

enum CandleSign { Positive, Negative };
enum CandleKind { Long, Short };
enum CandlePatternSign { Bullish, Bearish };
enum CandlePatternShape { Engulfing, Harami };
enum Item { Square, Line, Space };
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
  CandleSign c_sign = Positive;
  CandleKind c_kind = Long;
  int high_price = 0;
  int open_price = 0;
  int close_price = 0;
  int low_price = 0;
  int center = 0;
  int height = 16;
  Block *candle;

public:
  CandleStick();
  ~CandleStick();
  void set_candle(CandleSign _c_sign, CandleKind _c_kind, int _center,
                  int _height);
  bool check_available(CandlePatternSign cp_sign, CandlePatternShape cp_shape);
  void print_part(int part);
  void set_blocks();
};

class CandlePattern {
private:
  CandlePatternSign c_pattern_sign = Bullish;
  CandlePatternShape c_pattern_shape = Engulfing;
  int width = 0;
  int height = 16;
  int center = 0;
  int turn = 0;
  CandleStick *pattern;

public:
  CandlePattern();
  ~CandlePattern();
  void print_part(int part);
  int set_pattern(int _width, int _height, int _center,
                  CandlePatternSign _c_pattern_sign,
                  CandlePatternShape _c_pattern_shape);
  void make_pattern();
  void make_column(CandleSign c_sign, CandleKind c_kind);
  CandleStick *give_pattern();
};

class Chart {
private:
  int width;
  int height;
  int pattern_num;
  int center;
  CandlePattern *chart;

public:
  Chart(int _width, int _height);
  ~Chart();
  void print_chart();
  void add_pattern(CandlePatternSign cp_sign, CandlePatternShape cp_shape);
  void chart_game();
};