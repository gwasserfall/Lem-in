#include <visualiser.h>

void	draw_paths(t_state *s)
{
	t_pathlist *list;
	t_path *path;

	int i = 0;
	list = s->paths;

	double x1;
	double x2;
	double y1;
	double y2;

	SDL_SetRenderDrawColor(s->renderer, 0, 255, 0, SDL_ALPHA_OPAQUE);
	while (list)
	{
		path = list->path;
		while (path && path->next)
		{
			x1 = X(s, path->room->x);
			y1 = Y(s, path->room->y);
			x2 = X(s, path->next->room->x);
			y2 = Y(s, path->next->room->y);
			//aalineRGBA(s->renderer, x1, y1, x2, y2, 0, 255, 0, 255);
			SDL_RenderDrawLine(s->renderer, x1, y1, x2, y2);
			path = path->next;
		}
		i++;
		list = list->next;
	}
	char *str = ft_strjoin("Path count : ", ft_itoa(i));
	stringRGBA(s->renderer, 5, 20, str, 255, 255, 255, 255);
	free(str);
}