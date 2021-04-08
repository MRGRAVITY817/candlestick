#include "main.h"

// Make candlestick
CandleStick::CandleStick() { this->candle = new Block[32]; }
CandleStick::~CandleStick() { delete this->candle; }

void CandleStick::set_candle(CandleSign _c_sign, CandleKind _c_kind,
                             int _center, int _height) {
  this->c_sign = _c_sign;
  this->c_kind = _c_kind;
  this->center = _center;
  this->height = _height;
  if (this->c_kind == Long) {
    this->open_price = this->center - 1;
    this->close_price = this->center + 1;
    this->high_price = this->close_price + 1;
    this->low_price = this->open_price - 1;
  } else if (this->c_kind == Short) {
    this->open_price = this->center;
    this->close_price = this->center;
    this->high_price = this->close_price + 1;
    this->low_price = this->open_price - 1;
  }
  this->set_blocks();
}

void CandleStick::print_part(int part) {
  cprintf(this->candle[part].item, this->candle[part].color);
}

void CandleStick::set_blocks() {
  for (int i = 0; i < this->height; i++) {
    this->candle[i].color = this->c_sign == Positive ? Red : Blue;
    if (i == this->open_price || i == this->close_price || i == this->center) {
      this->candle[i].item = Square;
    } else if (i == this->high_price || i == this->low_price) {
      this->candle[i].item = Line;
    } else {
      this->candle[i].item = Space;
    }
  }
}