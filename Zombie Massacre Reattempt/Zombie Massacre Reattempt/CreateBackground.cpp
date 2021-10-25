#include "ZombieArena.h"

int createBackground(sf::VertexArray& rVa, sf::IntRect arena)
{
	// Anything we do to the rVa we are really doing it to the background

	// How big is each tile?
	const int TILE_SIZE = 50;
	const int TILE_TYPES = 3;
	const int VERTS_IN_QUAD = 4;

	int worldWidth = arena.width / TILE_SIZE;
	int worldHeight = arena.height / TILE_SIZE;

	// What type of primitive shape are we using?
	rVa.setPrimitiveType(sf::Quads);

	// Set the size of the vertex array
	rVa.resize(worldWidth * worldHeight * VERTS_IN_QUAD);

	// Start at the beginning of the VA
	int curVertex = 0;

	for (int w = 0; w < worldWidth; w++)
	{
		for (int h = 0; h < worldHeight; h++)
		{
			// Position each vertex in the current quad
			rVa[curVertex + 0].position =
				sf::Vector2f(w * TILE_SIZE, h * TILE_SIZE);

			rVa[curVertex + 1].position =
				sf::Vector2f((w * TILE_SIZE) + TILE_SIZE, h * TILE_SIZE);

			rVa[curVertex + 2].position =
				sf::Vector2f((w * TILE_SIZE) + TILE_SIZE, (h * TILE_SIZE) + TILE_SIZE);

			rVa[curVertex + 3].position =
				sf::Vector2f((w * TILE_SIZE), (h * TILE_SIZE) + TILE_SIZE);

			// Set the position in the Texture for the current quad
			if (h == 0 || h == worldHeight - 1 || w == 0 || w == worldWidth - 1)
			{
				// Use the wall texture
				rVa[curVertex + 0].texCoords =
					sf::Vector2f(0, 0 + TILE_TYPES * TILE_SIZE);

				rVa[curVertex + 1].texCoords =
					sf::Vector2f(TILE_SIZE, 0 + TILE_TYPES * TILE_SIZE);

				rVa[curVertex + 2].texCoords =
					sf::Vector2f(TILE_SIZE, TILE_SIZE + TILE_TYPES * TILE_SIZE);

				rVa[curVertex + 3].texCoords =
					sf::Vector2f(0, TILE_SIZE + TILE_TYPES * TILE_SIZE);
			}
			else
			{
				srand((int)time(0) + h * w - h);
				int mOrg = (rand() % TILE_TYPES);
				int verticalOffset = mOrg * TILE_SIZE;

				rVa[curVertex + 0].texCoords = sf::Vector2f(0, 0 + verticalOffset);
				rVa[curVertex + 1].texCoords = sf::Vector2f(TILE_SIZE, 0 + verticalOffset);
				rVa[curVertex + 2].texCoords = sf::Vector2f(TILE_SIZE, TILE_SIZE + verticalOffset);
				rVa[curVertex + 3].texCoords = sf::Vector2f(0, TILE_SIZE + verticalOffset);
			}

			// Position ready for the next four vertices
			curVertex = curVertex + VERTS_IN_QUAD;
		}
	}

	return TILE_SIZE;
}