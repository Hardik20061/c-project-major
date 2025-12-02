#include <stdio.h>
#include <string.h>
#include "fitness.h"

void deleteActivity() {
    char date[11];
    printf("Enter Date to delete (DD-MM-YYYY): ");
    scanf("%s", date);

    FILE *fp = fopen("fitness_data.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    if(fp == NULL) {
        printf("No records found!\n");
        return;
    }

    Activity act;
    int found = 0;
    while(fscanf(fp, "%s %d %f %d %d", act.date, &act.steps, &act.distance, &act.calories, &act.workoutMinutes) != EOF) {
        if(strcmp(act.date, date) != 0) {
            fprintf(temp, "%s %d %.2f %d %d\n", act.date, act.steps, act.distance, act.calories, act.workoutMinutes);
        } else {
            found = 1;
        }
    }

    fclose(fp);
    fclose(temp);

    if(found) {
        remove("fitness_data.txt");
        rename("temp.txt", "fitness_data.txt");
        printf("Record deleted successfully!\n");
    } else {
        remove("temp.txt");
        printf("Record not found for %s\n", date);
    }
}
