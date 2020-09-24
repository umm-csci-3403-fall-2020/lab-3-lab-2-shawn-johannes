#include <stdlib.h>
#include <stdio.h>
#include "array_merge.h"

 int* is_unique(int num_arrays, int* sizes, int** values, int* binaryArray) {
  for (int outerArrayIndex = 0; outerArrayIndex < num_arrays; outerArrayIndex++) {
    for (int innerArrayIndex = 0; innerArrayIndex < sizes[outerArrayIndex]; innerArrayIndex++) {
       int currentValue = values[outerArrayIndex][innerArrayIndex];
       if (binaryArray[currentValue] == 0) {
          binaryArray[currentValue] = 1;
       }
    }
  }
  return binaryArray;
}


