#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <gtkmm.h>
#include <iostream>

#include "Arrows.hpp"

class Window : public Gtk::Window
{
public:
	Window();
	~Window();

private:
	bool on_expose_event(GdkEventExpose* event);

	Gtk::DrawingArea* _drawingArea;
};

#endif /* WINDOW_HPP */