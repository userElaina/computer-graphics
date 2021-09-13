#include "jlu_cg.hpp"

Image *img;
void SetPixel(int x,int y){
	img->SetPixel(x,y);
	img->SetPixel(-x,y);
	img->SetPixel(x,-y);
	img->SetPixel(-x,-y);
}

void MidpointEllipse(int a,int b){
	int x,y;
	double d1,d2;
	x=0;y=b;
	d1=b*b+a*a*(-b+0.25);
	SetPixel(x,y);
	while(b*b*(x+1)<a*a*(y-0.5)) {
		if(d1<0) {
			d1+=b*b*(2*x+3);x++;
		}else{
			d1+=(b*b*(2*x+3)+a*a*(-2*y+2));x++;y--;
		}
		SetPixel(x,y);
	}
	d2=b*b*(x+0.5)*(x+0.5)+a*a*(y-1)*(y-1)-a*a*b*b;
	while(y>0){
		if(d2<0){
			d2+=b*b*(2*x+2)+a*a*(-2*y+3);x++;y--;
		}else{
			d2+=a*a*(-2*y+3);y--;
		}
		SetPixel(x,y);
	}
}

int main(){
	img=new Image(64,32);
	MidpointEllipse(20,30);
	img->Save("ellipse.bmp");
}