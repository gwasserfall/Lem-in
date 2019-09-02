// #include "visualiser.h"

// room	*new_room(char *name, int x, int y)
// {
// 	room *r = malloc(sizeof(room));
// 	r->link_count = 0;
// 	r->links = malloc(sizeof(room *) * 10);
// 	r->name = strdup(name);
// 	r->next = NULL;
// 	r->pos.x = x;
// 	r->pos.y = y;
// 	return r;
// }

// void link_room(room* this, room *that)
// {
// 	this->links[this->link_count] = that;
// 	this->link_count++;
// }


// t_anthill *init()
// {
// 	t_anthill *hill = malloc(sizeof(t_anthill));
// 	// ##start
// 	// 1 23 3
// 	room *one = new_room("START", 23, 3);
// 	// 2 16 7
// 	room *two = new_room("TWO", 16, 7);
// 	// #comment
// 	// 3 16 3
// 	room *three = new_room("THREE", 16, 3);
// 	// 4 16 5
// 	room *four = new_room("FOUR", 16, 5);
// 	// 5 9 3
// 	room *five = new_room("FIVE", 9, 3);
// 	// 6 1 5
// 	room *six = new_room("SIX", 1, 5);
// 	// 7 4 8
// 	room *seven = new_room("SEVEN", 4, 8);
// 	// ##end // 0 9 5
// 	room *zero = new_room("END", 9, 5);

// 	hill->start = one;
// 	hill->end = zero;

// 	one->next = two;
// 	two->next = three;
// 	three->next = four;
// 	four->next = five;
// 	five->next = six;
// 	six->next = seven;
// 	seven->next = zero;

// 	link_room(zero, four);// 0-4
// 	link_room(zero, six);// 0-6
// 	link_room(one, three);// 1-3
// 	link_room(four, three);// 4-3
// 	link_room(five, two);// 5-2
// 	link_room(three, five);// 3-5
// 	link_room(four, two);// 4-2
// 	link_room(two, one);// 2-1
// 	link_room(seven, six);// 7-6
// 	link_room(seven, two);// 7-2
// 	link_room(seven, four);// 7-4
// 	link_room(six, five);// 6-5

// 	return hill;
// }