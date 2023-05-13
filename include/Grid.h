#ifndef GRID_H
#define GRID_H

#include "Matrix.h"

// Cell types enum
enum Type {empty, start, end, wall, checked, path};

class Grid {
	private:
		// Temporary variables for storing the point from
		// where start_point or end_point where taken
		int temp_x;
		int temp_y;

		// Last cell addresses where mouse where positioned
		int last_x = 0;
		int last_y = 0;

		// Starting point reset location
		const int start_y = 7;
		const int start_x = 6;

		//Starting point reset location
		const int end_y = 7;
		const int end_x = 14;

		
		// Checkable flags during moving and grid drawing
		int border_set = 0;
		int point_set = 0;
		int start_set = 1;
		int end_set = 1;

		unsigned int cell_x = 20; // cell on x axis of the grid
		unsigned int cell_y = 14; // cell on y axis of the grid

		// Matrix class with needed overloading
		Matrix matrix = Matrix(cell_y, cell_x);

	public:
		Grid();
		Grid(unsigned int, unsigned int);
		~Grid();

		int width();
		int height();

		int get_index(unsigned int, unsigned int);
		void set_value(unsigned int, unsigned int, unsigned int value);

		void clear();
		void reset();

		void solve(int);

		void on_mouse_event(int, int, bool, int);
		void on_refresh_event();

};

#endif