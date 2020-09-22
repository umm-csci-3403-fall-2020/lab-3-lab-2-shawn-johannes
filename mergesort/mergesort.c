#include "mergesort.h"


void mergesort_Range(int *values, int startIndex, int endIndex) {
  int rangeSize = endIndex - startIndex;
  if (needsSorting(rangeSize)) {
    int midPoint = (startIndex + endIndex)/2;
    mergesort_Range(values, startIndex, midPoint);
    mergesort_Range(values, midPoint, endIndex);
    merge_Ranges(values, startIndex, midPoint, endIndex);
  }
}

void mergesort(int *values) {
  // This obviously doesn't actually do any *sorting*, so there's
  // certainly work still to be done.
  return;
}







