#include "Simple_window.h"
#include "Graph.h"

int main()
{
	//Point p{700,200};

	int xmax = 1280;
	int ymax = 720;
	int x_orig = xmax/2;
	int y_orig = ymax/2;

	Simple_window win {Point{600, 400}, xmax, ymax, "My window"};

	Point origo {x_orig, y_orig};

	int xlength = xmax-40;
	int ylentgh = ymax-40;

	int xscale = 30;
	int yscale = 30;

	Axis x {Axis::x, Point{20, y_orig}, xlength, xlength/xscale};
	Axis y {Axis::y, Point{x_orig, ylentgh + 20}, ylentgh, ylentgh/yscale, "y"};

	Rectangle r {Point{200,200}, 100, 50};
	r.set_fill_color(Color::blue);
	r.set_style(Line_style(Line_style::dash, 4));

	Text t {Point{950,400}, "First"};
	t.set_font(Font::times_bold);
	t.set_font_size(50);

	Polygon poly;

	poly.add(Point{200,100});
	poly.add(Point{450,100});
	poly.add(Point{400,200});

	Image img {Point{800,-50}, "badge.jpg"};

	win.attach(poly);
	win.attach(x);
	win.attach(y);
	win.attach(r);
	win.attach(t);
	win.attach(img);

	win.wait_for_button();
}