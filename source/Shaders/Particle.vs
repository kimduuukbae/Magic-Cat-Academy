#version 330

in vec3 a_Position;
in vec2 a_TexPos;
in vec4 a_Velocity;

uniform vec3 u_Trans;
uniform vec3 u_Scale;

uniform mat4 u_ProjView;
uniform mat4 u_RotToCam;

uniform vec3 u_TrailDir;
uniform float u_ElapsedTime;
uniform float u_MaxTime;

out vec2 v_TexPos;
out float v_Alpha;
out float v_Spark;

void main()
{
	vec4 newPosition;
	newPosition.xyz = a_Position.xyz*u_Scale;
	newPosition.w= 1.0;
	newPosition =  u_RotToCam * newPosition;
	newPosition.xyz += u_Trans.xyz;

	float newTime = u_ElapsedTime - a_Velocity.w;

	vec3 newVelocity = vec3(a_Velocity.x, a_Velocity.y, a_Velocity.z);
	
	if(newTime > 0)
	{
	  newTime = fract(newTime/u_MaxTime) * u_MaxTime;
      newPosition = 
	  vec4(
		  newPosition.x + newVelocity.x*newTime + 0.5*u_TrailDir.x*newTime*newTime,
		  newPosition.y + newVelocity.y*newTime + 0.5*u_TrailDir.y*newTime*newTime,
		  newPosition.z + newVelocity.z*newTime + 0.5*u_TrailDir.z*newTime*newTime,	
		  1.0
		  );
	}
	else
	{
	  newPosition = 
	  vec4(
		  -1000,
		  -1000,
		  -1000,		
		  1.0
		  );
	}

	gl_Position = u_ProjView * newPosition;

	v_TexPos = a_TexPos;
	v_Alpha = (1.0 - (u_MaxTime - newTime)/u_MaxTime) * 3.0;
	v_Spark = a_Position.z;
}

