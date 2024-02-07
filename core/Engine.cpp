#include "Engine.h"

#include "vendor/imgui.h"
#include <vendor/imgui_impl_glfw.h>
#include <vendor/imgui_impl_opengl3.h>


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

	// imgui


	while (window.isWindowOpen())
	{

		gf_render::ClearScreen();

		window.processInput(camera);
		sha.setMat4("view", camera.lookAt());
		
		gf_render::Draw(cube,goof::BLUE, glm::vec3(0.0f, 0.0f, 0.0f),sha);
		gf_render::Draw(cube, goof::RED, glm::vec3(2.0f, 1.5f, 0.0f),sha);

		gf_render::Draw(triangle, goof::BLUE, glm::vec3(2.0f, 0.0f, 0.0f), sha);
		gf_render::Draw(rect, goof::BLUE, glm::vec3(-1.0f, 1.5f, 0.0f), sha);


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



			ImGui::SliderFloat("float", &f, 0.0f, 1.0f);            

			if (ImGui::Button("Reset Camera"))
				camera.reset_camera();

			//ImGui::SameLine();
			//ImGui::Text("counter = %d", counter);

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
