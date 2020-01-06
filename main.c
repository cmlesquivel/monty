#include "monty.h"
extern char *global_node_n[1024];

/**
* input_split - split the string into an array
* @parameters: user's input splitted
* @string: string without split
* @delimitator: character that will act as delimitator
*
* Return: array where
**/

char **input_split(char **parameters, char *string, char *delimitator)
{
char *token;
int i = 0;

token = strtok(string, delimitator);
while (token && i < 2)
{
parameters[i] = token;
token = strtok(NULL, delimitator);
i++;
}
parameters[i] = 0;
return (parameters);
}

/**
 *read_file - function that manage the file to read
* @archivo: file to read
* @array_opcode: options of opcode
* @mi_pila: stack structures type doubly linked list
* Return: nothing
*/

void read_file(FILE *archivo, instruction_t array_opcode[], stack_t *mi_pila)
{
char caracteres[100], *my_parameters[10];
int j;
unsigned int my_line = 0;

while (1)
{
j = 0;

fgets(caracteres, 100, archivo);
if (feof(archivo))
break;

input_split(my_parameters, caracteres, " \n");
my_line++;

while (my_parameters[0] != NULL && array_opcode[j].opcode != NULL)
{
if (strcmp(my_parameters[0], array_opcode[j].opcode) == 0)
{
global_node_n[0] = my_parameters[1];
array_opcode[j].f(&mi_pila, my_line);
break;
}
j++;

if (array_opcode[j].opcode == NULL)
{
fprintf(stderr, "L%d: unknown instruction %s\n", my_line, my_parameters[0]);
exit(EXIT_FAILURE);
}
}
}
}


/**
 *main - function where start the program
* @argc: size the array argv
* @argv: array that contains the command line arguments
* Return: 0 is the compile is satisfactory
*/

int main(int argc, char *argv[])
{
FILE *archivo;
stack_t *mi_pila;

instruction_t array_opcode[] = {
{"push", push_element_stack},
{"pall", print_stack},
{NULL, NULL}
};

mi_pila = NULL;

if (argc == 2)
{
archivo = fopen(argv[1], "r");

if (archivo == NULL)
{
fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
exit(EXIT_FAILURE);
}
else
{
read_file(archivo, array_opcode, mi_pila);
}
fclose(archivo);
}
else
{
fprintf(stderr, "USAGE: monty file\n");
exit(EXIT_FAILURE);
}
return (0);
}
