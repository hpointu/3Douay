#ifndef GRID_HPP
#define GRID_HPP

#include "Plane.hpp"

class Grid : public Plane
{
public:
	Grid(int line, int col, float step);
	virtual void render(aiMatrix4x4 trans);

private:
	int line, col;
	float step;
};

#endif // GRID_HPP
