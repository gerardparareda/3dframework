#pragma once
#include "gameobjectmesh.h"
#include "mesh.h"
#include "texture.h"
#include <string>


class GameObjectEnemy : public GameObjectMesh {
public:
	GameObjectEnemy();
	GameObjectEnemy(std::string nameObject, std::string nameMesh, std::string nameTexture, std::string nameShader);

	//Attributes of this class
	/*Mesh* mesh;
	Texture* texture;
	Shader* shader;
	Vector3 color;*/
	std::vector<Vector3> waypoints;
	int currentWaypoint;
		
	//overwritten virtual functions
	void render();
	void update(float dt);
	void addWaypoint(Vector3 waypoint);
	void goToWaypoint(float dt);
	void chooseWaypoint(int obj);
};