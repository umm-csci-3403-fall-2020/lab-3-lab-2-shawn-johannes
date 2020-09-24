#include <stdlib.h>
#include <stdio.h>
#include "array_merge.h"

 int* is_unique(int num_arrays, int* sizes, int** values, int* binaryArray) {
  int unique_values = 0;
  for (int outerArrayIndex = 0; outerArrayIndex < num_arrays; outerArrayIndex++) {
    for (int innerArrayIndex = 0; innerArrayIndex < sizes[outerArrayIndex]; innerArrayIndex++) {
       int currentValue = values[outerArrayIndex][innerArrayIndex];
       if (binaryArray[currentValue] == 0) {
          binaryArray[currentValue] = 1;
          unique_values++;
       }
    }
  }
  binaryArray[10] = unique_values;
  return binaryArray;
}


