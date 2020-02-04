#include "renderer.h"

using namespace			mod1_engine_gl;

void 					renderer::loop()
{
	while(!core.is_working())
	{
		core::update();
		if (render_request)
		{
			render_call();
			core.swap_buffers();
			render_request = false;
		}
	}
}