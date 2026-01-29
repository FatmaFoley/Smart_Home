/*
 * motor.c
 *
 *  Created on: Sep 23, 2025
 *      Author: Fatma Foley
 */

/******************************************************************************
 *                             Include Files                                   *
 ******************************************************************************/

#include "dc_motor.h"
#include "pwm.h"
#include "common_macros.h"
#include <avr/delay.h>
#include "gpio.h"

/* Initialize the DC motor pins and stop the motor initially */
void DcMotor_Init(void)
{
    /* Set motor control pins as output */
    GPIO_setupPinDirection(DC_MOTOR_IN1_PORT_ID, DC_MOTOR_IN1_PIN_ID, PIN_OUTPUT);
    GPIO_setupPinDirection(DC_MOTOR_IN2_PORT_ID, DC_MOTOR_IN2_PIN_ID, PIN_OUTPUT);
    GPIO_setupPinDirection(DC_MOTOR_EN1_PORT_ID, DC_MOTOR_EN1_PIN_ID, PIN_OUTPUT);

    /* Stop the motor by setting input pins low */
    GPIO_writePin(DC_MOTOR_IN1_PORT_ID, DC_MOTOR_IN1_PIN_ID, LOGIC_LOW);
    GPIO_writePin(DC_MOTOR_IN2_PORT_ID, DC_MOTOR_IN2_PIN_ID, LOGIC_LOW);
}

/* Rotate the DC motor in the specified state and speed */
void DcMotor_Rotate(DcMotor_State state, uint8 speed)
{
    /* Start PWM with the given speed for motor enable pin */
    PWM_Timer0_Start(speed);

    /* Set motor direction pins according to desired rotation state */
    switch(state)
    {
        case Stop:
            /* Both pins low to stop motor */
            GPIO_writePin(DC_MOTOR_IN1_PORT_ID, DC_MOTOR_IN1_PIN_ID, LOGIC_LOW);
            GPIO_writePin(DC_MOTOR_IN2_PORT_ID, DC_MOTOR_IN2_PIN_ID, LOGIC_LOW);
            break;

        case A_CW:
            /* Rotate motor Anti-Clockwise: IN1 low, IN2 high */
            GPIO_writePin(DC_MOTOR_IN1_PORT_ID, DC_MOTOR_IN1_PIN_ID, LOGIC_LOW);
            GPIO_writePin(DC_MOTOR_IN2_PORT_ID, DC_MOTOR_IN2_PIN_ID, LOGIC_HIGH);
            break;

        case CW:
            /* Rotate motor Clockwise: IN1 high, IN2 low */
            GPIO_writePin(DC_MOTOR_IN1_PORT_ID, DC_MOTOR_IN1_PIN_ID, LOGIC_HIGH);
            GPIO_writePin(DC_MOTOR_IN2_PORT_ID, DC_MOTOR_IN2_PIN_ID, LOGIC_LOW);
            break;
    }
}
