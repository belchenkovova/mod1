#include "font.h"

using namespace		mod1_gui;

MOD1_GENERATE_EXCEPTION_DEFINITION(font, exception_library)
MOD1_GENERATE_EXCEPTION_DEFINITION(font, exception_font)
MOD1_GENERATE_EXCEPTION_DEFINITION(font, exception_symbol)

					font::font(const std::string &source, const int &width) :
					library(),
					face()
{
	if (FT_Init_FreeType(&library))
		throw (exception_library());

	if (FT_New_Face(library, source.c_str(), 0, &face))
		throw (exception_font());

	FT_Set_Pixel_Sizes(face, 0, width);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
}

					font::~font()
{
	FT_Done_Face(face);
	FT_Done_FreeType(library);
}

symbol				*font::generate_symbol(const char &task)
{
	if (FT_Load_Char(face, task, FT_LOAD_RENDER))
		throw (exception_symbol());

	return (new symbol(face));
}