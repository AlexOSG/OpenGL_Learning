
/************************************************************************/
/* by DR 2016.12.27 learning OpenGL_LessionOne create a window          */
/************************************************************************/
// notice: GLEW before GLFW
#define GLEW_STATIC
#include <GL/glew.h>
// GLFW
#include <GLFW/glfw3.h>
#include <iostream>

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	// When a user presses the escape key, we set the WindowShouldClose property to true, 
	// closing the application
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}

int main()
{
	//initialize GLFW window
# if 1
	glfwInit();
	//OpenGL version 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	//OpenGL version 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	//use core-profile
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", nullptr, nullptr);
	if (window == nullptr)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}

	//in current thread to make context for this window
	glfwMakeContextCurrent(window);
#endif


	//initialize GLEW
#if 1
	//use new modern techniques
	glewExperimental = GL_TRUE;

	if (glewInit() != GLEW_OK)
	{
		std::cout << "Failed to initialize GLEW" << std::endl;
		return -1;
	}
#endif

	//setViewport
	int width, height;
	glfwGetFramebufferSize(window, &width, &height);

	// the lower left corner
	glViewport(0, 0, width, height);
	glfwSetKeyCallback(window, key_callback);

	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
		
		// Rendering commands here
		//......
		//setting
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		//using
		glClear(GL_COLOR_BUFFER_BIT);

		// double buffer
		glfwSwapBuffers(window);
	}
	
	glfwTerminate();
	return 0;

}