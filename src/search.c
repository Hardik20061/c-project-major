#include <stdio.h>
#include <string.h>
#include "fitness.h"

void searchActivity() {
    char date[11];
    printf("Enter Date to search (DD-MM-YYYY): ");
    scanf("%s", date);

    FILE *fp = fopen("fitness_data.txt", "r");
    if(fp == NULL) {
        printf("No records found!\n");
        return;
    }

    Activity act;
    int found = 0;
    while(fscanf(fp, "%s %d %f %d %d", act.date, &act.steps, &act.distance, &act.calories, &act.workoutMinutes) != EOF) {
        if(strcmp(act.date, date) == 0) {
            printf("\nDATE       STEPS  DIST(km)  CALORIES  WORKOUT(min)\n");
            printf("---------------------------------------------------\n");
            printf("%s  %5d   %6.2f   %7d   %7d\n", act.date, act.steps, act.distance, act.calories, act.workoutMinutes);
            found = 1;
            break;
        }
    }

    if(!found) printf("Record not found for %s\n", date);
    fclose(fp);
}
