#include "matrix.h"

int VRx = A1;
int VRy = A0;

int columnValue[8] = {0};

void DrawCircle()
{
  int i=0;
  
  Clear();
  
  WritePixel(2+i, 4);
  WritePixel(2+i, 5);
  WritePixel(3+i, 6);
  WritePixel(4+i, 7);
  WritePixel(5+i, 7);
  WritePixel(6+i, 6);
  WritePixel(7+i, 5);
  WritePixel(7+i, 4);
  WritePixel(6+i, 3);
  WritePixel(5+i, 2);
  WritePixel(4+i, 2);
  WritePixel(3+i, 3);
  
  i++;
}

int xState()//Returns -1, 0, 1
{
  int xState = analogRead(VRx);

  if (xState>=24 && xState<=1000)
    return 0;
    
  else if (xState<24)
    return 1;

  else if (xState>1000)
    return -1;
}

int yState()//Returns -1, 0, 1
{
  int yState = analogRead(VRy);

  if (yState>=24 && yState<=1000)
    return 0;
    
  else if (yState<24)
    return -1;

  else if (yState>1000)
    return 1;
}

void setup() {

  pinMode(VRx, INPUT);
  pinMode(VRy, INPUT);

  Serial.begin(9600);

  SetupMatrix();
}

  int xPos = 4;
  int yPos = 4;

  int xLastCycle = 0;
  int yLastCycle = 0;

  int ticker = 0;

  bool matrixState[8][8] = {0};//All initialized to zero state
  int snakeXCoords[64] = {0};//Index 0 is tail of snake
  int snakeYCoords[64] = {0};
  int snakeLength = 1;//True length (which includes leader) is one more than this value

void loop() {
  Clear();//Erases last iteration's display

  if (!xLastCycle)
  {
    if (xState())//Only enters once per joystick movement
    {
      snakeXCoords[snakeLength] = xPos;
      snakeYCoords[snakeLength] = yPos;
      snakeLength++;
    }
    
    matrixState[xPos][yPos] = true;//Adds last pixel coordinates to matrixState
    xPos += xState();//Updates current xPos
  }

  if (!yLastCycle)
  {
    if (yState())//Only enters once per joystick movement
    {
      snakeXCoords[snakeLength] = xPos;
      snakeYCoords[snakeLength] = yPos;
      snakeLength++;
    }
    
    matrixState[xPos][yPos] = true;
    yPos += yState();
  }

  WritePixel(xPos, yPos);//Writes Leader

  for (int i=0; i<snakeLength; i++)
    WritePixel(snakeXCoords[i], snakeYCoords[i]);

  xLastCycle = xState();
  yLastCycle = yState();
  
  delay(1);//Refresh rate
}













