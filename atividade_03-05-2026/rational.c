#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
    int numerator;
    int denominator;
} Rational;

/**
 * Devolve o Least Common Multiplier - Mínimo Múltiplo Comun (MMC) entre a e b.
 */
int lcm(int a, int b);

/**
 * Devolve o Greatest Common Divisor - Máximo Divisor Comun (MDC) entre a e b.
 */
int gcd(int a, int b);

Rational *create(int numerator, int denominator)
{
    Rational *r = (Rational *)calloc(1, sizeof(Rational));

    if (r == NULL)
    {
        fprintf(stderr, "[ERRO]: Não foi possível instanciar uma struct Rational.\n");
        exit(1);
    }

    if (denominator == 0)
    {
        fprintf(stderr, "[ERRO]: Não foi possível instanciar uma struct Rational - Denominador deve ser maior que zero.\n");
        exit(1);
    }

    int n = numerator, d = denominator;

    if (n < 0)
    {
        n = n * (-1);
        d = d * (-1);
    }

    int rational_gcd = gcd(n, d);

    r->numerator = n / rational_gcd;
    r->denominator = d / rational_gcd;

    return r;
}

Rational *add(Rational a, Rational b)
{
    bool same_denominator = a.denominator == b.denominator;
    int denominator_lcm = same_denominator ? -1 : lcm(a.denominator, b.denominator);
    int n = same_denominator
                ? a.numerator + b.numerator
                : (denominator_lcm / a.denominator * a.numerator) + (denominator_lcm / b.denominator * b.denominator);
    int d = same_denominator ? a.denominator : lcm(a.denominator, b.denominator);

    return create(n, d);
}

Rational *subtract(Rational a, Rational b)
{
    bool same_denominator = a.denominator == b.denominator;
    int denominator_lcm = same_denominator ? -1 : lcm(a.denominator, b.denominator);
    int n = same_denominator
                ? a.numerator - b.numerator
                : (denominator_lcm / a.denominator * a.numerator) - (denominator_lcm / b.denominator * b.denominator);
    int d = same_denominator ? a.denominator : lcm(a.denominator, b.denominator);

    return create(n, d);
}

Rational *multiply(Rational a, Rational b)
{
    int n = a.numerator * b.numerator;
    int d = a.denominator * b.denominator;

    return create(n, d);
}

Rational *divide(Rational a, Rational b)
{
    int n = a.numerator * b.denominator;
    int d = a.denominator * b.numerator;

    return create(n, d);
}

char *toString(Rational number)
{
    char buffer[24];

    bool converted_n = snprintf(buffer, sizeof(buffer), "%d", number.numerator);
    bool converted_d = snprintf(buffer, sizeof(buffer), "%d", number.denominator);

    if (converted_n != true || converted_d != true)
    {
        fprintf(stderr, "[ERRO]: Falha ao serializar struct Rational\n");
        exit(1);
    }

    return buffer;
}

double toDouble(Rational number)
{
    return number.numerator / number.denominator;
}

int lcm(int a, int b)
{
    if (a == 0 || b == 0)
    {
        return 0;
    }

    return abs(a * b) / gcd(a, b);
}

int gcd(int a, int b)
{
    int abs_a = abs(a), abs_b = abs(b);

    while (abs_b != 0)
    {
        int tmp = abs_b;
        abs_b = abs_a % abs_b;
        abs_a = tmp;
    }

    return abs_a;
}
