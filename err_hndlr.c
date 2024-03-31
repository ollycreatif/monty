#include "main.h"

/**
 * err_01 - prints the appropriate error messages for a particular error type
 * @error_code: the error codes
 */
void err_01(int error_code, ...)
{
	va_list argmt;
	char *op;
	int l_num;

	va_start(argmt, error_code);
	switch (error_code)
	{
		case 1:
			printf("USAGE: monty file\n");
			break;
		case 2:
			printf("Error: Can't open file %s\n",
				va_arg(argmt, char *));
			break;
		case 3:
			l_num = va_arg(argmt, int);
			op = va_arg(argmt, char *);
			printf("L%d: unknown instruction %s\n", l_num, op);
			break;
		case 4:
			printf("Error: malloc failed\n");
			break;
		case 5:
			printf("L%d: usage: push integer\n", va_arg(argmt, int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * err_02 - handles a few more errors
 * @error_code: the error codes
 */
void err_02(int error_code, ...)
{
	va_list argmt;
	char *op;
	int l_num;

	va_start(argmt, error_code);
	switch (error_code)
	{
		case 6:
			printf("L%d: can't pint, stack empty\n",
				va_arg(argmt, int));
			break;
		case 7:
			printf("L%d: can't pop an empty stack\n",
				va_arg(argmt, int));
			break;
		case 8:
			l_num = va_arg(argmt, unsigned int);
			op = va_arg(argmt, char *);
			printf("L%d: can't %s, stack too short\n", l_num, op);
			break;
		case 9:
			printf("L%d: division by zero\n",
				va_arg(argmt, unsigned int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}
