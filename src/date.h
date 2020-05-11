/* MIT License 
 *
 * Copyright (c) Alexander Mazovets
*/

#ifndef DATE_H_
#define DATE_H_

#include <stdio.h>
#include "consupport.h"


/* Тип данных для времени.
*/
typedef struct {
    int day;
    int month;
    int year;
    int hour;
    int min;
} date;


/* Установка времени.
 * Возвращает дату в виде структуры с преобразованием введенных данных
 * к реалистичным значениям.
 * current - куда будет записана установленная дата,
 * d, m, y, h, m - устанавливаемая дата.
*/
date set_date (date* current, int day, int month, int year, int hour, int min); 


/* Выводит установленную дату в файловый поток.
*/ 
int put_date (date out_date, FILE* ostream);


/* Приглашение ко вводу даты.
 * current - куда будет записана устанавливаемая дата,
 * istream - поток файлового ввода,
 * ostream - поток файлового вывода,
 * prompt - начальное приглашение ко вводу.
*/
date ask_date (date* current, FILE* istream, FILE* ostream, const char* prompt);


int date_cmp (date date1, date date2);


#endif /* DATE_H_ */
