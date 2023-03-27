# 1 "c:\\Users\\bruno\\OneDrive\\Desktop\\prototipoECLIPSE\\protoECLIPSE.ino"
/*

  Example of BH1750 library usage. This example initialises the BH1750 object using the default high resolution continuous mode and then makes a light level reading every second.

*/
# 5 "c:\\Users\\bruno\\OneDrive\\Desktop\\prototipoECLIPSE\\protoECLIPSE.ino"
# 6 "c:\\Users\\bruno\\OneDrive\\Desktop\\prototipoECLIPSE\\protoECLIPSE.ino" 2
# 7 "c:\\Users\\bruno\\OneDrive\\Desktop\\prototipoECLIPSE\\protoECLIPSE.ino" 2
# 8 "c:\\Users\\bruno\\OneDrive\\Desktop\\prototipoECLIPSE\\protoECLIPSE.ino" 2
hw_timer_t *My_timer = 
# 8 "c:\\Users\\bruno\\OneDrive\\Desktop\\prototipoECLIPSE\\protoECLIPSE.ino" 3 4
                      __null
# 8 "c:\\Users\\bruno\\OneDrive\\Desktop\\prototipoECLIPSE\\protoECLIPSE.ino"
                          ;
portMUX_TYPE mux = { .owner = 0xB33FFFFF, .count = 0, };


BH1750 lightMeter;
uint32_t f = 400;
uint32_t M = f*(pow(2,32))/100000;
float lux;
int modulator = 9;
volatile bool flag = false;

//contadores
uint32_t acumuladorFASE = 0x00000000;
uint8_t addressPOINTER = 0x00;

//escribir la ISR del DSS----------------------------
void __attribute__((section(".iram1" "." "16"))) onTimer(){
acumuladorFASE = acumuladorFASE + M;
addressPOINTER = acumuladorFASE >> 24; //Shiftear los bits
dacWrite(25, SINE[modulator][addressPOINTER]);
}



void setup(){

My_timer = timerBegin(0, 80, true);
timerAttachInterrupt(My_timer, &onTimer, true);
timerAlarmWrite(My_timer,10, true);
timerAlarmEnable(My_timer);
Serial.begin(9600);
//Iniciarlizar sensor
Wire.begin();
lightMeter.begin();
}

void loop() {
  lux = lightMeter.readLightLevel();
  modulator = map(lux, 0, 5000, 0, 9);
  /*

  Serial.print("Medicion de luz: ");

  Serial.print(lux);

  Serial.print("\n");

  */
# 52 "c:\\Users\\bruno\\OneDrive\\Desktop\\prototipoECLIPSE\\protoECLIPSE.ino"
}
