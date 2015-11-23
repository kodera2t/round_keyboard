// Touch keyboard program,using round shape 1D touch sensor
// 
// Nov.23, 2015 kodera2t
///This program is free software: you can redistribute it and/or modify
///it under the terms of the GNU General Public License as published by
///the Free Software Foundation, either version 3 of the License, or
// any later version.

#include <Keyboard.h>
#define shift1 12
#define shift2 13
boolean shift_1,shift_2,shift_3;
unsigned long time1,time2;
unsigned int diftime;
// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
 // Serial.begin(9600);
  Keyboard.begin();
  pinMode(shift1, OUTPUT);
  pinMode(shift2, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  byte inkey,oldkey;
  char outkey;
  unsigned int senseval = analogRead(A0);
  oldkey=inkey;
  inkey=keynum(senseval);

  if(inkey !=0){/////////
    
    time1=millis();
    diftime=time1-time2;
    if((inkey != oldkey)&&(diftime>200)){
  shiftcheck(inkey);
  outkey=keyinput(inkey);

  if(outkey !=0x00){
  Keyboard.write(outkey);
  }
  //Serial.println("");
    }
  }//////////////////////
  delay(50);
  time2=time1;
}

byte keynum(unsigned int i){
  byte num;
  if(i<15){
    num=0;
    goto hoge;
  }else if(i<60){
    num=1;
    goto hoge;
  }else if(i<120){
    num=2;
    goto hoge;
  }else if(i<180){
    num=3;
    goto hoge;
  }else if(i<250){
    num=4;
    goto hoge;
  }else if(i<300){
    num=5;
    goto hoge;
  }else if(i<370){
    num=6;
    goto hoge;
  }else if(i<450){
    num=7;
    goto hoge;
  }else if(i<500){
    num=8;
    goto hoge;
  }else if(i<580){
    num=9;
    goto hoge;
  }else if(i<640){
    num=10;
    goto hoge;
  }else if(i<700){
    num=11;
    goto hoge;
  }else if(i<780){
    num=12;
    goto hoge;
  }else if(i<860){
    num=13;
    goto hoge;
  }else if(i<920){
    num=14;
    goto hoge;
  }else if(i<1000){
    num=15;
  }else{
    num=0;
  }
hoge:
  return num;
}

void shiftcheck(byte j){
  switch(j){
    case 1:
    shift_1=1;
    break;
    case 2:
    shift_2=1;
    break;
    case 14:
    shift_3=1; 
    break;
  }
}

char keyinput(byte in){
char out;
  switch(in){
    case 3:
      {
      if(shift_1==1){
        out='"';
//        shift_1=0;
      }else if(shift_2==1){
        out='+';
//        shift_2=0;
      }else if(shift_3==1){
        out='-';
 //       shift_3=0;
      }else{
        out='1';
      }
      initial_shift();
      break;
      }

    case 4:
      {
      if(shift_1==1){
        out='a';
     //   shift_1=0;
      }else if(shift_2==1){
        out='b';
     //   shift_2=0;
      }else if(shift_3==1){
        out='c';
     //   shift_3=0;
      }else{
        out='2';
      }
      initial_shift();
      break;
      }

    case 5:
      {
      if(shift_1==1){
        out='d';
     //   shift_1=0;
      }else if(shift_2==1){
        out='e';
     //   shift_2=0;
      }else if(shift_3==1){
        out='f';
     //   shift_3=0;
      }else{
        out='3';
      }
      initial_shift();
      break;
      }

    case 6:
      {
      if(shift_1==1){
        out='g';
     //   shift_1=0;
      }else if(shift_2==1){
        out='h';
     //   shift_2=0;
      }else if(shift_3==1){
        out='i';
     //   shift_3=0;
      }else{
        out='4';
      }
      initial_shift();
      break;
      }

    case 7:
      {
      if(shift_1==1){
        out='j';
     //   shift_1=0;
      }else if(shift_2==1){
        out='k';
     //   shift_2=0;
      }else if(shift_3==1){
        out='l';
     //   shift_3=0;
      }else{
        out='5';
      }
      initial_shift();
      break;
      }   

    case 8:
      {
      if(shift_1==1){
        out='m';
     //   shift_1=0;
      }else if(shift_2==1){
        out='n';
     //   shift_2=0;
      }else if(shift_3==1){
        out='o';
     //   shift_3=0;
      }else{
        out='6';
      }
      initial_shift();
      break;
      }         

    case 9:
      {
      if(shift_1==1){
        out='p';
     //   shift_1=0;
      }else if(shift_2==1){
        out='q';
     //   shift_2=0;
      }else if(shift_3==1){
        out='r';
     //   shift_3=0;
      }else{
        out='7';
      }
      initial_shift();
      break;
      }
      
    case 10:
      {
      if(shift_1==1){
        out='s';
     //   shift_1=0;
      }else if(shift_2==1){
        out='t';
     //   shift_2=0;
      }else if(shift_3==1){
        out='u';
     //   shift_3=0;
      }else{
        out='8';
      }
      initial_shift();
      break;
      }

    case 11:
      {
      if(shift_1==1){
        out='v';
     //   shift_1=0;
      }else if(shift_2==1){
        out='w';
     //   shift_2=0;
      }else if(shift_3==1){
        out='x';
     //   shift_3=0;
      }else{
        out='9';
      }
      initial_shift();
      break;
      }

    case 12:
      {
      if(shift_1==1){
        out='y';
     //   shift_1=0;
      }else if(shift_2==1){
        out='z';
     //   shift_2=0;
      }else if(shift_3==1){
        out='*';
     //   shift_3=0;
      }else{
        out='0';
      }
      initial_shift();
      break;
      }

    case 13:
      {
      if(shift_1==1){
        out='(';
     //   shift_1=0;
      }else if(shift_2==1){
        out=')';
     //   shift_2=0;
      }else if(shift_3==1){
        out='&';
      }else{
        out='@';
      }
      initial_shift();
      break;
      }

    case 15:
      {
      if(shift_1==1){
        out=0x08;
     //   shift_1=0;
      }else if(shift_2==1){
        out=0x20;
     //   shift_2=0;
      }else if(shift_3==1){
        out=0x00;
      }else{
        out='\n';
      }
      initial_shift();
      break;
      }
                  
    default:
    //;
    out=0x00;
  }

  return out;
}

void initial_shift()
{
  shift_1=0;
  shift_2=0;
  shift_3=0;
}

