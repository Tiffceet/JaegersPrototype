#include "lighting.h"
#include <GL/freeglut.h>
#include "typedefs.h"

Vec4f light_pos;
Rgba4f diffuse_light;
Rgba4f ambient_light;
Rgba4f specular_light;
bool light_state = false;

void SetDistantLighting(Vec4f position, Rgba4f diff_l, Rgba4f amb_l, Rgba4f spec_l)
{
    light_pos = position;
    diffuse_light = diff_l;
    ambient_light = amb_l;
    specular_light = spec_l;
}

void toggleLight()
{
    light_state = !light_state;
    if (light_state)
    {
        glEnable(GL_LIGHTING);
        glEnable(GL_LIGHT0);
    }
    else
    {
        glDisable(GL_LIGHTING);
        glDisable(GL_LIGHT0);
    }
}

void ApplyLight()
{
    float lightDiffuse[] = {diffuse_light.r, diffuse_light.g, diffuse_light.b, diffuse_light.a}; //red diffuse : color where light hit directly the object's surface
    float lightAmbient[] = {ambient_light.r, ambient_light.g, ambient_light.b, ambient_light.a}; //red ambient : color applied everywhere
    float lightSpecular[] = {specular_light.r, specular_light.g, specular_light.b, ambient_light.a};
    float lightPosition[] = {light_pos.x, light_pos.y, light_pos.z, light_pos.w};
    glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmbient);
    glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpecular);
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);

    // Debug
    glDisable(GL_LIGHTING);
    glDisable(GL_DEPTH_TEST);
    glPushMatrix();
    glTranslatef(light_pos.x, light_pos.y, light_pos.z);
    glPointSize(10.0f);
    glColor3f(1,1,1);
    glBegin(GL_POINTS);
    glVertex3f(0, 0, 0);
    glEnd();
    glPopMatrix();
    if (light_state)
    {
        glEnable(GL_LIGHTING);
    }
    glEnable(GL_DEPTH_TEST);
}

void setMaterial(Material mat)
{
    float lightAmbient[] = {mat.amb.r, mat.amb.g, mat.amb.b, mat.amb.a};
    float lightDiffuse[] = {mat.diff.r, mat.diff.g, mat.diff.b, mat.diff.a};
    float lightSpecular[] = {mat.spec.r, mat.spec.g, mat.spec.b, mat.spec.a};
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, lightAmbient);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, lightDiffuse);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, lightSpecular);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, &mat.shinyness);
}

void moveLightPosition(Vec3f delta)
{
    light_pos.x += delta.x;
    light_pos.y += delta.y;
    light_pos.z += delta.z;
}
