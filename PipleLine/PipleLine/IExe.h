#pragma once
#include "SDL.h"
class IExe{
protected:
	SDL_Renderer *m_render;
public:
	static const int SCR_WIDTH = 800;
	static const int SCR_HEIGHT = 480;

	IExe(SDL_Renderer *ren) {
		this->m_render = ren;
	}

	void setPixel(int x, int y, int red, int green, int blue, int alpha) {
		if (x < 0 || x >= SCR_WIDTH || y < 0 || y >= SCR_HEIGHT)
			return;

		SDL_SetRenderDrawColor(m_render, red, green, blue, alpha);
		SDL_RenderDrawPoint(m_render, x, y);
	}
	virtual int init() = 0;
	virtual void update() = 0;
	virtual void destory() = 0;
};//end class

