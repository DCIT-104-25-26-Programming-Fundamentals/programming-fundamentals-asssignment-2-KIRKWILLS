// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 9
// =============================================================================
//
// TASK: Console-Based Simple Calculator
//
// Build a calculator program that runs in the console and performs basic
// arithmetic operations based on the user's input.
//
// -----------------------------------------------------------------------------
// OPERATIONS YOUR CALCULATOR MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Addition          ( + )    e.g.  10 + 3  =  13
//   2. Subtraction       ( - )    e.g.  10 - 3  =  7
//   3. Multiplication    ( * )    e.g.  10 * 3  =  30
//   4. Division          ( / )    e.g.  10 / 3  =  3.33
//   5. Modulus           ( % )    e.g.  10 % 3  =  1  (remainder)
//   6. Exponentiation    ( ^ )    e.g.  2 ^ 8   =  256
//   7. Quit
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ============================
//        SIMPLE CALCULATOR
//   ============================
//   1. Addition
//   2. Subtraction
//   3. Multiplication
//   4. Division
//   5. Modulus
//   6. Exponentiation
//   7. Quit
//   Select an operation (1-7):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Select an operation (1-7): 4
//   Enter first number : 10
//   Enter second number: 3
//   Result: 10 / 3 = 3.33
//
//   Select an operation (1-7): 4
//   Enter first number : 5
//   Enter second number: 0
//   Error: Cannot divide by zero.
//
//   Select an operation (1-7): 7
//   Goodbye!
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Each arithmetic operation MUST be written as its own function.
// - Use a loop so the calculator keeps running until the user selects Quit.
// - Division by zero must be caught and handled with a clear error message
//   (do NOT let the program crash).
// - Use fixed and setprecision(2) to display results to 2 decimal places.
// - Handle invalid menu choices gracefully.
// - For exponentiation use a loop or the pow() function from <cmath>.
//

// =============================================================================
// YOUR CODE BELOW
// =============================================================================

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void printMenu() {
    cout << "\n============================\n";
    cout << "     SIMPLE CALCULATOR\n";
    cout << "============================\n";
    cout << "1. Addition\n";
    cout << "2. Subtraction\n";
    cout << "3. Multiplication\n";
    cout << "4. Division\n";
    cout << "5. Modulus\n";
    cout << "6. Exponentiation\n";
    cout << "7. Quit\n";
    cout << "Select an operation (1-7): ";
}

void add() {
    double num1, num2;
    cout << "Enter first number : ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;
    
    double result = num1 + num2;
    cout << "Result: " << num1 << " + " << num2 << " = " << result << endl;
}

void subtract() {
    double num1, num2;
    cout << "Enter first number : ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;
    
    double result = num1 - num2;
    cout << "Result: " << num1 << " - " << num2 << " = " << result << endl;
}

void multiply() {
    double num1, num2;
    cout << "Enter first number : ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;
    
    double result = num1 * num2;
    cout << "Result: " << num1 << " * " << num2 << " = " << result << endl;
}

void divide() {
    double num1, num2;
    cout << "Enter first number : ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;
    
    if (num2 == 0) {
        cout << "Error: Cannot divide by zero." << endl;
    } else {
        double result = num1 / num2;
        cout << "Result: " << num1 << " / " << num2 << " = " 
             << fixed << setprecision(2) << result << endl;
    }
}

void modulus() {
    int num1, num2;
    cout << "Enter first number : ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;
    
    if (num2 == 0) {
        cout << "Error: Cannot perform modulus with zero." << endl;
    } else {
        int result = num1 % num2;
        cout << "Result: " << num1 << " % " << num2 << " = " << result << endl;
    }
}

void exponentiate() {
    double base, exponent;
    cout << "Enter base number      : ";
    cin >> base;
    cout << "Enter exponent (power) : ";
    cin >> exponent;
    
    double result = pow(base, exponent);
    cout << "Result: " << base << " ^ " << exponent << " = " << result << endl;
}

int main() {
    int choice;
    
    cout << "Welcome to Simple Calculator!" << endl;
    
    while (true) {
        printMenu();
        cin >> choice;
        
        switch (choice) {
            case 1:
                add();
                break;
            case 2:
                subtract();
                break;
            case 3:
                multiply();
                break;
            case 4:
                divide();
                break;
            case 5:
                modulus();
                break;
            case 6:
                exponentiate();
                break;
            case 7:
                cout << "Thank you for using the Calculator. Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice! Please select 1-7." << endl;
        }
    }
    
    return 0;
}

