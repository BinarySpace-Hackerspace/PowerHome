#include <stdint.h>
#include <stm32l1xx.h>

#define STACK_TOP 0x20000800   

static void nmi_handler(void);
static void hardfault_handler(void);
int main(void);

// Define the vector table
unsigned int *myvectors[4]
__attribute__ ((section("vectors"))) = {
    (unsigned int *) STACK_TOP,         // stack pointer
    (unsigned int *) main,              // code entry point
    (unsigned int *) nmi_handler,       // NMI handler (not really)
    (unsigned int *) hardfault_handler  // hard fault handler
};


int main(void)
{
  RCC->AHBENR |=  (1UL <<  1);              /* Enable GPIOB clock         */
  GPIOB->MODER   |=   (0x00005000);             /* General purpose output mode*/
  GPIOB->OSPEEDR |=   (0x00005000);             /* 2 MHz Low speed            */

  GPIOB->BSRRL = 1L << 6; 

    int i=0;

    for(;;)
    {
        i++;
    }
}

void nmi_handler(void)
{
    for(;;);
}

void hardfault_handler(void)
{
    for(;;);
}
