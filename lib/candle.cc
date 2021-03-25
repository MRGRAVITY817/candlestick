#include "main.h"

// Make candlestick
CandleStick::CandleStick(CandleSign _c_sign, CandleKind _c_kind, int _center)
    : c_sign(_c_sign), c_kind(_c_kind), center(_center) {
  if (this->c_kind == Long) {
    this->open_price = this->center - 1;
    this->close_price = this->center + 1;
    this->high_price = this->close_price + 1;
    this->low_price = this->open_price - 1;
  } else if (this->c_kind == Short) {
    this->open_price, this->close_price = this->center;
    this->high_price = this->close_price + 1;
    this->low_price = this->open_price - 1;
  }
}

Block *CandleStick::give_candle(int center, int height) {
  Color block_color = this->c_sign == Positive ? Red : Blue;
  Block *block_array = new Block[height];
  for (int i = 0; i < height; i++) {
    block_array[i].color = block_color;
    if (i == this->open_price || i == this->close_price || i == this->center) {
      block_array[i].item = Square;
    } else if (i == this->high_price || i == this->low_price) {
      block_array[i].item = Line;
    } else {
      block_array[i].item = Space;
    }
  }
  return block_array;
}