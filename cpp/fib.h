#ifndef FIB_H
#define FIB_H

extern "C" {
  class Fib {
    public:
      Fib();
      int next();

    private:
      int curr;
      int prev;
  };

  extern int fib(int x);

  int fibNext();

  int next_val(int fib_instance);
  int new_fib();
}

#endif /* FIB_H */
