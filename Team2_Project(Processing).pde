//프로세싱
import processing.net.*;
import processing.serial.*;

Server s; //pc
Serial a; //arduino
Client c; //app

float cx = 100;
float cy = 50;
float ra = 30;  // circle radius
int p; //pitch
int o; //roll
int r=0; //red
int g=0;  //green
int b=0; //blue
String temp[];

int wall[][]={{50,150,500,50},{150,300,200,50},{450,300,200,50},{50,450,150,50},{300,450,250,50},{300,600,350,50}//가로
              ,{300,300,50,350},{300,300,50,350},{150,450,50,200} //세로
              ,{150,0,600,50},{650,0,50,800},{0,0,50,800},{0,750,550,50} //끝벽
};

void ball(float tempX, float tempY){ //move
  cx -= tempX / 8;//checkAdd(tempX);
  cy -= tempY / 8;//checkAdd(tempY);
}

void fov(float x, float y, float size){ //Visual range
  noStroke();
  fill(150,255);
  circle(x, y, size);
}

void setup() {
  size(700,800);
  s = new Server(this, 12345);
  a = new Serial(this,"COM3",9600);
}


void draw(){
  background(0); 
  c = s.available();
  if(c!=null){
    String m = c.readString();
    int n = m.indexOf("\r\n\r\n") + 4;
    m = m.substring(n);
   
    temp = m.split("/");

    p = int(temp[0]);
    o = int(temp[1]);
    r = int(temp[2]);
    g = int(temp[3]);
    b = int(temp[4]);
    print(cx,"/",cy,"\n");
    ball(o,p);
  }
  fov(cx,cy,300);
  
  for (int n = 0; n < wall.length; n++){ //wall
    float sx = wall[n][0];
    float sy = wall[n][1];
    float sw = wall[n][2];
    float sh = wall[n][3];
    stroke(0);
    fill(0);
    rect(sx,sy, sw,sh);
    }
    player();
    hit();
    goal();
  }
  
void player(){
  fill(r,g,b);
    noStroke();
    ellipse(cx,cy, ra*2,ra*2);
}
void goal(){
    boolean goal = circleRect(cx,cy,ra,550,850,100,50);
    if (goal) {
      a.write("goal");
      delay(20000);
      cx=100;
      cy=50;
    }
}
  
void hit(){
  for (int n = 0; n < wall.length; n++){
    float sx = wall[n][0];    // square position
    float sy = wall[n][1];
    float sw = wall[n][2];    // and dimensions
    float sh = wall[n][3];
    boolean hit = circleRect(cx,cy,ra, sx,sy,sw,sh);
    if (hit) {
      cx=100;
      cy=50;
      a.write("die");
    }
  }
}

// CIRCLE/RECTANGLE
boolean circleRect(float cx, float cy, float radius, float rx, float ry, float rw, float rh) {

  // temporary variables to set edges for testing
  float testX = cx;
  float testY = cy;

  // which edge is closest?
  if (cx < rx)         testX = rx;      // test left edge
  else if (cx > rx+rw) testX = rx+rw;   // right edge
  if (cy < ry)         testY = ry;      // top edge
  else if (cy > ry+rh) testY = ry+rh;   // bottom edge

  // get distance from closest edges
  float distX = cx-testX;
  float distY = cy-testY;
  float distance = sqrt( (distX*distX) + (distY*distY) );

  // if the distance is less than the radius, collision!
  if (distance <= radius) {
    return true;
  }
  return false;
}

/* 참고자료
충돌함수 : http://www.jeffreythompson.org/collision-detection/table_of_contents.php
시야 아이디어 : https://www.youtube.com/watch?v=XxzY5US6W-8
미로 표현 방식: https://kocoafab.cc/make/view/629 */
