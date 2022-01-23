#include "includes/minishell.h"
#define __env t_env
void	free_list(__env *head)
{
	__env *i;
	__env *to_free;

	while (head)
	{
		to_free = head;
		head = head->next;
		free(to_free);
	}

}

int	main(int argc, char **argv, char **envp)
{
	t_env_list *my_list;

	__env *list = NULL;
	my_list->head = list;

	my_list = malloc(sizeof(t_env_list));
	add_var_to_env(my_list, envp);

	return (0);
}
