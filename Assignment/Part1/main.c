#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define MAX_DEGREE 5
#define MAX_ITERATIONS 1000

// Function prototypes
double calculatePolynomial(double coefficients[], int degree, double x);
double calculateDerivedPolynomial(double coefficients[], int degree, double x);
double secantMethod(double coefficients[], int degree, double x0, double x1, double tolerance, int maxIterations);
double newtonRaphsonMethod(double coefficients[], int degree, double x, double tolerance, int maxIterations);
int validateAndReturnInt(int minRange, int maxRange);
double validateAndReturnDouble();
double validateAndReturnDoubleInRange(double minRange, double maxRange);
void printMenu();
void rootFindingMethod(int method);




int main() {
    int option;

    while (1) {
        printMenu();

        option = validateAndReturnInt(1, 3);

        switch (option) {
            case 1:
                rootFindingMethod(option);
                break;

            case 2:
                rootFindingMethod(option);
                break;

            case 3:
                printf("Exiting program");
                return 0;

            default:
                printf("Invalid option. Try again.\n");
        }
    }
}


// Function definitions

double calculatePolynomial(double coefficients[], int degree, double x) {
    double result = 0.0;

    for (int i = degree; i >= 0; i--) {
        result += coefficients[i] * pow(x, i);
    }

    return result;
}

double calculateDerivedPolynomial(double coefficients[], int degree, double x) {
    double result = 0.0;

    for (int i = degree - 1; i >= 0; i--) {
        result += coefficients[i + 1] * (i + 1) * pow(x, i);
    }

    return result;
}

double secantMethod(double coefficients[], int degree, double x0, double x1, double tolerance, int maxIterations) {
    double x2, f0, f1;

    for (int i = 0; i < maxIterations; i++) {
        f0 = calculatePolynomial(coefficients, degree, x0);
        f1 = calculatePolynomial(coefficients, degree, x1);

        x2 = x1 - (f1 * ((x1 - x0) / (f1 - f0)));

        if (fabs(x2 - x1) < tolerance) {
            printf("Root found!\n");
            return x2;
        }

        x0 = x1;
        x1 = x2;
    }

    printf("Secant method did not converge within the specified iterations.\n");
    return NAN;
}

double newtonRaphsonMethod(double coefficients[], int degree, double x, double tolerance, int maxIterations) {
    double x1, fx, fpx;

    for (int i = 0; i < maxIterations; i++) {
        fx = calculatePolynomial(coefficients, degree, x);
        fpx = calculateDerivedPolynomial(coefficients, degree, x);

        if (fabs(fpx) < tolerance) {
            printf("Derivative is close to zero. Newton-Raphson method cannot continue.\n");
            return NAN;
        }

        x1 = x - (fx / fpx);

        if (fabs(x1 - x) < tolerance) {
            printf("Root found at x = %lf\n", x1);
            return x1;
        }

        x = x1;
    }

    printf("Newton-Raphson method did not converge within the specified iterations.\n");
    return NAN;
}

int validateAndReturnInt(int minRange, int maxRange) {
    int returnValue;
    char extraChar;

    while (1) {
        if (scanf("%d%c", &returnValue, &extraChar) != 2 || extraChar != '\n' || returnValue < minRange || returnValue > maxRange) {
            printf("Invalid input. Try again: ");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        break;
    }

    return returnValue;
}

double validateAndReturnDouble() {
    double returnValue;
    char extraChar;

    while (1) {
        if (scanf("%lf%c", &returnValue, &extraChar) != 2 || !isspace(extraChar)) {
            printf("Invalid input. Try again: ");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        break;
    }

    return returnValue;
}

double validateAndReturnDoubleInRange(double minRange, double maxRange) {
    double returnValue;
    char extraChar;

    while (1) {
        if (scanf("%lf%c", &returnValue, &extraChar) != 2 || !isspace(extraChar) || returnValue < minRange || returnValue > maxRange) {
            printf("Invalid input. Try again: ");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        break;
    }

    return returnValue;
}

void printMenu() {
    printf("1. Secant root-finding method\n");
    printf("2. Newton-Raphson root-finding method\n");
    printf("3. Quit\n");
    printf("----------------------------------------------\n");
    printf("Enter a choice (1, 2, or 3): ");
}

void rootFindingMethod(int method) {
    int degree,maxIterations;
    double x0, x1, tolerance,root;

    printf("Enter max iterations (1-%d): ",MAX_ITERATIONS);
    maxIterations = validateAndReturnInt(1, MAX_ITERATIONS);


    printf("Enter tolerance(0-1): ");
    tolerance = validateAndReturnDoubleInRange(0, 1);

    printf("Enter the degree of the polynomial (1-%d): ", MAX_DEGREE);
    degree = validateAndReturnInt(1, MAX_DEGREE);

    double coefficients[degree + 1];
    printf("Enter the coefficients of the polynomial (from highest degree to constant term):\n");

    for (int i = degree; i >= 0; i--) {
        printf("x%d: ", i);
        coefficients[i] = validateAndReturnDouble();
    }

    printf("Enter x0: ");
    x0 = validateAndReturnDouble();

    if (method == 1) {
        printf("Enter x1: ");
        x1 = validateAndReturnDouble();

        root = secantMethod(coefficients, degree, x0, x1, tolerance, maxIterations);
    }

    if (method == 2) {
        root = newtonRaphsonMethod(coefficients, degree, x0, tolerance, maxIterations);
    }

    if (!isnan(root)) {
        printf("Approximate root: %lf\n", root);
    }

    printf("Returning back to menu.\n\n");
}