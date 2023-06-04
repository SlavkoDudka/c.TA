#include <stdio.h>
#include <stdlib.h>

#define INPUT_FILENAME "input.txt"
#define OUTPUT_FILENAME "output.txt"

void rearrangeWord(const char* inputFilename, const char* outputFilename)
{
    // ³�������� ������� ���� ��� �������
    FILE* inputFile;
    if (fopen_s(&inputFile, inputFilename, "r") != 0) {
        printf("An error occurred while opening the input file.\n");
        return;
    }

    // ��������� �������� ���� ��� ������
    FILE* outputFile;
    if (fopen_s(&outputFile, outputFilename, "w") != 0) {
        printf("An error occurred while creating the source file.\n");
        fclose(inputFile);
        return;
    }

    char word[] = "��������";
    int wordLength = sizeof(word) / sizeof(word[0]) - 1; // ��������� ������ ���������� ����� '\0'

    char currentChar;
    int wordIndex = 0;

    // ������ ������� � �������� �����
    while ((currentChar = fgetc(inputFile)) != EOF) {
        if (currentChar >= '�' && currentChar <= '�') {
            // �������� ������� � ����� "��������" �� ������� � �������� �����
            fputc(word[wordIndex], outputFile);
            wordIndex = (wordIndex + 1) % wordLength;
        }
        else {
            // ������� ������� ������� ��������� �����
            fputc(currentChar, outputFile);
        }
    }

    // ��������� �����
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
