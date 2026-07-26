/***************************************************************
  Motor driver implementation 4WD version
  Hardware: 2x L298N dual H-bridge
  
  setMotorSpeed(i, spd):
    i   = FRONT_LEFT | FRONT_RIGHT | REAR_LEFT | REAR_RIGHT
    spd = -255 .. +255 (negative = backward)

  setMotorSpeeds(leftSpeed, rightSpeed):
    Broadcast: leftSpeed  -> FL dan RL
               rightSpeed -> FR dan RR
    This is the main interface that called by PID controller.
***************************************************************/

#ifdef USE_BASE
#ifdef L298_MOTOR_DRIVER

void initMotorController() {
  pinMode(FL_MOTOR_ENABLE,   OUTPUT);
  pinMode(RL_MOTOR_ENABLE,   OUTPUT);
  pinMode(FR_MOTOR_ENABLE,   OUTPUT);
  pinMode(RR_MOTOR_ENABLE,   OUTPUT);

  pinMode(FL_MOTOR_FORWARD,  OUTPUT);
  pinMode(FL_MOTOR_BACKWARD, OUTPUT);
  pinMode(RL_MOTOR_FORWARD,  OUTPUT);
  pinMode(RL_MOTOR_BACKWARD, OUTPUT);
  pinMode(FR_MOTOR_FORWARD,  OUTPUT);
  pinMode(FR_MOTOR_BACKWARD, OUTPUT);
  pinMode(RR_MOTOR_FORWARD,  OUTPUT);
  pinMode(RR_MOTOR_BACKWARD, OUTPUT);

  digitalWrite(FL_MOTOR_ENABLE, HIGH);
  digitalWrite(RL_MOTOR_ENABLE, HIGH);
  digitalWrite(FR_MOTOR_ENABLE, HIGH);
  digitalWrite(RR_MOTOR_ENABLE, HIGH);
}

/* Setting speed of satu motor.
   Using analogWrite on ENABLE pin and digitalWrite on
   direction pin (IN1/IN2 style: FWD=HIGH/LOW, BWD=LOW/HIGH). */
void setMotorSpeed(int i, int spd) {
  uint8_t reverse = 0;

  if (spd < 0) {
    spd = -spd;
    reverse = 1;
  }
  if (spd > MAX_PWM) spd = MAX_PWM;

  switch (i) {
    case FRONT_LEFT:
      analogWrite(FL_MOTOR_ENABLE, spd);
      digitalWrite(FL_MOTOR_FORWARD,  reverse ? LOW  : HIGH);
      digitalWrite(FL_MOTOR_BACKWARD, reverse ? HIGH : LOW);
      break;

    case REAR_LEFT:
      analogWrite(RL_MOTOR_ENABLE, spd);
      digitalWrite(RL_MOTOR_FORWARD,  reverse ? LOW  : HIGH);
      digitalWrite(RL_MOTOR_BACKWARD, reverse ? HIGH : LOW);
      break;

    case FRONT_RIGHT:
      analogWrite(FR_MOTOR_ENABLE, spd);
      digitalWrite(FR_MOTOR_FORWARD,  reverse ? LOW  : HIGH);
      digitalWrite(FR_MOTOR_BACKWARD, reverse ? HIGH : LOW);
      break;

    case REAR_RIGHT:
      analogWrite(RR_MOTOR_ENABLE, spd);
      digitalWrite(RR_MOTOR_FORWARD,  reverse ? LOW  : HIGH);
      digitalWrite(RR_MOTOR_BACKWARD, reverse ? HIGH : LOW);
      break;
  }
}

void setMotorSpeeds(int leftSpeed, int rightSpeed) {
  setMotorSpeed(FRONT_LEFT,  leftSpeed);
  setMotorSpeed(REAR_LEFT,   leftSpeed);
  setMotorSpeed(FRONT_RIGHT, rightSpeed);
  setMotorSpeed(REAR_RIGHT,  rightSpeed);
}

#else
  #error A motor driver must be selected!
#endif
#endif