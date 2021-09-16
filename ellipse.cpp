#include "graphics.hpp"
#include "geometric_primitive.hpp"

Image *img;
inline int SetPixel(int x,int y){
	img->SetPixel(x,y);
	img->SetPixel(-x,y);
	img->SetPixel(x,-y);
	img->SetPixel(-x,-y);
	return 0;
}

int main(){
	img=new Image(64,32);
	MidpointEllipse(20,30);
	img->Save("ellipse.bmp");
}