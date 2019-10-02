/*
*  This program asks for an integer and return results
*  of signs of division by 2, 3, 4, 5, 6, 7, 8, 9, 11
*  30.09.2019 Mike Gemini
*/

#include <stdio.h>
#include <windows.h>
#include <limits.h>

#include "integer_validation.h"
#include "filling_int_array.h"
#include "convert_char_to_int.h"

void print_array(int *num_array, unsigned int array_size, int cutoff) {
   int i = 0;

   printf("**** we\'ve got array of numbers ****\n");

   for (; i < array_size; i++) {
      if (num_array[i] == cutoff)
         break;

      printf("%d ", num_array[i]);
   }

   printf("\n************************************\n");
}

int get_meaningful_size(int *num_array, unsigned int array_size, int cutoff) {
   int meaningful_size = 0;

   for (int i = 0; i < array_size; i++) {
      if (num_array[i] == cutoff && i != array_size - 1) {
         meaningful_size = i;
         break;
      } else if (i == array_size - 1) {
         meaningful_size = array_size;
         break;
      }
   }

   return meaningful_size;
}

void check_division_by_2(int *num_array, int a) {
   double result = 0;

   result = (double) a / 2;

   if (num_array[0] % 2 == 0) {
      printf("%d can ", a);
   } else {
      printf("%d can\'t ", a);
   }
   printf("be divide by 2\n");
   printf("%d / 2 = %.2f\n", num_array[0], (double) num_array[0] / 2);
   printf("%d / 2 = %.2f\n", a, result);

   printf("------------------------------------\n");
}

void check_division_by_3(int *num_array, int a, int meaningful_size) {
   int sum = 0;
   double result = 0;

   result = (double) a / 3;

   for (int i = 0; i < meaningful_size; i++)
      sum = sum + num_array[i];

   if (sum % 3 == 0) {
      printf("%d can ", a);
   } else {
      printf("%d can\'t ", a);
   }
   printf("be divide by 3. Sum of numbers is %d\n", sum);
   printf("%d / 3 = %.2f\n", sum, (double) sum / 3);
   printf("%d / 3 = %.2f\n", a, result);

   printf("------------------------------------\n");
}

void check_division_by_4(int *num_array, int a) {
   double result = 0;
   int sum = 0;

   result = (double) a / 4;

   if (a <= 9) {
      sum = num_array[0];
   } else {
      sum = num_array[0] + num_array[1];
   }

   if (sum % 4 == 0) {
      printf("%d can ", a);
   } else {
      printf("%d can\'t ", a);
   }
   printf("be divide by 4. ");
   if (a >= 9) {
      printf("Sum of %d and %d is %d\n", num_array[0], num_array[1], sum);
   }
   printf("%d / 4 = %.2f\n", sum, (double) sum / 4);
   printf("%d / 4 = %.2f\n", a, result);

   printf("------------------------------------\n");
}

void check_division_by_5(int *num_array, int a) {
   double result = 0;

   result = (double) a / 5;

   if (num_array[0] == 5 || num_array[0] == 0) {
      printf("%d can ", a);
   } else {
      printf("%d can\'t ", a);
   }
   printf("be divide by 5\n");
   printf("%d / 5 = %.2f\n", num_array[1] * 10 + num_array[0], (double) (num_array[1] * 10 + num_array[0]) / 5);
   printf("%d / 5 = %.2f\n", a, result);

   printf("------------------------------------\n");
}

int main(int argc, char *argv[]) {

   int a = 0;
   unsigned int array_size = 10;
   int num_array[array_size];
   char A[array_size];
   int conv_A[array_size];
   int cutoff = -99;
   int meaningful_size = 0;

   printf("Input an integer (less than %d and more than %d; -1 - exit):\n", INT_MAX, 0);
   scanf("%10s", A);
   a = atoi(A);

   convert_char_to_int(A, array_size, conv_A);

   filling_int_array(num_array, a, array_size, cutoff); // filling the array with numbers of integer 'a'

   meaningful_size = get_meaningful_size(num_array, array_size, cutoff); // get the meaningful size of num_array

   if (integer_validation(a, num_array, conv_A, meaningful_size) == 0) { // checking to -1 (exit) and trying check int overflow

      print_array(num_array, array_size, cutoff);

      check_division_by_2(num_array, a);
      check_division_by_3(num_array, a, meaningful_size);
      check_division_by_4(num_array, a);
      check_division_by_5(num_array, a);

   }

   printf("\nBeep\a\n");
   return 0;

}
