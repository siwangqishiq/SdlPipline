#include <iostream>
#include <string>
#include <ctime>
#include "SDL.h"
#include "IExe.h"
#include "BaseInstance.h"
#include "Pipline.h"


uint64_t mLastFrameNs = 0;

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

	float second_cout = 0;
	float fps = 0;

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
			timespec now;
			timespec_get(&now, 1);
			long nowNs = now.tv_sec * 1000000000ull + now.tv_nsec;
			if (mLastFrameNs > 0) {
				float dt = float(nowNs - mLastFrameNs) * 0.000000001f;

				second_cout += dt;
				fps++;
				//std::cout << "time " << dt << std::endl;
				if (second_cout > 1.0f) {
					std::cout << "fps =  " << fps << std::endl;

					second_cout = 0;
					fps = 0;
				}
				instance->update(dt);
			}
			//SDL_Delay(1000);
			mLastFrameNs = nowNs;
			//clock_gettime(CLOCK_MONOTONIC, &now);
			//std::cout << "time " << nowNs << std::endl;
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

