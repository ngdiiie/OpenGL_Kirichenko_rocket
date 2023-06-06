#include "drawGraph.h"
#include <array>
#include <ctime>
#include <cstdlib>

float randFloat() {
    return (float)rand() / RAND_MAX;
}

clock_t time_appStart;
clock_t time_anima1;

//параметры пламени
float flamePosX = 0.0;
float flamePosY = 0.0;
float flameScale = 1.0;
float flameIntensity = 0.0;

//радиус земли
float radius = 0.15f;

//центр земли
float centerX = 0.0f;
float centerY = 0.0f;

//колво сегментов
int numSegments = 5000;

void drawFlame(Figure& f) {
    glLoadIdentity();
    glPushMatrix();
    //glTranslatef(flamePosX, flamePosY, 0.0f);
    glTranslatef(f.pos.x, f.pos.y, 0);
    glScalef(flameScale, flameScale, 1.0f);

    float intensity = flameIntensity * 0.5f + 0.5f; //интенсивность

    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(-0.02, -0.47);
    glColor3f(1.0f, intensity, 0.0f);
    glVertex2f(-0.04, -0.47);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(-0.03, -0.63);
    glEnd();

    glPopMatrix();
}

void updateFlame(Figure& u) {
    flameScale += 0.00f; //обновление параметров пламени
    flameIntensity = sinf(glutGet(GLUT_ELAPSED_TIME) * 0.01f);
    glutPostRedisplay();
}

void drawFlame2(Figure& f) {
    glLoadIdentity();
    glPushMatrix();
    //glTranslatef(flamePosX, flamePosY, 0.0f);
    glTranslatef(f.pos.x, f.pos.y, 0);
    glScalef(flameScale, flameScale, 1.0f);

    float intensity = flameIntensity * 0.5f + 0.5f; //интенсивность

    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(-0.02, -0.47);
    glColor3f(1.0f, intensity, 0.0f);
    glVertex2f(-0.04, -0.47);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(-0.03, -0.55);
    glEnd();

    glPopMatrix();
}

void updateFlame2(Figure& u) {
    flameScale += 0.00f; //обновление параметров пламени
    flameIntensity = sinf(glutGet(GLUT_ELAPSED_TIME) * 0.01f);
    glutPostRedisplay();
}


void stars(){
    glLoadIdentity();
        glColor3ub(255,255,255);

        glBegin(GL_POINTS);

        int numPoints = 100;
        for (int i = 0; i < numPoints; i++) {
            float x = randFloat() * 2 - 1;
            float y = randFloat() * 2 - 1;

            glVertex2f(x, y);
        }

        glEnd();
        glFlush();
    }

void drawMoon() {
    glLoadIdentity();
    glTranslatef(1, 1, 0);
    glColor3ub(92, 92, 92);
    glBegin(GL_POLYGON);
    int num_segments = 100;
    float radius = 0.5;
    float center_x = 0.0;
    float center_y = 0.0;
    for (int i = 0; i < num_segments; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);
        float x = radius * cosf(theta) + center_x;
        float y = radius * sinf(theta) + center_y;
        glVertex2f(x, y);
    }
    glEnd();

    glColor3ub(41, 49, 51); //цвет кратеров
    float crater_radius = 0.05; //радиус кратеров
    int num_craters = 10; //количество кратеров
    float crater_positions[10][2] = { //координаты центров кратеров
        {-0.3, 0.2},
        {0.1, 0.4},
        {-0.2, -0.3},
        {0.3, -0.2},
        {-0.4, -0.1},
        {0.2, 0.1},
        {0.35, 0.15},
        {-0.15, -0.35},
        {0.25, -0.35},
        {-0.25, 0.35}
    };

    for (int i = 0; i < num_craters; i++) {
        float crater_center_x = crater_positions[i][0]; //x центра кратера
        float crater_center_y = crater_positions[i][1]; //y центра кратера

        glBegin(GL_POLYGON);
        for (int j = 0; j < num_segments; j++) {
            float theta = 2.0f * 3.1415926f * float(j) / float(num_segments);
            float x = crater_radius * cosf(theta) + crater_center_x;
            float y = crater_radius * sinf(theta) + crater_center_y;
            glVertex2f(x, y);
        }
        glEnd();
    }
}

void drawMoon2() {
    glLoadIdentity();
    glTranslatef(0.7, 0.7, 0);
    glColor3ub(92, 92, 92);
    glBegin(GL_POLYGON);
    int num_segments = 100;
    float radius = 0.17;
    float center_x = 0.0;
    float center_y = 0.0;
    for (int i = 0; i < num_segments; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);
        float x = radius * cosf(theta) + center_x;
        float y = radius * sinf(theta) + center_y;
        glVertex2f(x, y);
    }
    glEnd();
}

void drawEarth(){
    glLoadIdentity();
    glBegin(GL_QUADS);
    glColor3ub(179,220,253); //небо
    glVertex2f(-1, 1);
    glVertex2f(-1, -1);
    glVertex2f(1, -1);
    glVertex2f(1, 1);

    glColor3ub(62,67,33); //земля
    glVertex2f(-1.0,-0.6);
    glVertex2f(-1.0,-1);
    glVertex2f(1.0,-1.0);
    glVertex2f(1.0,-0.6);

    glColor3ub(128, 64, 48); //ствол
    glVertex2f(-0.6,-0.6);
    glVertex2f(-0.6,-0.5);
    glVertex2f(-0.56,-0.5);
    glVertex2f(-0.56,-0.6);

    glColor3ub(0, 0, 0); //станция
    glVertex2f(-0.1,-0.6);
    glVertex2f(-0.1,-0.2);
    glVertex2f(-0.12,-0.2);
    glVertex2f(-0.12,-0.6);
    glColor3ub(0, 0, 0);
    glVertex2f(-0.14,-0.6);
    glVertex2f(-0.14,-0.2);
    glVertex2f(-0.16,-0.2);
    glVertex2f(-0.16,-0.6);

    glColor3ub(0, 0, 0);  //станция(2)
    glVertex2f(0.03,-0.6);
    glVertex2f(0.03,-0.2);
    glVertex2f(0.05,-0.2);
    glVertex2f(0.05,-0.6);
    glColor3ub(0, 0, 0);
    glVertex2f(0.07,-0.6);
    glVertex2f(0.07,-0.2);
    glVertex2f(0.09,-0.2);
    glVertex2f(0.09,-0.6);

    glColor3ub(128,128,118); //пункт
    glVertex2f(0.4,-0.65);
    glVertex2f(0.4, -0.9);
    glVertex2f(0.75, -0.9);
    glVertex2f(0.75,-0.65);
    glColor3ub(176,196,222);
    glVertex2f(0.4,-0.75);
    glVertex2f(0.4, -0.7);
    glVertex2f(0.75, -0.7);
    glVertex2f(0.75,-0.75);
    glColor3ub(0,0,0);
    glVertex2f(0.45,-0.65);
    glVertex2f(0.45, -0.63);
    glVertex2f(0.7, -0.63);
    glVertex2f(0.7,-0.65);
    glColor3ub(245,245,220);
    glVertex2f(0.5,-0.63);
    glVertex2f(0.36, -0.59);
    glVertex2f(0.7, -0.45);
    glVertex2f(0.65,-0.58);
    glColor3ub(255, 0, 0);
    glVertex2f(0.47,-0.4);
    glVertex2f(0.47, -0.41);
    glVertex2f(0.48, -0.41);
    glVertex2f(0.48,-0.4);

    glColor3ub(76, 88, 102); //дорога
    glVertex2f(0.4,-0.8);
    glVertex2f(0.4, -0.86);
    glVertex2f(-1, -0.86);
    glVertex2f(-1,-0.8);
    glColor3ub(250, 250, 250);
    glVertex2f(0.38,-0.832);
    glVertex2f(0.38, -0.834);
    glVertex2f(0.34, -0.834);
    glVertex2f(0.34,-0.832);
    glColor3ub(250, 250, 250);
    glVertex2f(0.31,-0.832);
    glVertex2f(0.31, -0.834);
    glVertex2f(0.27, -0.834);
    glVertex2f(0.27,-0.832);
    glColor3ub(250, 250, 250);
    glVertex2f(0.24,-0.832);
    glVertex2f(0.24, -0.834);
    glVertex2f(0.2, -0.834);
    glVertex2f(0.2,-0.832);
    glColor3ub(250, 250, 250);
    glVertex2f(0.17,-0.832);
    glVertex2f(0.17, -0.834);
    glVertex2f(0.13, -0.834);
    glVertex2f(0.13,-0.832);
    glColor3ub(250, 250, 250);
    glVertex2f(0.1,-0.832);
    glVertex2f(0.1, -0.834);
    glVertex2f(0.06, -0.834);
    glVertex2f(0.06,-0.832);
    glColor3ub(250, 250, 250);
    glVertex2f(0.03,-0.832);
    glVertex2f(0.03, -0.834);
    glVertex2f(-0.01, -0.834);
    glVertex2f(-0.01,-0.832);
    glColor3ub(250, 250, 250);
    glVertex2f(-0.04,-0.832);
    glVertex2f(-0.04, -0.834);
    glVertex2f(-0.08, -0.834);
    glVertex2f(-0.08,-0.832);
    glColor3ub(250, 250, 250);
    glVertex2f(-0.11,-0.832);
    glVertex2f(-0.11, -0.834);
    glVertex2f(-0.15, -0.834);
    glVertex2f(-0.15,-0.832);
    glColor3ub(250, 250, 250);
    glVertex2f(-0.18,-0.832);
    glVertex2f(-0.18, -0.834);
    glVertex2f(-0.22, -0.834);
    glVertex2f(-0.22,-0.832);
    glColor3ub(250, 250, 250);
    glVertex2f(-0.25,-0.832);
    glVertex2f(-0.25, -0.834);
    glVertex2f(-0.29, -0.834);
    glVertex2f(-0.29,-0.832);
    glColor3ub(250, 250, 250);
    glVertex2f(-0.32,-0.832);
    glVertex2f(-0.32, -0.834);
    glVertex2f(-0.36, -0.834);
    glVertex2f(-0.36,-0.832);
    glColor3ub(250, 250, 250);
    glVertex2f(-0.39,-0.832);
    glVertex2f(-0.39, -0.834);
    glVertex2f(-0.43, -0.834);
    glVertex2f(-0.43,-0.832);
    glColor3ub(250, 250, 250);
    glVertex2f(-0.46,-0.832);
    glVertex2f(-0.46, -0.834);
    glVertex2f(-0.5, -0.834);
    glVertex2f(-0.5,-0.832);
    glColor3ub(250, 250, 250);
    glVertex2f(-0.53,-0.832);
    glVertex2f(-0.53, -0.834);
    glVertex2f(-0.57, -0.834);
    glVertex2f(-0.57,-0.832);
    glColor3ub(250, 250, 250);
    glVertex2f(-0.6,-0.832);
    glVertex2f(-0.6, -0.834);
    glVertex2f(-0.64, -0.834);
    glVertex2f(-0.64,-0.832);
    glColor3ub(250, 250, 250);
    glVertex2f(-0.67,-0.832);
    glVertex2f(-0.67, -0.834);
    glVertex2f(-0.71, -0.834);
    glVertex2f(-0.71,-0.832);
    glColor3ub(250, 250, 250);
    glVertex2f(-0.74,-0.832);
    glVertex2f(-0.74, -0.834);
    glVertex2f(-0.78, -0.834);
    glVertex2f(-0.78,-0.832);
    glColor3ub(250, 250, 250);
    glVertex2f(-0.81,-0.832);
    glVertex2f(-0.81, -0.834);
    glVertex2f(-0.85, -0.834);
    glVertex2f(-0.85,-0.832);
    glColor3ub(250, 250, 250);
    glVertex2f(-0.88,-0.832);
    glVertex2f(-0.88, -0.834);
    glVertex2f(-0.92, -0.834);
    glVertex2f(-0.92,-0.832);
    glColor3ub(250, 250, 250);
    glVertex2f(-0.95,-0.832);
    glVertex2f(-0.95, -0.834);
    glVertex2f(-0.99, -0.834);
    glVertex2f(-0.99,-0.832);

    glEnd();

    glBegin(GL_TRIANGLES);

    glColor3ub(156,156,156); //пункт
    glVertex2f(0.5, -0.63);
    glVertex2f(0.68, -0.63);
    glVertex2f(0.65, -0.58);
    glColor3ub(156,156,156);
    glVertex2f(0.53, -0.52);
    glVertex2f(0.55, -0.51);
    glVertex2f(0.47, -0.4);

    glColor3ub(1, 121, 111); //ель
    glVertex2f(-0.67, -0.5);
    glVertex2f(-0.49, -0.5);
    glVertex2f(-0.58, -0.46);
    glColor3ub(1, 121, 111);
    glVertex2f(-0.67, -0.47);
    glVertex2f(-0.49, -0.47);
    glVertex2f(-0.58, -0.42);
    glColor3ub(1, 121, 111);
    glVertex2f(-0.67, -0.44);
    glVertex2f(-0.49, -0.44);
    glVertex2f(-0.58, -0.36);

    glColor3ub(73,77,78); //станция
    glVertex2f(0.05, -0.6);
    glVertex2f(0.07, -0.6);
    glVertex2f(0.06, -0.56);
    glColor3ub(73,77,78);
    glVertex2f(0.06, -0.57);
    glVertex2f(0.05, -0.52);
    glVertex2f(0.07, -0.52);
    glColor3ub(73,77,78);
    glVertex2f(0.05, -0.52);
    glVertex2f(0.07, -0.52);
    glVertex2f(0.06, -0.48);
    glColor3ub(73,77,78);
    glVertex2f(0.06, -0.49);
    glVertex2f(0.05, -0.44);
    glVertex2f(0.07, -0.44);
    glColor3ub(73,77,78);
    glVertex2f(0.05, -0.44);
    glVertex2f(0.07, -0.44);
    glVertex2f(0.06, -0.4);
    glColor3ub(73,77,78);
    glVertex2f(0.06, -0.41);
    glVertex2f(0.05, -0.36);
    glVertex2f(0.07, -0.36);
    glColor3ub(73,77,78);
    glVertex2f(0.05, -0.36);
    glVertex2f(0.07, -0.36);
    glVertex2f(0.06, -0.32);
    glColor3ub(73,77,78);
    glVertex2f(0.06, -0.33);
    glVertex2f(0.05, -0.28);
    glVertex2f(0.07, -0.28);
    glColor3ub(73,77,78);
    glVertex2f(0.05, -0.28);
    glVertex2f(0.07, -0.28);
    glVertex2f(0.06, -0.24);
    glColor3ub(73,77,78);
    glVertex2f(0.06, -0.25);
    glVertex2f(0.05, -0.2);
    glVertex2f(0.07, -0.2);



    glColor3ub(73,77,78); //станция(2)
    glVertex2f(-0.12, -0.6);
    glVertex2f(-0.14, -0.6);
    glVertex2f(-0.13, -0.56);
    glColor3ub(73,77,78);
    glVertex2f(-0.13, -0.57);
    glVertex2f(-0.12, -0.52);
    glVertex2f(-0.14, -0.52);
    glColor3ub(73,77,78);
    glVertex2f(-0.12, -0.52);
    glVertex2f(-0.14, -0.52);
    glVertex2f(-0.13, -0.48);
    glColor3ub(73,77,78);
    glVertex2f(-0.13, -0.49);
    glVertex2f(-0.12, -0.44);
    glVertex2f(-0.14, -0.44);
    glColor3ub(73,77,78);
    glVertex2f(-0.12, -0.44);
    glVertex2f(-0.14, -0.44);
    glVertex2f(-0.13, -0.4);
    glColor3ub(73,77,78);
    glVertex2f(-0.13, -0.41);
    glVertex2f(-0.12, -0.36);
    glVertex2f(-0.14, -0.36);
    glColor3ub(73,77,78);
    glVertex2f(-0.12, -0.36);
    glVertex2f(-0.14, -0.36);
    glVertex2f(-0.13, -0.32);
    glColor3ub(73,77,78);
    glVertex2f(-0.13, -0.33);
    glVertex2f(-0.12, -0.28);
    glVertex2f(-0.14, -0.28);
    glColor3ub(73,77,78);
    glVertex2f(-0.12, -0.28);
    glVertex2f(-0.14, -0.28);
    glVertex2f(-0.13, -0.24);
    glColor3ub(73,77,78);
    glVertex2f(-0.13, -0.25);
    glVertex2f(-0.12, -0.2);
    glVertex2f(-0.14, -0.2);
    glEnd();
}

void drawTroposphere(){
    glLoadIdentity();
    glBegin(GL_QUADS);
    glColor3ub(179,220,253); //небо
    glVertex2f(-1, 1);
    glVertex2f(-1, -1);
    glVertex2f(1, -1);
    glVertex2f(1, 1);
    glEnd();
}

void drawStratosphere(){
    glLoadIdentity();
    glBegin(GL_QUADS);
    glColor3ub(127,199,255); //небо
    glVertex2f(-1, 1);
    glColor3ub(179,220,253);
    glVertex2f(-1, -1);
    glColor3ub(179,220,253);
    glVertex2f(1, -1);
    glColor3ub(127,199,255);
    glVertex2f(1, 1);

    glColor3ub(42,100,120); //озоновый слой
    glVertex2f(-1, -0.53);
    glColor3ub(119,221,231);
    glVertex2f(-1, -0.5);
    glColor3ub(119,221,231);
    glVertex2f(1, -0.5);
    glColor3ub(42,100,120);
    glVertex2f(1, -0.53);

    glColor3ub(119,221,231); //озоновый слой(2)
    glVertex2f(-1, -0.5);
    glColor3ub(42,100,120);
    glVertex2f(-1, -0.47);
    glColor3ub(42,100,120);
    glVertex2f(1, -0.47);
    glColor3ub(119,221,231);
    glVertex2f(1, -0.5);
    glEnd();
}

void drawMesosphere(){
    glLoadIdentity();
    glBegin(GL_QUADS);
    glColor3ub(34,113,179); //небо
    glVertex2f(-1, 1);
    glColor3ub(127,199,255);
    glVertex2f(-1, -1);
    glColor3ub(34,113,179);
    glVertex2f(1, -1);
    glColor3ub(34,113,179);
    glVertex2f(1, 1);
    glEnd();
}

void drawSpace(){
    glLoadIdentity();
    glBegin(GL_QUADS);
    glColor3ub(37,40,80); //небо
    glVertex2f(-1, 1);
    glColor3ub(34,113,179);
    glVertex2f(-1, -1);
    glColor3ub(37,40,80);
    glVertex2f(1, -1);
    glColor3ub(37,40,80);
    glVertex2f(1, 1);
    glEnd();
}

void drawSpace2(){
    glLoadIdentity();
    glBegin(GL_QUADS);
    glColor3ub(37,40,80); //небо
    glVertex2f(-1, 1);
    glVertex2f(-1, -1);
    glVertex2f(1, -1);
    glVertex2f(1, 1);
    glEnd();
}

void drawSpace3(){
    glLoadIdentity();
    glBegin(GL_QUADS);
    glColor3ub(37,40,80); //небо
    glVertex2f(-1, 1);
    glVertex2f(-1, -1);
    glVertex2f(1, -1);
    glVertex2f(1, 1);

    glColor3ub(150, 150, 150);
    glVertex2f(-1.0,-0.6);
    glVertex2f(-1.0,-1);
    glVertex2f(1.0,-1.0);
    glVertex2f(1.0,-0.6);
    glEnd();
}

void drawSun(float radius, float x, float y){
        glLoadIdentity();
        const float PI = 3.14159265358979323846;
        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(255, 255, 0);
        glVertex2f(x, y);
        for (int i = 0; i <= 360; i++) {
            glVertex2f(x + (radius * cos(i * PI / 180.0)), y + (radius * sin(i * PI / 180.0)));
        }
        glEnd();
    }

void drawPlanetEarth() {
    glLoadIdentity();
    glTranslatef(-0.4, 0.5, 0);
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(42,82,190);
    glVertex2f(centerX, centerY);  //центральная вершина
    for (int i = 0; i <= numSegments; i++) { //расчет и установка цветов вершин с плавным переходом
        float angle = 2.0f * M_PI * static_cast<float>(i) / static_cast<float>(numSegments);
        float x = radius * cosf(angle);
        float y = radius * sinf(angle);
        float b = static_cast<float>(i) / static_cast<float>(numSegments);//расчет плавного перехода цветов
        float g = 1.0f - b;
        glColor3f(0.0f, g, b);
        glVertex2f(centerX + x, centerY + y);
    }

    glEnd();
}

void drawCloud(Figure& o) {
    glLoadIdentity();
    float x, y;
    float cnt = 30;
    float l = 0.08;
    float a = M_PI * 2 / cnt;
    glPushMatrix();
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(255, 255, 252);
    glVertex2f(0.5, 0.7);
    for (int i = -1; i < cnt; i++) {
        x = sin(a * i) * l;
        y = cos(a * i) * l;
    glVertex2f(x + 0.5, y + 0.7);
}
    glEnd();

    float x1, y1;
    float cnt1 = 30;
    float l1 = 0.09;
    float a1 = M_PI * 2 / cnt1;
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(255, 255, 252);
    glVertex2f(0.4, 0.7);
    for (int i = -1; i < cnt1; i++) {
        x1 = sin(a1 * i) * l1;
        y1 = cos(a1 * i) * l1;
        glVertex2f(x1 + 0.4, y1 + 0.7);
}
    glEnd();

    float x2, y2;
    float cnt2 = 30;
    float l2 = 0.08;
    float a2 = M_PI * 2 / cnt2;
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(255, 255, 252);
    glVertex2f(0.5, 0.7);
        for (int i = -1; i < cnt2; i++) {
        x2 = sin(a2 * i) * l2;
        y2 = cos(a2 * i) * l2;
        glVertex2f(x2 + 0.3, y2 + 0.7);
}
    glEnd();

    float x3, y3;
    float cnt3 = 30;
    float l3 = 0.07;
    float a3 = M_PI * 2 / cnt3;
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(255, 255, 252);
    glVertex2f(0.45, 0.8);
    for (int i = -1; i < cnt3; i++) {
        x3 = sin(a3 * i) * l3;
        y3 = cos(a3 * i) * l3;
        glVertex2f(x3 + 0.45, y3 + 0.8);
}
    glEnd();

    float x4, y4;
    float cnt4 = 30;
    float l4 = 0.08;
    float a4 = M_PI * 2 / cnt4;
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(255, 255, 252);
    glVertex2f(0.36, 0.77);
    for (int i = -1; i < cnt4; i++) {
        x4 = sin(a4 * i) * l4;
        y4 = cos(a4 * i) * l4;
    glVertex2f(x4 + 0.36, y4 + 0.77);
}
    glEnd();
    glPopMatrix();
}

void drawCloud1(Figure& o1) {
    glLoadIdentity();
    float x, y;
    float cnt = 30;
    float l = 0.08;
    float a = M_PI * 2 / cnt;
    glPushMatrix();
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(255, 255, 252);
    glVertex2f(0.5, -0.7);
    for (int i = -1; i < cnt; i++) {
        x = sin(a * i) * l;
        y = cos(a * i) * l;
        glVertex2f(x + 0.5, y - 0.7);
}
    glEnd();

    float x1, y1;
    float cnt1 = 30;
    float l1 = 0.09;
    float a1 = M_PI * 2 / cnt1;
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(255, 255, 252);
    glVertex2f(0.4, -0.7);
    for (int i = -1; i < cnt1; i++) {
        x1 = sin(a1 * i) * l1;
        y1 = cos(a1 * i) * l1;
        glVertex2f(x1 + 0.4, y1 - 0.7);
}
    glEnd();

    float x2, y2;
    float cnt2 = 30;
    float l2 = 0.08;
    float a2 = M_PI * 2 / cnt2;
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(255, 255, 252);
    glVertex2f(0.5, -0.7);
    for (int i = -1; i < cnt2; i++) {
        x2 = sin(a2 * i) * l2;
        y2 = cos(a2 * i) * l2;
    glVertex2f(x2 + 0.3, y2 - 0.7);
    }
    glEnd();

    float x3, y3;
    float cnt3 = 30;
    float l3 = 0.07;
    float a3 = M_PI * 2 / cnt3;
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(255, 255, 252);
    glVertex2f(0.45, -0.8);
    for (int i = -1; i < cnt3; i++) {
        x3 = sin(a3 * i) * l3;
        y3 = cos(a3 * i) * l3;
        glVertex2f(x3 + 0.45, y3 - 0.8);
    }
    glEnd();

    float x4, y4;
    float cnt4 = 30;
    float l4 = 0.08;
    float a4 = M_PI * 2 / cnt4;
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(255, 255, 252);
    glVertex2f(0.36, -0.77);
    for (int i = -1; i < cnt4; i++) {
        x4 = sin(a4 * i) * l4;
        y4 = cos(a4 * i) * l4;
        glVertex2f(x4 + 0.36, y4 - 0.77);
        }
    glEnd();
    glPopMatrix();
}

void drawRocket(Figure &f){
    glLoadIdentity();
    glPushMatrix();
    glTranslatef(f.pos.x, f.pos.y, 0);
    glTranslatef(-0.03, -0.35, 1);
    glScalef(0.5, 0.5, 1);
    glBegin(GL_QUAD_STRIP);
    glColor3ub(176, 196, 222);
    glVertex2f(0.03, -0.13);
    glVertex2f(-0.03, -0.13);
    glVertex2f(0.025, -0.18);
    glVertex2f(-0.025, -0.18);
    glEnd();

    glBegin(GL_TRIANGLE_STRIP);
    glColor3ub(255, 250, 250);
    glVertex2f(-0.027, -0.13);
    glColor3ub(255, 235, 215);
    glVertex2f(0.07, -0.44);
    glColor3ub(112, 128, 144);
    glVertex2f(0.06, -0.24);
    glEnd();

    glBegin(GL_TRIANGLE_STRIP);
    glColor3ub(255, 250, 250);
    glVertex2f(0.027, -0.13);
    glColor3ub(255, 235, 215);
    glVertex2f(-0.07, -0.44);
    glColor3ub(112, 128, 144);
    glVertex2f(-0.06, -0.24);
    glEnd();

    glBegin(GL_TRIANGLE_STRIP);
    glColor3ub(112, 128, 144);
    glVertex2f(0.037, -0.2);
    glColor3ub(0, 0, 0);
    glVertex2f(-0.037, -0.2);
    glColor3ub(0, 0, 0);
    glVertex2f(0, -0.25);
    glEnd();

    glBegin(GL_TRIANGLE_STRIP);
    glColor3ub(0, 0, 0);
    glVertex2f(-0.037, 0.07);
    glColor3ub(0, 0, 0);
    glVertex2f(-0.037, -0.18);
    glColor3ub(0, 0, 0);
    glVertex2f(-0.055, 0);
    glEnd();

    glBegin(GL_TRIANGLE_STRIP);
    glColor3ub(0, 0, 0);
    glVertex2f(0.037, 0.07);
    glColor3ub(0, 0, 0);
    glVertex2f(0.037, -0.18);
    glColor3ub(0, 0, 0);
    glVertex2f(0.055, 0);
    glEnd();

    glBegin(GL_QUAD_STRIP);
    glColor3ub(255, 255, 255);
    glVertex2f(0.037, -0.2);
    glColor3ub(255, 255, 255);
    glVertex2f(-0.037, -0.2);
    glColor3ub(255, 255, 255);
    glVertex2f(0.037, 0.2);
    glColor3ub(255, 255, 255);
    glVertex2f(-0.037, 0.2);
    glEnd();

    glBegin(GL_QUAD_STRIP);
    glColor3ub(112, 128, 144);
    glVertex2f(0.037, 0.2);
    glColor3ub(0, 0, 0);
    glVertex2f(-0.037, 0.2);
    glColor3ub(0, 0, 0);
    glVertex2f(0.03, 0.24);
    glColor3ub(0, 0, 0);
    glVertex2f(-0.03, 0.24);
    glEnd();

    glBegin(GL_QUAD_STRIP);
    glColor3ub(255, 255, 255);
    glVertex2f(0.048, 0.24);
    glColor3ub(255, 255, 255);
    glVertex2f(-0.048, 0.24);
    glColor3ub(255, 255, 255);
    glVertex2f(0.048, 0.4);
    glColor3ub(255, 255, 255);
    glVertex2f(-0.048, 0.4);
    glEnd();

    glBegin(GL_QUAD_STRIP);
    glColor3ub(255, 255, 255);
    glVertex2f(0.035, 0.44);
    glColor3ub(255, 255, 255);
    glVertex2f(-0.035, 0.44);
    glColor3ub(255, 255, 255);
    glVertex2f(0.048, 0.4);
    glColor3ub(255, 255, 255);
    glVertex2f(-0.048, 0.4);
    glEnd();

    glBegin(GL_QUAD_STRIP);
    glColor3ub(71, 74, 81);
    glVertex2f(0.02, 0.47);
    glColor3ub(71, 74, 81);
    glVertex2f(-0.02, 0.47);
    glColor3ub(255, 255, 255);
    glVertex2f(0.035, 0.44);
    glColor3ub(255, 255, 255);
    glVertex2f(-0.035, 0.44);
    glEnd();

    glBegin(GL_QUAD_STRIP);
    glColor3ub(255, 0, 0);
    glVertex2f(0.02, 0.47);
    glVertex2f(-0.02, 0.47);
    glVertex2f(0, 0.5);
    glVertex2f(0, 0.5);
    glEnd();
    glPopMatrix();
}

void drawRocket2(Figure &f){
    glLoadIdentity();


    glPushMatrix();
    glScalef(flameScale, flameScale, 1.0f);
    glRotatef(-70, 0.4,0.4, 1);
    glTranslatef(f.pos.x, f.pos.y, 0);
    glTranslatef(-0.03, -0.35, 1);
    glScalef(0.5, 0.5, 1);
    glBegin(GL_QUAD_STRIP);
    glColor3ub(176, 196, 222);
    glVertex2f(0.03, -0.13);
    glVertex2f(-0.03, -0.13);
    glVertex2f(0.025, -0.18);
    glVertex2f(-0.025, -0.18);
    glEnd();

    glBegin(GL_TRIANGLE_STRIP);
    glColor3ub(255, 250, 250);
    glVertex2f(-0.027, -0.13);
    glColor3ub(255, 235, 215);
    glVertex2f(0.07, -0.44);
    glColor3ub(112, 128, 144);
    glVertex2f(0.06, -0.24);
    glEnd();

    glBegin(GL_TRIANGLE_STRIP);
    glColor3ub(255, 250, 250);
    glVertex2f(0.027, -0.13);
    glColor3ub(255, 235, 215);
    glVertex2f(-0.07, -0.44);
    glColor3ub(112, 128, 144);
    glVertex2f(-0.06, -0.24);
    glEnd();

    glBegin(GL_TRIANGLE_STRIP);
    glColor3ub(112, 128, 144);
    glVertex2f(0.037, -0.2);
    glColor3ub(0, 0, 0);
    glVertex2f(-0.037, -0.2);
    glColor3ub(0, 0, 0);
    glVertex2f(0, -0.25);
    glEnd();

    glBegin(GL_TRIANGLE_STRIP);
    glColor3ub(0, 0, 0);
    glVertex2f(-0.037, 0.07);
    glColor3ub(0, 0, 0);
    glVertex2f(-0.037, -0.18);
    glColor3ub(0, 0, 0);
    glVertex2f(-0.055, 0);
    glEnd();

    glBegin(GL_TRIANGLE_STRIP);
    glColor3ub(0, 0, 0);
    glVertex2f(0.037, 0.07);
    glColor3ub(0, 0, 0);
    glVertex2f(0.037, -0.18);
    glColor3ub(0, 0, 0);
    glVertex2f(0.055, 0);
    glEnd();

    glBegin(GL_QUAD_STRIP);
    glColor3ub(255, 255, 255);
    glVertex2f(0.037, -0.2);
    glColor3ub(255, 255, 255);
    glVertex2f(-0.037, -0.2);
    glColor3ub(255, 255, 255);
    glVertex2f(0.037, 0.2);
    glColor3ub(255, 255, 255);
    glVertex2f(-0.037, 0.2);
    glEnd();

    glBegin(GL_QUAD_STRIP);
    glColor3ub(112, 128, 144);
    glVertex2f(0.037, 0.2);
    glColor3ub(0, 0, 0);
    glVertex2f(-0.037, 0.2);
    glColor3ub(0, 0, 0);
    glVertex2f(0.03, 0.24);
    glColor3ub(0, 0, 0);
    glVertex2f(-0.03, 0.24);
    glEnd();

    glBegin(GL_QUAD_STRIP);
    glColor3ub(255, 255, 255);
    glVertex2f(0.048, 0.24);
    glColor3ub(255, 255, 255);
    glVertex2f(-0.048, 0.24);
    glColor3ub(255, 255, 255);
    glVertex2f(0.048, 0.4);
    glColor3ub(255, 255, 255);
    glVertex2f(-0.048, 0.4);
    glEnd();

    glBegin(GL_QUAD_STRIP);
    glColor3ub(255, 255, 255);
    glVertex2f(0.035, 0.44);
    glColor3ub(255, 255, 255);
    glVertex2f(-0.035, 0.44);
    glColor3ub(255, 255, 255);
    glVertex2f(0.048, 0.4);
    glColor3ub(255, 255, 255);
    glVertex2f(-0.048, 0.4);
    glEnd();

    glBegin(GL_QUAD_STRIP);
    glColor3ub(71, 74, 81);
    glVertex2f(0.02, 0.47);
    glColor3ub(71, 74, 81);
    glVertex2f(-0.02, 0.47);
    glColor3ub(255, 255, 255);
    glVertex2f(0.035, 0.44);
    glColor3ub(255, 255, 255);
    glVertex2f(-0.035, 0.44);
    glEnd();

    glBegin(GL_QUAD_STRIP);
    glColor3ub(255, 0, 0);
    glVertex2f(0.02, 0.47);
    glVertex2f(-0.02, 0.47);
    glVertex2f(0, 0.5);
    glVertex2f(0, 0.5);
    glEnd();



    float intensity = flameIntensity * 0.5f + 0.5f; //интенсивность

    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(-0.014, -0.26);
    glColor3f(1.0f, intensity, 0.0f);
    glVertex2f(0.017, -0.62);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(0.02, -0.26);
    glEnd();

    flameScale += 0.00f; //обновление параметров пламени
    flameIntensity = sinf(glutGet(GLUT_ELAPSED_TIME) * 0.01f);
    glutPostRedisplay();


    glPopMatrix();
}

void animate(int value){
    glutPostRedisplay();
    glutTimerFunc(1000/60, animate, 1);
}

void drawCraters(){
glColor3ub(41, 49, 51); //цвет кратеров
int num_segments = 100;
float crater_radius = 0.1; //радиус кратеров
int num_craters = 3; //количество кратеров
float crater_positions[10][2] = { //координаты центров кратеров
    {-0.7, -0.73},
    {0.8, -0.75},
    {-0.9, -0.8},
};

for (int i = 0; i < num_craters; i++) {
    float crater_center_x = crater_positions[i][0]; //x центра кратера
    float crater_center_y = crater_positions[i][1]; //y центра кратера

    glBegin(GL_POLYGON);
    for (int j = 0; j < num_segments; j++) {
        float theta = 2.0f * 3.1415926f * float(j) / float(num_segments);
        float x = crater_radius * cosf(theta) + crater_center_x;
        float y = crater_radius * sinf(theta) + crater_center_y;
        glVertex2f(x, y);
    }
    glEnd();
}
}
