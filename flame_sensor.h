/*
 * flame.h
 *
 *  Created on: Sep 23, 2025
 *      Author: Fatma Foley
 */

#ifndef FLAME_SENSOR_H_
#define FLAME_SENSOR_H_

/******************************************************************************
 *                             Include Files                                   *
 ******************************************************************************/

#include "std_types.h"


/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

/* Define the port and pin ID connected to the flame sensor output */
#define FLAME_SENSOR_OUT_PORT_ID         PORTD_ID
#define FLAME_SENSOR_OUT_PIN_ID          PIN2_ID

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

/* Initialize the flame sensor pin as input */
void FlameSensor_init(void);

/* Get the current digital value read from the flame sensor */
uint8 FlameSensor_getValue(void);

#endif /* FLAME_SENSOR_H_ */
