#pragma once
#include "gameobjectmesh.h"
#include "mesh.h"
#include "texture.h"
#include <string>


class GameObjectPlayer : public GameObjectMesh {
public:
	GameObjectPlayer();
	GameObjectPlayer(std::string nameObject, std::string nameMesh, std::string nameTexture, std::string nameShader);

	//Attributes of this class
	/*Mesh* mesh;
	Texture* texture;
	Shader* shader;
	Vector3 color;*/
		
	//overwritten virtual functions
	void render();
	void update(float dt);

	//funcions del moviment
	void roll(float s, float dt);
	void pitch(float s, float dt);
	void accelerate(int sentit);
};