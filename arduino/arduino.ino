#include <AccelStepper.h>

// Define the stepper motor and the pins that is connected to
class JointStepper {
  public:
    // Static variables
    int driverType;
    int stepPin;
    int dirPin;
    int NegativeLimitPin;
    int PositiveLimitPin; // -1 if not used
    int dir;
    int homeDir;
    int stepResolution; // Steps per revolution
    float ratio; // Gear ratio
    float maxPosition; // Degrees
    float minPosition; // Degrees
    float homePosition; // Degrees

    // Dynamic variables
    bool homed;
    float position; // Degrees

    // Stepper object
    AccelStepper stepper;

    // Constructor
    JointStepper(int driverType, int stepPin, int dirPin, int NegativeLimitPin, int PositiveLimitPin, int dir, int homeDir, int stepResolution, float ratio, float maxPosition, float minPosition, float homePosition) {
      this->driverType = driverType;
      this->stepPin = stepPin;
      this->dirPin = dirPin;
      this->NegativeLimitPin = NegativeLimitPin;
      this->PositiveLimitPin = PositiveLimitPin;
      this->dir = dir;
      this->homeDir = homeDir;
      this->stepResolution = stepResolution;
      this->ratio = ratio;
      this->maxPosition = maxPosition;
      this->minPosition = minPosition;
      this->homePosition = homePosition;
      this->homed = false;
      this->position = 0;
      this->stepper = AccelStepper(driverType, stepPin, dirPin);
    }

    // Homing Method
    void home() {
      // Move to the limit switch
      while (digitalRead(NegativeLimitPin) == HIGH) {
        stepper.setSpeed(100);
        stepper.runSpeed();
      }
      // Stop the motor
      stepper.stop();
      // Set the position to the home position
      position = homePosition;
      // Set the homed flag to true
      homed = true;
    }
}

void setup() {
}

void loop() {
}