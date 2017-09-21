#include "Pipline.h"

#include "unitTest.hpp"

int Pipeline::init(){
	std::cout << "pipleline init" << std::endl;
	doTestUnit();
	return 0;
}

void Pipeline::update(float delta){
	//std::cout << "pipleline update" << delta<< std::endl;
	//SDL_Delay(500);
}

void Pipeline::destory(){
	std::cout << "pipleline destory" << std::endl;
}
