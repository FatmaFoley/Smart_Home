/*
 * main.c
 *
 *  Created on: Sep 22, 2025
 *      Author: Fatma Foley
 */

/******************************************************************************
 *                             Include Files                                   *
 ******************************************************************************/


#include "std_types.h"
#include "ldr.h"
#include "leds.h"
#include "lm35_temp_sensor.h"
#include "dc_motor.h"
#include "flame_sensor.h"
#include "lcd.h"
#include "buzzer.h"
#include "adc.h"
#include <avr/delay.h>

int main(void)
{
    /* Configure ADC with AVCC reference and prescaler 128 */
    ADC_DYNAMIC_CONVEGRATIONS configrations ={AVCC_with_external_capacitor_at_AREF_pin, PRESCALER_128};
    ADC_init(&configrations);

    /* Initialize peripherals */
    LCD_init();
    LEDS_init();
    LM35_init();
    DcMotor_Init();
    FlameSensor_init();
    Buzzer_init();

    _delay_ms(1);

    uint16 intensity;

    while(1)
    {
        /* Read light intensity from LDR */
        intensity = LDR_getLightIntensity();
        _delay_ms(1);

        /* Display "LDR=" label at row 1, column 8 */
        LCD_displayStringRowColumn(1, 8, "LDR=");

        /* Display light intensity with spacing alignment */
        if (100 == intensity)
        {
            LCD_moveCursor(1, 12);
            LCD_intgerToString(intensity);
        }
        else if (intensity >= 10)
        {
            LCD_moveCursor(1, 12);
            LCD_intgerToString(intensity);
            LCD_displayStringRowColumn(1, 14, " ");
        }
        else
        {
            LCD_moveCursor(1, 12);
            LCD_intgerToString(intensity);
            LCD_displayStringRowColumn(1, 13, "  ");
        }

        /* Display percentage symbol */
        LCD_moveCursor(1, 15);
        LCD_displayCharacter('%');

        /* Control LEDs based on light intensity thresholds */
        if(intensity > 70)
        {
            LED_off(LEDS_RED_LED_ID);
            LED_off(LEDS_GREEN_LED_ID);
            LED_off(LEDS_BLUE_LED_ID);
        }
        else if(intensity > 50)
        {
            LED_on(LEDS_RED_LED_ID);
            LED_off(LEDS_GREEN_LED_ID);
            LED_off(LEDS_BLUE_LED_ID);
        }
        else if(intensity > 15)
        {
            LED_on(LEDS_RED_LED_ID);
            LED_on(LEDS_GREEN_LED_ID);
            LED_off(LEDS_BLUE_LED_ID);
        }
        else
        {
            LED_on(LEDS_RED_LED_ID);
            LED_on(LEDS_GREEN_LED_ID);
            LED_on(LEDS_BLUE_LED_ID);
        }

        /* Read temperature from LM35 sensor */
        uint8 temperature_value = LM35_getTemperature();
        _delay_ms(1);

        /* Display temperature label */
        LCD_displayStringRowColumn(1, 0, "Temp=");

        /* Display temperature value with spacing alignment */
        if (temperature_value >= 100)
        {
            LCD_moveCursor(1, 5);
            LCD_intgerToString(temperature_value);
        }
        else if (temperature_value >= 10)
        {
            LCD_moveCursor(1, 5);
            LCD_intgerToString(temperature_value);
            LCD_displayStringRowColumn(1, 7, " ");
        }
        else
        {
            LCD_moveCursor(1, 5);
            LCD_intgerToString(temperature_value);
            LCD_displayStringRowColumn(1, 6, "  ");
        }

        /* Control fan speed and display fan status on LCD based on temperature */
        if (temperature_value >= 40)
        {
            DcMotor_Rotate(CW, 100);
            LCD_displayStringRowColumn(0, 3, "FAN is ON ");
        }
        else if (temperature_value >= 35)
        {
            DcMotor_Rotate(CW, 75);
            LCD_displayStringRowColumn(0, 3, "FAN is ON ");
        }
        else if (temperature_value >= 25)
        {
            DcMotor_Rotate(CW, 25);
            LCD_displayStringRowColumn(0, 3, "FAN is ON ");
        }
        else
        {
            DcMotor_Rotate(Stop, 0);
            LCD_displayStringRowColumn(0, 3, "FAN is OFF");
        }

        /* Flame sensor alert: if flame detected, show alert and sound buzzer */
        if (FlameSensor_getValue())
        {
            LCD_clearScreen();
            LCD_displayStringRowColumn(0, 1, "Critical alert!");
            Buzzer_on();

            /* Wait until flame sensor output returns low */
            while (FlameSensor_getValue());

            LCD_clearScreen();
            Buzzer_off();
        }
    }
}
