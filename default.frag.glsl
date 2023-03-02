//Fragment Shader source code
#version 330 core
out vec4 FragColor;

in vec3 Color;
in vec2 texCoords;

uniform sampler2D texCat;
uniform sampler2D texSade;



void main()
{
	vec4 cat = texture(texCat,texCoords);
	vec4 sade = texture(texSade,texCoords);

	FragColor = vec4(Color, 1.0) * mix(cat,sade,0.5f);
}