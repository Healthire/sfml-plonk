#include "Animation.h"


Animation::Animation(std::vector<int> frames, float frameRate, bool loopAnimation)
{
	cells = frames;
	rate = frameRate;
	loop = loopAnimation;

	currentCell = 0;
	elapsedTime = 0;
}

void Animation::Start(){
	if(cells.size() > 0){
		currentCell = 0;
		elapsedTime = 0;
	}
}

void Animation::Update(float dTime){
	elapsedTime += dTime;
	if(elapsedTime >= 1/rate){
		currentCell++;
		elapsedTime = 0;

		if(currentCell >= cells.size()){
			currentCell = loop ? 0 : cells.size() -1;
		}
	}
}

int Animation::GetCell(){
	return cells[currentCell];
}
