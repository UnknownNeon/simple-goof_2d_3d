#pragma once
#include "Shader.h"

namespace goof {

	class Texture2D {
		
		unsigned int ID;

	public:

		Texture2D();
		~Texture2D();

		void Init( const char* file_name);
		inline unsigned int get_tex2d_id() { return ID; }
		void use();

	};
}