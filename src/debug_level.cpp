/*
#include "includes.h"
#define RUN 0
#define DEBUG 0

#if DEBUG == 1
#define LOG(x) std::cout << x << "\n"
#else
#define LOG(x)
#endif

#if RUN


int main(int argc, char* args[]) {
	LOG("Running in debug mode");
	int n_width = 1280, n_height = 600;
	
	Window main_window(n_width, n_height, "title");
	Renderer main_renderer(main_window.Fetch_Window());
	Texture_Wrapper texture;
	texture.Load_From_File("sprites/girl_idea.png", main_renderer.Fetch_Renderer(), 2);
	
	// Test using a main window loop

	bool b_quit = false;
	while (b_quit != true) {
		main_window.Input_Handler(b_quit);
		main_renderer.Clear();
		texture.Render(10, 10, main_renderer.Fetch_Renderer());
		main_renderer.Update();
	}





	return 0;
}
#endif
*/