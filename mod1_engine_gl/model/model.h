#pragma once

#include "mod1_main/mod1_OpenGL.h"
#include "mod1_main/mod1_generic.h"

#include "mod1_engine_gl/namespace.h"

#include "mod1_engine_gl/model/model_data.h"
#include "mod1_engine_gl/loader/loader.h"
#include "mod1_engine_gl/point/point2.h"

class				mod1_engine_gl::model
{
	friend class 	model_reader;

public :

					model() = default;
					~model() = default;

	MOD1_GENERATE_EXCEPTION_DECLARATION(exception_build, "Mod1 Model : Object not built")
	MOD1_GENERATE_EXCEPTION_DECLARATION(exception_load, "Mod1 Model : Object not loaded")
	MOD1_GENERATE_EXCEPTION_DECLARATION(exception_dynamic, "Mod1 Model : Can't set object as dynamic after loading")

	virtual void	build() = 0;
	void			load(loader &loader);
	void			start();
	void			stop();

	int 			vertex_number();
	glm::mat4		&transformation();

protected :

	model_data		data;
	int				vertex_number_internal = -1;
	glm::mat4 		transformation_internal = glm::mat4(1);

	void			*get_ptr(const int &index, const model_data::slot_type &slot);
	void const		*get_ptr(const int &index, const model_data::slot_type &slot) const;

	void 			upload_buffer(const model_data::slot_type &slot);

	void			set_as_built();
	void			set_as_dynamic();

private :

	bool			is_built = false;
	bool			is_loaded = false;
	bool 			is_dynamic = false;
};

