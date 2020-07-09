#pragma once
#include "scene.h"
#include "mesh.h"
#include "texture.h"
#include <string>
#include "gameobjectmesh.h"
#include "gameobjectskybox.h"
#include "gameobjectenemy.h"
#include "gameobjectplayer.h"


class SceneParser{
public:

	//overwritten virtual functions
	void SceneParser::parseFile(std::string path, Scene* s);

	SceneParser();
	~SceneParser();
};