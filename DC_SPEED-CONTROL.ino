#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 9, 10, 11, 12, 13);
#define motor_RPS_pulse_ip 7
#define motor_PWM_pulse_ip 4
int motor_RPS_Ton,motor_RPS_Toff,PWM_Ton,PWM_Toff,PWM_T;
int PWM_duty,pulse_width=255,RPS,motor_RPS_period,RPM;
float voltage;
   
void setup()
{    
  pinMode(motor_RPS_pulse_ip,INPUT);
  pinMode(motor_PWM_pulse_ip,INPUT);
  lcd.begin(16, 4);
  lcd.clear();
  lcd.print("Pulse Width:");
  lcd.setCursor(0,1);
  lcd.print("PWM Volt:");
  lcd.setCursor(0,2);
  lcd.print("Speed(RPS):");   
  lcd.setCursor(0,3);
  lcd.print("Speed(RPM):");   
}
void loop()
{
   analogWrite(3,pulse_width);  
   PWM_Ton= pulseIn(motor_PWM_pulse_ip,HIGH);
   PWM_Toff=pulseIn(motor_PWM_pulse_ip,LOW); 
   delay(2000);    
   PWM_T = PWM_Ton+PWM_Toff;
   PWM_duty = (PWM_Ton/PWM_T)*100;  
   voltage = 0.12*PWM_duty;  
   lcd.setCursor(12,0);
   lcd.print(PWM_duty); 
   lcd.print('%');   
   lcd.setCursor(9,1);
   lcd.print(voltage); 
   lcd.print('V');   
   pulse_width-=15;
   if(pulse_width==90) pulse_width = 255;
   delay(3000);
}
