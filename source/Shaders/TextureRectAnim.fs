#version 330

out vec4 FragColor;

in vec2 vTexPos;

uniform sampler2D u_Texture;
uniform float u_TotalSeqX;
uniform float u_TotalSeqY;
uniform float u_CurrSeqX;
uniform float u_CurrSeqY;
uniform vec4 u_Color;
uniform float u_Depth;

void main()
{
	vec2 newTexPos = vec2(vTexPos.x, 1-vTexPos.y);
	newTexPos.x = u_CurrSeqX/u_TotalSeqX + newTexPos.x/u_TotalSeqX;
	newTexPos.y = u_CurrSeqY/u_TotalSeqY + newTexPos.y/u_TotalSeqY;
	FragColor = texture2D(u_Texture, newTexPos)*u_Color;

	gl_FragDepth = u_Depth + floor(1.0-FragColor.a);
}
