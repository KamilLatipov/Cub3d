#include "../include/cub3d.h"

int key_press(int key, t_info *list)
{
	float oldDirX;
	float oldPlaneX;
	float rotSpeed;

	rotSpeed = 0.2;
    key = 0;
	mlx_clear_window(list->mlx->mlx, list->mlx->win);
	oldDirX = list->dirX;
	list->dirX = list->dirX * cos(-rotSpeed) - list->dirY * sin(-rotSpeed);
	list->dirY = oldDirX * sin(-rotSpeed) +
			list->dirY * cos(-rotSpeed);
	oldPlaneX = list->planeX;
	list->planeX = list->planeX * cos(-rotSpeed) -
			list->planeY * sin(-rotSpeed);
	list->planeY = oldPlaneX * sin(-rotSpeed) +
			list->planeY * cos(-rotSpeed);
	draw_screen(list, list->mlx);
	return (0);
}
