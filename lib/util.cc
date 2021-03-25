#include "main.h"

// Colored Print
void cprintf(Item item, Color color) {
  printf("\033[1;%dm", color);
  printf("%c ", item);
}
// Clear the print
void clear_out() { printf("\x1b[2J"); }

// Allocate memory for 2d array
Block **alloc_2d(Block **array, int width, int height) {
  array = new Block *[width];
  for (int i = 0; i < width; i++) {
    array[i] = new Block[height];
  }
  return array;
}
// Free memory for 2d array
void free_2d(Block **array, int width) {
  for (int i = 0; i < width; i++) {
    delete[] array[i];
  }
  delete[] array;
}