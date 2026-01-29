🏠 Smart Home Automation System
📌 Project Overview

This project implements a Smart Home Automation System using an ATmega32 microcontroller.
The system automatically controls:

💡 Lighting (based on LDR)

🌡️ Fan speed (based on temperature)

🔥 Fire detection & alarm

📟 LCD real-time display

It simulates a smart home environment with automatic decision-making based on sensor readings.

🎯 Project Objectives

Automate lighting using LDR sensor

Control fan speed based on temperature

Detect fire and activate alarm

Display system status on LCD

Apply layered architecture for drivers

⚙️ System Features
🔹 Lighting Control (LDR)
Light Intensity	LED Status
< 15%	Red + Green + Blue ON
16–50%	Red + Green ON
51–70%	Red ON
> 70%	All LEDs OFF
🔹 Fan Speed Control (LM35)
Temperature	Fan Speed
≥ 40°C	100%
35–40°C	75%
30–35°C	50%
25–30°C	25%
< 25°C	OFF
🔹 Fire Detection

Flame sensor detects fire

LCD shows "Critical Alert!"

Buzzer turns ON

System stays in alert mode until fire is removed

🔹 LCD Display

Line 1: Fan status (ON / OFF)

Line 2: Temperature & Light intensity

🧰 Hardware Components
Component	Description
Microcontroller	ATmega32
Temperature Sensor	LM35
Light Sensor	LDR
Flame Sensor	Fire detection
LCD	16x2 (8-bit mode)
Motor	DC Fan
LEDs	Red, Green, Blue
Buzzer	Fire alarm
Motor Driver	H-Bridge
🔌 Pin Configuration
LCD
Pin	Connection
RS	PD0
EN	PD1
RW	GND
Data	PORTC
Sensors
Sensor	Pin
LDR	PA0
LM35	PA1
Flame Sensor	PD2
Outputs
Device	Pin
Buzzer	PD3
Motor IN1	PB0
Motor IN2	PB1
Motor EN	PB3 (PWM)
Red LED	PB5
Green LED	PB6
Blue LED	PB7
🧠 Software Architecture

The project follows Layered Architecture:

Application Layer

HAL Layer (LCD, Sensors, Motor)

MCAL Layer (ADC, GPIO, PWM)

Hardware Layer

⚡ Drivers Implemented

ADC Driver

GPIO Driver

PWM Driver

LCD Driver

LDR Driver

LM35 Driver

DC Motor Driver

Flame Sensor Driver

Buzzer Driver

LED Driver

🛠 Tools Used

Microchip Studio

Proteus Simulation

AVR-GCC

ATmega32

GitHub

🎥 Project Demo

🔗 Project Video:
https://youtu.be/Iyj7sOfwYLw

🔗 Flame Sensor Library:
https://www.mediafire.com/file/cnrdckfrdxun270/Flame-Sensor-Library-For-Proteus-main.zip/file

👩‍💻 Author

Fatma Foley
Smart Home Automation Project
Embedded Systems – Mini Project
