// code by userElaina

#include<stdio.h>
#include<string.h>
#define LL long long
#define pt putchar
#define gt getchar
#define register
// #define inline

class ImageHead{
private:
	unsigned char head[0x36]={
		0x42,0x4d,0xff,0xff,	0xff,0xff,0x00,0x00,	0x00,0x00,0x36,0x00,	0x00,0x00,0x28,0x00,
		0x00,0x00,0xff,0xff,	0xff,0xff,0xff,0xff,	0xff,0xff,0x01,0x00,	0x18,0x00,0x00,0x00,
		0x00,0x00,0xff,0xff,	0xff,0xff,0x00,0x00,	0x00,0x00,0x00,0x00,	0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,	0x00,0x00
	};

	inline void SetHead(LL reg,int l,int r){
		for(int i=l;i<=r;i++){
			head[i]=reg&0xff;
			reg>>=8;
		}
	}

public:
	ImageHead(LL x,LL y){
		SetHead(y<<32|x,0x12,0x19);

		register LL size_img=x*y;
		size_img+=size_img<<1;
		SetHead(size_img,0x22,0x25);

		SetHead(size_img+0x36,0x02,0x05);
	}

	inline int Save(const char*pth){
		fwrite(head,sizeof(unsigned char),0x36,fopen(pth,"wb"));
		return 0;
	}

};

class Image{
private:
	int ox,oy;
	LL mx,my;
	unsigned char p[100000000];
	ImageHead*head;

public:
	Image(int x,int y){
		ox=x-1;
		oy=y-1;
		mx=(ox<<1&(~0xf))+0x10;
		my=(oy<<1&(~0xf))+0x10;
		
		head=new ImageHead(mx,my);
		
		memset(p,0xff,sizeof(p));
		// printf("You creat a new %lldx%lld bmp-pic, and it will be %lld KB.",mx,my,size_file>>10);
	}

	inline int Save(const char*pth){
		if(head->Save(pth))
			return 1;
		fwrite(p,sizeof(unsigned char),mx*my*3,fopen(pth,"ab"));
		return 0;
	}

	inline static int RGB(int r,int g,int b){
		return b<<16|g<<8|r;
	}

	inline int SetPixel(int x,int y,int color){
		// printf("(%d,%d),",x,y);
		x+=ox;
		y+=oy;
		if(ox<0||ox>=mx||oy<0||oy>=my)return 1;
		register int reg=54+(mx*y+x)*3;
		p[reg++]=(color>>16);
		p[reg++]=(color>>8)&0xff;
		p[reg++]=color&0xff;
		return 0;
	}

	inline int SetPixel(int x,int y){
		return SetPixel(x,y,0x000000);
	}

	inline int GetPixel(int x,int y){
		x+=ox;
		y+=oy;
		if(ox<0||ox>=mx||oy<0||oy>=my)return -1;
		register int reg=54+(mx*y+x)*3;
		register int color=((int)p[reg++])<<16;
		color|=((int)p[reg++])<<8;
		color|=p[reg++];
		return color;
	}
};
