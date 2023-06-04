#include <stdio.h>
#include <stdlib.h>

#define INPUT_FILENAME "input.txt"
#define OUTPUT_FILENAME "output.txt"

void rearrangeWord(const char* inputFilename, const char* outputFilename)
{
    // Відкриваємо вхідний файл для читання
    FILE* inputFile;
    if (fopen_s(&inputFile, inputFilename, "r") != 0) {
        printf("An error occurred while opening the input file.\n");
        return;
    }

    // Створюємо вихідний файл для запису
    FILE* outputFile;
    if (fopen_s(&outputFile, outputFilename, "w") != 0) {
        printf("An error occurred while creating the source file.\n");
        fclose(inputFile);
        return;
    }

    char word[] = "алгоритм";
    int wordLength = sizeof(word) / sizeof(word[0]) - 1; // Враховуємо символ завершення рядка '\0'

    char currentChar;
    int wordIndex = 0;

    // Читаємо символи з вхідного файлу
    while ((currentChar = fgetc(inputFile)) != EOF) {
        if (currentChar >= 'а' && currentChar <= 'я') {
            // Замінюємо символи зі слова "алгоритм" на символи з вхідного файлу
            fputc(word[wordIndex], outputFile);
            wordIndex = (wordIndex + 1) % wordLength;
        }
        else {
            // Копіюємо незмінені символи вихідного файлу
            fputc(currentChar, outputFile);
        }
    }

    // Закриваємо файли
    fclose(inputFile);
    fclose(outputFile);

    printf("Completed. The result is saved in a file \"%s\".\n", outputFilename);
}

int main()
{
#define _CRT_SECURE_NO_WARNINGS
    rearrangeWord(INPUT_FILENAME, OUTPUT_FILENAME);
    return 0;
}
