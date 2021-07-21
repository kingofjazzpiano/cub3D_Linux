#include "main.h"

// Рисует в image карты, но белый не перезаписывает / для игрока
void	my_mlx_pixel_put(t_all *all, t_pnt point, int color)
{
	unsigned int	*dst;

	if ((int)point.x < 0 || (int)point.y < 0
		|| (int)point.x >= all->win.width || (int)point.y >= all->win.height)
		return ;
	dst = calculate_address(all, point.x, point.y);
	if (WHITE == *dst)
		return ;
	*dst = color;
}

// Проверяет в image карты / для игрока
unsigned int	*calculate_address(t_all *all, int x, int y)
{
	return (all -> win.addr
		+ (y * all -> win.line_length + x * CHARS_PER_PIXEL));
}

// Рисует в temp image 
void	my_mlx_pixel_put2(t_all *all, t_pnt point, int color)
{
	unsigned int	*dst;

	if (point.x < 0 || point.y < 0
		|| point.x >= all->win.width || point.y >= all->win.height)
		return ;
	dst = calculate_address2(all, point.x, point.y);
	*dst = color;
}

// Рисует в temp image
unsigned int	*calculate_address2(t_all *all, int x, int y)
{
	return (all -> win.addr2
		+ (y * all -> win.line_length + x * CHARS_PER_PIXEL));
}
