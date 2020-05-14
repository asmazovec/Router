/*   MIT License
 *
 *   Copyright (c) 2020 Alexander Mazovets
 *
 *   Permission is hereby granted, free of charge, to any person obtaining a copy
 *   of this software and associated documentation files (the "Software"), to deal
 *   in the Software without restriction, including without limitation the rights
 *   to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *   copies of the Software, and to permit persons to whom the Software is
 *   furnished to do so, subject to the following conditions:
 *
 *   The above copyright notice and this permission notice shall be included in all
 *   copies or substantial portions of the Software.
 *
 *   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *   OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *   SOFTWARE.
*/

#include <stdio.h>
#include "date.h"
#include "consupport.h"
#include "router.h"
#include "station.h"


int main () {
    struct station_t stations = {NULL, 0};
    struct route_t routes = {NULL, 0};
    

    station* exists;
    char key;
cancel:
    while (1) {
        fprintf (stdout, "\n\nq - выход\ns - создание станции\nr - создание маршрута\np - печать сводных таблиц\n");
        key = input_key (stdin, stdout, "qsrp", "Выберите пункт меню: ");
        switch (key) {
        case ('r'):
            /// Добавление новой станции
            exists = find_station (
                    set_station (input_word (NULL, 256, stdin, stdout, "Укажите название станции: "), NULL),
                    stations);
            if (exists) {
                add_route (
                    set_route (
                        *exists,
                        ask_date (NULL, stdin, stdout, "Укажите дату прибытия:\n"),
                        NULL),
                    &routes);
            } else {
                printf ("Станции с таким названием не существует.\n");
            }
            
            break;
        

        case ('s'):
            add_station (set_station (input_word (NULL, 256, stdin, stdout, "Введите название станции: "), NULL), &stations);
            break;


        case ('p'):
            fprintf (stdout, "r - маршруты\ns - станции\nc - отмена ввода \n");
            while (key = input_key (stdin, stdout, "rsc", "Что вывести на печать? : ")) {
                switch (key) {
                case ('r'):
                    print_route_t (routes, stdout);
                    goto cancel;
                    break;

                case ('s'):
                    print_station_t (stations, stdout);
                    goto cancel;
                    break;

                case ('c'):
                    goto cancel;
                    break;

                default:
                    fprintf (stdout, "Ошибка ввода, повторите ввод.\n");
                }
            }
            break;


        case ('q'):
            free (exists);
            return 0;
            break;


        default:
            fprintf (stdout, "Ошибка ввода, повторите ввод.\n");
            break;
        }
    }

    return 0;
}








