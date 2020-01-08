#include <stdlib.h>
#include <string.h>
#include <stdio.h>
// #include "./includes/lem_in.h"


typedef struct	s_node
{
	int				visited;
	int				start;
	int				end;
	char			*name;
	struct s_node	*parent;
	struct s_node	*next;
}					t_node;

// copied
typedef struct		s_fifo
{
	struct s_fifo 	*next;
	t_node			*node;
}					t_fifo;

typedef struct		s_link
{
	t_node			*a;
	t_node			*b;
	struct s_link 	*next;
}					t_link;

typedef struct			s_path
{
	t_node				*room;
	int					index;
	struct s_path		*next;
	struct s_path		*prev;
}						t_path;

t_node 				*new_node(char *name)
{
	t_node *node;

	node = malloc(sizeof(t_node));
	node->end = 0;
	node->start = 0;
	node->visited = 0;
	node->name = strdup(name);
	node->parent = NULL;
	node->next = NULL;
	return node;
}

void 				append_node(t_node **list, t_node *new)
{
	t_node *cursor;

	cursor = *list;
	if (cursor)
	{
		while (cursor->next)
			cursor = cursor->next;
		cursor->next = new;
	}
	else
		*list = new;	
}

t_link 				*new_link(t_node *a, t_node *b)
{
	t_link *link;

	link = malloc(sizeof(t_link));

	link->a = a;
	link->b = b;
	link->next = NULL;
	return (link);
}

// copied
void fifo_push(t_fifo **stack, t_node *node)
{
	t_fifo *element;
	t_fifo *head;

	element = malloc(sizeof(t_fifo));
	element->node = node;
	element->next = NULL;
	if (*stack)
		element->next = *stack;
	*stack = element;
}

// copied
t_node *fifo_pop(t_fifo **stack)
{
	t_fifo *head;
	t_node *node;
	
	head = *stack;
	node = NULL;
	if (!head)
		return node;
	while (head->next && head->next->next)
		head = head->next;
	if (!head->next)
	{
		*stack = NULL;
		node = head->node;
		free(head);
	}
	else
	{
		node = head->next->node;
		free(head->next);
		head->next = NULL;
	}
	return (node);
}

void append_node_link(t_link **links, t_node *a, t_node *b)
{
	t_link *cursor;
	t_link *link;

	link = new_link(a, b);
	cursor = *links;
	if (cursor)
	{
		while (cursor->next)
			cursor = cursor->next;
		cursor->next = link;
	}
	else
		*links = link;	
}

// copied
t_node	*get_node_neighbour(t_node *node, t_link *links)
{
	while (links)
	{
		if (links->a == node && !links->b->parent && !links->b->start)
		{
			links->b->parent = node;
			return (links->b);
		}
		if (links->b == node && !links->a->parent && !links->a->start)
		{
			links->a->parent = node;
			return (links->a);
		}
		links = links->next;
	}
	return (NULL);
}

void	add_to_path(t_path **start, t_node *node)
{
	t_path *head;
	t_path *path;
	
	path = malloc(sizeof(t_path));
	if (*start)
	{
		head = *start;
		while (head->next)
			head = head->next;
		head->next = path;
	}
	else
		*start = path;
}

int		node_in_path(t_node *node, t_path *path)
{
	while (path)
	{
		if (path->room == node)
			return 1;
		path = path->next;
	}
	return 0;
}

void	reset_node_parents(t_path *paths, t_node *node)
{
	while (node)
	{
		if (!node_in_path(node, paths))
			node->parent = NULL;
		node = node->next;
	}
}

void	graph_traverse(t_node *start_node, t_link *links)
{
	t_fifo	*queue;
	t_node	*node;
	t_node	*neighbour;

	queue = NULL;
	fifo_push(&queue, start_node);
	while ((node = fifo_pop(&queue)))
		while ((neighbour = get_node_neighbour(node, links)))
			fifo_push(&queue, neighbour);
}

// copied
t_path *get_shortest_path(t_node *end_node)
{
	t_path *start;

	start = NULL;
	while (end_node->parent)
	{
		printf("%s => %s, ", end_node->name, end_node->parent->name);
		add_to_path();
		end_node = end_node->parent;
	}
	printf("\n");
}

int main()
{
	// Build rooms
	t_node *node1 = new_node("node1");
	t_node *node2 = new_node("node2");
	t_node *node3 = new_node("node3");
	t_node *node4 = new_node("node4");
	t_node *node5 = new_node("node5");
	t_node *node6 = new_node("node6");
	t_node *node7 = new_node("node7");
	t_node *node8 = new_node("node8");
	t_node *node9 = new_node("node9");

	// link the nodes list
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	node5->next = node6;
	node6->next = node7;
	node7->next = node8;
	node8->next = node9;


	// Add start and end
	node1->start = 1;
	node3->end = 1;

	// Add links 
	t_link *links = NULL;
	append_node_link(&links, node1, node2);
	append_node_link(&links, node2, node3);
	append_node_link(&links, node3, node4);
	append_node_link(&links, node4, node5);
	append_node_link(&links, node5, node6);
	append_node_link(&links, node6, node7);
	append_node_link(&links, node7, node8);
	append_node_link(&links, node8, node9);
	append_node_link(&links, node1, node9);

	t_path *single_path;

	graph_traverse(node1, links);
	single_path = get_shortest_path(node5);


}