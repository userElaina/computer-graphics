// copy from course ppt

inline int SetPixel(int x,int y,int color);
inline int SetPixel(int x,int y);

inline int GetPixel(int x,int y);
inline int RGB(int r,int g,int b);

inline void MidpointEllipse(int a,int b){
	register int x,y;
	register double d1,d2;
	x=0;y=b;
	d1=b*b+a*a*(-b+0.25);
	SetPixel(x,y);
	while(b*b*(x+1)<a*a*(y-0.5)) {
		if(d1<0) d1+=b*b*((x++<<1)+3);
		else d1+=(b*b*((x++<<1)+3)+a*a*(1+~(y--<<1)));
		SetPixel(x,y);
	}
	d2=b*b*(x+0.5)*(x+0.5)+a*a*(y-1)*(y-1)-a*a*b*b;
	while(y>0){
		if(d2<0) d2+=b*b*((x++<<1)+2)+a*a*(2+~(y--<<1));
		else d2+=a*a*(2+~(y--<<1));
		SetPixel(x,y);
	}
}