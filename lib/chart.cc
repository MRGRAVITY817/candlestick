#include "main.h"

// Constructor: Allocate matrix memory
Chart::Chart(int _width, int _height)
    : width(_width), height(_height), stretch(0) {
  this->matrix = alloc_2d(this->matrix, this->width, this->height);
}
// Destructor: Free matrix memory
Chart::~Chart() { free_2d(this->matrix, this->width); }
// Print matrix
void Chart::print_matrix() {
  for (int i = 0; i < this->height; i++) {
    for (int j = 0; j < this->width; j++) {
      printf("□ ");
    }
    printf("\n");
  }
}

void Chart::print_column() {
  for (int i = 0; i < this->height; i++) {
  }
}
