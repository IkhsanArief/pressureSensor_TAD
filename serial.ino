void tampilkanSerial() {
  Serial.printf("Waktu: %04d/%02d/%02d %02d:%02d:%02d | Tegangan: %.2f V | Tekanan: %.2f Bar \n",
                now.year(), now.month(), now.day(),
                now.hour(), now.minute(), now.second(),
                volt, tekanan);
}