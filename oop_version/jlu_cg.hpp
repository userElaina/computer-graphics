// code by userElaina
#include<stdio.h>
#include<string.h>
#define LL long long
#define itn int
#define pt putchar
#define gt getchar
#define register
// #define inline

class Image{
private:
	unsigned char head[54]={
		0x42,0x4d,0xff,0xff,	0xff,0xff,0x00,0x00,	0x00,0x00,0x36,0x00,	0x00,0x00,0x28,0x00,
		0x00,0x00,0xff,0xff,	0xff,0xff,0xff,0xff,	0xff,0xff,0x01,0x00,	0x18,0x00,0x00,0x00,
		0x00,0x00,0xff,0xff,	0xff,0xff,0x00,0x00,	0x00,0x00,0x00,0x00,	0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,	0x00,0x00
	};
	int ox,oy;
	LL mx,my,size_file;
	unsigned char img[100000054];

public:
	Image(int x,int y){
		ox=x-1;
		oy=y-1;
		mx=(ox<<1&(~0xf))+0x10;
		my=(oy<<1&(~0xf))+0x10;
		
		SetHead(my<<32|mx,18,25);

		LL size_img=mx*my;
		size_img+=size_img<<1;
		SetHead(size_img,34,37);
		
		size_file=size_img+54;
		SetHead(size_file,2,5);
		
		memset(img,0xff,sizeof(img));
		for(int i=0;i<54;i++){
			img[i]=head[i];
		}
		// printf("You creat a new %lldx%lld bmp-pic, and it will be %lld KB.",mx,my,size_file);
	}

	inline void SetHead(LL reg,int l,int r){
		for(int i=l;i<=r;i++){
			head[i]=reg&0xff;
			reg>>=8;
		}
	}

	inline void Save(char*pth){
		fwrite(img,sizeof(unsigned char),size_file,fopen(pth,"wb"));
	}

	inline int RGB(int r,int g,int b){
		return b<<16|g<<8|r;
	}

	inline int SetPixel(int x,int y,int color=0x000000){
		// printf("(%d,%d),",x,y);
		x+=ox;
		y+=oy;
		if(ox<0||ox>=mx||oy<0||oy>=my)return 1;
		int reg=54+(mx*y+x)*3;
		img[reg++]=(color>>16);
		img[reg++]=(color>>8)&0xff;
		img[reg++]=color&0xff;
		return 0;
	}
};