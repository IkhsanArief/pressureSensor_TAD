#include <Wire.h>
#include <Adafruit_ADS1X15.h>
#include <SPI.h>
#include "SdFat.h"
#include <RTClib.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define SAMPLE_INTERVAL_MS 1000
#define tegangan 0

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
int16_t ox;
int16_t oy;
uint16_t ow, oh;

Adafruit_ADS1115 ads;
SdFat sd;
SdFile file;
RTC_DS3231 rtc;
DateTime now;

// GLOBAL
const uint8_t chipSelect = SS;
uint32_t logTime;
int fileNumber = 1;
char fileName[25];
int waktu;
int i;
int burst;
unsigned long reads = 0;  //pressure
int16_t reads1 = 0;       //pressure
float tekanan, volt;
float offset = 0.0;

void setup() {
  Serial.begin(115200);
  Wire.begin();

  initOLED();  //Inisialisasi OLED
  initRTC();   //Inisialisasi RTC
  initADS();   //Inisialisasi ADS1115
  initSD();    //Inisialisasi SDCard

  ads.setGain(GAIN_TWOTHIRDS);

  oledSetup();
}

void loop() {
  waktu = millis();
  now = rtc.now();
  logTime = millis() + SAMPLE_INTERVAL_MS;

  burstSampling();
  konversiTekanan();
  tampilkanSerial();
  tampilkanOLED();

  if (now.second() == 0) {
    dataLogging();
  }

  while (millis() < logTime)
    ;
}
