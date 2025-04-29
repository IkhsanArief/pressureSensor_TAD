


void initOLED() {
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("OLED gagal"));
    while (true)
      ;
  }
  display.setTextColor(SSD1306_WHITE);
  display.display();
  delay(2000);
}

void oledSetup() {
  display.setCursor(0, 17);  display.print(F("Tegangan"));
  display.setCursor(0, 30);  display.print(F("Tekanan"));
  display.setCursor(55, 17);  display.print(F("="));
  display.setCursor(55, 30);  display.print(F("="));
  display.setCursor(95, 17);  display.print(F("V"));
  display.setCursor(95, 30);  display.print(F("Bar"));
}

void tampilkanOLED() {
  display.fillRect(0, 0, 128, 10, SSD1306_BLACK);   // Hapus parameter waktu pada OLED
  display.fillRect(70, 16, 58, 28, SSD1306_BLACK);  // Hapus nilai tegangan dan tekanan pada OLED

  display.setCursor(0, 0);
  display.printf("%04d/%02d/%02d %02d:%02d:%02d", now.year(), now.month(), now.day(), now.hour(), now.minute(), now.second());

  display.setCursor(70, 16);
  display.print(volt, 2);
  display.print(" V");

  display.setCursor(70, 32);
  display.print(tekanan, 2);
  display.print(" Bar");

  display.display();
}