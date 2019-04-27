#include "number.h"

class Multiplicator {
  public:
    Multiplicator() {}
    static ll PowerOfTwo(unsigned long Value);
    static Number ran(Number& a);
    static Number mul(Number& a, Number& b);
    static Number DAC(Number& nn, Number& o);
    static void test (Number& limit);
    static void store ();
    static void experiment (Number& limit);
};
