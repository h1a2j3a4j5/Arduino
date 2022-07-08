
#define ledRed D7
#define ledGreen D6
#define Vrx   A0
void setup() {
  pinMode(ledRed , OUTPUT);
  pinMode(ledGreen ,OUTPUT);
  Serial.begin(9600);
}
bool check = false;
void loop(){ 
   int x =  analogRead(Vrx);
//     int redValue =  map(x , 550 , 1024 ,0 , 255);
//   // analogWrite(ledRed , 25);
//   // delay(1000);
//   // digitalWrite(ledRed , HIGH);
// //   delay(1000);
// 
//    analogWrite(ledRed , x /4);
//    analogWrite(ledGreen , x /4);

  
   
    if (x > 600){
      int redValue =  map(x , 550 , 1024 ,0 , 255);
         analogWrite(ledRed , redValue);
         digitalWrite(ledGreen , LOW);
         
   }else if (x < 400){
        int greenValue = map(x , 450 , 0 , 0 ,255);
        analogWrite(ledGreen , greenValue);
        digitalWrite(ledRed , LOW);
    }else{
        digitalWrite(ledGreen , LOW);
        digitalWrite(ledRed , LOW);
   } 

//
//    if( x > 600 ){
//      int redValue =  map(x , 550 , 1024 ,0 , 255);
//      analogWrite(ledRed , redValue);
//      delay(150);
//      digitalWrite(ledRed , LOW);
//      delay(150);
//      check = true;
//    }
//    if( x > 450 && x < 600 && check ){
//      digitalWrite(ledRed , HIGH);
//      delay(150);
//      digitalWrite(ledRed , LOW);
//      delay(150);
//    }

//       if (x > 600){
//          int redValue =  map(x , 550 , 1024 ,0 , 255);
//          analogWrite(ledRed , redValue);   
//          digitalWrite(ledGreen , HIGH);
//          delay(100);
//          digitalWrite(ledGreen , LOW);
//          delay(100);
//          check = true;
//        }       
//       if( x > 450 && x < 600 && check ){
//           digitalWrite(ledRed , LOW); 
//           digitalWrite(ledGreen , HIGH);
//           delay(100);
//           digitalWrite(ledGreen , LOW);
//           delay(100);
//         }  
//         if ( x < 450 ){
//              digitalWrite(ledGreen , LOW);
//              check = false; 
//           }
//
//     Serial.println(x);
   }
