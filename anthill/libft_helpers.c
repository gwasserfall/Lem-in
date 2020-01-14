#include <lem_in.h>

/*
** checks if the only info in the line is digits.
*/

bool		only_digit(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (ft_isdigit(line[i]) == 0)
			return (false);
		i++;
	}
	return (true);
}
