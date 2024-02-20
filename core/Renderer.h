#pragma once
#include "Shader.h"
#include "Texture.h"

namespace gf_render {

	static Shader nullShader;

	class shapes {

	protected:
		unsigned int VBO, VAO ,EBO = 0;
		int size_vertices = 0;

	public:
		shapes() = default;
		std::string name = "shape";

		std::vector<glm::vec3> loc_vec_shape;
		std::vector<glm::vec3>::iterator erase_iter;

		std::vector<glm::vec4> color_index;
		std::vector<glm::vec3> object_scale;

		inline unsigned int getVBO() { return VBO; };
		inline unsigned int getVAO() { return VAO; };
		inline unsigned int getEBO() { return EBO; };
		inline unsigned int getSize_Vertices() { return size_vertices; };
		inline void set_name(std::string name) { this->name = name; }
	};

	class Triangle : public shapes {
	public:
		std::string name = "Triangle";
		Triangle();
		~Triangle();
	};

	class Rect : public shapes {
	public:
		std::string name = "Rectangle";
		Rect();
		~Rect();
	};

	class Cube :public shapes {
	public:
		std::string name = "Cube";
		Cube();
		~Cube();
	};

	void Draw(shapes& tri , const float* COLOR = nullptr,
					glm::vec3 Postion = glm::vec3(0.0f,0.0f,0.0f),
					Shader& shader =nullShader,
					glm::vec3 Scale =glm::vec3(1.0f),goof::Texture2D* tex = nullptr);

	void ClearScreen();
	void setWireframeMode(bool set);
	
	
}