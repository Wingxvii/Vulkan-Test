#include "FirstApp.hpp"
namespace lve {

	void lve::FirstApp::run()
	{
		while (!lveWindow.shouldClose())
		{
			glfwPollEvents();

		}
	}
}