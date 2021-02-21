#include "Simple_window.h"
#include "Graph.h"

double one(double){ return 1; }

double square(double x) { return x*x; }

int main()
{
	using namespace Graph_lib;

	//Point tl {100, 100};

	int xmax = 1280;
	int ymax = 720;

	int x_orig = xmax/2;
	int y_orig = ymax/2;

	int rmin = -11;
	int rmax = 11;

	int n_points = 400;

	Simple_window win {Point{100,100}, xmax, ymax, "Canvas"};

	Point origo {x_orig, y_orig};

	int xlength = xmax-40;
	int ylentgh = ymax-40;

	int xscale = 30;
	int yscale = 30;

	Function s (one, rmin, rmax, origo, n_points, xscale, yscale);
	Function sq (square, rmin, rmax, origo, n_points, xscale, yscale);
	Function cos_func ( [] (double x) { return cos(x); }
		, rmin, rmax, origo, n_points, xscale, yscale);
	

	Axis x {Axis::x, Point{20, y_orig}, xlength, xlength/xscale, "x"};
	Axis y {Axis::y, Point{x_orig, ylentgh + 20}, ylentgh, ylentgh/yscale, "y"};

	Rectangle r {Point{200,200}, 100, 50};
	r.set_fill_color(Color::yellow);
	r.set_style(Line_style(Line_style::dash, 4));

	Text t {Point{200,400}, "Hello graphics"};
	t.set_font(Font::times_bold);
	t.set_font_size(20);

	Image ii {Point{50,50}, "badge.jpg"};

	Circle c {Point{700,700}, 100};

	win.attach(c);
	win.attach(ii);
	win.attach(t);
	win.attach(r);
	win.attach(s);
	win.attach(sq);
	win.attach(cos_func);
	win.attach(x);
	win.attach(y);

	/*Polygon poly;

	poly.add(Point{300,200});
	poly.add(Point{350,100});
	poly.add(Point{400,200});

	win.attach(poly);
	*/

	win.wait_for_button();
}