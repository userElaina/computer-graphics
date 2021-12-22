// code by userElaina
#pragma once
#include "g.hpp"



inline std::pair<double,double> m2p3(double l[3],double m[3][3]){
    double r[3];
    for(int i=0;i<3;i++){
        double t=0;
        for(int j=0;j<3;j++){
            t+=l[i]*m[i][j];
        }
        r[i]=t;
    }
    return std::make_pair(r[0],r[1]);
}

inline std::pair<double,double> Translation(std::pair<double,double> p,double tx,double ty){
    return std::make_pair(
        p.first+tx,
        p.second+ty
    );
}

inline std::pair<double,double> Translation_Matrix(std::pair<double,double> p,double tx,double ty){
    double l[3]={p.first,p.second,1};
    double m[3][3]={
        {1,0,0},
        {0,1,0},
        {tx,ty,1}
    };
    return m2p3(l,m);
}

inline std::pair<double,double> Proportion(std::pair<double,double> p,double sx,double sy){
    return std::make_pair(
        p.first*sx,
        p.second*sy
    );
}

inline std::pair<double,double> Proportion_Matrix(std::pair<double,double> p,double sx,double sy){
    double l[3]={p.first,p.second,1};
    double m[3][3]={
        {sx,0,0},
        {0,sy,0},
        {0,0,1}
    };
    return m2p3(l,m);
}

inline std::pair<double,double> Rotation(std::pair<double,double> p,double theta){
    return std::make_pair(
        p.first*cos(theta)-p.second*sin(theta),
        p.first*sin(theta)+p.second*cos(theta)
    );
}

inline std::pair<double,double> Rotation_Matrix(std::pair<double,double> p,double theta){
    double l[3]={p.first,p.second,1};
    double m[3][3]={
        {cos(theta),-sin(theta),0},
        {sin(theta),cos(theta),0},
        {0,0,1}
    };
    return m2p3(l,m);
}

inline std::pair<double,double> Stagger(std::pair<double,double> p,double b,double d){
    return std::make_pair(
        p.first+b*p.second,
        p.second+d*p.first
    );
}

inline std::pair<double,double> Stagger_Matrix(std::pair<double,double> p,double b,double d){
    double l[3]={p.first,p.second,1};
    double m[3][3]={
        {1,d,0},
        {b,1,0},
        {0,0,1}
    };
    return m2p3(l,m);
}
