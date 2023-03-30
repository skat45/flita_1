#include <stdio.h>
#include <string.h>


int pow (int x, int y) {
    if (y == 0) return 1;
    int result = 1;
    for (int i = 0; i < y; i++) {
        result *= x;
    }
    return result;
}

int toDec(char input[]) {
    int length = strlen(input);
    int sum = 0;
    short isBinary = 1;
    for (int i = 0; i < length; i++) {
        switch (input[i]) {
            case '1':
                sum += pow(2, length - i - 1);
                break;

            case '0':
                break;

            default:
                isBinary = 0;
        }
    }

    if (isBinary) return sum;
    else return -1;
}


short alreadyMet(int num, int len, int array[]) {
    short result = 0;
    for (int i = 0; i < len; i++) {
        if (num == array[i]) {
            result = 1;
            break;
        }
    }

    return result;
}


int main() {
    int numOfTryings;
    printf("Enter the number of your inputs \n");
    scanf("%d", &numOfTryings);

    char binaryDigits[numOfTryings][50];
    int digits[numOfTryings];
    int numOfElements = 0;
    int triesCounter = 0;

    while (triesCounter < numOfTryings) {
        char input[50];
        printf("Enter the binary digit: \n");
        scanf("%s", &input);
        int digit = toDec(input);
        if (digit == -1) {
            printf("Your input is not a binary digit! Try again: \n");
            continue;
        }

        if (!alreadyMet(digit, numOfElements, digits)) {
            int length = strlen(input);
            for (int i = 0; i <= length; i++) {
                binaryDigits[numOfElements][i] = input[i];
            }
            digits[numOfElements] = digit;
            numOfElements++;
        }

        triesCounter++;
    }

    printf("\n Printing sets...\n");
    printf("Binary \t\t Dec \n");
    for (int i = 0; i < numOfElements; i++) {
        printf("%s \t\t %d \n", binaryDigits[i], digits[i]);
    }
    return 0;
}