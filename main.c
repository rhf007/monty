#include "monty.h"
stack_t *head = NULL;

/**
 * main - entry point
 * @argc: arguments count
 * @argv: list of arguments
 * Return: always 0
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file_open(argv[1]);
	node_free();
	return (0);
}

/**
 * node_create - Creates a node.
 * @n: node data.
 * Return: Upon sucess a pointer to the node. Otherwise NULL.
 */
stack_t *node_create(int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		check_error(4);
	node->next = NULL;
	node->prev = NULL;
	node->n = n;
	return (node);
}

/**
 * node_free - Frees nodes in the stack.
 */
void node_free(void)
{
	stack_t *temp;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}


/**
 * queue_add - Adds a node to the queue.
 * @new_node: new node pointer.
 * @line_num: line number of the opcode.
 */
void queue_add(stack_t **new_node, __attribute__((unused))unsigned int line_num)
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
	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *new_node;
	(*new_node)->prev = temp;

}
