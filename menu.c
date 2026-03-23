#include <stdio.h>
#include "menu.h"

int show_menu() {
    int choice;
    printf("\n==== Real Estate Cash Flow Analyzer ====\n");
    printf("1. Enter NOI data manually\n");
    printf("2. Load NOI data from file\n");
    printf("3. Calculate mean NOI\n");
    printf("4. Calculate median NOI\n");
    printf("5. Display min and max NOI\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}
