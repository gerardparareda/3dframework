#pragma once
#include <iostream>
#include <string>
#include "framework.h"

class GameObject
{
public:
	//some attributes
	std::string name;
	Matrix44 model;

	GameObject* parent;
	std::vector<GameObject*> children;

	//virtual methods which will be overwritten
	virtual void render();
	virtual void update(float elapsed_time);

	void addChild(GameObject* obj);
	void removeChild(GameObject* obj);
	GameObject* lookInChilds(std::string);
	void GameObject::checkColisions();
	std::vector<GameObject*> GameObject::returnAllCollidableChilds();
	void clear();

	Matrix44 getGlobalMatrix();

	GameObject();
};