#include <cmath>
#include <fstream>
#include “ccc_win.h”

using namespace std;

int ccc_win_main()
{
	Point middle(0,0);
	Circle petals(middle, 3);
	Line stem(middle, Point(0,-6));
	
	int n_flowers = cwin.get_int("Enter number of flowers: ");
	
	for (int count = 0; count < n_flowers; count++)
	{
		middle = cwin.get_mouse ("Click where the next flower is: ");
		stem = (middle, Point(middle.get_x(), middle.get_y() - 6));
		cwin << middle << petals << stem;
		
	}
	
	return 0;
}
