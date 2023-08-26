#include "monty.h"

/**
 * check_error - Prints error messages according to their error code.
 * @_error: error codes:
 * 1 ~ user doesn't give any file/more than one file to the program.
 * 2 ~ file provided is not a file that can be opened/read.
 * 3 ~ file provided contains an invalid instruction.
 * 4 ~ When program is unable to malloc more memory.
 * 5 ~ When parameter passed to "push" is not int.
 * 6 ~ empty stack for pint.
 * 7 ~ emptystack for pop.
 * 8 ~ When stack is too short for operation.
 */
void check_error(int _error, ...)
{
	va_list args;
	char *opcode;
	int line_num;

	va_start(args, _error);
	switch (_error)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(args, char *));
			break;
		case 3:
			line_num = va_arg(args, int);
			opcode = va_arg(args, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", line_num, opcode);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(args, int));
			break;
		default:
			break;
	}
	node_free();
	exit(EXIT_FAILURE);
}

/**
 * check_more_errors - handles more errors.
 * @_error: error codes:
 * 6 ~ empty stack for pint.
 * 7 ~ empty stack for pop.
 * 8 ~ When stack is too short for operation.
 * 9 ~ Division by 0.
 */
void check_more_errors(int _error, ...)
{
	va_list args;
	char *opcode;
	int line_num;

	va_start(args, _error);
	switch (_error)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(args, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(args, int));
			break;
		case 8:
			line_num = va_arg(args, unsigned int);
			opcode = va_arg(args, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", line_num, opcode);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(args, unsigned int));
			break;
		default:
			break;
	}
	node_free();
	exit(EXIT_FAILURE);
}

/**
 * check_string_errors - handles string errors.
 * @_error: error codes:
 * 10 ~ number inside a node is not in ASCII bounds.
 * 11 ~ empty stack.
 */
void check_string_errors(int _error, ...)
{
	va_list args;
	int line_num;

	va_start(args, _error);
	line_num = va_arg(args, int);
	switch (_error)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", line_num);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", line_num);
			break;
		default:
			break;
	}
	node_free();
	exit(EXIT_FAILURE);
}
