// code by userElaina
// pop version that you can start quickly
#pragma once
#include "bmp24bits.hpp"

BMP24bits*nft;
int ox,oy;
int col=0x000000;
double xa=1,xb=0,ya=1,yb=0;

inline int NewImage(int x,int y){
    ox=((x>>2)+1)<<2;
    oy=((y>>2)+1)<<2;
    nft=new BMP24bits(ox<<1,oy<<1);
    printf("NewImage: O(%d,%d)\n",ox,oy);
    return 0;
}

inline int LoadImage(std::string pth){
    nft=new BMP24bits(pth);
    ox=nft->width>>1;
    oy=nft->height>>1;
    printf("LoadImage: O(%d,%d)\n",ox,oy);
    return 0;
}

inline int SetAxis(){
    for(int i=0;i<nft->width;i++)
        nft->setpixel(nft->getp(i,oy));
    for(int i=0;i<nft->height;i++)
        nft->setpixel(nft->getp(ox,i));
    return 0;
}

inline int SetColor(int color=0x000000){
    col=color;
    return 0;
}


inline int SetPixel(int x,int y,int rgb=(-1)){
    if(rgb==(-1))rgb=col;
    return nft->setpixel(nft->getp(x+ox,y+oy),rgb);
}

inline int SetPixel(double x,double y,int rgb=(-1)){
    return SetPixel((int)(x>0?x+0.5:x-0.5),(int)(y>0?y+0.5:y-0.5),rgb);
}

inline int SetPixel(std::pair<int,int>p,int rgb=(-1)){
    return SetPixel(p.first,p.second,rgb);
}

inline int SetPixel(std::pair<double,double>p,int rgb=(-1)){
    return SetPixel(p.first,p.second,rgb);
}

inline int SetPixel2(int x,int y,int rgb=(-1)){
    return SetPixel(x,y,rgb)+SetPixel(-x,-y,rgb);
}

inline int SetPixel4(int x,int y,int rgb=(-1)){
    return SetPixel2(x,y,rgb)+SetPixel2(-x,y,rgb);
}

inline int SetPixel8(int x,int y,int rgb=(-1)){
    return SetPixel4(x,y,rgb)+SetPixel4(y,x,rgb);
}

inline int SetPixel_map(double x,double y,int rgb=(-1)){
    return SetPixel(x*xa+xb,y*ya+yb,rgb);
}

inline int GetPixel(int x,int y){
    return nft->getpixel(nft->getp(x+ox,y+oy));
}

inline int RGB(int r,int g,int b,int a=0){
    return argb(r,g,b,a);
}

inline int Save(std::string pth){
    return nft->save(pth);
}

inline int Clear(){
    nft->white();
    return 0;
}
