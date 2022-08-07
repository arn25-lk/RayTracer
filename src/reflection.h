#ifndef REFLECTION_H
#define REFLECTION_H

#include "tuples.h"

struct PointLight
{
    Tuple position;
    Color intensity;
};

class Material
{
    private:
        Color color; 
        double ambient;
        double diffuse; 
        double specular; 
        double shininess;
    public:
        Material(Color color, double ambient, double diffuse, double specular, double shininess);
        Material();
        inline Color getColor(){ return this->color;}
        inline double getAmbient(){ return this->ambient;}
        inline double getDiffuse(){ return this->diffuse;}
        inline double getSpecular(){ return this->specular;}
        inline double getShininess(){ return this->shininess;}
        inline void setColor(Color color){ this->color = color;}
        inline void setAmbient(double ambient){this->ambient = ambient;}
        inline void setDiffuse(double diffuse){ this->diffuse = diffuse;}
        inline void setSpecular(double specular ){ this->specular = specular;}
        inline void setShininess(double shininess){ this->shininess = shininess;}

};

Color lighting(Material mat, PointLight light, Tuple point, Tuple eyev, Tuple normalv);
#endif
