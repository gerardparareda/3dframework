# If the line starts with a # symbol, it is a comment
# and should be ignored

*SCENE_NAME Nivell2

# The RESOURCES line tells us how many resources we need to load
*RESOURCES 5

*RESOURCE mesh
*NAME spitfire
*PATH data/assets/spitfire.ase

*RESOURCE mesh
*NAME terrain
*PATH data/assets/terrain.ase

*RESOURCE texture
*NAME spitfire_diffuse
*PATH data/assets/spitfire_color_spec.tga

*RESOURCE texture
*NAME terrain_tex
*PATH data/assets/terrain.tga

*RESOURCE texture
*NAME sky_tex
*PATH data/assets/cielo.tga

# each resource to load starts with RESOURCE followed by the type

# the OBJECTS line tells us how many objects we need to load
*OBJECTS 3

*OBJECT GameObjectSkybox
*NAME skybox
*MESH sphere
*SHADER skybox_shader
*TEXTURE sky_tex
*POSITION 0.0 0.0 0.0
*ROTATION 0.0 0.0 0.0
*SCALE 3.0 3.0 3.0

# each object starts with the OBJECT followed by the type
*OBJECT GameObjectMesh
*NAME terrain
*MESH terrain
*SHADER phong_tex
*TEXTURE terrain_tex
*POSITION -50.0 -40.0 20.0
*ROTATION 0.0 0.0 0.0
*SCALE 1.0 1.0 1.0
*PARENT root
*COLLISION yes

*OBJECT GameObjectPlayer
*NAME player1
*MESH spitfire
*SHADER phong_tex
*TEXTURE spitfire_diffuse
*POSITION 0.0 40.0 0.0
*ROTATION 0.0 0.0 0.0
*SCALE 1.0 1.0 1.0
*PARENT root
*COLLISION yes