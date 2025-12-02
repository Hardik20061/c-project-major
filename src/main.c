#include <stdio.h>
#include <stdlib.h>
#include <fitness.h>

int main() {
    int choice;
    do {
        printf("\n========= FITNESS TRACKER =========\n");
        printf("1. Add Activity\n");
        printf("2. View All Activities\n");
        printf("3. Search Activity by Date\n");
        printf("4. Weekly / Monthly Summary\n");
        printf("5. Update Activity\n");
        printf("6. Delete Activity\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: addActivity(); break;
            case 2: viewActivities(); break;
            case 3: searchActivity(); break;
            case 4: calculateSummary(); break;
            case 5: updateActivity(); break;
            case 6: deleteActivity(); break;
            case 7: printf("Exiting...\n"); break;
            default: printf("Invalid choice! Try again.\n");
        }
    } while(choice != 7);

    return 0;
}
