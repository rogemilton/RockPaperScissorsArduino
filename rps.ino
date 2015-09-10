
//Roger Milton


#include <Servo.h>

Servo serv[4];
int user_present = 0;
int pos[4];
int counter = 0;
int makeMove = 0;
int cereal = 8;
int reset_pin = 12;
/*
0 = rock
1 = paper
2 = scissors
*/
void setup()
{
    Serial.begin(9600);
     for(int i=0; i<4; ++i)
     {
          serv[i].attach(9-i);
          pos[i] = 0;
     }
     pinMode(13,OUTPUT);
     pinMode(12,OUTPUT);
     pinMode(11,OUTPUT);
     
      user_present = 1;
      serv[1].write(0);
      serv[2].write(90);
      serv[3].write(90);
}

void loop()
{
  
  
     if(Serial.available() > 0)
     {
                     cereal = Serial.read();
                     Serial.print("...-");
     
          cereal -= 48;
           Serial.print(cereal);
          if(cereal == 9)
          {
           digitalWrite(13, HIGH); 
           digitalWrite(12,LOW);
           digitalWrite(11,LOW);
           Scissors();
          }
          if(cereal ==8)
          {
           digitalWrite(12,HIGH); 
           digitalWrite(13,LOW);
           digitalWrite(11,LOW);
           Scissors();
          }
          if(cereal == 7)
          {
           digitalWrite(11,HIGH); 
           digitalWrite(12,LOW);
           digitalWrite(13,LOW);
          }
        if(user_present == 1)
        {              
           int a = random(0,2);
           Serial.write(a);
              if(makeMove == 0)
              {
                //paper = -40 for now
                if(Shake() == 1)
               {
                 if(cereal == -40)
                 {
                    Paper();
                 }
                 else if(cereal == -41)
                 {
                  Rock(); 
                 }
                 else
                 {
                  Scissors(); 
                 }
               } 
              } 
        }
     } 
}

void Rock()
{
     //do nothing 'cause it's rock!
      serv[2].write(90);
     serv[3].write(90);
     //serv[1].write(0);
    
     makeMove = 1;
}

void Paper()
{
     /*
     1 = 0
     2 = 0
     3 = 90
     4 = 90
     */
      for(pos[1] = 0; pos[1] > 90; pos[1] += 3)
     {                
         serv[1].write(pos[1]); 
         delay(15);                     
      } 
      serv[1].write(90);
      serv[2].write(90);
      serv[3].write(90);
      
     for(pos[3] = 0; pos[3] < 90; pos[3] += 3)
      {                
             serv[3].write(pos[3]); 
             delay(15);                     
       } 
    
      makeMove = 1;
}

void Scissors()
{
     /*
     1 = 0
     2 = 90
     3 = 180
     4 = 0
     */
     
      for(pos[1] = 0; pos[1] > 90; pos[1] += 3)
     {                
             serv[1].write(pos[1]); 
             delay(15);                     
      } 
      serv[1].write(90);
     //serv[2].write(90);
     //serv[3].write(90);
      for(pos[3] = 90; pos[3] > 60; pos[3] -= 3)
     {                
             serv[3].write(pos[3]); 
             delay(15);                     
      } 
       for(pos[2] = 90; pos[2] < 120; pos[2] += 3)
     {                
             serv[2].write(pos[2]); 
             delay(15);                     
      } 
      makeMove = 1;
}

int Shake()
{
            while(counter < 3)
            {
                   for(pos[0] = 0; pos[0] < 90; pos[0] += 3)
                   {                
                         serv[0].write(pos[0]); 
                         delay(15);                     
                    } 
                    for(pos[0] = 90; pos[0]>=1; pos[0] -= 3)    
                    {    
                         serv[0].write(pos[0]); 
                         delay(15);  
                    } 
                    counter ++;
            }
            
            
             return 1;
            
}
