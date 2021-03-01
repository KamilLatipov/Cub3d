#include "../include/cub3d.h"

int key_press(int key, t_info *list)
{
	float oldDirX;
	float oldPanelX;
	float rotSpeed;

	rotSpeed = 0.5;
	mlx_clear_window(list->mlx.mlx, list->mlx.win);
	oldDirX = list->plr.dirX;
	list->plr.dirX = list->plr.dirX * cos(-rotSpeeD) -
			list->plr.dirY * sin(-rotSpeed);
	list->plr.dirY = oldDirX * sin(-rotSpeed) +
			list->plr.dirY * cos(-rotSpeed);
	oldPlaneX = list->plr.planeX;
	list->plr.planeX = list->plr.planeX * cos(-rotSpeed) -
			list->plr.planeY * sin(-rotSpeed);
	list->plr.planeY = oldPlaneX * sin(-rotSpeed) +
			list->plr.planeY * cos(-rotSpeed);
	draw_screen(list, list.mlx);
	return (0);
}

void init_window(t_info *list)
{
	t_mlx	mlx;

	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, list->res_x, list->res_y, "Hello world!");
	draw_screen(list, mlx);
	list->mlx = &mlx;
	mlx_key_hook(mlx.win, key_press, list);
	mlx_loop(mlx);
}
