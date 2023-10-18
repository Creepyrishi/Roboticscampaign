//It's fresh
// Define the pins for the ultrasonic sensor
const int trigPin = 9;   // Trigger pin
const int echoPin = 10;  // Echo pin
long duration;
int distance_cm;
int fix;
const int buzzer = 8;  //buzzer pin

void setup() {
  // Initialize the serial communication
  Serial.begin(9600);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzer, OUTPUT);

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  int fix = pulseIn(echoPin, HIGH);
}

void loop() {
  // Send a 10us pulse to the trigger pin to start the measurement
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);


  duration = pulseIn(echoPin, HIGH);
  Serial.print(duration);

  if (fix != duration) {
    digitalWrite(buzzer, HIGH);

  } else {
    digitalWrite(buzzer, LOW);
  }
}
