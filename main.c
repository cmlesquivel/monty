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
		parameters[i] = token;
		token = strtok(NULL, delimitator);
		i++;
	}
	parameters[i] = 0;
	return (parameters);
}



int main(int argc, char *argv[])
{
	FILE *archivo;
	char caracteres[100];
	char *my_parameters[10];
	int j;
	unsigned int my_line = 0;
	extern int global_node_n;

	stack_t *mi_pila;
	mi_pila = NULL;

	instruction_t array_opcode[] = {
		{"push", push_element_stack},
		{"pall", print_all_element},
//		{"pint", printf_top_element},
//		{"pop", remove_top_element},
//		{"swap", swap_two_element},
//		{"add", add_two_elements},
//		{"nop",do_not_anything},
		{NULL,NULL}
	};



	if ( argc == 2)
	{
		archivo = fopen(argv[1],"r");

		if (archivo == NULL)
		{
			printf("Error: Can't open file %s\n",argv[1]);
			exit(EXIT_FAILURE);
		}
		else
		{
			
			while(1)
			{
				j = 0;
				
				fgets(caracteres,100,archivo);
				if (feof(archivo))
                break;

				input_split(my_parameters, caracteres, " \n");
				my_line++;

				while (my_parameters[0] != NULL && array_opcode[j].opcode != NULL )
				{
					
					

					
					if ( strcmp (my_parameters[0], array_opcode[j].opcode)==0)
					{
				
						if(my_parameters[1] !=NULL)
						global_node_n = atoi(my_parameters[1]);
						else
						{
							//global_node_n=NULL;
						}
						
						//printf("global_node_n %d\n",global_node_n);
						array_opcode[j].f(&mi_pila ,my_line);
						

						break;
					}
					j++;

					if (array_opcode[j].opcode == NULL)
					{
						printf("L%d: unknown instruction %s\n",my_line,my_parameters[0]);
						exit(EXIT_FAILURE);
					}
					
					
				}
			        
			}
		}
		fclose(archivo);
	}
	else
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
}
