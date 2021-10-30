#ifndef StepMotor4windings_H
#define StepMotor4windings_H

#include <Arduino.h>
    
#define STEPMOTOR_usDEFAULT_STEPPERIOD  1700

class StepMotor4windings
{
  public:
    enum StepMotorPhase {
                          smpA = 0,
                          smpAB = 1,
                          smpB = 2,
                          smpBC = 3,
                          smpC = 4,
                          smpCD = 5,
                          smpD = 6,
                          smpDA = 7,
                          smpUnknown = 8
                        };
    
    void static (StepMotor4windings:: * setPhaseFn[8])();
    void static (StepMotor4windings:: * setPhaseFn_up[8])();
    void static (StepMotor4windings:: * setPhaseFn_down[8])();
    
    void setPhaseA();
    void setPhaseAB();
    void setPhaseB();
    void setPhaseBC();
    void setPhaseC();
    void setPhaseCD();
    void setPhaseD();
    void setPhaseDA();
    
    void setPhaseA_up();
    void setPhaseAB_up();
    void setPhaseB_up();
    void setPhaseBC_up();
    void setPhaseC_up();
    void setPhaseCD_up();
    void setPhaseD_up();
    void setPhaseDA_up();
    
    void setPhaseA_down();
    void setPhaseAB_down();
    void setPhaseB_down();
    void setPhaseBC_down();
    void setPhaseC_down();
    void setPhaseCD_down();
    void setPhaseD_down();
    void setPhaseDA_down();
    
  private:
    byte pinWindingA;
    byte pinWindingB;
    byte pinWindingC;
    byte pinWindingD;
    uint32_t usStepMinPeriod;
    uint32_t usLastStepTC;
    bool powerIsOn;
    StepMotorPhase currentPhase;

  public:
    StepMotor4windings(byte _pinWindingA, byte _pinWindingB, byte _pinWindingC, byte _pinWindingD);
    ~StepMotor4windings();

    bool PowerIsOn() { return powerIsOn; }
    void powerOff();
    bool powerOn(bool waitForPeriod = true);
    bool waveStep(int8_t Direction, bool waitForPeriod = true);
    bool halfStep(int8_t Direction, bool waitForPeriod = true);
    bool fullStep(int8_t Direction, bool waitForPeriod = true);
    uint32_t get_usStepMinPeriod() { return usStepMinPeriod; }
    void set_usStepMinPeriod(uint32_t new_usStepMinPeriod) { usStepMinPeriod = new_usStepMinPeriod; }
    // If readyForStep() returns true there is still small probability that a
    // *Step() function called right after won't be able to perform a
    // step immidiately and will determine that it is not a time for step;
    // that is because of cyclic nature of micros():
    //                  usLastStepTC|
    // micros(): 0------------------|xxxx|----------------------------0xFFFFFFFF
    //                                   |usLastStepTC + usStepMinPeriod
    // So if it passed about [1 hour 12 minutes] * N since the last step
    // such thing can happen.
    bool readyForStep(void) { return micros() - usLastStepTC >= usStepMinPeriod; }
    uint32_t usBeforeReadyForStep(void)
    {
      uint32_t a = micros() - usLastStepTC;
      return a < usStepMinPeriod ? usStepMinPeriod - a : 0;
    }
};

#endif
