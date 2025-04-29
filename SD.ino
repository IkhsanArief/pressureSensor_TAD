
// void generateFileName() {
//   do {
//     snprintf(fileName, sizeof(fileName), "data_tekanan_air_%02d.txt", fileNumber);
//     fileNumber++;
//   } while (sd.exists(fileName));
// }

void generateFileName() {
  while (true) {
    snprintf(fileName, sizeof(fileName), "data_tekanan_air_%02d.txt", fileNumber);
    if (!sd.exists(fileName)) {
      break;
    }
    fileNumber++;
  }
}

void initSD() {
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 0);
  if (!sd.begin(chipSelect, SD_SCK_MHZ(50))) {
    Serial.println("MODUL SD GAGAL!!");
    display.getTextBounds(("MODUL SD GAGAL!!"), 0, 0, &ox, &oy, &ow, &oh);
    display.setCursor((128 - ow) / 2, 17);
    display.print(F("MODUL SD GAGAL!!"));
    display.display();
    while (true)
      ;
  }
  Serial.println("MODUL SD AMAN");
  display.getTextBounds(("MODUL SD AMAN"), 0, 0, &ox, &oy, &ow, &oh);
  display.setCursor((128 - ow) / 2, 17);
  display.print(F("MODUL SD AMAN"));
  display.display();
  delay(2000);

  generateFileName();

  display.clearDisplay();
  display.setTextSize(4);
  display.setCursor(55, 18);
  if (!file.open(fileName, O_WRONLY | O_CREAT | O_APPEND)) {
    Serial.println("KARTU SD GAGAL!!");
    display.getTextBounds(F("MODUL SD GAGAL!!"), 0, 0, &ox, &oy, &ow, &oh);
    display.setCursor((128 - ow) / 2, 17);
    display.print(F("KARTU SD GAGAL!!"));
    display.display();
    while (true)
      ;
  }
  Serial.print("Menyimpan data ke file: ");
  Serial.println(fileName);
  display.setCursor(40, 16);
  display.print(fileNumber);
  display.display();
  delay(3000);
  display.clearDisplay();
  display.setTextSize(1);
}

void dataLogging() {
  if (file.open(fileName, O_WRONLY | O_APPEND)) {
    file.print(now.year());
    file.print("/");
    file.print(now.month());
    file.print("/");
    file.print(now.day());
    file.print(" ");
    file.print(now.hour());
    file.print(":");
    file.print(now.minute());
    file.print(":");
    file.print(now.second());
    file.print("||");
    file.print(volt, 2);
    file.print("||");
    file.println(tekanan, 2);
    file.close();
    Serial.println("DATA BERHASIL TERSIMPAN");
    display.fillRect(19, 56, SCREEN_WIDTH, 8, SSD1306_BLACK);
    display.setCursor(19, 56);
    display.print("DATA TERSIMPAN");
  } else {
    Serial.println("DATA GAGAL TERSIMPAN!!");
    display.fillRect(10, 56, SCREEN_WIDTH, 8, SSD1306_BLACK);
    display.setCursor(10, 56);
    display.print("GAGAL SIMPAN DATA");
  }
}