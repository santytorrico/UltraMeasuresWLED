#define ECHO_PIN 4
#define TRIG_PIN 2
#define REDLED_PIN 33
#define GREENLED_PIN 32
#define YELLOWLED_PIN 26

const int DISTANCE_THRESHOLD_SHORT = 10;
const int DISTANCE_THRESHOLD_MEDIUM = 20;
const int DISTANCE_THRESHOLD_LONG = 30;

long duration, distance;

void setup() {
  Serial.begin(115200);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(REDLED_PIN, OUTPUT);
  pinMode(GREENLED_PIN, OUTPUT);
  pinMode(YELLOWLED_PIN, OUTPUT);
}

void loop() {
  measureAndDisplayDistance();

  if (distance >= 0 && distance <= 400) {
    if (distance < DISTANCE_THRESHOLD_SHORT) {
      turnOnLed(REDLED_PIN);
      turnOnLed(GREENLED _PIN);
      turnOnLed(YELLOWLED_PIN);
    } else if (distance < DISTANCE_THRESHOLD_MEDIUM) {
      turnOnLed(REDLED_PIN);
      turnOnLed(GREENLED_PIN);
    } else if (distance < DISTANCE_THRESHOLD_LONG) {
      turnOnLed(REDLED_PIN);
    } else {
      turnOffAllLeds();
    }
  } else {
    Serial.println("Invalid Distance Reading.");
  }

  delay(500);
  turnOffAllLeds();
  delay(200);
}

void measureAndDisplayDistance() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(4);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH);
  duration = duration / 2;
  distance = duration / 29.2;

  Serial.print("Distance in Cm: ");
  Serial.println(distance);
}

void turnOnLed(int pin) {
  digitalWrite(pin, HIGH);
}

void turnOffLed(int pin) {
  digitalWrite(pin, LOW);
}

void turnOffAllLeds() {
  turnOffLed(REDLED_PIN);
  turnOffLed(GREENLED_PIN);
  turnOffLed(YELLOWLED_PIN);
}
