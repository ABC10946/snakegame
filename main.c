#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

typedef enum
{
	Up,
	Left,
	Right,
	Down
} Direction;

typedef struct SnakeCell
{
	int x;
	int y;
	Direction CellDirection;
} SnakeCell;

typedef struct Snake
{
	int length;
	SnakeCell *body;
} Snake;

int **field = NULL;
Snake snake;

void initField(int width, int height)
{
	field = (int **)malloc(sizeof(int *) * height);
	for (int i = 0; i < height; i++)
	{
		field[i] = (int *)malloc(sizeof(int) * width);
	}

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			field[i][j] = 0;
		}
	}
}

bool isDigitArray(char *str)
{
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (!isdigit(str[i]))
		{
			return false;
		}
	}
	return true;
}

void printField(int width, int height)
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			printf("%d", field[i][j]);
		}
		printf("\n");
	}
}

void initSnake(int length, int x, int y)
{
	snake.length = length;
	SnakeCell cells[length];
	for (int i = 0; i < length; i++)
	{
		SnakeCell cell;
		cell.x = i;
		cell.y = 0;
		cell.CellDirection = Left;
		cells[i] = cell;
	}
	snake.body = cells;
}

void putSnake(Snake snake)
{
	for (int i = 0; i < snake.length; i++)
	{
		int x = snake.body[i].x;
		int y = snake.body[i].y;
		field[y][x] = 1;
	}
}

void resetField(int width, int height)
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			field[i][j] = 0;
		}
	}
}

void stepSnake(Snake snake)
{
	for (int i = 1; i < snake.length; i++)
	{
		SnakeCell forwardCell = snake.body[i - 1];
		if (forwardCell.CellDirection == Up)
		{
			snake.body[i].y -= 1;
		}
		else if (forwardCell.CellDirection == Left)
		{
			snake.body[i].x -= 1;
		}
		else if (forwardCell.CellDirection == Down)
		{
			snake.body[i].y += 1;
		}
		else if (forwardCell.CellDirection == Right)
		{
			snake.body[i].x += 1;
		}
	}
}

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		fprintf(stderr, "argument must be 2\n");
		fprintf(stderr, "snakegame <width> <height>\n");
		return -1;
	}

	if (!isDigitArray(argv[1]) || !isDigitArray(argv[2]))
	{
		fprintf(stderr, "argument value error\n");
		fprintf(stderr, "argument width, height must be integer\n");
		return -1;
	}

	int width = atoi(argv[1]);
	int height = atoi(argv[2]);
	initField(width, height);
	printField(width, height);
	initSnake(3, 0, 0);
	putSnake(snake);
	printField(width, height);
	resetField(width, height);
}
