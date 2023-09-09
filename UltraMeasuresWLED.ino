#define ECHO_PIN 4
#define TRIG_PIN 2
#define LED1_PIN 33
#define LED2_PIN 32
#define LED3_PIN 26

const int DISTANCE_THRESHOLD_SHORT = 10;
const int DISTANCE_THRESHOLD_MEDIUM = 20;
const int DISTANCE_THRESHOLD_LONG = 30;

long duration, distance;

void setup() {
  Serial.begin(115200);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);
  pinMode(LED3_PIN, OUTPUT);
}

void loop() {
  measureAndDisplayDistance();

  if (distance >= 0 && distance <= 400) {
    if (distance < DISTANCE_THRESHOLD_SHORT) {
      turnOnLed(LED1_PIN);
      turnOnLed(LED2_PIN);
      turnOnLed(LED3_PIN);
    } else if (distance < DISTANCE_THRESHOLD_MEDIUM) {
      turnOnLed(LED1_PIN);
      turnOnLed(LED2_PIN);
    } else if (distance < DISTANCE_THRESHOLD_LONG) {
      turnOnLed(LED1_PIN);
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
  turnOffLed(LED1_PIN);
  turnOffLed(LED2_PIN);
  turnOffLed(LED3_PIN);
}
