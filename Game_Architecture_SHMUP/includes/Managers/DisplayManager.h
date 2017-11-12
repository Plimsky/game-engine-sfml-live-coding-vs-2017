#pragma once

#include <SFML/Graphics.hpp>
#include <Managers/IManager.h>
#include <Utils/Sprite.h>

using namespace Utils;

namespace Managers
{
	class DisplayManager : public IManager
	{
	public:
		static const unsigned int m_windowWidth = 1280;
		static const unsigned int m_windowHeight = 720;

		enum class Layers : uint8_t
		{
			BACKGROUND = 0u,
			PLAYER,
			ENEMY,
			UI
		};

	private:
		sf::RenderWindow *m_window;
		bool m_isStarted;
		std::map<Layers, Sprite *> m_sprites;

	public:
		DisplayManager();
		~DisplayManager();

		void Setup() override;
		void Update() override;

		bool IsRunning() const;
		bool IsStarted() const;
	};
}
