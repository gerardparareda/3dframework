#pragma once
#include "gameobject.h"
#include "mesh.h"
#include "texture.h"
#include <string>


class GameObjectSkybox : public GameObject {
public:
	GameObjectSkybox();
	GameObjectSkybox(std::string nameObject, std::string nameMesh, std::string nameTexture, std::string nameShader);
	~GameObjectSkybox();

	//Attributes of this class
	Mesh* mesh;
	Texture* texture;
	Shader* shader;
	Vector3 color;
		
	//overwritten virtual functions
	void render();
	void update(float dt);
};