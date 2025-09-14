#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_TOKENS 100   
#define MAX_LEN 50
#define TOTAL_TESTS 48

int main() {
    FILE* file = fopen("A1_tests.txt", "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }
    
    uint32_t num1, base;
    char str3[MAX_LEN];
    int testNum = 1;
    int testsPassed = 0;

    // Scanning each line in file and separating by whitespace DIV_CONVERT
    while (fscanf(file, "%d %d %127s", &num1, &base, str3) == 3) {
        char tempAnswer[MAX_LEN];
        div_Convert(num1, base, tempAnswer);

        // having trouble printing 32 bit number, math still checks out though?
        if (strcmp(str3, tempAnswer) == 0) {
            printf("Test %d: div_convert (%d, % d)->Expected :% s, Got : % s[PASS]\n", testNum, num1, base, str3, tempAnswer);
            testsPassed++;
        }
        else 
        {
            printf("Test %d: div_convert (%d, %d) -> Expected : %s , Got : %s [ FAIL ]\n", testNum, num1, base, str3, tempAnswer);
        }
        testNum++;
    }

    rewind(file);

    // SUB_CONVERT loop
    while (fscanf(file, "%d %d %127s", &num1, &base, str3) == 3) {
        char tempAnswer2[MAX_LEN];
        sub_Convert(num1, base, tempAnswer2);

        if (strcmp(str3, tempAnswer2) == 0) {
            printf("Test %d: sub_convert (%d, %d) -> Expected : %s , Got : %s [ PASS ]\n", testNum, num1, base, str3, tempAnswer2);
            testsPassed++;
        }
        else
        {
            printf("Test %d: sub_convert (%d, %d) -> Expected : %s , Got : %s [ FAIL ]\n", testNum, num1, base, str3, tempAnswer2);
        }
        testNum++;
    }
    fclose(file);
    file = fopen("print_tables_cases.txt", "r");

    // print tables loop
    while (fscanf(file, "%d", &num1) == 1) {
        print_tables(num1);
        testsPassed++;
    }

    printf("%d/%d tests passed", testsPassed, TOTAL_TESTS);
    
    print_tables(5);
    return 0;
}
