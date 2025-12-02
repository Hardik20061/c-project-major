#ifndef FITNESS_H
#define FITNESS_H

typedef struct {
    char date[11];       // Format: DD-MM-YYYY
    int steps;
    float distance;
    int calories;
    int workoutMinutes;
} Activity;

void addActivity();
void viewActivities();
void searchActivity();
void calculateSummary();
void updateActivity();
void deleteActivity();

#endif
