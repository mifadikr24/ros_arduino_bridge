/**********************************************************
  Motor driver function definitions - by James Nugen
  Motor driver function definitions - 4WD version
  Hardware: 2x L298N dual H-bridge
  Platform: Arduino Mega

  === DRIVER 1 (left) ===
  Channel A -> FRONT LEFT  (FL)
    ENA  -> pin 2  (PWM)
    IN1  -> pin 22 (DIR)
    IN2  -> pin 23 (DIR)

  Channel B -> REAR LEFT   (RL)
    ENB  -> pin 3  (PWM)
    IN3  -> pin 24 (DIR)
    IN4  -> pin 25 (DIR)

  === DRIVER 2 (right) ===
  Channel A -> FRONT RIGHT (FR)
    ENA  -> pin 4  (PWM)
    IN1  -> pin 26 (DIR)
    IN2  -> pin 27 (DIR)

  Channel B -> REAR RIGHT  (RR)
    ENB  -> pin 5  (PWM)
    IN3  -> pin 28 (DIR)
    IN4  -> pin 29 (DIR)

  Note: Pin 2,3,4, and 5 are the timer-backed PWM pins in Mega.
**********************************************************/

#ifdef L298_MOTOR_DRIVER

  /* FRONT LEFT */
  #define FL_MOTOR_ENABLE    2
  #define FL_MOTOR_FORWARD   22
  #define FL_MOTOR_BACKWARD  23

  /* REAR LEFT */
  #define RL_MOTOR_ENABLE    3
  #define RL_MOTOR_FORWARD   24
  #define RL_MOTOR_BACKWARD  25

  /* FRONT RIGHT */
  #define FR_MOTOR_ENABLE    4
  #define FR_MOTOR_FORWARD   26
  #define FR_MOTOR_BACKWARD  27

  /* REAR RIGHT */
  #define RR_MOTOR_ENABLE    5
  #define RR_MOTOR_FORWARD   28
  #define RR_MOTOR_BACKWARD  29

#endif

void initMotorController();
void setMotorSpeed(int i, int spd);
void setMotorSpeeds(int leftSpeed, int rightSpeed);