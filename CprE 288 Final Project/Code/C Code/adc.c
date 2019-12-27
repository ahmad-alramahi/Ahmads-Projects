#include <stdint.h>
#include <stdbool.h>
#include "timer.h"
#include "lcd.h"
#include <inc/tm4c123gh6pm.h>
#include "driverlib/interrupt.h"

/**
 * Generates the ADC module for reading the IR Distance.
 *
 * Authors : Daniel Nikolic
 *         : Ahmad Alramahi
 *         : Rithwik Gokhale
 *         : Hayden Sellars
 */

void adc_init(void)
{
    SYSCTL_RCGCGPIO_R |= 0b10;                                     // enable ADC 0 module on port B
    SYSCTL_RCGCADC_R |= 0x1;                                       // enable clock for ADC
    GPIO_PORTB_AFSEL_R |= 0x01;                                    // enable port B pin 4 to work as alternate functions
    GPIO_PORTB_DEN_R |= 0b00010000;                                // set pin to input - 0
    GPIO_PORTB_AMSEL_R |= 0x10;                                    // disable analog isolation for the pin
    GPIO_PORTB_ADCCTL_R = 0x00;                                    // initialize the port trigger source as processor (default)
    ADC0_ACTSS_R &= ~ADC_ACTSS_ASEN0;                              // disable SS0 sample sequencer to configure it
    ADC0_EMUX_R = ADC_EMUX_EM0_PROCESSOR;                          // initialize the ADC trigger source as processor (default)
    ADC0_SSMUX0_R |= 0x000A;                                       // set 1st sample to use the AIN10 ADC pin
    ADC0_SSCTL0_R |= (ADC_SSCTL0_IE0 | ADC_SSCTL0_END0);           // enable raw interrupt status
    ADC0_SAC_R |= ADC_SAC_AVG_64X;                                 // enable oversampling to average
    ADC0_ACTSS_R |= ADC_ACTSS_ASEN0;                               // re-enable ADC0 SS0
}

int adc_read(void)
{
    ADC0_PSSI_R = ADC_PSSI_SS0;               // initiate SS0 conversion

    while ((ADC0_RIS_R & ADC_RIS_INR0) == 0)  // wait for ADC conversion to be complete
    {
        // wait
    }
	
    // grab result
    int value = ADC0_SSFIFO0_R;
    return value;
}
