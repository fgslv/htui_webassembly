#include "fib.h"
#include <vector>


Fib::Fib() {
  curr = 1;
  prev = 1;
}

int Fib::next() {
  int next = curr + prev;

  prev = curr;
  curr = next;

  return next;
}

int fib(int x) {
  if (x < 1) return 0;
  if (x == 1) return 1;

  return fib(x-1) + fib(x-2);
}

int fibNext() {
  static Fib fib = Fib();
  return fib.next();
}

auto instances = std::vector<Fib>();

int next_val(int fib_instance) {
  return instances[fib_instance].next();
}

int new_fib() {
  instances.push_back(Fib());
  return instances.size() - 1;
}
