#include "Window.hpp"

Window::Window() : Gtk::Window()
{
	_drawingArea = new Gtk::DrawingArea();
	// Gtk::VBox* vbox = new Gtk::VBox();

	add(*_drawingArea);

	_drawingArea->signal_expose_event().connect(sigc::mem_fun(*this, &Window::on_expose_event), false);
	show_all_children();
}

Window::~Window()
{

}

bool Window::on_expose_event(GdkEventExpose* event)
{
	Glib::RefPtr<Gdk::Window> window = _drawingArea->get_window();
	
	if (window)
	{		
		Gtk::Allocation a = _drawingArea->get_allocation();
		const int w = a.get_width();
		const int h = a.get_height();
		
		int xc, yc;
		xc = w/2;
		yc = h/2;
		
		Cairo::RefPtr<Cairo::Context> cr = window->create_cairo_context();
		cr->set_line_width(1.0);
		
		int wx = 0;
		int wy = 0;
		translate_coordinates(*(get_toplevel()),0, -20,wx,wy);

		cr->set_source_rgb(0.0, 0.0, 0.0);
	
		Arrows::draw_arrow(cr, 10,10,100,100, Arrow::DIAMOND, Arrow::OPEN);
		Arrows::draw_arrow(cr, 110,10,210,100, Arrow::DIAMONDFILLED, Arrow::FILLED);
		Arrows::draw_arrow(cr, 60,10,150,100, Arrow::NONE, Arrow::NORMAL);

	}

	return true;

}