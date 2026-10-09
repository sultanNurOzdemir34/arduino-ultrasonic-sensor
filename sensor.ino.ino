// HC-SR04 Ultrasonik Sensör ile Engel Mesafe Ölçümü
const int trigPin = 9;
const int echoPin = 10;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600); // Seri haberleşme başlatılır
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // 10 mikrosaniyelik tetikleme sinyali gönderilir
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Ses dalgasının gidiş süresi ölçülür
  long duration = pulseIn(echoPin, HIGH);
  
  // Süre mesafeye çevrilir (cm cinsinden)
  int distance = duration * 0.034 / 2;
  
  Serial.print("Mesafe: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  // 15 cm'den yakınsa uyarı verir
  if (distance < 15 && distance > 0) {
    Serial.println("DİKKAT: Engel Algılandı!");
  }
  
  delay(500);
}
