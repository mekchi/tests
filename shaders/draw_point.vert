#version 150

uniform mat4 modelview;
uniform mat4 projection;

in vec4 vertex;
in vec2 uv;

out vec2 frag_uv;

void main()
{
    gl_Position = projection * modelview * vertex;
    frag_uv = uv;
}
