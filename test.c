#include "bitlib.h"

#include <assert.h>
#include <stdio.h>
#include <stdint.h>

#define TRUE  1
#define FALSE 0
#define BOOL int


void test_get_next_power_of_2() {
    assert(next_power_of_2(1) == 1);
    assert(next_power_of_2(2) == 2);
    assert(next_power_of_2(3) == 4);
    assert(next_power_of_2(6) == 8);
    assert(next_power_of_2(10) == 16);
    assert(next_power_of_2(20) == 32);
    assert(next_power_of_2(40) == 64);
    assert(next_power_of_2(120) == 128);
    assert(next_power_of_2(1000) == 1024);
}

void test_next_multiple() {
    assert(next_multiple(1, 8) == 8);
    assert(next_multiple(30, 8) == 32);
    
    assert(next_multiple(1, 16) == 16);
    assert(next_multiple(30, 16) == 32);

    assert(next_multiple(1, 32) == 32);
    assert(next_multiple(40, 32) == 64);
    assert(next_multiple(1000, 32) == 1024);
}

void test_sign_bits() {
    assert(sign_bits(0) == 0);
    assert(sign_bits(1) == 0);
    assert(sign_bits(2) == 0);
    assert(sign_bits(-0) == 0);
    assert(sign_bits(-1) == -1);
    assert(sign_bits(-2) == -1);
}



int main() {
    test_get_next_power_of_2();
    test_next_multiple();
    test_sign_bits();

    return 0;
}