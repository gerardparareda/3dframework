#pragma once
#include <iostream>
#include "mesh.h"
#include "texture.h"
#include "shader.h"
#include <unordered_map>


class ResourceManager
{
private:
	//maps for storing handles to pointers to asset objects
	std::unordered_map<std::string, Mesh*> m_meshes;
	std::unordered_map<std::string, Texture*> m_textures;
	std::unordered_map<std::string, Shader*> m_shaders;

public:
	ResourceManager(void);
	~ResourceManager(void);

	//load assets into memory
	void loadMesh(const std::string, const std::string);
	void loadTexture(const std::string, const std::string);
	void loadShader(const std::string, const std::string, const std::string);

	//unload assets out of memory
	void unloadMesh(const std::string);
	void unloadTexture(const std::string);
	void unloadShader(const std::string);

	//getters for individual assets
	Mesh* getMesh(const std::string);
	Texture* getTexture(const std::string);
	Shader* getShader(const std::string);

	//bool existMesh(const std::string nom);
	//bool existTexture(const std::string nom);
	//bool existShader(const std::string nom);

};

