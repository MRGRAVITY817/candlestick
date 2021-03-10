#include "../lib/main.h"

int main() {
  bool interrupt = true;
  Chart *pm = new Chart(32, 16);

  // while (interrupt) {
  //   system("clear");
  //   pm->print_matrix();
  //   usleep(3 * 1000);
  // }
  cprintf("Hello world ", Red);
  delete pm;
  return 0;
}