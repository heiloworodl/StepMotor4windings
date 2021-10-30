#include "StepMotor4windings.h"

void StepMotor4windings::setPhaseA()
{
  digitalWrite(pinWindingA, 1);
  digitalWrite(pinWindingB, 0);
  digitalWrite(pinWindingC, 0);
  digitalWrite(pinWindingD, 0);
}
void StepMotor4windings::setPhaseAB()
{
  digitalWrite(pinWindingA, 1);
  digitalWrite(pinWindingB, 1);
  digitalWrite(pinWindingC, 0);
  digitalWrite(pinWindingD, 0);
}
void StepMotor4windings::setPhaseB()
{
  digitalWrite(pinWindingA, 0);
  digitalWrite(pinWindingB, 1);
  digitalWrite(pinWindingC, 0);
  digitalWrite(pinWindingD, 0);
}
void StepMotor4windings::setPhaseBC()
{
  digitalWrite(pinWindingA, 0);
  digitalWrite(pinWindingB, 1);
  digitalWrite(pinWindingC, 1);
  digitalWrite(pinWindingD, 0);
}
void StepMotor4windings::setPhaseC()
{
  digitalWrite(pinWindingA, 0);
  digitalWrite(pinWindingB, 0);
  digitalWrite(pinWindingC, 1);
  digitalWrite(pinWindingD, 0);
}
void StepMotor4windings::setPhaseCD()
{
  digitalWrite(pinWindingA, 0);
  digitalWrite(pinWindingB, 0);
  digitalWrite(pinWindingC, 1);
  digitalWrite(pinWindingD, 1);
}
void StepMotor4windings::setPhaseD()
{
  digitalWrite(pinWindingA, 0);
  digitalWrite(pinWindingB, 0);
  digitalWrite(pinWindingC, 0);
  digitalWrite(pinWindingD, 1);
}
void StepMotor4windings::setPhaseDA()
{
  digitalWrite(pinWindingB, 0);
  digitalWrite(pinWindingC, 0);
  digitalWrite(pinWindingD, 1);
  digitalWrite(pinWindingA, 1);
}
// ---------- 
// These functions should be called only if powerIsOn == true and the
// current phase is either the previous one (-1) or pre-previous one (-2).
void StepMotor4windings::setPhaseA_up()
{
  if(currentPhase == smpD) digitalWrite(pinWindingA, 1);
  digitalWrite(pinWindingD, 0);
}
void StepMotor4windings::setPhaseAB_up()
{
  if(currentPhase == smpDA) digitalWrite(pinWindingD, 0);
  digitalWrite(pinWindingB, 1);
}
void StepMotor4windings::setPhaseB_up()
{
  if(currentPhase == smpA) digitalWrite(pinWindingB, 1);
  digitalWrite(pinWindingA, 0);
}
void StepMotor4windings::setPhaseBC_up()
{
  if(currentPhase == smpAB) digitalWrite(pinWindingA, 0);
  digitalWrite(pinWindingC, 1);
}
void StepMotor4windings::setPhaseC_up()
{
  if(currentPhase == smpB) digitalWrite(pinWindingC, 1);
  digitalWrite(pinWindingB, 0);
}
void StepMotor4windings::setPhaseCD_up()
{
  if(currentPhase == smpBC) digitalWrite(pinWindingB, 0);
  digitalWrite(pinWindingD, 1);
}
void StepMotor4windings::setPhaseD_up()
{
  if(currentPhase == smpC) digitalWrite(pinWindingD, 1);
  digitalWrite(pinWindingC, 0);
}
void StepMotor4windings::setPhaseDA_up()
{
  if(currentPhase == smpCD) digitalWrite(pinWindingC, 0);
  digitalWrite(pinWindingA, 1);
}
// ----------- 
// These functions should be called only if powerIsOn == true and the
// current phase is either the next one (+1) or after-next one (+2).
void StepMotor4windings::setPhaseA_down()
{
  if(currentPhase == smpB) digitalWrite(pinWindingA, 1);
  digitalWrite(pinWindingB, 0);
}
void StepMotor4windings::setPhaseAB_down()
{
  if(currentPhase == smpBC) digitalWrite(pinWindingC, 0);
  digitalWrite(pinWindingA, 1);
}
void StepMotor4windings::setPhaseB_down()
{
  if(currentPhase == smpC) digitalWrite(pinWindingB, 1);
  digitalWrite(pinWindingC, 0);
}
void StepMotor4windings::setPhaseBC_down()
{
  if(currentPhase == smpCD) digitalWrite(pinWindingD, 0);
  digitalWrite(pinWindingB, 1);
}
void StepMotor4windings::setPhaseC_down()
{
  if(currentPhase == smpD) digitalWrite(pinWindingC, 1);
  digitalWrite(pinWindingD, 0);
}
void StepMotor4windings::setPhaseCD_down()
{
  if(currentPhase == smpDA) digitalWrite(pinWindingA, 0);
  digitalWrite(pinWindingC, 1);
}
void StepMotor4windings::setPhaseD_down()
{
  if(currentPhase == smpA) digitalWrite(pinWindingD, 1);
  digitalWrite(pinWindingA, 0);
}
void StepMotor4windings::setPhaseDA_down()
{
  if(currentPhase == smpAB) digitalWrite(pinWindingB, 0);
  digitalWrite(pinWindingD, 1);
}


  // Initializing function pointer arrays
  void (StepMotor4windings:: * StepMotor4windings::setPhaseFn[8])() = 
  {
    & StepMotor4windings::setPhaseA,
    & StepMotor4windings::setPhaseAB,
    & StepMotor4windings::setPhaseB,
    & StepMotor4windings::setPhaseBC,
    & StepMotor4windings::setPhaseC,
    & StepMotor4windings::setPhaseCD,
    & StepMotor4windings::setPhaseD,
    & StepMotor4windings::setPhaseDA
  };
  void (StepMotor4windings:: * StepMotor4windings::setPhaseFn_up[8])() = 
  {
    & StepMotor4windings::setPhaseA_up,
    & StepMotor4windings::setPhaseAB_up,
    & StepMotor4windings::setPhaseB_up,
    & StepMotor4windings::setPhaseBC_up,
    & StepMotor4windings::setPhaseC_up,
    & StepMotor4windings::setPhaseCD_up,
    & StepMotor4windings::setPhaseD_up,
    & StepMotor4windings::setPhaseDA_up
  };
  void (StepMotor4windings:: * StepMotor4windings::setPhaseFn_down[8])() = 
  {
    & StepMotor4windings::setPhaseA_down,
    & StepMotor4windings::setPhaseAB_down,
    & StepMotor4windings::setPhaseB_down,
    & StepMotor4windings::setPhaseBC_down,
    & StepMotor4windings::setPhaseC_down,
    & StepMotor4windings::setPhaseCD_down,
    & StepMotor4windings::setPhaseD_down,
    & StepMotor4windings::setPhaseDA_down
  };
  
StepMotor4windings::StepMotor4windings(byte _pinWindingA, byte _pinWindingB,
                                        byte _pinWindingC, byte _pinWindingD)
  : pinWindingA(_pinWindingA), pinWindingB(_pinWindingB),
    pinWindingC(_pinWindingC), pinWindingD(_pinWindingD),
    usStepMinPeriod(STEPMOTOR_usDEFAULT_STEPPERIOD),
    powerIsOn(false), currentPhase(smpA)
{
  digitalWrite(pinWindingA, 0);
  digitalWrite(pinWindingB, 0);
  digitalWrite(pinWindingC, 0);
  digitalWrite(pinWindingD, 0);
  pinMode(pinWindingA, OUTPUT);
  pinMode(pinWindingB, OUTPUT);
  pinMode(pinWindingC, OUTPUT);
  pinMode(pinWindingD, OUTPUT);
  usLastStepTC = micros();
}

StepMotor4windings::~StepMotor4windings()
{
  powerOff();
}

void StepMotor4windings::powerOff()
{
  digitalWrite(pinWindingA, 0);
  digitalWrite(pinWindingB, 0);
  digitalWrite(pinWindingC, 0);
  digitalWrite(pinWindingD, 0);
  usLastStepTC = micros();
  powerIsOn = false;
}

bool StepMotor4windings::powerOn(bool waitForPeriod)
{
  while(micros() - usLastStepTC < usStepMinPeriod) if(waitForPeriod); else return false;
  (this->* StepMotor4windings::setPhaseFn[currentPhase])();
  usLastStepTC = micros();
  return powerIsOn = true;
}

bool StepMotor4windings::waveStep(int8_t Direction, bool waitForPeriod)
{
  StepMotorPhase newPhase; bool positive = false;
  if(Direction > 0)
  {
    newPhase = (StepMotorPhase)((currentPhase + 2 - (currentPhase & 1)) & 0x07);
    positive = true;
  }
  else if(Direction < 0)
    newPhase = (StepMotorPhase)((currentPhase - 2 + (currentPhase & 1)) & 0x07);
  else if(powerIsOn) return true;
  else return powerOn(waitForPeriod);
  // here: Direction is either > 0 or < 0 (not 0)
  while(micros() - usLastStepTC < usStepMinPeriod) if(waitForPeriod); else return false;
  if(powerIsOn)
  {
    if(positive) (this->* StepMotor4windings::setPhaseFn_up[newPhase])();
    else (this->* StepMotor4windings::setPhaseFn_down[newPhase])();
  }
  else { (this->* StepMotor4windings::setPhaseFn[newPhase])(); powerIsOn = true; }
  usLastStepTC = micros();
  currentPhase = newPhase;
  return true;
}

bool StepMotor4windings::halfStep(int8_t Direction, bool waitForPeriod)
{
  StepMotorPhase newPhase; bool positive = false;
  if(Direction > 0)
  { newPhase = (StepMotorPhase)((currentPhase + 1) & 0x07); positive = true; }
  else if(Direction < 0)
    newPhase = (StepMotorPhase)((currentPhase - 1) & 0x07);
  else if(powerIsOn) return true;
  else return powerOn(waitForPeriod);
  // here: Direction is either > 0 or < 0 (not 0)
  while(micros() - usLastStepTC < usStepMinPeriod) if(waitForPeriod); else return false;
  if(powerIsOn)
  {
    if(positive) (this->* StepMotor4windings::setPhaseFn_up[newPhase])();
    else (this->* StepMotor4windings::setPhaseFn_down[newPhase])();
  }
  else { (this->* StepMotor4windings::setPhaseFn[newPhase])(); powerIsOn = true; }
  usLastStepTC = micros();
  currentPhase = newPhase;
  return true;
}

bool StepMotor4windings::fullStep(int8_t Direction, bool waitForPeriod)
{
  StepMotorPhase newPhase; bool positive = false;
  if(Direction > 0)
  {
    newPhase = (StepMotorPhase)((currentPhase + 1 + (currentPhase & 1)) & 0x07);
    positive = true;
  }
  else if(Direction < 0)
    newPhase = (StepMotorPhase)((currentPhase - 1 - (currentPhase & 1)) & 0x07);
  else if(powerIsOn) return true;
  else return powerOn(waitForPeriod);
  // here: Direction is either > 0 or < 0 (not 0)
  while(micros() - usLastStepTC < usStepMinPeriod) if(waitForPeriod); else return false;
  if(powerIsOn)
  {
    if(positive) (this->* StepMotor4windings::setPhaseFn_up[newPhase])();
    else (this->* StepMotor4windings::setPhaseFn_down[newPhase])();
  }
  else { (this->* StepMotor4windings::setPhaseFn[newPhase])(); powerIsOn = true; }
  usLastStepTC = micros();
  currentPhase = newPhase;
  return true;
}
