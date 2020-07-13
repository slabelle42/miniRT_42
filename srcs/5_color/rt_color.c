#include "../incs/minirt.h"

int	rt_color_rgbtoi(int R, int G, int B)
{
	return (65536 * R + 256 * G + B);
}
