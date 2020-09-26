#include <stdlib.h>
#include <stdio.h>
#include "array_merge.h"

 int* is_unique(int num_arrays, int* sizes, int** values, int* binaryArray, int greatestValue) {
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
  binaryArray[greatestValue] = unique_values;
  return binaryArray;
}

int findGreatestValue(int num_arrays, int* sizes, int** values) {
  int greatestValue = 0;
   for (int outerArrayIndex = 0; outerArrayIndex < num_arrays; outerArrayIndex++) {
    for (int innerArrayIndex = 0; innerArrayIndex < sizes[outerArrayIndex]; innerArrayIndex++) {
       int currentValue = values[outerArrayIndex][innerArrayIndex];
       if (currentValue > greatestValue) {
         greatestValue = currentValue;
       }
    }
  }
  return greatestValue + 1;
}

int* array_merge(int num_arrays, int* sizes, int** values) {
  // Find greatest value in range 
  int greatestValue = findGreatestValue(num_arrays, sizes, values);

  // Create a temporary array for recording unique values (see is_unique)
  int* binaryArray;
  binaryArray = (int*) calloc(greatestValue + 1, sizeof(int));
  binaryArray = is_unique(num_arrays, sizes, values, binaryArray, greatestValue);
  int unique_values = binaryArray[greatestValue];
  int* mergedArray;
  mergedArray = (int*) calloc(unique_values + 1, sizeof(int));
  int mergeArrayIndex = 1;
  for (int i = 0; i < greatestValue; i++) {
    if(binaryArray[i] == 1) {
      mergedArray[mergeArrayIndex] = i;
      mergeArrayIndex++;
    }
  }
  free(binaryArray);
  // The first index lists the number of unique values
  mergedArray[0] = unique_values;  
  return mergedArray;
}



