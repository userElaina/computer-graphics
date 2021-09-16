#include "g.hpp"
#include "geometric_primitive.hpp"

int main(){
	NewImage(64,32);
	MidpointEllipse(20,30);
	Save("ellipse_g.bmp");
}