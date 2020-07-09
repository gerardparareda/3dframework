#version 330

out vec4 fragColor;

in vec3 u_light;
in varying v_normal;

void main(void)
{
	vec3 L = normalize(u_light);
	vec3 N = normalize(v_normal);
	float NdotL = max(dot(N,L), 0.0);
	vec3 color = vec3(1.0, 0.0, 0.0);
	vec3 final_color = color.xyz * NdotL;
	fragColor =  vec4(final_color, 1.0);
}