#include <stdio.h>
#include <stdlib.h>

int main() 
{
	const int HEIGHT = 30;
	const int WIDTH = 30;
	
	char current_gen[HEIGHT][WIDTH];
	char next_gen[HEIGHT][WIDTH];
	
	int vicini;
	int x, y; 
	int i, j;
	
	for (y = 0; y < HEIGHT; y++) 
	{
		for (x = 0; x < WIDTH; x++) 
		{
			if (rand() % 2) 
			{
				current_gen[y][x] = ' ';
			} 
			else 
			{
				current_gen[y][x] = '*';
			}
		}
	}
	
	while (1) 
	{
		for (y = 0; y < HEIGHT; y++) 
		{
			for (x = 0; x < WIDTH; x++) 
			{
				vicini = 0;
				for (i = -1; i < 2; i++) 
				{
					for (j = -1; j < 2; j++) 
					{
						if (current_gen[(y + i) % HEIGHT][(x + j) % WIDTH] == '*')
						{
							vicini++;
						}	
					}
				}
				if (current_gen[y][x] == '*')
				{
					vicini--;
				}
				if (current_gen[y][x] == ' ' && vicini == 3) 
				{
					next_gen[y][x] = '*';
				}
				else if (current_gen[y][x] == '*' && vicini < 2)
				{
					next_gen[y][x] = ' ';
				}
				else if (current_gen[y][x] == '*' && vicini > 3)
				{
					next_gen[y][x] = ' ';
				}
				else 
				{
					next_gen[y][x] = current_gen[y][x];
				}
				printf("%c ", current_gen[y][x]);
			}
			printf("\n");
		}
		
		system("cls");
		
		for (y = 0; y < HEIGHT; y++) 
		{
			for (x = 0; x < WIDTH; x++) 
			{
				current_gen[y][x] = next_gen[y][x];
			}
		}
		
	}
	
	return 0;
}
