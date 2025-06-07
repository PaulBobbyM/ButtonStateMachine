# Pushbutton-Controlled State Machine  | PIC32MZ2048EFH144

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
## Usage

- Press **Switch 1** to move to the next state (LED1 → LED2 → LED3 → INIT)
- Press **Switch 2** to go to the previous state (LED3 → LED2 → LED1 → INIT)
- Each state is visually indicated by the corresponding LED
- Input is debounced in software to ensure accurate transitions

## Build & Flash Instructions

1. Open the project in **MPLAB X v4.15**
2. Ensure Harmony v2.06 is correctly installed and linked
3. Select the correct hardware tool and compiler (XC32)
4. Build and flash to the PIC32MZ2048EFH144 board
