#include <stdint.h>


#define REG1 *((volatile uint32_t *)0x48028110)
#define REG2 *((volatile uint32_t *)0x48028100)
#define JUMP_ADDRESS ((void (*)())0x08000325)

int main(void) {

    volatile uint32_t *reg1;
    volatile uint32_t *reg2;
    uint32_t value;


    reg1 = (volatile uint32_t *)0x48028110;
    value = 0x8080; // movs r2, #0x8080
    *reg1 = value;  // str r2, [r1]

    reg2 = (volatile uint32_t *)0x48028100;
    *reg2 = value;  // str r2, [r1]


    void (*jump_to_address)(void) = JUMP_ADDRESS;
    

    jump_to_address();


    while (1) {
    }
    return 0;
}
