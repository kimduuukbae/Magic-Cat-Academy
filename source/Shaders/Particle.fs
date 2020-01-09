#version 330

in vec2 v_TexPos;
in float v_Alpha;
in float v_Spark;

out vec4 FragColor;

uniform sampler2D u_Texture;
uniform vec4 u_Color;
uniform float u_Depth;

void main()
{
    FragColor = texture(u_Texture, v_TexPos);
    //FragColor.a *= v_Alpha;
    //FragColor *= u_Color * v_Spark;
    //FragColor = vec4(v_TexPos, 0, 1);
	gl_FragDepth = u_Depth + floor(1.0-FragColor.a);
}
