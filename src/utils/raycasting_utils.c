#include "cub3d.h"

int	ft_color_shadow(int color)
{
	int r = (color >> 16) & 0xFF;
	int g = (color >> 8) & 0xFF;
	int b = color & 0xFF;

	r = (r * 85) >> 7;
	g = (g * 85) >> 7;
	b = (b * 85) >> 7;

	return (r << 16) | (g << 8) | b;
}

