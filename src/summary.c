#include <stdio.h>
#include "fitness.h"

void calculateSummary() {
    FILE *fp = fopen("fitness_data.txt", "r");
    if(fp == NULL) {
        printf("No records found!\n");
        return;
    }

    Activity act;
    int totalSteps = 0, totalCalories = 0, count = 0, totalWorkout = 0;

    while(fscanf(fp, "%s %d %f %d %d", act.date, &act.steps, &act.distance, &act.calories, &act.workoutMinutes) != EOF) {
        totalSteps += act.steps;
        totalCalories += act.calories;
        totalWorkout += act.workoutMinutes;
        count++;
    }
    fclose(fp);

    if(count == 0) {
        printf("No data to summarize!\n");
        return;
    }

    printf("\n=== Summary ===\n");
    printf("Total Records: %d\n", count);
    printf("Total Steps: %d\n", totalSteps);
    printf("Total Calories: %d\n", totalCalories);
    printf("Average Workout Minutes: %.2f\n", (float)totalWorkout/count);
}
