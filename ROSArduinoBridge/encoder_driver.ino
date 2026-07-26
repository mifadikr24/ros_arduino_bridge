/* *************************************************************.
   Encoder driver 4WD version
   
   All the 4 encoders are connected to PORTK (A8 to A15) so they only
   need an ISR: PCINT2_vect.
   
   ISR reads 8 bit PORTK at once and processes each pair of pins
   (A,B) per wheel with quadrature lookup table.
   ************************************************************ */

#ifdef USE_BASE
#ifdef ARDUINO_ENC_COUNTER

volatile long fl_enc_pos = 0L;
volatile long fr_enc_pos = 0L;
volatile long rl_enc_pos = 0L;
volatile long rr_enc_pos = 0L;

/* Quadrature state machine lookup table.
   Index = {prev_A, prev_B, curr_A, curr_B} as 4-bit value.
   Output: +1, -1, or 0. */
static const int8_t ENC_STATES[] = {
   0,  1, -1,  0,
  -1,  0,  0,  1,
   1,  0,  0, -1,
   0, -1,  1,  0
};

/* An ISR serves all the 4 encoders in PORTK */
ISR (PCINT2_vect) {
  static uint8_t portk_last = 0;
  uint8_t portk_now = PINK;  // read entire PORTK at once
  uint8_t changed   = portk_now ^ portk_last;

  /* --- FRONT LEFT: bit 0 (PA) and bit 1 (PB) --- */
  if (changed & 0x03) {
    uint8_t state = ((portk_last & 0x03) << 2) | (portk_now & 0x03);
    fl_enc_pos += ENC_STATES[state];
  }

  /* --- REAR LEFT: bit 2 (PA) and bit 3 (PB) --- */
  if (changed & 0x0C) {
    uint8_t state = (((portk_last & 0x0C) >> 2) << 2) | ((portk_now & 0x0C) >> 2);
    rl_enc_pos += ENC_STATES[state];
  }

  /* --- FRONT RIGHT: bit 4 (PA) and bit 5 (PB) --- */
  if (changed & 0x30) {
    uint8_t state = (((portk_last & 0x30) >> 4) << 2) | ((portk_now & 0x30) >> 4);
    fr_enc_pos += ENC_STATES[state];
  }

  /* --- REAR RIGHT: bit 6 (PA) and bit 7 (PB) --- */
  if (changed & 0xC0) {
    uint8_t state = (((portk_last & 0xC0) >> 6) << 2) | ((portk_now & 0xC0) >> 6);
    rr_enc_pos += ENC_STATES[state];
  }

  portk_last = portk_now;
}

/* Wrap the encoder reading function */
long readEncoder(int i) {
  switch (i) {
    case FRONT_LEFT:  return fl_enc_pos;
    case FRONT_RIGHT: return fr_enc_pos;
    case REAR_LEFT:   return rl_enc_pos;
    case REAR_RIGHT:  return rr_enc_pos;
    default:          return 0;
  }
}

/* Wrap the encoder reset function based-on wheel's index */
void resetEncoder(int i) {
  switch (i) {
    case FRONT_LEFT:  fl_enc_pos = 0L; break;
    case FRONT_RIGHT: fr_enc_pos = 0L; break;
    case REAR_LEFT:   rl_enc_pos = 0L; break;
    case REAR_RIGHT:  rr_enc_pos = 0L; break;
  }
}

#else
  #error A encoder driver must be selected!
#endif

/* Wrap the encoder reset function */
void resetEncoders() {
  resetEncoder(FRONT_LEFT);
  resetEncoder(FRONT_RIGHT);
  resetEncoder(REAR_LEFT);
  resetEncoder(REAR_RIGHT);
}

#endif