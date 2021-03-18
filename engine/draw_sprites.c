#include "../include/cub3d.h"

static void	drawing_ext(t_info *list, t_sprite *sp, int x_stripe, int x_text)
{
	int clr;
	int y_stripe;
	int y_text;

	if (sp->transformy > 0 && x_stripe > 0 && x_stripe < s->w
		&& sp->transformy < s->zbuffer[x_stripe])
	{
		y_stripe = sp->drawstarty;
		while (y_stripe < sp->drawendy)
		{
			clr = y_stripe * 256 - s->h * 128 + sp->spriteh * 128;
			y_text = ((clr * s->text_sp->height) / sp->spriteh) / 256;
			clr = s->text_sp->data_ptr[s->text_sp->width * y_text + x_text];
			if ((clr & 0x00FFFFFF) != 0)
				s->img->data_ptr[y_stripe * s->img->width + x_stripe] = clr;
			y_stripe++;
		}
	}
}

static void	drawing_sprites(t_info *list, t_sprite *sp)
{
	int		x_text;
	int		x_stripe;

	x_stripe = sp->drawstartx;
	while (x_stripe < sp->drawendx)
	{
		x_text = (int)(256 * (x_stripe - (-sp->spritew / 2 + sp->spritescreenx))
					   * list->sprt_text.width / sp->spritew) / 256;
		if (sp->transformy > 0 && x_stripe > 0 && x_stripe < list->res_x
			&& sp->transformy < list->dist_buff[x_stripe])
		{
			drawing_ext(list, sp, x_stripe, x_text);
		}
		x_stripe++;
	}
}

static void	drawing_computing(t_info *list, t_sprite *sp)
{
	sp->drawstarty = -sp->spriteh / 2 + list->res_y / 2;
	if (sp->drawstarty < 0)
		sp->drawstarty = 0;
	sp->drawendy = sp->spriteh / 2 + list->res_y / 2;
	if (sp->drawendy >= list->res_y)
		sp->drawendy = list->res_y - 1;
	sp->drawstartx = -sp->spritew / 2 + sp->spritescreenx;
	if (sp->drawstartx < 0)
		sp->drawstartx = 0;
	sp->drawendx = sp->spritew / 2 + sp->spritescreenx;
	if (sp->drawendx >= list->res_x)
		sp->drawendx = list->res_x - 1;
}

static void	pre_compute(t_info *list, t_sprite *sp, int i)
{
	double	invdet;
	double	spritex;
	double	spritey;
	double	transformx;

	spritex = list->sprt[i].x - list->posX;
	spritey = list->sprt[i].y - list->posY;
	invdet = 1.0 / (list->planeX * list->dirY - list->dirX * list->planeY);
	transformx = invdet * (list->dirY * spritex - list->dirX * spritey);
	sp->transformy = invdet * (-list->planeY * spritex + list->planeX * spritey);
	sp->spritescreenx = (int)((list->res_x / 2) * (1 + transformx /
			sp->transformy));
	sp->spriteh = abs((int)(list->res_y / (sp->transformy)));
	sp->spritew = abs((int)(list->res_y / (sp->transformy)));
}

void		draw_sprites(t_info *list)
{
	int			i;
	t_sprite 	sprite_values;

	i = 0;
	while (i < list->sprts_number)
	{
		pre_compute(list, &sprite_values, i);
		drawing_computing(s, &sprite_values);
		drawing_sprites(s, &sprite_values);
		i++;
	}
}

