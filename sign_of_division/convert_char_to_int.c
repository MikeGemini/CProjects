#include "convert_char_to_int.h"

void convert_char_to_int(char *A, unsigned int array_size, int *conv_A) {
   int i = 0;

   while (i < array_size) {
      switch (A[i]) {
         case '0':
            conv_A[i] = 0;
            break;
         case '1':
            conv_A[i] = 1;
            break;
         case '2':
            conv_A[i] = 2;
            break;
         case '3':
            conv_A[i] = 3;
            break;
         case '4':
            conv_A[i] = 4;
            break;
         case '5':
            conv_A[i] = 5;
            break;
         case '6':
            conv_A[i] = 6;
            break;
         case '7':
            conv_A[i] = 7;
            break;
         case '8':
            conv_A[i] = 8;
            break;
         case '9':
            conv_A[i] = 9;
            break;
         default:
            conv_A[i] = -99;
            break;
      }

      i++;
   }
}
