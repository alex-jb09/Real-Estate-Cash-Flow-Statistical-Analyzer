#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "data.h"
#include "stats.h"
#include "fileio.h"

int main() {
    double *data = NULL;
    int size = 0;
    int choice;
    char filename[100];

    while (1) {
        choice = show_menu();

        switch (choice) {
            case 1:
                input_data(&data, &size);
                break;
            case 2:
                printf("Enter file name: ");
                scanf("%s", filename);
                load_data_from_file(filename, &data, &size);
                break;
            case 3:
                if (size == 0) {
                    printf("No data available.\n");
                } else {
                    printf("Mean NOI: %.2f\n", mean(data, size));
                }
                break;
            case 4:
                if (size == 0) {
                    printf("No data available.\n");
                } else {
                    printf("Median NOI: %.2f\n", median(data, size));
                }
                break;
            case 5:
                if (size == 0) {
                    printf("No data available.\n");
                } else {
                    printf("Min NOI: %.2f\n", min_value(data, size));
                    printf("Max NOI: %.2f\n", max_value(data, size));
                }
                break;
            case 6:
                free(data);
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
}
