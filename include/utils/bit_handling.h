// bit_handling.h

#ifndef BIT_HANDLING_H
#define BIT_HANDLING_H

#include <stdbool.h>

uint16_t turn_on_bit_in_array(uint16_t bit_array, unsigned int position);

bool access_bit_array(uint16_t bit_array, unsigned int position);

int print_binary(uint16_t integer);

#endif
