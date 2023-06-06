#ifndef DRAWGRAPH_H
#define DRAWGRAPH_H
#include <cmath>
#include <GL/glut.h>
#include <ctime>
#include "drawGraph.h"

struct Position
{
    float x, y;
};
struct Figure
{
    Position pos;
};

extern Figure flame;
extern Figure update;
extern Figure rocket;
extern clock_t time_appStart;
extern clock_t time_anima1;

void renderscene();
void drawFlame2(Figure& f);
void updateFlame2(Figure& u);
void drawFlame(Figure& f);
void updateFlame(Figure& u);
void drawAnima();
void drawEarth();
void drawCloud(Figure& o);
void drawCloud1(Figure& o1);
void drawSun(float radius, float x, float y);
void drawTroposphere();
void drawStratosphere();
void drawMesosphere();
void stars();
void drawSpace();
void drawSpace2();
void drawSpace3();
void animate(int value);
void plotGraph();
void drawTreug(GLubyte r,GLubyte g,GLubyte b);
void drawRocket(Figure &f);
void drawMoon();
void drawMoon2();
void drawPlanetEarth();
void drawRocket2(Figure &f);
void initGraph();
void drawCraters();
#endif // DRAWGRAPH_H
