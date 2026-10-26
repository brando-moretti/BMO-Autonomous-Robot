# BMO Autonomous Robot 

Development of an autonomous, interactive desktop robot based on the ESP32 microcontroller. This project is built from scratch with a strong emphasis on non-blocking C++ architecture, hardware interrupts, and modular hardware design.

# Project Goals

The ultimate goal is to create a fully functional, interactive companion robot (inspired by BMO).
The software architecture strictly avoids blocking functions like delay(), relying entirely on millis() timers and hardware interrupts (ISR) to ensure real-time responsiveness for sensors, actuators, and communication protocols.

 # Hardware & Software Stack

Microcontroller: ESP32 (38-pin DevKit)

Display: 0.96" OLED I2C (SSD1306)

Environment: VS Code + PlatformIO

Core Libraries: Wire.h (I2C), Adafruit_GFX, Adafruit_SSD1306

# Development Roadmap

## Phase 0: Core Architecture (Completed)

[x] Non-blocking state machines using millis()

[x] Memory management (Structs and Pointers)

[x] Hardware Interrupts (ISR) and button debouncing

Phase 1: Communication Protocols & UI (Active)

[x] I2C Bus Bring-up (I2C Scanner)

[x] Static Face Rendering (Adafruit GFX)

[ ] Dynamic non-blocking animations (Blinking, Expressions)

## Phase 1.5: Actuators & Mobility (Upcoming)

[ ] PWM Motor Control (DRV8833 / L298N H-Bridge)

[ ] Servo motor integration for arms/head

## Phase 2: IoT & Connectivity

[ ] Wi-Fi Access Point and Web Server implementation

[ ] Remote control via HTTP/WebSockets

## Phase 3: The "Brain" (AI Integration)

[ ] Cloud API connectivity (OpenAI / Gemini)

[ ] Audio processing (I2S Microphones/Speakers)

# Current State

The project is currently in Phase 1. The ESP32 is successfully communicating with the OLED display via the I2C protocol (Address 0x3C). The static face of BMO is rendered using geometric shapes, laying the groundwork for the upcoming dynamic animation system.

Developed by Brando Moretti - Engineering Student & Aspiring Embedded Systems Engineer.
