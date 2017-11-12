#include <Managers/DisplayManager.h>
#include <iostream>

using namespace Managers;

DisplayManager::DisplayManager() : m_window(nullptr), m_isStarted(false)
{
	std::cout << "Display Manager created" << std::endl;
}

DisplayManager::~DisplayManager()
{
	auto it = m_sprites.begin();
	const auto end = m_sprites.end();

	if (m_window != nullptr)
		delete m_window;

	while (it != end)
	{
		delete it->second;
		++it;
	}

	std::cout << "Display Manager destroyed" << std::endl;
}

void DisplayManager::Setup()
{
	m_window = new sf::RenderWindow(sf::VideoMode(m_windowWidth, m_windowHeight), "My Game");
	
	if (m_window != nullptr)
		m_isStarted = true;

	// Example
	m_sprites[Layers::PLAYER] = new Sprite("res/spaceship.png");
}

void DisplayManager::Update()
{
	// TODO to move in the InputManager
	sf::Event event;
	while (m_window->pollEvent(event))
	{
		// Close window: exit
		if (event.type == sf::Event::Closed)
			m_window->close();
	}

	m_window->clear();

	auto it = m_sprites.begin();
	const auto end = m_sprites.end();

	// Call the same sprite at different positions (enemies)
	while (it != end)
	{
		m_window->draw(*it->second->GetSource());
		++it;
	}

	m_window->display();
}

bool DisplayManager::IsRunning() const
{
	if (m_window == nullptr)
		return false;

	return m_window->isOpen();
}

bool DisplayManager::IsStarted() const
{
	return m_isStarted;
}
