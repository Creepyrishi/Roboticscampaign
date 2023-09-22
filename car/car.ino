// Define motor pins
int in1 = 10;//+
int in2 = 11;//-
int in3 = 12;//+
int in4 = 13;//-
  
void setup() {
  // Set motor pins as outputs
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  if(Serial.available()){
    char c = Serial.read();
    if (c == 'F')
    {
      forward();
    }
    else if (c == 'B')
    {
      backward();
    }
    else if (c == 'L')
    {
      right();
    }
    else if(c == 'R')
    {
      left();
    }
    else
    {
      stop();
    }
  }
}

void forward()
{
  digitalWrite(in1,1);
  digitalWrite(in3,1);
  digitalWrite(in2,0);
  digitalWrite(in4,0);
}
void backward ()
{
  digitalWrite (in2,1);
  digitalWrite (in4,1);
  digitalWrite (in1,0);
  digitalWrite (in3,0);
}

void right()
{
  digitalWrite(in3,1);
  digitalWrite(in2,1);
  digitalWrite(in4,0);
  digitalWrite(in1,0);
}
void left()
{
  digitalWrite(in3,0);
  digitalWrite(in2,0);
  digitalWrite(in4,1);
  digitalWrite(in1,1);
}
void stop()
{
  digitalWrite(in1,0);
  digitalWrite(in2,0);
  digitalWrite(in3,0);
  digitalWrite(in4,0);
  
}
