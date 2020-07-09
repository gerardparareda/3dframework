#include "resourcemanager.h"


ResourceManager::ResourceManager(void)
{
}


ResourceManager::~ResourceManager(void)
{
}

//load a mesh into memory, and associate it with a handle
void ResourceManager::loadMesh(const std::string handle,
 const std::string path)
{
	Mesh *mesh = new Mesh();
	mesh->loadASE(path.c_str());
	m_meshes[handle] = mesh;
}

//load a texture into memory, and associate it with a handle
void ResourceManager::loadTexture(const std::string handle,
 const std::string path)
{
	Texture *texture = new Texture();
	texture->load(path.c_str());
	m_textures[handle] = texture;
}

//load a shader into memory, and associate it with a handle
void ResourceManager::loadShader(const std::string handle,
 const std::string path, const std::string path2)
{
	
	Shader* shader = new Shader();
	if(!shader->load(path.c_str(), path2.c_str())){
		std::cout << "error: shader " << path << " not found" << std::endl;
	}		
	m_shaders[handle] = shader;
}


//unload a mesh from memory, given its handle
void ResourceManager::unloadMesh(const std::string handle) {
	//try to find mesh in map
	std::unordered_map<std::string, Mesh*>::iterator itr = m_meshes.find(handle);
	//check it's there
	if (itr != m_meshes.end()){
		// found it - delete it and erase it
		delete itr->second;
		m_meshes.erase(itr);
	}
	else //else print error and quit
	{
		std::cout << "could not find asset with handle" << handle << std::endl;
		exit(0);
	}
}

//Return a pointer to a mesh object, given a handle
Mesh* ResourceManager::getMesh(const std::string name) {
	//...you should probably add some error checking here...!
	return m_meshes.at(name);
}


//Return a pointer to a shader object, given a handle
Shader* ResourceManager::getShader(const std::string name) {
	//...you should probably add some error checking here...!
	return m_shaders.at(name);
}

//Return a pointer to a texture object, given a handle
Texture* ResourceManager::getTexture(const std::string name) {
	//...you should probably add some error checking here...!
	return m_textures.at(name);
}


//Returns true if the desired resource exists
//
//bool ResourceManager::existMesh(const std::string nom) {
//
//	std::unordered_map<std::string, Mesh*>::iterator itr = m_meshes.find(nom.c_str());
//	if (itr != m_meshes.end()) {
//		return true;
//		std::cout << "omitit " << nom << std::endl;
//	}
//	else {
//		return false;
//	}
//
//}
//
//bool ResourceManager::existTexture(const std::string nom) {
//
//	std::unordered_map<std::string, Texture*>::iterator itr = m_textures.find(nom.c_str());
//	if (itr != m_textures.end()) {
//		return true;
//		std::cout << "omitit " << nom << std::endl;
//	}
//	else {
//		return false;
//	}
//
//}
//bool ResourceManager::existShader(const std::string nom) {
//
//	std::unordered_map<std::string, Shader*>::iterator itr = m_shaders.find(nom.c_str());
//	if (itr != m_shaders.end()) {
//		return true;
//		std::cout << "omitit " << nom << std::endl;
//	}
//	else {
//		return false;
//	}
//
//
//
//}
