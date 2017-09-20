#include "Pipline.h"

#include "unitTest.hpp"

int Pipeline::init(){
	std::cout << "pipleline init" << std::endl;
	doTestUnit();
	return 0;
}

void Pipeline::update(){
	//std::cout << "pipleline update" << std::endl;
}

void Pipeline::destory(){
	std::cout << "pipleline destory" << std::endl;
}
