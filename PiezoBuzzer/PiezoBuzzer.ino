
#include "HeepDeviceDefinitions.h"

#define FREQUENCY_PIN 14

void InitializeControlHardware(){
  pinMode(FREQUENCY_PIN,OUTPUT);
}

int WriteFrequency(){
  int currentSetting = GetControlValueByName("Frequency");
  if(currentSetting == 0) noTone(FREQUENCY_PIN);
  else tone(FREQUENCY_PIN,map(currentSetting,1,100,1000,4400));
  return currentSetting;
}

void setup()
{

  Serial.begin(115200);
  InitializeControlHardware();
  AddRangeControl("Frequency",HEEP_INPUT,100,0,0);
  StartHeep("PiezoBuzzer", 5);

}

void loop()
{
  PerformHeepTasks();
  WriteFrequency();

}