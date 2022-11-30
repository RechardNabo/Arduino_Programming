#define A 2
#define B 3
#define C 4
#define D 5
#define E 6
#define F 7
#define G 8

void Init(){  
  pinMode(A,OUTPUT);
  pinMode(B,OUTPUT);
  pinMode(C,OUTPUT);
  pinMode(D,OUTPUT);
  pinMode(E,OUTPUT);
  pinMode(F,OUTPUT);
  pinMode(G,OUTPUT);
  
  digitalWrite(A,LOW);
			  digitalWrite(B,LOW);
			  digitalWrite(C,LOW);
			  digitalWrite(D,LOW);
			  digitalWrite(E,LOW);
			  digitalWrite(F,LOW);
			  digitalWrite(G,LOW);
 }
 void Display(int number){
	switch(number){
          case 0 :
			  digitalWrite(A,HIGH);
			  digitalWrite(B,HIGH);
			  digitalWrite(C,HIGH);
			  digitalWrite(D,HIGH);
			  digitalWrite(E,HIGH);
			  digitalWrite(F,HIGH);
			  digitalWrite(G,LOW);
		  
          break;

          case 1 :
			  digitalWrite(A,LOW);
			  digitalWrite(B,HIGH);
			  digitalWrite(C,HIGH);
			  digitalWrite(D,LOW);
			  digitalWrite(E,LOW);
			  digitalWrite(F,LOW);
			  digitalWrite(G,LOW);
		  
          break;

          case 2 :
			  digitalWrite(A,HIGH);
			  digitalWrite(B,HIGH);
			  digitalWrite(C,LOW);
			  digitalWrite(D,HIGH);
			  digitalWrite(E,HIGH);
			  digitalWrite(F,LOW);
			  digitalWrite(G,HIGH);
		  
          break;

          case 3 :
			  digitalWrite(A,HIGH);
			  digitalWrite(B,HIGH);
			  digitalWrite(C,HIGH);
			  digitalWrite(D,HIGH);
			  digitalWrite(E,LOW);
			  digitalWrite(F,LOW);
			  digitalWrite(G,HIGH);
		  
          break;

          case 4 :
			  digitalWrite(A,LOW);
			  digitalWrite(B,HIGH);
			  digitalWrite(C,HIGH);
			  digitalWrite(D,LOW);
			  digitalWrite(E,LOW);
			  digitalWrite(F,HIGH);
			  digitalWrite(G,HIGH);
		  
          break;

          case 5 :
			  digitalWrite(A,HIGH);
			  digitalWrite(B,LOW);
			  digitalWrite(C,HIGH);
			  digitalWrite(D,HIGH);
			  digitalWrite(E,LOW);
			  digitalWrite(F,HIGH);
			  digitalWrite(G,HIGH);
			  
          break;

          case 6 :
			  digitalWrite(A,HIGH);
			  digitalWrite(B,LOW);
			  digitalWrite(C,HIGH);
			  digitalWrite(D,HIGH);
			  digitalWrite(E,HIGH);
			  digitalWrite(F,HIGH);
			  digitalWrite(G,HIGH);
		  
          break;

          case 7 :
			  digitalWrite(A,HIGH);
			  digitalWrite(B,HIGH);
			  digitalWrite(C,HIGH);
			  digitalWrite(D,LOW);
			  digitalWrite(E,LOW);
			  digitalWrite(F,LOW);
			  digitalWrite(G,LOW);
		  
          break;

          case 8 :
			  digitalWrite(A,HIGH);
			  digitalWrite(B,HIGH);
			  digitalWrite(C,HIGH);
			  digitalWrite(D,HIGH);
			  digitalWrite(E,HIGH);
			  digitalWrite(F,HIGH);
			  digitalWrite(G,HIGH);
		  
          break;

          case 9 :
			  digitalWrite(A,HIGH);
			  digitalWrite(B,HIGH);
			  digitalWrite(C,HIGH);
			  digitalWrite(D,HIGH);
			  digitalWrite(E,LOW);
			  digitalWrite(F,HIGH);
			  digitalWrite(G,HIGH);
		  
          break;

          default:
			  digitalWrite(A,LOW);
			  digitalWrite(B,LOW);
			  digitalWrite(C,LOW);
			  digitalWrite(D,LOW);
			  digitalWrite(E,LOW);
			  digitalWrite(F,LOW);
			  digitalWrite(G,LOW);
		  
          break;
        }
 }