#include <stdlib.h>
#include <stdbool.h>

#include "mergesort.h"

bool needs_sorting(int rangeSize) {
  return rangeSize >= 2;
}

void merge_ranges(int *values, int startIndex, int midPoint, int endIndex) {
  int rangeSize = endIndex - startIndex;
  int *destination;
  destination = (int*) calloc(rangeSize, sizeof(int));
  int firstIndex = startIndex;
  int secondIndex = midPoint;
  int copyIndex = 0;
  while (firstIndex < midPoint && secondIndex < endIndex) {
    if (values[firstIndex] < values[secondIndex]) {
      destination[copyIndex] = values[firstIndex];
      firstIndex++;
    } else {
      destination[copyIndex] = values[secondIndex];
      secondIndex++;
    }
    copyIndex++;
  }
  while (firstIndex < midPoint) {
    destination[copyIndex] = values[firstIndex];
    copyIndex++;
    firstIndex++;
  }
  while (secondIndex < endIndex) {
   destination[copyIndex] = values[secondIndex];
   copyIndex++;
   secondIndex++;
  }
  for (int i = 0; i < rangeSize; i++) {
    values[i + startIndex] = destination[i];
  }
  free(destination);
}

void mergesort_range(int *values, int startIndex, int endIndex) {
  int rangeSize = endIndex - startIndex;
  if (needs_sorting(rangeSize)) {
    int midPoint = (startIndex + endIndex)/2;
    mergesort_range(values, startIndex, midPoint);
    mergesort_range(values, midPoint, endIndex);
    merge_ranges(values, startIndex, midPoint, endIndex);
  }
}

void mergesort(int size, int *values) {
  mergesort_range(values, 0, size);
}







