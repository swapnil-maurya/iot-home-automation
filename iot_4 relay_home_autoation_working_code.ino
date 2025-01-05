// 4 Relay home automation using blynk iot plateform working code

#define BLYNK_TEMPLATE_ID           "TMPL3x6Y_eJHn"
#define BLYNK_TEMPLATE_NAME         "Quickstart Template"
#define BLYNK_AUTH_TOKEN            "mRZUIz-HjCJaFYbG68vnVjlt08Xnaa51"
#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "vivo T1x";
char pass[] = "123456789";

BLYNK_WRITE(V0) {
  digitalWrite(D0, param.asInt());
}

BLYNK_WRITE(V1) {
  digitalWrite(D1, param.asInt());
}

BLYNK_WRITE(V2) {
  digitalWrite(D2, param.asInt());
}

BLYNK_WRITE(V3) {
  digitalWrite(D3, param.asInt());
}

void setup() {
  Serial.begin(115200);
  pinMode(D0, OUTPUT);
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
  digitalWrite(D0, LOW);
  digitalWrite(D1, LOW);
  digitalWrite(D2, LOW);
  digitalWrite(D3, LOW);

  Serial.println("Connecting to WiFi...");
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);

  // Wait until the device is connected to WiFi
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("Connected to WiFi");
  } else {
    Serial.println("Failed to connect to WiFi");
  }
}

void loop() {
  Blynk.run();
}
