#include "stm32f10x.h"                  // Device header
#include "beep.h"
#include "Delay.h"
#include "lightsensor.h" 
int main()
{		Beep_();
	lightsensor_init();
		
			while(1)
			{			if (lightsensor_read()==0) Beep_on();
				if (lightsensor_read()==1) Beep_off();
	
		

}
			}

