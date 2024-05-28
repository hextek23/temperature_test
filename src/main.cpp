#include <Arduino.h>
#include <dht.h>

#define DHTPIN 2     // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11   // DHT 11


// Connect pin 1 (on the left) of the sensor to +5V
// NOTE: If using a board with 3.3V logic like an Arduino Due connect pin 1
// to 3.3V instead of 5V!
// Connect pin 2 of the sensor to whatever your DHTPIN is
// Connect pin 3 (on the right) of the sensor to GROUND (if your sensor has 3 pins)
// Connect pin 4 (on the right) of the sensor to GROUND and leave the pin 3 EMPTY (if your sensor has 4 pins)
// Connect a 10K resistor from pin 2 (data) to pin 1 (power) of the sensor

DHT dht(DHTPIN, DHTTYPE);
 
void setup(){
 
  Serial.begin(9600);
  delay(500);//Delay to let system boot
  Serial.println("DHT11 Humidity & temperature Sensor\n\n");
  delay(1000);//Wait before accessing Sensor
  dht.begin();
 
}
 
void loop(){
    // Door deze instructies worden zowel de vochtigheidsgraad als temperatuur naar de Serial Monittor gestuurd
    Serial.print("Current humidity = ");
    Serial.print(dht.readHumidity());
    Serial.print("%  ");
    Serial.print("temperature = ");
    Serial.print(dht.readTemperature()); 
    Serial.println("°C  ");
    
    delay(5000);// Hier wordt een delay van 5s seconden geplaatst. Het snelste dat de waarde van de temperatuur en vochtigheid kan veranderen is ongeveer 2s
 
}