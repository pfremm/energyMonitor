
// EmonLibrary examples openenergymonitor.org, Licence GNU GPL V3

#include "EmonLib.h"             // Include Emon Library

#define VOLT_CAL 123.7
#define CURRENT_CAL 53.2

EnergyMonitor emon1;             // Create an instance

void setup()
{  
  Serial.begin(9600);
  
  emon1.voltage(1, VOLT_CAL, 1.7);  // Voltage: input pin, calibration, phase_shift
  emon1.current(0, CURRENT_CAL);       // Current: input pin, calibration.  
}

void loop()
{
  emon1.calcVI(20,2000);         // Calculate all. No.of half wavelengths (crossings), time-out
  
  float supplyVoltage   = emon1.Vrms;             //extract Vrms into Variable
  float currentDraw            = emon1.Irms;             //extract Irms into Variable
  Serial.print("Voltage: ");
  Serial.println(supplyVoltage);
  
  Serial.print("Current: ");
  Serial.println(currentDraw);

  Serial.print("Watts: ");
  Serial.println(currentDraw * supplyVoltage);
  Serial.println("\n\n");
 }

