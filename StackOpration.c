#include "monty.h"

/**
 * mul_nodes - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void mul_nodes(stack_t **stack, unsigned int line_number)
{
	int Calc;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		More_Errors(8, line_number, "mul");

	(*stack) = (*stack)->next;
	Calc = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = Calc;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * mod_nodes - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void mod_nodes(stack_t **stack, unsigned int line_number)
{
	int Culc;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		More_Errors(8, line_number, "mod");


	if ((*stack)->n == 0)
		More_Errors(9, line_number);
	(*stack) = (*stack)->next;
	Culc = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = Culc;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
