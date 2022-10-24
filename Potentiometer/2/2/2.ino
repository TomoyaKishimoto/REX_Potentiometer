const int INPUT_PIN = A0; // 入力ピンをA0にする
const int LED_PIN = 9;    // LEDのピン番号を9にする
float volume;             // 読み取った電圧の大きさを格納する変数
 
void setup(){
  Serial.begin(9600);     // シリアル通信の開始
}
 
void loop(){
  volume = analogRead(INPUT_PIN); // 電圧の読み取り, 値は0~1023の大きさ
  volume = (volume / 1023) * 5;   // volumeが0~5[V]になるように変換

  // シリアルモニタに出力, volumeはfloat型からString型へ変換
  Serial.println("VOLUME: " + String(volume) + "[V]");

  analogWrite(LED_PIN, volume);   // LEDをvolumeの大きさで点灯する

  delay(100);                     // 100ms待機
}