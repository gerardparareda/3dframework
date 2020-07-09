#include "gameobjectplayer.h"
#include "game.h"

//Some globals
float throttle = 0.0;

//overwritten virtual functions
void GameObjectPlayer::render(){
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

void GameObjectPlayer::update(float dt){
	Vector3 f = this->model.frontVector().normalize();

	this->model.traslate(-f.x*dt*throttle, -f.y*dt*throttle, -f.z*dt*throttle);
	
	
}

void GameObjectPlayer::roll(float s, float dt){
	this->model.rotateLocal(s * 5.005 * dt, Vector3(0.0, 0.0, 1.0));
}

void GameObjectPlayer::pitch(float s, float dt){
	this->model.rotateLocal(s * 5.005 * dt, Vector3(1.0, 0.0, 0.0));

}

void GameObjectPlayer::accelerate(int sentit){
	if (sentit == 1){
		throttle += sentit * 0.1;
	} else if (throttle > 0){
		throttle += sentit * 0.1;
	} else if (throttle <= 0.1){
		throttle = 0;
	}
}

//void GameObjectPlayer::move(){
	

	

	////Vector3 myPos = Vector3(this->model.m[12], this->model.m[13], this->model.m[14]);
	//Vector3 to_target = waypoint - myPos;
	//Vector3 f = this->model.frontVector();
	//f = f * -1;
	//f.normalize();
	//to_target.normalize();
	//float angle = acos(to_target.dot(f));
	//Vector3 axis = to_target.cross(f);

	//



	//	Matrix44 inv = this->model;
	//	inv.inverse();
	//	Vector3 rot_axis = inv.rotateVector(axis);
	//	this->model.rotateLocal(0.05, rot_axis);
	//

	//double distance = (waypoint - myPos).length();
	//this->model.traslate(f.x * 0.4, f.y * 0.4, f.z * 0.4);

	//double distanceMoved = (myPos - Vector3(this->model.m[12], this->model.m[13], this->model.m[14])).length();

	//if (distanceMoved >= distance) {
	//	if(currentWaypoint == 3){
	//		currentWaypoint = 0;
	//	}else{
	//		currentWaypoint++;
	//	}
	//}
//}

GameObjectPlayer::GameObjectPlayer(){

};

GameObjectPlayer::GameObjectPlayer(std::string nameObject, std::string nameMesh, std::string nameTexture, std::string nameShader){
	Game* g = Game::instance;
	name = nameObject;
	mesh = g->resource_manager->getMesh(nameMesh.c_str());
	texture = g->resource_manager->getTexture(nameTexture.c_str());
	shader = g->resource_manager->getShader(nameShader.c_str());
}