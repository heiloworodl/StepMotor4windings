# StepMotor4windings
Cool code class for driving 4 windings (pins) stepper motors. Well suitable for 28BYJ-48 + ULN2003 motor/driver. All three stepping methods: Wave, Full Step, Half Step. Sync/async operation. Powering off the motor. Protection against too short duration between steps.

The class uses static arrays of functions to switch between the phases of step motor. So in order to switch to the next (or previous) phase the class doesn't perform a number of if-else statements nor check the conditions in a switch statement but simply increments (or decrements) the index of the function in the array.

## How to use
```
#include <StepMotor4windings.h>

StepMotor4windings motor(pinA, pinB, pinC, pinD);

void setup() {
  motor.set_usStepMinPeriod(2500);          // setting the min duration between steps to 2500 microseconds
}

uint32_t millisLastStep = millis();         // variable for the purpose of powering the motor off

// in loop():

    motor.waveStep(-1);                         // -1 - step backward
    millisLastStep = millis();
    // or
    bool stepDone = motor.waveStep(1, false);   // returns false if it's not long-enough since the last
    if(stepDone) millisLastStep = millis();     // step and this step has not been done
    
// or

    uint32_t usBeforeNextStepAllowed = motor.usBeforeReadyForStep();
    if(usBeforeNextStepAllowed <= 500) {        // if it's less than 500 us till next step is allowed
      motor.waveStep(1, true);                  // then wait for that time ('true' causes waiting)
      millisLastStep = millis();                // in order to do the step as sychronously as possible,
    }                                           // and do the step
    // otherwise, we're free to do some other work waiting for the next step's time

// powering off
    // if it's long-enough since the last step then it's okay to switch all the windings of the motor off
    if(motor.PowerIsOn() && millis() - millisLastStep > 5000) motor.powerOff();
```
