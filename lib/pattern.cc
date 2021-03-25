#include "main.h"

// Constructor: Allocate matrix memory
CandlePattern::CandlePattern(int _width, int _height,
                             CandlePatternSign _c_pattern_sign,
                             CandlePatternShape _c_pattern_shape)
    : width(_width), height(_height), c_pattern_sign(_c_pattern_sign),
      c_pattern_shape(_c_pattern_shape) {
  this->pattern = alloc_2d(this->pattern, this->width, this->height);
}

// Destructor: Free pattern memory
CandlePattern::~CandlePattern() { free_2d(this->pattern, this->width); }

// Return pattern
Block **CandlePattern::give_pattern() {
  make_pattern();
  return this->pattern;
}

// Make a pattern
void CandlePattern::make_pattern() {
  if (this->c_pattern_sign == Bearish) {
    if (this->c_pattern_shape == Engulfing) {
      // +Long +Long +Short -Long
      make_column(Positive, Long);
      this->center = this->center + 2;
      make_column(Positive, Long);
      this->center = this->center + 2;
      make_column(Positive, Short);
      make_column(Negative, Long);
    } else if (this->c_pattern_shape == Harami) {
      // +Long +Long +Long -Short
      make_column(Positive, Long);
      this->center = this->center + 2;
      make_column(Positive, Long);
      this->center = this->center + 2;
      make_column(Positive, Long);
      this->center = this->center + 1;
      make_column(Negative, Short);
    } else {
      printf("Wrong Candle Pattern");
      assert(false);
    }
  } else if (this->c_pattern_sign == Bullish) {
    if (this->c_pattern_shape == Engulfing) {
      // -Long -Long -Short +Long
      make_column(Negative, Long);
      this->center = this->center - 2;
      make_column(Negative, Long);
      this->center = this->center - 2;
      make_column(Negative, Short);
      make_column(Positive, Long);
    } else if (this->c_pattern_shape == Harami) {
      // -Long -Long -Long +Short
      make_column(Negative, Long);
      this->center = this->center - 2;
      make_column(Negative, Long);
      this->center = this->center - 2;
      make_column(Negative, Long);
      this->center = this->center - 1;
      make_column(Positive, Short);
    } else {
      printf("Wrong Candle Pattern");
      assert(false);
    }
  }
}

// Make a Column from candle stick
void CandlePattern::make_column(CandleSign c_sign, CandleKind c_kind) {
  // Check if this turn reached maximum
  if (this->turn > 3) {
    this->turn = 0;
    return;
  }
  CandleStick *c_stick = new CandleStick(c_sign, c_kind, this->center);
  for (int i = 0; i < this->height; i++) {
    this->pattern[this->turn][i].item =
        c_stick->give_candle(this->center, this->height)->item;
    this->pattern[this->turn][i].color =
        c_stick->give_candle(this->center, this->height)->color;
  }
  this->turn++;
  return;
}
