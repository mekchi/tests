#version 150

uniform mat4 modelview;
uniform mat4 projection;

in vec4 vertex;
in vec2 uv;

out vec4 out_position;
out vec2 out_uv;

void main()
{
    out_position = projection * modelview * vertex;
	out_uv = uv;
}
