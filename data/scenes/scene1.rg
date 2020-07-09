# If the line starts with a # symbol, it is a comment
# and should be ignored

*SCENE_NAME Nivell1

# The RESOURCES line tells us how many resources we need to load
*RESOURCES 10

# each resource to load starts with RESOURCE followed by the type
*RESOURCE mesh
*NAME x3_fighter
*PATH data/assets/x3_fighter.ase

*RESOURCE mesh
*NAME tetera
*PATH data/assets/teapot.ase

*RESOURCE mesh
*NAME sphere
*PATH data/assets/sphere.ase

*RESOURCE shader
*NAME simple
*PATH data/shaders/simple.vert data/shaders/simple.frag

*RESOURCE shader
*NAME simpleBlue
*PATH data/shaders/simple.vert data/shaders/simpleBlue.frag

*RESOURCE shader
*NAME phong_tex
*PATH data/shaders/phong.vert data/shaders/phong.frag

*RESOURCE shader
*NAME skybox_shader
*PATH data/shaders/skybox.vert data/shaders/skybox.frag

*RESOURCE texture
*NAME x3_fighter_diffuse
*PATH data/assets/x3_fighter.tga

*RESOURCE texture
*NAME x3_fighter_diffuse_player
*PATH data/assets/x3_fighter_player.tga

*RESOURCE texture
*NAME milkyway_tex
*PATH data/assets/milkyway.tga

# the OBJECTS line tells us how many objects we need to load
*OBJECTS 7

*OBJECT GameObjectSkybox
*NAME skybox
*MESH sphere
*SHADER skybox_shader
*TEXTURE milkyway_tex
*POSITION 0.0 0.0 0.0
*ROTATION 0.0 0.0 0.0
*SCALE 3.0 3.0 3.0

# each object starts with the OBJECT followed by the type
*OBJECT GameObjectMesh
*NAME teapot_001
*MESH tetera
*SHADER simple
*TEXTURE x3_fighter_diffuse
*POSITION -50.0 40.0 20.0
*ROTATION 0.0 0.0 0.0
*SCALE 1.0 1.0 1.0
*PARENT root
*COLLISION yes

*OBJECT GameObjectMesh
*NAME fighter_001
*MESH x3_fighter
*SHADER phong_tex
*TEXTURE x3_fighter_diffuse
*POSITION 50.0 40.0 20.0
*ROTATION 0.0 0.0 0.0
*SCALE 1.0 1.0 1.0
*PARENT teapot_001
*COLLISION no

*OBJECT GameObjectMesh
*NAME waypoint1
*MESH sphere
*SHADER simpleBlue
*TEXTURE x3_fighter_diffuse
*POSITION 0.0 0.0 50.0
*ROTATION 0.0 0.0 0.0
*SCALE 0.01 0.01 0.01
*PARENT root
*COLLISION yes

*OBJECT GameObjectMesh
*NAME waypoint2
*MESH sphere
*SHADER simple
*TEXTURE x3_fighter_diffuse
*POSITION 25.0 25.0 25.0
*ROTATION 0.0 0.0 0.0
*SCALE 0.01 0.01 0.01
*PARENT root
*COLLISION no

*OBJECT GameObjectEnemy
*NAME enemy1
*MESH tetera
*SHADER simple
*TEXTURE x3_fighter_diffuse
*POSITION -50.0 0.0 0.0
*ROTATION 0.0 0.0 90.0
*SCALE 0.3 0.3 0.3
*PARENT root
*COLLISION yes
*NUMWAYPOINTS 4
*WAYPOINT 0.0 0.0 50.0
*WAYPOINT 25.0 25.0 25.0
*WAYPOINT 0.0 25.0 0.0
*WAYPOINT -125.0 100.0 125.0

*OBJECT GameObjectPlayer
*NAME player1
*MESH x3_fighter
*SHADER phong_tex
*TEXTURE x3_fighter_diffuse_player
*POSITION 0.0 40.0 0.0
*ROTATION 0.0 0.0 0.0
*SCALE 1.0 1.0 1.0
*PARENT root
*COLLISION yes

