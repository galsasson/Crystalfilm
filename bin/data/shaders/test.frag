#version 150

// Horizontal Blur from:
// https://github.com/mattdesl/lwjgl-basics/wiki/ShaderLesson5

in vec4 vColor;
in vec2 vTexCoord;

uniform sampler2DRect tex0;
uniform float resolution;
uniform float radius;
uniform vec2 dir;

out vec4 outColor;

void main( void )
{
    vec4 sum = vec4(0.0);
	vec2 uv = vTexCoord;
	
    outColor = vColor;//vec4(texture(tex0, uv).rgb, 0.0) + vColor;
}

