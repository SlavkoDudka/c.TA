#include <stdio.h>
#include <math.h>

#define FILENAME "input.txt"

int countOddSquareNumbers(FILE* file) {
    int number;
    int count = 0;

    while (fscanf_s(file, "%d", &number) != EOF) {
        if (number % 2 != 0) { // Перевіряємо, чи число непарне
            double square = sqrt(number);
            if (square == (int)square) { // Перевіряємо, чи число є квадратом
                count++;
            }
        }
    }

    return count;
}

int findDifference(FILE* file) {
    int number;
    int maxEven = 0;
    int minOdd = 0;
    int isFirstOdd = 1;

    while (fscanf_s(file, "%d", &number) != EOF) {
        if (number % 2 == 0) { // Перевіряємо, чи число парне
            if (number > maxEven) {
                maxEven = number;
            }
        }
        else { // Число непарне
            if (isFirstOdd) {
                minOdd = number;
                isFirstOdd = 0;
            }
            else {
                if (number < minOdd) {
                    minOdd = number;
                }
            }
        }
    }

    return maxEven - minOdd;
}

int main() {
    FILE* file;
    if (fopen_s(&file, FILENAME, "r") != 0) {
        printf("An error occurred while opening the file.\n");
        return 1;
    }

    int oddSquareCount = countOddSquareNumbers(file);
    fseek(file, 0, SEEK_SET); // Переміщуємо покажчик файлу на початок
    int difference = findDifference(file);

    fclose(file);

    printf("The number of squares of odd numbers: %d\n", oddSquareCount);
    printf("The difference between the largest even number and the smallest odd number: %d\n", difference);

    return 0;
}
