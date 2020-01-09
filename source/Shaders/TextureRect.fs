#version 330

layout(location=0) out vec4 FragColor;

uniform vec4 u_Color;
uniform sampler2D u_Texture;
uniform float u_Depth;

in vec2 vTexPos;

void main()
{
	FragColor = vec4(u_Color.r, u_Color.g, u_Color.b, u_Color.a);
    FragColor *= texture(u_Texture, vTexPos);
	gl_FragDepth = u_Depth + floor(1.0-FragColor.a);
}
