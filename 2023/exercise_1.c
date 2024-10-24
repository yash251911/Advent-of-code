#include <stdio.h>
#include <ctype.h>  // for isdigit()

// Function to extract the first and last digit from a line
int extractFirstAndLastDigit(char *line) {
    int firstDigit = -1, lastDigit = -1;

    // Find the first digit
    for (int i = 0; line[i] != '\0'; i++) {
        if (isdigit(line[i])) {
            firstDigit = line[i] - '0';
            break;
        }
    }

    // Find the last digit
    for (int i = 0; line[i] != '\0'; i++) {
        if (isdigit(line[i])) {
            lastDigit = line[i] - '0';
        }
    }

    // If both digits are found, return the combined number
    if (firstDigit != -1 && lastDigit != -1) {
        return firstDigit * 10 + lastDigit;
    }

    // Return 0 if no valid number is found
    return 0;
}

int main() {
    FILE *file, *fd;
    char line[256];
    int totalSum = 0;

    // Open the file for reading
    file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // Read each line from the file
    while (fgets(line, sizeof(line), file)) {
        // Extract the combined number from first and last digit
        int number = extractFirstAndLastDigit(line);

        fd = fopen("output.txt", "a");
        if (file == NULL) {
            printf("Error opening file!\n");
        return 1;
        }
        // printf("%d", number);
        fprintf(fd, " %d\n", number);
        fclose(fd);
        // Add the number to the total sum
        totalSum += number;
    }

    // Close the file
    fclose(file);

    // Output the total sum
    printf("The total sum is: %d\n", totalSum);

    return 0;
}
