#include <Managers/Game.h>
#include <iostream>

using namespace Managers;

Game::Game() : m_displayManager(nullptr)
{
	std::cout << "Game Manager created" << std::endl;
}

Game::~Game()
{
	if (m_displayManager != nullptr)
		delete m_displayManager;
	std::cout << "Game Manager destroyed" << std::endl;
}

void Game::Setup()
{
	m_displayManager = new DisplayManager();
	
	if (m_displayManager != nullptr)
		m_displayManager->Setup();
}

void Game::Update()
{
	// Inputs Handling

	// Update Gameplay

	// Display Sprites
	m_displayManager->Update();
}

void Game::Run()
{
	while(m_displayManager->IsRunning())
	{
		Update();
	}
}
