#include "monty.h"
stack_t *head = NULL;

/**
 * main - Entry point
 * @argc: Arguments count
 * @argv: List of arguments
 * Return: Always 0
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	open_file(argv[1]);
	free_nodes();
	return (0);
}

/**
 * add_to_queue - Adds a node to the queue.
 * @new_node: Pointer to the new node.
 * @ln: Line number of the opcode (unused).
 */
void add_to_queue(stack_t **new_node, __attribute__((unused)) unsigned int ln)
{
	stack_t *Temp;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);

	if (head == NULL)
	{
		head = *new_node;
		return;
	}

	Temp = head;
	while (Temp->next != NULL)
		Temp = Temp->next;

	Temp->next = *new_node;
	(*new_node)->prev = Temp;
}

/**
 * free_nodes - Frees nodes in the stack.
 */
void free_nodes(void)
{
	stack_t *Temp;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		Temp = head;
		head = head->next;
		free(Temp);
	}
}

/**
 * create_node - Creates a node.
 * @n: Number to go inside the node.
 * Return: Upon success, a pointer to the node. Otherwise NULL.
 */
stack_t *create_node(int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		Errors(4);

	node->next = NULL;
	node->prev = NULL;
	node->n = n;

	return (node);
}
