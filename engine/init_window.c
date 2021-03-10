#include "../include/cub3d.h"

int key_press(int key, t_info *list)
{
	float oldDirX;
	float oldPlaneX;
	float rotSpeed;
    float moveSpeed;

    moveSpeed = 0.2;
    rotSpeed = 0.05;
    if (key == 13)
    {
        mlx_clear_window(list->mlx->mlx, list->mlx->win);
        if(list->map[(int)(list->posX + list->dirX * moveSpeed)][(int)list->posY] != '1')
            list->posX += list->dirX * moveSpeed;
        if(list->map[(int)list->posX][(int)(list->posY + list->dirY * moveSpeed)] != '1') list->posY += list->dirY * moveSpeed;
    }
    else if (key == 1)
    {
        mlx_clear_window(list->mlx->mlx, list->mlx->win);
        if(list->map[(int)(list->posX - list->dirX * moveSpeed)][(int)list->posY] != '1') list->posX -= list->dirX * moveSpeed;
        if(list->map[(int)list->posX][(int)(list->posY - list->dirY * moveSpeed)] != '1') list->posY -= list->dirY * moveSpeed;
    }
    else if (key == 124)
    {
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
    }
    else if (key == 123)
    {
        mlx_clear_window(list->mlx->mlx, list->mlx->win);
	    oldDirX = list->dirX;
	    list->dirX = list->dirX * cos(rotSpeed) - list->dirY * sin(rotSpeed);
	    list->dirY = oldDirX * sin(rotSpeed) +
			list->dirY * cos(rotSpeed);
	    oldPlaneX = list->planeX;
	    list->planeX = list->planeX * cos(rotSpeed) -
			list->planeY * sin(rotSpeed);
	    list->planeY = oldPlaneX * sin(rotSpeed) +
			list->planeY * cos(rotSpeed); 
    }
	draw_screen(list, list->mlx);
	return (0);
}
