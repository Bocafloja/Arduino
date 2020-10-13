int VelocidadMotor1 = 10; // ENA - PWM
int VelocidadMotor2 = 6; // ENB
int Motor1A = 11; // IN2
int Motor1B = 2; // IN1
int Motor2C = 3; // IN4
int Motor2D = 5; // IN3
int infraPin = 7; // izquierdo - pin del infrarrojos utilizado como entrada digital
int infraPin1=8; // derecho
int valorInfra = 0; // Valor inicial de la lectura digital del infrarrojos
int valorInfra1 = 0;

void setup() {
  
  pinMode(infraPin, INPUT);
  pinMode(infraPin1, INPUT);
  pinMode(Motor1A, OUTPUT);
  pinMode(Motor1B, OUTPUT);
  pinMode(Motor2C, OUTPUT);
  pinMode(Motor2D, OUTPUT);
  pinMode(VelocidadMotor1, OUTPUT);
  pinMode(VelocidadMotor2, OUTPUT);
  analogWrite(VelocidadMotor1, 60); //motor izquierdo PWM
  analogWrite(VelocidadMotor2, 60); //motor derecho PWM
  digitalWrite(Motor1A, LOW);
  digitalWrite(Motor1B, LOW);
  digitalWrite(Motor2C, LOW);
  digitalWrite(Motor2D, LOW);
  
}
void loop() {
  
  valorInfra = digitalRead(infraPin); // valor entrada que lee el infrarrojo izquierdo
  valorInfra1 = digitalRead(infraPin1); // valor entrada que lee el infrarrojo derecho
  
// Lectura de los sensores 0 = blanco
//                         1 = negro

  if(valorInfra == 0 && valorInfra1 == 0){ // hacia delante
    digitalWrite(Motor1B, HIGH);
    digitalWrite(Motor2D, HIGH);
    digitalWrite(Motor1A, LOW);
    digitalWrite(Motor2C, LOW);
    delay(20);

  }
  
  if(valorInfra == 0 && valorInfra1 == 1){ // Gira hacia la derecha
    digitalWrite(Motor1A, LOW);
    digitalWrite(Motor2D,LOW);
    delay(25);
    digitalWrite(Motor1A, HIGH);
    digitalWrite(Motor2D,LOW);
    delay(20);
  }
  
  if(valorInfra == 1 && valorInfra1 == 0){ // Gira hacia la izquierda
    digitalWrite(Motor1A,LOW);
    digitalWrite(Motor2D, LOW);
    delay(25);
    digitalWrite(Motor1A,LOW);
    digitalWrite(Motor2D, HIGH);
    delay(20);
  }
  
  if(valorInfra == 1 && valorInfra1 == 1){ // STOP
    digitalWrite(Motor1A, LOW);
    digitalWrite(Motor1B, LOW);
    digitalWrite(Motor2C, LOW);
    digitalWrite(Motor2D, LOW);
  }
}

