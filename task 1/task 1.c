#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fptr;
    char data[100];

    // ================= CREATE + WRITE =================
    fptr = fopen("internship_task.txt", "w");

    if (fptr == NULL) {
        printf("Error creating file!\n");
        return 1;
    }

    printf("Enter text to write to the file:\n");
    fgets(data, sizeof(data), stdin);
    fprintf(fptr, "%s", data);
    fclose(fptr);

    printf("Data written successfully.\n");

    // ================= APPEND =================
    fptr = fopen("internship_task.txt", "a");

    if (fptr == NULL) {
        printf("Error opening file for append!\n");
        return 1;
    }

    printf("\nEnter text to append:\n");
    fgets(data, sizeof(data), stdin);
    fprintf(fptr, "%s", data);
    fclose(fptr);

    printf("Data appended successfully.\n");

    // ================= READ =================
    fptr = fopen("internship_task.txt", "r");

    if (fptr == NULL) {
        printf("Error opening file for reading!\n");
        return 1;
    }

    printf("\nFinal File Content:\n");

    while (fgets(data, sizeof(data), fptr) != NULL) {
        printf("%s", data);
    }

    fclose(fptr);

    return 0;
}


