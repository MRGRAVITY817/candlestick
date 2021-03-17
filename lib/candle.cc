#include "main.h"

// Make candlestick
CandleStick::CandleStick(CandleSign _c_sign, CandleKind _c_kind)
    : c_sign(_c_sign), c_kind(_c_kind) {
  if (c_sign == Positive) {
    switch (this->c_kind) {
    case Long:
      this->open_price = -1;
      this->close_price = 1;
      this->high_price = this->close_price + 1;
      this->low_price = this->open_price - 1;
      break;
    case Short:
      this->open_price, this->close_price = 0;
      this->high_price = this->close_price + 1;
      this->low_price = this->open_price - 1;
      break;
    case Hammer:
      this->open_price = -1;
      this->close_price = 1;
      this->high_price = this->close_price;
      this->low_price = this->open_price - 1;
      break;
    case ReverseHammer:
      this->open_price = -1;
      this->close_price = 1;
      this->high_price = this->close_price + 1;
      this->low_price = this->open_price;
      break;
    }
  }
}