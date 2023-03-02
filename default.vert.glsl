// Vertex Shader source code
#version 330 core

in vec3 position;
in vec3 color;
in vec2 texcoords;

out vec3 Color;
out vec2 texCoords;

uniform vec3 overrideColor;
uniform mat4 model;
uniform mat4 view;
uniform mat4 proj;



void main()
{
   Color = overrideColor * color;
   gl_Position = proj * view * model * vec4(position, 1.0);
   texCoords = texcoords;
}