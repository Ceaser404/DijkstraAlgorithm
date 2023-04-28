#include <iostream>
#include <SDL2/SDL.h>
#include <random>
#include <ranges>
#include <algorithm>


void draw_state(std::vector<int>& v, SDL_Renderer* renderer, unsigned int red, unsigned blue)
{
	int index = 0;
	for (int i : v)
	{
		SDL_SetRenderDrawColor(renderer, 255,255,255,255);
		SDL_RenderDrawLine(renderer, index, 99, index, i);
		index += 1;

	}


}


int main()
{
	std::random_device rd;
	std::uniform_int_distribution<int> d(1, 99);	
	std::vector<int> v;
	for (uint8_t i = 0; i < 100; i++)
	{
		v.push_back(d(rd));
	}
	// bubble sort algorithm
	
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	SDL_CreateWindowAndRenderer(
		100*10, 100*10, 0,
		&window, &renderer);	

	SDL_RenderSetScale(renderer, 10, 10);
	
	SDL_Event e;
	bool quit = false;

	while (!quit)
	{
		while (SDL_PollEvent(&e))
		{
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}

			if (e.type == SDL_KEYDOWN)
			{
				quit = true;
			}
			
			
			for (uint8_t i = 0; i < v.size(); i++) 
			{
				for (uint8_t j = i; j < v.size(); j++)

				{
					if (v[j] < v[i]) 
					{
						std::swap(v[j], v[i]);
					}

				// Clear screen
				SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
				SDL_RenderClear(renderer);
				// Draw the state of the sort
				//
				draw_state(v, renderer, i, j);

				// Show to window
				SDL_RenderPresent(renderer);
				}
			}
		}		
	}
}

