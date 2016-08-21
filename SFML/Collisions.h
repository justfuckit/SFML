#pragma once
#include <SFML\Graphics.hpp>

using namespace sf;
using namespace std;

class Collisions
{
public:
	Collisions();
	~Collisions();
	bool checkCollision(Vector2i position1, vector<IntRect>* collisionRect1, Vector2i position2, vector<IntRect>* collisionRect2, RenderWindow &w);
	void changeCollisionRectsDrawing();
private:
	void drawCollisionRects(IntRect rect, RenderWindow &w, Color c);
	bool collisionRectsDrawing;
};

