#include "monty.h"

extern int global_node_n;

/**
 * printf_integer - print a number
 * @integer: the number to print
 *
 * Return: nothing
*/

/*void print_all_element (){
     printf("su numero es: %d\n", number);
     }*/

void push_element_stack(stack_t **stack, unsigned int line_number){


     stack_t *new_node, *aux;
     
     new_node = malloc(sizeof(stack_t));
     
     if (new_node == NULL)
     {
          exit;
     }
     new_node->n =global_node_n;
     new_node->next =NULL;
     new_node->prev =NULL;

     if (*stack == NULL)
     {
          *stack=new_node;          
     }
     else
     {
       /*   aux = malloc(sizeof(stack_t));
if (aux == NULL)
{
exit;
}*/

aux = *stack;

while (aux->next != NULL)
{
aux = aux->next;
}

aux->next = new_node;
new_node->prev = aux;

     //printf("su numero es: %d\n", line_number);
     }
    // return;
}



void print_all_element(stack_t **stack, unsigned int line_number)
{
	stack_t *aux;
	//size_t size = 0;

	aux = *stack;

	while (aux != NULL)
	{
		printf("%d\n", aux->n);
		aux = aux->next;
		//size++;
	}

	//return;
}
