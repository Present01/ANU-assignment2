void setup() {
  Serial.begin(9600);
}
void loop() {
  if (Serial.available() > 0) {
    String m = Serial.readString();
    if (m.indexOf("die") == 0) {
      //벽에 걸렸을때
      //𝐁𝐚𝐜𝐡 - 𝐓𝐨𝐜𝐜𝐚𝐭𝐚 𝐚𝐧𝐝 𝐅𝐮𝐠𝐮𝐞 𝐢𝐧 𝐃 𝐦𝐢𝐧𝐨𝐫 𝐁𝐖𝐕 𝟓𝟔𝟓
      tone(4, 880, 100);
      delay(125);
      tone(4, 784, 100);
      delay(125);
      tone(4, 880, 350);
      delay(500);

      tone(4, 784, 100);
      delay(125);
      tone(4, 698, 100);
      delay(125);
      tone(4, 659, 100);
      delay(125);
      tone(4, 587, 100);
      delay(125);
      tone(4, 554, 225);
      delay(250);
      tone(4, 587, 225);
      delay(250);
    }
    if (m.indexOf("goal") == 0) {
      //축하
      //𝐌𝐨𝐳𝐚𝐫𝐭 - 𝐄𝐢𝐧𝐞 𝐊𝐥𝐞𝐢𝐧𝐞 𝐍𝐚𝐜𝐡𝐭𝐦𝐮𝐬𝐢𝐤

      tone(4, 784, 475);
      delay(750);
      tone(4, 523, 225);
      delay(250);
      tone(4, 784, 475);
      delay(750);
      tone(4, 523, 225);
      delay(250);
      tone(4, 784, 225);
      delay(250);
      tone(4, 587, 225);
      delay(250);
      tone(4, 784, 225);
      delay(250);
      tone(4, 987, 225);
      delay(250);
      tone(4, 1175, 475);
      delay(1000);

      tone(4, 1047, 475);
      delay(750);
      tone(4, 880, 225);
      delay(250);
      tone(4, 1047, 475);
      delay(750);
      tone(4, 880, 225);
      delay(250);
      tone(4, 1047, 225);
      delay(250);
      tone(4, 880, 225);
      delay(250);
      tone(4, 740, 225);
      delay(250);
      tone(4, 880, 225);
      delay(250);
      tone(4, 587, 475);
      delay(1000);

      tone(4, 784, 225);
      delay(500);
      tone(4, 784, 725);
      delay(750);
      tone(4, 987, 225);
      delay(250);
      tone(4, 880, 225);
      delay(250);
      tone(4, 784, 225);
      delay(250);
      tone(4, 784, 225);
      delay(250);
      tone(4, 740, 225);
      delay(250);
      tone(4, 740, 725);
      delay(750);

      tone(4, 880, 225);
      delay(250);
      tone(4, 1047, 225);
      delay(250);
      tone(4, 740, 225);
      delay(250);
      tone(4, 880, 225);
      delay(250);
      tone(4, 784, 225);
      delay(250);
      tone(4, 784, 725);
      delay(750);

      tone(4, 987, 225);
      delay(250);
      tone(4, 880, 225);
      delay(250);
      tone(4, 784, 225);
      delay(250);
      tone(4, 784, 225);
      delay(250);
      tone(4, 740, 225);
      delay(250);
      tone(4, 740, 725);
      delay(750);

      tone(4, 880, 225);
      delay(250);
      tone(4, 1047, 225);
      delay(250);
      tone(4, 740, 225);
      delay(250);
      tone(4, 784, 225);
      delay(250);
      tone(4, 784, 225);
      delay(250);
      tone(4, 784, 100);
      delay(125);
      tone(4, 740, 225);
      delay(250);
      tone(4, 659, 100);
      delay(125);
      tone(4, 740, 100);
      delay(125);
      tone(4, 784, 225);
      delay(250);
      tone(4, 784, 225);
      delay(250);
      tone(4, 987, 100);
      delay(125);
      tone(4, 880, 225);
      delay(250);
      tone(4, 784, 100);
      delay(125);
      tone(4, 880, 100);
      delay(125);
      tone(4, 987, 225);
      delay(250);
      tone(4, 987, 225);
      delay(250);
      tone(4, 1175, 100);
      delay(125);
      tone(4, 1047, 225);
      delay(250);
      tone(4, 987, 100);
      delay(125);
      tone(4, 1047, 100);
      delay(125);
      tone(4, 1175, 475);
      delay(500);
    }
  }
}
