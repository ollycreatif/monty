#include "main.h"

/**
 * open_f - Opens a file.
 * @file_name: String with the name of the file.
 */
void open_f(char *file_name)
{
	int file_check;
	FILE *fd;

	if (file_name == NULL)
		err_01(2, file_name);

	file_check = access(file_name, R_OK);
	if (file_check == -1)
		err_01(2, file_name);
	fd = fopen(file_name, "r");
	if (fd == NULL)
		err_01(2, file_name);

	read_f(fd);
	fclose(fd);
}

/**
 * read_f - Reads the content of a file line by line.
 * @fd: Pointer to a file descriptor of an open file
 */
void read_f(FILE *fd)
{
	int line_n;
	int format;
	char *lineprt;
	size_t n;

	lineprt = NULL;
	n = 0;
	format = 0;

	if (fd == NULL)
		err_01(2, "file_name");

	for (line_n = 1; getline(&lineprt, &n, fd) != EOF; line_n++)
	{
		format = intprt_line(lineprt, line_n, format);
	}
	free(lineprt);
}


/**
 * intprt_line - Separates each line into tokens to determine
 * which function to call.
 * @lineptr: String representing a line in a file.
 * @line_number: Line number for the opcode.
 * @format: Format specifier. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 * Return: Returns 0 if the opcode is stack. 1 if queue.
 */
int intprt_line(char *lineptr, int line_number, int format)
{
	const char *delim;
	char *opcode;
	char *value;

	if (lineptr == NULL)
		err_01(4);
	delim = "\n ";
	opcode = strtok(lineptr, delim);

	if (opcode == NULL)
		return (format);
	value = strtok(NULL, delim);

	if (strcmp(opcode, "queue") == 0)
		return (1);
	else if (strcmp(opcode, "stack") == 0)
		return (0);

	find_func(opcode, value, line_number, format);
	return (format);
}

/**
 * find_func - Finds the appropite function to run the opcode instructions.
 * @opcode: The operation code, It could be push, pall, ...
 * @value: The possible value for the operation.
 * @ln: Line number for the opcode.
 * @format: Format specifier. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 */
void find_func(char *opcode, char *value, int ln, int format)
{
	int i;
	int flag;

	instruction_t func_list[] = {
		{"push", push_stk},
		{"pall", pall_stk},
		{"pint", pint_top},
		{"pop", pop_stk},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;
	
	for (flag = 1, i = 0; func_list[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, func_list[i].opcode) == 0)
		{
			func_call(func_list[i].f, opcode, value, ln, format);
			flag = 0;
		}
	}
	if (flag == 1)
		err_01(3, ln, opcode);
}

/**
 * func_call - Calls the required function.
 * @f: Pointer to the function that is about to be called.
 * @op: string representing the opcode.
 * @val: string representing a numeric value.
 * @ln: line numeber for the instruction.
 * @format: Format specifier. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 */
void func_call(op_func f, char *op, char *val, int ln, int format)
{
	stack_t *node;
	int flag;
	int i;

	flag = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			flag = -1;
		}

		if (val == NULL)
			err_01(5, ln);
		for (i = 0; val[i] != '\0'; i++)
		{
			if (isdigit(val[i]) == 0)
				err_01(5, ln);
		}
		node = cr8_node(atoi(val) * flag);
		if (format == 0)
			f(&node, ln);
		if (format == 1)
			add_2_queue(&node, ln);
	}
	else
		f(&head, ln);
}
