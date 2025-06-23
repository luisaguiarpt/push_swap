#include "push_swap.h"

static int	*values_array(t_core *core, int size);
static void	sort_array(int *array, int size);

void	init_stack_a(t_core *core, char **char_arr)
{
	int	i;

	i = 0;
	while (char_arr[i])
	{
		lstadd_back(core->a, lst_new(ft_atoi(char_arr[i])));
		i++;
	}
	core->size = lst_size(core->a);
	core->sorted_array = values_array(core, core->size);
	sort_array(core->sorted_array, core->size);
	assign_index(core);
}

static int	*values_array(t_core *core, int size)
{
	int		*array;
	int		i;
	t_stack	*lst;

	array = ft_calloc(size, sizeof(int));
	if (!array)
		return (NULL);
	lst = *core->a;
	i = 0;
	while (lst)
	{
		array[i] = lst->value;
		lst = lst->next;
		i++;
	}
	return (array);
}

static void	sort_array(int *array, int size)
{
	int	i;
	int	tmp;
	int	flag;

	flag = 1;
	while (flag)
	{
		flag = 0;
		i = 0;
		while (i < size - 1)
		{
			if (array[i] > array[i + 1])
			{
				tmp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = tmp;
				flag = 1;
			}
			i++;
		}
	}
}
