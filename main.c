#include "monty.h"

/**
* input_split - split the string into an array
* @argv: user's input splitted
* @string: string without split
* @delimitator: character that will act as delimitator
*
* Return: argv
**/

char **input_split(char **parameters, char *string, char *delimitator)
{
	char *token;
	int i = 0;

	token = strtok(string, delimitator);
	while (token)
	{
		parameters[i++] = token;
		token = strtok(NULL, delimitator);
	}
	parameters[i] = 0;
	return (parameters);
}



int main(int argc, char *argv[])
{
	FILE *archivo;
	char caracteres[100];
	char *my_parameters[10];
	int j = 0;

	stack_t **mi_pila;
	mi_pila = NULL;

	instruction_t array_opcode[] = {
		{"push", push_element_stack},
//		{"pall", print_all_element},
//		{"pint", printf_top_element},
//		{"pop", remove_top_element},
//		{"swap", swap_two_element},
//		{"add", add_two_elements},
//		{"nop",do_not_anything},
		{NULL,NULL}
	};

	if (argc > 1)
	{
		archivo = fopen(argv[1],"r");

		if (archivo == NULL)
		{
			printf("Error lectura");
			exit(1);
		}
		else
		{
			//printf("\nEl contenido del archivo de prueba es \n\n");
			while (feof(archivo) == 0)
			{
				fgets(caracteres,100,archivo);
				//printf("env-->%s<--\n",caracteres);

				input_split(my_parameters, caracteres, " \n");
/*
				while (argv[0] != NULL || argv != NULL )
				{
					if (argv[0] == array_opcode[j].opcode)
					{
						sarray_opcode[j].f(mi_pila ,atoi(argv[1]));
						break;
					}
					j++;
					}*/
			        //printf("--0--%s--\n",my_parameters[0]);
				//printf("--1--%s--\n",my_parameters[1]);

				//printf("--%s--\n",caracteres);
			}
			//system("PAUSE");
		}
		fclose(archivo);
	}
	else
	{
		printf("Error");
	}
}
