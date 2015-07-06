#include "display.h"
#include <cairomm/context.h>
#include <glibmm/main.h>
#include <iostream>


Display::Display(Map* world) {
	carte = world;
	Glib::signal_timeout().connect(sigc::mem_fun(*this, &Display::on_timeout), 100);
}


Display::~Display() {
}


bool Display::on_draw(const Cairo::RefPtr<Cairo::Context>& cr) {

	const int lesser = MIN(20, 20); // En fonction du nb de pixels par case

	cr->set_line_width(lesser * 0.02); // outline thickness changes
											// with window size

	for(int i = 0; i < carte->get_size(); i++) {
		for(int j = 0; j < carte->get_size(); j++) {

			if(!carte->get_case(i*carte->get_size()+j)->is_no_dog()) {
				cr->save();
				cr->arc(j*10+5, i*10+5, lesser / 4.0, 0.0, 2.0 * M_PI);
				cr->set_source_rgb(0.0, 0.8, 0.0);
				cr->fill_preserve();
				cr->restore();
				cr->stroke();

			} else if(!carte->get_case(i*carte->get_size()+j)->is_no_puce()) {
				cr->save();
				cr->arc(j*10+5, i*10+5, lesser / 4.0, 0.0, 2.0 * M_PI);
				cr->set_source_rgb(0.0, 0.0, 0.8);
				cr->fill_preserve();
				cr->restore();
				cr->stroke();
			}
		}
	}

	return true;
}


bool Display::on_timeout() {
	Glib::RefPtr<Gdk::Window> win = get_window();

	if(win) {
		Gdk::Rectangle r(0, 0, get_allocation().get_width(), get_allocation().get_height());
		win->invalidate_rect(r, false);
	}

	return true;
}
