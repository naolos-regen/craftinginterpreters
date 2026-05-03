#ifndef DOUBLE_LINKED_STR
# define DOUBLE_LINKED_STR

#include <stdlib.h>

typedef struct s_dl t_dl;


t_dl * new_dl(char * /* initial_str */);
t_dl * from_strs_dl(char ** /* data */);

int dl_add(t_dl ** /* first_node */, char * /* str */);
int dl_add_all(t_dl ** /* fist_node */, char ** /* strs */);

char * dl_rem_index(t_dl ** /* first_node */, size_t /* index */);
char * dl_rem_elem (t_dl ** /* first_node */, char * /* str */);

size_t dl_find_elem(t_dl ** /* first_node */, char * /* str */);
char * dl_find_index(t_dl ** /* first_node */, size_t /* index */);

int dl_free(t_dl ** /* first_node */);

#endif
