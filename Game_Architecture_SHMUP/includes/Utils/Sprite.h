#pragma once
#include <SFML/Graphics.hpp>

namespace Utils
{
	class Sprite
	{
	private:
		sf::Texture *m_texture;
		sf::Sprite *m_sprite;

	public:
		Sprite();
		explicit Sprite(const std::string &p_filename);
		~Sprite();

		void LoadSprite(const std::string& p_filename);
		sf::Sprite* GetSource() const;
	};
}
