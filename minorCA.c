#include <stdio.h>
#include <stdlib.h>

// Function to get a coefficient from the user with error checking
double get_coefficient(char name) {
    double coefficient;
    while (1) {
        printf("Enter coefficient %c: ", name);
        if (scanf("%lf", &coefficient) != 1) {
            printf("Invalid input. Coefficient %c must be a number.\n", name);
            while (getchar() != '\n'); // clear input buffer
        } else if (coefficient == 0 && name == 'a') {
            printf("Invalid input. Coefficient a cannot be zero.\n");
        } else {
            return coefficient;
        }
    }
}

// Function to calculate the discriminant and return its value
double get_discriminant(double a, double b, double c) {
    return b * b - 4 * a * c;
}

// Custom square root function using the Newton-Raphson method
double my_sqrt(double x) {
    if (x == 0.0) {
        return 0.0;
    }
    double prev = 0.0;
    double next = 1.0;
    while (prev != next) {
        prev = next;
        next = (prev + x / prev) / 2;
    }
    return next;
}

// Function to solve the quadratic equation and print the results
void solve_quadratic(double a, double b, double c) {
    double discriminant = get_discriminant(a, b, c);
    if (discriminant > 0) {
        double root1 = (-b + my_sqrt(discriminant)) / (2 * a);
        double root2 = (-b - my_sqrt(discriminant)) / (2 * a);
        printf("has two real roots: %.2lf and %.2lf\n", root1, root2);
    } else if (discriminant == 0) {
        double root1 = -b / (2 * a);
        printf("has one real root: %.2lf\n", root1);
    } else {
        double realPart = -b / (2 * a);
        double imagPart = my_sqrt(-discriminant) / (2 * a);
        printf("has two complex roots: %.2lf + %.2lfi and %.2lf - %.2lfi\n", realPart, imagPart, realPart, imagPart);
    }
}

int main() {
    char Flag = 'Y';
    while(Flag=='Y' || Flag=='y'){
    printf("=============================\n");
    printf("Quadratic Equation Solver\n");
    printf("ax^2 + bx + c = 0\n");
    printf("=============================\n");
    
    
    double a = get_coefficient('a');
    double b = get_coefficient('b');
    double c = get_coefficient('c');
    
    printf("The equation of %.2lfx^2 + %.2lfx + %.2lf = 0 \n", a, b, c);
    
    solve_quadratic(a, b, c);
    printf("Do you want to solve another equation? (Y/N): ");
    scanf(" %c",&Flag);
    }
    
    printf("Program End");
    return 0;
}
