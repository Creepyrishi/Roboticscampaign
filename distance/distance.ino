//It's fresh
// Define the pins for the ultrasonic sensor
const int trigPin = 9;  // Trigger pin
const int echoPin = 10; // Echo pin

// Variables to store the duration and distance
long duration;
int distance_cm;

void setup() {
  // Initialize the serial communication
  Serial.begin(9600);
  
  // Define the trigger pin as an OUTPUT and the echo pin as an INPUT
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  // Send a 10us pulse to the trigger pin to start the measurement
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Measure the duration of the echo pulse
  duration = pulseIn(echoPin, HIGH);
  
  // Calculate the distance in centimeters (cm)
  distance_cm = duration / 58; // Speed of sound is approximately 343 meters per second, which is 34300 cm/s
  
  // Display the distance on the serial monitor
  Serial.print("Distance: ");
  Serial.print(distance_cm);
  Serial.println(" cm");
  
  // Add a delay before the next measurement
  delay(1000); // You can adjust this delay to control the measurement frequency
}
