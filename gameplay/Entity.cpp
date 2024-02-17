#include "Entity.h"

goof::Entity::~Entity()
{
}


goof::Entity::Entity() : size(glm::vec3(50.f)) ,entity_position_init(glm::vec3(0.f))
{
}

goof::Entity::Entity(float x, float y, float z) : size(glm::vec3(50.f))
{
	entity_position_init = glm::vec3(x, y, z);
}

void goof::Entity::update_pos(float x, float y, float z, Shader& sha)
{
	entity_position = glm::vec3(x, y, z);
	follow_camera.camera_Pos = entity_position ;

	gf_render::Draw(player_sprite, goof::BLUE, entity_position + entity_position_init, sha, size);
	sha.setMat4("view", follow_camera.follow_lookAt());
}

