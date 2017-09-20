#include <iostream>
#include <string>
#include "SDL.h"
#include "IExe.h"
#include "BaseInstance.h"
#include "Pipline.h"

SDL_Window *window = nullptr;
SDL_Renderer *render = nullptr;

IExe *instance = nullptr;

int main(int argc, char *argv[]) {
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1) {
		std::cout << SDL_GetError() << std::endl;
		return 1;
	}
	
	window = SDL_CreateWindow("Hello Pipline", SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, IExe::SCR_WIDTH, IExe::SCR_HEIGHT, SDL_WINDOW_SHOWN);

	if (window == nullptr) {
		std::cout << SDL_GetError() << std::endl;
		return 2;
	}

	render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED
		| SDL_RENDERER_PRESENTVSYNC);
	if (render == nullptr) {
		std::cout << SDL_GetError() << std::endl;
		return 3;
	}
	
	//instance = new BaseInstance(render);
	instance = new Pipeline(render);

	SDL_Event e;//ÊÂ¼þ
	bool quit = false;

	if (instance != nullptr) {
		instance->init();
	}

	while (!quit) {
		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT) {
				quit = true;
			}
			//if (e.type == SDL_KEYDOWN) {
			//	quit = true;
			//}
		}
	
		//clear background
		SDL_SetRenderDrawColor(render, 255, 255, 255, 255);
		SDL_RenderClear(render);

		if (instance != nullptr) {
			instance->update();
		}

		//cout << "update clear" << endl;
		//SDL_SetRenderDrawColor(render, 255, 255, 255, 255);
		//SDL_RenderFillRect(render, &bgRect);
		//SDL_RenderDrawRect(render, &bgRect);
		
		SDL_RenderPresent(render);
	}//end while
	if (instance != nullptr) {
		instance->destory();

		delete instance;
		instance = nullptr;
	}
	

	SDL_DestroyRenderer(render);
	SDL_DestroyWindow(window);

	SDL_Quit();

	return 0;
}

