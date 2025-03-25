#include "push_swap.h"
/*	if ac = 2
		split, atoi, check int, check nb arg
	if ac > 2
		ac[i] : atoi, check int, -> stack*/

/*gerer pb atoi ("-" = 0, INT_MIN)*/
t_bool	check_one_arg(char **av, t_stack a)
{
	char	**split;
	int		i;

	split = ft_split(av[1], ' ');
	if (!split)
		return (NULL);
	if (split[0] && !split[1])
		return (false);
	while (split[i])
	{
		// stack.nb = ft_atoi(split[i]);
		// stack.index = i;
	}
}

t_bool	check_args(int ac, char **av, t_stack a)
{
	int	i;

	i = 0;
	while (i++ < ac - 1)
	{
		// stack.nb = ft_atoi(av[i]);
		// stack.index = i - 1;
	}
}

int	main(int ac, char **av)
{
	t_stack	a;

	if (ac == 2)
		check_one_arg(av, a);
	else if (ac > 2)
		check_args(ac, av, a);
}
