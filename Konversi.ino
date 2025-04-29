void burstSampling() {
  // burst sampling
  burst = 10;
  reads1 = 0;
  reads = 0;
  for (i = 0; i < burst; i++) {
    reads1 = ads.readADC_SingleEnded(0);  //pressure
    //nilai ads sensor #debug
    //    Serial.print(i);
    //    Serial.print("=");
    //    Serial.println(reads1);
    if (reads1 < 0) {
      reads = reads + 0;
    } else {
      reads = reads + reads1;
    }
    delay(10);
  }
}

void konversiTekanan() {
  //KONVERSI
  // volt = ((float)reads / (float)burst) * 0.1875 / 1000.0000; // nilai voltase dari nilai DN
  // volt = volt * 147.00 / 100.00;
  reads = ads.readADC_SingleEnded(tegangan);
  volt = (float)reads * 0.1875 / 1000.0000 * 147.00 / 100.00;  // nilai voltase dari nilai DN
  tekanan = (300.00 * volt - 150.00) * 0.01 + float(offset);
  tekanan = tekanan - 0.42;
  if (tekanan <= 0) tekanan = 0;
}

