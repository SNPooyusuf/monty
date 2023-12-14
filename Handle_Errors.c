#include "monty.h"

/**
 * Errors - Prints appropiate error messages determined by their error code.
 * @error_code: The error codes are the following:
 * (1) -> The user does not give any file or more than one file to the program.
 * (2) -> The file provided is not a file that can be opened or read.
 * (3) -> The file provided contains an invalid instruction.
 * (4) -> When the program is unable to malloc more memory.
 * (5) -> When the parameter passed to the instruction "push" is not an int.
 * (6) -> When the stack it empty for pint.
 * (7) -> When the stack it empty for pop.
 * (8) -> When stack is too short for operation.
 */
void Errors(int error_code, ...)
{
    va_list ag;
    char *optimal;
    int L_Nums;

    va_start(ag, error_code);
    switch (error_code)
    {
    case 1:
        fprintf(stderr, "USAGE: monty file\n");
        break;
    case 2:
        fprintf(stderr, "Error: Can't open file %s\n",
                va_arg(ag, char *));
        break;
    case 3:
        L_Nums = va_arg(ag, int);
        optimal = va_arg(ag, char *);
        fprintf(stderr, "L%d: unknown instruction %s\n", L_Nums, optimal);
        break;
    case 4:
        fprintf(stderr, "Error: malloc failed\n");
        break;
    case 5:
        fprintf(stderr, "L%d: usage: push integer\n", va_arg(ag, int));
        break;
    default:
        break;
    }
    free_nodes();
    exit(EXIT_FAILURE);
}

/**
 * More_Errors - handles errors.
 * @error_code: The error codes are the following:
 * (6) -> When the stack it empty for pint.
 * (7) -> When the stack it empty for pop.
 * (8) -> When stack is too short for operation.
 * (9) -> Division by zero.
 */
void More_Errors(int error_code, ...)
{
    va_list ag;
    char *Optimal;
    int L_Nums;

    va_start(ag, error_code);
    switch (error_code)
    {
    case 6:
        fprintf(stderr, "L%d: can't pint, stack empty\n",
                va_arg(ag, int));
        break;
    case 7:
        fprintf(stderr, "L%d: can't pop an empty stack\n",
                va_arg(ag, int));
        break;
    case 8:
        L_Nums = va_arg(ag, unsigned int);
        Optimal = va_arg(ag, char *);
        fprintf(stderr, "L%d: can't %s, stack too short\n", L_Nums, Optimal);
        break;
    case 9:
        fprintf(stderr, "L%d: division by zero\n",
                va_arg(ag, unsigned int));
        break;
    default:
        break;
    }
    free_nodes();
    exit(EXIT_FAILURE);
}

/**
 * Errors_Strings - handles errors.
 * @error_code: The error codes are the following:
 * (10) -> The number inside a node is outside ASCII bounds.
 * (11) -> The stack is empty.
 */
void Errors_Strings(int error_code, ...)
{
    va_list ag;
    int L_Nums;

    va_start(ag, error_code);
    L_Nums = va_arg(ag, int);
    switch (error_code)
    {
    case 10:
        fprintf(stderr, "L%d: can't pchar, value out of range\n", L_Nums);
        break;
    case 11:
        fprintf(stderr, "L%d: can't pchar, stack empty\n", L_Nums);
        break;
        L_Nums default : break;
    }
    free_nodes();
    exit(EXIT_FAILURE);
}