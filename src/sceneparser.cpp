#include "sceneparser.h"

#include "game.h"
#include "extra/textparser.h"
#include <algorithm>

/**
/* TODO: Mirar si existeixen els fitxers abans d'intentar carregar-los (peta el programa si no existeixen)
/* i mirar si cal passar a minúscula els noms dels resources dels objectes (probablement sí), ex:
/* nomObjecte: teapot_001 funciona igual que nomObjecte: TEAPOT_001 (troba un objecte amb aquest nom? probablement no)
**/

//overwritten virtual functions
void SceneParser::parseFile(std::string path, Scene* s){
	Game* g = Game::instance;
	TextParser t;
	
	//Obrir fitxer
	if (t.create(path.c_str()) == false) {
		std::cout << "Could not open file" << std::endl;
	}

	//Llegir el nom de l'escena
	t.seek("*SCENE_NAME");
	std::string nomEscena(t.getword());
	s->name = nomEscena;

	//Llegir quants resources necessitem
	t.seek("*RESOURCES");
	int resources = t.getint();

	//Carreguem els resources al resource manager
	for(int i = 0; i < resources; i++){
		t.seek("*RESOURCE");
		std::string type_resource(t.getword());

		if(type_resource == "MESH"){
			t.seek("*NAME");
			std::string nomResource(t.getword());
			std::transform(nomResource.begin(), nomResource.end(), nomResource.begin(), ::tolower);
			
			t.seek("*PATH");
			std::string pathResource(t.getword());
			std::transform(pathResource.begin(), pathResource.end(), pathResource.begin(), ::tolower);
	
			g->resource_manager->loadMesh(nomResource, pathResource);
		}

		if(type_resource == "TEXTURE"){
			t.seek("*NAME");
			std::string nomResource(t.getword());
			std::transform(nomResource.begin(), nomResource.end(), nomResource.begin(), ::tolower);

			t.seek("*PATH");
			std::string pathResource(t.getword());
			std::transform(pathResource.begin(), pathResource.end(), pathResource.begin(), ::tolower);

			std::cout << nomResource << " " << pathResource << std::endl;

			g->resource_manager->loadTexture(nomResource, pathResource);
		}

		if(type_resource == "SHADER"){
			t.seek("*NAME");
			std::string nomResource(t.getword());
			std::transform(nomResource.begin(), nomResource.end(), nomResource.begin(), ::tolower);
			
			t.seek("*PATH");
			std::string pathResource(t.getword());
			std::transform(pathResource.begin(), pathResource.end(), pathResource.begin(), ::tolower);
			std::string pathResource2(t.getword());
			std::transform(pathResource2.begin(), pathResource2.end(), pathResource2.begin(), ::tolower);

			g->resource_manager->loadShader(nomResource, pathResource, pathResource2);
		}
	}

	std::cout << "loading resources done" << std::endl;

	//Llegir quants objectes necessitem
	t.seek("*OBJECTS");
	int objects = t.getint();

	//Carreguem els Game Objects Meshes
	for(int i = 0; i < objects; i++){
		t.seek("*OBJECT");
		std::string type_object(t.getword());

		if(type_object == "GAMEOBJECTMESH"){
			t.seek("*NAME");
			std::string nomObjecte(t.getword());
			std::transform(nomObjecte.begin(), nomObjecte.end(), nomObjecte.begin(), ::tolower);

			t.seek("*MESH");
			std::string nomMesh(t.getword());
			std::transform(nomMesh.begin(), nomMesh.end(), nomMesh.begin(), ::tolower);

			t.seek("*SHADER");
			std::string nomShader(t.getword());
			std::transform(nomShader.begin(), nomShader.end(), nomShader.begin(), ::tolower);

			t.seek("*TEXTURE");
			std::string nomTexture(t.getword());
			std::transform(nomTexture.begin(), nomTexture.end(), nomTexture.begin(), ::tolower);

			t.seek("*POSITION");
			float px = t.getfloat();
			float py = t.getfloat();
			float pz = t.getfloat();

			t.seek("*ROTATION");
			float rx = t.getfloat();
			float ry = t.getfloat();
			float rz = t.getfloat();

			t.seek("*SCALE");
			float sx = t.getfloat();
			float sy = t.getfloat();
			float sz = t.getfloat();

			GameObjectMesh* tmp = new GameObjectMesh(nomObjecte, nomMesh, nomTexture, nomShader);
			tmp->model.setScale(sx, sy, sz);
			tmp->model.traslate(px, py, pz);
			tmp->model.rotateVector(Vector3(rx, ry, rz));

			t.seek("*PARENT");
			std::string nomparent(t.getword());
			std::transform(nomparent.begin(), nomparent.end(), nomparent.begin(), ::tolower);
			std::cout << "nom pare: " << nomparent << " nom fill: " << nomObjecte << std::endl;

			t.seek("*COLLISION");
			std::string teColisio(t.getword());
			if (teColisio == "YES") {
				tmp->isCollide = true;
				tmp->mesh->setCollisionModel();
			} else {
				tmp->isCollide = false;
			}

			if(nomparent == "root"){
				s->root->addChild(tmp);
			}else{
				GameObject* pepe = s->root->lookInChilds(nomparent);
				pepe->addChild(tmp);
			}

		}
		if(type_object == "GAMEOBJECTSKYBOX"){
			t.seek("*NAME");
			std::string nomObjecte(t.getword());
			std::transform(nomObjecte.begin(), nomObjecte.end(), nomObjecte.begin(), ::tolower);

			t.seek("*MESH");
			std::string nomMesh(t.getword());
			std::transform(nomMesh.begin(), nomMesh.end(), nomMesh.begin(), ::tolower);

			t.seek("*SHADER");
			std::string nomShader(t.getword());
			std::transform(nomShader.begin(), nomShader.end(), nomShader.begin(), ::tolower);

			t.seek("*TEXTURE");
			std::string nomTexture(t.getword());
			std::transform(nomTexture.begin(), nomTexture.end(), nomTexture.begin(), ::tolower);

			t.seek("*POSITION");
			float px = t.getfloat();
			float py = t.getfloat();
			float pz = t.getfloat();

			t.seek("*ROTATION");
			float rx = t.getfloat();
			float ry = t.getfloat();
			float rz = t.getfloat();

			t.seek("*SCALE");
			float sx = t.getfloat();
			float sy = t.getfloat();
			float sz = t.getfloat();

			GameObjectSkybox* tmp = new GameObjectSkybox(nomObjecte, nomMesh, nomTexture, nomShader);
			tmp->model.scale(sx, sy, sz);
			tmp->model.traslate(px, py, pz);
			tmp->model.rotateVector(Vector3(rx, ry, rz));
			
			s->root->addChild(tmp);
		}

		if(type_object == "GAMEOBJECTENEMY"){
			t.seek("*NAME");
			std::string nomObjecte(t.getword());
			std::transform(nomObjecte.begin(), nomObjecte.end(), nomObjecte.begin(), ::tolower);

			t.seek("*MESH");
			std::string nomMesh(t.getword());
			std::transform(nomMesh.begin(), nomMesh.end(), nomMesh.begin(), ::tolower);

			t.seek("*SHADER");
			std::string nomShader(t.getword());
			std::transform(nomShader.begin(), nomShader.end(), nomShader.begin(), ::tolower);

			t.seek("*TEXTURE");
			std::string nomTexture(t.getword());
			std::transform(nomTexture.begin(), nomTexture.end(), nomTexture.begin(), ::tolower);

			t.seek("*POSITION");
			float px = t.getfloat();
			float py = t.getfloat();
			float pz = t.getfloat();

			t.seek("*ROTATION");
			float rx = t.getfloat();
			float ry = t.getfloat();
			float rz = t.getfloat();

			t.seek("*SCALE");
			float sx = t.getfloat();
			float sy = t.getfloat();
			float sz = t.getfloat();

			t.seek("*PARENT");
			std::string nomparent(t.getword());
			std::transform(nomparent.begin(), nomparent.end(), nomparent.begin(), ::tolower);

			GameObjectEnemy* tmp = new GameObjectEnemy(nomObjecte, nomMesh, nomTexture, nomShader);
			tmp->model.scale(sx, sy, sz);
			tmp->model.traslate(px, py, pz);
			tmp->model.rotateVector(Vector3(rx, ry, rz));

			t.seek("*COLLISION");
			std::string teColisio(t.getword());
			if (teColisio == "YES") {
				tmp->isCollide = true;
				tmp->mesh->setCollisionModel();
			}
			else {
				tmp->isCollide = false;
			}

			t.seek("*NUMWAYPOINTS");
			int waypoints = t.getint();
			Vector3 tmpWaypoint;

			for(int j = 0; j < waypoints; j++){
				t.seek("*WAYPOINT");
				float wx = t.getfloat();
				float wy = t.getfloat();
				float wz = t.getfloat();
				tmpWaypoint = Vector3(wx, wy, wz);
				
				tmp->addWaypoint(tmpWaypoint);
			}

			//std::cout <<"tipus: " << typeid(tmp).name() << " nom: " << nomObjecte << std::endl;

			if(nomparent == "root"){
				s->root->addChild(tmp);
			}else{
				GameObject* pepe = s->root->lookInChilds(nomparent);
				pepe->addChild(tmp);
			}
		}

		if(type_object == "GAMEOBJECTPLAYER"){
			t.seek("*NAME");
			std::string nomObjecte(t.getword());
			std::transform(nomObjecte.begin(), nomObjecte.end(), nomObjecte.begin(), ::tolower);

			t.seek("*MESH");
			std::string nomMesh(t.getword());
			std::transform(nomMesh.begin(), nomMesh.end(), nomMesh.begin(), ::tolower);

			t.seek("*SHADER");
			std::string nomShader(t.getword());
			std::transform(nomShader.begin(), nomShader.end(), nomShader.begin(), ::tolower);

			t.seek("*TEXTURE");
			std::string nomTexture(t.getword());
			std::transform(nomTexture.begin(), nomTexture.end(), nomTexture.begin(), ::tolower);

			t.seek("*POSITION");
			float px = t.getfloat();
			float py = t.getfloat();
			float pz = t.getfloat();

			t.seek("*ROTATION");
			float rx = t.getfloat();
			float ry = t.getfloat();
			float rz = t.getfloat();

			t.seek("*SCALE");
			float sx = t.getfloat();
			float sy = t.getfloat();
			float sz = t.getfloat();

			t.seek("*PARENT");
			std::string nomparent(t.getword());
			std::transform(nomparent.begin(), nomparent.end(), nomparent.begin(), ::tolower);

			GameObjectPlayer* tmp = new GameObjectPlayer(nomObjecte, nomMesh, nomTexture, nomShader);
			tmp->model.scale(sx, sy, sz);
			tmp->model.traslate(px, py, pz);
			tmp->model.rotateVector(Vector3(rx, ry, rz));

			t.seek("*COLLISION");
			std::string teColisio(t.getword());
			if (teColisio == "YES") {
				tmp->isCollide = true;
				tmp->mesh->setCollisionModel();
			}
			else {
				tmp->isCollide = false;
			}

			s->camera->tofollow = tmp;

			//std::cout <<"tipus: " << typeid(tmp).name() << " nom: " << g->scene->camera->tofollow->name << std::endl;

			if(nomparent == "root"){
				s->root->addChild(tmp);
			}else{
				GameObject* pepe = s->root->lookInChilds(nomparent);
				pepe->addChild(tmp);
			}
		}

	}

	std::cout << "creating game objects done for level " << s->name << std::endl;
}

SceneParser::SceneParser() {
}

SceneParser::~SceneParser() {
}