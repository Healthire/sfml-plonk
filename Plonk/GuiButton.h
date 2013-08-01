#pragma once
#include "GuiElement.h"

class GuiButton : public GuiElement
{
public:
	GuiButton(GuiState* state, sf::Vector2f btnPos, sf::Vector2f btnSize);
	~GuiButton(void);

	void Init();
	void LoadAssets(AssetManager* AssetManager);
	void Update(InputHandler* input);
	void Draw(sf::RenderTarget* target, sf::RenderStates states = sf::RenderStates::Default);

	void setText(std::string newText);

	bool ContainsPoint(sf::Vector2f point);

private:
	sf::Vector2f pos;
	sf::Vector2f size;
	sf::Font* font;
	sf::Text text;

	bool focus;
};

