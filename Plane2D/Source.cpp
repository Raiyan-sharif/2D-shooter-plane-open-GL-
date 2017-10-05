

#include <windows.h>

#include <math.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
using namespace std;
void drawMissileLeft(int missileX, int missileY);
void detectCollision();
int changemode=0;
int vX1,vY1;
int point=0;
GLfloat rotation = 90.0;
float posX = 0, posY = 0, posZ = 0;
float move_unit = 3;
float rate = 1.0f;
float angle = -0.0f;
float RotateX = 0.f, RotateY = 45.f;
int missileRX = 0;
int missileRY = 0;
float plan_trans=-2;
float backgroundR=0.0,backgroundG=0.0,backgroundB=0.0;
int lifeOfPlane=7;
int missileXvar = 0;
int viewY1, viewX1, viewX2, viewX3, viewY2, viewY3,viewZ1=0 ;
int enemyX=1200,enemyY=170;

//Initializes 3D rendering
void initRendering() {
	glEnable(GL_DEPTH_TEST);
}


//Called when the window is resized
void handleResize(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
}


void Timer(int value)
{
	glutPostRedisplay();      
	glutTimerFunc(16, Timer, 0); 
}



int y11=5;
void fireMissileLeft()
{
	//cout<<missileXvar;
	missileXvar = missileXvar + 3;


	if (missileXvar >= 1300)
	{
		missileXvar = 0;
		drawMissileLeft(missileXvar, y11);
	}
	else
	{
		drawMissileLeft(missileXvar, y11);
	}

}


void fireEnemy()
{
	

	if (enemyX <= 0)
	{
		enemyX = 1300;

	}
	else
	{
		enemyX -= 2;
	}




}
void plane1() {



	glColor3ub(255, 0, 0);
	glBegin(GL_POLYGON);
	glPointSize(3.0);

	glVertex3i(10 + viewX1, 245 + viewY1, viewZ1);
	glVertex3i(15 + viewX1, 245 + viewY1, viewZ1);
	glVertex3i(35 + viewX1, 235 + viewY1, viewZ1);
	glVertex3i(15 + viewX1, 225 + viewY1, viewZ1);
	glEnd();

	//plane wing back
	
	glColor3ub(255, 0, 0);
	//cout<< viewX1<<" "<<viewY1<<" "<<viewZ1<<endl;
	glBegin(GL_POLYGON);
	glVertex3i(80 + viewX1, 225 + viewY1, viewZ1);
	glVertex3i(90 + viewX1, 245 + viewY1, viewZ1);
	glVertex3i(85 + viewX1, 245 + viewY1, viewZ1);
	glVertex3i(50 + viewX1, 225 + viewY1, viewZ1);
	glEnd();
	
	glColor3ub(255, 0, 0);
	glBegin(GL_POLYGON);
	glVertex3i(80 + viewX1, 225 + viewY1, viewZ1);
	glVertex3i(90 + viewX1, 245 + viewY1, viewZ1);
	glVertex3i(88 + viewX1, 245 + viewY1, viewZ1);
	glVertex3i(55 + viewX1, 225 + viewY1, viewZ1);
	glEnd();
	// body of the plane
	glColor3ub(0, 0, 255);
	glBegin(GL_POLYGON);
	glVertex3i(90 + viewX1, 220 + viewY1, viewZ1);
	glVertex3i(30 + viewX1, 220 + viewY1, viewZ1);
	glVertex3i(15 + viewX1, 225 + viewY1, viewZ1);
	glVertex3i(35 + viewX1, 235 + viewY1, viewZ1);
	glVertex3i(80 + viewX1, 235 + viewY1, viewZ1);
	glVertex3i(90 + viewX1, 230 + viewY1, viewZ1);
	glEnd();
	
	glColor3ub(0, 0, 255);
	glBegin(GL_POLYGON);
	glVertex3i(90 + viewX1, 227 + viewY1, viewZ1);
	glVertex3i(30 + viewX1, 227 + viewY1, viewZ1);
	glVertex3i(30 + viewX1, 230 + viewY1, viewZ1);
	glVertex3i(90 + viewX1, 230 + viewY1, viewZ1);
	glEnd();
	
	glColor3ub(255, 0, 0);//head
	glBegin(GL_POLYGON);
	glVertex3i(90 + viewX1, 220 + viewY1, viewZ1);
	glVertex3i(90 + viewX1, 230 + viewY1, viewZ1);
	glVertex3i(100 + viewX1, 222 + viewY1, viewZ1);
	glVertex3i(100 + viewX1, 220 + viewY1, viewZ1);
	glEnd();

	glColor3ub(0, 220, 0);
	//glass of the plane
	glBegin(GL_POLYGON);
	glVertex3i(80 + viewX1, 225 + viewY1, viewZ1);
	glVertex3i(90 + viewX1, 225 + viewY1, viewZ1);
	glVertex3i(90 + viewX1, 228 + viewY1, viewZ1);
	glVertex3i(78 + viewX1, 237 + viewY1, viewZ1);
	glEnd();
	//Right wing of plane
	glColor3ub(255, 0, 0);
	glBegin(GL_POLYGON);
	glVertex3i(80 + viewX1, 225 + viewY1, viewZ1);
	glVertex3i(35 + viewX1, 212 + viewY1, viewZ1);
	glVertex3i(25 + viewX1, 212 + viewY1, viewZ1);
	glVertex3i(50 + viewX1, 225 + viewY1, viewZ1);
	glEnd();
	
    fireMissileLeft();
    fireEnemy();
    detectCollision();
   // cout<<point<<endl;
	glutPostRedisplay();

}
void detectCollision(){
    if(vX1 +50 >= enemyX+25 && vX1+50 <= enemyX+65){
        if(vY1 + 250 >=enemyY && vY1 + 250 <=enemyY+10){
            point++;
			missileXvar = move_unit;
            enemyX = 1300;
            vX1=3;
        }
    }



}
void lifeTime(){
	
}

void collisionOfPlane(){
	//lifeTime();
	//cout<<enemyX+25<<" "<<enemyX+65<<" "<<viewX1+15<<" "<<viewX1+90<<endl;
	
	//else{lifeOfPlane--;}

}
void drawMissileLeft(int missileX, int missileY)

{
	missileRX = missileX + 150;
	missileRY = missileY + 450;
    vX1 = viewX1,vY1 = viewY1;
    vX1 = missileX + viewX1;

    vY1 = missileY + viewY1-25;
    detectCollision();
	//printf("%d %d \n",missileRX,missileRY);
	//missile head
	glBegin(GL_TRIANGLES);
	glColor3f(1, 0, 0);
	glVertex2f(vX1 + 50, vY1 + 250);
	glVertex2f(vX1 + 35, vY1 + 247);
	glVertex2f(vX1 + 35, vY1 + 252);
	glEnd();

	//body
	glBegin(GL_QUADS);
	glColor3f(.8, .4, .1);
	glVertex2f(vX1 + 700 - 665, vY1 + 447-200);
	glVertex2f(vX1 + 700 - 665, vY1 + 452-200);
	glVertex2f(vX1 + 700 - 660, vY1 + 452-200);
	glVertex2f(vX1 + 700 - 660, vY1 + 447-200);
	glEnd();

	


}
void drawCircle(int x1, int y1, int radius)

{
	float x2, y2;
	float angle;
	glBegin(GL_POLYGON);
	for (angle = .1f; angle<361.0f; angle += 1.0f)

	{
		x2 = x1 + sin(angle)*radius;
		y2 = y1 + cos(angle)*radius;
		glVertex2f(x2, y2);
	}

	glEnd();
}



void cloud()

{
	glColor3f(0.4, 0.4, 0.4);
	drawCircle(45, 680, 20);
	drawCircle(75, 680, 40);
	drawCircle(90, 680, 45);
	drawCircle(120, 680, 35);
	drawCircle(140, 680, 20);

	drawCircle(200, 670, 25);
	drawCircle(220, 670, 35);
	drawCircle(260, 670, 50);
	drawCircle(290, 670, 35);
	drawCircle(320, 670, 20);

}

void tree()
{
	//right leaf
	glColor3f(0, 0.98, 0);
	drawCircle(1170, 288, 25);
	drawCircle(1190, 344, 45);
	drawCircle(1185, 320, 30);
	drawCircle(1245, 380, 55);
	drawCircle(1238, 310, 25);
	drawCircle(1259, 315, 30);
	drawCircle(1200, 295, 35);
	drawCircle(1280, 315, 45);

	//left leaf

	glColor3f(0, 0.98, 0);
	drawCircle(956, 364, 20);
	drawCircle(990, 361, 25);
	drawCircle(1046, 361, 25);
	drawCircle(1070, 360, 20);

	glColor3f(0, 0.98, 0);
	drawCircle(980, 400, 25);
	drawCircle(1020, 387, 35);
	drawCircle(1065, 392, 25);

 	glColor3f(0, 0.98, 0);
	drawCircle(999, 440, 30);
	drawCircle(1030, 435, 35);



}
void score(){
	int i, j, k;
	i = point / 100;
	j = point / 10 - i * 10;
	k = point - j * 10 - i * 100;
	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glTranslated(120, 20, 0);
	glScaled(.25, .25, 0);
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'S');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'c');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'o');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'r');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'e');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)':');
	glColor3f(1.0, 0.0, 1.0);
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)i + 48);
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)j + 48);
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)k + 48);
	glTranslated(-120, -20, -0);
	glPopMatrix();
}
void background()
{
	//*******backgrounds*******
	
	glMatrixMode(GL_MODELVIEW); 
	glLoadIdentity();

    glColor3f(0.30, 0.701, 0.235);
	glPushMatrix();
	score();
	//collisionOfPlane();
	glBegin(GL_QUADS);
	
	glColor3f(backgroundR, backgroundG, backgroundB);
	//glColor3f(0.70, 0.76, 0.96);
	glVertex2i(-12, 420);
	glVertex2i(1290, 420);
	glVertex2i(1290, 780);
	glVertex2i(-12, 780);
	glEnd();
	//glFlush();
	
	///back grass left
	glBegin(GL_QUADS);
	glColor3f(0.30, 0.701, 0.235);
	glVertex3i(0, 420,0);
	glVertex3i(0, 80,0);
	glVertex3i(1236, 80,0);
	glVertex3i(625, 420,0);
	glEnd();


	glFlush();
	glPopMatrix();

	
	///back grass right
	/*glBegin(GL_TRIANGLES);
	glColor3f(0.30, 0.701, 0.235);
	glVertex3i(1277, 117,0);
	glVertex3i(1277, 420,0);
	glVertex3i(600, 420,0);
	glEnd();
	glFlush();*/

	///river side
  	/*glBegin(GL_QUADS);

	glColor3f(0.30, 0.701, 0.235);
	glVertex3i(0, 80,0);
	glVertex3i(0, 50,0);
	glVertex3i(1277, 50,0);
	glVertex3i(1277, 80,0);
	glEnd();
	glFlush();*/



	//glFlush();
	glPopMatrix() ;
}
void objectView(){
	glPushMatrix();
	glBegin(GL_QUADS);
	glColor3f(0.1, 0.1, 0.1);
	glVertex3i(1230+50, 304, 0);
	glVertex3i(1230+50, 169, 0);
	glVertex3i(1260, 169, 0);
	glVertex3i(1260, 304, 0);
	glEnd();
	glPopMatrix();
}

void treeBase()
{
	//base of 1st tree
	
	glTranslatef(plan_trans, 0, 0);
	glBegin(GL_QUADS);
	glColor3f(0.313, 0.321, 0.258);
	glVertex3i(1230, 304, 0);
	glVertex3i(1230, 169, 0);
	glVertex3i(1260, 169, 0);
	glVertex3i(1260, 304, 0);
	glEnd();
	glFlush();

	glBegin(GL_QUADS);
	glColor3f(0.313, 0.321, 0.258);
	glVertex3i(1230, 180, 0);
	glVertex3i(1225, 170, 0);
	glVertex3i(1265, 170, 0);
	glVertex3i(1260, 180, 0);
	glEnd();
	glFlush();
	
	//base of tree 2

	glBegin(GL_QUADS);
	glColor3f(0.313, 0.321, 0.258);
	glVertex3i(1004, 360, 0);
	glVertex3i(1004, 267, 0);
	glVertex3i(1027, 267, 0);
	glVertex3i(1027, 360, 0);
	glEnd();
	glFlush();

	glBegin(GL_QUADS);
	glColor3f(0.313, 0.321, 0.258);
	glVertex3i(1004, 267, 0);
	glVertex3i(1000, 265, 0);
	glVertex3i(1029, 265, 0);
	glVertex3i(1027, 267, 0);
	glEnd();
	glFlush();
    
	tree();
	objectView();
	

}
void enemyObject(){
    glBegin(GL_QUADS);
	glColor3f(1, 0.0, 0.0);
	//cout<<enemyX<<endl;
	//cout<<enemyY<<endl;
	//lifeOfPlane--;
	glVertex3i(enemyX+30, enemyY+10, 0);
	glVertex3i(enemyX+25, enemyY, 0);
	glVertex3i(enemyX+65, enemyY, 0);
	glVertex3i(enemyX+60, enemyY+10, 0);
	glEnd();

	glFlush();

}
void check(){

	glBegin(GL_QUADS);
	glColor3f(0.0, 1.0, 0.0);
	if(lifeOfPlane<=6 && lifeOfPlane>4){
		glColor3f(1.0, 1.0, 0.0);
	}
	else if(lifeOfPlane>=7){
		glColor3f(0.0, 1.0, 0.0);
		//glScalef(.1, 0.0,0.0) ;
	}
	else{
		glColor3f(1.0, 0.0, 0.0);
		//glScalef(.1, 0.0,0.0) ;
		
		
	}
	if(enemyX==100){
		lifeOfPlane--;
	}
	glScalef(.5, 0.0,0.0) ;
		glVertex2f(1000,750);
		glVertex2f(1000, 710);
		glVertex2f(1100, 710);
		glVertex2f(1100, 750);
		glEnd();
		glFlush();


}
void Display1(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.5);
	glPointSize(4.0);
	glPushMatrix();
	glBegin(GL_QUADS);

	glColor3f(0.30, 0.701, 0.235);
	glVertex3i(0, 80,0);
	glVertex3i(0, 50,0);
	glVertex3i(1277, 50,0);
	glVertex3i(1277, 80,0);
	glEnd();
	background();
	score();
	
	
	//collisionOfPlane();
	Timer(12);
	
	
	glPushMatrix();
	check() ;
	
	
	glPopMatrix();
	
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();
	glScalef(0.7, 0.7, 0.0) ;
	glTranslatef(213.0, 595.0f, 1);
	glRotatef(angle, 0.0f, 0.0f, 1.0f);
	if(angle >= 400){
	angle = angle - 400;
	}
	else{
        angle+=.50;
	}
	glTranslatef(-100.0f, -500.0f, -2.0f);


	
	glPopMatrix();
	glFlush();
	glPushMatrix();
	glTranslatef(-posX, -posY, -posZ);
	//Beep(523,500);
	treeBase();
	glTranslatef(posX, posY, posZ);
	glPopMatrix();
	
	//glTranslatef(-100, 0, 0);
	glPopMatrix();

    glMatrixMode(GL_MODELVIEW); //Switch to the drawing perspective
	glLoadIdentity(); //Reset the drawing perspective

    glTranslatef(0.0,370.0, 0.0) ;
   // glTranslatef(posX, posY, posZ) ;

    plane1() ;
    enemyObject();
    glPopMatrix( ) ;

	glLoadIdentity();

	glPushMatrix();
	glTranslatef(posX, posY, posZ);
	cloud();

	glPopMatrix();

	glutSwapBuffers();

}

void myInit(void)
{
	glClearColor(0.30, 0.701, 0.235, 0.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	glPointSize(3.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 1280.0, 0.0, 768.0);
}

void update(int value)
{

	//cout<< "p " << point <<endl;
	posX += move_unit;
	if (posX>1400)
	{
		posX -= 2000;
	}



	//move background
	plan_trans += 0.01f;
	if (plan_trans > 1.0) {
		plan_trans -=3.5;
	}



	glutPostRedisplay();
	glutTimerFunc(50, update, 0);
}

void keyboard(int key, int x, int y)
{
	switch (key){


	case GLUT_KEY_RIGHT:

		viewX1 +=5;
		Beep(523,10);
		glutPostRedisplay();

		break;

	case GLUT_KEY_LEFT:

		viewX1 -= 5;
		Beep(523,10);
		glutPostRedisplay();

		break;
    case GLUT_KEY_UP:
        viewY1+=5;
		Beep(523,10);
        glutPostRedisplay();

		break;
    case GLUT_KEY_DOWN:
        viewY1-=5;
		Beep(1523,10);
        glutPostRedisplay();

		break;
    
	case GLUT_KEY_F3 :
		//glColor3f(0.70, 0.76, 0.96);
		Beep(1523,300);
		changemode++;
		if(changemode==0)
		{
			backgroundR=0;backgroundG=0;backgroundB=0;
		}
		else if(changemode==1)
		{
			backgroundR=0.70;backgroundG=0.76;backgroundB=0.96;
		}
		else if(changemode==2)
		{
			backgroundR=1;backgroundG=1;backgroundB=1;
		}
		else{
			backgroundR=0.70;backgroundG=0.76;backgroundB=0.96;
			changemode=-1;
		}



	default:
		break;


	}

}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1300, 800);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Shooter plane");
	glutDisplayFunc(Display1);
	myInit();
	glutTimerFunc(1000, update, 0);
    glutSpecialFunc(keyboard);


	glutMainLoop();
}
