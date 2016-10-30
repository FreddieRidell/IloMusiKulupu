#pragma once

#include <vector>
#include <cassert>
#include <Core/Math/Cartesian/CartTwo.hpp>
#include <Core/Math/Cartesian/CartThree.hpp>
#include <Macros/generateGetAndSet.hpp>
#include <Core/idManager.hpp>

#define GLEW_STATIC
#include <GL/glew.h>

#include <SDL.h>
#include <SDL_opengl.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace render{
class Mesh;
class Engine;
}

#include "./engine.hpp"

namespace render {

typedef struct Face{
	GLuint first;
	GLuint second;
	GLuint third;
} Face;

typedef core::math::cartesian::CartThree<GLfloat> point;

class Mesh{
private:
	Engine* engine;
	std::vector<
		core::math::cartesian::CartThree<>
	> positions_;

	std::vector<
		core::math::cartesian::CartThree<>
	> colors_;

	std::vector<
		core::math::cartesian::CartThree<>
	> normals_;

	std::vector<
		Face
	> faces_;

	core::ID program_;
	GLuint programToken_;

	GLuint vbos[3];
	GLuint vao;
	GLuint ebo;

	point position_;
	point rotation_;
	point scale_;

	glm::mat4 modelMatrix;
	glm::mat4 mvpMatrix;

	void loadPositions();
	void loadColors();
	void loadFaces();

	void calculateMVP();

public:
	Mesh();

	GENERATE_GETTERS_AND_SETTERS(positions);
	GENERATE_GETTERS_AND_SETTERS(colors);
	GENERATE_GETTERS_AND_SETTERS(normals);
	GENERATE_GETTERS_AND_SETTERS(faces);
	GENERATE_GETTERS_AND_SETTERS(program);

	GENERATE_GETTERS_AND_SETTERS(position);
	GENERATE_GETTERS_AND_SETTERS(rotation);
	GENERATE_GETTERS_AND_SETTERS(scale);

	void reset();

	//std::size_t addVertex(
		//core::math::cartesian::CartThree<> position,
		//core::math::cartesian::CartThree<> color,
		//core::math::cartesian::CartThree<> normal
	//);

	//std::size_t addFace(Face f);

	void render();

};
} //render
