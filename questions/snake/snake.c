#ifdef _WIN32
	#define WIN32_LEAN_AND_MEAN
	#include <windows.h>
#endif

#include "snake.h"

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

/// /// /// /// Your best friend for debuggnign: /// /// /// /// 
void print_snake(snake_t snake, size_t snake_size)
{
	for (int i = 0; i < snake_size; i++)
	{
		printf("%d) %d %d \n", i, snake[i][0], snake[i][1]);
	}
	printf("\n");
}

/// /// /// /// Drawing functions: /// /// /// /// 

void draw_at_xy(int x, int y, unsigned char color)
{
#ifdef _WIN32
	// Windows-specific code
	COORD coord; coord.X = x; coord.Y = y;
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(consoleHandle, coord);
#else
	// Unix/Linux/MacOS-specific code
	printf("\033[%d;%dH", y, x);
#endif
	printf("%c", color);
}

void clear_cursor()
{
	draw_at_xy(GAME_WIDTH + 1, 0, ' ');
}

void draw_borders()
{
	// vertical walls:
	for (int i = 0; i <= GAME_HEIGHT; i++)
	{
		draw_at_xy(0, i, WALLS_COLOR);
		draw_at_xy(GAME_WIDTH, i, WALLS_COLOR);
	}

	// Horizontal walls:
	for (int i = 0; i <= GAME_WIDTH; i++)
	{
		draw_at_xy(i, 0, WALLS_COLOR);
		draw_at_xy(i, GAME_HEIGHT, WALLS_COLOR);
	}
}

void draw_food(uint8_t* food)
{
	// TODO: Draw the food here!
	clear_cursor();
}

bool will_snake_collide_border_on_next_move(snake_t snake, size_t snake_size, direction_t direction)
{
	return false;
}

bool can_snake_move_in_direction(direction_t current_direction, direction_t requested_direction)
{
	return true;
}
bool will_snake_collide_with_itself_on_next_move(snake_t snake, size_t snake_size, direction_t direction)
{
	return false;
}

void draw_snake(snake_t snake, size_t snake_size)
{
	// TODO !
}
void erase_snake_tail(snake_t snake, size_t snake_size)
{
	// TODO !
}
void clear_snake(snake_t snake, size_t snake_size)
{
	// TODO !
}

snake_t create_snake(uint8_t x, uint8_t y)
{
	return NULL;
}
void free_snake(snake_t snake, size_t snake_size)
{
	// TODO !
}

uint8_t* snake_head(snake_t snake, size_t snake_size)
{
	return NULL;
}

void get_next_snake_head_location(snake_t snake, size_t snake_size, direction_t direction, uint8_t next_snake_head_pos[2])
{
	// TODO: Set the corret values!
	next_snake_head_pos[0] = -1;
	next_snake_head_pos[1] = -1;
}
size_t grow_snake(snake_t* snake_ptr, size_t snake_size, direction_t direction)
{
	return 0;
}

// correctly implemented, don't touch:
bool are_snakes_equal(snake_t a, size_t a_size, snake_t b, size_t b_size)
{
	if (a_size != b_size)
	{
		return false;
	}
	for (int i = 0; i < a_size; i++)
	{
		if (a[i][0] != b[i][0] || a[i][1] != b[i][1])
		{
			return false;
		}
	}
	return true;
}

void move_snake(snake_t snake, size_t snake_size, direction_t to_where)
{
	// TODO: Set the corret values!
	snake[snake_size - 1][0] = -1;
	snake[snake_size - 1][1] = -1;
}


snake_t create_long_snake(uint8_t x, uint8_t y, direction_t* growth_directions, size_t growth_directions_size)
{
	snake_t snake = create_snake(x, y);
	for (int i = 0; i < growth_directions_size; i++)
	{
		grow_snake(&snake, (i + 1), growth_directions[i]);
	}
	return snake;
}

bool will_snake_reach_food_on_next_move(snake_t snake, size_t snake_size, uint8_t* food, direction_t direction)
{
	return false;
}

bool is_food_on_snake(snake_t snake, size_t snake_size, uint8_t food[2])
{
	// TODO
}
void set_new_food_location(snake_t snake, size_t snake_size, uint8_t food[2])
{
	// TODO
}