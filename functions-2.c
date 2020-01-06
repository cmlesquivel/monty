#include "monty.h"

extern char *global_node_n[1024];


/**
 * remove_top_element -  removes the top element of the stack
 * @stack: stack structures type doubly linked list
 * @line_number: line number where the instruction appears.
 * Return: nothing
*/

void remove_top_element(stack_t **stack, unsigned int line_number)
{
stack_t *aux;
aux = *stack;

if (*stack == NULL)
{
dprintf(2, "L%d: can't pop stack empty\n", line_number);
exit(EXIT_FAILURE);
}

(aux->next)->prev = NULL;
*stack = aux->next;
free(aux);
}


/**
 * swap_two_element -  removes the top element of the stack
 * @stack: stack structures type doubly linked list
 * @line_number: line number where the instruction appears.
 * Return: nothing
*/

void swap_two_element(stack_t **stack, unsigned int line_number)
{
stack_t *aux, *aux2;
aux = *stack;
aux2 = aux->next;
int lont = 0;

while (aux != NULL)
{     aux = aux->next;
lont++;
}

if (lont < 3)
{
dprintf(2, "L%d: can't pop stack empty\n", line_number);
exit(EXIT_FAILURE);
}

aux->next = aux2->next;
aux->prev = aux2;

aux2->prev = NULL;
aux2->next = aux2;

*stack = aux2;

}



