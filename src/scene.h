#pragma once


#include "gameobject.h"
#include "camera.h"

class Scene
{
public:
	Scene();
	~Scene();

	//Name of this scene
	std::string name;

	//scene graph starts from here
	GameObject* root;
	
	//optional - you can choose whether to put the camera in Scene
	//or leave it in game
	Camera* camera;

	//a list of all lights - could be within graph or not
	//std::vector<GameObjectLight*> lights;
	//standard render and update functions
	void render();
	void update(float seconds_elapsed);
};