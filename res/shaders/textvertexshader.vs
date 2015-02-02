#version 330 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec2 texCoord;

out vec2 TexCoord;

uniform int windowWidth; 
uniform int windowHeight;

void main()
{

	// map [0..windowWidth][0..windowHeight] to [-1..1][-1..1]
	vec2 vertexposition = vec2(position.x, position.y) - vec2(windowWidth/2, windowHeight/2);
	vertexposition /= vec2(windowWidth/2, windowHeight/2);
	gl_Position =  vec4(vertexposition,0,1);
	
	// UV of the vertex. No special space for this one.
	TexCoord = texCoord;
}

