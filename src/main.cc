#include "../lib/main.h"

int main() {
  Chart *chart = new Chart(32, 16);
  chart->chart_game();
  delete chart;
  return 0;
}