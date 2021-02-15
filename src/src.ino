/* 
ficheiro sem codigo
para compilar automatico, o programa procura primeiro um
ficheiro com o nome da pasta
podem colocar codigo aqui neste ficheiro e nao alteram o nome
ou deixam o ficheiro sem codigo e podem trabalhar noutros
*/


#include <Servo.h>
int estado_hora1;
int estado_hora2;
int estado_hora3;
int estado_chave;
Servo porta1;
Servo porta2;
Servo porta3;

int echo1 =7;
int trig1 =2;
int echo2 =6;
int trig2 =3;
int echo3 =5;
int trig3 =4;
bool vazio1=false;
bool tamp_aberta1=false;
bool vazio2=false;
bool tamp_aberta2=false;
bool vazio3=false;
bool tamp_aberta3=false;
bool carregado1=false; 
bool carregado2=false;
bool carregado3=false;
int teste=0;
int posicao1=0;

void setup(){
  Serial.begin(9600);
  porta1.write(0);
  porta2.write(0);
  porta3.write(0);
  pinMode(echo1,INPUT);
  pinMode(trig1, OUTPUT);
   pinMode(echo2,INPUT);
  pinMode(trig2, OUTPUT);
   pinMode(echo3,INPUT);
  pinMode(trig3, OUTPUT);
  Serial.println("INICIO");
  porta1.attach(9);
  porta2.attach(10);
  porta3.attach(11);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(8, INPUT);
  
}
  

 void loop()
  {
   estado_chave=digitalRead(8);
   if(estado_chave==HIGH)
   {
      //abrirtodos();
      levanta_todos();
      caixa();
   }
   else
   {  
       //fechartodos();
       fecha_todos();
        Serial.println("Pronto");
   
     horas();
     Serial.println("sai das horas ");
   }

 }
     
     
     
     
void caixa()
{
     
     if(verificasensor(trig1, echo1)<15)
       
     {
         carregado1=true;
         Serial.print(teste);
       Serial.print("caixa1");
       Serial.print(verificasensor(trig1, echo1));
     }
  else
    {
    carregado1=false;
    }
  
   if(verificasensor(trig2, echo2)<15)
       
    {
         carregado2=true;
         Serial.print(teste);
       Serial.print("caixa2");
       Serial.print(verificasensor(trig2, echo2));
     }
  else
    {
    carregado2=false;
    }
  
  
   if(verificasensor(trig3, echo3)<15)
       
     {
         carregado3=true;
         Serial.print(teste);
       Serial.print("caixa3");
       Serial.print(verificasensor(trig3, echo3));
     }
  else
    {
    carregado3=false;
    }
  
     }



void horas()
{
        Serial.println("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA");
        estado_hora1=digitalRead(12);
         Serial.println(estado_hora1);
         delay(1000);
         if(carregado1==true && estado_hora1==HIGH)  // verificar com dupla cond
         { 
           Serial.println("aaaaaaaaaaaaaaaaaaaaa");
           abrirtampa1();
              //levanta_porta1;

           Serial.println("ativar hora 1");
         }
         
      else
      {
       Serial.println("desativar hora 1");
      }
  
  
        estado_hora2=digitalRead(A1);
         if(carregado2==true && estado_hora2==HIGH) // verificar com dupla cond
         { 
           abrirtampa2();
           Serial.println("ativar hora 2");
         }
         
      else
      {
       Serial.println("desativar hora 2");
      }
  
     estado_hora3=digitalRead(A2);
         if(carregado3==true && estado_hora3==HIGH) // verificar com dupla cond
         { 
           Serial.println("aaaaaaaaaaaaaaaaaaaaa");
           //abrirtampa3();
           Serial.println("ativar hora 3");
         }
         
      else
      {
       Serial.println("desativar hora 3");
      }
}  
  
     
 long verificasensor(int trig, int echo)
 {
 long duration, dista;
   digitalWrite(trig, LOW);
   delayMicroseconds(2);
   digitalWrite(trig, HIGH);
   delayMicroseconds(10);
   digitalWrite(trig, LOW);
   duration = pulseIn(echo, HIGH);
   dista = duration / 29.1 /2; 
   Serial.println (dista);
   dista == teste;
   delay(10);
   return dista; 
  }


//## abrir tampa 1 ##
 void abrirtampa1()
 {
  Serial.println("abri a tampa1");
 //  porta1.write(90);  // tampa aberta
   levanta_porta1();
   tamp_aberta1=true;
   while(verificasensor(trig1, echo1)<15){
        vazio1=false;
   }
   vazio1=true;
   delay(4000);
   while(verificasensor(trig1, echo1)>15){
   
   }
   vazio1=false;
 //  fechartampa1();
 delay(4000);
 fecha_porta1();
   
}

/*//##fechar tampa 1 ##
  void fechartampa1()
  { 
    delay(4000);
    porta1.write(0);
    
  }*/

//## abrir tampa 2 ##
 void abrirtampa2()
 {
 //  porta2.write(90);  // tampa aberta
   //levanta_porta2();
   tamp_aberta2=true;
   while(verificasensor(trig2, echo2)<15){
        vazio2=false;
   }
   vazio2=true;
   delay(4000);
   while(verificasensor(trig2, echo2)>15){
   
   }
   vazio1=false;
  // fechartampa2();
   fecha_porta2();
  
 }

/*//## fechar tampa 2 ##
  void fechartampa2()
 {
  delay(4000);
   porta2.write(0); 
 }  */

/*//## abrir tampa 3 ##
 void abrirtampa3()
 {
  // porta3.write(90);  // tampa aberta
   tamp_aberta3=true;
   while(verificasensor(trig3, echo3)<15){
        vazio3=false;
   }
   vazio3=true;
   delay(4000);
   while(verificasensor(trig3, echo3)>15){
   
   }
   vazio3=false;
  // fechartampa3();
  
 }

//## fechar tampa 3 ##
  void fechartampa3()
 {
  delay(4000);
   porta3.write(0); 
 }  
*/

/*  void abrirtodos()
  {
   
    for(int i=0; i<=90; i++){
 porta1.write(i);
 delay(150);
    
    }
    porta2.write(90);
    porta3.write(90);
  }

  void fechartodos()
  {
    delay(1000);
     for(int i=90; i>=0; i--){
 porta1.write(i);
 delay(150);
    
    }
    porta2.write(0);
    porta3.write(0);
  }*/

void levanta_porta1() {
  
 
  while(posicao1<90){


    porta1.write(posicao1); // “Escreve” na tampa a posiçao para onde o servo se vai deslocar

    //Serial.println("a baixar cancela : posicao");
    posicao1=posicao1+10;
     delay(150);
  }
  
}

void fecha_porta1() {
  //Serial.println("levantando a cancela");

  while (posicao1>0){
    porta1.write(posicao1); // “Escreve” na tampa a posiçao para onde o servo se vai desloca
    //Serial.println("a levantar cancela: posicao");
    posicao1=posicao1-10;
    delay(150);
  }

}

void fecha_porta2() {
  //Serial.println("levantando a cancela");

  while (posicao1>0){
    porta1.write(posicao1); // “Escreve” na tampa a posiçao para onde o servo se vai desloca
    //Serial.println("a levantar cancela: posicao");
    posicao1=posicao1-10;
    delay(150);
  }

}

void fecha_porta3() {
  //Serial.println("levantando a cancela");

  while (posicao1>0){
    porta1.write(posicao1); // “Escreve” na tampa a posiçao para onde o servo se vai desloca
    //Serial.println("a levantar cancela: posicao");
    posicao1=posicao1-10;
    delay(150);
  }

}

void levanta_todos() {
  
 
  while(posicao1<90){


    porta1.write(posicao1); // “Escreve” na tampa a posiçao para onde o servo se vai deslocar
//porta2.write(posicao); // “Escreve” na tampa a posiçao para onde o servo se vai deslocar
//porta3.write(posicao); // “Escreve” na tampa a posiçao para onde o servo se vai deslocar

    //Serial.println("a baixar cancela : posicao");
    posicao1=posicao1+10;
     delay(150);
  }
  
}

void fecha_todos() {
  //Serial.println("levantando a cancela");

  while (posicao1>0){
    porta1.write(posicao1); // “Escreve” na tampa a posiçao para onde o servo se vai desloca
    // porta2.write(posicao); // “Escreve” na tampa a posiçao para onde o servo se vai desloca
     // porta3.write(posicao); // “Escreve” na tampa a posiçao para onde o servo se vai desloca
    //Serial.println("a levantar cancela: posicao");
    posicao1=posicao1-10;
    delay(150);
  }

}
