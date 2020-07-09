#include "../incs/minirt.h"

int	rt_color_rgbtoi(int red, int green, int blue)
{
	return (65536 * red + 256 * green + blue);
}
