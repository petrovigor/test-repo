#ifndef __TESTS_HPP__
#define __TESTS_HPP__

/* Проверка, что в зеленой свече цена внутри тела */
bool testBodyContainsGreenInside();

/* Проверка, что в красной свече цена внутри тела */
bool testBodyContainsRedInside();

/* Проверка, что в красной свече цена на границе тела */
bool testBodyContainsRedBorder();

/* Проверка значения цены внутри тела свечи */
bool testContainsInside();

/* Проверка на значение цены вне диапазона */
bool testContainsOutside();

/* Проверка значения цена на границе диапазона */
bool testContainsBorder();

/* Проверка правильного расчета размера свечи,
 * когда верхняя цена больше нижней
 */
bool testFullSizeHigh();

/* Проверка правильного расчета размера свечи,
 * когда верхняя цена меньше нижней
 */
bool testFullSizeLow();

/* Проверка случая, когда все цены равны */
bool testFullSizeEquals();

/* Создание свечи с ценой открытия 5 и ценой закрытия 20 */
bool testBodySizeHigh();

/* Проверка вычисления размера тела при условии,
 * что цена закрытия ниже цены открытия
 */
bool testBodySizeRedCandle();

/* Проверка свечи, при условии, что цена открытия равна цене закрытия */
bool testBodySizeBorder();

/* Проверка на создание зеленой свечи */
bool testIsGreen_1();

/* Проверка на создание красной свечи,
 * инвертирование проверки на зеленую свечу
 */
bool testIsGreen_2();

/* Проверка на создание свечи с равными ценами открытия и закрытия,
 * инвертирование проверки на зеленую свечу
 */
bool testIsGreen_3();

/* Проверка на создание красной свечи */
bool testIsRed_1();

/* Проверка на создание зеленой свечи,
 * инвертирование проверки на красную свечу
 */
bool testIsRed_2();

/* Проверка на создание свечи с равными ценами открытия и закрытия,
 * инвертирование проверки на красную свечу
 */
bool testIsRed_3();

#endif
