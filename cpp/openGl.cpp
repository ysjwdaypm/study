#include<math.h>
#include<gl.h>

const int n = 20;
const float R = 0.5f;
const float Pi = 3.1415926;

int main(void){
    
    int i;
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);
    for(i = 0; i < n;i++){
        glVertex2f(R*cos(2*Pi/n * i),R*sin(2*Pi/n*i));
    }
    
    glEnd();
    glFlush();
    return 0;
}