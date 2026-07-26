/* *************************************************************
   Encoder driver function definitions - by James Nugen
   *************************************************************
   Encoder driver function definitions 4WD version
   
   All of the 4 encoders used  PORTK (Arduino Mega pin A8 to A15),
   as results, all of them served by an ISR PCINT2_vect.
   
   Pin mapping:
     FL_ENC_PIN_A  = PK0 (A8)
     FL_ENC_PIN_B  = PK1 (A9)
     RL_ENC_PIN_A  = PK2 (A10)
     RL_ENC_PIN_B  = PK3 (A11)
     FR_ENC_PIN_A  = PK4 (A12)
     FR_ENC_PIN_B  = PK5 (A13)
     RR_ENC_PIN_A  = PK6 (A14)
     RR_ENC_PIN_B  = PK7 (A15)
   */

#ifdef ARDUINO_ENC_COUNTER

  /* FRONT LEFT PORTK bit 0 and 1 */
  #define FL_ENC_PIN_A  PK0   // A8
  #define FL_ENC_PIN_B  PK1   // A9

  /* REAR LEFT PORTK bit 2 and 3 */
  #define RL_ENC_PIN_A  PK2   // A10
  #define RL_ENC_PIN_B  PK3   // A11

  /* FRONT RIGHT PORTK bit 4 and 5 */
  #define FR_ENC_PIN_A  PK4   // A12
  #define FR_ENC_PIN_B  PK5   // A13

  /* REAR RIGHT PORTK bit 6 and 7 */
  #define RR_ENC_PIN_A  PK6   // A14
  #define RR_ENC_PIN_B  PK7   // A15

#endif

long readEncoder(int i);
void resetEncoder(int i);
void resetEncoders();
