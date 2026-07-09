#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

// I2C LCD address is usually 0x27 or 0x3F — try 0x27 first
LiquidCrystal_I2C lcd(0x27, 16, 2);

Servo gateServo;

// Pin definitions
const int mq3Pin    = A0;  // MQ3 alcohol sensor
const int irPin     = 7;   // IR proximity sensor
const int buzzerPin = 5;   // Buzzer
const int fanPin    = 6;   // Mini brushless fan
const int servoPin  = 8;   // Servo motor

// Threshold value for alcohol detection (adjust after testing)
const int alcoholThreshold = 400;

void setup() {
  Serial.begin(9600);

  pinMode(irPin,     INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(fanPin,    OUTPUT);

  gateServo.attach(servoPin);
  gateServo.write(0);  // Gate closed at start

  // Initialize I2C LCD
  lcd.init();
  lcd.backlight();

  lcd.setCursor(2, 0);
  lcd.print("Alcohol");
  lcd.setCursor(1, 1);
  lcd.print("Detection Sys");
  delay(2500);
  lcd.clear();
}

void loop() {
  int irValue      = digitalRead(irPin);
  int alcoholValue = analogRead(mq3Pin);

  Serial.print("IR: ");
  Serial.print(irValue);
  Serial.print("  Alcohol: ");
  Serial.println(alcoholValue);

  // Only check when person is detected by IR sensor
  if (irValue == LOW) {  // LOW means object detected (IR sensor active low)

    lcd.setCursor(0, 0);
    lcd.print("Person Detected ");
    lcd.setCursor(0, 1);
    lcd.print("Checking...     ");
    delay(2000);

    // Read alcohol level again fresh
    alcoholValue = analogRead(mq3Pin);

    if (alcoholValue > alcoholThreshold) {
      // Alcohol detected — deny entry
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("ALERT! Alcohol  ");
      lcd.setCursor(0, 1);
      lcd.print("Access DENIED   ");

      // Buzzer beeps
      for (int i = 0; i < 5; i++) {
        digitalWrite(buzzerPin, HIGH);
        delay(300);
        digitalWrite(buzzerPin, LOW);
        delay(200);
      }

      // Turn on fan to blow fresh air
      digitalWrite(fanPin, HIGH);
      delay(3000);
      digitalWrite(fanPin, LOW);

      // Keep gate closed
      gateServo.write(0);

    } else {
      // No alcohol — allow entry
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("No Alcohol      ");
      lcd.setCursor(0, 1);
      lcd.print("Access GRANTED  ");

      // Open gate
      gateServo.write(90);
      delay(3000);

      // Close gate again
      gateServo.write(0);
    }

    lcd.clear();

  } else {
    // No person detected — idle display
    lcd.setCursor(0, 0);
    lcd.print("Alcohol Det Sys ");
    lcd.setCursor(0, 1);
    lcd.print("Waiting...      ");
  }

  delay(500);
}