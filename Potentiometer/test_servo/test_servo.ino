#include <Servo.h>
 
Servo myservo;            //Servoオブジェクトの宣言 
const int INPUT_PIN = A0; // 入力ピンをA0に固定
int VOLUME;               // 変数を整数型で宣言
int angle;
 
void setup(){
 
  Serial.begin(9600);  // シリアル通信の開始
  myservo.attach(9);   //servo変数をピンに割り当てる、ここでは9番ピン
  myservo.write(90);   //角度を指定、ここでは90度
}
 
 
void loop(){
 
  VOLUME = analogRead(INPUT_PIN);  // アナログ値の読み取り
  angle = map(VOLUME,0,1023,0,180);
  myservo.write(angle);
  Serial.print("angle: ");         // シリアルモニタに出力
  Serial.println(angle);
 
  delay(10);
 
}
