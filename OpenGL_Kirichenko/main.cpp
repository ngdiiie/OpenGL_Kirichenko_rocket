#include <GL/glut.h>
#include <iostream>
#define _USE_MATH_DFINES
#include <cmath>
#include <array>
#include <ctime>
#include "drawGraph.h"
#include <ctime>

Figure f = {.0, .0};
Figure f2 = {.0, -1.0};
Figure f3 = {.0, -1.0};
Figure f4 = {.0, -1.0};
Figure f5 = {.0, -1.0};
Figure f6 = {-0.2, -0.2};
Figure f7 = {.0, 5.0};

Figure d = {.0, .0};
Figure d2 = {0, -1};

Figure u = {.0, .0};

Figure o = {0, 0};
Figure o1 = {1, -0.5};

float SpeedY = 0.0042;
float SpeedX = 0.0042;
float SpeedY1 = 0.0021;

void renderScene(void);
void processKeys(unsigned char key, int x, int y);
void drawAnima() {
    drawEarth();
    d.pos.y += SpeedY;
    drawFlame(d);
    u.pos.y += SpeedY;
    updateFlame(u);
    drawSun(0.2, -0.7, 0.7);
    drawCloud(o);
    f.pos.y += SpeedY;
    drawRocket(f);

    if (f.pos.y > 3.5) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        drawTroposphere();
        d.pos.y += SpeedY;
        drawFlame(f2);
        u.pos.y += SpeedY;
        updateFlame(f2);
        drawSun(0.2, -0.7, -0.6);
        drawCloud1(o1);
        f2.pos.y += SpeedY;
        drawRocket(f2);

        if (f2.pos.y > 3.5){
                    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
                    drawStratosphere();
                    d.pos.y += SpeedY;
                    drawFlame(f3);
                    u.pos.y += SpeedY;
                    updateFlame(f3);
                    f3.pos.y += SpeedY;
                    drawRocket(f3);

                    if (f3.pos.y > 3.5){
                               glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
                               drawMesosphere();
                               f4.pos.y += SpeedY;
                               drawRocket2(f4);
                               //std::cout<<d2.pos.y;
                               if (f4.pos.y > 3.5) {
                                               glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
                                               drawSpace();
                                               drawMoon2();
                                               stars();
                                               f5.pos.y += SpeedY;
                                               drawRocket2(f5);

                                               if (f5.pos.y > 3.5) {
                                                               glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
                                                               drawSpace2();
                                                               drawMoon();
                                                               stars();
                                                               f6.pos.y += SpeedY1;
                                                               drawRocket2(f6);
                                                               if(f6.pos.y > 3.5){

                                                                              if (f6.pos.y > 3.5) {
                                                                                              glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
                                                                                              drawSpace3();
                                                                                              drawCraters();
                                                                                              d.pos.y -= SpeedY;
                                                                                              drawFlame2(f7);
                                                                                              u.pos.y -= SpeedY;
                                                                                              updateFlame2(f7);
                                                                                              stars();
                                                                                              drawSun(0.1, -0.7, 0.6);
                                                                                              drawPlanetEarth();
                                                                                              glPushMatrix();
                                                                                              if (f7.pos.y > -0.3)
                                                                                              f7.pos.y -= SpeedY1;
                                                                                              glPopMatrix();
                                                                                              drawRocket(f7);

                                                                                                      if (f7.pos.y < -0.3) {
                                                                                                              glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
                                                                                                              drawSpace3();
                                                                                                              drawCraters();
                                                                                                              stars();
                                                                                                              drawSun(0.1, -0.7, 0.6);
                                                                                                              drawPlanetEarth();
                                                                                                              glPushMatrix();
                                                                                                              if (f7.pos.y > -0.3)
                                                                                                              f7.pos.y -= SpeedY1;
                                                                                                              glPopMatrix();
                                                                                                              drawRocket(f7);

                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(800,800);
    glutCreateWindow("Rocket");
    glutDisplayFunc(renderScene);
    time_appStart=clock();
    time_anima1=clock();
    glutTimerFunc(1000/60, animate, 1);
    glutMainLoop();
    return 0;
}

void renderScene(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    drawAnima();
    glutSwapBuffers();
}



