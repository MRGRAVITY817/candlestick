#include "main.h"

// Constructor: Allocate matrix memory
Chart::Chart(int _width, int _height)
    : width(_width), height(_height), stretch(0) {}
// Destructor: Free matrix memory
Chart::~Chart() {}
// Print matrix
void Chart::print_matrix() {
  for (int i = 0; i < this->height; i++) {
    for (int j = 0; j < this->width; j++) {
      printf("□ ");
    }
    printf("\n");
  }
}
