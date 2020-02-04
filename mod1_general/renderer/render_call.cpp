#include "renderer.h"

void				::renderer::render_call()
{
	core::clear(MOD1_BACKGROUND);

	program.start();

	program.camera_projection.upload(camera.projection());
	program.camera_view.upload(camera.view());

	program.light_ambient_intensity.upload(light_info.ambient_intensity);
	program.light_direct_direction.upload(light_info.direct_direction);
	program.light_direct_intensity.upload(light_info.direct_intensity);

	for (auto &model : model_array())
	{
		program.object_transformation.upload(model->transformation());
		model->draw();
	}
	program::stop();
}