#include "../include/cub3d.h"

void calc_delta(t_info *list, t_calc *calc)
{
	float dirX;
	float dirY;
	float cameraX;
	float rayDirX;
	float rayDirY;

	dirX = list.plr.dirX;
	dirY = list.plr.dirY;
	cameraX = 2*x/list->res_x - 1; //x-coordinate in camera space
	rayDirX = dirX + planeX*cameraX;
	rayDirY = dirY + planeY*cameraX;

	//length of ray from one x or y-side to next x or y-side
	calc.deltaDistX = (rayDirY == 0) ? 0 : ((rayDirX == 0) ? 1 : fabs(1
			/ rayDirX));
	calc.deltaDistY = (rayDirX == 0) ? 0 : ((rayDirY == 0) ? 1 : fabs(1 /
			rayDirY));
	calc.rayDirX = rayDirX;
	calc.rayDirY = rayDirY;
}

void find_side_dist(t_calc *calc)
{
	if (calc.rayDirX < 0)
	{
		calc.stepX = -1;
		calc.sideDistX = (posX - mapX) * calc.deltaDistX;
	}
	else
	{
		calc.stepX = 1;
		calc.sideDistX = (mapX + 1.0 - posX) * calc.deltaDistX;
	}
	if (calc.rayDirY < 0)
	{
		calc.stepY = -1;
		calc.sideDistY = (posY - mapY) * deltaDistY;
	}
	else
	{
		calc.stepY = 1;
		calc.sideDistY = (mapY + 1.0 - posY) * deltaDistY;
	}
}

void find_wall_hit(t_calc *calc)
{
	int hit = 0;
	while (hit == 0)
	{
		//jump to next map square, OR in x-direction, OR in y-direction
		if (calc.sideDistX < calc.sideDistY)
		{
			calc.sideDistX += calc.deltaDistX;
			mapX += calc.stepX;
			calc.side = 0;
		}
		else
		{
			calc.sideDistY += calc.deltaDistY;
			mapY += calc.stepY;
			calc.side = 1;
		}
		if (list->map[mapX][mapY] - 48 > 0)
		{
			hit = 1;
		}
	}
}

float find_perp_dist(t_calc *calc, t_info *list, int mapX,int mapY)
{
	if (calc.side == 0)
		calc.perpWallDist = (float)(mapX - list.plr.posX + (1 - calc.stepX) /
				2) / calc.rayDirX;
	else
		calc.perpWallDist = (float)(mapY - list.plr.posY + (1 - calc.stepY) /
				2) / calc.rayDirY;
}

int find_line_height(t_calc *calc, t_info *list)
{
	calc.lineHeight = (int)(list->res_y / calc.perpWallDist);
	if (calc.perpWallDist == 0)
		calc.lineHeight = list->res_y;lineHeight = list->res_y;
}

void draw_screen(t_info *list, t_mlx *mlx, t_data *img)
{
	int x;
	int mapX;
	int mapY;
	t_calc	calc;
	t_data	img;

	img.img = mlx_new_image(mlx.mlx, list->res_x, list->res_y);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								 &img.endian);
	x = -1;
	while (++x < list->res_x)
	{
		hit = 0;
		mapX = (int)list.plr.posX;
		mapY = (int)list.plr.posY;

		calc_delta(list, &calc);
		find_side_dist(&calc);
		find_wall_hit(&calc);
		calc.perpWallDist = find_perp_dist(&calc, side, mapX, mapY);
		calc.lineHeight = find_line_height(&calc, list);
		int drawStart = -lineHeight / 2 + list->res_y / 2;
		if(drawStart < 0) drawStart = 0;
		int drawEnd = lineHeight / 2 + list->res_y / 2;
		if(drawEnd >= list->res_y) drawEnd = list->res_y - 1;
		int color;
		switch(list->map[mapX][mapY])
		{
			case 1:  color = 0X00FFFF00;  break; //red
			default: color = 0x00FF0000; break; //yellow
		}
		if (side == 1) {color = color / 2;}
		while (drawStart < drawEnd)
		{
			my_mlx_pixel_put(&img, x, drawStart, 0x00FF0000);
			drawStart++;
		}
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_destroy_image(mlx.mlx, img);
}

