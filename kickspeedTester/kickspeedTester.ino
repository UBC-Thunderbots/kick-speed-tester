//#include <Adafruit_GFX.h>
//#include <Adafruit_GrayOLED.h>
//#include <Adafruit_SPITFT.h>
//#include <Adafruit_SPITFT_Macros.h>



#include <Wire.h>
//#include <Adafruit_GFX.h>
//#include <Adafruit_SSD1306.h>
double startTime = 0; //Initialize the start time
double endTime = 0;  //Initialize the end time
double timeTakenInSeconds = 0; //Difference between start and end time
double speedOfObject = 0;  //Holds the value distance divided by time taken
const double distance = 0.05;  // Distance between the two sensors is set to 1 metre
int executed = 0;   //Flag to run the code in the loop only once. When set to 1, code in the loop is not executed.
int sensor1 = 4;   //idk which pin to put it in, so I assigned it at random
int sensor2 = 2; 
int sense1 = 0;
int sense2 = 0;

void setup() {
  
  Serial.begin(115200);

  pinMode(sensor1, INPUT);
  pinMode(sensor2, INPUT);
  //The pinMode() function is used to configure a specific pin to behave either as an input or an output. 

  }

void loop() {
 
    //Serial.print("Sensor1");
    //Serial.print(digitalRead(sensor1));
    //Serial.print("Sensor2");
    //Serial.println(digitalRead(sensor2));

    if (digitalRead(sensor1) == 1) { //If movement is detected by the first sensor     
        sense1 = 1;

    } 
    if (sense1 == 1 && digitalRead (sensor1) == 0){
      startTime = millis(); //Assign Arduino time to startTime 
      sense1 = 0;
    }
    
    
  if (digitalRead(sensor2) == 1) { //If movement is detected by the second sensor
      sense2 = 1;
  }
  if (sense2 == 1 && digitalRead(sensor2)==0){
        endTime = millis ();
        sense2 = 0;
      timeTakenInSeconds = (endTime - startTime)/1000;
      speedOfObject = distance / timeTakenInSeconds; //Calculate speed in metres per second

        /* Print the values to the serial monitor */
        Serial.print("Start Time: "); //Print to the serial monitor
        Serial.print(startTime/1000);  //Print value
        Serial.println(" seconds");
        Serial.print("End Time: "); //Print value
        Serial.print(endTime/1000);    //Print value
        Serial.println(" seconds");
        Serial.print("Speed of Object = ");
        Serial.print(speedOfObject);
        Serial.println(" m/s");
        Serial.println(" ");
        // grd to neg and pwr to pos
  }
      
      
}
