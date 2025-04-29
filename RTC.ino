
void initRTC() {
  display.clearDisplay();
  display.setTextSize(1);
  if (!rtc.begin()) {
    Serial.println("RTC GAGAL!!");
    display.getTextBounds(F("RTC GAGAL!!"), 0, 0, &ox, &oy, &ow, &oh);
    display.setCursor((128 - ow) / 2, 17);
    display.print(F("RTC GAGAL!!"));
    display.display();
    while (true)
      ;
  }
  Serial.println("RTC AMAN");
  display.getTextBounds(F("RTC AMAN"), 0, 0, &ox, &oy, &ow, &oh);
  display.setCursor((128 - ow) / 2, 17);
  display.print(F("RTC AMAN"));
  display.display();
  delay(2000);
}
