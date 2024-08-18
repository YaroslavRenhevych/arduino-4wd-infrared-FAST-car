#define DECODE_FAST

#include <IRremote.hpp>
#include <L298NX2.h>

const int IR_RECEIVER_PIN = 7;

const int EN_A = 9;
const int IN1_A = 3;
const int IN2_A = 4;

const int EN_B = 10;
const int IN1_B = 5;
const int IN2_B = 6;

const int COMMAND_EXECUTION_INTERVAL = 150;

// Initialize both motors
L298NX2 motors(EN_A, IN1_A, IN2_A, EN_B, IN1_B, IN2_B);

unsigned long lastCommandTimestamp = 0;

void setup() {
  Serial.begin(9600);

  IrReceiver.begin(IR_RECEIVER_PIN);

  motors.setSpeed(255);
}


void loop() {
  if (IrReceiver.decode()) {
    IrReceiver.resume();

    if (IrReceiver.decodedIRData.command == 0x01) {

      Serial.println("FORWARD-LEFT");
      motors.stopB();
      motors.forwardA();

      lastCommandTimestamp = millis();

    } else if (IrReceiver.decodedIRData.command == 0x02) {

      Serial.println("FORWARD");
      motors.forward();

      lastCommandTimestamp = millis();

    } else if (IrReceiver.decodedIRData.command == 0x03) {

      Serial.println("FORWARD-RIGHT");
      motors.forwardB();
      motors.stopA();
      lastCommandTimestamp = millis();

    } else if (IrReceiver.decodedIRData.command == 0x04) {

      Serial.println("LEFT");
      motors.backwardB();
      motors.forwardA();

      lastCommandTimestamp = millis();

    } else if (IrReceiver.decodedIRData.command == 0x06) {

      Serial.println("RIGHT");
      motors.forwardB();
      motors.backwardA();

      lastCommandTimestamp = millis();

    } if (IrReceiver.decodedIRData.command == 0x07) {
      
      Serial.println("BACKWARD-LEFT");
      motors.stopB();
      motors.backwardA();

      lastCommandTimestamp = millis();

    } else if (IrReceiver.decodedIRData.command == 0x08) {

      Serial.println("BACKWARD");
      motors.backward();

      lastCommandTimestamp = millis();

    } else if (IrReceiver.decodedIRData.command == 0x09) {

      Serial.println("BACKWARD-RIGHT");
      motors.backwardB();
      motors.stopA();

      lastCommandTimestamp = millis();

    }
  }

  if (millis() - lastCommandTimestamp > COMMAND_EXECUTION_INTERVAL) {

    Serial.println("STOP");

    motors.stop();
  }
}
