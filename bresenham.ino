int x1=0,y1=0;
//initializing and declaring led rows
  int c[6]={0,1,2,3,4,5};
//initializing and declaring led layers
  int a[6]={A5,A4,A3,A2,A1,A0};
void setup()
{
  //setting rows,column to ouput
   //Serial.begin(9600);
  for(int i = 0; i<6; i++){pinMode(c[i], OUTPUT); pinMode(a[i], OUTPUT);}
  alloff();//default-screen-off
}

void loop()
{
  //runtest();
  splot(x1,y1);
  bresenham(3,5);
}
void alloff()
{
  for(int i = 0; i<6; i++)
  {
    digitalWrite(a[i], 0);
    digitalWrite(c[i], 1);
  }
}
void splot(int x, int y)//swiftplot
{
   digitalWrite(a[y], 1);
   digitalWrite(c[x], 0);
   //delay(500);
   digitalWrite(a[y], 0);
   digitalWrite(c[x], 1);
}
void runtest()
{
   for(int i=0;i<6;i++)
  {
    for(int j=0;j<6;j++)
    {splot(j,i);}
  }
}
void bresenham(int x2, int y2)
{
  int dx,dy,x,y,p;
  dx = (x2 - x1);
  dy = (y2 - y1);
  p = 2 * (dy) - (dx);
  x = x1;
  y = y1;

  while(x < x2)
 { if(p < 0){ x=x+1; y=y; p = p + 2 * (dy);}
   else{ x=x+1;y=y+1; p = p + 2 * (dy - dx);}
   splot(x,y);
 }

}

