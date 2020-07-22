#include "minirt.h"

int		rt_keys_exit()
{
	exit(0);
	return (0);
}

int		rt_keys(int key)
{
	if (key == 65307 || key == 53)
		return (rt_keys_exit());
	return (0);
}
