#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int total_print_space = 100;

void print_with_indent_centered(int total_print_space, char * string);
void print_equal_signs(int total_print_space);
void my_strcat(char * destination, char * source);

void red_bolded () {
  printf("\033[1;31m");
}

void yellow () {
  printf("\033[1;33m");
}

void bolded () {
  printf("\033[1m");
}

void reset () {
  printf("\033[0m");
}

// Function to get a coefficient from the user with error checking
double get_coefficient(char name) {
    double coefficient;
    while (1) {
        printf("Enter coefficient %c: ", name);
        if (scanf("%lf", &coefficient) != 1) {
            red_bolded();
            printf("[ERROR] Invalid input. Coefficient %c must be a number.\n", name);
            reset();
            while (getchar() != '\n'); // clear input buffer
        } else if (coefficient == 0 && name == 'a') {
            red_bolded();
            printf("[ERROR] Invalid input. Coefficient a cannot be zero.\n");
            reset();
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
    char buffer_1[46]= "Root 1 : ";
    char buffer_2[46]= "Root 2 : ";
    char buffer_1root[46]= "Root : ";
    char buffer[38];
    char buffer2[38];
    char buffer_1root_value[39];

    if (discriminant > 0) {
        double root1 = (-b + my_sqrt(discriminant)) / (2 * a);
        double root2 = (-b - my_sqrt(discriminant)) / (2 * a);
        snprintf(buffer, 38, "%f", root1);
        my_strcat(buffer_1, buffer);
        snprintf(buffer, 38, "%f", root2);
        my_strcat(buffer_2, buffer);
        printf("|"); print_with_indent_centered(total_print_space-2, "TWO REAL roots"); printf("|\n"); 
        print_equal_signs(total_print_space);

        printf("|"); print_with_indent_centered(total_print_space-2, buffer_1); printf("|\n");
        printf("|"); print_with_indent_centered(total_print_space-2, buffer_2); printf("|\n");

        print_equal_signs(total_print_space);
    } else if (discriminant == 0) {
        double root1 = -b / (2 * a);
        snprintf(buffer_1root_value, 39, "%f", root1);
        my_strcat(buffer_1root, buffer_1root_value);

        printf("|"); print_with_indent_centered(total_print_space-2, "ONE REAL root"); printf("|\n"); 
        print_equal_signs(total_print_space);

        printf("|"); print_with_indent_centered(total_print_space-2, buffer_1root); printf("|\n");
        print_equal_signs(total_print_space);
    } else {
        double realPart = -b / (2 * a);
        double imagPart = my_sqrt(-discriminant) / (2 * a);
        snprintf(buffer, 38, "%.2lf + %.2lfi", realPart, imagPart);
        my_strcat(buffer_1, buffer);
        snprintf(buffer2, 38, "%.2lf - %.2lfi", realPart, imagPart);
        my_strcat(buffer_2, buffer2);

        printf("|"); print_with_indent_centered(total_print_space-2, "TWO COMPLEX roots"); printf("|\n"); 
        print_equal_signs(total_print_space);

        printf("|"); print_with_indent_centered(total_print_space-2, buffer_1); printf("|\n");
        printf("|"); print_with_indent_centered(total_print_space-2, buffer_2); printf("|\n");
        print_equal_signs(total_print_space);
    }
}

int my_strlen(char * string) {
    int length = 0;
    while (string[length] != '\0') {
        length++;
    }
    return length;
}

void print_equal_signs(int n) {
    for (int i = 0; i < n; i++) {
        printf("=");
    }
    printf("\n");
}

void my_strcat(char * dest, char * src) {
    int dest_length = my_strlen(dest);
    int src_length = my_strlen(src);
    for (int i = 0; i < src_length; i++) {
        dest[dest_length + i] = src[i];
    }
    dest[dest_length + src_length] = '\0';
}

int digit_counter(int number) {
    int count = 0;
    while (number != 0) {
        number /= 10;
        count++;
    }
    return count;
}

void print_with_indent_centered(int total_print_space, char * string)
{
    int string_length = 0;
    int indent1 = 0, indent2 = 0;
    string_length = my_strlen(string);
    total_print_space -= 2; // account for the two | at the start and end
    if (string_length%2 == 0) {
        indent1 = (total_print_space - string_length) / 2 - 1;
        indent2 = (total_print_space - string_length) / 2 + 1;
    }
    else {
        indent1 = (total_print_space - string_length) / 2;
        indent2 = indent1 + 1;
    }
    printf("|%*s%s%*s|", indent1, "", string, indent2, "");
}
void print_coefficient_indent(int total_print_space, char coefficient_name, double coefficient, int decimal_places){
    float coefficient_float = (float)coefficient;
    char buffer[26];
    int string_length = 0;
    int indent1 = 0, indent2 = 0;
    snprintf(buffer, digit_counter((int)coefficient) + decimal_places + 2, "%lf", coefficient); 
    string_length = my_strlen(buffer) + 4 + 2; // 4 for the coefficient name, 2 for | at start and end
    if (string_length%2 == 0) {
        indent1 = (total_print_space - string_length) / 2 - 1;
        indent2 = (total_print_space - string_length) / 2 + 1;
    }
    else {
        indent1 = (total_print_space - string_length) / 2;
        indent2 = indent1 + 1;
    }
    printf("|%*s%c = %s%*s|", indent1, "", coefficient_name, buffer, indent2, "");
}

int main() {
    char Flag = 'Y';
    while(Flag=='Y' || Flag=='y'){
    system("cls");
    // printf("=============================\n");
    print_equal_signs(total_print_space);
    // printf(*print_with_indent_centered(total_print_space, "Quadratic Equation Solver"));
    printf("|"); print_with_indent_centered(total_print_space-2, "Quadratic Equation Solver"); printf("|\n"); // account for the two | at the start and end
    printf("|"); print_with_indent_centered(total_print_space-2, "ax^2 + bx + c = 0"); printf("|\n"); // account for the two | at the start and end
    print_equal_signs(total_print_space);
    // printf("=============================\n");
    
    
    double a = get_coefficient('a');
    double b = get_coefficient('b');
    double c = get_coefficient('c');
    char concatentated_string[30] = "";
    snprintf(concatentated_string, 30, "%.2lfx^2 + %.2lfx + %.2lf = 0", a, b, c);
    
    // printf("The equation of %.2lfx^2 + %.2lfx + %.2lf = 0 \n", a, b, c);
    print_equal_signs(total_print_space);
    printf("|"); print_with_indent_centered(total_print_space-2, "The equation of"); printf("|\n");
    printf("|"); print_with_indent_centered(total_print_space-2, concatentated_string); printf("|\n");
    print_equal_signs(total_print_space);
    
    printf("|"); 
    print_coefficient_indent(32, 'a', a, 2); 
    print_coefficient_indent(34, 'b', b, 2);
    print_coefficient_indent(32, 'c', c, 2);
    printf("|\n");
    print_equal_signs(total_print_space);

    solve_quadratic(a, b, c);
    printf("Do you want to solve another equation?\n(Input 'Y' or 'y' to continue or type any key to end the program): ");
    scanf(" %c",&Flag);
    }
    
    printf("Program End");
    return 0;
}
