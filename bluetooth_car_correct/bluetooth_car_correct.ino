// Motor A connections
int enA = 9;
int in1 = 2;
int in2 = 3;
// Motor B connections
int enB = 10;
int in3 = 4;
int in4 = 5;

void setup() {
  // Set all the motor control pins to outputs
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  // Start with motors stopped
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);

  Serial.begin(9600); // Start serial communication with the Bluetooth module
}

void loop() {
  if (Serial.available()) {
    char command = Serial.read(); // Read the incoming data
    switch(command) {
      case 'F': // Move forward
        forward();
        break;
      case 'B': // Move backward
        backward();
        break;
      case 'L': // Turn left
        left();
        break;
      case 'R': // Turn right
        right();
        break;
      case 'S': // Stop
        stop();
        break;
    }
  }
}

void forward() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enA, 255); // Speed can be adjusted
  analogWrite(enB, 255);
}

void backward() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enA, 205); 
  analogWrite(enB, 205);
}

void left() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enA, 205); 
  analogWrite(enB, 205);
}

void right() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enA, 205); 
  analogWrite(enB, 205);
}

void stop() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}
