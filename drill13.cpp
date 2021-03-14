#include "Simple_window.h"
#include "Graph.h"

int main(){

	int width = 800;
	int height = 1000;

	Simple_window win{Point{100,100}, width, height, "GUI"};

	int xs = 800;
	int ys = 800;
	int x_grid = 100;
	int y_grid = 100;

	Lines grid;

	for(int x=x_grid; x < xs; x+=x_grid)
		grid.add(Point(x,0),Point(x,ys));
	for(int y=y_grid; y <= ys; y+=y_grid)
		grid.add(Point(0,y),Point(xs,y));

	win.attach(grid);

	Vector_ref<Rectangle> rects;
    for (int i = 0; i < xs; i += x_grid) {
        rects.push_back(new Rectangle{Point{i,i}, Point{i+x_grid,i+x_grid}});
        rects[rects.size() - 1].set_color(Color::invisible);
        rects[rects.size() - 1].set_fill_color(Color::red);
        win.attach(rects[rects.size() - 1]);
    }

    Image im1{Point(200,0), "seal.jpeg"};
    Image im2{Point(0,600), "seal.jpeg"};
    Image im3{Point(600,300), "seal.jpeg"};

    win.attach(im1);
    win.attach(im2);
    win.attach(im3);

	while (true){
		int x = rand() % 8;
		int y = rand() % 8;
		Image im4 {Point{x*100,y*100}, "orca.jpg"};
		win.attach(im4);
		win.wait_for_button();
	}
	win.wait_for_button();

}