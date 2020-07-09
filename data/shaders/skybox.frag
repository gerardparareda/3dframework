#version 330

in vec3 v_normal;
in vec3 v_camera;
in vec2 v_uv;

uniform sampler2D u_texture_diffuse;

out vec4 fragColor;

void main(void)
{
	fragColor =  vec4(texture2D(u_texture_diffuse, v_uv).xyz, 1.0);
}
