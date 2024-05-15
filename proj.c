#include <lpc21xx.h>

int adc(int adch);

void delay(unsigned int count);
void pwm_init(void)
{
PINSEL0=0x0002800A;
	PWMPCR=0X1C00;
	PWMMR0=350;
	PWMTCR=0X09;
	PWMMCR=0X02;
}

int adc(int adch){
  PINSEL1= 0x05400000;
int adc_val,temp;
	if (adch==1){
	 ADCR= 0x01200001;}
	else if(adch==2){
	 ADCR= 0x01200002;
	}
	else if(adch==3){
	 ADCR= 0x01200004;
	}
	 while(!(temp=ADDR) &0x80000000);
	 adc_val= (temp >> 6)&0x000003FF;
	 int valtr=( (adc_val) / (1024) ) * (350)
	 if (valtr>290)valtr=290;
	 if (valtr<0)valtr=0;
	 return valtr;
}
 

 int main(){
	 pwm_init();
while(1){
//start convertion
	PWMMR2=adc(1);
	PWMMR3=adc(2);
	PWMMR4=adc(3);
	PWMLER=0X1E;
	
}
}
 

void delay(unsigned int count) {
    unsigned int i;
    for (i = 0; i < count; i++);
}
