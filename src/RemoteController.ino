#include <IRremote.hpp>

const int FORWARD_BUTTON_PIN = 2;
const int BACKWARD_BUTTON_PIN = 3;
const int LEFT_BUTTON_PIN = 4;
const int RIGHT_BUTTON_PIN = 5;

const int INFRARED_LED_PIN = 6;

const int NUMBER_OF_REPEATS = 0;

const long SIGNAL_DELAY = 25;



void setup() {
  Serial.begin(9600);

  pinMode(FORWARD_BUTTON_PIN, INPUT);
  pinMode(BACKWARD_BUTTON_PIN, INPUT);
  pinMode(LEFT_BUTTON_PIN, INPUT);
  pinMode(RIGHT_BUTTON_PIN, INPUT);

  pinMode(INFRARED_LED_PIN, OUTPUT);
  IrSender.begin(INFRARED_LED_PIN);
}

void loop() {



  if (
    digitalRead(FORWARD_BUTTON_PIN) == HIGH 
    && digitalRead(LEFT_BUTTON_PIN) == HIGH
    ) {
    
    Serial.println("FORWARD-LEFT");
    IrSender.sendFAST(0x01, NUMBER_OF_REPEATS);
    delay(SIGNAL_DELAY);

  } else if (
    digitalRead(FORWARD_BUTTON_PIN) == HIGH 
    && digitalRead(RIGHT_BUTTON_PIN) == HIGH
    ) {
    
    Serial.println("FORWARD-RIGHT");
    IrSender.sendFAST(0x03, NUMBER_OF_REPEATS);
    delay(SIGNAL_DELAY);

  } else if (
    digitalRead(BACKWARD_BUTTON_PIN) == HIGH 
    && digitalRead(LEFT_BUTTON_PIN) == HIGH
    ) {
    
    Serial.println("BACKWARD-LEFT");
    IrSender.sendFAST(0x07, NUMBER_OF_REPEATS);
    delay(SIGNAL_DELAY);

  } else if (
    digitalRead(BACKWARD_BUTTON_PIN) == HIGH 
    && digitalRead(RIGHT_BUTTON_PIN) == HIGH
    ) {
    
    Serial.println("BACKWARD-RIGHT");
    IrSender.sendFAST(0x09, NUMBER_OF_REPEATS);
    delay(SIGNAL_DELAY);

  } else if (digitalRead(FORWARD_BUTTON_PIN) == HIGH) {
    
    Serial.println("FORWARD");
    IrSender.sendFAST(0x02, NUMBER_OF_REPEATS);
    delay(SIGNAL_DELAY);

  } else if (digitalRead(BACKWARD_BUTTON_PIN) == HIGH) {

    Serial.println("BACKWARD");
    IrSender.sendFAST(0x08, NUMBER_OF_REPEATS);
    delay(SIGNAL_DELAY);

  } else if (digitalRead(LEFT_BUTTON_PIN) == HIGH) {

    Serial.println("LEFT");
    IrSender.sendFAST(0x04, NUMBER_OF_REPEATS);
    delay(SIGNAL_DELAY);

  } else if (digitalRead(RIGHT_BUTTON_PIN) == HIGH) {

    Serial.println("RIGHT");
    IrSender.sendFAST(0x06, NUMBER_OF_REPEATS);
    delay(SIGNAL_DELAY);
    
  }
}
