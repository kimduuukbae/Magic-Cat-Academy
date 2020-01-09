#version 330

layout(location=0) out vec4 FragColor;

uniform vec4 u_Color;
uniform float u_Depth;

void main()
{
	FragColor = vec4(u_Color.r, u_Color.g, u_Color.b, u_Color.a);
	gl_FragDepth = u_Depth + floor(1.0-FragColor.a);
}
