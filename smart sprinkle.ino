// smart_sprinkler.ino

const int relayPin = 27;               // ขาเชื่อม Relay
const int moistureThreshold = 400;     // เกณฑ์ค่าความชื้น (ยิ่งต่ำยิ่งแห้ง)

void setup() {
  Serial.begin(115200);
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, LOW); // เริ่มต้นปิดน้ำ
  Serial.println("🌱 ระบบรดน้ำต้นไม้เริ่มทำงานแล้ว...");
}

void loop() {
  // จำลองค่าความชื้นระหว่าง 300-800 แทน sensor จริง
  int moistureValue = random(300, 800);

  // แสดงค่าความชื้น
  Serial.print("💧 ค่าความชื้น: ");
  Serial.println(moistureValue);

  // ตัดสินใจว่าจะรดน้ำหรือไม่
  if (moistureValue < moistureThreshold) {
    Serial.println("🌵 ดินแห้ง! กำลังรดน้ำ...");
    digitalWrite(relayPin, HIGH); // เปิดน้ำ
  } else {
    Serial.println("🌴 ดินชุ่ม! ยังไม่ต้องรดน้ำ");
    digitalWrite(relayPin, LOW); // ปิดน้ำ
  }

  delay(5000); // รอ 5 วิแล้วตรวจอีกครั้ง
}