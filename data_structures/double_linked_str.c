#include "double_linked_str.h"
#include <stdio.h>
#include <string.h>

struct s_dl {
	struct s_dl *_N_left,
	    *_N_right;
	char* _D_str;
	size_t _M_count;
};

void* x_malloc(size_t size)
{
	void* data;

	data = malloc(size);
	if (!size) {
		perror("not enough memory");
		exit(EXIT_FAILURE);
	}
	return (data);
}

t_dl* new_dl(char* initial_str)
{
	t_dl* data;

	data = x_malloc(sizeof(t_dl));
	if (initial_str) {
		data->_M_count = (1);
		data->_D_str = initial_str;
	};
	data->_N_left = (NULL);
	data->_N_right = (NULL);

	return (data);
};

t_dl* from_strs_dl(char** initial_strings)
{
	t_dl* list = NULL;

	if (!initial_strings)
		return (NULL);

	if (dl_add_all(&list, initial_strings) != 0) {
		dl_free(&list);
	};

	return (list);
};

int dl_add(t_dl** first_node, char* str)
{
	t_dl* node;

	node = new_dl(str);
	if (!node)
		return (1);

	if (*first_node) {
		node->_N_right = *first_node;
		(*first_node)->_N_left = node;
	};
	*first_node = node;
	return (0);
};

int dl_add_all(t_dl** first_node, char** strs)
{
	size_t i;
	int rc;

	rc = 0;
	i = 0;
	while (strs[i])
		if ((rc = dl_add(first_node, strs[i++])) != 0)
			break;
	return (rc);
};

char* dl_rem_index(t_dl** first_node, size_t index)
{
	t_dl* curr;
	size_t i;

	i = 0;
	curr = *first_node;

	while (curr && i < index) {
		curr = curr->_N_right;
		i++;
	};
	if (!curr)
		return (NULL);

	if (curr->_N_left)
		curr->_N_left->_N_right = curr->_N_right;
	else
		*first_node = curr->_N_right;

	if (curr->_N_right)
		curr->_N_right->_N_left = curr->_N_left;

	char* res = curr->_D_str;
	free(curr);
	return (res);
};

char* dl_rem_elem(t_dl** first_node, char* str)
{
	t_dl* curr;

	curr = *first_node;

	while (curr) {
		if (strcmp(curr->_D_str, str) == 0)
			break;
	};
	if (!curr)
		return (NULL);

	if (curr->_N_left)
		curr->_N_left->_N_right = curr->_N_right;
	else
		*first_node = curr->_N_right;

	if (curr->_N_right)
		curr->_N_right->_N_left = curr->_N_left;

	char* res = curr->_D_str;
	free(curr);
	return (res);

	return (NULL);
};

size_t
dl_find_elem(t_dl** first_node, char* str)
{
	t_dl* curr;
	size_t index;

	curr = *first_node;
	index = 0;
	while (curr) {
		if (strcmp(curr->_D_str, str) == 0)
			return (index);
		curr = curr->_N_right;
		index++;
	};

	return (-1);
};

char* dl_find_index(t_dl** first_node, size_t index)
{
	t_dl* curr;
	size_t i;

	i = 0;
	curr = *first_node;
	while (curr && i < index) {
		curr = curr->_N_right;
		i++;
	};
	return (curr ? curr->_D_str : (NULL));
};

int dl_free(t_dl** first_node)
{
	t_dl* current;
	t_dl* next;

	if (!first_node || !*first_node)
		return (1);

	current = *first_node;
	while (current) {
		next = current->_N_right;

		if (current->_D_str)
			free(current->_D_str);

		free(current);
		current = next;
	};

	*first_node = (NULL);
	return (0);
};
