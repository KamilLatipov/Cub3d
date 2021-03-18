#include "../include/cub3d.h"

static void calc_delta(t_info *list, int x)
{
	float dirX;
	float dirY;
	float cameraX;
	float rayDirX;
	float rayDirY;

	dirX = list->dirX;
	dirY = list->dirY;
	cameraX = 2*x/(float)list->res_x - 1;
	rayDirX = dirX + list->planeX*cameraX;
	rayDirY = dirY + list->planeY*cameraX;

	list->deltaDistX = (rayDirY == 0) ? 0 : ((rayDirX == 0) ? 1 : fabs(1 / rayDirX));
	list->deltaDistY = (rayDirX == 0) ? 0 : ((rayDirY == 0) ? 1 : fabs(1 / rayDirY));
	list->rayDirX = rayDirX;
	list->rayDirY = rayDirY;
}

static void find_side_dist(t_info *list, int mapX, int mapY)
{
	if (list->rayDirX < 0)
	{
		list->stepX = -1;
		list->sideDistX = (list->posX - mapX) * list->deltaDistX;
	}
	else
	{
		list->stepX = 1;
		list->sideDistX = (mapX + 1.0 - list->posX) * list->deltaDistX;
	}
	if (list->rayDirY < 0)
	{
		list->stepY = -1;
		list->sideDistY = (list->posY - mapY) * list->deltaDistY;
	}
	else
	{
		list->stepY = 1;
		list->sideDistY = (mapY + 1.0 - list->posY) * list->deltaDistY;
	}
}

void find_wall_hit(t_info *list, int *mapX, int *mapY)
{
	int hit = 0;
	while (hit == 0)
	{
		if (list->sideDistX < list->sideDistY)
		{
			list->sideDistX += list->deltaDistX;
			*mapX += list->stepX;
			list->side = 0;
		}
		else
		{
			list->sideDistY += list->deltaDistY;
			*mapY += list->stepY;
			list->side = 1;
		}
		if (list->map[*mapX][*mapY] == '1')
		{
			hit = 1;
		}
	}
}

static void find_perp_dist(t_info *list, int mapX,int mapY)
{
	if (list->side == 0)
    {
		list->perpWallDist = (float)(mapX - list->posX + (1 - list->stepX) /
				2) / list->rayDirX;
    }
	else
    {
		list->perpWallDist = (float)(mapY - list->posY + (1 - list->stepY) /
				2) / list->rayDirY;
    }
}

static void find_line_height(t_info *list)
{
	list->lineHeight = (list->res_y / list->perpWallDist);
	if (list->perpWallDist == 0)
		list->lineHeight = list->res_y;
}

static unsigned int choose_tex(t_info *list, int texX, int texY)
{
    if (!list->side)
    {
        if (list->stepX == 1)
            return (my_mlx_pixel_take(&list->s, texX, texY));
        else if (list->stepX == -1)
            return (my_mlx_pixel_take(&list->n, texX, texY));
    }
    else
    {
        if (list->stepY == -1)
            return (my_mlx_pixel_take(&list->e, texX, texY));
        else if (list->stepY == 1)
         return (my_mlx_pixel_take(&list->w, texX, texY));
    }
    return (0);
}

void draw_screen(t_info *list, t_mlx *mlx)
{
	int x;
	int mapX;
	int mapY;
	t_data	img;
    int hit;
    float drawStart;

	img.img = mlx_new_image(mlx->mlx, list->res_x, list->res_y);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								 &img.endian);
	x = -1;
	while (++x < list->res_x)
	{
		hit = 0;
		mapX = (int)list->posX;
		mapY = (int)list->posY;

		calc_delta(list, x);
		find_side_dist(list, mapX, mapY);
		find_wall_hit(list, &mapX, &mapY);
		find_perp_dist(list, mapX, mapY);
		find_line_height(list);
		drawStart = -list->lineHeight / 2 + list->res_y / 2;
		if(drawStart < 0) drawStart = 0;
		float drawEnd = list->lineHeight / 2 + list->res_y / 2;
		if(drawEnd >= list->res_y) drawEnd = list->res_y - 1;
		double wallX;
        if (list->side == 0) wallX = list->posY + list->perpWallDist * list->rayDirY;
        else           wallX = list->posX + list->perpWallDist * list->rayDirX;
        wallX -= floor((wallX));
        int texX = (int)(wallX * (double)list->n.width);
        if(list->side == 0 && list->rayDirX > 0) texX = list->n.width - texX - 1;
        if(list->side == 1 && list->rayDirY < 0) texX = list->n.width - texX - 1;
        double step = 1.0 * (list->n.width / list->lineHeight);
        double texPos = (drawStart - list->res_y / 2 + list->lineHeight / 2) * step;

        int k = 0;
        while (k++ < drawStart)
        	my_mlx_pixel_put(&img, x, k, 0x00FFFFFF);
        k = list->lineHeight;
        while (k-- > drawEnd)
        	my_mlx_pixel_put(&img, x, k, 0x0FFFF00);
		while (drawStart < drawEnd)
		{
            int texY = (int)texPos & (list->n.width - 1);
            unsigned int color = choose_tex(list, texX ,texY);
            texPos += step;
            
			my_mlx_pixel_put(&img, x, drawStart, color);
			drawStart++;
		}
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, img.img, 0, 0);
	mlx_destroy_image(mlx->mlx, img.img);
}

