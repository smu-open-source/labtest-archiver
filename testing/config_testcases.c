/*
* Testing for individual config.c functions
*/

#include "../include/config.h"


int main(void) {
    FILE *fp = fopen("config_test", "rb");
    char * buffer = malloc(1000);
    memset(buffer, 0, 1000);

    int stat = 0;
    while (stat != -1) {
        printf("%s %i\n", buffer, stat);
        stat = read_config_line(fp, buffer, 1000);
    }

    fclose(fp);
    free(buffer);
}