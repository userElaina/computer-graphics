// code by userElaina
// pop version that you can start quickly

#include "graphics.hpp"

Image*default_image;

inline Image*NewImage(int x,int y){
	default_image=new Image(x,y);
	return default_image;
}

inline int SetPixel(int x,int y,int color){
	return default_image->SetPixel(x,y,color);
}

inline int SetPixel(int x,int y){
	return default_image->SetPixel(x,y);
}

inline int GetPixel(int x,int y){
	return default_image->GetPixel(x,y);
}

inline int RGB(int r,int g,int b){
	return Image::RGB(r,g,b);
}

inline int Save(const char*pth){
	return default_image->Save(pth);
}