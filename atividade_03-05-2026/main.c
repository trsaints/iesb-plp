#include <stdio.h>
#include "rational.h"

int main()
{
    Rational *r1 = create(2, 4);      // armazena internamente como 1/2
    Rational *r2 = create(1, 3);      // armazena internamente como 1/3
    Rational *r3 = add(*r1, *r2);     // resulta em 5/6
    char *r3_string = toString(*r3);  // "5/6"
    double r3_double = toDouble(*r3); // 0.833333...

    printf("r3: %s (~%.5lf)\n", r3_string, r3_double);

    Rational *r4 = create(6, -8);    // resulta em -3/4
    char *r4_string = toString(*r4); // "-3/4"
    double r4_double = toDouble(*r4);

    printf("r4: %s (~%.5lf)\n", r4_string, r4_double);

    return 0;
}