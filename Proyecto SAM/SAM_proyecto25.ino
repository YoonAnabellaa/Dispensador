#include <Servo.h>

char letra;
Servo servo_6;
Servo servo_5;

void setup()
{
  letra = ' ';
  
  Serial.begin(9600); // Inicia comunicación serial
  servo_6.attach(6);  // Adjunta el servo en el pin 6
  servo_5.attach(5);  // Cambié el pin a 9, puedes usar otro si lo prefieres
  servo_6.write(180); // Establece la posición inicial del servo 6
  servo_5.write(90);  // Establece la posición inicial del servo 5
  delay(2000);        // Pausa de 3 segundos
  Serial.println("Setup completo");
}

void loop()
{
  // Movimiento secuencial predeterminado de los servos
  servo_6.write(180);
  delay(2000);
  servo_6.write(100);
  delay(1000);
  
  // Espera por una letra desde el puerto serial
  while (letra == ' ') {
    if (Serial.available() > 0) {
      letra = Serial.read();
    }
  }

  // Acciones según la letra recibida
  if (letra == 'r') {
    Serial.println("Comando R recibido");
    servo_5.write(135);
    delay(1000);
    servo_6.write(0);
    delay(1000);
  }
  else if (letra == 'a') {
    Serial.println("Comando A recibido");
    servo_5.write(65);
    delay(1000);
    servo_6.write(0);
    delay(1000);
  }
  else if (letra == 'v') {
    Serial.println("Comando V recibido");
    servo_5.write(90);
    delay(1000);
    servo_6.write(0);
    delay(1000);
  }
  
  // Resetea la letra para esperar un nuevo comando
  letra = ' ';
  
  // Movimiento final del servo 6
  servo_6.write(180);
  delay(1000);
}
