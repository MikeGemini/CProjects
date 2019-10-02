#include "filling_int_array.h"

void filling_int_array(int *num_array, int a, unsigned int array_size, int cutoff) {
   int d = 10;
   int division_result = 0;
   int counter = 1;
   int meaningful_size = 0;

   num_array[0] = a % d;

   division_result = a;
   while (counter < array_size) {
      division_result = division_result / d;

      if (division_result == 0){
         num_array[counter] = cutoff; // cutoff number
      } else {
         num_array[counter] = division_result % d;
      }

      counter++;
   }

   return meaningful_size;
}
