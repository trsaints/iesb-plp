/**
 * Representa um número racional, no formato de razão (numerador/denominador).
 */
typedef struct
{
    /**
     * Representa o numerador da razão.
     */
    int numerator;

    /**
     * Representa o denominador da razão.
     */
    int denominator;
} Rational;

/**
 * @brief Instancia uma struct do tipo Rational.
 *
 * @param numerator O numerador da razão.
 * @param denominator O denominador da razão.
 *
 * @returns uma referência para uma instância de Rational.
 */
Rational *create(int numerator, int denominator);

/**
 * @brief Realiza a soma entre duas structs do tipo Rational
 *
 * @returns uma nova referência de Rational, representando a soma entre a e b.
 */
Rational *add(Rational a, Rational b);

/**
 * @brief Realiza a subração entre duas structs do tipo Rational.
 *
 * @returns uma nova referência de Rational, representando a subtração entre a e b.
 */
Rational *subtract(Rational a, Rational b);

/**
 * @brief Realiza a multiplicação entre duas structs do tipo Rational.
 *
 * @returns uma nova referência de Rational, representando o produto entre a e b.
 */
Rational *multiply(Rational a, Rational b);

/**
 * @brief Realiza a divisão entre duas structs do tipo Rational.
 *
 * @returns uma nova referência de Rational, representando a divisão entre a e b.
 */
Rational *divide(Rational a, Rational b);

/**
 * @brief Converte uma struct Rational para o formato textual.
 *
 * @param number O número no formato Rational a ser convertido.
 *
 * @returns uma string representando um número racional em seu formato fracionário.
 */
char *toString(Rational number);

/**
 * @brief Converte uma struct Rational para o formato numérico.
 *
 * @param number O número no formato Rational a ser convertido.
 *
 * @returns um double, representando um número racional em seu formato decimal.
 */
double toDouble(Rational number);
