#include "g.hpp"

int main(){
    NewImage(64,32);
    int x=2,y=3;
    SetPixel(x,y,RGB(0xff,0x00,0xf0));
    printf("%x",GetPixel(x,y));
    SetPixel(x+1,y+1,RGB(0xff,0x00,0x00));
    SetPixel(x+2,y+2,RGB(0x00,0xff,0x00));
    SetPixel(x+3,y+3,RGB(0x00,0x00,0xff));
    Save("test.bmp");
}