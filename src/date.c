/* MIT License 
 *
 * Copyright (c) Alexander Mazovets
*/

#include "date.h"


/* Установка времени.
 * Возвращает дату в виде структуры с преобразованием введенных данных
 * к реалистичным значениям.
 * current - куда будет записана установленная дата,
 * d, m, y, h, m - устанавливаемая дата.
*/ 
date set_date (date* current, int day, int month, int year, int hour, int min) {
    month--;

    hour += min / 60;
    min %= 60;

    day += hour / 24;
    hour %= 24;
    
    int cur = (month % 12) + 1;
    int month_days = 28 + (cur + cur/8)%2 + 2%cur + 1/cur*2; 

    while (day / month_days) {
        day -= month_days;
        month++;
        cur = (month % 12) + 1;
        month_days = 28 + (cur + cur/8)%2 + 2%cur + 1/cur*2;
    }

    year += month / 12;
    month %= 12;

    if (current) {
        current->day   = day;
        current->month = month;
        current->year  = year;
        current->hour  = hour;
        current->min   = min;
    }

    date tmp = {day, month, year, hour, min};
    return tmp;
}


/* Выводит установленную дату в файловый поток.
*/ 
int put_date (date out_date, FILE* ostream) {
    return fprintf (ostream, "%d/%d/%d %02d.%02d\n",
            out_date.day,
            out_date.month+1,
            out_date.year,
            out_date.hour,
            out_date.min);
}


/* Приглашение ко вводу даты.
 * current - куда будет записана устанавливаемая дата,
 * istream - поток файлового ввода,
 * ostream - поток файлового вывода,
 * prompt - начальное приглашение ко вводу.
*/
date ask_date (date* current, FILE* istream, FILE* ostream, const char* prompt) {
    fprintf (ostream, "%s", prompt);
    int day, month, year, hour, min;

    input_num (&day  , istream, ostream, " День:   ");
    input_num (&month, istream, ostream, " Месяц:  ");
    input_num (&year , istream, ostream, " Год:    ");
    input_num (&hour , istream, ostream, " Часы:   ");
    input_num (&min  , istream, ostream, " Минуты: ");

    return set_date (current, day, month, year, hour, min);
}


int date_cmp (date date1, date date2) {
    if (
            (date1.day==date2.day) &&
            (date1.month==date2.month) &&
            (date1.year==date2.year) &&
            (date1.hour==date2.hour) &&
            (date1.min==date2.min) 
            ) {
        return 0;
    }
    return 1;
}
