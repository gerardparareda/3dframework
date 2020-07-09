
#include "scene.h"
#include "game.h"

Scene::Scene(){

	Game* g = Game::instance;

	this->root = new GameObject();

	//create our camera
	camera = new Camera();	//declarada al game.h i instanciada aquí
	camera->lookAt(Vector3(0,25,25),Vector3(0,0,0), Vector3(0,1,0)); //position the camera and point to 0,0,0
	camera->setPerspective(70.0f,(float)g->window_width/(float)g->window_height,0.1f,10000.0f); //set the projection, we want to be perspective


}

Scene::~Scene() {
	this->root->clear();
	delete this->root;
}

//standard render and update functions
void Scene::render(){
	
	//update view and projection matrices, and push gl matrices for fixed pipeline rendering
	camera->set();

	this->root->render();
}

void Scene::update(float seconds_elapsed){
	
	this->root->update(seconds_elapsed);
}