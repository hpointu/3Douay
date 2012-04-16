#include "Application.hpp"

int main(void)
{
	Application *app = Application::getInstance();
	app->run();

	return 0;
}
