#include "Managers/Game.h"

using namespace Managers;

int main()
{
	{
		Game game;
		game.Setup();
		game.Run();
	}
	system("pause");
	return 0;
}
