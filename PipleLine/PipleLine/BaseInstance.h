#pragma once
#include "IExe.h"
#include <iostream>

class BaseInstance :public IExe{
public:
	BaseInstance(SDL_Renderer *ren):IExe(ren){
	}

	// Í¨¹ý IExe ¼Ì³Ð
	int init() override;

	void update() override;

	void destory() override;
protected:
	int m_win_width;
	int m_win_height;
};

