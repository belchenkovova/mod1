#include "general.h"

MOD1_GENERATE_EXCEPTION_DEFINITION(general, exception_arguments)

MOD1_GENERATE_INTERNAL_READ_DEFINITION(general, terrain)
MOD1_GENERATE_INTERNAL_READ_DEFINITION(general, water)

					general::general(int argc, char **argv) :
					mod1_engine_gl::renderer(),
					cl_core(),
					framebuffer(window_width(), window_height()),
					program(),
					light_info(),
					system(*(mod1_engine_gl::core *)this)
{
MOD1_GENERATE_MESSAGE("")

	light_info.ambient_intensity = MOD1_LIGHT_AMBIENT_INTENSITY;
	light_info.direct_direction = glm::vec3(MOD1_LIGHT_DIRECT_DIRECTION);
	light_info.direct_intensity = MOD1_LIGHT_DIRECT_INTENSITY;

	MOD1_INTERNAL(terrain) = new mod1_algorithm::terrain;
MOD1_GENERATE_MESSAGE("Mod1 General : Terrain is created")
	MOD1_INTERNAL(water) = new mod1_algorithm::water(cl_core, MOD1_INTERNAL(terrain));
MOD1_GENERATE_MESSAGE("Mod1 General : Water is created")

	if (argc < 2)
		throw (exception_arguments());
	first_argument = argv[1];
	second_argument = argc >= 3 ? argv[2] : nullptr;

	add_callback(mod1_engine_gl::event_type::key_press, general::functor_key, this);
	add_callback(mod1_engine_gl::event_type::mouse_drag, general::functor_drag, this);

MOD1_GENERATE_MESSAGE("Mod1 General : Callbacks are set")

	timer = add_timer(1. / 35., functor_timer, this);

MOD1_GENERATE_MESSAGE("Mod1 General : Timers are set")

	system.add_button(100, 100, "Exit", functor_stop, this);

MOD1_GENERATE_MESSAGE("Mod1 General : Ready")
}

					general::~general()
{
	delete MOD1_INTERNAL(terrain);
	delete MOD1_INTERNAL(water);
}