
void initADS() {
  display.clearDisplay();
  display.setTextSize(1);
  if (!ads.begin()) {
    Serial.println("ADS1115 GAGAL!!");
    display.getTextBounds(F("ADS1115 GAGAL!!"), 0, 0, &ox, &oy, &ow, &oh);
    display.setCursor((128 - ow) / 2, 17);
    display.print(F("RTC GAGAL!!"));
    display.display();
    while (true)
      ;
  }
  Serial.println("ADS1115 AMAN");
  display.getTextBounds(F("ADS1115 AMAN"), 0, 0, &ox, &oy, &ow, &oh);
  display.setCursor((128 - ow) / 2, 17);
  display.print(F("ADS1115 AMAN"));
  display.display();
  delay(2000);
}
