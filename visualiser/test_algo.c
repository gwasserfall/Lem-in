#include <lem_in.h>

typedef struct s_frontier
{
	t_room				*room;
	struct s_frontier	*next;
}	t_frontier;


/*
level = {s : 0}
parent = {s : None}

i = 1
frontier = [s]

while frontier:
	next = []
	for u in frontier:

		for v in u.neighbours:

			if v not in level:
				level[v] = i
				parent[v] = u
				next.append(v)

	frontier = next
	i += 1
*/

void append_roomz(t_frontier **front, t_room *room)
{
	t_frontier *cur;
	t_frontier *new;


	cur = *front;

	ft_putstr("Appending Room\n");

	if (!cur)
	{
		ft_putstr("cur does not exist\n");
		*front = malloc(sizeof(t_frontier));
		(*front)->next = NULL;
		(*front)->room = room;
	}
	else
	{
		ft_putstr("cur exists\n");
		while (cur->next)
		{
			cur = cur->next;
			
		}
		ft_putstr("Moving cur");
		new =  malloc(sizeof(t_frontier));
		new->room = room;
		new->next = NULL;
		cur->next = new;
	}
}

bool has_vertices(t_frontier *frontier)
{
	if (frontier)
		return true;
	return false;
}


void	append_frontier(t_frontier **current, t_frontier *next)
{
	t_frontier *cur;

	cur = *current;

	if (!cur)
		*current = next;
	else
	{
		while (cur->next)
			cur = cur->next;
		cur->next = next;
		next->next = NULL;
	}
}

t_frontier *get_neighbours(t_link *links, t_frontier *front)
{
	t_room *room = front->room;
	t_frontier *neighs;
	neighs = NULL;

	if (!ft_strcmp(front->room->name, "two"))
		ft_putstr("asd");

	while (links)
	{
		if (links->from == front->room)
		{
			append_roomz(&neighs, links->to);
		}	
		else if (links->to == front->room)
		{
			append_roomz(&neighs, links->from);
		}
		links = links->next;
	}
	return neighs;
}


int	main()
{
	t_frontier *frontier;
	t_frontier *next;
	t_frontier *neighbour;

	t_link *lone = malloc(sizeof(t_link));
	t_link *ltwo = malloc(sizeof(t_link));
	t_link *lthr = malloc(sizeof(t_link));
	t_link *lfou = malloc(sizeof(t_link));
	t_link *lfiv = malloc(sizeof(t_link));

	lone->next = ltwo;
	ltwo->next = lthr;
	lthr->next = lfou;
	lfou->next = lfiv;
	lfiv->next = NULL;

	t_room *one = malloc(sizeof(t_room));
	t_room *two = malloc(sizeof(t_room));
	t_room *thr = malloc(sizeof(t_room));
	t_room *fou = malloc(sizeof(t_room));
	t_room *fiv = malloc(sizeof(t_room));
	t_room *six = malloc(sizeof(t_room));

	one->next = two;
	one->level = 0;
	one->is_start = true;
	one->name = ft_strdup("one");

	two->next = thr;
	two->level = -1;
	two->name = ft_strdup("two");

	thr->next = fou;
	thr->level = -1;
	thr->name = ft_strdup("thr");

	fou->next = fiv;
	fou->level = -1;
	fou->name = ft_strdup("fou");

	fiv->next = six;
	fiv->level = -1;
	fiv->name = ft_strdup("fiv");

	six->next = NULL;
	six->level = -1;
	six->name = ft_strdup("six");

	lone->from = one;
	lone->to = two;

	ltwo->from = two;
	ltwo->to = thr;
	
	lthr->from = two;
	lthr->to = fou;
	
	lfou->from = fou;
	lfou->to = fiv;
	
	lfiv->from = fiv;
	lfiv->to = six;

	int i = 1;

	frontier = NULL;

	append_roomz(&frontier, one);

	while (has_vertices(frontier))
	{
		next = NULL;
		while (frontier)
		{
			neighbour = get_neighbours(lone, frontier);
			while (neighbour)
			{
				if (neighbour->room->level == -1)
				{
					neighbour->room->level = i;
					neighbour->room->parent = frontier->room;
					append_frontier(&next, neighbour);
				}
				neighbour = neighbour->next;
			}
			frontier = frontier->next;
		}
		i++;
		frontier = next;
	}


	t_room *c = one;

	while (c)
	{
		printf("name : %s ,level %d\n", c->name, c->level);
		c = c->next;
	}



	return 1;
}