// algorythms.h - заголовок з функціями для пошуку найкоротших шляхів
// у орієнтованому графі

#ifndef ALGORYTHMS_H
#define ALGORYTHMS_H

// ================= ПРОТОТИПИ ФУНКЦІЙ АЛГОРИТМІВ ======================

/**
 * @brief shortestPathsByFloyd
 * Пошук найкоротших шляхів у графі за алгоритмом Флойда-Уоршелла.
 * Алгоритм модифікований для пошуку найкоротших шляхів
 * навіть при присутності у графі циклів з від'ємною вагою.
 * Повертає матрицю найкоротших відстаней та записує матрицю відновлення
 * шляху у змінну renewMatrix.
 *
 * @param D0 - матриця відстаней (що зберігає усі ваги ребер у графі)
 * @param n  - розмір матриці відстаней (кількість вершин у графі)
 * @param renewMatrix - змінна у яку запишеться матриця відновлення шляху
 * @return матрицу кратчайших путей
 *         (без учета циклов с отрицательными весами)
 */
int **shortestPathsByFloyd(int **D0, int n, int **&renewMatrix);

/**
 * @brief shortestPathsByDantzig
 * Пошук найкоротших шляхів у графі за алгоритмом Данцига.
 * Алгоритм модифікований для пошуку найкоротших шляхів навіть при
 * присутності у графі циклів з від'ємною вагою.
 * Повертає матрицю найкоротших відстаней та записує матрицю відновлення
 * шляху у змінну renewMatrix.
 *
 * @param D0 - матриця відстаней (що зберігає усі ваги ребер у графі)
 * @param n  - розмір матриці відстаней (кількість вершин у графі)
 * @param renewMatrix - змінна у яку запишеться матриця відновлення шляху
 * @return матрицу кратчайших путей
 *         (без учета циклов с отрицательными весами)
 */
int **shortestPathsByDantzig(int **D0, int n, int **&renewMatrix);

/**
 * @brief shortestPathsByFloydWithoutNegativeLoopCheck
 *
 *  Функція знаходить найкоротші шляхи у графі, що заданий матрицею
 * відстаней та кількістю ребер у ній за алгоритмом Флойда-Уоршелла.
 * Повертає матрицю найкоротших відстаней та записує матрицю відновлення
 * шляху у змінну renewMatrix.
 *
 * @param D0 - матриця відстаней (що зберігає усі ваги ребер у графі)
 * @param n  - розмір матриці відстаней (кількість вершин у графі)
 * @param renewMatrix - змінна у яку запишеться матриця відновлення шляху
 * @return матрицю найкоротших відстаней
 */
int **shortestPathsByFloydWithoutNegativeLoopCheck(int **D0, int n,
                                                   int **&renewMatrix);

/**
 * @brief shortestPathsByFloydWithoutNegativeLoopCheck
 *
 *  Функція знаходить найкоротші шляхи у графі, що заданий матрицею
 * відстаней та кількістю ребер у ній за алгоритмом Данцига.
 * Повертає матрицю найкоротших відстаней та записує матрицю відновлення
 * шляху у змінну renewMatrix.
 *
 * @param D0 - матриця відстаней (що зберігає усі ваги ребер у графі)
 * @param n  - розмір матриці відстаней (кількість вершин у графі)
 * @param renewMatrix - змінна у яку запишеться матриця відновлення шляху
 * @return матрицю найкоротших відстаней
 */
int **shortestPathsByDantzigWithoutNegativeLoopCheck(int **D0, int n,
                                                     int **&renewMatrix);

/**
 * @brief negativeLoopCheck
 *
 * Оглядає матрицю найкоротших відстаней отриману,
 * наприклад, алгоритмами Флойда-Уоршелла або Данцига
 * та проводить обробку циклів з негативними вагами.
 * У разі їх відстуності вхідна матриця не змінюється.
 * Повертає оброблену матрицю відстаней, в якій знайдені
 * та правильним чином оброблені цикли з негативними вагами.
 *
 * @param D матриця найкоротших відстаней
 * @param n кількість вершин у графі
 * @return обработаную матрицу кратчайших
 * расстояний, которая учитывает негативные циклы.
 */
int **negativeLoopCheck(int **D, int n);

/**
 * @brief sum
 *
 * Виконує додавання двох чисел, враховуючи можливість переповнення
 * розрядної сітки. У випадку, якщо сума чисел перевищує максимальне
 * можливе число для 32-бітної розрядної сітки, то функція повертає
 * останнє. У разі додавання, результатом якого є число, що менше за
 * мінімальне для 32-бітної розрядної сітки, функція повертає останнє.
 *
 *
 * @param operand1 перший доданок
 * @param operand2 другий доданок
 * @return суму двох чисел.
 */
int sum(int operand1, int operand2);

/**
 * @brief copyOf
 * Повертає копію квадратної матриці matrix
 * порядку (size)x(size).
 *
 * @param matrix матриця, яку копіює функція
 * @param size розмір цієї матриці
 * @return копії матриці matrix
 */
int **copyOf(int **matrix, int size);

/**
 * @brief relaxPath
 *
 * Намагається релаксувати шлях у матриці з from до to, спробою
 * прокласти шлях через вершину through. Тобто, якщо сума шляхів
 * з from до through та з through до to менша за поточний
 * шлях з from до to, то замінюємо останній на цю суму.
 * В результаті замінює елемент матриці, що відповідає
 * відстані, яку релаксує функція.
 *
 * @param from - вершина, звідки прокладається відстань у графі
 * @param through - вершина, через яку, можливо, проходитиме новий шлях
 * @param to - вершина, до якої прокладається шлях
 * @param D - матриця відстаней графу, що розглядається
 * @param P - матриця відновлення шляхів у графі
 */
void relaxPath(int from, int through, int to, int **D, int **&P);

/**
 * @brief prepareRenewMatrix
 *
 * Підготовлення матриці відновлення для заповнення
 * у ході алгоритму пошуку найкоротших шляхів.
 *
 * @param renewMatrix матриця відновлення, що буде заповнюватись
 * @param size порядок матриці відновлення.
 * @return матрицю відновлення, що готова для запису у ході алгоритмів
 * пошуку найкоротшого шляху.
 */
int **prepareRenewMatrix(int **&renewMatrix, int size);

#endif // ALGORYTHMS_H
