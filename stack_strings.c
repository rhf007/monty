#include "monty.h"

/**
 * char_print - Prints character.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_num: line number of of the opcode.
 */
void char_print(stack_t **stack, unsigned int line_num)
{
	int ascii;

	if (stack == NULL || *stack == NULL)
		check_string_errors(11, line_num);

	ascii = (*stack)->n;
	if (ascii < 0 || ascii > 127)
		check_string_errors(10, line_num);
	printf("%c\n", ascii);
}

/**
 * str_print - Prints a string.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_num: line number of of the opcode.
 */
void str_print(stack_t **stack, __attribute__((unused))unsigned int line_num)
{
	int ascii;
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	temp = *stack;
	while (temp != NULL)
	{
		ascii = temp->n;
		if (ascii <= 0 || ascii > 127)
			break;
		printf("%c", ascii);
		temp = temp->next;
	}
	printf("\n");
}

/**
 * rotl - Rotates the first node of the stack to the bottom.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_num: line number of of the opcode.
 */
void rotl(stack_t **stack, __attribute__((unused))unsigned int line_num)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *stack;
	(*stack)->prev = temp;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}


/**
 * rotr - Rotates the last node of the stack to the top.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_num: line number of the opcode.
 */
void rotr(stack_t **stack, __attribute__((unused))unsigned int line_num)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	temp = *stack;

	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *stack;
	temp->prev->next = NULL;
	temp->prev = NULL;
	(*stack)->prev = temp;
	(*stack) = temp;
}
