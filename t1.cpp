#include "geometric_primitive.hpp"

int main(){
    int x=64,y=32;
    NewImage(x,y);
    SetAxis();

    SetPixel(x,y,RGB(0x7f,0x00,0xf0));
    printf("%x",GetPixel(x,y));
    SetPixel(x-1,y-1,RGB(0xff,0x00,0x00));
    SetPixel(x-2,y-2,RGB(0x00,0xff,0x00));
    SetPixel(x-3,y-3,RGB(0x00,0x00,0xff));

    SetColor(0x0000ff);
    BresenhamCircle(30);
    SetColor(0x00ff00);
    BresenhamCircle(20);
    SetColor(0xff0000);
    MidpointEllipse(20,30);

    SetColor(0x00ffff);
    DDALine(0,0,20,10);
    SetColor(0xff00ff);
    MidpointLine(0,10,20,20);
    SetColor(0xffff00);
    BresenhamLine(0,20,20,30);

    Save("t1.bmp");
}
