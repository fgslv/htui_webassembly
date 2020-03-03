#include <stdio.h>
#include <stdint.h>
#include <math.h>

extern "C" {
  int int_sqrt(int x)
  {
    return sqrt(x);
  }

  extern float addNums(float *buffer, int bufSize)
  {
    float total = 0;

    for (int i=0; i<bufSize; i++) {
      total += buffer[i];
    }

    return total;
  }


  extern void sortNums(uint8_t *buffer, int bufSize)
  {
    printf("sortNums: received %d nums to sort\n", bufSize);
    for (int i=0; i<bufSize; i++) 
      printf("%d, ", buffer[i]);
    printf("\n");

    uint8_t temp = 0;
    for (int i=0; i<bufSize; i++) {
      for (int j=i+1; j<bufSize; j++) {
	if (buffer[i] > buffer[j]) {
	  temp = buffer[i];
	  buffer[i] = buffer[j];
	  buffer[j] = temp;
	}
      }
    }

    for (int i=0; i<bufSize; i++) 
      printf("%d, ", buffer[i]);
    printf("\n");
  }
}
