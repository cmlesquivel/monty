#include "monty.h"

extern char *global_node_n[1024];

/**
 * push_element_stack - pushes an element to the stack.
 * @stack: stack structures type doubly linked list
 * @line_number: line number where the instruction appears.
 * Return: nothing
*/

void push_element_stack(stack_t **stack, unsigned int line_number)
{
stack_t *new_node;
int number, i;

if (global_node_n[0] == NULL)
{
dprintf(2, "L%d: usage: push integer\n", line_number);
free_stack(*stack);
exit(EXIT_FAILURE);
}

for (i = 0; global_node_n[0][i] != '\0'; i++)
{
if (isdigit(global_node_n[0][i]) == 0)
{
dprintf(2, "L%d: usage: push integer\n", line_number);
free_stack(*stack);
exit(EXIT_FAILURE);
}
}
number = atoi(global_node_n[0]);
new_node = malloc(sizeof(stack_t));

if (new_node == NULL)
{
dprintf(2, "Error: malloc failed\n");
free_stack(*stack);
exit(EXIT_FAILURE);
}
new_node->n = number;
new_node->next = NULL;
new_node->prev = NULL;

if (*stack == NULL)
*stack = new_node;
else
{
new_node->next = *stack;
(*stack)->prev = new_node;
*stack = new_node;
}
}


/**
 * print_stack -  prints all values on the stack.
 * @stack: stack structures type doubly linked list
 * @line_number: line number where the instruction appears.
 * Return: nothing
*/

void print_stack(stack_t **stack, unsigned int line_number)
{
stack_t *aux;
aux = *stack;
IGNORE line_number;


if (*stack == NULL)
{
return;
}

while (aux != NULL)
{
printf("%d\n", aux->n);
aux = aux->next;
}

}



/**
 * free_stack -  free a stack structures .
 * @stack: stack structures type doubly linked list
 * Return: nothing
*/
void free_stack(stack_t *stack)
{
if (stack == NULL)
{
return;
}
while (stack->next != NULL)
{
stack = stack->next;
free(stack->prev);
stack->prev = NULL;
}

free(stack);
}



/**
 * printf_top_element -  prints the value at the top of the stack
 * @stack: stack structures type doubly linked list
 * @line_number: line number where the instruction appears.
 * Return: nothing
*/

void printf_top_element(stack_t **stack, unsigned int line_number)
{
stack_t *aux;
aux = *stack;

if (*stack == NULL)
{
dprintf(2, "L%d: can't pint, stack empty\n", line_number);
free_stack(*stack);
exit(EXIT_FAILURE);
}
else
{
printf("%d\n", aux->n);
}
}
