#include "NewGame.h"

int main()
{
	NewGame game;
	game.InitializeGame();
	game.StageChooseBase();
	game.StageChoseRegion();
	game.StageDuels();
	game.Ranking();
	return 0;
}