#include <SoftwareSerial.h>

SoftwareSerial bt(2,3); /* (Rx,Tx) */
//Green and black thread for thumb //
int FLEX_PIN1 = A0;
int flexADC1 = 0;
int sensorMin1 = 745;
int sensorMax1 = 815;

//Red and brown thread for the index finger //
int FLEX_PIN2 = A1;
int flexADC2 = 0;
int sensorMin2 = 740;
int sensorMax2 = 840;

//Red and green string for the middle //
int FLEX_PIN3 = A2;
int flexADC3 = 0;
int sensorMin3 = 715;
int sensorMax3 = 820;

//Yellow and brown thread for the ring finger //
int FLEX_PIN4 = A3;
int flexADC4 = 0;
int sensorMin4 = 760;
int sensorMax4 = 870;

//Green and blue thread for the pinky //
int FLEX_PIN5 = A4;
int flexADC5 = 0;
int sensorMin5 = 740;
int sensorMax5 = 835;
int xpin = A5;
int xadc = 0;
int ypin = A6;
int yadc = 0;
char letter = '';

void setup() {
  // put your setup code here, to run once:
Serial.begin(1200);
bt.begin(9600);

float flexADC1 = analogRead(FLEX_PIN1);
if(flexADC1<sensorMin1){sensorMin1=flexADC1;}
if(flexADC1>sensorMax1){sensorMax1=flexADC1;}

float flexADC2 = analogRead(FLEX_PIN2);
if(flexADC2<sensorMin2){sensorMin2=flexADC2;}
if(flexADC2>sensorMax2){sensorMax2=flexADC2;}

float flexADC3 = analogRead(FLEX_PIN3);
if(flexADC3<sensorMin3){sensorMin3=flexADC3;}
if(flexADC3>sensorMax3){sensorMax3=flexADC3;}

float flexADC4 = analogRead(FLEX_PIN4);
if(flexADC4<sensorMin4){sensorMin4=flexADC4;}
if(flexADC4>sensorMax4){sensorMax4=flexADC4;}

float flexADC5 = analogRead(FLEX_PIN5);
if(flexADC5<sensorMin5){sensorMin5=flexADC5;}
if(flexADC5>sensorMax5){sensorMax5=flexADC5;}

}

void loop() {
  // put your main code here, to run repeatedly:
Serial.print(“angle1:”);
float flexADC1 = analogRead(FLEX_PIN1);
flexADC1 = constrain(flexADC1,sensorMin1, sensorMax1);
float angle1= map(flexADC1, sensorMin1, sensorMax1, 0, 90);
Serial.print(angle1);
Serial.print(“\t”);

Serial.print(“angle2:”);
float flexADC2 = analogRead(FLEX_PIN2);
flexADC2 = constrain(flexADC2,sensorMin2, sensorMax2);
float angle2= map(flexADC2, sensorMin2, sensorMax2, 0, 90);
Serial.print(angle2);
Serial.print(“\t”);

Serial.print(“angle3:”);
float flexADC3 = analogRead(FLEX_PIN3);
flexADC3 = constrain(flexADC3,sensorMin3, sensorMax3);
float angle3= map(flexADC3, sensorMin3, sensorMax3, 0, 90);
Serial.print(angle3);
Serial.print(“\t”);

Serial.print(“angle4:”);
float flexADC4 = analogRead(FLEX_PIN4);
flexADC4 = constrain(flexADC4,sensorMin4, sensorMax4);
float angle4= map(flexADC4, sensorMin4, sensorMax4, 0, 90);
Serial.print(angle4);
Serial.print(“\t”);

Serial.print(“angle5:”);
float flexADC5 = analogRead(FLEX_PIN5);
flexADC5 = constrain(flexADC5,sensorMin5, sensorMax5);
float angle5= map(flexADC5, sensorMin5, sensorMax5, 0, 90);
Serial.print(angle5);
Serial.print(“\t”);

Serial.print(“x:”);
xadc = analogRead(xpin);
Serial.print(xadc);
Serial.print(“\t”);

Serial.print(“y:”);
yadc = analogRead(ypin);
Serial.println(yadc);
bool horizantol (((xadc>=309)&&(xadc<=390))&&((yadc>=270)&&(yadc<=320))) ;
bool vertical = (((xadc>=410)&&(xadc<=462))&&((yadc>=310)&&(yadc<=405)));
bool equaliburium =(((xadc>=317)&&(xadc<=385))&&((yadc>=315)&&(yadc<=390)));

if((angle1<=40)&&(angle2>=60)&&(angle3>=72)&&(angle4>=68)&&(angle5>=72))
{Serial.println(letter);
letter = 'A';}

if((angle1>=35)&&(angle2<=15)&&(angle3<=15)&&(angle4<=15)&&(angle5<=15))
{Serial.println('B');
letter = 'B';}

if((angle1<20)&&((angle2>=30)&&(angle2<80))&&((angle3>=30)&&(angle3<85))&&((
angle4>=30)&&(angle4<85))&&((angle5>=30)&&(angle5<85)))
{Serial.println('C');
letter = 'C';}

if(((angle1>=30)&&(angle1<=70))&&(angle2<=15)&&(angle3>=60)&&(angle4>=40)&&(
angle5>=40)&& vertical)
{Serial.println('D');
letter = 'D';}

if((angle1>=85)&&(angle2>=85)&&(angle3>=85)&&(angle4>=85)&&(angle5>=85))
{Serial.println('E');
letter = 'E';}

if((angle1>=30)&&(angle2>=40)&&(angle3<=15)&&(angle4<=15)&&(angle5<=15))
{Serial.println('F');
letter = 'F';}

if((angle1<=30)&&(angle2<=15)&&(angle3>=55)&&(angle4>=55)&&(angle5>=60)&&hor
izantol)
{Serial.println('G');
letter = 'G';}

if((angle1>=40)&&(angle2<=15)&&(angle3<=15)&&(angle4>=55)&&(angle5>=50)&&hor
izantol)
{Serial.println('H');
letter = 'H';}

if((angle1>=30)&&(angle2>=70)&&(angle3>=55)&&(angle4>=55)&&(angle5<=30)&&ver
tical)
{Serial.println('I');
letter='I';}

if((angle1>=30)&&(angle2>=70)&&(angle3>=55)&&(angle4>=55)&&(angle5<=30)&&!ve
rtical)
{Serial.println('J');
letter='J';}

if((angle1<=30)&&(angle2<=15)&&(angle3<=15)&&(angle4>=55)&&(angle5>=55)&&ver
tical)
{Serial.println('K');
letter = 'K';}

if((angle1<=10)&&(angle2<=18)&&(angle3>=40)&&(angle4>=40)&&(angle5>=40)&&ver
tical)
{Serial.println('L');
letter = 'L';}

if(((angle1>=30)&&(angle1<=75))&&((angle2>=40)&&(angle2<80))&&((angle3>=40)&
&(angle3<80))&&((angle4>=50)&&(angle4<=85))&&(angle5>=85))
{Serial.println('M');
letter = 'M';}

if(((angle1>=30)&&(angle1<=70))&&((angle2>=40)&&(angle2<80))&&((angle3>=40)&
&(angle3<80))&&(angle4>85)&&(angle5>=85))
{Serial.println('N');
letter = 'N';}

if((angle1>=20)&&((angle2>=30)&&(angle2<80))&&((angle3>=30)&&(angle3<85))&&(
(angle4>=30)&&(angle4<85))&&((angle5>=30)&&(angle5<85))&&vertical)
{Serial.println('O');
letter = 'O';}

if((angle1<=40)&&(angle2<=15)&&(angle3<=30)&&(angle4>=55)&&(angle5>=55)&&equ
aliburium)
{Serial.println('P');
letter = 'P';}

if((angle1<=15)&&(angle2<=15)&&(angle3>=50)&&(angle4>=50)&&(angle5>=60)&&equ
aliburium)
{Serial.println('Q');
letter = 'Q';}

if((angle1>=30)&&(angle2<=10)&&((angle3>=10)&&(angle3<=20))&&(angle4>=55)&&(
angle5>=55)&&vertical)
{Serial.println('R');
letter = 'R';}

if(((angle1>=60)&&(angle1<85))&&(angle2>=70)&&(angle3>=70)&&(angle4>=70)&&(a
ngle5>=70))
{Serial.println('S');
letter = 'S';}

if(((angle1>=10)&&(angle1<=40))&&((angle2>=20)&&(angle2<=50))&&(angle3>=80)&
&(angle4>=80)&&(angle5>=80))
{Serial.println('T');
letter = 'T';}

if((angle1>=30)&&(angle2<=10)&&(angle3<10)&&(angle4>=55)&&(angle5>=55)&&vert
ical)
{Serial.println('U');
letter = 'U';}

if((angle1>=30)&&(angle2<=10)&&(angle3<10)&&(angle4>=55)&&(angle5>=55)&&vert
ical)
{Serial.println('V');
letter = 'V';}

if((angle1>=40)&&(angle2<=10)&&(angle3<=15)&&(angle4<=15)&&(angle5>=55))
{Serial.println('W');
letter = 'W';}

if((angle1>=30)&&((angle2>=15)&&(angle2<=40))&&(angle3>=30)&&(angle4>=30)&&(
angle5>=30)&&vertical)
{Serial.println('X');
letter = 'X';}

if((angle1<=10)&&(angle2>=44)&&(angle3>=40)&&(angle4>=40)&&(angle5<=15))
{Serial.println('Y');
letter = 'Y';}

if(((angle1>=30)&&(angle1<=70))&&(angle2<=15)&&(angle3>=60)&&(angle4>=40)&&(
angle5>=40)&&!vertical)
{Serial.println('Z');
letter='Z';}

bt.write(letter);
delay(20);


}
