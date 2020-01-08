// #type fragment
#version 430 core

layout(location = 0) out vec4 color;

in vec2 v_TexCoord;

uniform vec4 u_Color;
uniform sampler2D u_Texture;
uniform float u_Scale;

void main()
{
	color = 1.0f * texture(u_Texture, v_TexCoord * u_Scale) * u_Color;
}