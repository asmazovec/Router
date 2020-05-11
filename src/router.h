/* MIT License
 *
 * Copyright (c) Alexander Mazovets
*/

#ifndef ROUTER_H_
#define ROUTER_H_

#include <stdio.h>
#include <stdlib.h>
#include "date.h"
#include "station.h"
#include "consupport.h"


typedef struct {
    station terminal;
    date departure;
} route;


struct route_t {
    route* table;
    int size;
};


route set_route (station terminal, date departure, route* current);
route* add_route (route current, struct route_t* table);
route* find_route (route current, struct route_t table);
int route_cmp (route route1, route route2);
int print_route (route current, FILE* ostream);
int print_route_t (struct route_t current, FILE* ostream);


#endif /* ROUTER_H_ */
