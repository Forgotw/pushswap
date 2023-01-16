#include "push_swap.h"

t_data	*ps_new_data(void)
{
	t_data	*ps_data;

	ps_data = malloc(sizeof (t_data *));
	if (!ps_data)
		return (NULL);
	ps_data->index = 0;
	ps_data->pos = 0;
	ps_data->lena = 0;
	ps_data->lenb = 0;
	ps_data->x = 0;
	ps_data->y = 0;
	ps_data->pile = 0;
	return (ps_data);
}

void	ps_find_data(t_data *ps_data, size_t i, size_t p, char pil)
{
	ps_data->index = i;
	ps_data->pos = p;
	ps_data->pile = 'a';
}