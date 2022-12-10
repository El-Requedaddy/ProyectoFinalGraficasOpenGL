#include "Cubo.h"

Cubo::Cubo() {


}

Cubo::~Cubo() {

}

void Cubo::visualizar() {
	glPushMatrix();
	//GLfloat vertices[][3] = { {1,1,1}, {-1,1,1}, {-1,-1,1}, {1,-1,1},{-1,-1,-1},{1,-1,-1},{-1,1,-1},{1,1,-1} };
	//GLubyte indices[] = { 1,2,3,1,3,0,2,4,5,2,5,3,4,6,7,4,7,5,6,4,2,6,2,1,6,1,0,6,0,7,0,3,5,0,5,7 };
	
	GLfloat vertices[] = { 1, 1, 1,  -1, 1, 1,  -1,-1, 1,   1,-1, 1,   // v0,v1,v2,v3 (front)
					   1, 1, 1,   1,-1, 1,   1,-1,-1,   1, 1,-1,   // v0,v3,v4,v5 (right)
					   1, 1, 1,   1, 1,-1,  -1, 1,-1,  -1, 1, 1,   // v0,v5,v6,v1 (top)
					  -1, 1, 1,  -1, 1,-1,  -1,-1,-1,  -1,-1, 1,   // v1,v6,v7,v2 (left)
					  -1,-1,-1,   1,-1,-1,   1,-1, 1,  -1,-1, 1,   // v7,v4,v3,v2 (bottom)
					   1,-1,-1,  -1,-1,-1,  -1, 1,-1,   1, 1,-1 }; // v4,v7,v6,v5 (back)

// normal array
	GLfloat normals[] = { 0, 0, 1,   0, 0, 1,   0, 0, 1,   0, 0, 1,   // v0,v1,v2,v3 (front)
					   1, 0, 0,   1, 0, 0,   1, 0, 0,   1, 0, 0,   // v0,v3,v4,v5 (right)
					   0, 1, 0,   0, 1, 0,   0, 1, 0,   0, 1, 0,   // v0,v5,v6,v1 (top)
					  -1, 0, 0,  -1, 0, 0,  -1, 0, 0,  -1, 0, 0,   // v1,v6,v7,v2 (left)
					   0,-1, 0,   0,-1, 0,   0,-1, 0,   0,-1, 0,   // v7,v4,v3,v2 (bottom)
					   0, 0,-1,   0, 0,-1,   0, 0,-1,   0, 0,-1 }; // v4,v7,v6,v5 (back)

	// texCoord array
	GLfloat texCoords[] = { 1, 0,   0, 0,   0, 1,   1, 1,             // v0,v1,v2,v3 (front)
							 0, 0,   0, 1,   1, 1,   1, 0,             // v0,v3,v4,v5 (right)
							 1, 1,   1, 0,   0, 0,   0, 1,             // v0,v5,v6,v1 (top)
							 1, 0,   0, 0,   0, 1,   1, 1,             // v1,v6,v7,v2 (left)
							 0, 1,   1, 1,   1, 0,   0, 0,             // v7,v4,v3,v2 (bottom)
							 0, 1,   1, 1,   1, 0,   0, 0, };          // v4,v7,v6,v5 (back)

	// index array of vertex array for glDrawElements() & glDrawRangeElement()
	GLubyte indices[] = { 0, 1, 2,   2, 3, 0,      // front
						   4, 5, 6,   6, 7, 4,      // right
						   8, 9,10,  10,11, 8,      // top
						  12,13,14,  14,15,12,      // left
						  16,17,18,  18,19,16,      // bottom
						  20,21,22,  22,23,20 };    // back




	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);

	glVertexPointer(3, GL_FLOAT, 0, vertices);
	glNormalPointer(GL_FLOAT, 0, normals);
	glTexCoordPointer(2, GL_FLOAT, 0, texCoords);
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_BYTE, indices);

	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_NORMAL_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);

	glPopMatrix();

}