#include <stdio.h>
#include <fitness.h>

void viewActivities() {
    FILE *fp = fopen("fitness_data.txt", "r");
    if(fp == NULL) {
        printf("No records found!\n");
        return;
    }

    Activity act;
    printf("\nDATE       STEPS  DIST(km)  CALORIES  WORKOUT(min)\n");
    printf("---------------------------------------------------\n");
    while(fscanf(fp, "%s %d %f %d %d", act.date, &act.steps, &act.distance, &act.calories, &act.workoutMinutes) != EOF) {
        printf("%s  %5d   %6.2f   %7d   %7d\n", act.date, act.steps, act.distance, act.calories, act.workoutMinutes);
    }
    fclose(fp);
}
