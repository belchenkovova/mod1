#include "renderer.h"

using namespace			mod1_engine_gl;

void					renderer::callback_key(const class event &event, void *ptr)
{
	const int 			key = event.read_key();

	auto				renderer = (mod1_engine_gl::renderer *)ptr;

	if (key == GLFW_KEY_ESCAPE)
	{
		renderer->stop();
		return ;
	}
	else if (key == GLFW_KEY_A)
		renderer->camera.move(axis::x, sign::negative);
	else if (key == GLFW_KEY_D)
		renderer->camera.move(axis::x, sign::positive);
	else if (key == GLFW_KEY_W)
		renderer->camera.move(axis::z, sign::negative);
	else if (key == GLFW_KEY_S)
		renderer->camera.move(axis::z, sign::positive);
	else if (key == GLFW_KEY_Q)
		renderer->camera.move(axis::y, sign::positive);
	else if (key == GLFW_KEY_E)
		renderer->camera.move(axis::y, sign::negative);
	else if (key == GLFW_KEY_LEFT)
		renderer->camera.rotate(axis::y, sign::positive);
	else if (key == GLFW_KEY_RIGHT)
		renderer->camera.rotate(axis::y, sign::negative);
	else if (key == GLFW_KEY_UP)
		renderer->camera.rotate(axis::x, sign::positive);
	else if (key == GLFW_KEY_DOWN)
		renderer->camera.rotate(axis::x, sign::negative);
	else
		return ;
	renderer->render();
}