#include "geometric_primitive.hpp"

int px[6],py[6];
const double _00=0.9510565162951535,_01=0.30901699437494745,_10=0.5877852522924732,_11=0.8090169943749473;
std::vector<std::pair<int,int>>points;

// 01234
// 02413

int main(){
    int x=128,y=128;
    px[0]=0;
    py[0]=y;
    px[1]=0.5+x*_00;
    py[1]=0.5+y*_01;
    px[2]=0.5+x*_10;
    py[2]=0.5+y*_11;
    
    py[2]=~py[2]+1;
    px[3]=~px[2]+1;
    py[3]=py[2];
    px[4]=~px[1]+1;
    py[4]=py[1];

    for(int i=0;i<5;i++){
        printf("(%d,%d)\n",px[i],py[i]);
        int j=(i<<1)%5;
        points.push_back(std::make_pair(px[j],py[j]));
    }
    points.push_back(points[0]);

    NewImage(x,y);
    SetColor(0xffff00);
    Lines(points);

    SetColor(0xff0000);
    BresenhamCircle(128);

    Save("star.bmp");

}
