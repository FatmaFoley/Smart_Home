/*
 * flame.c
 *
 *  Created on: Sep 23, 2025
 *      Author: Fatma Foley
 */


/******************************************************************************
 *                             Include Files                                   *
 ******************************************************************************/

#include "flame_sensor.h"
#include "common_macros.h"
#include "gpio.h"

/* Initialize the flame sensor pin as input */
void FlameSensor_init(void)
{
    GPIO_setupPinDirection(FLAME_SENSOR_OUT_PORT_ID, FLAME_SENSOR_OUT_PIN_ID, PIN_INPUT);
}

/* Read and return the current value from the flame sensor pin */
uint8 FlameSensor_getValue(void)
{
    return GPIO_readPin(FLAME_SENSOR_OUT_PORT_ID, FLAME_SENSOR_OUT_PIN_ID);
}
