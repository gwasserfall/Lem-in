#include <lem_in.h>

#define ANT_COUNT 1
#define IDENT 2
#define ROOM 3
#define LINK 4
#define COMMENT 5
#define INVLD 6
#define MOVE 7
#define EMPTY 8

// http://pythontutor.com/c.html#code=%23include%20%3Cstdlib.h%3E%0A%0Atypedef%20struct%20%20s_room%0A%7B%0A%20%20struct%20s_room%20**links%3B%0A%20%20int%20%20%20%20%20%20%20%20%20%20%20count%3B%0A%20%20int%20%20%20%20%20%20%20%20%20%20%20end%3B%0A%20%20struct%20s_room%20*next%3B%0A%7D%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20t_room%3B%0A%0Atypedef%20struct%20%20s_hill%0A%7B%0A%20%20t_room%20%20%20%20%20%20%20%20*start%3B%0A%7D%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20t_hill%3B%0A%0A%0At_room%20*new%28%29%0A%7B%0A%20%20t_room%20*n%20%3D%20malloc%28sizeof%28t_room%29%29%3B%0A%0A%20%20n-%3Ecount%20%3D%200%3B%0A%20%20n-%3Enext%20%3D%20NULL%3B%0A%20%20n-%3Eend%20%3D%200%3B%0A%20%20n-%3Elinks%20%3D%20malloc%28sizeof%28t_room%20*%29%20*%205%29%3B%0A%20%20return%20n%3B%0A%7D%0A%0Atypedef%20struct%20%20s_path%0A%7B%0A%20%20struct%20s_path%20*next%3B%0A%20%20t_room%20%20%20%20%20%20%20%20*room%3B%0A%7D%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20t_path%3B%0A%0Aint%20visited%28t_path%20*path,%20t_room%20*room%29%0A%7B%0A%20%20while%20%28path%29%0A%20%20%7B%0A%20%20%20%20if%20%28path-%3Eroom%20%3D%3D%20room%29%0A%20%20%20%20%20%20return%201%3B%0A%20%20%20%20path%20%3D%20path-%3Enext%3B%20%20%0A%20%20%7D%0A%20%20return%200%3B%0A%7D%0A%0Avoid%20link%28t_room%20*from,%20t_room%20*to%29%0A%7B%0A%20%20from-%3Elinks%5Bfrom-%3Ecount%5D%20%3D%20to%3B%0A%20%20from-%3Ecount%2B%2B%3B%0A%7D%0A%0Avoid%20append%28t_path%20*main,%20t_path%20*elem%29%0A%7B%0A%20%20while%20%28main-%3Enext%29%0A%20%20%20%20main%20%3D%20main-%3Enext%3B%0A%20%20main-%3Enext%20%3D%20elem%3B%0A%7D%0A%0Avoid%20traverse%28t_path%20*path,%20t_room%20*from,%20t_room%20*to,%20int%20room%29%0A%7B%0A%20%20t_path%20*next%20%3D%20malloc%28sizeof%28t_path%29%29%3B%0A%20%20%0A%20%20if%20%28to-%3Eend%29%0A%20%20%7B%0A%20%20%20%20next-%3Eroom%20%3D%20to%3B%0A%20%20%20%20append%28path,%20next%29%3B%0A%20%20%20%20return%20%3B%0A%20%20%7D%0A%20%20if%20%28room%20%3E%3D%20to-%3Ecount%29%0A%20%20%7B%0A%20%20%20%20return%20%3B%0A%20%20%7D%0A%20%20%0A%20%20next-%3Eroom%20%3D%20to%3B%0A%20%20append%28path,%20next%29%3B%0A%20%20%0A%20%20%0A%20%20traverse%28path,%20to,%20to-%3Elinks%5Broom%5D,%20room%20%2B%201%29%3B%0A%7D%0A%0A%0Aint%20main%28%29%20%7B%0A%0A%20%20t_hill%20*hill%20%3D%20malloc%28sizeof%28t_hill%29%29%3B%0A%20%20t_room%20*start%20%3D%20new%28%29%3B%0A%20%20t_room%20*one%20%3D%20new%28%29%3B%0A%20%20t_room%20*two%20%3D%20new%28%29%3B%0A%20%20t_room%20*three%20%3D%20new%28%29%3B%0A%20%20t_room%20*four%20%3D%20new%28%29%3B%0A%20%20t_room%20*five%20%3D%20new%28%29%3B%0A%20%20t_room%20*six%20%3D%20new%28%29%3B%0A%20%20t_room%20*end%20%3D%20new%28%29%3B%0A%20%20t_path%20*path%20%3D%20malloc%28sizeof%28t_path%29%29%3B%0A%20%20end-%3Eend%20%3D%201%3B%0A%0A%20%20link%28start,%20one%29%3B%0A%20%20%0A%20%20link%28one,%20two%29%3B%0A%20%20link%28two,%20three%29%3B%0A%20%20link%28two,%20four%29%3B%0A%20%20link%28four,%20five%29%3B%0A%20%20link%28five,%20six%29%3B%0A%20%20%0A%20%20link%28six,%20end%29%3B%0A%20%20%0A%20%20path-%3Enext%20%3D%20NULL%3B%0A%20%20path-%3Eroom%20%3D%20start%3B%0A%20%20traverse%28path,%20start,%20start-%3Elinks%5B0%5D,%200%29%3B%0A%0A%0A%20%20return%200%3B%0A%7D&curInstr=127&mode=display&origin=opt-frontend.js&py=c&rawInputLstJSON=%5B%5D

t_anthill	*init_anthill(void)
{
	t_anthill	*anthill;

	if (!(anthill = malloc(sizeof(t_anthill))))
		return false;
	anthill->room_count = 0;
	anthill->linear = NULL;
	anthill->colony = NULL;
	anthill->start = NULL;
	anthill->nb_ants = 0;
	anthill->connectors = NULL;
	anthill->end = NULL;
	return (anthill);
}

void	append_room(t_room *entry_point, t_room *new)
{
	t_room		*current;

	current = entry_point;
	while (current->next)
		current = current->next;
	current->next = new;
}

t_room	*init_room_g(char *name, int x, int y)
{
	t_room *new;

	if (!(new = (t_room *)malloc(sizeof(t_room))))
		return (NULL);
	new->next = NULL;
	new->link_count = 0;
	new->name = ft_strdup(name);
	new->is_end = 0;
	new->is_start = 0;
	new->x = x;
	new->y = y;
	new->links = NULL;
	return (new);
}

bool int_string(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (false);
		str++;
	}
	return (true);
}

int	identify_line(char *line)
{
	int line_length;
	line_length = ft_strlen(line);

	if (line_length < 1)
		return EMPTY;
	else if (line[0] == '#' && line[1] == '#')
		return IDENT;
	else if (line[0] == '#' && line[1] != '#')
		return COMMENT;
	else if (int_string(line))
		return ANT_COUNT;
	else if (ft_strchr(line, ' ') != NULL)
		return ROOM;
	else if (ft_strchr(line, '-') != NULL)
		return LINK;
	else if (line[0] == 'L')
		return MOVE;
	else
		return INVLD;
}

void	assign_room(t_anthill *ah, char *str, bool *s, bool *e)
{
	t_room	*room;
	char	**line;
	
	line = ft_strsplit(str, ' ');
	room = init_room_g(line[0], ft_atoi(line[1]), ft_atoi(line[2]));
	free(line[0]);
	free(line[1]);
	free(line[2]);
	free(line);
	ah->start = (*s) ? room : ah->start;
	ah->end = (*e) ? room : ah->end;
	room->is_start = *s;
	room->is_end = *e;
	ah->room_count++;
	if (!ah->linear)
		ah->linear = room;
	else
		append_room(ah->linear, room);
	*s = false;
	*e = false;
}

t_room *get_room(t_anthill *anthill, char *name)
{
	t_room *cursor;

	cursor = anthill->linear;

	while (cursor)
	{
		if (!(ft_strcmp(name, cursor->name)))
		{
			return (cursor);
		}
		cursor = cursor->next;
	}
	return (NULL);
}

void	assign_link(t_anthill *ah, char *str)
{
	char **line;
	t_room *from;
	t_room *to;


	line = ft_strsplit(str, '-');
	from = get_room(ah, line[0]);
	to = get_room(ah, line[1]);


	// Updated code for BFS
	t_link *link;
	t_link *cursor;
	
	link = malloc(sizeof(t_link));
	link->to = to;
	link->from = from;
	link->next = NULL;


	cursor = ah->connectors;

	if (!cursor)
		ah->connectors = link;
	else
	{
		while (cursor->next)
			cursor = cursor->next;
		cursor->next = link;
	}
	// End of update

	free(line[0]);
	free(line[1]);
	free(line);
	if (from && to)
	{
		if (!from->links)
			from->links = malloc(sizeof(t_room *) * ah->room_count);
		from->links[from->link_count] = to;
		from->link_count++;
	}
}

void	print_hill(t_anthill *anthill)
{
	t_room *cursor;
	cursor = anthill->linear;
	int link;
	while (cursor)
	{
		link = 0;
		if (cursor->is_end)
			printf("End   ");
		else if (cursor->is_start)
			printf("Start ");
		else
			printf("      ");
		
		printf("Room : '%s', [%d], [%d]\n", cursor->name, cursor->x, cursor->y);
		while (link < cursor->link_count)
		{
			printf("            Linked to '%s'\n", cursor->links[link]->name);
			link++;
		}
		cursor = cursor->next;
	}
}

t_path	*append_path(t_path *path, t_room *room)
{
	t_path *p;
	t_path *cur;

	p = malloc(sizeof(t_path));
	p->next = NULL;
	p->room = room;
	if (!path)
	{
		path = p;
	}
	else
	{
		cur = path;
		while (cur->next)
			cur = cur->next;
		cur->next = p;
	}
	return path;
}

bool visited(t_path *path, t_room *room)
{
	t_path *cursor;

	cursor = path;

	while (cursor)
	{
		if (cursor->room == room)
			return true;
		cursor = cursor->next;
	}
	return false;
}

void	move(t_path **callback, t_path *path, t_room *from, t_room *to)
{
	int i;

	i = 0;

	if (from)
		append_path(path, from);

	if (to && to->is_end)
	{
		//append_path(path, to);
		*callback = path;
	}

	if (*callback)
	{
		return ;
	}

	while (i < to->link_count)
	{
		if (!(visited(path, to->links[i])))
			move(callback, path, to, to->links[i]);
		i++;
	}
}

void traverse_anthill(t_anthill *anthill)
{
	printf("Start links to %d rooms\n", anthill->start->link_count);
	printf("End links to %d rooms\n", anthill->end->link_count);

	t_path *path = append_path(NULL, anthill->start);
	t_path *valid_path;

	move(&valid_path, path, NULL, anthill->start);
	
	printf("Valid Path? %s\n", (valid_path) ? "Yes" : "No");

	while (valid_path)
	{
		printf("%s --> \n", valid_path->room->name);
		valid_path = valid_path->next;
	}
	printf("\n");
}

void	assign_ants(t_anthill *anthill, char *str)
{
	char **line;
	int i;

	anthill->nb_ants = ft_atoi(str);

	i = 0;
	while (i < anthill->nb_ants)
	{
		hatch_ant(anthill, 0, 0, "name_here");
		i++;
	}
}

t_anthill  *get_infos()
{
	char		*line;
	int			line_type;
	t_anthill	*anthill;
	bool		next_start;
	bool		next_end;
	
	next_start = false;
	next_end = false;
	anthill = init_anthill();
	while (get_next_line(0, &line) > 0)
	{
		line_type = identify_line(line);
		if (line_type == IDENT && ft_strchr(line, 'e') != NULL)
			next_end = true;
		else if (line_type == IDENT && ft_strchr(line, 's') != NULL)
			next_start = true;
		else if (line_type == ROOM)
			assign_room(anthill, line, &next_start, &next_end);
		else if (line_type == LINK)
		 	assign_link(anthill, line);
		else if (line_type == ANT_COUNT)
			assign_ants(anthill, line);
		free(line);
	}
	//traverse_anthill(anthill);
	return(anthill);
}