#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include "./libft/libft.h"
typedef struct        s_listg
{
    char            *content;
    int                fd;
    struct s_listg    *next;
}                    t_listg;
int                    get_next_line(const int fd, char **line);
#endif

t_listg        *getfile(t_listg **stat, int fd)
{
	t_listg *cur;
	if (!*stat)
	{
		*stat = malloc(sizeof(t_listg));
		(*stat)->next = NULL;
		(*stat)->fd = fd;
		return *stat;
	}
	cur = *stat;
	while (cur)
	{
		if (cur->fd = fd)
			return cur;
		cur = cur->next;
	}
	cur = malloc(sizeof(t_listg));
	cur->fd = fd;
	cur->next
}
static char        *get_line(t_listg **temp, t_listg **stat, int fd)
{
    char    *ptr;
    char    *line = NULL;
    t_listg    *node;
	char *tempstr;

    node = getfile(stat, fd);
    if ((ptr = ft_strchr((*temp)->content, '\n')))
    {
        *ptr = '\0';
        line = ft_strdup((*temp)->content);

		tempstr = ft_strcpy(node->content, (ptr + 1));

		//free(node->content);
        node->content = tempstr;
		//free(tempstr);

        return (line);    
    }
    line = ft_strdup((*temp)->content);
    ft_strclr(node->content);
    return (line);
}
int                get_next_line(const int fd, char **line)
{
    static t_listg    *stat;
    t_listg            *temp;
    char            buf[BUFF_SIZE + 1];
    int                readret;

	char *tempstr;


    if (fd < 0 || read(fd, buf, 0) < 0 || BUFF_SIZE <= 0)
        return (-1);
    *line = NULL;
    if (!(temp = getfile(&stat, fd)))
        return (-1);
    while ((readret = read(fd, buf, BUFF_SIZE)) > 0)
    {
        buf[readret] = '\0';
		
		tempstr = ft_strjoin(temp->content, buf);

		free(temp->content);
        temp->content = ft_strdup(tempstr);				
		free(tempstr);

		if (ft_strchr(buf, '\n'))
            break ;
    }
    if (readret == 0 && !ft_strlen(temp->content))
        return (0);
    *line = get_line(&temp, &stat, fd);
    return (1);
}

#include <fcntl.h>
#include <stdio.h>

int main()
{
	int fd = open("main.c", O_RDONLY);

	char *line;

	while (get_next_line(fd, &line) > 0)
	{
		printf("%s\n", line);
	}
	while (1);
}