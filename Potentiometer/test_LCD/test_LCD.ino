#include <LiquidCrystal.h>   // LCDのライブラリを使う

LiquidCrystal lcd( 8, 9, 10, 11, 12, 13 ); // LiquidCrystal型の変数を生成、使うピンの設定をしている
const int INPUT_PIN = A0;    // 入力ピンをA0に固定
const int LED_PIN = 10;      // 入力ピンをA0に固定
int VOLUME;                  // 変数を整数型で宣言
 
void setup(){
  Serial.begin(9600);  // シリアル通信の開始
  lcd.begin(16, 2);            // ディスプレイの列数と行数を設定, (列, 行)
  lcd.clear();                 // LCDをクリアする
  lcd.setCursor(0, 0);         // カーソルの位置を(列, 行)に合わせる
}
 
 
void loop(){
 
  VOLUME = analogRead(INPUT_PIN);  // アナログ値の読み取り
  Serial.print("VOLUME: ");        // シリアルモニタに出力
  Serial.println(VOLUME);

  String str = "VOLUME: " + String(VOLUME);
  lcd.clear();                 // LCDをクリアする
  lcd.setCursor(0, 0);         // カーソルの位置を(列, 行)に合わせる
  lcd.print(str);
  delay(50);
 
}
