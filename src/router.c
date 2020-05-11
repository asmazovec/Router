/* MIT License
 *
 * Copyright (c) Alexander Mazovets
*/

#include "router.h"


route set_route (station terminal, date departure, route* current) {
    route tmp = {terminal, departure};
    if (current) {
        current->terminal = terminal;
        current->departure = departure;
    }
    return tmp;
}


route* add_route (route current, struct route_t* table) {
    route* exists = find_route (current, *table);
    if (exists) {
        return exists;
    }
    table->size++;
    table->table = (route*) realloc (table->table, table->size*sizeof (route));
    table->table[table->size-1] = current;
    return &table->table[table->size-1];
}


route* find_route (route current, struct route_t table) {
    for (int i = 0; i < table.size; i++) {
        if (0==route_cmp (current, table.table[i])) {
            return &table.table[i];
        }
    }
    return NULL;
}


int route_cmp (route route1, route route2) {
    if ((0==station_cmp (route1.terminal, route2.terminal)) &&
        (0==date_cmp (route1.departure, route2.departure))) {
        return 0;
    }
    return 1;
}


int print_route (route current, FILE* ostream) {
    print_station (current.terminal, ostream);
    fprintf (ostream, " :: ");
    put_date (current.departure, ostream);
    return 0;
}


int print_route_t (struct route_t current, FILE* ostream) {
    for (int i = 0; i < current.size; i++) {
        fprintf (ostream, "%-4d ", i);
        print_route (current.table[i], ostream);
        fprintf (ostream, "\n");
    }
    return 0;
}
