/*
 * ldr.h
 *
 *  Created on: Sep 23, 2025
 *      Author: Fatma Foley
 */

#ifndef LDR_H_
#define LDR_H_

/******************************************************************************
 *                             Include Files                                   *
 ******************************************************************************/

#include "std_types.h"


/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

/* ADC channel number to which the LDR sensor output is connected */
#define LDR_SENSOR_CHANNEL_ID                0

/* Maximum expected output voltage of the LDR sensor in volts */
#define LDR_SENSOR_MAX_VOLT_VALUE            2.56

/* Maximum light intensity percentage corresponding to max sensor output */
#define LDR_SENSOR_MAX_LIGHT_INTENSITY       100

/* Port and pin IDs where LDR sensor output signal is connected (if needed) */
#define LDR_SENSOR_INTENSITY_PORT_ID         PORTA_ID
#define LDR_SENSOR_INTENSITY_PIN_ID          PIN0_ID

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

/*
 * Reads the analog value from the ADC channel connected to the LDR sensor,
 * converts it to a light intensity percentage (0-100), and returns it.
 *
 * Returns:
 *   The computed light intensity percentage as a 16-bit unsigned integer.
 */
uint16 LDR_getLightIntensity(void);

#endif /* LDR_H_ */
