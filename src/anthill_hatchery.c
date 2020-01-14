#include <lem_in.h>

void	join_colony(t_anthill **anthill, t_ant *larvae)
{
	t_ant	*nurse;
	if (!(*anthill)->colony)
		(*anthill)->colony = larvae;
	else
	{
		nurse = (*anthill)->colony;
		while (nurse->next)
			nurse = nurse->next;
		nurse->next = larvae;
	}
}

int		hatch_ant(t_anthill *anthill, char *name)
{
	t_ant *egg;

	if (!(egg = malloc(sizeof(t_ant))))
		return (0);
	egg->next = NULL;
	egg->following = NULL;
	egg->current = anthill->start;
	egg->name = name;
	join_colony(&anthill, egg);
	return (1);
}

/*
** Now that the rooms have levels this will go and find all the valid paths
** and add them to the pathlist struct *Does not include ##start-##end.
*/

/* apparently I can't write a freaking string-reverse algorithm
   stackoverflow.com/a/784567/6850771 */
char *reverse(char *str)
{
    char tmp, *src, *dst;
    size_t len;
    if (str != NULL)
    {
        len = strlen (str);
        if (len > 1) {
            src = str;
            dst = src + len - 1;
            while (src < dst) {
                tmp = *src;
                *src++ = *dst;
                *dst-- = tmp;
            }
        }
    }
    return str;
}

void	create_colony(t_anthill *anthill)
{
	int i;

	i = 0;
	while (i < anthill->nb_ants)
		hatch_ant(anthill, ft_itoa(++i));
	
}