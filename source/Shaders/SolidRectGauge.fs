#version 330

in vec2 vTexPos;

out vec4 FragColor;

uniform vec4 u_Color;
uniform float u_Gauge;
uniform float u_Depth;

void main()
{
    float gauge = ceil(u_Gauge - vTexPos.x);
	FragColor = u_Color*gauge;
	gl_FragDepth = u_Depth + floor(1.0-FragColor.a);
}
