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


/firmware/
├── /src/
│   ├── app.c                → Application logic (state machine, debouncing)
│   ├── app.h                → Application state enums and definitions
│   ├── main.c               → System initialization and task calling
│   └── system_config/
│       ├── default/
│       │   ├── system_init.c       → Hardware and middleware initialization
│       │   ├── system_config.h     → Configuration header
│       │   ├── system_definitions.h → Global system declarations
│       │   └── system_tasks.c      → Scheduler-style task runner
│       └── bsp/                    → Board support package files
├── /doc/ (optional)         → Documentation or design notes
├── README.md
└── *.X/                     → MPLAB Harmony project folder (e.g., .X production)
