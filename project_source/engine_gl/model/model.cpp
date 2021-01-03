#include "model.h"

using namespace		mod1_engine_gl;

MOD1_GENERATE_EXCEPTION_DEFINITION(model, exception_build)
MOD1_GENERATE_EXCEPTION_DEFINITION(model, exception_load)
MOD1_GENERATE_EXCEPTION_DEFINITION(model, exception_dynamic_a)
MOD1_GENERATE_EXCEPTION_DEFINITION(model, exception_dynamic_b)

MOD1_GENERATE_INTERNAL_READ_DEFINITION(model, transformation)
MOD1_GENERATE_INTERNAL_READ_DEFINITION(model, ambient_receptivity)
MOD1_GENERATE_INTERNAL_READ_DEFINITION(model, diffuse_receptivity)
MOD1_GENERATE_INTERNAL_READ_DEFINITION(model, specular_receptivity)
MOD1_GENERATE_INTERNAL_READ_DEFINITION(model, is_built)
MOD1_GENERATE_INTERNAL_READ_DEFINITION(model, is_loaded)
MOD1_GENERATE_INTERNAL_READ_DEFINITION(model, is_dynamic)