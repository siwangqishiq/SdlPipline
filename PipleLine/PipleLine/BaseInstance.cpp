#include "BaseInstance.h"

int BaseInstance::init() {
	std::cout << "Base Instance init" << std::endl;
	return 0;
}

void BaseInstance::update(float delta){
	std::cout << "Base Instance update" << std::endl;

	for (int x = 0; x < 100; x++) {
		setPixel(x , x , 255 , 0 , 0, 255);
	}
}

void BaseInstance::destory(){
	std::cout << "Base Instance destory" << std::endl;

}
