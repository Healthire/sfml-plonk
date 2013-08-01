#include "MainMenu.h"
#include "GuiButton.h"
#include "StateManager.h"
#include "PlayState.h"

MainMenu::MainMenu(){

}

void MainMenu::Init(){

	Input = new InputHandler(stateManager->game->Window);

	GuiButton* testbutton = new GuiButton(&Gui, sf::Vector2f(0, 0), sf::Vector2f(270, 55));
	testbutton->setTag("start");
	testbutton->setText("Start Game");

	Gui.setViewport(stateManager->game->Window->getSize());

	Gui.Init();

	sf::Vector2f guiSize = sf::Vector2f(1280, 720);
	Gui.setSize(guiSize);
}

void MainMenu::LoadAssets(AssetManager* AssetManager){
	Gui.LoadAssets(AssetManager);
}

void MainMenu::Update(float dTime){
	Input->Update();
	Gui.Update(Input);

	while(Gui.pollMessage()){
		GuiMessage msg = Gui.getMessage();
		HandleGuiMessage(msg);
	}
}

void MainMenu::Draw(sf::RenderTarget* target){
	Gui.Draw(target);
}

void MainMenu::HandleGuiMessage(GuiMessage msg){
	std::string message = msg.GetMessage();
	std::string tag = msg.GetSender()->getTag();

	if(message == "mouseUp"){
		if(tag == "start"){
			StartGame();
		}
	}
}

void MainMenu::StartGame(){
	PlayState* playState = new PlayState;
	stateManager->AddState(playState);
	stateManager->RemoveState(this);
}