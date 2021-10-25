//Link to player
#include "Player.h"

#include "ZombieArena.h"
#include <iostream>

int main()
{
	/*Create 4 stages the game would be in*/
	enum class State { PAUSED, LEVELLING_UP, GAME_OVER, PLAYING };
	/*Start With Game Over state*/
	State state = State::PLAYING;



	sf::Vector2f desktopRes;
	desktopRes.x = sf::VideoMode::getDesktopMode().width;
	desktopRes.y = sf::VideoMode::getDesktopMode().height;
	sf::VideoMode vm(desktopRes.x, desktopRes.y);
	sf::RenderWindow window(vm, "Zombie Massacre!", sf::Style::Fullscreen);

	sf::View mainView(sf::FloatRect(0, 0, desktopRes.x, desktopRes.y));

	sf::Clock clock;
	sf::Time gameTimeTotal;

	/*Variable for World & screen corodinates from mouse*/
	sf::Vector2f mouseWorldPosition;
	sf::Vector2i mousePosition;

	Player player;

	sf::IntRect arena;

	// Create the background reference
	sf::VertexArray bg;

	// Load the texture for our background
	sf::Texture tBackground;
	tBackground.loadFromFile("assets/graphics/background_sheet.png");

	while (true)
	{
		/*Player Input*/
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::KeyPressed)
			{
				#pragma region Pause & Reset Game
				/*Pause game mid game*/
				if (event.key.code == sf::Keyboard::Return &&
					state == State::PLAYING) {
					/*Pause game*/
					state = State::PAUSED;
				}
				/*Restart While paused*/
				if (event.key.code == sf::Keyboard::Return &&
					state == State::PAUSED) {
					/*Restart game*/
					state = State::PLAYING;
					clock.restart();
				}
				/*Restart when in GAME_OVER state*/
				else if (event.key.code == sf::Keyboard::Return &&
					state == State::GAME_OVER) {
					/*Starting new game*/
					state = State::LEVELLING_UP;
				}

				if (state == State::PLAYING)
				{
					// Gameplay event logic
				}
				#pragma endregion

				#pragma region Movement Handling
				if (state == State::PLAYING) {
					/*Start moving the player and stop when the key is releced*/
					#pragma region Up
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) { player.moveUp(); }
					else { player.stopUp(); }
					#pragma endregion

					#pragma region Down
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) { player.moveDown(); }
					else { player.stopDown(); }
					#pragma endregion

					#pragma region Left
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) { player.moveLeft(); }
					else { player.stopLeft(); }
					#pragma endregion

					#pragma region Right
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) { player.moveRight(); }
					else { player.stopRight(); }
					#pragma endregion
				}
				#pragma endregion

				#pragma region Levelling Up
				if (state == State::LEVELLING_UP) {
					if (event.key.code == sf::Keyboard::Num1) {
						state = State::PLAYING;
					}
					if (event.key.code == sf::Keyboard::Num2) {
						state = State::PLAYING;
					}
					if (event.key.code == sf::Keyboard::Num3) {
						state = State::PLAYING;
					}
					if (event.key.code == sf::Keyboard::Num4) {
						state = State::PLAYING;
					}
					if (event.key.code == sf::Keyboard::Num5) {
						state = State::PLAYING;
					}
					if (event.key.code == sf::Keyboard::Num6) {
						state = State::PLAYING;
					}
				}
				#pragma endregion

				if (state == State::PLAYING)
				{
					#pragma region Arena Size
					/*Setting up the size of the play space*/
					arena.width = 500;
					arena.height = 500;
					arena.left = 0;
					arena.top = 0;

					/*Tile Size*/
					int tileSize = createBackground(bg, arena);
					#pragma endregion

					#pragma region Spawning Player
					player.spawn(arena, desktopRes, tileSize);

					clock.restart();
					#pragma endregion
				}
			}

			#pragma region Quit game
			//Handle game quitting
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
				window.close();
			}
			#pragma endregion

		}
		/*Update*/
		if (state == State::PLAYING) {
			/*Update the time*/
			sf::Time deltaTime = clock.restart();

			/*Update the total game time*/
			gameTimeTotal += deltaTime;

			/*Make time nice round number*/
			float dtAsSeconds = deltaTime.asSeconds();


			//Locate Mouse cursor
			mousePosition = sf::Mouse::getPosition();

			/*Convert mouse location to Coordinates*/
			mouseWorldPosition = window.mapPixelToCoords(sf::Mouse::getPosition(), mainView);


			/*Update The player*/
			player.update(dtAsSeconds, sf::Mouse::getPosition());

			sf::Vector2f playerPosition(player.getCenter());

			/*Make View center to player*/
			mainView.setCenter(player.getCenter());
		}
		/*Drawing the scene*/
		if (state == State::PLAYING) {
			window.clear();
			window.setView(mainView);
			window.draw(bg, &tBackground);
			window.draw(player.getSprite());
		}
		if (state == State::LEVELLING_UP)
		{

		}
		if (state == State::PAUSED)
		{

		}
		if (state == State::GAME_OVER)
		{

		}
		window.display();
	}
	return 0;
}