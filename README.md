# Pushbutton-Controlled State Machine | PIC32MZ2048EFH144

This project implements a pushbutton-driven finite state machine (FSM) on the PIC32MZ2048EFH144 microcontroller using MPLAB X v4.15 and Harmony v2. An LED visually indicates each state, and the system transitions between states based on button inputs with precise software-based debouncing.

---

## Features

- Finite State Machine with three active states and one initial state
- Two pushbuttons for forward and reverse state transitions
- LED indicators for each state (LED1, LED2, LED3)
- Software-based debouncing using SYS_TMR_TickCountGet() for accurate edge detection
- Non-blocking logic for real-time responsiveness

---

## Tools & Technologies

- **Microcontroller**: PIC32MZ2048EFH144  
- **IDE**: MPLAB X v4.15  
- **Framework**: MPLAB Harmony v2.06  
- **Language**: Embedded C

---

## System Overview

| State         | LED Indicator |
|---------------|---------------|
| INIT          | All OFF       |
| STATE 1       | LED1 ON       |
| STATE 2       | LED2 ON       |
| STATE 3       | LED3 ON       |

- **Debounce threshold**: 300ms
- **Tick source**: SYS_TMR module

---

## File Structure


firmware/

src/

app.c → UART command parsing logic, state machine execution

app.h → State definitions, UART buffer declarations

main.c → System init and main task loop

system_config/

default/

system_init.c → Driver/system service initialization

system_config.h → System configuration header

system_definitions.h → Global handles and includes

system_tasks.c → Calls application task function

bsp/ → Board support package files (UART pins, LEDs)

.X/ → MPLAB Harmony project metadata/build directory

README.md → Project description, usage, features

doc/ (optional) → UART command list, design notes, screenshots
