#include "loader.h"

using namespace			mod1_engine_gl;

unsigned int					loader::vao_build()
{
	unsigned int				result;

	glGenVertexArrays(1, &result);
	vbo_vector.push_back(result);
	return (result);
}

void					loader::vao_bind(unsigned int vao)
{
	glBindVertexArray(vao);
}

void					loader::vao_unbind()
{
	glBindVertexArray(0);
}