#include <stdio.h>
#include <stdlib.h>

#define FIRST_STAGE "Input first number: "
#define SECOND_STAGE "Input operation: "
#define THIRD_STAGE "Input second number: "
#define STAGES 3
#define MAX_CHARACTERS 22

void print(char message[]) {
    for (int i = 0; message[i] != '\0'; i++) {
        putchar(message[i]);
    }
}

int is_digit(int a) {
    if (a >= '0' && a <= '9') {
        return 1;
    }

    return 0;
}

int add(int a, int b) {
    return a + b;
}

int sub(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

int divide(int a, int b) {
    return a / b;
}

int main() {

    int c;

    int stage = 0;
    int count = 0;

    long int first_int = 0;
    int operation;
    long int second_int = 0;
    
    print(FIRST_STAGE);
    
    while ((c = getchar()) != EOF) {
        
        if (stage == 0 && is_digit(c)) {
            first_int = first_int * 10 + (c - '0');
        } else if (stage == 1 && (c == '+' || c == '-' || c == '*' || c == '/')) {
            operation = c;
        } else if (stage == 2 && is_digit(c)) {
            second_int = second_int * 10 + (c - '0');
        } else {
            continue;
        }

        if (c == '\n') {
            stage++;

            if (stage == 3) {
                int result;

                if (operation == '+') {result = add(first_int, second_int);}
                if (operation == '-') {result = sub(first_int, second_int);}
                if (operation == '*') {result = multiply(first_int, second_int);}
                if (operation == '/') {result = divide(first_int, second_int);}

                printf("Result: %i", result);

                break;
            } else {
                char stages[STAGES][MAX_CHARACTERS] = {FIRST_STAGE, SECOND_STAGE, THIRD_STAGE};

                print(stages[stage]);
            }
        }        
    }

    return 0;
}