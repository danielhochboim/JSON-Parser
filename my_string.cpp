#include "my_string.h"

char* my_strdup(const char* str) {
    char* dupstr;
    int len = 0;
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    len = i;
    dupstr = (char*)malloc((len + 1) * sizeof(char));
    if (dupstr == NULL) {
        return NULL;
    }
    for (i = 0; str[i] != '\0'; i++) {
        dupstr[i] = str[i];
    }
    dupstr[i + 1] = '\0';
    return dupstr;
}

char* my_strtok(char* str, const char* delim) {

    static char* input = NULL;

    if (str != NULL)
        input = str;

    if (input == NULL)
        return NULL;

    char* result = (char*)malloc((strlen(input) + 1) * sizeof(char));
    int i;

    for (i = 0; input[i] != '\0'; i++) {

        if (input[i] != *delim)
            result[i] = input[i];

        else {
            result[i] = '\0';
            input = input + i + 1;
            return result;
        }
    }

    result[i] = '\0';
    input = NULL;

    return result;
}