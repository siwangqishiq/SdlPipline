#pragma once

#include <iostream>
#include "IExe.h"
#include "PipelineMath.hpp"

class Pipeline : public IExe{
public:
	Pipeline(SDL_Renderer *ren) : IExe(ren) {
	}

	// Í¨¹ý IExe ¼Ì³Ð
	virtual int init() override;
	virtual void update() override;
	virtual void destory() override;
};

