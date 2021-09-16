#include "graphics.hpp"

int main(){
	Image*img=new Image(64,32);
	register int x=2,y=3;
	img->SetPixel(x,y,Image::RGB(0xff,0x00,0xf0));
	printf("%x",img->GetPixel(x,y));
	img->Save("test.bmp");
}