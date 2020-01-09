#version 330

in vec3 a_Position;

uniform vec3 u_Trans;
uniform vec3 u_Scale;

uniform mat4 u_ProjView;
uniform mat4 u_RotToCam;

void main()
{
	vec4 newPosition;
	newPosition.xyz = a_Position.xyz*u_Scale;
	newPosition.w= 1.0;
	newPosition =  u_RotToCam * newPosition;
	newPosition.xyz += u_Trans.xyz;
	gl_Position = u_ProjView * newPosition;
}
