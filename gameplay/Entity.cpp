#include "Entity.h"

goof::Entity::~Entity()
{
}


goof::Entity::Entity() : size(glm::vec3(50.f)) ,entity_position_init(glm::vec3(0.f))
{
}

void goof::character2d::update_pos(float x, float y, float z, Shader& sha)
{
	entity_position = glm::vec3(x, y, z);
	follow_camera.camera_Pos =  glm::vec3(entity_position.x, entity_position.y , entity_position.z - 1.f);

	gf_render::Draw(player_sprite, goof::BLUE, entity_position + entity_position_init, sha, size);
	sha.setMat4("view", follow_camera.follow_lookAt());
}

goof::character2d::character2d()
{
}

goof::character2d::~character2d()
{
}

goof::character2d::character2d(float x, float y, float z) 
{
	size = glm::vec3(50.f);
	entity_position_init = glm::vec3(x, y, z);
}

goof::character3d::character3d()
{
}

goof::character3d::~character3d()
{
}

void goof::character3d::update_pos(float x, float y, float z, Shader& sha)
{
	entity_position = glm::vec3(x, y, z);
	follow_camera.camera_Pos = glm::vec3(entity_position.x, entity_position.y, entity_position.z);

	gf_render::Draw(player_sprite, goof::BLUE, entity_position , sha, size);
	sha.setMat4("view", follow_camera.follow_lookAt());
}
