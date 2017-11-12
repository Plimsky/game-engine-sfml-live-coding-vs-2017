#include <Utils/Sprite.h>
#include <iostream>

using namespace Utils;

Sprite::Sprite(): m_texture(nullptr), m_sprite(nullptr)
{
	std::cout << "Sprite created" << std::endl;
}

Sprite::Sprite(const std::string& p_filename) : m_texture(nullptr), m_sprite(nullptr)
{
	LoadSprite(p_filename);
	std::cout << "Sprite created" << std::endl;
}

Sprite::~Sprite()
{
	if (m_sprite != nullptr)
		delete m_sprite;

	if (m_texture != nullptr)
		delete m_texture;

	std::cout << "Sprite destroyed" << std::endl;
}

void Sprite::LoadSprite(const std::string &p_filename)
{
	m_texture = new sf::Texture;

	if (m_texture != nullptr)
	{
		m_texture->loadFromFile(p_filename);
		m_sprite = new sf::Sprite(*m_texture);
	}
}

sf::Sprite* Sprite::GetSource() const
{
	return m_sprite;
}
