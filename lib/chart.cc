#include "main.h"

Chart::Chart(int _width, int _height) : width(_width), height(_height) {
  this->chart = new CandlePattern[this->width / 4];
  this->pattern_num = 0;
  this->center = this->height / 2;
}

Chart::~Chart() { delete this->chart; }

void Chart::print_chart() {
  for (int i = 0; i < this->height; i++) {
    for (int j = 0; j < this->width / 4; j++) {
      this->chart[j].print_part(i);
    }
    printf("\n");
  }
}

void Chart::add_pattern(CandlePatternSign cp_sign,
                        CandlePatternShape cp_shape) {
  if (this->pattern_num > this->width / 4 - 1) {
    this->chart = new CandlePattern[this->width / 4];
    this->pattern_num = 0;
  }
  // adding pattern logic
  int change = this->chart[this->pattern_num].set_pattern(
      4, this->height, this->center, cp_sign, cp_shape);

  this->center = this->center + change;
  this->pattern_num++;
}

void Chart::chart_game() {
  bool running = true;
  int choice;
  while (running) {
    system("clear");
    printf("\033[1;33m");
    printf("                    < The CandleStick Chart >              \n");
    printf("\n");
    this->print_chart();
    printf("\n");
    printf("\033[1;33m");
    printf("Select Pattern: \n");
    printf("1. Bearish Engulfing Pattern \n");
    printf("2. Bullish Engulfing Pattern \n");
    printf("3. Bearish Harami Pattern \n");
    printf("4. Bullish Harami Pattern \n");
    printf("9. Quit\n");
    printf("Choose option: ");
    scanf("%d", &choice);
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
      this->add_pattern(Bullish, Harami);
      break;
    case 9:
      running = false;
      break;
    }
  }
}
