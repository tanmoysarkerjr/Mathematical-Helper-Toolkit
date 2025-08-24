#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

// ------------------------
// Utility functions
// ------------------------
void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void pauseScreen() {
    printf("\nPress Enter to continue...");
    getchar();
    
    getchar();
}

void printTitle(const char *title) {
    printf("\n====================================\n");
    printf("   %s\n", title);
    printf("====================================\n");
}

// ------------------------
// 1. Math Conversion & Tools
// ------------------------
void mathConversions() {
    int choice, num, n1, n2;
    char hex[20];

    do {
        clearScreen();
        printTitle("  Math Conversion & Tools");
        printf("  1. Decimal to Binary\n");
        printf("  2. Binary to Decimal\n");
        printf("  3. Decimal to Hexadecimal\n");
        printf("  4. Hexadecimal to Decimal\n");
        printf("  5. Prime Number Check\n");
        printf("  6. Fibonacci Series\n");
        printf("  7. Find Remainder (n1 %% n2)\n");
        printf("  8. Factorial\n");
        printf("  9. Circle Area & Circumference (using radius)\n");
        printf("  0. Back to Main Menu\n");
        printf("  Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: {
                printf("Enter decimal number: ");
                scanf("%d", &num);
                printf("Binary: ");
                for(int i = 31; i >= 0; i--)
                    printf("%d", (num >> i) & 1);
                printf("\n");
                break;
            }
            case 2: {
                printf("Enter binary number: ");
                scanf("%s", hex);
                num = (int)strtol(hex, NULL, 2);
                printf("Decimal: %d\n", num);
                break;
            }
            case 3: {
                printf("Enter decimal number: ");
                scanf("%d", &num);
                printf("Hexadecimal: %X\n", num);
                break;
            }
            case 4: {
                printf("Enter hexadecimal number: ");
                scanf("%s", hex);
                num = (int)strtol(hex, NULL, 16);
                printf("Decimal: %d\n", num);
                break;
            }
            case 5: {
                printf("Enter a number: ");
                scanf("%d", &num);
                int isPrime = 1;
                if(num <= 1) isPrime = 0;
                for(int i = 2; i <= sqrt(num); i++) {
                    if(num % i == 0) {
                        isPrime = 0;
                        break;
                    }
                }
                if(isPrime) 
                    printf("%d is a Prime Number\n", num);
                else 
                    printf("%d is NOT a Prime Number\n", num);
                break;
            }
            case 6: {
                printf("Enter number of terms: ");
                scanf("%d", &num);
                int a = 0, b = 1, c;
                printf("Fibonacci Series: ");
                for(int i = 1; i <= num; i++) {
                    printf("%d ", a);
                    c = a + b;
                    a = b;
                    b = c;
                }
                printf("\n");
                break;
            }
            case 7: {
                printf("Enter two numbers (n1 n2): ");
                scanf("%d %d", &n1, &n2);
                if(n2 != 0) 
                    printf("Remainder = %d\n", n1 % n2);
                else 
                    printf("Division by zero not allowed!\n");
                break;
            }
            case 8: {
                printf("Enter a number: ");
                scanf("%d", &num);
                unsigned long long fact = 1;
                for(int i = 1; i <= num; i++) 
                    fact *= i;
                printf("Factorial of %d = %llu\n", num, fact);
                break;
            }
            case 9: {
                double r;
                printf("Enter radius: ");
                scanf("%lf", &r);
                printf("Area = %.2lf\n", M_PI * r * r);
                printf("Circumference = %.2lf\n", 2 * M_PI * r);
                break;
            }
        }
        if(choice != 0) pauseScreen();
    } while(choice != 0);
}

// ------------------------
// 2. Physics Tools
// ------------------------
void physicsTools() {
    int choice;
    double mass, velocity, height;

    do {
        clearScreen();
        printTitle("Physics Tools");
        printf("1. Kinetic Energy (0.5*m*v^2)\n");
        printf("2. Potential Energy (m*g*h)\n");
        printf("0. Back\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if(choice == 1) {
            printf("Enter mass and velocity: ");
            scanf("%lf %lf", &mass, &velocity);
            printf("Kinetic Energy: %.2lf J\n", 0.5 * mass * velocity * velocity);
        } else if(choice == 2) {
            printf("Enter mass and height: ");
            scanf("%lf %lf", &mass, &height);
            printf("Potential Energy: %.2lf J\n", mass * 9.8 * height);
        }

        if(choice != 0) pauseScreen();
    } while(choice != 0);
}

// ------------------------
// 3. Statistics Toolkit
// ------------------------
void statisticsToolkit() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    double arr[n], sum = 0;
    for(int i = 0; i < n; i++) { 
        scanf("%lf", &arr[i]); 
        sum += arr[i]; 
    }
    printf("Mean = %.2lf\n", sum / n);
}

// ------------------------
// 4. Motivational Quotes
// ------------------------
void motivationalQuote() {
    const char *quotes[] = {
        "Believe in yourself!",
        "Never give up!",
        "Every day is a new opportunity.",
        "Work hard in silence, let success be your noise."
    };
    srand(time(0));
    int idx = rand() % 4;
    printf("\nQuote: %s\n", quotes[idx]);
}

// ------------------------
// 5. Typing Speed Test
// ------------------------
void typingSpeedTest() {
    char target[] = "C programming makes you strong!";
    char input[200];
    printf("Type this: %s\n", target);
    clock_t start = clock();
    getchar();
    fgets(input, sizeof(input), stdin);
    clock_t end = clock();
    double secs = (double)(end - start) / CLOCKS_PER_SEC;
    if(strncmp(input, target, strlen(target)) == 0)
        printf("Perfect typing! Time: %.2f seconds\n", secs);
    else
        printf("Mistake! Time: %.2f seconds\n", secs);
}

// ------------------------
// 6. Daily Quiz (Fixed)
// ------------------------
void dailyQuiz() {
    FILE *fp = fopen("quiz.txt", "r");
    if (!fp) {
        printf("quiz.txt not found!\n");
        return;
    }
    char question[256], optionA[100], optionB[100], optionC[100], correct;
    int score = 0, total = 0;
    while (fscanf(fp, " %[^\n]\nA. %[^\n]\nB. %[^\n]\nC. %[^\n]\nAnswer: %c\n", 
                question, optionA, optionB, optionC, &correct) == 5) {
        char ans;
        printf("\n%s\nA. %s\nB. %s\nC. %s\nYour answer: ", question, optionA, optionB, optionC);
        getchar();
        scanf("%c", &ans);
        if (toupper(ans) == toupper(correct)) score++;
        total++;
    }
    fclose(fp);
    printf("\nYour Score: %d/%d\n", score, total);
}

// ------------------------
// Main Menu
// ------------------------
int main() {
    int choice;
    do {
        clearScreen();
        printTitle("Mathematical Helper Toolkit");
        printf("  1. Math Conversion & Tools\n");
        printf("  2. Physics Tools\n");
        printf("  3. Statistics Toolkit\n");
        printf("  4. Motivational Quote\n");
        printf("  5. Typing Speed Test\n");
        printf("  6. Daily Quiz\n");
        printf("  0. Exit\n");
        printf("\n====================================\n");
        printf("        Developed by Tanmoy\n");
        printf("====================================\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: mathConversions(); break;
            case 2: physicsTools(); break;
            case 3: statisticsToolkit(); pauseScreen(); break;
            case 4: motivationalQuote(); pauseScreen(); break;
            case 5: typingSpeedTest(); pauseScreen(); break;
            case 6: dailyQuiz(); pauseScreen(); break;
        }
    } while(choice != 0);
    printf("Goodbye!\n");
    return 0;
}
