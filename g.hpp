// code by userElaina
// pop version that you can start quickly

#include "bmp24bits.hpp"

BMP24bits*default_image;
int ox,oy;

inline int NewImage(int x,int y){
    ox=((x>>2)+1)<<2;
    oy=((y>>2)+1)<<2;
    default_image=new BMP24bits(ox<<1,oy<<1);
    printf("NewImage: O(%d,%d)\n",ox,oy);
    return 0;
}

inline int LoadImage(std::string pth){
    default_image=new BMP24bits(pth);
    ox=default_image->width>>1;
    oy=default_image->height>>1;
    printf("LoadImage: O(%d,%d)\n",ox,oy);
    return 0;
}

inline int SetPixel(int x,int y,const int rgb=0x000000){
    return default_image->setpixel(default_image->getp(x+ox,y+oy),rgb);
}

inline int SetPixel4(int x,int y,const int rgb=0x000000){
    return default_image->setpixel(default_image->getp(x+ox,y+oy),rgb)+default_image->setpixel(default_image->getp(ox-x,y+oy),rgb)+default_image->setpixel(default_image->getp(x+ox,oy-y),rgb)+default_image->setpixel(default_image->getp(ox-x,oy-y),rgb);
}

inline int GetPixel(int x,int y){
    return default_image->getpixel(default_image->getp(x+ox,y+oy));
}

inline int RGB(int r,int g,int b,int a=0){
    return argb(r,g,b,a);
}

inline int Save(std::string pth){
    return default_image->save(pth);
}

inline int Clear(){
    delete default_image;
}

inline int Reboot(std::string pth){
    Save(pth);
    Clear();
    default_image=new BMP24bits(ox<<1,oy<<1);
    printf("RenewImage: O(%d,%d)\n",ox,oy);
    return 0;
}