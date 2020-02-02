#version 330 core

layout (location = 0) in vec4	vertex;
out vec2						texture_coordinates;

uniform mat4					projection;

void							main()
{
	gl_Position = projection * vec4(vertex.xy, 0, 1);
	texture_coordinates = vertex.zw;
}