#include "monty.h"


/**
 * stack_add - Adds a node to the stack.
 * @new_node: Pointer to the new node.
 * @line_num: line number of of the opcode.
 */
void stack_add(stack_t **new_node, __attribute__((unused))unsigned int line_num)
{
	stack_t *temp;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	temp = head;
	head = *new_node;
	head->next = temp;
	temp->prev = head;
}


/**
 * stack_print - print stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_num: line number of  the opcode.
 */
void stack_print(stack_t **stack, unsigned int line_num)
{
	stack_t *temp;

	(void) line_num;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	temp = *stack;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * top_pop - pop top node
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_num: line number of the opcode.
 */
void top_pop(stack_t **stack, unsigned int line_num)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
		check_more_errors(7, line_num);

	temp = *stack;
	*stack = temp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(temp);
}

/**
 * top_print - Prints the top node of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_num: line number of of the opcode.
 */
void top_print(stack_t **stack, unsigned int line_num)
{
	if (stack == NULL || *stack == NULL)
		check_more_errors(6, line_num);
	printf("%d\n", (*stack)->n);
}
