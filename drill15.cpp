#include "Simple_window.h"
#include "Graph.h"

double one(double x) {return 1;}

double slope(double x) {return x/2;}

double square(double x) {return x*x;}

double sloping_cos(double x){
	return cos(x) + slope(x);
}

int main(){
	using namespace Graph_lib;

	int xmax = 600;
	int ymax = 600;

	int x_orig = xmax/2;
	int y_orig = ymax/2;

	int rmin = -10;
	int rmax = 11;

	int n_points = 400;

	int xscale = 20;
	int yscale = 20;

	Point origo {x_orig, y_orig};

	Simple_window win(Point{100,100}, xmax, ymax, "Function graphs");

	Axis x{Axis::x ,Point(100,300), 400, 20, "1==20 pixels"};
	Axis y{Axis::y ,Point(300,500), 400, 20, "1==20 pixels"};

	x.set_color(Color::red);
	y.set_color(Color::red);

	win.attach(x);
	win.attach(y);

	Function s(one, rmin, rmax, origo, n_points, xscale, yscale);
	Function sl(slope, rmin, rmax, origo, n_points, xscale, yscale);
	Function sq(square, rmin, rmax, origo, n_points, xscale, yscale);
	Function cosi(cos, rmin, rmax, origo, n_points, xscale, yscale);
	Function sl_cos(sloping_cos, rmin, rmax, origo, n_points, xscale, yscale);

	Text t1{Point{100,380}, "x/2"};
	cosi.set_color(Color::blue);

	win.attach(s);
	win.attach(sl);
	win.attach(sq);
	win.attach(cosi);
	win.attach(sl_cos);
	win.attach(t1);

	win.wait_for_button();
}