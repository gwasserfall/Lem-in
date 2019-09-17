#include "visualiser.h"

#define ANT_COUNT 1
#define IDENT 2
#define ROOM 3
#define LINK 4
#define COMMENT 5
#define INVLD 6
#define MOVE 7
#define EMPTY 8

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
	anthill->movelist = NULL;
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
	new->level = -1;
	new->parent = NULL;
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
	else if (ft_strchr(line, ' ') && line[0] != 'L')
		return ROOM;
	else if (ft_strchr(line, '-') && line[0] != 'L')
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
	if (room->is_start)
		room->level = 0;
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
	t_link *link;
	t_link *cursor;

	line = ft_strsplit(str, '-');
	from = get_room(ah, line[0]);
	to = get_room(ah, line[1]);
	
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

void	assign_ants(t_anthill *anthill, char *str)
{
	int i;

	anthill->nb_ants = ft_atoi(str);

	i = 0;
	while (i < anthill->nb_ants)
	{
		hatch_ant(anthill, 0, 0, ft_itoa(i + 1));
		i++;
	}
}

t_movelist *make_movelist_item(t_moves *moves)
{
	t_movelist *new;

	if (!(new = malloc(sizeof(t_movelist))))
		return (NULL);
	new->next = NULL;
	new->active = false;
	new->complete = false;
	new->moves = moves;
	return (new);
}

void	append_to_movelist(t_movelist **start, t_movelist *new)
{
	t_movelist *mvlist;

	mvlist = *start;
	if (!mvlist)
		*start = new;
	else
	{
		while (mvlist->next)
			mvlist = mvlist->next;
		mvlist->next = new;
	}
}

void	assign_move(t_anthill *anthill, char *str)
{
	char **line;
	int i;
	t_moves *moves;

	moves = NULL;
	line = ft_strsplit(str, ' ');
	i = 0;
	while (line[i])
		append_move(&moves, deserialise_move(anthill, line[i++]));
	append_to_movelist(&anthill->movelist, make_movelist_item(moves));
	// TODO free line
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
		if (line_type == IDENT && ft_strchr(line, 'e'))
			next_end = true;
		else if (line_type == IDENT && ft_strchr(line, 's'))
			next_start = true;
		else if (line_type == ROOM)
			assign_room(anthill, line, &next_start, &next_end);
		else if (line_type == LINK)
		 	assign_link(anthill, line);
		else if (line_type == ANT_COUNT)
			assign_ants(anthill, line);
		else if (line_type == MOVE)
			assign_move(anthill, line);
		free(line);
	}
	return(anthill);
}