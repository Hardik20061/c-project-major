#include <stdio.h>
#include "fitness.h"

void addActivity() {
    FILE *fp = fopen("fitness_data.txt", "a");
    if(fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    Activity act;
    printf("Enter Date (DD-MM-YYYY): ");
    scanf("%s", act.date);
    printf("Enter Steps Walked: ");
    scanf("%d", &act.steps);
    printf("Enter Distance (km): ");
    scanf("%f", &act.distance);
    printf("Enter Calories Burned: ");
    scanf("%d", &act.calories);
    printf("Enter Workout Minutes: ");
    scanf("%d", &act.workoutMinutes);

    fprintf(fp, "%s %d %.2f %d %d\n", act.date, act.steps, act.distance, act.calories, act.workoutMinutes);
    fclose(fp);

    printf("Activity added successfully!\n");
}
