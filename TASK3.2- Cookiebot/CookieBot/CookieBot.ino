/*
------Amir Kasseb------
------19/8/2923-------
------Cookie Bot------
*/


//Define Pins of First Ultrasonic Sensor
#define trigPin0 2
#define echoPin0 3
//Define Pins of Second Ultrasonic Sensor
#define trigPin90 4
#define echoPin90 5
//Define Pins of Third Ultrasonic Sensor
#define trigPin180 6
#define echoPin180 7
//Define Pins of Four Ultrasonic Sensor
#define trigPin270 8
#define echoPin270 9

int x_cordinates=0;
int y_cordinates=0;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin0, OUTPUT);
  pinMode(echoPin0, INPUT);
  pinMode(trigPin90, OUTPUT);
  pinMode(echoPin90, INPUT);
  pinMode(trigPin180, OUTPUT);
  pinMode(echoPin180, INPUT);
  pinMode(trigPin270, OUTPUT);
  pinMode(echoPin270, INPUT);
}
//Function to Get The Distance Reading from the ultrsonic Sensor 
float getDistance(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  long duration = pulseIn(echoPin, HIGH);
  float distance = duration * 0.0343 / 2;
  return distance;
}

void loop() {

  float d0 = getDistance(trigPin0, echoPin0);
  float d90 = getDistance(trigPin90, echoPin90);
  float d180 = getDistance(trigPin180, echoPin180);
  float d270 = getDistance(trigPin270, echoPin270);

//Calculate Average Of readings from both sensors on each side

x_cordinates=(d0+d180)/2.0;
y_cordinates=(d90+d270)/2.0;

//Display The Cordinates on the Serial Portal
Serial.print(" X= ");
Serial.println(x_cordinates);
Serial.print(" Y= ");
Serial.println(y_cordinates);

}