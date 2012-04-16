#include "Grid.hpp"

Grid::Grid(int line, int col, float step) :
	Plane(),
	line(line),
	col(col),
	step(step)
{
}

void Grid::render(aiMatrix4x4 trans)
{

	aiVector3D v;

	glBegin(GL_QUADS);
	for(int i=0; i<line; i++)
	{
		for(int j=0; i<col; i++)
		{
			v.x = j*step;
			v.y = i*step;
			v.z = -1;

			v *= trans;

			glVertex3d(v.x, v.y, v.z);
			glVertex3d(v.x, v.y, v.z);
			glVertex3d(v.x, v.y, v.z);
			glVertex3d(v.x, v.y, v.z);
		}
	}
	glEnd();

}
