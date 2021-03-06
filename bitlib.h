#include <stdint.h>
#define BITLIB_DEBUG


#ifdef BITLIB_DEBUG
    #include <assert.h>
#endif


#ifdef BITLIB_DEBUG
    #define ASSERT(cond) assert(cond)
#else
    #define ASSERT(cond)
#endif


#define CHAR_BIT 8  // the number of bits per byte (normally 8)


/*
    获取大于等于n的2的幂
*/
uint32_t next_power_of_2(uint32_t n) {
    const static uint32_t max_value = 1 << 14;  // change it to set max value
    uint32_t k = n - 1;
    k |= k >> 1;
    k |= k >> 2;
    k |= k >> 4;
    k |= k >> 8;
    k |= k >> 16;
    return k >= max_value ? max_value : k + 1;
}

/* 
    获取大于等于n的align的倍数
*/
uint32_t next_multiple(uint32_t n, uint32_t align) {
    // const static uint32_t align = 32;
    const static uint32_t max_value = 1 << 14;  // change it to set max value

    uint32_t k = ((n + align - 1) & ~(align - 1));
    return k >= max_value ? max_value : k;
}

/*
    获取n的符号
*/
int32_t sign_bits(int32_t n) {
    // avoid branching on CPUs with flag registers (IA32)
    return -(int32_t)((uint32_t)((int)n) >> (sizeof(int) * CHAR_BIT -1));
}