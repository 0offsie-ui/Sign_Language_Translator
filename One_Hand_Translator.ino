#include <SoftwareSerial.h>
// For WiFi connectivity, include necessary libraries if hardware supports HTTP requests.
// e.g. #include <ESP8266WiFi.h> and #include <ESP8266HTTPClient.h>

SoftwareSerial bt(2,3); // (Rx,Tx)

// Global structure for calibration (to be filled from backend)
// (Define appropriate structs or global variables as needed)
struct Calibration {
  int sensorMin1, sensorMax1;
  int sensorMin2, sensorMax2;
  int sensorMin3, sensorMax3;
  int sensorMin4, sensorMax4;
  int sensorMin5, sensorMax5;
};

Calibration calib = {745,815,740,840,715,820,760,870,740,835};

//Green and black thread for thumb //
int FLEX_PIN1 = A0;
int flexADC1 = 0;

//Red and brown thread for the index finger //
int FLEX_PIN2 = A1;
int flexADC2 = 0;

//Red and green string for the middle //
int FLEX_PIN3 = A2;
int flexADC3 = 0;

//Yellow and brown thread for the ring finger //
int FLEX_PIN4 = A3;
int flexADC4 = 0;

//Green and blue thread for the pinky //
int FLEX_PIN5 = A4;
int flexADC5 = 0;
int xpin = A5;
int xadc = 0;
int ypin = A6;
int yadc = 0;
char letter = '';

void setup() {
  Serial.begin(1200);
  bt.begin(9600);

  // Optionally, fetch calibration from backend here:
  // getConfigFromBackend();

  float flexADC1 = analogRead(FLEX_PIN1);
  if(flexADC1<calib.sensorMin1){calib.sensorMin1=flexADC1;}
  if(flexADC1>calib.sensorMax1){calib.sensorMax1=flexADC1;}

  float flexADC2 = analogRead(FLEX_PIN2);
  if(flexADC2<calib.sensorMin2){calib.sensorMin2=flexADC2;}
  if(flexADC2>calib.sensorMax2){calib.sensorMax2=flexADC2;}

  float flexADC3 = analogRead(FLEX_PIN3);
  if(flexADC3<calib.sensorMin3){calib.sensorMin3=flexADC3;}
  if(flexADC3>calib.sensorMax3){calib.sensorMax3=flexADC3;}

  float flexADC4 = analogRead(FLEX_PIN4);
  if(flexADC4<calib.sensorMin4){calib.sensorMin4=flexADC4;}
  if(flexADC4>calib.sensorMax4){calib.sensorMax4=flexADC4;}

  float flexADC5 = analogRead(FLEX_PIN5);
  if(flexADC5<calib.sensorMin5){calib.sensorMin5=flexADC5;}
  if(flexADC5>calib.sensorMax5){calib.sensorMax5=flexADC5;}
}

void loop() {
  // Read all flex sensor values and any additional data (e.g. x, y)
  float angle1 = map(constrain(analogRead(A0), 745,815), 745,815, 0, 90);
  float angle2 = map(constrain(analogRead(A1), 740,840), 740,840, 0, 90);
  float angle3 = map(constrain(analogRead(A2), 715,820), 715,820, 0, 90);
  float angle4 = map(constrain(analogRead(A3), 760,870), 760,870, 0, 90);
  float angle5 = map(constrain(analogRead(A4), 740,835), 740,835, 0, 90);
  int x = analogRead(A5);
  int y = analogRead(A6);

  // Instead of mapping conditions locally, send raw angles to backend server
  // Example (pseudocode): sendDataToBackend(angle1, angle2, angle3, angle4, angle5, x, y);
  
  // ...existing code to send data (actual HTTP code depends on WiFi module & libraries)...
  // For demonstration, we simulate sending using serial output:
  Serial.print("Sending flex data: ");
  Serial.print(angle1); Serial.print(", ");
  Serial.print(angle2); Serial.print(", ");
  Serial.print(angle3); Serial.print(", ");
  Serial.print(angle4); Serial.print(", ");
  Serial.print(angle5); Serial.print(" | ");
  Serial.print("x:"); Serial.print(x); Serial.print(", y:"); Serial.println(y);

  // Wait before next reading
  delay(1000);
}

// Example function to retrieve configuration from backend
// (Requires WiFi connectivity; additional hardware and libraries may be needed.)
/*
void getConfigFromBackend() {
  WiFi.begin("SSID", "PASSWORD");
  while(WiFi.status() != WL_CONNECTED) { delay(500); }
  HTTPClient http;
  http.begin("http://<SERVER_IP>:3000/config");
  int httpCode = http.GET();
  if(httpCode == 200) {
    String payload = http.getString();
    // Parse JSON and update 'calib' and mapping variables
    // (Parsing can be implemented using ArduinoJson library)
  }
  http.end();
}
*/
