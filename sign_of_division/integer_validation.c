#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "integer_validation.h"

int check_arrays(int *num_array, int *conv_A, int meaningful_size) {
   int result = 0;

   meaningful_size = meaningful_size - 1;

   // order of elements is reverse in the num_array
   // that's why used the meaningful_size variable
   for (int i = 0; i < meaningful_size; i++) {
      if (conv_A[i] != num_array[meaningful_size - i]) {
         result = 1;
         break;
      }
   }

   return result;
}

int integer_validation(int a, int *num_array, int *conv_A, int meaningful_size) {
   int result = 1;

   if (a == -1) {
      printf("Program terminated...\n");
   } else if (check_arrays(num_array, conv_A, meaningful_size) == 1) {
      printf("Error (overflow or negative detected): number can\'t be more than %d and less than %d\n", 0, INT_MAX);
   } else {
      result = 0;
   }

   return result;
}

