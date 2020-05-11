/* MIT License
 *
 * Copyright (c) 2020 Alexander Mazovets
*/

#include "consupport.h"


/* Приглашение ко вводу символа-ключа
 * Если введенный символ совпадает с одним из целевых символов, возвращает этот символ;
 * Если введенного символа нет среди целевых символов, возвращает NULL.
 * istream - файловый поток ввода,
 * ostream - файловый поток вывода,
 * purposes - строка с целевыми символами,
 * prompt - строка приглашения ко вводу.
*/ 
char input_key (FILE* istream, FILE* ostream, const char* purposes, const char* prompt) {
    char key;

    fprintf (ostream, prompt);
    fscanf (istream, "%c", &key);
    
    while (*purposes) {
        if (*purposes==key) {
            return key;
        }
        *purposes++;
    }

    return 0;
}


/* Приглашение ко вводу целого числа.
 * num - указатель на число, в которое будет вестись запись,
 * istream - файловый поток ввода,
 * ostream - файловый поток вывода,
 * prompt - строка приглашения ко вводу.
*/
int input_num (int* num, FILE* istream, FILE* ostream, const char* prompt) { 
    int* tmp = (int*) malloc (sizeof (int));
    fprintf (ostream, prompt);
    fscanf (istream, "%d", tmp);
    if (num) {
        *num = *tmp;
    }
    return *tmp;
}


/* Приглашение ко вводу строки.
 * str - строка, в которую будет вестись запись,
 * istream - файловый поток ввода,
 * ostream - файловый поток вывода,
 * prompt - приглашение ко вводу.
*/
char* input_word (char* str, int size, FILE* istream, FILE* ostream, const char* prompt) {
    char* tmp = (char*) malloc (size*sizeof(char));
    fprintf (ostream, prompt);
    fscanf (istream, "%s", tmp);
    if (str) {
        strcpy (str, tmp);
    }
    return tmp;
}
