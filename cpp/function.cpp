#include <math.h>

extern "C" {
  int int_sqrt(int x) {
    return sqrt(x);
  }

  extern float addNums(float *buffer, int bufSize) {
    float total = 0;

    for (int i=0; i<bufSize; i++) {
      total += buffer[i];
    }

    return total;
  }
}
