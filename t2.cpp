#include "graphical_transformation.hpp"
int main(){
    int x=64,y=64;
    NewImage(x,y);
    SetAxis();

    int l=10,r=40;
    for(int i=l;i<=r;i++){
        SetPixel(i,l);
        SetPixel(l,i);
        SetPixel(i,r);
        SetPixel(r,i);
    }

    SetColor(0x0000ff);
    for(int i=l;i<=r;i++){
        SetPixel(Translation(std::make_pair(i,l),-20,-30));
        SetPixel(Translation(std::make_pair(l,i),-20,-30));
        SetPixel(Translation(std::make_pair(i,r),-20,-30));
        SetPixel(Translation(std::make_pair(r,i),-20,-30));
    }

    SetColor(0x00ff00);
    for(int i=l;i<=r;i++){
        SetPixel(Proportion(std::make_pair(i,l),0.4,0.6));
        SetPixel(Proportion(std::make_pair(l,i),0.4,0.6));
        SetPixel(Proportion(std::make_pair(i,r),0.4,0.6));
        SetPixel(Proportion(std::make_pair(r,i),0.4,0.6));
    }

    SetColor(0xff0000);
    for(int i=l;i<=r;i++){
        SetPixel(Rotation(std::make_pair(i,l),45.0/180.0*3.14159265359));
        SetPixel(Rotation(std::make_pair(l,i),45.0/180.0*3.14159265359));
        SetPixel(Rotation(std::make_pair(i,r),45.0/180.0*3.14159265359));
        SetPixel(Rotation(std::make_pair(r,i),45.0/180.0*3.14159265359));
    }

    SetColor(0xffff00);
    for(int i=l;i<=r;i++){
        SetPixel(Stagger(std::make_pair(i,l),0.5,0.5));
        SetPixel(Stagger(std::make_pair(l,i),0.5,0.5));
        SetPixel(Stagger(std::make_pair(i,r),0.5,0.5));
        SetPixel(Stagger(std::make_pair(r,i),0.5,0.5));
    }

    Save("t2.bmp");
}

