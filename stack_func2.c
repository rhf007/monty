#include "monty.h"

/**
 * nop - Does nothing.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_num: line number of the opcode.
 */
void nop(stack_t **stack, unsigned int line_num)
{
	(void)stack;
	(void)line_num;
}


/**
 * node_swap - Swaps the top two nodes of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_num: line number of of the opcode.
 */
void node_swap(stack_t **stack, unsigned int line_num)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		check_more_errors(8, line_num, "swap");
	temp = (*stack)->next;
	(*stack)->next = temp->next;
	if (temp->next != NULL)
		temp->next->prev = *stack;
	temp->next = *stack;
	(*stack)->prev = temp;
	temp->prev = NULL;
	*stack = temp;
}

/**
 * node_add - Adds the top two nodes of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_num: line number of of the opcode.
 */
void node_add(stack_t **stack, unsigned int line_num)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		check_more_errors(8, line_num, "add");

	(*stack) = (*stack)->next;
	sum = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * node_sub - subtracts the top two nodes of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_num: line number of of the opcode.
 */
void node_sub(stack_t **stack, unsigned int line_num)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		check_more_errors(8, line_num, "sub");


	(*stack) = (*stack)->next;
	sum = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * node_div - divides the top two nodes of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_num: line number of of the opcode.
 */
void node_div(stack_t **stack, unsigned int line_num)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		check_more_errors(8, line_num, "div");

	if ((*stack)->n == 0)
		check_more_errors(9, line_num);
	(*stack) = (*stack)->next;
	sum = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
