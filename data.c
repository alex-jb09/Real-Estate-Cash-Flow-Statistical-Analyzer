#include <stdio.h>
#include <stdlib.h>
#include "data.h"

void input_data(double **data, int *size) {
    int n;
    printf("Enter number of NOI values: ");
    scanf("%d", &n);

    *data = (double *)realloc(*data, n * sizeof(double));
    if (*data == NULL) {
        printf("Memory allocation failed.\n");
        *size = 0;
        return;
    }

    *size = n;
    printf("Enter NOI values:\n");
    for (int i = 0; i < n; i++) {
        scanf("%lf", &((*data)[i]));
    }
}
