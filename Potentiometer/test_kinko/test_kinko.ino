#include <LiquidCrystal.h> // LCDのライブラリを使う

LiquidCrystal lcd( 5, 6, 9, 10, 11, 12 ); // LiquidCrystal型の変数を生成、使うピンの設定をしている
const int INPUT_PIN = A0; // 入力ピンをA0にする
const int BUTTON_PIN = 4; // 入力ピンをA0にする
float volume;             // 読み取った電圧の大きさを格納する変数
int place = 0;            // 操作する数字の桁数
int buttonValue;          // ボタンの状態を格納する変数
String nums = "000";      // 入力している文字列
String ans = "528";       // パスワード
 
void setup(){
  Serial.begin(9600);     // シリアル通信の開始
  lcd.begin(16, 2);       // ディスプレイの列数と行数を設定, (列, 行)
  lcd.clear();            // LCDをクリアする
  lcd.setCursor(0, 0);    // カーソルの位置を(列, 行)に合わせる
  pinMode( BUTTON_PIN, INPUT_PULLUP ); // ボタンピンの設定
}
 
 
void loop(){
 
  volume = analogRead(INPUT_PIN);        // 電圧の読み取り, 値は0~1023の大きさ
  volume = map(volume, 1023, 0, 9, 0);   // volumeが0~になるように変換
  String temp = String(volume);
  nums[place] = temp[0];

  buttonValue = digitalRead(BUTTON_PIN); // ボタンの状態を取得 

  // もし、ボタンが押された かつ numsのplace番目とansのplace番目が等しいならplaceを1増やす
  // → つまり入力している桁の数字が正解なら次の桁に進む
  if(buttonValue == LOW && nums[place] == ans[place])
  {
    place++;
  }

  lcd.clear();         // LCDをクリアする
  lcd.setCursor(0, 0); // カーソルの位置を(列, 行)に合わせる
  if(place >= 3)
  {
    lcd.print("OPEN");     // OPENを表示する
  }
  else
  {
    lcd.print("password: " + nums);     // numsを表示する
  }

  delay(100);
 
}
