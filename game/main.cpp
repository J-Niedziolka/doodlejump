#include "game.cpp"

int main(int argc, char* argv[])
{
	int width = 320;
	int height = 200;
	bool fullscreen = false;

	parseCommandLineArguments(argc, argv, width, height, fullscreen);

	MyFramework* myFramework = new MyFramework(width, height);
	return run(myFramework);
}