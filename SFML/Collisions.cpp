#include "Collisions.h"


Collisions::Collisions()
{
	collisionRectsDrawing = false;
}


Collisions::~Collisions()
{
}


bool Collisions::checkCollision(Vector2i position1, vector<IntRect>* collisionRects1, Vector2i position2, vector<IntRect>* collisionRects2, RenderWindow &w)
{
	IntRect A, B;
	bool returnVal = false;
	for (int i = 0; i < (signed)collisionRects1->size(); i++)
	{
		A = IntRect(position1.x + collisionRects1->at(i).left, position1.y + collisionRects1->at(i).top,
			collisionRects1->at(i).width, collisionRects1->at(i).height);

		for (int j = 0; j < (signed)collisionRects2->size(); j++)
		{
			B = IntRect(position2.x + collisionRects2->at(j).left, position2.y + collisionRects2->at(j).top,
								collisionRects2->at(j).width, collisionRects2->at(j).height);

			if (A.left >= B.left && A.left <= B.left + B.width && A.top >= B.top && A.top <= B.top + B.height)
				returnVal = true;
			else if (A.left >= B.left && A.left <= B.left + B.width && A.top + A.height >= B.top && A.top + A.height <= B.top + B.height)
				returnVal = true;
			else if (A.left + A.width >= B.left && A.left + A.width <= B.left + B.width && A.top >= B.top && A.top <= B.top + B.height)
				returnVal = true;
			else if (A.left + A.width >= B.left && A.left + A.width <= B.left + B.width && A.top + A.height >= B.top && A.top + A.height <= B.top + B.height)
				returnVal = true;

			if (returnVal)
				drawCollisionRects(B, w, Color::Yellow);
			else
				drawCollisionRects(B, w, Color::White);
		}
		if (returnVal)
			drawCollisionRects(A, w, Color::Yellow);
		else
			drawCollisionRects(A, w, Color::White);
	}
	return returnVal;
}

void Collisions::drawCollisionRects(IntRect rect, RenderWindow &w, Color c)
{
	if (collisionRectsDrawing)
	{
		RectangleShape up, down, left, right;

		up.setSize(Vector2f(Vector2i(rect.width, 1)));
		left.setSize(Vector2f(Vector2i(1, rect.height)));
		down = up;
		right = left;

		up.setFillColor(c);
		down.setFillColor(c);
		left.setFillColor(c);
		right.setFillColor(c);

		up.setPosition((float)rect.left, (float)rect.top);
		down.setPosition((float)rect.left, (float)rect.top + (float)rect.height);
		left.setPosition((float)rect.left, (float)rect.top);
		right.setPosition((float)rect.left + (float)rect.width, (float)rect.top);

		w.draw(up);
		w.draw(down);
		w.draw(left);
		w.draw(right);
	}
}

void Collisions::changeCollisionRectsDrawing()
{
	collisionRectsDrawing = !collisionRectsDrawing;
}