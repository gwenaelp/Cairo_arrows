#include "Window.hpp"

int main(int argc, char **argv)
{
    Gtk::Main kit(&argc, &argv);

    Window* mainWindow = new Window();
    
    kit.run(*mainWindow);
	
	return 0;
}