#define F_CPU 16000000UL
#include <avr/io.h>
void setupADC() {
  //ADC Control and Status Register
  ADCSRA |= (1<<7) | (1<<5) | (1<<2) | (1<<1) | 1;

  //sensor 4 setup
  //ADMUX |= (1<<7) | (1<<6) | (1<<5) | (1<<2) | (1<<1)| (1<<0); //ADC7 works (light on when sensor covered)

  sensor 5 setup
  ADMUX |= (1<<7) | (1<<6) | (1<<5) | (1<<3) | (1<<1)| (1<<0);   //ADC11 not working (light on constantly)

  //ADC Control and Status Register setup
  ADCSRB = 0;

  //Start ADC Conversion
  ADCSRA |= (1<<6);
  
}

int main(){
  //setup LED
  DDRE |= (1<<6);

  //Sensor output variable
  uint8_t sensor_out = 0;
  
  setupADC();
  
  while(1){
    //wait until conversion is complete
    while(~ADCSRA&(1<<4)){}

    //update sensor_out variable
    sensor_out = ADCH;

    if (sensor_out < 200){
      PORTE |= (1<<6);
    }else{
      PORTE &= ~(1<<6);
    }
  }
}
