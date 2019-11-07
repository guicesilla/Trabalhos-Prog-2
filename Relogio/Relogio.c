//Guilherme Augusto Leme Cesila - 217116
//Julia Yumy Nakamura Zanerato - 219372
#include<time.h>
#include<stdlib.h>

double inicia, para;
double startTime, finalTime,tempo;

void start(){
	
inicia = (double) clock() / CLOCKS_PER_SEC;

}

void finish(){
	
para = (double) clock() / CLOCKS_PER_SEC;
tempo = para - inicia;
	
}

double getDelta(){
	
return tempo;
	
}
