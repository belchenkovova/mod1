#include "model.h"

using namespace		mod1_engine_gl;

void				model::load()
{
	eab = new class eab;
	vao = new class vao;

	vao->bind();
	eab->bind();

	vbo_point = vao->attribute(MOD1_MODEL_POINT_GROUP, buffer_point, MOD1_INTERNAL(is_dynamic));

	eab->buffer(buffer_index);

	if (buffer_normal.is_allocated())
		vbo_normal = vao->attribute(MOD1_MODEL_NORMAL_GROUP, buffer_normal, MOD1_INTERNAL(is_dynamic));
	if (buffer_color.is_allocated())
		vbo_color = vao->attribute(MOD1_MODEL_COLOR_GROUP, buffer_color, MOD1_INTERNAL(is_dynamic));
	if (buffer_texture.is_allocated())
		vbo_texture = vao->attribute(MOD1_MODEL_TEXTURE_GROUP, buffer_texture, MOD1_INTERNAL(is_dynamic));

	vao::unbind();
	eab::unbind();

	set_as_loaded();
	vertex_number = buffer_index.size();
}