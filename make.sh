#! /bin/bash 

gcc src/station.c src/router.c src/date.c src/consupport.c src/main.c -o bin/router.out
./bin/router.out
