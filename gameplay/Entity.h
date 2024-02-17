#pragma once

#include "Camera.h"
#include "Renderer.h"

namespace goof {

	class Entity {
	public:
		goof::Camera follow_camera;

		glm::vec3 entity_position = glm::vec3(0.0f,0.0f,0.0f);
		glm::vec3 entity_position_init;
		glm::vec3 size;

	public:
		Entity();
		~Entity();
		
	};

	class character2d : public Entity {

		gf_render::Rect player_sprite;

	public:

		character2d();
		~character2d();

		character2d(float x, float y, float z);
		void update_pos(float x, float y, float z, Shader& shader);
	};

	class character3d : public Entity {

		gf_render::Cube player_sprite;

	public:
		character3d();
		~character3d();

		void update_pos(float x, float y, float z, Shader& shader);
	};
}