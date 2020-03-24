     1  #include <stdio.h>
     2  #include <math.h>
     3  
     4  #define BELOW 2000000
     5  
     6  int isaprime (int num);
     7  
     8  int main (void) {
     9  
    10      int i;
    11      long sum = 0;
    12  
    13      for (i = 2; i < BELOW; i++) {
    14  
    15              if (isaprime(i) == 1) {
    16                      sum = sum + i;
    17              }
    18      }
    19      printf("sum: %ld\n", sum);
    20  
    21      return 0;
    22  }
    23  
    24  int isaprime (int num) {
    25  
    26      int i;
    27  
    28      for (i = 2; i <= sqrt(num); i++) {
    29              if (num % i == 0) {
    30                      return 0;
    31              }
    32              else {
    33                      ;
    34              }
    35      }
    36  
    37      return 1;
    38  }