# DIY-LED-Sand-Simulation-Project

Turn an LED matrix into a mesmerizing flowing “digital sand” display that reacts to movement and gravity — perfect for desk setups, maker showcases, and Instagram reels.

---

## 🛠️ Components Required

1. [ESP32 NodeMCU-32 Development Board](https://robocraze.com/products/esp32-development-board)
2. [WS2812B 8x8 RGB LED Matrix](https://robocraze.com/products/ws2812-64bit-8x8-rgb-led-matrix-panel)
3. [MPU-6050 Gyroscope + Accelerometer Module](https://robocraze.com/products/mpu-6050-module)
4. [Jumper Wires Kit](https://robocraze.com/products/560-pcs-jumper-cable-for-interlocking-board-metal-bridge-jumper-wires-assortment)
5. Breadboard or PCB
6. USB Cable / Power Supply
7. Optional: Acrylic Case or Wooden Frame for aesthetic finish

---

## ⚙️ How It Works

- The MPU6050 senses tilt and motion in real time.
- Based on the tilt angle, virtual “sand particles” move across the LED matrix.
- LEDs dynamically light up to simulate realistic flowing sand behavior.
- The particles continuously react to gravity and orientation changes.

---

## ✨ Features

- Real-Time Gravity Simulation
- Smooth Particle Movement
- Interactive Motion Response
- Relaxing Desk Aesthetic
- Beginner-Friendly Physics + Electronics Project
- Perfect for STEM Exhibitions & Social Media Reels

---

## 🔌 Circuit Connections

### MPU6050 → ESP32

| MPU6050 Pin | ESP32 Pin |
|---|---|
| VCC | 3.3V |
| GND | GND |
| SDA | GPIO21 |
| SCL | GPIO22 |

### LED Matrix → ESP32

| LED Matrix Pin | ESP32 Pin |
|---|---|
| VCC | 5V |
| GND | GND |
| DIN | GPIO5 |

---

## 💻 Libraries Required

- FastLED / Adafruit NeoPixel
- Adafruit MPU6050
- Adafruit Sensor
- Wire.h

---

## 🚀 Project Flow

1. Read tilt and motion values from MPU6050
2. Calculate gravity direction based on orientation
3. Move digital particles accordingly
4. Update the LED matrix continuously
5. Create a smooth flowing sand simulation effect

---

## 🎯 Why This Project is Cool

- Combines Coding + Physics + Creativity
- Creates a Premium Interactive Display
- Looks Amazing on Desks & Gaming Setups
- Extremely Satisfying Visual Effect 😌
- Great for Learning Motion Sensors and LED Control

---

## 🎥 Project Reel

👉 [Watch on Instagram](https://www.instagram.com/reel/DYCcp-gzyjI/?igsh=MTQ3dzI4YXRjY2tjaA==)

