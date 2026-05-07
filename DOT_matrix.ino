#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_ADXL345_U.h>
#include <MD_MAX72xx.h>
#include <SPI.h>

// ---------------- ADXL345 ----------------
Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified(12345);

// ---------------- MATRIX ----------------
#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
#define MAX_DEVICES 4
#define CS_PIN 10

MD_MAX72XX M = MD_MAX72XX(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);

// ---------------- GRID ----------------
#define WIDTH (MAX_DEVICES * 8)
#define HEIGHT 8

struct Dot {
  int x;
  int y;
};

#define MAX_DOTS 200
Dot dots[MAX_DOTS];

// ---------------- SETUP ----------------
void setup()
{
  Serial.begin(9600);

  if (!accel.begin())
  {
    Serial.println("ADXL345 not found!");
    while (1);
  }

  accel.setRange(ADXL345_RANGE_16_G);

  M.begin();
  M.control(MD_MAX72XX::INTENSITY, 5);
  M.clear();

  randomSeed(analogRead(A0));

  // create random dots
  for (int i = 0; i < MAX_DOTS; i++)
  {
    dots[i].x = random(WIDTH);
    dots[i].y = random(HEIGHT);
  }
}

// ---------------- LOOP ----------------
void loop()
{
  sensors_event_t event;
  accel.getEvent(&event);

  float ax = event.acceleration.x;
  float ay = event.acceleration.y;

  updateDots(ax, ay);
  drawDots();

  delay(100);
}

// ---------------- UPDATE DOTS ----------------
void updateDots(float ax, float ay)
{
  for (int i = 0; i < MAX_DOTS; i++)
  {
    // ---------------- Flat condition ----------------
    if (abs(ax) < 2 && abs(ay) < 2)
    {
      // random jitter (floating sand effect)
      dots[i].x += random(-1, 2);
      dots[i].y += random(-1, 2);
    }
    else
    {
      // ---------------- Tilt gravity ----------------
      if (ax > 2) dots[i].x += 1;
      if (ax < -2) dots[i].x -= 1;

      if (ay > 2) dots[i].y += 1;
      if (ay < -2) dots[i].y -= 1;
    }

    // ---------------- boundaries ----------------
    if (dots[i].x < 0) dots[i].x = 0;
    if (dots[i].x >= WIDTH) dots[i].x = WIDTH - 1;

    if (dots[i].y < 0) dots[i].y = 0;
    if (dots[i].y >= HEIGHT) dots[i].y = HEIGHT - 1;
  }
}

// ---------------- DRAW ----------------
void drawDots()
{
  M.clear();

  for (int i = 0; i < MAX_DOTS; i++)
  {
    M.setPoint(dots[i].y, dots[i].x, true);
  }
}