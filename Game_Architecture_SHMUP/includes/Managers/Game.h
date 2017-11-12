#pragma once
#include <Managers/IManager.h>
#include <Managers/DisplayManager.h>

namespace Managers
{
	class Game : public IManager
	{
	private:
		DisplayManager *m_displayManager;

	public:
		Game();
		~Game();

		void Setup() override;
		void Update() override;
		void Run();
	};
}
