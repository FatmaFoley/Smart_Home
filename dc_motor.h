/*
 * motor.h
 *
 *  Created on: Sep 23, 2025
 *      Author: Fatma Foley
 */

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

/******************************************************************************
 *                             Include Files                                   *
 ******************************************************************************/

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

/* Define the port and pin IDs for the motor control pins */
#define DC_MOTOR_IN1_PORT_ID            PORTB_ID
#define DC_MOTOR_IN1_PIN_ID             PIN0_ID
#define DC_MOTOR_IN2_PORT_ID            PORTB_ID
#define DC_MOTOR_IN2_PIN_ID             PIN1_ID
#define DC_MOTOR_EN1_PORT_ID            PORTB_ID
#define DC_MOTOR_EN1_PIN_ID             PIN3_ID

/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/

/* Enum for the motor rotation states */
typedef enum {
    CW,     /* Clockwise rotation */
    A_CW,   /* Anti-Clockwise rotation */
    Stop    /* Stop the motor */
} DcMotor_State;

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

/* Initialize the DC motor pins and state */
void DcMotor_Init(void);

/* Rotate the DC motor in a specified state and speed (PWM duty cycle) */
void DcMotor_Rotate(DcMotor_State state, uint8 speed);

#endif /* DC_MOTOR_H_ */
