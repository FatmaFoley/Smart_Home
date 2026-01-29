/*
 * ldr.c
 *
 *  Created on: Sep 23, 2025
 *      Author: Fatma Foley
 */

/******************************************************************************
 *                             Include Files                                   *
 ******************************************************************************/

#include "ldr.h"
#include <avr/delay.h>
#include "adc.h"
#include "gpio.h"

/*
 * Function: LDR_getLightIntensity
 * ----------------------------
 *   Reads the analog value from the ADC channel connected to the LDR sensor,
 *   calculates the light intensity percentage based on ADC reading and known
 *   calibration constants, and returns the intensity capped at 100%.
 *
 *   returns: uint16 representing light intensity as percentage (0-100)
 */
uint16 LDR_getLightIntensity(void)
{
    uint16 intensity_value = 0;

    // Read the ADC channel where the LDR voltage divider output is connected
    intensity_value = ADC_readChannel(LDR_SENSOR_CHANNEL_ID);

    _delay_ms(5);  // Small delay for signal stabilization

    // Convert ADC digital value to light intensity percentage
    // The formula accounts for ADC reference voltage, maximum sensor output voltage,
    // maximum light intensity scale, and ADC resolution.
    intensity_value = (uint16)(((uint32)intensity_value * ADC_REF_VOLT_VALUE * LDR_SENSOR_MAX_LIGHT_INTENSITY) /
                               (LDR_SENSOR_MAX_VOLT_VALUE * ADC_MAXIMUM_VALUE));

    // Limit the maximum intensity value to 100%
    if(intensity_value > 100)
    {
        return 100;
    }
    else
    {
        return intensity_value;
    }
}
