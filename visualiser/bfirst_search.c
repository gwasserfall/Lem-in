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

#include <lem_in.h>

typedef struct			s_frontier
{
	t_room				*room;
	struct s_frontier	*next;
}						t_frontier;

void append_roomz(t_frontier **front, t_room *room)
{
	t_frontier *cur;
	t_frontier *new;

	cur = *front;

	if (!cur)
	{
		*front = malloc(sizeof(t_frontier));
		(*front)->next = NULL;
		(*front)->room = room;
	}
	else
	{
		while (cur->next)
		{
			cur = cur->next;
		}
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


// void	set_levels(t_state *s)
// {
// 	t_frontier *frontier;
// 	t_frontier *next;
// 	t_frontier *neighbour;
// 	int i = 1;

// 	frontier = NULL;

// 	append_roomz(&frontier, s->anthill->start);

// 	while (has_vertices(frontier))
// 	{
// 		next = NULL;
// 		while (frontier)
// 		{
// 			neighbour = get_neighbours(s->anthill->connectors, frontier);
// 			while (neighbour)
// 			{
// 				if (neighbour->room->level == -1)
// 				{
// 					neighbour->room->level = i;
// 					neighbour->room->parent = frontier->room;
// 					append_frontier(&next, neighbour);
// 				}
// 				neighbour = neighbour->next;
// 			}
// 			frontier = frontier->next;
// 		}
// 		i++;
// 		frontier = next;
// 	}
// }

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
	t_link *lsix = malloc(sizeof(t_link));
	t_link *lsev = malloc(sizeof(t_link));
	t_link *leig = malloc(sizeof(t_link));

	lone->next = ltwo;
	ltwo->next = lthr;
	lthr->next = lfou;
	lfou->next = lfiv;
	lfiv->next = lsix;
	lsix->next = lsev;
	lsev->next = leig;

	t_room *one = malloc(sizeof(t_room));
	t_room *two = malloc(sizeof(t_room));
	t_room *thr = malloc(sizeof(t_room));
	t_room *fou = malloc(sizeof(t_room));
	t_room *fiv = malloc(sizeof(t_room));
	t_room *six = malloc(sizeof(t_room));
	t_room *sev = malloc(sizeof(t_room));
	t_room *eig = malloc(sizeof(t_room));
	t_room *nin = malloc(sizeof(t_room));

	one->next = two;
	one->level = 0;
	one->is_start = true;
	one->name = ft_strdup("One");

	two->next = thr;
	two->level = -1;
	two->name = ft_strdup("Two");

	thr->next = fou;
	thr->level = -1;
	thr->name = ft_strdup("Three");

	fou->next = fiv;
	fou->level = -1;
	fou->name = ft_strdup("Four");

	fiv->next = six;
	fiv->level = -1;
	fiv->name = ft_strdup("Five");

	six->next = sev;
	six->level = -1;
	six->name = ft_strdup("Six");

	sev->next = eig;
	sev->level = -1;
	sev->name = ft_strdup("Seven");

	eig->next = nin;
	eig->level = -1;
	eig->name = ft_strdup("Eight");

	nin->next = NULL;
	nin->level = -1;
	nin->name = ft_strdup("Nine");


// 	3
// ##start
// 1 3 15
// 2 10 10
// 3 10 15
// 4 10 20
// 5 20 10
// 6 20 15
// 7 20 20
// 8 30 15
// ##end
// 9 55 15
// 1-2
// 1-3
// 1-4
// 4-5
// 4-6
// 4-7
// 7-8
// 8-9%     



	lone->from = one;
	lone->to = two;

	ltwo->from = one;
	ltwo->to = thr;
	
	lthr->from = one;
	lthr->to = fou;
	
	lfou->from = fou;
	lfou->to = fiv;
	
	lfiv->from = fou;
	lfiv->to = six;

	lsix->from = fou;
	lsix->to = sev;

	lsev->from = sev;
	lsev->to = eig;

	leig->from = eig;
	leig->to = nin;

	int i = 1;

	frontier = NULL;

	append_roomz(&frontier, one);

	while (has_vertices(frontier))
	{
		next = NULL;
		while (frontier)
		{
			printf("Frontier = %s\n", frontier->room->name);
			neighbour = get_neighbours(lone, frontier);
			while (neighbour)
			{
				if (neighbour->room->level == -1)
				{
					neighbour->room->level = i;
					neighbour->room->parent = frontier->room;
					append_frontier(&next, neighbour);
				}
				printf("\tNeighbour = %s [%d]\n", neighbour->room->name, neighbour->room->level);
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