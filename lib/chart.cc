#include "main.h"

Chart::Chart(int _width, int _height) : width(_width), height(_height) {
  this->chart = alloc_2d(this->chart, this->width, this->height);
}

Chart::~Chart() { free_2d(this->chart, this->width); }

void Chart::print_chart() {
  for (int i = 0; i < this->width; i++)
    for (int j = 0; j < this->height; j++) {
      cprintf(this->chart[i][j].item, this->chart[i][j].color);
    }
  printf("\n");
}

void Chart::add_pattern(CandlePatternSign cp_sign,
                        CandlePatternShape cp_shape) {
  if (this->pattern_num > 7) {
    this->pattern_num = 0;
  }
  // adding pattern logic
  CandlePattern *c_pattern =
      new CandlePattern(4, this->height, cp_sign, cp_shape);
  for (int i = this->pattern_num * 4; i < this->pattern_num * 4 + 4; i++)
    for (int j = 0; j < this->height; j++) {
      this->chart[i][j].item = c_pattern->give_pattern()[i][j].item;
      this->chart[i][j].color = c_pattern->give_pattern()[i][j].color;
    }

  this->pattern_num++;
}

void Chart::chart_game() {
  bool running = true;
  int choice;
  while (running) {
    system("clear");
    printf("           < The CandleStick Chart >              \n");
    this->print_chart();
    printf("\n");
    printf("Select Pattern: \n");
    printf("1. Bearish Engulfing Pattern \n");
    printf("2. Bullish Engulfing Pattern \n");
    printf("3. Bearish Harami Pattern \n");
    printf("4. Bullish Harami Pattern \n");
    printf("\n");
    scanf("Choose: (type 9 to escape) ", &choice);
    switch (choice) {
    case 1:
      this->add_pattern(Bearish, Engulfing);
      break;
    case 2:
      this->add_pattern(Bullish, Engulfing);
      break;
    case 3:
      this->add_pattern(Bearish, Harami);
      break;
    case 4:
      this->add_pattern(Bearish, Harami);
      break;
    case 9:
      running = false;
      break;
    }
  }
}
