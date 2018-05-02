//  ORIGINAL SKETCH BY:
//  Udo Klein (Blinkenlight)
//  for Blinkenlight Shield
//  https://blog.blinkenlight.net/experiments/basic-effects/pov-reloaded/
//  
//  ADAPTED BY:
//  SC Lim (Cytron Technologies)
//  for Maker UNO 
//  https://makeruno.com.my/
//

#include "MsTimer2.h"
#include <avr/io.h>
#include <avr/pgmspace.h>
 
#define PARSE(pattern) ((pattern>>8) & 0b111111), (pattern & 0b11111111)


uint8_t const pov_iloveu[] PROGMEM = {
    PARSE( 0b000000000000 ),
    PARSE( 0b000000000000 ),
    PARSE( 0b000000000000 ),
    PARSE( 0b000000000000 ),
    PARSE( 0b000000000000 ),
    PARSE( 0b000000000000 ),
    PARSE( 0b000000000000 ),
    PARSE( 0b000000000000 ),
    PARSE( 0b000000000000 ),
    PARSE( 0b000000000000 ),
    PARSE( 0b000000000000 ),
    PARSE( 0b000000000000 ),
    PARSE( 0b111111111111 ),
    PARSE( 0b111111111111 ),
    PARSE( 0b000000000000 ),
    PARSE( 0b000000000000 ),
    PARSE( 0b000000000000 ),
    PARSE( 0b000000000000 ),
    PARSE( 0b000001110000 ),
    PARSE( 0b000011111000 ),
    PARSE( 0b000111111110 ),
    PARSE( 0b001111111111 ),
    PARSE( 0b011111111110 ),
    PARSE( 0b011111111100 ),
    PARSE( 0b111111111000 ),
    PARSE( 0b111111111100 ),
    PARSE( 0b011111111110 ),
    PARSE( 0b011111111111 ),
    PARSE( 0b001111111110 ),
    PARSE( 0b000011111000 ),
    PARSE( 0b000001110000 ),
    PARSE( 0b000000000000 ),
    PARSE( 0b000000000000 ),
    PARSE( 0b000000000000 ),
    PARSE( 0b000000000000 ),
    PARSE( 0b011111111111 ),
    PARSE( 0b111111111111 ),
    PARSE( 0b111000000000 ),
    PARSE( 0b110000000000 ),
    PARSE( 0b111000000000 ),
    PARSE( 0b111111111111 ),
    PARSE( 0b011111111111 ),
    PARSE( 0b000000000000 ),
    PARSE( 0b000000000000 ),
    PARSE( 0b000000000000 ),
    PARSE( 0b000000000000 ),
    PARSE( 0b000000000000 ),
    PARSE( 0b000000000000 ),
    PARSE( 0b000000000000 ),
    PARSE( 0b000000000000 ),
    PARSE( 0b000000000000 ),
    PARSE( 0b000000000000 ),
    PARSE( 0b000000000000 ),
    PARSE( 0b000000000000 ),
    PARSE( 0b000000000000 ),
    PARSE( 0b000000000000 ),
    PARSE( 0b000000000000 ),
    PARSE( 0b000000000000 ),   
};


void blink_iloveu() {
    static uint16_t index = 0;

    PORTB = pgm_read_byte(pov_iloveu+(index++));
    PORTD = pgm_read_byte(pov_iloveu+(index++));
 
    if (index >= sizeof(pov_iloveu)) { index = 0; }
}


void setup() {
  
  DDRD = 0b11111111; // set digital  0- 7 to output
  DDRB = 0b00111111; // set digital  8-13 to output

  MsTimer2::set(2, blink_iloveu);
  MsTimer2::start();
}


void loop() { 
  
}

