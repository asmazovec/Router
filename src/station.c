/* MIT License
 *
 * Copyright (c) Alexander Mazovets
*/

#include "station.h"


station set_station (char* denomination, station* current) {
    station tmp = {denomination};
    if (current) {
        current->denomination = denomination;
    }
    return tmp;
}


station* add_station (station current, struct station_t* table) {
    station* exists = find_station (current, *table);
    if (exists) {
        return exists;
    }
    table->size++;
    table->table = (station*) realloc (table->table, table->size*sizeof (station));
    table->table[table->size-1] = current;
    return &table->table[table->size-1];
}


station* find_station (station current, struct station_t table) {
    for (int i = 0; i < table.size; i++) {
        if (0==station_cmp (current, table.table[i])) {
            return &table.table[i];
        }
    }
    return NULL;
}


int station_cmp (station station1, station station2) {
    if (0==strcmp (station1.denomination, station2.denomination)) {
        return 0;
    }
    return 1;
}


int print_station (station current, FILE* ostream) {
    fprintf (ostream, "%s", current.denomination);
    return 0;
}


int print_station_t (struct station_t current, FILE* ostream) {
    for (int i = 0; i < current.size; i++) {
        fprintf (ostream, "%-4d ", i);
        print_station (current.table[i], ostream);
        fprintf (ostream, "\n");
    }
    return 0;
}

