/**********************************************************
Motor driver function definitions - by James Nugen
MODIFIED 2026-05-12 for Mifad's 2WD configuration:
**********************************************************/

#ifdef L298_MOTOR_DRIVER
  /********************************************************
  DRIVER 1 - REAR LEFT (RL)
  Channel B
  ENB -> PWM enable
  IN3 -> Direction
  IN4 -> Direction
  OUT3 -> RL-
  OUT4 -> RL+
  ********************************************************/
  #define LEFT_MOTOR_FORWARD 10
  #define LEFT_MOTOR_BACKWARD 11
  #define LEFT_MOTOR_ENABLE 8

  /********************************************************
  DRIVER 2 - REAR RIGHT (RR)
  Channel B
  ENB -> PWM enable
  IN3 -> Direction
  IN4 -> Direction
  OUT3 -> RR-
  OUT4 -> RR+
  ********************************************************/
  #define RIGHT_MOTOR_FORWARD 9
  #define RIGHT_MOTOR_BACKWARD 6
  #define RIGHT_MOTOR_ENABLE 13

#endif

void initMotorController();
void setMotorSpeed(int i, int spd);
void setMotorSpeeds(int leftSpeed, int rightSpeed);
