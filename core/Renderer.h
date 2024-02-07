#pragma once
#include "Shader.h"

namespace gf_render {

	static Shader nullShader;
	class shapes {

	protected:
		unsigned int VBO, VAO ,EBO = 0;
		int size_vertices = 0;

	public:
		shapes() = default;
		inline unsigned int getVBO() { return VBO; };
		inline unsigned int getVAO() { return VAO; };
		inline unsigned int getEBO() { return EBO; };
		inline unsigned int getSize_Vertices() { return size_vertices; };
	};

	class Triangle : public shapes {
	public:
		Triangle();
		~Triangle();
	};

	class Rect : public shapes {
	public:
		Rect();
		~Rect();
	};

	class Cube :public shapes {
	public:
		Cube();
		~Cube();
	};

	void Draw(shapes& tri , const float COLOR[] = nullptr ,glm::vec3 Postion = glm::vec3(0.0f,0.0f,0.0f), Shader& shader = nullShader);
	void ClearScreen();
	void setWireframeMode(bool set);
}