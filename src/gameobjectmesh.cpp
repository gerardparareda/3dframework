#include "gameobjectmesh.h"
#include "game.h"

//Some globals

//overwritten virtual functions
void GameObjectMesh::render(){
	Game* g = Game::instance;
	//*** Drawing code starts here ***
   
	//create model matrix for our mesh

	//build a rotation matrix - angle is incremented in update()
	//m.rotate(angle * DEG2RAD, Vector3(0,1,0) ); 
	
	//create our mvp
	Matrix44 mvp = this->getGlobalMatrix() * g->activeScene->camera->viewprojection_matrix;

	//create normal matrix
	Matrix44 inverse_model = model;
	inverse_model.inverse();
	Matrix44 normal_m = inverse_model.transpose();

	//light position
	Vector3 light_pos(100.0f, 100.0f, 100.0f);

	//enable shader and set uniforms
	shader->enable();
	shader->setMatrix44("u_mvp", mvp);
	shader->setMatrix44("u_normal_matrix", normal_m);
	shader->setUniform3("u_light", light_pos);
	shader->setTexture("u_texture_diffuse", texture);

	//set the cullback
	glCullFace(GL_BACK);
   
	//mesh->render() binds the relevant attributes, and drawing code
	mesh->render(GL_TRIANGLES, shader);

	//disable the shader
	shader->disable();

	for(int i = 0; i < this->children.size(); i++){
		this->children[i]->render();
	}

}

void GameObjectMesh::update(float dt){
}

GameObjectMesh::GameObjectMesh() {
}

GameObjectMesh::GameObjectMesh(std::string nameObject, std::string nameMesh, std::string nameTexture, std::string nameShader){
	Game* g = Game::instance;
	name = nameObject;
	mesh = g->resource_manager->getMesh(nameMesh.c_str());
	texture = g->resource_manager->getTexture(nameTexture.c_str());
	shader = g->resource_manager->getShader(nameShader.c_str());
}
