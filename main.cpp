#include<windows.h>
#include<gl/glut.h>
#include<bits/stdc++.h>
#include <mmsystem.h>

using namespace std;

float x=10;
float y=0.1;
float watery=0.1;
float waterx=0;
float gre=255;
float bl=255;
float inbl= 0.0479591836734;//0.0959183673;
float ingr=0.0051020408163;//0.0142857141;
float sunx=0.3;
float suny=3;
float six=0.0006183673469;
float siy=0.0002448979591;


void Sun(float cx, float cy, float r, int num_segments) {

    bl+=inbl;
    if(bl>254)
        inbl=-0.0479591836734;//-0.0959183673;
    if(bl<21)
        inbl=0.0479591836734;//0.0959183673;
    gre+=ingr;
    if(gre>254)
        ingr=-0.0051020408163;//0.0142857141;
    if(gre<221)
        ingr=0.0051020408163;//0.0142857141;
    glBegin(GL_POLYGON);
    glColor3ub(255, gre, bl);
    for (int ii = 0; ii < num_segments; ii++)   {
        float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle
        float x = r * cosf(theta);//calculate the x component
        float y = r * sinf(theta);//calculate the y component
        glVertex2f(x + cx, y + cy);//output vertex
    }
    glEnd();

    }
void boat()
{

				 if (waterx>=9)
				 waterx=-4.5;
				 else
					waterx += .0005;


			  glPushMatrix();

			 glTranslatef(waterx, 0, 0);
    float a=0.3,x=0,y=1;
    glBegin(GL_QUADS);
    glColor3ub(100,67,33);
    glVertex3f(-7*a+x,-5*a+y,0.0);
    glVertex3f(-1*a+x,-5*a+y,0.0);
    glVertex3f(-2*a+x,-6*a+y,0);
    glVertex3f(-6*a+x,-6*a+y,0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(100,167,133);
    glVertex3f(-2.5*a+x,-4.3*a+y,0.0);
    glVertex3f(-5.5*a+x,-4.3*a+y,0.0);
    glVertex3f(-6*a+x,-5*a+y,0);
    glVertex3f(-2*a+x,-5*a+y,0);
    glEnd();
 glPopMatrix();
}
void view()
{
    x+=y;
    if(x>254)
        y=-0.05;
    if(x<10)
        y=0.05;



    glColor3f(1.0,1.0,1.0);
    glBegin(GL_LINES);
        glVertex3f(-4,0,0.0);
        glColor3f(1.1,0.1,1.0);
        glVertex3f(18,0,0.0);
        glColor3f(0.0,1.1,1.0);

        glEnd();
      //SKY
      glColor3ub(x/4, x/2, x);
        glBegin(GL_QUADS);
        glVertex3f(-4,8,0);
        glVertex3f(-4,0,0.0);
        glVertex3f(20,0,0.0);
        glVertex3f(20.05,7.93,0.0);
        glEnd();

        //Sun
        sunx+=six;
    if(sunx>0.3)
        six=-0.0006183673469;//0.00134693878;;
    if(sunx<-3)
        six=0.0006183673469;
    suny+=siy;
    if(suny>4.2)
        siy=-0.0002448979591;//0.000489795918;
    if(suny<3)
        siy=0.0002448979591;//0.000489795918;
        Sun(sunx,suny,1,500);


      //1st mountain
      glColor3f(0.53, 0.71, 0.78);
        glBegin(GL_TRIANGLES);

        glVertex3f(-4,0,0.0);
        glVertex3f(-3.19,1.42,0.0);
        glVertex3f(-2,0,0.0);
        glEnd();
    //2nd mountain
      glColor3f(0.60, 0.77, 0.83);
    glBegin(GL_TRIANGLES);

        glVertex3f(-3,0,0.0);
        glVertex3f(-1.58,1.77,0.0);
        glVertex3f(-0.40,0,0.0);
        glEnd();
    //3rd mountain
      glColor3f(0.53, 0.71, 0.78);
    glBegin(GL_TRIANGLES);

        glVertex3f(-1.43,0,0.0);
        glVertex3f(1.44,4.02,0.0);
        glVertex3f(2.91,0,0.0);
        glEnd();
    //3rd mountain slide
      glColor3f(0.60, 0.77, 0.83);
    glBegin(GL_TRIANGLES);

        glVertex3f(1.44,4.02,0.0);
        glVertex3f(2.91,0,0.0);
        glVertex3f(3.62,0,0.0);
        glEnd();
     //4th mountain
      glColor3f(0.53, 0.71, 0.78);
    glBegin(GL_TRIANGLES);

        glVertex3f(2.28,0,0.0);
        glVertex3f(4.39,3.21,0.0);
        glVertex3f(6,0,0.0);
        glEnd();

     //4th mountain slide
        glColor3f(0.60, 0.77, 0.83);
    glBegin(GL_TRIANGLES);

        glVertex3f(4.39,3.21,0.0);
        glVertex3f(6,0,0.0);
        glVertex3f(6.82,0,0.0);
        glEnd();

     //5th mountain
      glColor3f(0.53, 0.71, 0.78);
    glBegin(GL_TRIANGLES);

        glVertex3f(5.37,0,0.0);
        glVertex3f(7,2,0.0);
        glVertex3f(9.64,0,0.0);
        glEnd();


      //1st mountain front
        glColor3f(0.43, 0.55, 0.70);
    glBegin(GL_TRIANGLES);

        glVertex3f(-4,0,0.0);
        glVertex3f(0.73,0.55,0.0);
        glVertex3f(2.91,0,0.0);
        glEnd();

      //2nd mountain front
        glColor3f(.43, 0.55, 0.70);
    glBegin(GL_TRIANGLES);

        glVertex3f(2.91,0,0.0);
        glVertex3f(7.29,0.71,0.0);
        glVertex3f(9.64,0,0.0);
        glEnd();



      //water
        glColor3f(0.13, 0.55, 0.70);
    glBegin(GL_QUADS);
        glVertex3f(-4,0,0);
        glVertex3f(-4,-8,0.0);
        glVertex3f(20,-8,0.0);
        glVertex3f(20,0,0.0);
        glEnd();


      //right side soil
     glColor3f(0.04, 0.19, 0.26);
  glBegin(GL_POLYGON);

       glVertex3f(-0.60,-5.84,0.0);
       glVertex3f(-1.13,-4.44,0.0);
       glVertex3f(2.99,-3.76,0.0);
       glVertex3f(3.63,-2.44,0.0);
       glVertex3f(6.19,-1.12,0.0);
       glVertex3f(10.70,-0.67,0.0);
       glVertex3f(13.48,-2.45,0.0);
       glVertex3f(16.86,-4.75,0.0);
       glVertex3f(14.27,-1.16,0.0);
       glVertex3f(14.31,-10.20,0.0);
       //glVertex3f(8.48,-3.45,0.0);
       //glVertex3f(-2.19,-9.75,0.0);

    glEnd();



     //left side soil
       glColor3f(0.04, 0.19, 0.26);
    glBegin(GL_TRIANGLES);

        glVertex3f(-7.9710810522827, -1.122695262683,0.0);
        glVertex3f(-0.1058577224848, -2.3007463341065,0.0);
        glVertex3f(-8, -4,0.0);
        glEnd();


     //Sea lines
        glColor3f(1.0,1.0,0.0);
    glBegin(GL_LINES);

       glVertex3f(1.21, -2.78, 0.0);
       glVertex3f(2.81, -2.78, 0.0);
       glEnd();


        glColor3f(1.0,1.0,0.0);
    glBegin(GL_LINES);

       glVertex3f(-5.02, -0.78, 0.0);
       glVertex3f(-3.431, -0.78, 0.0);
       glEnd();


       glColor3f(1.0,1.0,0.0);
    glBegin(GL_LINES);

       glVertex3f(-2.66,-0.36, 0.0);
       glVertex3f(-1.97,-0.36, 0.0);
       glEnd();


       glColor3f(1.0,1.0,0.0);
    glBegin(GL_LINES);

       glVertex3f(2,-1.19, 0.0);
       glVertex3f(4.017,-1.15, 0.0);
       glEnd();
  //glPopMatrix();

      glColor3f(1.0,1.0,0.0);
    glBegin(GL_LINES);

       glVertex3f(-1.21,-2.85, 0.0);
       glVertex3f(-2.01,-2.88, 0.0);
       glEnd();


    glColor3f(1.0,1.0,0.0);
    glBegin(GL_LINES);

       glVertex3f(-0.48,-0.77, 0.0);
       glVertex3f(1.07,-0.78, 0.0);
       glEnd();


       glColor3f(1.0,1.0,0.0);
    glBegin(GL_LINES);

       glVertex3f(2.76,-0.39, 0.0);
       glVertex3f(3.56,-0.39, 0.0);
       glEnd();


        glColor3f(1.0,1.0,0.0);
    glBegin(GL_LINES);

       glVertex3f(5.23,-0.39, 0.0);
       glVertex3f(5.96,-0.39, 0.0);
       glEnd();

        glColor3f(1.0,1.0,0.0);
    glBegin(GL_LINES);
       glVertex3f(-0.86,-1.60, 0.0);
       glVertex3f(-2.01,-1.60, 0.0);

       glEnd();

        glColor3f(1.0,1.0,0.0);
    glBegin(GL_LINES);
       glVertex3f(0.41,-1.57, 0.0);
       glVertex3f(1.17,-1.57, 0.0);

       glEnd();


         glColor3f(1.0,1.0,0.0);
    glBegin(GL_LINES);
       glVertex3f(-3.18,-3.61, 0.0);
       glVertex3f(-2.04,-3.61, 0.0);

       glEnd();


        glColor3f(1.0,1.0,0.0);
    glBegin(GL_LINES);
       glVertex3f(-0.45,-3.30, 0.0);
       glVertex3f(0.84,-3.30, 0.0);

       glEnd();


}
void draw()
{   //glClear(GL_COLOR_BUFFER_BIT);

    view();
    boat();

    glFlush();
     glutPostRedisplay();
    glutSwapBuffers();
}
void initialize()
{
    glClearColor(0.0,0.0,0.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-4,7,-5,5,-1,1);
}
int main(int Argc,char **Argv)
{
    PlaySound(TEXT("2.wav"), NULL, SND_FILENAME | SND_ASYNC);
    glutInit(&Argc, Argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(850,800);
    glutInitWindowPosition(50,50);
    glutCreateWindow("My Window");
    glutDisplayFunc(draw);
    initialize();
    glutMainLoop();
    return 0;
}
