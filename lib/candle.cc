#include "main.h"

// Make candlestick
CandleStick::CandleStick(CandleSign _c_sign, CandleKind _c_kind)
    : c_sign(_c_sign), c_kind(_c_kind) {
  // Common bar for every kind
  this->open_price = 1;
  this->close_price = -1;
  // For candle kind cases
  if (this->c_kind == Long) {
    this->high_price = 2;
    this->low_price = -2;
  } else if (this->c_kind == Short) {
    // Same as common
  } else if (this->c_kind == Hammer) {
    this->low_price = -2;
  } else if (this->c_kind == ReverseHammer) {
    this->high_price = 2;
  }
}