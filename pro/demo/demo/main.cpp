#include <GLUT/GLUT.h>
#include <iostream>
#include <math.h>

static GLfloat spin = 0.5;
GLfloat max = 2.0f;
int vv = 1;

void init(void)
{
    glClearColor(0.0,0.0,0.0,0.0);
    glShadeModel(GL_FLAT);   //设置着色模式,恒定着色或光滑着色
}

void display(void)
{
    
    vv++;
//    printf("vv=%d\n",vv);
    glViewport(0, 0,300,300);
    glLoadIdentity();
    glClear(GL_COLOR_BUFFER_BIT);
    glShadeModel(GL_SMOOTH);//设置为光滑明暗模式
    glPushMatrix();
//    glPointSize(50.0F);
    glRotatef(spin,0.0,1.0,0.0);
    glColor3f(1.0,1.0,1.0);
    int v = 100;
    glRectf(-0.5,-0.5,0.3,0.2);
    
//    glEnable(GL_CULL_FACE);
//    glCullFace(GL_BACK);
    glPolygonMode(GL_FRONT, GL_FILL); // 设置正面为填充模式
    glPolygonMode(GL_BACK, GL_LINE);  // 设置反面为线形模式
//    glFrontFace(GL_CW);              // 设置逆时针方向为正面
    glBegin(GL_POLYGON);              // 按逆时针绘制一个正方形，在左下方
    glVertex2f(-0.5f, -0.5f);
    glVertex2f(0.0f, -0.5f);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(-0.5f, 0.0f);
    glEnd();
    glPopMatrix();
    
    glPushMatrix();
    glRotatef(60,1.0,1.0,0.0);
    glColor3f(1.0,1.0,0.0);
    glBegin(GL_POLYGON);              // 按顺时针绘制一个正方形，在右上方
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.0f, 0.5f);
    glVertex2f(0.5f, 0.5f);
    glVertex2f(0.5f, 0.0f);
    glEnd();
    
    
    glPopMatrix();
    
    glutSwapBuffers();
}

int v = 1;

void spinDisplay(void)
{
    
    spin += v;
//    v *= -1;
    if(spin > 360.0)
        spin -= 360.0;
    glutPostRedisplay(); //使每次循环先调用该函数所在函数，然后调用display
//    printf(" elapsed time is %d\n",glutGet(GLUT_ELAPSED_TIME));
}



void reshape(int w, int h)
{
    printf("w=%d,h=%d\n",w,h);
//    max++;
//    glOrtho(-(max), max, -(max), max, -1.0, 1.0);
    
    
    glViewport(0, 0, (GLsizei)w, (GLsizei)h); //选择一个所要的绘图区域
    
   // glOrtho(-(max), max, -(max), max, -1.0, 1.0);
    

    
//    glOrtho(-(max), max, -(max), max, -1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
//    glOrtho(-(max), max, -(max), max, -1.0, 1.0);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    
    
    
//    glOrtho(-(max), max, -(max), max, -1.0, 1.0);
}

void mouse(int button, int state, int x, int y)
{
    switch(button)
    {
        case GLUT_LEFT_BUTTON:
            if(state == GLUT_DOWN)
            {
//                glOrtho(-(max), max, -(max), max, -1.0, 1.0);
                glutIdleFunc(spinDisplay);
            }
            
            break;
        case GLUT_MIDDLE_BUTTON:
            if(state == GLUT_DOWN)
                glutIdleFunc(0);
            break;
        default:
            break;
            
    }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
//    glutInitWindowSize(250,250);
//    glutInitWindowPosition(100,100);
    glutCreateWindow(argv[0]);
    init();
    
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMouseFunc(mouse);
//    printf("screen width is %d",glutGet(GLUT_WINDOW_W));
    
    
//    char* max[128];
////    printf("---- %d",sizeof(max));
//    float i = atan2(1,1)*180/M_PI;
//    printf("--------ysj----%f\n",i);
//    
//    float ii = atan2(-1,1)*180/M_PI;
//    printf("--------ysj----%f\n",ii);
//    float v = atan2(1,-1)*180/M_PI;
//    printf("--------ysj----%f\n",v);
//    
//    float iii = atan2(-1,-1)*180/M_PI;
//    printf("--------ysj----%f\n",iii);
//    
    
    glutMainLoop();
    
    
    
    return 0;
}