#include "minirt.h"

int		rt_exit_ok()
{
	ft_putendl_fd("Thanks for trying MiniRT :D", 1);
	exit(0);
	return (0);
}

void	rt_exit_ko(int error_nb)
{
	if (error_nb == 1)
		ft_putendl_fd("Error 1 : missing argument :'( I need a file name", 1);	
	else if (error_nb == 2)
		ft_putendl_fd("Error 2 : wrong file name :'( I can't find it", 1);		
	else if (error_nb == 3)
		ft_putendl_fd("Error 3 : wrong parameter :'(", 1);
	else if (error_nb == 42)
		ft_putendl_fd(
			"Error 42 : technical issue, oops o_O Did we break something?", 1);
	exit(-1);
}

int		rt_keys(int key)
{
	if (key == 65307 || key == 53)
		return (rt_exit_ok());
	return (0);
}
