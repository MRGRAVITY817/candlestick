#include "main.h"

// Colored Print
void cprintf(std::string str, Color color) {
  printf("\033[1;%dm", color);
  printf("%s", str.c_str());
}
// Allocate memory for 2d array
int **alloc_2d(int **array, int width, int height) {
  array = new int *[width];
  for (int i = 0; i < width; i++) {
    array[i] = new int[height];
  }
  return array;
}
// Free memory for 2d array
void free_2d(int **array, int width) {
  for (int i = 0; i < width; i++) {
    delete[] array[i];
  }
  delete[] array;
}