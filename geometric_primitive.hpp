// copy from course ppt
#include "g.hpp"

inline void DDALine(int x1,int y1,int x2,int y2){
    double dx,dy,e,x,y;
    dx=x2-x1;
    dy=y2-y1;
    e=(fabs(dx)>fabs(dy))?fabs(dx):fabs(dy);
    dx/=e;
    dy/=e;
    x=x1;
    y=y1;
    for(int i=0;i<=e;i++){
        SetPixel(x+0.5,y+0.5);
        x+=dx;
        y+=dy;
    }
}

inline void MidpointLine(int x1,int y1,int x2,int y2){
    const int a=y1-y2,b=x2-x1;
    const int d1=a*2;
    int d=d1+b;
    const int d2=d+b;

    for(int x=x1,y=y1;x<=x2;x++){
        SetPixel(x,y);
        if(d<0){
            y++;
            d+=d2;
        }else{
            d+=d1;
        }
    }
}

inline void BresenhamLine(int x1,int y1,int x2,int y2){
    const int dx=x2-x1,dy=y2-y1;
    const int d2=dy*2;
    int d=d2-dx;
    const int d1=d-dx;
    for(int x=x1,y=y1;x<=x2;x++){
        SetPixel(x,y);
        if(d>=0){
            y++;
            d+=d1;
        }else{
            d+=d2;
        }
    }
}


inline void BresenhamCircle(int R){
    int x,y,p;
    x=0;
    y=R;
    p=3-2*R;
    for(;x<=y;x++){
        SetPixel8(x,y);
        if(p>=0){
            p+=4*(x-y)+10;
            y--;
        }else{
            p+=4*x+6;
        }
    }
}


inline void MidpointEllipse(int a,int b){
    register int x,y;
    register double d1,d2;
    x=0;y=b;
    d1=b*b+a*a*(-b+0.25);
    SetPixel4(x,y);
    while(b*b*(x+1)<a*a*(y-0.5)) {
        if(d1<0) d1+=b*b*(((x++)*2)+3);
        else d1+=(b*b*(((x++)*2)+3)+a*a*(1+~((y--)*2)));
        SetPixel4(x,y);
    }
    d2=b*b*(x+0.5)*(x+0.5)+a*a*(y-1)*(y-1)-a*a*b*b;
    while(y>0){
        if(d2<0) d2+=b*b*(((x++)*2)+2)+a*a*(2+~((y--)*2));
        else d2+=a*a*(2+~((y--)*2));
        SetPixel4(x,y);
    }
}

inline void Lines(std::vector<std::pair<int,int>>points){
    for(int i=1;i<points.size();i++){
        DDALine(points[i-1].first,points[i-1].second,points[i].first,points[i].second);
    }
}
