/* MIT License
 *
 * Copyright (c) Alexander Mazovets
*/

#ifndef STATION_H_
#define STATION_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    char* denomination;
} station;


struct station_t {
    station* table;
    int size;
};


station set_station (char* denomination, station* current);
station* add_station (station current, struct station_t* table);
station* find_station (station current, struct station_t table);
int station_cmp (station station1, station station2);
int print_station (station current, FILE* ostream);
int print_station_t (struct station_t current, FILE* ostream);


#endif /* STATION_H_ */
