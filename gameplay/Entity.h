#pragma once

#include "Camera.h"
#include "Renderer.h"

namespace goof {

	class Entity {
	public:
		gf_render::Rect player_sprite;

		goof::Camera follow_camera;

		glm::vec3 entity_position = glm::vec3(0.0f,0.0f,0.0f);
		glm::vec3 entity_position_init;
		glm::vec3 size;

	public:
		Entity();
		~Entity();
		
	};

	class character2d : public Entity {

	public:
		character2d();
		~character2d();

		character2d(float x, float y, float z);
		void update_pos(float x, float y, float z, Shader& shader);
	};
}