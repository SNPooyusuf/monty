#include "monty.h"

/**
 * print_str - Prints a string.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @ln: Interger representing the line number of of the opcode.
 */
void print_str(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	int ASCii;
	stack_t *TEMP;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	TEMP = *stack;
	while (TEMP != NULL)
	{
		ASCii = TEMP->n;
		if (ASCii <= 0 || ASCii > 127)
			break;
		printf("%c", ASCii);
		TEMP = TEMP->next;
	}
	printf("\n");
}

/**
 * print_char - Prints the Ascii value.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void print_char(stack_t **stack, unsigned int line_number)
{
	int ASCii;

	if (stack == NULL || *stack == NULL)
		Errors_Strings(11, line_number);

	ASCii = (*stack)->n;
	if (ASCii < 0 || ASCii > 127)
		Errors_Strings(10, line_number);
	printf("%c\n", ASCii);
}

/**
 * rotl - Rotates the first node of the stack to the bottom.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @ln: Interger representing the line number of of the opcode.
 */
void rotl(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *Temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	Temp = *stack;
	while (Temp->next != NULL)
		Temp = Temp->next;

	Temp->next = *stack;
	(*stack)->prev = Temp;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}


/**
 * rotr - Rotates the last node of the stack to the top.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @ln: Interger representing the line number of of the opcode.
 */
void rotr(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *Temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	Temp = *stack;

	while (Temp->next != NULL)
		Temp = Temp->next;

	Temp->next = *stack;
	Temp->prev->next = NULL;
	Temp->prev = NULL;
	(*stack)->prev = Temp;
	(*stack) = Temp;
}
