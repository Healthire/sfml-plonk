#pragma once
#include <vector>

class Animation
{
public:
	Animation(std::vector<int> frames, float frameRate, bool loopAnimation);

	void Start();
	void Update(float dTime);
	int GetCell();

private:
	std::vector<int> cells;
	float rate;
	bool loop;

	int currentCell;
	float elapsedTime;
};

