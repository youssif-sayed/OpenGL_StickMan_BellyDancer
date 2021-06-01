#include <iostream>
#include <GL/glut.h>
#include <math.h>
using namespace std;
float y1LeftHand = -500;    //x-axis 3l4an lma a8yr 7rkt l 2ed l 4mal 
float y2LeftHand = -500;    //x-axis 3l4an lma a8yr 7rkt l 2ed l 4mal 
float y1RightHand = -500;   //x-axis 3l4an lma a8yr 7rkt l 2ed l ymen 
float y2RightHand = -500;   //x-axis 3l4an lma a8yr 7rkt l 2ed l ymen
int leftHandState = 0;  //state 3l4an a3rf l 2ed l 4mal t7t wla fo2 (t7t by defult)
int rightHandState = 0; //state 3l4an a3rf l 2ed l ymen t7t wla fo2 (t7t by defult)
float hza = 0;  //3l4an ydef hzt l wst 
float ktf = 0;  //3l4an ydef r34t l ktf



void MyInit(void)   //bn3ml create ll screen l hn4t8l 3leha
{
    glClearColor(1,1,1,0);  //5lena lon l background beda
    
    glPointSize(100);   //7gm l point
    gluOrtho2D(-1000, 1000, -1000,500); //dimentions l screen mn -1000 4mal w 1000 ymen w -1000 t7t w 500 fo2
    //dy l dimntions l hn4t8l 3leha fy l rsm
}
void head()
{   
   
    glBegin(GL_POLYGON);    //hn3mlo polygon 3l4an ymlah w dy function 3l4an nbd2 rsmt l ras
    glColor3f(0.0f,0.0f,0.0f);  //l lon eswd
    float pi; 
    for (int i = 0;i <= 360;i++)    //hnlf 360 drga b nos kotr 160 w nrsm l dyra
    {
        pi = i * 3.14 / 180;
        glVertex2f( 160 * cos(pi), 160 * sin(pi));
        if (i == 0||i==1) // if statment mlha4 lzma
            glColor3f(0.0f,0.0f,0.0f);
    }
    glEnd();    //bn2fl l 4kl bta3 l ras 
}
void body()
{   glBegin(GL_POLYGON);    //bnbd2 rsmt l gsm
    glColor3f(0.0f, 0.0f, 0.0f);    //l lon eswd
    
    glVertex2i(-25, -150);
    glVertex2i(25, -150);
    glVertex2i(25+ktf, -250);  //l ktf 7to hna 3l4an l point da 3nd l ktf
    glVertex2i( 25, -650);  //7att dy 3l4an tsbt l gsm lma l r2asa thz
    glVertex2i(25+hza, -800);   //l hza httha hna 3l4an l point da 3nd l wst
    glVertex2i(-25+hza, -800);   //l hza httha hna 3l4an l point da 3nd l wst
    glVertex2i(-25, -650);  //7att dy 3l4an tsbt l gsm lma l r2asa thz *bs m4 48ala*
    glVertex2i(-25+ktf, -250);  //l ktf 7to hna 3l4an l point da 3nd l ktf

    glEnd();    //bn2fl rsmt l gsm
}
void handR()
{   glBegin(GL_POLYGON);    //bnbd2 rsmt l 2ed l ymen
    glColor3f(0.0f, 0.0f, 0.0f);    //l lon eswd
    //23do b2a t5ylo l dimentions bs na 3aml + ktf 3l4an yro7 w yegi m3 l r34a
    //y3ni lw l r34a gt ymen yzwd 50 3l4an n7rko ymen fy l x
    glVertex2i(-25+ktf, -250);  //l ktf 7to hna 3l4an l point da 3nd l ktf
    glVertex2i(25+ktf, -250);  //l ktf 7to hna 3l4an l point da 3nd l ktf
    glVertex2i(285, y1RightHand);   //hna 7att l y 3l4an lma a7b a7rkha w hia -500 by defualt
    glVertex2i(235, y2RightHand);   //hna 7att l y 3l4an lma a7b a7rkha w hia -500 by defualt
    glEnd();    //bn2fl rsmt l 2ed l ymen
}
void handL()
{   glBegin(GL_POLYGON);    //bnbd2 rsmt l 2ed l 4mal 
    glColor3f(0.0f, 0.0f, 0.0f);    //l lon eswd
    //23do b2a t5ylo l dimentions bs na 3aml + ktf 3l4an yro7 w yegi m3 l r34a
    //y3ni lw l r34a gt ymen yzwd 50 3l4an n7rko ymen fy l x
    glVertex2i(25+ktf, -250);   //l ktf 7to hna 3l4an l point da 3nd l ktf
    glVertex2i(-25+ktf, -250);  //l ktf 7to hna 3l4an l point da 3nd l ktf
    glVertex2i(-285, y1LeftHand);   //hna 7att l y 3l4an lma a7b a7rkha w hia -500 by defualt
    glVertex2i(-235, y2LeftHand);   //hna 7att l y 3l4an lma a7b a7rkha w hia -500 by defualt
    glEnd();    //bn2fl rsmt l 2ed l 4mal
}
void legR()
{   glBegin(GL_POLYGON);    //bnbd2 rsmt l rgl l ymen
    glColor3f(0.0f, 0.0f, 0.0f);    //l lon eswd
    //23do b2a t5ylo l dimentions bs na 3aml + hza 3l4an yro7 w yegi m3 l hza 
    //y3ni lw l hza gt ymen yzwd 50 3l4an n7rko ymen fy l x
    glVertex2i(-25+hza, -800);   //l hza httha hna 3l4an l point da 3nd l wst
    glVertex2i(25+hza, -800);  //l hza 7ttha hna 3l4an l point da 3nd l wst
    glVertex2i(235, -1000);
    glVertex2i(185, -1000);
    glEnd();    //bn2fl rsmt l rgl l 4mal
}
void legL()
{   glBegin(GL_POLYGON);    //bnbd2 rsmt l rgl l 4mal
    glColor3f(0.0f, 0.0f, 0.0f);    //l lon eswd
    //23do b2a t5ylo l dimentions bs na 3aml + hza 3l4an yro7 w yegi m3 l hza 
    //y3ni lw l hza gt ymen yzwd 50 3l4an n7rko ymen fy l x
    glVertex2i(25+hza, -800);   //l hza httha hna 3l4an l point da 3nd l wst
    glVertex2i(-25+hza, -800);  //l hza 7ttha hna 3l4an l point da 3nd l wst
    glVertex2i(-235, -1000);
    glVertex2i(-185, -1000);
    glEnd();    //bn5ls rsmt l rgl l 4mal
}
void hezamLR2s()
{
    glBegin(GL_POLYGON);    //bnbd2 rsmt l hezam
    glColor3f(1.0f, 0.0f, 1.0f);    //l lon pink
    //23do b2a t5ylo l dimentions bs na 3aml + hza 3l4an yro7 w yegi m3 l hza 
    //y3ni lw l hza gt ymen yzwd 50 3l4an n7rko ymen fy l x
    glVertex2i(-50+hza, -700);  
    glVertex2i(50 + hza, -700);
    glVertex2i(85 + hza, -750);
    glVertex2i(85 + hza, -800);
    glVertex2i(50 + hza, -750);
    glVertex2i(-50 + hza, -750);
    glEnd();    //bn5ls rsmt l 7zam
}


void display(void)  //function l bn3rdo
{
    
    glClear(GL_COLOR_BUFFER_BIT);   //bndf l screen 3l4an n4t8l 3la ndafa 
    //hndef l functions bta3t agza2 l gsm
    head();
    body();
    handR();
    handL();
    legR();
    legL();
    hezamLR2s();
    

    glFlush();  //5lsna l rsma
    
}

void mouseClcik(int button,int state, int x ,int y) //function lw dost 3la l mouse(lzorar,mdas 3leh wla la,mkan l mouse f x,mkan l mouse f y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)   //lw l click 4mal etdast fy l mouse
    {
        if (leftHandState == 0) //lw l 2ed t7t hyrf3ha fo2
        {
            y1LeftHand = 0 ;    //tl3t l 2ed mn bra 3nd 0
            y2LeftHand = 0 ;    //tl3t l 2ed mn gwa 3nd l zero
            leftHandState = 1;  //5lena l state b wa7d 3l4an y3rf enha mrfo3a
        }
        else {  //lw m4 t7t y5leha t7t
            y1LeftHand = -500;  //nzlt l 2ed mn bra 3nd -500
            y2LeftHand = -500;  //nzlt l 2ed mn gwa 3nd -500
            leftHandState = 0;  //5lena l state b wa7d 3l4an y3rf enha nzlt
        }
        
    }
    else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) //lw click ymen etdast fy l mouse
    {
        if (rightHandState == 0)    //lw l 2ed t7t hyrf3ha fo2
        {
            y1RightHand = 0;    //tl3t l 2ed mn bra 3nd 0
            y2RightHand = 0;    //tl3t l 2ed mn gwa 3nd l zero
            rightHandState = 1; //5lena l state b wa7d 3l4an y3rf enha mrfo3a
        }
        else {  //lw m4 t7t y5leha t7t
            y1RightHand = -500;  //nzlt l 2ed mn bra 3nd -500
            y2RightHand = -500;  //nzlt l 2ed mn gwa 3nd -500
            rightHandState = 0;  //5lena l state b wa7d 3l4an y3rf enha nzlt
        }
    }
        glutPostRedisplay();    //bn3ed rsm l function l display tani 
}

void keyPress(unsigned char key,int x,int y)    //function lw dost 3la l keyboard(lzorar l etdas 3leh,mkano fy l x,mkano fy l y)
{
    switch (key)    //swich 3l4an n4of anhy zorar etdas 3leh
    {
    case'w':    //l wst ydy hza 4mal
        hza = -25;
        break;
    case'e':    //l wst f mkano
        hza = 0;
        break;
    case'r':    //l wst ydy hza ymen
        hza = 25;
        break;
    case's':    //l ktf ydy r34a 4mal
        ktf = -25;
        break;
    case'd':    //l ktf f mkano
        ktf = 0;
        break;
    case'f':    //l ktf ydy r34a ymen
        ktf = 25;
        break;
    case'=':    //hnkbr l rsma bnsbt 1.1 fy l (x,y) w z = 0 3l4an dy 2D
        glScalef(1.1,1.1,0);
        break;
    case'-':    //hns8r l rsma bnsbt 0.9 fy l (x,y) w z = 0 3l4an dy 2D
        glScalef(0.9,0.9,0);
        break;
    case',':    //hn7rk l rasma -50 fy l x y3ni hnwdy l rsma 4mal
        glTranslatef(-50,0,0);
        break;
    case'.':    //hn7rk l rasma 50 fy l x y3ni hnwdy l rsma ymen
        glTranslatef(50, 0, 0);
        break;
    case'0':    //hnlf 90 drga 7wlen l z
        glRotatef(90, 0, 0, 1);
        break;
    case'9':    //hnlf -90 drga 7wlen l z
        glRotatef(-90, 0, 0, 1);
        break;

    }
    glutPostRedisplay();
}




int main(int argc,char** argv)
{
    glutInit(&argc, argv);  //bn create l prnamg
    glutCreateWindow("hz ta5od l drga");    //dy l bnktb feha esm l prnamg
    glutInitWindowSize(480, 720);   //dy l mfrod bt3ml 7gm l screen l feha l rsma *bs m4 48ala m4 3arf leh*
    glutInitWindowPosition(500, 500);   //dy l mfrod bt3ml mkan l screen l feha l rasma *bs bardo m4 48ala m4 3arf leh*
    glutDisplayFunc(display);   //dy l mnha bn3rd l e7na rsmnah
    glutMouseFunc(mouseClcik);  //dy 3l4an yra2b 7rkt l mouse
    glutKeyboardFunc(keyPress); //dy btra2b 7rkt l keyboard
    MyInit();   //bn create ll screen l hn4t8l 3leha
    glutMainLoop(); //function lzom l brnamg w 5las
    
    return 0;
}
