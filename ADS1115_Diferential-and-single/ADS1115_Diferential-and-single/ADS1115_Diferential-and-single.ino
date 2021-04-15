#include <Wire.h>
#include <Adafruit_ADS1015.h>

Adafruit_ADS1115 ads(0x48);  // ADC object at I2C address 0x48 for addr pin = GND

int16_t adc0_1, adc0, adc1, adc2, unoA0;  // variables to hold ADC readings
float multiplier = 0.1875F;               // ADS1115  @ +/- 6.144V gain = 0.1875mV/step
float adcScale   = 4.8828F;               // Arduino 10 bit @ 5 volts   = 4.88mV/step

void setup(void)
{
  Serial.begin(9600);
  Serial.println("Comparing ADS1115 external 16 bit ADC with Arduino internal 10 bit ADC");
  Serial.println();
  Serial.println("Getting differential reading from AIN0 (P) - AIN1 (N)");
  Serial.println("Getting single-ended reading from AIN2");
  Serial.println("Getting single-ended reading from Arduino A0");
  Serial.println();
  Serial.println();

  // The ADC input range (or gain) can be changed via the following
  // functions, but be careful never to exceed VDD +0.3V max, or to
  // exceed the upper and lower limits if you adjust the input range!
  // Setting these values incorrectly may destroy your ADC!
  //                                                                ADS1115
  //                                                                -------
  // ads.setGain(GAIN_TWOTHIRDS);  // 2/3x gain +/- 6.144V  1 bit = 0.1875mV (default)
  // ads.setGain(GAIN_ONE);        // 1x gain   +/- 4.096V  1 bit = 0.125mV
  // ads.setGain(GAIN_TWO);        // 2x gain   +/- 2.048V  1 bit = 0.0625mV
  // ads.setGain(GAIN_FOUR);       // 4x gain   +/- 1.024V  1 bit = 0.03125mV
  // ads.setGain(GAIN_EIGHT);      // 8x gain   +/- 0.512V  1 bit = 0.015625mV
  // ads.setGain(GAIN_SIXTEEN);    // 16x gain  +/- 0.256V  1 bit = 0.0078125mV

  ads.begin();  // init ADS1115 ADC
}

void loop(void) {

  // read in analog inputs
  adc0_1 = ads.readADC_Differential_0_1();  // read differential AIN0 - AIN1
  adc0 = ads.readADC_SingleEnded(0);        // read single AIN0
  adc1 = ads.readADC_SingleEnded(1);        // read single AIN1
  adc2 = ads.readADC_SingleEnded(2);        // read single AIN2
  unoA0 = analogRead(A0);                   // read Arduino single A0

  Serial.println("ADS1115 Differential AIN0-AIN1        ADS1115 AIN2      Arduino 10-bit");
  Serial.println("----------------------------------------------------------------------");
  Serial.print("             ");
  Serial.print(adc0_1 * multiplier); Serial.print("mV                     ");
  Serial.print(adc2 * multiplier); Serial.print("mV          ");
  Serial.print(unoA0 * adcScale); Serial.println("mV");

  Serial.print("A0: ");
  Serial.print(adc0 * multiplier); Serial.print("mV   ");
  Serial.print("A1: ");
  Serial.print(adc1 * multiplier); Serial.print("mV ");

  Serial.println();
  Serial.println();
  Serial.println();
  Serial.println();
  delay(2000);

}
