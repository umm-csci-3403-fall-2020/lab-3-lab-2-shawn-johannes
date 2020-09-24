#include "mergesort.h"

bool needs_sorting(int rangeSize) {
  return rangeSize >= 2;
}

void merge_ranges(int *values, int midPoint, int startIndex, int endIndex) {
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
    secondIndex++;
  }
  while (secondIndex < endIndex) {
   destination[copyIndex] = values[secondIndex];
   copyIndex++;
   secondIndex++;
  }
  for (int i = 0; i < rangeSize; i++) {
    values[i + startIndex] = destination[i];
  }
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

void mergesort(int *values) {
  // This obviously doesn't actually do any *sorting*, so there's
  // certainly work still to be done.
  return;
}







