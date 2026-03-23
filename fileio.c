#include <stdio.h>
#include <stdlib.h>
#include "fileio.h"

void load_data_from_file(const char *filename, double **data, int *size) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Failed to open file.\n");
        return;
    }

    double temp;
    int count = 0;

    while (fscanf(fp, "%lf", &temp) == 1) {
        count++;
    }

    rewind(fp);

    *data = (double *)realloc(*data, count * sizeof(double));
    if (*data == NULL) {
        printf("Memory allocation failed.\n");
        fclose(fp);
        *size = 0;
        return;
    }

    for (int i = 0; i < count; i++) {
        fscanf(fp, "%lf", &((*data)[i]));
    }

    *size = count;
    fclose(fp);

    printf("%d NOI values loaded successfully.\n", *size);
}
