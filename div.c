#include "monty.h"

/**
 *div - divide the second top element
 *@stack: double pointer that point to the head of stack
 *@line_number: the number of the line in file
 *
 */
void div(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	int result;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		printf("L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp = *stack;

	if (tmp->n == 0) 
	{
		printf("L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	result = tmp->next->n / tmp->n;
	tmp->next->n = result;

	*stack = tmp->next;

	free(tmp);
}

