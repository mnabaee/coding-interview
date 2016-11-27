#include <stdlib.h>
#include <stdio.h>
#include <cstdlib>
#include <string>


using namespace std;


void fillPaint(int**array, Size sz, int x, int y, int color){
	if(x <=0 || x >sz.X || y <= 0 || y > sz.Y || array[x][y] == color){
		return;
	}
	int myColor = array[x][y];
	array[x][y] = color;
	if(array[x][y+1] == myColor) fillPaint(array, sz, x, y+1, color);
	if(array[x][y-1] == myColor) fillPaint(array, sz, x, y-1, color);
	if(array[x+1][y] == myColor) fillPaint(array, sz, x+1, y, color);
	if(array[x-1][y] == myColor) fillPaint(array, sz, x-1, y, color);
}

