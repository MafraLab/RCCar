#include <SoftwareSerial.h>

int bluetoothTx = 2;
int bluetoothRx = 3;
int pinDir1 = 9;
int pinDir2 = 8;

int motor1 = 7;
int motor2 = 6;

SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);

void setup()
{
  //Setup usb serial connection to computer
  Serial.begin(9600);

  //Setup Bluetooth serial connection to android
  bluetooth.begin(115200);
  bluetooth.print("$$$");
  delay(100);
  bluetooth.println("U,9600,N");
  bluetooth.begin(9600);
}

void loop()
{
  //Read from bluetooth and write to usb serial
  if(bluetooth.available())
  {
    String toSend;
    char readln = (char)bluetooth.read();
    if ( readln== '2')
    {
      digitalWrite(motor2, LOW);
      digitalWrite(motor1, HIGH);
      digitalWrite(pinDir1, LOW);
      digitalWrite(pinDir2, LOW);
      toSend = "frente";
      delay(250);
      Para();
    }
    else if (readln == '1')
    {
      digitalWrite(motor2, LOW);
      digitalWrite(motor1, HIGH);
      digitalWrite(pinDir1, HIGH);
      digitalWrite(pinDir2, LOW);
      toSend = "frente + esquerda";
      delay(250);
      Para();
    }
    else if (readln == '3')
    {
      digitalWrite(motor2, LOW);
      digitalWrite(motor1, HIGH);
      digitalWrite(pinDir1, LOW);
      digitalWrite(pinDir2, HIGH);
      toSend = "frente + direita";
      delay(250);
      Para();
    }
    else if (readln == '8')
    {
      digitalWrite(motor2, HIGH);
      digitalWrite(motor1, LOW);
      toSend = "tras";
      delay(250);
      Para();
    }
    else if (readln == '9')
    {
      digitalWrite(motor2, HIGH);
      digitalWrite(motor1, LOW);
      digitalWrite(pinDir1, LOW);
      digitalWrite(pinDir2, HIGH);
      toSend = "tras + direita";
      delay(250);
      Para();
    }
    else if (readln == '7calma')
    {
      digitalWrite(motor2, HIGH);
      digitalWrite(motor1, LOW);
      digitalWrite(pinDir1, HIGH);
      digitalWrite(pinDir2, LOW);
      toSend = "tras + esquerda";
      delay(250);
      Para();
    }
    else
    {
      digitalWrite(motor2, HIGH);
      digitalWrite(motor1, HIGH);
      delay(500);
      digitalWrite(motor2, LOW);
      digitalWrite(motor1, LOW);
      digitalWrite(pinDir1, LOW);
      digitalWrite(pinDir2, LOW);
    }
    Serial.println(toSend);
  }

  //Read from usb serial to bluetooth
  if(Serial.available())
  {
    char toSend = (char)Serial.read();
    bluetooth.print(toSend);
  }
}

void Para()
{
      digitalWrite(motor2, LOW);
      digitalWrite(motor1, LOW);
      digitalWrite(pinDir1, LOW);
      digitalWrite(pinDir2, LOW);
}
