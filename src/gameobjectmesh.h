#pragma once
#include "gameobject.h"
#include "mesh.h"
#include "texture.h"
#include <string>
#include "coldet/coldet.h"


class GameObjectMesh : public GameObject {
public:
	GameObjectMesh();
	GameObjectMesh(std::string nameObject, std::string nameMesh, std::string nameTexture, std::string nameShader);
	//~GameObjectMesh();

	//Attributes of this class
	Mesh* mesh;
	Texture* texture;
	Shader* shader;
	Vector3 color;
	bool isCollide;
		
	//overwritten virtual functions
	void render();
	void update(float dt);

};