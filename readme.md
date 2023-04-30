
# MA4830 – Realtime Software for Mechatronic Systems

## Minor Programming Assignment

### 1 December 2022

## Introduction

This assignment focuses on creating a C program to calculate the roots of a quadratic equation, intended for execution on QNX or Windows OS. The program is restricted to sequential execution with standard I/O (keyboard and display).

## Assignment

The program calculates the roots of a quadratic equation using the formula:

`𝑥 = (−𝑏 ± √(𝑏² − 4𝑎𝑐)) / (2𝑎)`

where a, b, and c are the coefficients of the equation: ax² + bx + c = 0.

The program performs the following tasks:

1.  Request the user to enter the coefficients a, b, and c.
2.  Analyze the roots for real and equal, real and different, or complex cases.
3.  Check the correctness of input parameters and prompt for re-entry if necessary.
4.  Display the results, including the type and values of roots, and the quadratic equation.

## Details on required tasks

-   Check the correctness of input parameters
-   Analyze the type of roots of the quadratic equation
-   Display the quadratic equation
-   List the values of the roots
-   Classify the conditions of the roots (real, complex, same, different)

## Elaboration of Requirements

-   Real-time check of data entered via keyboard
-   Check the validity of input values and ensure no missing data
-   Provide help and suggestions for identifying input errors
-   Ensure software robustness
-   Prevent infinite loops or program "hanging"
-   Display output results in a pleasant format, showing data points entered and the required classification of data entered
-   Present the data entered and computed in a neat table or "graphical" format, if possible

## Functions in the code

The code provided includes several functions that are used to accomplish the tasks listed above. These functions include:

-   `get_coefficient(char name)`: Gets a coefficient from the user with error checking
-   `get_discriminant(double a, double b, double c)`: Calculates the discriminant and returns its value
-   `my_sqrt(double x)`: Custom square root function using the Newton-Raphson method
-   `solve_quadratic(double a, double b, double c)`: Solves the quadratic equation and prints the results
-   `print_with_indent_centered(int total_print_space, char *string)`: Prints a string with centered indentation
-   `print_equal_signs(int n)`: Prints a line of equal signs to separate output sections
-   `print_coefficient_indent(int total_print_space, char coefficient_name, double coefficient, int decimal_places)`: Prints the coefficients with centered indentation

## How to use

1.  Compile the program using a C compiler, targeting the appropriate OS (QNX or Windows).
2.  Run the compiled program.
3.  When prompted, enter the coefficients a, b, and c for the quadratic equation.
4.  The program will analyze the input and calculate the roots.
5.  The program will display the quadratic equation, the type and values of the roots, and other relevant information in a tabulated or graphical format.
6.  You can choose to solve another equation by entering 'Y' or 'y', or exit the program by entering any other key.

Please ensure to provide valid input values for the coefficients a, b, and c. The program will help identify errors in the input and provide suggestions if necessary.