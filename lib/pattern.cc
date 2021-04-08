#include "main.h"

// Constructor: Allocate matrix memory
CandlePattern::CandlePattern() {
  this->pattern = new CandleStick[this->height];
}

// Destructor: Free pattern memory
CandlePattern::~CandlePattern() { delete this->pattern; }

int CandlePattern::set_pattern(int _width, int _height, int _center,
                               CandlePatternSign _c_pattern_sign,
                               CandlePatternShape _c_pattern_shape) {
  this->c_pattern_sign = _c_pattern_sign;
  this->c_pattern_shape = _c_pattern_shape;
  this->width = _width;
  this->height = _height;
  this->center = _center;
  this->make_pattern();

  if (this->c_pattern_sign == Bearish) {
    if (this->c_pattern_shape == Engulfing) {
      // +Long +Long +Short -Long
      return 3;
    } else if (this->c_pattern_shape == Harami) {
      // +Long +Long +Long -Short
      return 4;
    } else {
      printf("Wrong Candle Pattern");
      assert(false);
    }
  } else if (this->c_pattern_sign == Bullish) {
    if (this->c_pattern_shape == Engulfing) {
      // -Long -Long -Short +Long
      return -3;
    } else if (this->c_pattern_shape == Harami) {
      // -Long -Long -Long +Short
      return -4;
    } else {
      printf("Wrong Candle Pattern");
      assert(false);
    }
  }
}

// Return pattern
CandleStick *CandlePattern::give_pattern() {
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
  this->pattern[this->turn].set_candle(c_sign, c_kind, this->center,
                                       this->height);
  this->turn++;
  return;
}

void CandlePattern::print_part(int part) {
  for (int i = 0; i < 4; i++) {
    this->pattern[i].print_part(part);
  }
}
