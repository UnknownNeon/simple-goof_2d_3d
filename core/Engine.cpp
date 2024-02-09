#include "Engine.h"

#include "imgui/imgui.h"
#include <imgui/imgui_impl_glfw.h>
#include <imgui/imgui_impl_opengl3.h>
#include <vector>


void goof::setViewMode(Shader& shader, glm::mat4 MODE)
{
	shader.setMat4("projection", MODE);
}


void goof::run()
{

	_Window window;

	Shader sha;
	sha.load_shader("dep/basic.vert");
	sha.load_shader("dep/basic.frag");
	sha.init_and_use_shader();
	sha.setColor(goof::RED);

	gf_render::Triangle triangle;
	gf_render::Rect rect;
	gf_render::Cube cube;
 
	goof::Camera camera;
	

	//IMGUI STATES:
	goof::IMGUI::Init(window.getWindow());
	static bool show_wireframe = false;
	static bool view_mode = false;

	const char* items[2] = {  "Prespective [3D]", "Orthographic [2D]" };
	static const char* current_item = items[1];

	glm::vec3 location = glm::vec3(0.f,0.f,0.f);



	//
	/*std::vector<glm::vec3> loc_vec_cube;
	std::vector<glm::vec3>::iterator erase_iter;*/

	//imgui
	/////////////////////GAAAAAAAAAAAAAAME LOOOOOOOOOOOOOOOOOOOOOOOOOOP//////////////////////////////////////

	while (window.isWindowOpen())
	{

		gf_render::ClearScreen();

		window.processInput(camera);
		sha.setMat4("view", camera.lookAt());
		
		//gf_render::Draw(cube,goof::BLUE, glm::vec3(0.0f, 0.0f, 0.0f),sha);
		

		//dearimgui
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();
		//----------------

		{
			static float f = 0.0f;

			ImGui::Begin("Debug window game....");                        

			ImGui::Text("Graphics Settings : ");              
			ImGui::Checkbox("Show Wireframe", &show_wireframe);      
			gf_render::setWireframeMode(show_wireframe);

			
			ImGui::Text("[WARNING :] While in orthographic \n dont W or S (Go forward or back)");
			if (ImGui::BeginCombo("##combo", current_item)) 
			{
				for (int n = 0; n < IM_ARRAYSIZE(items); n++)
				{
					bool is_selected = (current_item == items[n]); 
					if (ImGui::Selectable(items[n], is_selected))
						current_item = items[n];
						if (is_selected)
							ImGui::SetItemDefaultFocus();   
				}
				ImGui::EndCombo();
			}
			if (current_item == items[0])
				goof::setViewMode(sha, prespective);
			if (current_item == items[1])
				goof::setViewMode(sha, orthographic);

			//@TODO Impelememting saving and loading states
			if (ImGui::Button("Save to file"));

			if (ImGui::Button("Reset Camera"))
				camera.reset_camera();

			goof::IMGUI::render_primitives(triangle,sha);
			goof::IMGUI::render_primitives(cube, sha);



			ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
			ImGui::End();
		}


		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		window.swap_and_pollevents();
			
	}

	goof::IMGUI::Destroy();
}


void goof::IMGUI::Init(GLFWwindow* the_Window)
{
	const char* glsl_version = "#version 330";

	ImGui::CreateContext();
	ImGui_ImplGlfw_InitForOpenGL(the_Window, true);
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	ImGui::StyleColorsDark();

	ImGui_ImplOpenGL3_Init(glsl_version);
}

void goof::IMGUI::Destroy()
{
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();
}

void goof::IMGUI::render_primitives(gf_render::shapes& cube,Shader& sha)
{

	if (ImGui::Button(("Add " + cube.name).c_str())) {

		cube.loc_vec_shape.push_back(glm::vec3(0.f, 0.f, 0.f));
		cube.color_index.push_back(glm::vec4(1.f, 0.f, 0.f , 1.f));
	}

	ImGui::SameLine();
	if (ImGui::Button(("ERASE ALL : " + cube.name).c_str())) {
		cube.loc_vec_shape.clear();
	}

	//Inittializing the vector iterator and falgs to delete deleted objs
	cube.erase_iter = cube.loc_vec_shape.begin();
	std::vector<bool> delete_flags(cube.loc_vec_shape.size(), false);
	
	if(cube.loc_vec_shape.size() != 0)
		ImGui::Begin(cube.name.c_str());
	
	//ADD multiple objects:
	for (int n = 0; n < cube.loc_vec_shape.size(); n++) {

		ImGui::Text("item : %d", n);
		ImGui::SameLine();
		std::string  temp = std::to_string(n);

		ImGui::SliderFloat3((cube.name+temp).c_str(), glm::value_ptr(cube.loc_vec_shape[n]), -2.5f * i, 2.5f * i);
		ImGui::SameLine();
		if (ImGui::Button(("Delete" + cube.name + temp).c_str())) {
			delete_flags[n] = true;
		}
		//color change:
		ImGui::ColorEdit3(("Color" + cube.name + temp).c_str(), glm::value_ptr(cube.color_index[n]));
		//colorend
		gf_render::Draw(cube, glm::value_ptr(cube.color_index[n]), cube.loc_vec_shape[n],sha);
	}


	if (cube.loc_vec_shape.size() != 0)
		ImGui::End();

	//delete multiple objects
	for (int n = 0; n < cube.loc_vec_shape.size(); ++n) {
		if (delete_flags[n]) {
			cube.erase_iter = cube.loc_vec_shape.erase(cube.erase_iter);
			cube.color_index.erase(std::next(cube.color_index.begin(), n));
		}
		else {
			++cube.erase_iter;
		}
	}
	
}
