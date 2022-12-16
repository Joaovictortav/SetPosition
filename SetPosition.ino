// Include the Arduino Stepper Library
#include <Stepper.h>

// Number of steps per output rotation
const int stepsPerRevolution = 48;

// Create Instance of Stepper library
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);
int var = 0;

double positionNow = 30;
double positionFinal = 20;


double catetoOposto = 7.6;
double pi = 3.141592653;

float angle_rad = positionNow * pi / 180;
float tan_result = tan(angle_rad);
double catetoAdj = catetoOposto / tan_result;

float angle_rad_final = positionFinal * pi / 180;
float tan_result_fianl = tan(angle_rad_final);
double catetoAdjFinal = catetoOposto / tan_result_fianl;

double steps = (catetoAdj - catetoAdjFinal) / 0.004508;

void setup()
{
	// set the speed at 60 rpm:
	myStepper.setSpeed(60);
	// initialize the serial port:
	Serial.begin(9600);

  Serial.println(catetoAdj);
  Serial.println(catetoAdjFinal);
  Serial.println(steps);
  
  myStepper.step(steps);
}

void loop() 
{

}
