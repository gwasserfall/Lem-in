#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>

#include <stdbool.h>

// ##start
// 1 23 3
// 2 16 7
// #comment
// 3 16 3
// 4 16 5
// 5 9 3
// 6 1 5
// 7 4 8
// ##end
// 0 9 5

#define LINK_MAX 20

#define WIDTH 480
#define HEIGHT 640

typedef struct svector
{
	int x;
	int y;
}	vector;

typedef struct sroom
{
	struct sroom *next;
	struct sroom **links;
	int link_count;
	char *name;
	vector pos;
}				room;

typedef struct s_hill
{
	room *start;
	room *end;
}			t_anthill;

typedef	struct		s_state
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	t_anthill		*anthill;
	bool			running;
	int				width;
	int				height;
}					t_state;


room *new_room(char *name, int x, int y)
{
	room *new = malloc(sizeof(room));

	new->name = strdup(name);
	new->pos.x = x;
	new->pos.y = y;
	new->link_count = 0;

	new->links = malloc(sizeof(room *) * LINK_MAX);
	new->next = NULL;
	return new;
}


void	link_room(room *r1, room *r2)
{
	r1->links[r1->link_count] = r2;
	r1->link_count++;
}

t_anthill *init()
{
	t_anthill *hill = malloc(sizeof(t_anthill));
	// ##start
	// 1 23 3
	room *one = new_room("START", 23, 3);
	// 2 16 7
	room *two = new_room("TWO", 16, 7);
	// #comment
	// 3 16 3
	room *three = new_room("THREE", 16, 3);
	// 4 16 5
	room *four = new_room("FOUR", 16, 5);
	// 5 9 3
	room *five = new_room("FIVE", 9, 3);
	// 6 1 5
	room *six = new_room("SIX", 1, 5);
	// 7 4 8
	room *seven = new_room("SEVEN", 4, 8);
	// ##end // 0 9 5
	room *zero = new_room("END", 9, 5);

	hill->start = one;
	hill->end = zero;

	one->next = two;
	two->next = three;
	three->next = four;
	four->next = five;
	five->next = six;
	six->next = seven;
	seven->next = zero;

	link_room(zero, four);// 0-4
	link_room(zero, six);// 0-6
	link_room(one, three);// 1-3
	link_room(four, three);// 4-3
	link_room(five, two);// 5-2
	link_room(three, five);// 3-5
	link_room(four, two);// 4-2
	link_room(two, one);// 2-1
	link_room(seven, six);// 7-6
	link_room(seven, two);// 7-2
	link_room(seven, four);// 7-4
	link_room(six, five);// 6-5

	return hill;

}


void	draw_rect(SDL_Renderer* renderer, int x, int y)
{
	SDL_Rect r;
    r.x = x;
    r.y = y;
    r.w = 20;
    r.h = 20;

	SDL_SetRenderDrawColor( renderer, 0, 0, 255, 255 );

    // Render rect
    SDL_RenderFillRect( renderer, &r );

    // // Render the rect to the screen
    // SDL_RenderPresent(renderer);
}


#define ZOOM 20

t_state	*new_state(void)
{
	t_state *state;

	if (!(state = malloc(sizeof(t_state))))
		return (NULL);
	state->renderer = NULL;
	state->window = NULL;
	state->anthill = NULL;
	
	return (state);
}

t_state *initialise_state(int width, int height, Uint32 flags)
{
	t_state *state;

	state = new_state();
	state->width = width;
	state->height = height;
	state->window = SDL_CreateWindow("Lem-in", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
	state->renderer = SDL_CreateRenderer(state->window, -1, SDL_RENDERER_ACCELERATED);
	state->running = true;

	if (!state->window)
		printf("Could not create window: %s\n", SDL_GetError());

	return state;
}


int	tx(x)
{
	x = x * ZOOM + 10;
	return x + (WIDTH / 8);
}

int ty(y)
{
	if (y > 5)
		y += 6;
	else if (y > 3)
		y += 2;

	y = y * ZOOM + 10;
	return y + (HEIGHT / 8);
}

void draw(SDL_Renderer* renderer, t_anthill *anthill)
{
	room *start;

	start = anthill->start;
	int i;

	while (start)
	{
		i = 0;
		
		// Draw links first
		while (i < start->link_count)
		{
			thickLineRGBA(renderer, tx(start->pos.x), ty(start->pos.y), tx(start->links[i]->pos.x), ty(start->links[i]->pos.y), 3, 221, 221, 221, 155);
			thickLineRGBA(renderer, tx(start->pos.x), ty(start->pos.y), tx(start->links[i]->pos.x), ty(start->links[i]->pos.y), 2, 201, 201, 201, 255);
			
			i++;
		}
		start=start->next;
	}

	start = anthill->start;
	while (start)
	{	
		filledEllipseRGBA(renderer, tx(start->pos.x), ty(start->pos.y), 14, 14, 200, 200, 0, 130);
		filledEllipseRGBA(renderer, tx(start->pos.x), ty(start->pos.y), 10, 10, 200, 200, 0, 255);
		filledEllipseRGBA(renderer, tx(start->pos.x), ty(start->pos.y), 12, 12, 200, 200, 0, 200);
		start = start->next;
	}

}

int main (int argc, char** argv)
{
	SDL_Window *win;
	SDL_Event ev;

	win = SDL_CreateWindow("asd", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);


	bool running = true;

	while (running)
	{
		if (SDL_PollEvent(&ev))
		{
			if (ev.type == SDL_QUIT)
				running = false;
			if (ev.type == SDL_KEYDOWN)
				running = false;
		}
	}


	return 0;


	t_state *state;
	SDL_Event event;

	state = initialise_state(800, 600, 0);
	state->anthill = init();

	SDL_RenderClear(state->renderer);

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		while (state->running) // event loop
		{
			// handle event;
			if (SDL_PollEvent(&event))
			{
				if (event.type == SDL_QUIT)
					state->running = false;
				if (event.type == SDL_KEYDOWN)
					state->running = false;
			}
		


			// update vars



			// render
			filledEllipseRGBA(state->renderer, 1, 1, 14, 14, 200, 200, 0, 130);
			SDL_RenderPresent(state->renderer);
			SDL_Delay(1200);
		}
	}

	SDL_DestroyWindow(state->window);
	SDL_DestroyRenderer(state->renderer);
    SDL_Quit();

	//return (0);

	t_anthill *anthill = init();

	SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window* window = NULL;
    window = SDL_CreateWindow
    (
        "Lemon is Hard",
		SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        HEIGHT,
        WIDTH,
        SDL_WINDOW_SHOWN
    );

    // Setup renderer
    SDL_Renderer* renderer = NULL;
    renderer =  SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED);

    // Set render color to red ( background will be rendered in this color )
    //SDL_SetRenderDrawColor( renderer, 255, 0, 0, 255 );

    // Clear winow
    SDL_RenderClear( renderer );

    // Render the rect to the screen
	int x = 40;
	

	SDL_Event e;
	
	bool quit = false;
	while (!quit){

		draw(renderer, anthill);

		SDL_RenderPresent(renderer);
		
		while (SDL_PollEvent(&e)){
			
			if (e.type == SDL_KEYUP)
			{
				x++;
			}
			if (e.type == SDL_QUIT){
				quit = true;
			}
		}
	}

    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;
}