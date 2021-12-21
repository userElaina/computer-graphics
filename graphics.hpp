// code by userElaina

#include "bmp24bits.hpp"

class Image:public BMP24bits{
public:
    int ox,oy;
    Image(int x,int y):ox(((x>>2)+1)<<2),oy(((y>>2)+1)<<2),BMP24bits(ox<<1,oy<<1){
    }

    Image(std::string p):BMP24bits(p){
        ox=width>>1;
        oy=height>>1;
    }

    inline int getp(int x,int y=DEFAULT_Y){
        x+=ox;
        if(y==DEFAULT_Y){
            if(x<0||x>=size){
                printf("ERROR %d>=%d\n",x,size);
                return ERR_SIZE_3;
            }
            return x;
        }else{
            y+=oy;
            if(x<0||y<0||x>=width||y>=height){
                printf("ERROR %d>=%d %d>=%d\n",x,width,y,height);
                return ERR_SIZE_3;
            }
            return x+y*width;
        }
    }

};
