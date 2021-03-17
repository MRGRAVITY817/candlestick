#include "../lib/main.h"

int main() {
  bool interrupt = true;
  Chart *chart = new Chart(32, 16);

  // while (interrupt) {
  //   clear_out();
  //   chart->print_matrix();
  //   usleep(5 * 1000);
  // }
  cprintf("Hello world ", Red);
  cprintf("Hello world ", Blue);
  delete chart;
  return 0;
}