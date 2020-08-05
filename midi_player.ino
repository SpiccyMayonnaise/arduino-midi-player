#include <Tone.h>
#include <avr/pgmspace.h>
#include <math.h>

//Track 1 - Acoustic Piano
static const uint16_t Track1[] PROGMEM {0b110000, 0b1111100100000001, 0b1111101100110111, 0b1111101000000001, 0b1111101000111110, 0b1111101000000001, 0b1111101000111100, 0b1111111110000000, 0b1111111110000000, 0b1111111110000000, 0b10110000000001, 0b1011110000110111, 0b1111101000000001, 0b1111101001000011, 0b1111101000000001, 0b1111111110000000, 0b1111111110000000, 0b1110111000110000, 0b1111100100000001, 0b1111101100110111, 0b1111101000000001, 0b1111101000111110, 0b1111101000000001, 0b1111101000111100, 0b1111111110000000, 0b1111111110000000, 0b1111111110000000, 0b10110000000001, 0b1011110000110111, 0b1111101000000001, 0b1111101001000011, 0b1111101000000001, 0b1111101000110111, 0b1111101000000001, 0b1111101000101100, 0b1111100100000001, 0b1111101100110111, 0b1111101000000001, 0b1111101000111110, 0b1111101000000001, 0b1111101000111100, 0b1111111110000000, 0b1111111110000000, 0b1111111110000000, 0b10110000000001, 0b1011110000110111, 0b1111101000000001, 0b1111101001000011, 0b1111101000000001, 0b1111111110000000, 0b1111111110000000, 0b1110111000101110, 0b1111100100000001, 0b1111101100110111, 0b1111101000000001, 0b1111101000111110, 0b1111101000000001, 0b1111101000111100, 0b1111111110000000, 0b1111111110000000, 0b1111111110000000, 0b10110000000001, 0b1011110000110111, 0b1111101000000001, 0b1111101001000011, 0b1111101000000001, 0b1111101000110111, 0b1111101000000001, 0b1111101000110000, 0b1111100100000001, 0b1111101100110111, 0b1111101000000001, 0b1111101000111110, 0b1111101000000001, 0b1111101000111100, 0b1111111110000000, 0b1111111110000000, 0b1111111110000000, 0b10110000000001, 0b1011110000110111, 0b1111101000000001, 0b1111101001000011, 0b1111101000000001, 0b1111111110000000, 0b1111111110000000, 0b1110111000110010, 0b1111100100000001, 0b1111101100110111, 0b1111101000000001, 0b1111101000111110, 0b1111101000000001, 0b1111101000111100, 0b1111111110000000, 0b1111111110000000, 0b1111111110000000, 0b10110000000001, 0b1011110000110111, 0b1111101000000001, 0b1111101001000011, 0b1111101000000001, 0b1111101000110111, 0b1111101000000001, 0b1111101000110011, 0b1111101000000001, 0b1111101000110111, 0b1111101000000001, 0b1111101000111110, 0b1111101000000001, 0b1111101000111100, 0b1111111110000000, 0b1111111110000000, 0b1111111110000000, 0b10110000000001, 0b1011110000110111, 0b1111101000000001, 0b1111101001000011, 0b1111101000000001, 0b1111111110000000, 0b1111111110000000, 0b1110111000110101, 0b1111100100000001, 0b1111101100110111, 0b1111101000000001, 0b1111101000111110, 0b1111101000000001, 0b1111101000111100, 0b1111111110000000, 0b1111111110000000, 0b1111111110000000, 0b10110000000001, 0b1011110000110111, 0b1111101000000001, 0b1111101001000011, 0b1111101000000001, 0b1111101000110111, 0b1111101000000001, 0b1111101000110000, 0b1111100100000001, 0b1111101100110111, 0b1111101000000001, 0b1111101000111110, 0b1111101000000001, 0b1111101000111100, 0b1111111110000000, 0b1111111110000000, 0b1111111110000000, 0b10110000000001, 0b1011110000110111, 0b1111101000000001, 0b1111101001000011, 0b1111101000000001, 0b1111111110000000, 0b1111111110000000, 0b1110111000110000, 0b1111100100000001, 0b1111101100110111, 0b1111101000000001, 0b1111101000111110, 0b1111101000000001, 0b1111101000111100, 0b1111111110000000, 0b1111111110000000, 0b1111111110000000, 0b10110000000001, 0b1011110000110111, 0b1111101000000001, 0b1111101001000011, 0b1111101000000001, 0b1111101000110111, 0b1111101000000001, 0b1111101000101100, 0b1111100100000001, 0b1111101100110111, 0b1111101000000001, 0b1111101000111110, 0b1111101000000001, 0b1111101000111100, 0b1111111110000000, 0b1111111110000000, 0b1111111110000000, 0b10110000000001, 0b1011110000110111, 0b1111101000000001, 0b1111101001000011, 0b1111101000000001, 0b1111111110000000, 0b1111111110000000, 0b1110111000101110, 0b1111100100000001, 0b1111101100110111, 0b1111101000000001, 0b1111101000111110, 0b1111101000000001, 0b1111101000111100, 0b1111111110000000, 0b1111111110000000, 0b1111111110000000, 0b10110000000001, 0b1011110000110111, 0b1111101000000001, 0b1111101001000011, 0b1111101000000001, 0b1111101000110111, 0b1111101000000001, 0b1111101000110000, 0b1111100100000001, 0b1111101100110111, 0b1111101000000001, 0b1111101000111110, 0b1111101000000001, 0b1111101000111100, 0b1111111110000000, 0b1111111110000000, 0b1111111110000000, 0b10110000000001, 0b1011110000110111, 0b1111101000000001, 0b1111101001000011, 0b1111101000000001, 0b1111111110000000, 0b1111111110000000, 0b1110111000110010, 0b1111100100000001, 0b1111101100110111, 0b1111101000000001, 0b1111101000111110, 0b1111101000000001, 0b1111101000111100, 0b1111111110000000, 0b1111111110000000, 0b1111111110000000, 0b10110000000001, 0b1011110000110111, 0b1111101000000001, 0b1111101001000011, 0b1111101000000001, 0b1111101000110111, 0b1111101000000001, 0b1111101000110011, 0b1111101000000001, 0b1111101000110111, 0b1111101000000001, 0b1111101000111110, 0b1111101000000001, 0b1111101000111100, 0b1111111110000000, 0b1111111110000000, 0b1111111110000000, 0b10110000000001, 0b1011110000110111, 0b1111101000000001, 0b1111101001000011, 0b1111101000000001, 0b1111111110000000, 0b1111111110000000, 0b1110111000110101, 0b1111100100000001, 0b1111101100110111, 0b1111101000000001, 0b1111101000111110, 0b1111101000000001, 0b1111101000111100, 0b1111111110000000, 0b1111111110000000, 0b1111111110000000, 0b10110000000001, 0b1011110000110111, 0b1111101000000001, 0b1111101001000011, 0b1111101000000001, 0b1111101000110111, 0b1111101000000001};
static const uint16_t Track1_Length = sizeof( Track1 ) / sizeof(uint16_t); 
//Track 2 - Acoustic Piano
static const uint16_t Track2[] PROGMEM {0b110000, 0b1111100100000001, 0b100110111, 0b1111101000000001, 0b111110, 0b1111101000000001, 0b111100, 0b1111111110000000, 0b1111010000000001, 0b110111, 0b1111101000000001, 0b1000011, 0b1111101000000001, 0b1111101000110000, 0b1111100100000001, 0b100110111, 0b1111101000000001, 0b111110, 0b1111101000000001, 0b111100, 0b1111111110000000, 0b1111010000000001, 0b110111, 0b1111101000000001, 0b1000011, 0b1111101000000001, 0b110111, 0b1111101000000001, 0b110000, 0b1111100100000001, 0b100110111, 0b1111101000000001, 0b111110, 0b1111101000000001, 0b111100, 0b1111111110000000, 0b1111010000000001, 0b110111, 0b1111101000000001, 0b1000011, 0b1111101000000001, 0b1111101000110000, 0b1111100100000001, 0b100110111, 0b1111101000000001, 0b111110, 0b1111101000000001, 0b111100, 0b1111111110000000, 0b1111010000000001, 0b110111, 0b1111101000000001, 0b1000011, 0b1111101000000001, 0b110111, 0b1111101000000001, 0b101100, 0b1111100100000001, 0b100110111, 0b1111101000000001, 0b111110, 0b1111101000000001, 0b111100, 0b1111111110000000, 0b1111010000000001, 0b110111, 0b1111101000000001, 0b1000011, 0b1111101000000001, 0b1111101000101100, 0b1111100100000001, 0b100110111, 0b1111101000000001, 0b111110, 0b1111101000000001, 0b111100, 0b1111111110000000, 0b1111010000000001, 0b110111, 0b1111101000000001, 0b1000011, 0b1111101000000001, 0b110111, 0b1111101000000001, 0b101110, 0b1111100100000001, 0b100110111, 0b1111101000000001, 0b111110, 0b1111101000000001, 0b111100, 0b1111111110000000, 0b1111010000000001, 0b110111, 0b1111101000000001, 0b1000011, 0b1111101000000001, 0b1111101000101110, 0b1111100100000001, 0b100110111, 0b1111101000000001, 0b111110, 0b1111101000000001, 0b111100, 0b1111111110000000, 0b1111010000000001, 0b110111, 0b1111101000000001, 0b1000011, 0b1111101000000001, 0b110111, 0b1111101000000001, 0b111100, 0b1111100100000001, 0b101000011, 0b1111101000000001, 0b1001010, 0b1111101000000001, 0b1001000, 0b1111111110000000, 0b1111010000000001, 0b1000011, 0b1111101000000001, 0b1001111, 0b1111101000000001, 0b1111101000111100, 0b1111100100000001, 0b101000011, 0b1111101000000001, 0b1001010, 0b1111101000000001, 0b1001000, 0b1111111110000000, 0b1111010000000001, 0b1000011, 0b1111101000000001, 0b1001111, 0b1111101000000001, 0b1000011, 0b1111101000000001, 0b111100, 0b1111100100000001, 0b101000011, 0b1111101000000001, 0b1001010, 0b1111101000000001, 0b1001000, 0b1111111110000000, 0b1111010000000001, 0b1000011, 0b1111101000000001, 0b1001111, 0b1111101000000001, 0b1111101000111100, 0b1111100100000001, 0b101000011, 0b1111101000000001, 0b1001010, 0b1111101000000001, 0b1001000, 0b1111111110000000, 0b1111010000000001, 0b1000011, 0b1111101000000001, 0b1001111, 0b1111101000000001, 0b1000011, 0b1111101000000001, 0b111000, 0b1111100100000001, 0b101000011, 0b1111101000000001, 0b1001010, 0b1111101000000001, 0b1001000, 0b1111111110000000, 0b1111010000000001, 0b1000011, 0b1111101000000001, 0b1001111, 0b1111101000000001, 0b1111101000111000, 0b1111100100000001, 0b101000011, 0b1111101000000001, 0b1001010, 0b1111101000000001, 0b1001000, 0b1111111110000000, 0b1111010000000001, 0b1000011, 0b1111101000000001, 0b1001111, 0b1111101000000001, 0b1000011, 0b1111101000000001, 0b111010, 0b1111100100000001, 0b101000011, 0b1111101000000001, 0b1001010, 0b1111101000000001, 0b1001000, 0b1111111110000000, 0b1111010000000001, 0b1000011, 0b1111101000000001, 0b1001111, 0b1111101000000001, 0b1111101000111010, 0b1111100100000001, 0b101000011, 0b1111101000000001, 0b1001010, 0b1111101000000001, 0b1001000, 0b1111111110000000, 0b1111010000000001, 0b1000011, 0b1111101000000001, 0b1001111, 0b1111101000000001, 0b1000011, 0b1111101000000001, 0b110000, 0b1111100100000001, 0b100110111, 0b1111101000000001, 0b111110, 0b1111101000000001, 0b111100, 0b1111111110000000, 0b1111010000000001, 0b110111, 0b1111101000000001, 0b1000011, 0b1111101000000001, 0b1111101000110000, 0b1111100100000001, 0b100110111, 0b1111101000000001, 0b111110, 0b1111101000000001, 0b111100, 0b1111111110000000, 0b1111010000000001, 0b110111, 0b1111101000000001, 0b1000011, 0b1111101000000001, 0b110111, 0b1111101000000001, 0b110000, 0b1111100100000001, 0b100110111, 0b1111101000000001, 0b111110, 0b1111101000000001, 0b111100, 0b1111111110000000, 0b1111010000000001, 0b110111, 0b1111101000000001, 0b1000011, 0b1111101000000001, 0b1111101000110000, 0b1111100100000001, 0b100110111, 0b1111101000000001, 0b111110, 0b1111101000000001, 0b111100, 0b1111111110000000, 0b1111010000000001, 0b110111, 0b1111101000000001, 0b1000011, 0b1111101000000001, 0b110111, 0b1111101000000001, 0b101100, 0b1111100100000001, 0b100110111, 0b1111101000000001, 0b111110, 0b1111101000000001, 0b111100, 0b1111111110000000, 0b1111010000000001, 0b110111, 0b1111101000000001, 0b1000011, 0b1111101000000001, 0b1111101000101100, 0b1111100100000001, 0b100110111, 0b1111101000000001, 0b111110, 0b1111101000000001, 0b111100, 0b1111111110000000, 0b1111010000000001, 0b110111, 0b1111101000000001, 0b1000011, 0b1111101000000001, 0b110111, 0b1111101000000001, 0b101110, 0b1111100100000001, 0b100110111, 0b1111101000000001, 0b111110, 0b1111101000000001, 0b111100, 0b1111111110000000, 0b1111010000000001, 0b110111, 0b1111101000000001, 0b1000011, 0b1111101000000001, 0b1111101000101110, 0b1111100100000001, 0b100110111, 0b1111101000000001, 0b111110, 0b1111101000000001, 0b111100, 0b1111111110000000, 0b1111010000000001, 0b110111, 0b1111101000000001, 0b1000011, 0b1111101000000001, 0b110111, 0b1111101000000001, 0b111100, 0b1111100100000001, 0b101000011, 0b1111101000000001, 0b1001010, 0b1111101000000001, 0b1001000, 0b1111111110000000, 0b1111010000000001, 0b1000011, 0b1111101000000001, 0b1001111, 0b1111101000000001, 0b1111101000111100, 0b1111100100000001, 0b101000011, 0b1111101000000001, 0b1001010, 0b1111101000000001, 0b1001000, 0b1111111110000000, 0b1111010000000001, 0b1000011, 0b1111101000000001, 0b1001111, 0b1111101000000001, 0b1000011, 0b1111101000000001, 0b111100, 0b1111100100000001, 0b101000011, 0b1111101000000001, 0b1001010, 0b1111101000000001, 0b1001000, 0b1111111110000000, 0b1111010000000001, 0b1000011, 0b1111101000000001, 0b1001111, 0b1111101000000001, 0b1111101000111100, 0b1111100100000001, 0b101000011, 0b1111101000000001, 0b1001010, 0b1111101000000001, 0b1001000, 0b1111111110000000, 0b1111010000000001, 0b1000011, 0b1111101000000001, 0b1001111, 0b1111101000000001, 0b1000011, 0b1111101000000001, 0b111000, 0b1111100100000001, 0b101000011, 0b1111101000000001, 0b1001010, 0b1111101000000001, 0b1001000, 0b1111111110000000, 0b1111010000000001, 0b1000011, 0b1111101000000001, 0b1001111, 0b1111101000000001, 0b1111101000111000, 0b1111100100000001, 0b101000011, 0b1111101000000001, 0b1001010, 0b1111101000000001, 0b1001000, 0b1111111110000000, 0b1111010000000001, 0b1000011, 0b1111101000000001, 0b1001111, 0b1111101000000001, 0b1000011, 0b1111101000000001, 0b111010, 0b1111100100000001, 0b101000011, 0b1111101000000001, 0b1001010, 0b1111101000000001, 0b1001000, 0b1111111110000000, 0b1111010000000001, 0b1000011, 0b1111101000000001, 0b1001111, 0b1111101000000001, 0b1111101000111010, 0b1111100100000001, 0b101000011, 0b1111101000000001, 0b1001010, 0b1111101000000001, 0b1001000, 0b1111111110000000, 0b1111010000000001, 0b1000011, 0b1111101000000001, 0b1001111, 0b1111101000000001, 0b1000011, 0b1111101000000001};
static const uint16_t Track2_Length = sizeof( Track2 ) / sizeof(uint16_t); 
//Track 3 - Acoustic Piano
static const uint16_t Track3[] PROGMEM {0b1001000, 0b1111101000000001, 0b1111111110000000, 0b1111010001001000, 0b1111101000000001, 0b1111111110000000, 0b1111010001001000, 0b1111111110000000, 0b111011100000001, 0b1111111110000000, 0b1111111110000000, 0b1111111110000000, 0b1111111110000000, 0b1111111110000000, 0b1111111110000000, 0b1111111110000000, 0b1111111110000000, 0b1111111110000000, 0b1111111110000000, 0b1111111110000000, 0b1111111110000000, 0b1111111110000000, 0b1111111110000000, 0b1111111110000000, 0b1111111110000000, 0b1110101000001, 0b1111101000000001, 0b1111111110000000, 0b1111010001000011, 0b1111101000000001, 0b1111111110000000, 0b1111010000111100, 0b1111101000000001, 0b1111101001000100, 0b1111101000000001, 0b1111111110000000, 0b1111010001000100, 0b1111101000000001, 0b1111111110000000, 0b1111010001000100, 0b1111111110000000, 0b111011100000001, 0b1111111110000000, 0b1111111110000000, 0b1111111110000000, 0b1111111110000000, 0b1111111110000000, 0b101111101000110, 0b1111101000000001, 0b1111111110000000, 0b1111010001000001, 0b1111101000000001, 0b1111111110000000, 0b1111010001000001, 0b1111101000000001, 0b1111111110000000, 0b1111010001000001, 0b1111111110000000, 0b111011100000001, 0b1111111110000000, 0b1111111110000000, 0b1111111110000000, 0b1111111110000000, 0b1111111110000000, 0b101111101000011, 0b1111101000000001, 0b1111111110000000, 0b1111010001001000, 0b1111101000000001, 0b1111111110000000, 0b1111010001001000, 0b1111101000000001, 0b1111111110000000, 0b1111010001001000, 0b1111111110000000, 0b111011100000001, 0b1111111110000000, 0b1111111110000000, 0b1111111110000000, 0b1111111110000000, 0b1111111110000000, 0b1111111110000000, 0b1111111110000000, 0b1111111110000000, 0b1111111110000000, 0b1111111110000000, 0b1111111110000000, 0b1111111110000000, 0b1111111110000000, 0b1111111110000000, 0b1111111110000000, 0b1111111110000000, 0b1110101000001, 0b1111101000000001, 0b1111111110000000, 0b1111010001000011, 0b1111101000000001, 0b1111111110000000, 0b1111010000111100, 0b1111101000000001, 0b1111101001000100, 0b1111101000000001, 0b1111111110000000, 0b1111010001000100, 0b1111101000000001, 0b1111111110000000, 0b1111010001000100, 0b1111111110000000, 0b111011100000001, 0b1111111110000000, 0b1111111110000000, 0b1111111110000000, 0b1111111110000000, 0b1111111110000000, 0b101111101000110, 0b1111101000000001, 0b1111111110000000, 0b1111010001000001, 0b1111101000000001, 0b1111111110000000, 0b1111010001000001, 0b1111101000000001, 0b1111111110000000, 0b1111010001000001, 0b1111111110000000, 0b111011100000001, 0b1111111110000000, 0b1111111110000000, 0b1111111110000000, 0b1111111110000000, 0b1111111110000000, 0b101111101000011, 0b1111101000000001, 0b1111111110000000, 0b1111010001001000, 0b1111111110000000, 0b1111010000000001, 0b1111101001001000, 0b1111111110000000, 0b1111010000000001, 0b1111101001001000, 0b1111111110000000, 0b1111010000000001, 0b1111111110000000, 0b1111111110000000, 0b1111111110000000, 0b1111111110000000, 0b1111111110000000, 0b1111111110000000, 0b1111111110000000, 0b1111111110000000, 0b1111111110000000, 0b1111111110000000, 0b1111111110000000, 0b1111111110000000, 0b1111111110000000, 0b1111111110000000, 0b1111111110000000, 0b1010000001000001, 0b1111111110000000, 0b1111010000000001, 0b1111101001000011, 0b1111111110000000, 0b1111010000000001, 0b1111101000111100, 0b1111111110000000, 0b1111010000000001, 0b1000100, 0b1111111110000000, 0b1111111110000000, 0b111000100000001, 0b111110101000100, 0b1111111110000000, 0b1111111110000000, 0b111000100000001, 0b111110101000100, 0b1111111110000000, 0b1111111110000000, 0b111000100000001, 0b1111111110000000, 0b1111111110000000, 0b1111111110000000, 0b1111111110000000, 0b110010101000110, 0b1111111110000000, 0b1111111110000000, 0b11100000001, 0b1110011101000001, 0b1111111110000000, 0b1111111110000000, 0b100101000000001, 0b1010010001000001, 0b1111111110000000, 0b1111111110000000, 0b100101000000001, 0b1010010001000001, 0b1111111110000000, 0b1111111110000000, 0b100101000000001, 0b1111111110000000, 0b1111111110000000, 0b1111111110000000, 0b1111111110000000, 0b1000110001000011, 0b1111111110000000, 0b1111010000000001, 0b1111101001001000, 0b1111111110000000, 0b1111010000000001, 0b1111101001001000, 0b1111111110000000, 0b1111010000000001, 0b1111101001001000, 0b1111111110000000, 0b1111010000000001, 0b1111111110000000, 0b1111111110000000, 0b1111111110000000, 0b1111111110000000, 0b1111111110000000, 0b1111111110000000, 0b1111111110000000, 0b1111111110000000, 0b1111111110000000, 0b1111111110000000, 0b1111111110000000, 0b1111111110000000, 0b1111111110000000, 0b1111111110000000, 0b1111111110000000, 0b1010000001000001, 0b1111111110000000, 0b1111010000000001, 0b1111101001000011, 0b1111111110000000, 0b1111010000000001, 0b1111101000111100, 0b1111111110000000, 0b1111010000000001, 0b1000100, 0b1111111110000000, 0b1111111110000000, 0b111000100000001, 0b111110101000100, 0b1111111110000000, 0b1111111110000000, 0b111000100000001, 0b111110101000100, 0b1111111110000000, 0b1111111110000000, 0b111000100000001, 0b1111111110000000, 0b1111111110000000, 0b1111111110000000, 0b1111111110000000, 0b110010101000110, 0b1111111110000000, 0b1111111110000000, 0b11100000001, 0b1110011101000001, 0b1111111110000000, 0b1111111110000000, 0b100101100000001, 0b1010001101000001, 0b1111111110000000, 0b1111111110000000, 0b100101100000001, 0b1010001101000001, 0b1111111110000000, 0b1111111110000000, 0b100101100000001, 0b1111111110000000, 0b1111111110000000, 0b1111111110000000, 0b1111111110000000, 0b1000101101000011, 0b1111111110000000, 0b1111010000000001};
static const uint16_t Track3_Length = sizeof( Track3 ) / sizeof(uint16_t); 


static const uint16_t Freq8[] = { 4186 , 4435 , 4699  , 4978 , 5274 , 5588 , 5920 , 6272 , 6645 , 7040 , 7459 , 7902 };

/*
  tone() Melody Player With Melodies Converted From on_the_island.mid
  ------------------------------------------------------------------------------  
  
  1. Save or copy-and-paste this file into the Arduino IDE
  2. Configure the tonePin variable
  3. Edit the melodyToPlay and tempoToPlay in the loop
  
  Wiring: Attach a typical piezo element between the tonePin defined below
  and ground.  Maybe put a resistor in series too if you are feeling cautious.
*/

static const uint16_t tempo = 3;

class Voice {
    private:
      uint16_t _pin;

      //The current index of the note
      uint16_t nextNote = 0;
      //The time of the next note
      uint64_t currentNote = 0;

      const uint16_t* _trackStart;
      uint16_t trackLength;

      Tone tone;
    
    public:
      Voice(int pin, const uint16_t* trackStart) {
        _pin = pin;

        tone.begin(_pin);

        _trackStart = trackStart;
      }

      void Update() {
        if (nextNote < millis()) {
          uint16_t data = pgm_read_word((uint16_t *)(_trackStart + currentNote));
          if ((data & 0b0000001) == 0b0000001) {
            tone.stop();

          } else if((data & 0b0000000) == 0b0000000) {
              // Do nothing
          
          } else {
            uint16_t Freq = (440 / 32) * pow(2, ((data & 0b0000000001111111) - 9) / 12);
            tone.play(Freq);    
            Serial.println(Freq);

          }    
          
          int16_t Duration = (data >> 7);
          
          currentNote++;
          
          nextNote = millis() + (Duration * tempo);
        }
      }
};

Voice* voice1;
Voice* voice2;

void setup() 
{
  Serial.begin(9600);

  voice1 = new Voice(7, &Track1[0]);
  voice2 = new Voice(8, &Track2[0]);
}

void loop() 
{
  voice1->Update();
  voice2->Update();
}