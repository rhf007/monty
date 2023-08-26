#include "monty.h"

/**
 * file_open - opens a file
 * @filename: file namepath
 */

void file_open(char *filename)
{
	FILE *fd = fopen(filename, "r");

	if (filename == NULL || fd == NULL)
		check_error(2, filename);

	file_read(fd);
	fclose(fd);
}


/**
 * file_read - reads a file
 * @fd: pointer to file descriptor
 */

void file_read(FILE *fd)
{
	int line_num, format = 0;
	char *buff = NULL;
	size_t length = 0;

	for (line_num = 1; getline(&buff, &length, fd) != -1; line_num++)
	{
		format = line_parse(buff, line_num, format);
	}
	free(buff);
}


/**
 * line_parse - tokenize line to determine function
 * @buff: line from the file
 * @line_num: line number
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 * if 1 node will be entered as a queue.
 * Return: Returns 0 if the opcode is stack. 1 if queue.
 */

int line_parse(char *buff, int line_num, int format)
{
	char *opcode, *val;
	const char *delimiter = "\n ";

	if (buff == NULL)
		check_error(4);

	opcode = strtok(buff, delimiter);
	if (opcode == NULL)
		return (format);
	val = strtok(NULL, delimiter);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	find_function(opcode, val, line_num, format);
	return (format);
}

/**
 * find_function - find function according to opcode
 * @opcode: opcode
 * @val: opcode argument
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 * @line_num: line number
 * if 1 nodes will be entered as a queue.
 */
void find_function(char *opcode, char *val, int line_num, int format)
{
	int i;
	int flag;

	instruction_t function_list[] = {
		{"push", stack_add},
		{"pall", stack_print},
		{"pint", top_print},
		{"pop", top_pop},
		{"nop", nop},
		{"swap", node_swap},
		{"add", node_add},
		{"sub", node_sub},
		{"div", node_div},
		{"mul", node_mul},
		{"mod", node_mod},
		{"pchar", char_print},
		{"pstr", str_print},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (flag = 1, i = 0; function_list[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, function_list[i].opcode) == 0)
		{
			call_function(function_list[i].f, opcode, val, line_num, format);
			flag = 0;
		}
	}
	if (flag == 1)
		check_error(3, line_num, opcode);
}


/**
 * call_function - function call.
 * @function: function pointer.
 * @opcode: string representing the opcode.
 * @val: string representing a numeric value.
 * @line_num: line number for the instruction.
 * @format: Format specifier. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 */
void call_function(op_func function, char *opcode, char *val, int line_num, int format)
{
	stack_t *node;
	int flag;
	int i;

	flag = 1;
	if (strcmp(opcode, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			flag = -1;
		}
		if (val == NULL)
			check_error(5, line_num);
		for (i = 0; val[i] != '\0'; i++)
		{
			if (isdigit(val[i]) == 0)
				check_error(5, line_num);
		}
		node = node_create(atoi(val) * flag);
		if (format == 0)
			function(&node, line_num);
		if (format == 1)
			queue_add(&node, line_num);
	}
	else
		function(&head, line_num);
}
