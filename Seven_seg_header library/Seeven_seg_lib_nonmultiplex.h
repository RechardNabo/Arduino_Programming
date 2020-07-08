#include <TimerOne.h>

#define SegType1 'A'
#define SegType2 'C'

class Segment{
	private:
		int pinA,pinB,pinC,pinD,pinE,pinF,pinG,pinDp,number;
		char segType;
	volatile
		 int status = 0x00;
	public:
		Segment(){
			//empty constructor
		}
	public:
		Segment(int pinA,int pinB,int pinC,int pinD,int pinE,int pinF,int pinG,int pinDp, char  segType){
			this->pinA = pinA;
			this->pinB = pinB;
			this->pinC = pinC;
			this->pinD = pinD;
			this->pinE = pinE;
			this->pinF = pinF;
			this->pinG = pinG;
			this->pinDp = pinDp;
			this->segType = toupper(segType);
		}

	private:
		void Cathod(){
			pinMode(this->pinA,OUTPUT);
			pinMode(this->pinB,OUTPUT);
			pinMode(this->pinC,OUTPUT);
			pinMode(this->pinD,OUTPUT);
			pinMode(this->pinE,OUTPUT);
			pinMode(this->pinF,OUTPUT);
			pinMode(this->pinG,OUTPUT);
			pinMode(this->pinDp,OUTPUT);
		}
	private:
		void Anode(){
			pinMode(this->pinA,OUTPUT);
			pinMode(this->pinB,OUTPUT);
			pinMode(this->pinC,OUTPUT);
			pinMode(this->pinD,OUTPUT);
			pinMode(this->pinE,OUTPUT);
			pinMode(this->pinF,OUTPUT);
			pinMode(this->pinG,OUTPUT);
			pinMode(this->pinDp,OUTPUT);
		}
	private:
		char SegType(){
			switch(this->segType){
				case SegType1:
					Anode();
					return this->segType;
					break;

				case SegType2:
					Cathod();
					return this->segType;
					break;
				default:
					break;
			}
			return this->segType;
		}
	private:
		void Digits(int number){
			this->number = number;
		switch(this->number){
			case 0x00:
					digitalWrite(pinA,HIGH);
					digitalWrite(pinB,HIGH);
					digitalWrite(pinC,HIGH);
					digitalWrite(pinD,HIGH);
					digitalWrite(pinE,HIGH);
					digitalWrite(pinF,HIGH);
					digitalWrite(pinG,LOW);
				  break;
			case 0x01:
					digitalWrite(pinA,LOW);
					digitalWrite(pinB,HIGH);
					digitalWrite(pinC,HIGH);
					digitalWrite(pinD,LOW);
					digitalWrite(pinE,LOW);
					digitalWrite(pinF,LOW);
					digitalWrite(pinG,LOW);
				  break;
			case 0x02:
					digitalWrite(pinA,HIGH);
					digitalWrite(pinB,HIGH);
					digitalWrite(pinC,LOW);
					digitalWrite(pinD,HIGH);
					digitalWrite(pinE,HIGH);
					digitalWrite(pinF,LOW);
					digitalWrite(pinG,HIGH);
				  break;
			case 0x03:
					digitalWrite(pinA,HIGH);
					digitalWrite(pinB,HIGH);
					digitalWrite(pinC,HIGH);
					digitalWrite(pinD,HIGH);
					digitalWrite(pinE,LOW);
					digitalWrite(pinF,LOW);
					digitalWrite(pinG,HIGH);
					break;
			case 0x04:
					digitalWrite(pinA,LOW);
					digitalWrite(pinB,HIGH);
					digitalWrite(pinC,HIGH);
					digitalWrite(pinD,LOW);
					digitalWrite(pinE,LOW);
					digitalWrite(pinF,HIGH);
					digitalWrite(pinG,HIGH);
				  break;
			case 0x05:
					digitalWrite(pinA,HIGH);
					digitalWrite(pinB,LOW);
					digitalWrite(pinC,HIGH);
					digitalWrite(pinD,HIGH);
					digitalWrite(pinE,LOW);
					digitalWrite(pinF,HIGH);
					digitalWrite(pinG,HIGH);
				  break;
			case 0x06:
					digitalWrite(pinA,HIGH);
					digitalWrite(pinB,LOW);
					digitalWrite(pinC,HIGH);
					digitalWrite(pinD,HIGH);
					digitalWrite(pinE,HIGH);
					digitalWrite(pinF,HIGH);
					digitalWrite(pinG,HIGH);
				  break;
			case 0x07:
					digitalWrite(pinA,HIGH);
					digitalWrite(pinB,HIGH);
					digitalWrite(pinC,HIGH);
					digitalWrite(pinD,LOW);
					digitalWrite(pinE,LOW);
					digitalWrite(pinF,LOW);
					digitalWrite(pinG,LOW);
				  break;
			case 0x08:
					digitalWrite(pinA,HIGH);
					digitalWrite(pinB,HIGH);
					digitalWrite(pinC,HIGH);
					digitalWrite(pinD,HIGH);
					digitalWrite(pinE,HIGH);
					digitalWrite(pinF,HIGH);
					digitalWrite(pinG,HIGH);
				  break;
			case 0x09:
					digitalWrite(pinA,HIGH);
					digitalWrite(pinB,HIGH);
					digitalWrite(pinC,HIGH);
					digitalWrite(pinD,HIGH);
					digitalWrite(pinE,LOW);
					digitalWrite(pinF,HIGH);
					digitalWrite(pinG,HIGH);
				  break;
			case 0x0A:
					digitalWrite(pinA,HIGH);
					digitalWrite(pinB,HIGH);
					digitalWrite(pinC,HIGH);
					digitalWrite(pinD,LOW);
					digitalWrite(pinE,HIGH);
					digitalWrite(pinF,HIGH);
					digitalWrite(pinG,HIGH);
				  break;
							}
			}

		public:
			void Display(int number){
				this->number = number;
				SegType();
				Digits(this->number);
			}


};
