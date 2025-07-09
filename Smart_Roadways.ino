const int trig1 = 2, echo1 = 3;
const int trig2 = 4, echo2 = 5;
const int trig3 = 6, echo3 = 7;
const int trig4 = 8, echo4 = 9;

const int red1 = 10, green1 = 11;
const int red2 = 12, green2 = 13;
const int red3 = A0, green3 = A1;
const int red4 = A2, green4 = A3;

const int defaultTime = 2000;
const int extendedTime = 8000;
const int distanceThreshold = 10; // Distance threshold in cm

void setup() {
  pinMode(trig1, OUTPUT);
  pinMode(echo1, INPUT);
  pinMode(trig2, OUTPUT);
  pinMode(echo2, INPUT);
  pinMode(trig3, OUTPUT);
  pinMode(echo3, INPUT);
  pinMode(trig4, OUTPUT);
  pinMode(echo4, INPUT);

  pinMode(red1, OUTPUT);
  pinMode(green1, OUTPUT);
  pinMode(red2, OUTPUT);
  pinMode(green2, OUTPUT);
  pinMode(red3, OUTPUT);
  pinMode(green3, OUTPUT);
  pinMode(red4, OUTPUT);
  pinMode(green4, OUTPUT);

  Serial.begin(9600);

  digitalWrite(green1, LOW);
  digitalWrite(red1, HIGH);
  digitalWrite(green2, LOW);
  digitalWrite(red2, HIGH);
  digitalWrite(green3, LOW);
  digitalWrite(red3, HIGH);
  digitalWrite(green4, LOW);
  digitalWrite(red4, HIGH);
}

void loop() {
  long duration, distance;

  if (Serial.available() > 0) {
    char command = Serial.read(); // Read a single character from serial input

    if (command == '1') { // Command to activate Lane 1
      digitalWrite(green1, HIGH);
      digitalWrite(red1, LOW);
      digitalWrite(green2, LOW);
      digitalWrite(red2, HIGH);
      digitalWrite(green3, LOW);
      digitalWrite(red3, HIGH);
      digitalWrite(green4, LOW);
      digitalWrite(red4, HIGH);
      Serial.println("Lane 1 is on");
      delay(15000);
    } 
    else if (command == '2') { // Command to activate Lane 2
      digitalWrite(green1, LOW);
      digitalWrite(red1, HIGH);
      digitalWrite(green2, HIGH);
      digitalWrite(red2, LOW);
      digitalWrite(green3, LOW);
      digitalWrite(red3, HIGH);
      digitalWrite(green4, LOW);
      digitalWrite(red4, HIGH);
      Serial.println("Lane 2 is on");
      delay(15000);
    } 
    else if (command == '3') { // Command to activate Lane 3
      digitalWrite(green1, LOW);
      digitalWrite(red1, HIGH);
      digitalWrite(green2, LOW);
      digitalWrite(red2, HIGH);
      digitalWrite(green3, HIGH);
      digitalWrite(red3, LOW);
      digitalWrite(green4, LOW);
      digitalWrite(red4, HIGH);
      Serial.println("Lane 3 is on");
      delay(15000);
    } 
    else if (command == '4') { // Command to activate Lane 4
      digitalWrite(green1, LOW);
      digitalWrite(red1, HIGH);
      digitalWrite(green2, LOW);
      digitalWrite(red2, HIGH);
      digitalWrite(green3, LOW);
      digitalWrite(red3, HIGH);
      digitalWrite(green4, HIGH);
      digitalWrite(red4, LOW);
      Serial.println("Lane 4 is on");
      delay(15000);
    } 
    else {
      digitalWrite(green1, LOW);
      digitalWrite(red1, HIGH);
      digitalWrite(green2, LOW);
      digitalWrite(red2, HIGH);
      digitalWrite(green3, LOW);
      digitalWrite(red3, HIGH);
      digitalWrite(green4, LOW);
      digitalWrite(red4, HIGH);
    }
  } 
  else {
    // Lane 1
    digitalWrite(trig1, LOW);
    delayMicroseconds(2);
    digitalWrite(trig1, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig1, LOW);
    duration = pulseIn(echo1, HIGH);
    distance = (duration * 0.034) / 2;

    digitalWrite(red1, LOW);
    digitalWrite(green1, HIGH);
    if (distance < distanceThreshold) {
      delay(extendedTime);
    } else {
      delay(defaultTime);
    }
    digitalWrite(green1, LOW);
    digitalWrite(red1, HIGH);

    // Lane 2
    digitalWrite(trig2, LOW);
    delayMicroseconds(2);
    digitalWrite(trig2, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig2, LOW);
    duration = pulseIn(echo2, HIGH);
    distance = (duration * 0.034) / 2;

    digitalWrite(red2, LOW);
    digitalWrite(green2, HIGH);
    if (distance < distanceThreshold) {
      delay(extendedTime);
    } else {
      delay(defaultTime);
    }
    digitalWrite(green2, LOW);
    digitalWrite(red2, HIGH);

    // Lane 3
    digitalWrite(trig3, LOW);
    delayMicroseconds(2);
    digitalWrite(trig3, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig3, LOW);
    duration = pulseIn(echo3, HIGH);
    distance = (duration * 0.034) / 2;

    digitalWrite(red3, LOW);
    digitalWrite(green3, HIGH);
    if (distance < distanceThreshold) {
      delay(extendedTime);
    } else {
      delay(defaultTime);
    }
    digitalWrite(green3, LOW);
    digitalWrite(red3, HIGH);

    // Lane 4
    digitalWrite(trig4, LOW);
    delayMicroseconds(2);
    digitalWrite(trig4, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig4, LOW);
    duration = pulseIn(echo4, HIGH);
    distance = (duration * 0.034) / 2;

    digitalWrite(red4, LOW);
    digitalWrite(green4, HIGH);
    if (distance < distanceThreshold) {
      delay(extendedTime);
    } else {
      delay(defaultTime);
    }
    digitalWrite(green4, LOW);
    digitalWrite(red4, HIGH);
  }
}
