# Mind Concentration Trainer

![Mind Concentration Trainer Banner](https://github.com/Xavier308/Assets/raw/main/Arduino/mindConcentrationBanner.png)

## Overview

This project allows users to control a servo motor using their brain activity, creating the illusion of telekinetic control over a metal ball. By using the NeuroSky Mindwave headset to measure concentration levels, you can physically move objects with nothing but your thoughts!

## The Story Behind It

I built this project before I even started my formal software engineering education at Holberton School. It was born out of my fascination with the intersection of technology and human capability - I've always wondered "what if we could move things with our minds?" So I decided to make it happen!

This was one of the most fun projects I've ever worked on. There's something magical about seeing a physical object respond to your thoughts. The first time I got the metal ball to rise just by focusing my mind, I couldn't stop smiling for hours.

## How It Works

The system uses:
- **NeuroSky Mindwave Mobile 2**: A non-invasive EEG headset that safely measures brainwave activity. It detects alpha waves, beta waves, and NeuroSky's proprietary "attention" and "meditation" metrics. The headset has sensors that rest on your forehead and earlobe to detect the faint electrical signals produced by your brain.

- **Arduino Uno**: A microcontroller board based on the ATmega328P. It serves as the brain of the project, processing the data from the Mindwave headset and controlling the servo motor based on attention levels.

- **HC-05 Bluetooth Module**: A serial communication module that enables wireless communication between the NeuroSky headset and the Arduino. It receives the brainwave data transmitted by the Mindwave headset via Bluetooth.

- **MG 996R Servo Motor**: A high-torque servo that provides precise angular control. It's connected to a pulley system that lifts the metal ball.

- **Pulley System with Metal Ball**: The physical manifestation of your mental effort.

The Arduino code (written in C++) receives attention level values from the NeuroSky headset via Bluetooth. The headset measures your concentration level on a scale from 0-100, and the Arduino maps these values to servo positions. As your concentration increases, the servo rotates to a wider angle, pulling up the metal ball on the pulley system. The more you focus, the higher the ball rises!

When your attention level is low (0-10), the servo moves to 0°. At maximum concentration (90-100), the servo rotates to 180°, lifting the ball to its highest position. This creates a visual feedback loop - seeing the ball rise encourages even deeper concentration.

## Why I Love This Project

This project represents what I'm all about - taking emerging technologies and creating tangible applications that feel like science fiction. I didn't just want to read data from a brain sensor - I wanted to create something that would make people say "wow!"

I've always been drawn to inventing new things and finding creative applications for technology. This project was my early exploration into how hardware and software can work together to create experiences that feel magical.

## Looking Forward

This project was just the beginning of my journey into building next-generation applications. Since then, I've refined my skills and vision, but my core motivation remains the same: I want to build technology that pushes boundaries and creates new possibilities.

---

*If you're looking for someone who can prototype innovative applications and bring fresh ideas to the table, I'd love to chat about how my creative approach to problem-solving could benefit your team!*

## Technical Details

The code is commented and includes all the necessary instructions to recreate this project. Feel free to modify and improve upon it!

## License

This project is based on example code provided by NeuroSky, Inc. (license free) and has been modified by Xavier J. Cruz.
