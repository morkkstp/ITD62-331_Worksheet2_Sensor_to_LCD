#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <LiquidCrystal_I2C.h>

float temperature;
float humidity;
DHT dht11(D4, DHT11);

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  // setup DHT11
  temperature = 0.0;
  humidity = 0.0;
  dht11.begin();

  // setup LiquidCrystal I2C
  lcd.begin();
}

void loop() {
  // put your main code here, to run repeatedly:

  // Get Value on DHT11
  humidity = (dht11.readHumidity());
  temperature = (dht11.readTemperature());

  // Display on Serial Monitor
  Serial.print("Temperature: ");
  Serial.println(temperature);
  Serial.print("Humidity: ");
  Serial.println(humidity);
  delay(1000);

  // Display on LiquidCrystal I2C
  lcd.setCursor(0, 0);
  lcd.print("Temp: " + String(temperature) + " C");
  lcd.setCursor(0, 1);
  lcd.print("Humi: " + String(humidity) + " %");
}
