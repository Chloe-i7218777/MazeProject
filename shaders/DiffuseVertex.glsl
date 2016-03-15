#version 410 core

layout (location=0) in vec3 inVert;
layout (location=2) in vec3 inNormal;

out vec3 fragmentNormal;
uniform vec4 colour;
uniform mat4 MVP;

void main()
{
    fragmentNormal = inNormal;
    gl_Position = MVP*vec4(inVert,1.0);

}
