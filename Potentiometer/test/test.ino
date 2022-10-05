const int INPUT_PIN = A0;    // 入力ピンをA0に固定
const int LED_PIN = 10;    // 入力ピンをA0に固定
int VOLUME;                  // 変数を整数型で宣言
int brightness;
 
void setup(){
  Serial.begin(9600);  // シリアル通信の開始
}
 
 
void loop(){
 
  VOLUME = analogRead(INPUT_PIN);  // アナログ値の読み取り
  brightness = map(VOLUME,0,1023,0,255);
  Serial.print("brightness: ");        // シリアルモニタに出力
  Serial.println(brightness);
  analogWrite(LED_PIN, brightness);
  delay(10);
 
}
