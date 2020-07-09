/*  by Alun Evans 2016 LaSalle (alunthomasevasevans@gmail.com)
	based on framework by Javi Agenjo 2013 UPF  javi.agenjo@gmail.com
	This class encapsulates the game, is in charge of creating the game, getting the user input, process the update and render.
*/

#ifndef GAME_H
#define GAME_H

#include "includes.h"
#include "camera.h"
#include "resourcemanager.h"
#include "sceneparser.h"
#include "scene.h"

class Game
{
public:
	static Game* instance;

	//window
	SDL_Window* window;
	int window_width;
	int window_height;
    
    float time;

	//keyboard state
	const Uint8* keystate;

	//mouse state
	int mouse_state; //tells which buttons are pressed
	Vector2 mouse_position; //last mouse position
	Vector2 mouse_delta; //mouse movement in the last frame
	bool mouse_locked; //tells if the mouse is locked (not seen)
	
	ResourceManager* resource_manager;	//our resource manager
	SceneParser* scene_parser;	//our scene parser
	
	//Scene* scene;	//our scene with root
	std::vector<Scene*> scenes; //our scenes
	Scene* activeScene; //our active scene, to be used without the local

	Game(SDL_Window* window);
	void init( void );	//es crida un cop
	void render( void );	//es crida cada cop que volem pintar algo (continuament)
	void update( double dt );	//es crida continuament

	void onKeyPressed( SDL_KeyboardEvent event );
	void onMouseButton( SDL_MouseButtonEvent event );
    void onResize( SDL_Event e );
    
	void setWindowSize(int width, int height);
};


#endif 