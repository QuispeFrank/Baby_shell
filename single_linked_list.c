#include "main.h"

/**
  * add_node_end - function that adds a new node
  * at the beginning of a list_t list
  * @head: head of the linked list
  * @str: needs to be duplicated
  * Return: the address of the new element, or NULL if it failed
  */

dir_t *add_node_end(dir_t **head, const char *str)
{
	/* creating the last nodo */
	dir_t *last_node = malloc(sizeof(dir_t));
	dir_t *ptr;

	/* validation */
	if (last_node == NULL)
		return (NULL);
	ptr = *head;
	if (*head == NULL)
		*head = last_node;
	else
	{
		/*finding the last Node*/
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = last_node;
	}
	/* adding values to node->path_dir */
	last_node->path_dir = _strdup(str);
	if (last_node->path_dir == NULL)
	{
		free(last_node);
		return (NULL);
	}
	last_node->next = NULL;
	return (last_node);
}


/**
 * print_list - a function that prints all the elements of a list_t list.
 * @h: pointer to first element of the linked list.
 *
 * Return: the number of nodes.
 */
size_t print_list(const dir_t *h)
{
	size_t counter = 0;
	const dir_t *ptr = h;

	for (; ptr != NULL; counter++)
	{
		if (ptr->path_dir == NULL)
			printf("[%d] %s\n", 0, "(nil)");
		else
			printf("%s\n", ptr->path_dir);
		ptr = ptr->next;
	}
	return (counter);
}


/**
 * free_list - Frees a list_t list.
 * @head: A pointer to the list_t list.
 */
void free_list(dir_t *head)
{
	dir_t *tmp;

	while (head)
	{
		tmp = head->next;
		free(head->path_dir);
		free(head);
		head = tmp;
	}
}
