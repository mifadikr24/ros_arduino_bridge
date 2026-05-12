/***************************************************************
   Motor driver function definitions - by James Nugen
   *************************************************************/

#ifdef L298_MOTOR_DRIVER
  // Pins can be changed
  // However, DIRECTION must be able to support AnalogWrite
  #define RIGHT_MOTOR_BACKWARD  11
  #define LEFT_MOTOR_BACKWARD  9
  #define RIGHT_MOTOR_FORWARD  10
  #define LEFT_MOTOR_FORWARD  6

  #define RIGHT_MOTOR_ENABLE  7
  #define LEFT_MOTOR_ENABLE  12
  
  #define RIGHT2_MOTOR_ENABLE 8
  #define LEFT2_MOTOR_ENABLE  13
#endif

void initMotorController();
void setMotorSpeed(int i, int spd);
void setMotorSpeeds(int leftSpeed, int rightSpeed, int left2Speed, int right2Speed);
