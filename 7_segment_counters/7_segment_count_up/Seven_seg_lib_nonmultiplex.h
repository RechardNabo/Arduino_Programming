/*
 * FIle Available on GITHUB
 * https://github.com/RechardNabo/Arduino_Programming/blob/master/Seven_seg_header%20library/Seeven_seg_lib_nonmultiplex.h
                        A
                    =========
                    =       =
                  F =       =  B
                    =   G   =
                    =========
                    =       =
                  E =       =  C
                    =       =
                    ========= # decimal point
                        D
                    G-F-Com-A-B
                    ===========
                    =         =
                    =         =
                    =         =     //8 pins
                    ===========
                    =         =
                    =         =
                    =         =
                    =========== #
                    E-D-Com-C-Dp
*/
#define SegType1 'A'
#define SegType2 'C'
#define ENABLE ENABLE 
#define DISABLE DISABLE 

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
		void Initialize(){
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
					Initialize();
					return this->segType;
					break;

				case SegType2:
					Initialize();
					return this->segType;
					break;
				default:
					break;
			}
			return this->segType;
		}
	private:
		void Digits_cathode(int number){
			this->number = number;
		switch(this->number){
			case 0x00:
					digitalWrite(this->pinA,ENABLE);
					digitalWrite(this->pinB,ENABLE);
					digitalWrite(this->pinC,ENABLE);
					digitalWrite(this->pinD,ENABLE);
					digitalWrite(this->pinE,ENABLE);
					digitalWrite(this->pinF,ENABLE);
					digitalWrite(this->pinG,DISABLE);
				  break;
			case 0x01:
					digitalWrite(this->pinA,DISABLE);
					digitalWrite(this->pinB,ENABLE);
					digitalWrite(this->pinC,ENABLE);
					digitalWrite(this->pinD,DISABLE);
					digitalWrite(this->pinE,DISABLE);
					digitalWrite(this->pinF,DISABLE);
					digitalWrite(this->pinG,DISABLE);
				  break;
			case 0x02:
					digitalWrite(this->pinA,ENABLE);
					digitalWrite(this->pinB,ENABLE);
					digitalWrite(this->pinC,DISABLE);
					digitalWrite(this->pinD,ENABLE);
					digitalWrite(this->pinE,ENABLE);
					digitalWrite(this->pinF,DISABLE);
					digitalWrite(this->pinG,ENABLE);
				  break;
			case 0x03:
					digitalWrite(this->pinA,ENABLE);
					digitalWrite(this->pinB,ENABLE);
					digitalWrite(this->pinC,ENABLE);
					digitalWrite(this->pinD,ENABLE);
					digitalWrite(this->pinE,DISABLE);
					digitalWrite(this->pinF,DISABLE);
					digitalWrite(this->pinG,ENABLE);
					break;
			case 0x04:
					digitalWrite(this->pinA,DISABLE);
					digitalWrite(this->pinB,ENABLE);
					digitalWrite(this->pinC,ENABLE);
					digitalWrite(this->pinD,DISABLE);
					digitalWrite(this->pinE,DISABLE);
					digitalWrite(this->pinF,ENABLE);
					digitalWrite(this->pinG,ENABLE);
				  break;
			case 0x05:
					digitalWrite(this->pinA,ENABLE);
					digitalWrite(this->pinB,DISABLE);
					digitalWrite(this->pinC,ENABLE);
					digitalWrite(this->pinD,ENABLE);
					digitalWrite(this->pinE,DISABLE);
					digitalWrite(this->pinF,ENABLE);
					digitalWrite(this->pinG,ENABLE);
				  break;
			case 0x06:
					digitalWrite(this->pinA,ENABLE);
					digitalWrite(this->pinB,DISABLE);
					digitalWrite(this->pinC,ENABLE);
					digitalWrite(this->pinD,ENABLE);
					digitalWrite(this->pinE,ENABLE);
					digitalWrite(this->pinF,ENABLE);
					digitalWrite(this->pinG,ENABLE);
				  break;
			case 0x07:
					digitalWrite(this->pinA,ENABLE);
					digitalWrite(this->pinB,ENABLE);
					digitalWrite(this->pinC,ENABLE);
					digitalWrite(this->pinD,DISABLE);
					digitalWrite(this->pinE,DISABLE);
					digitalWrite(this->pinF,DISABLE);
					digitalWrite(this->pinG,DISABLE);
				  break;
			case 0x08:
					digitalWrite(this->pinA,ENABLE);
					digitalWrite(this->pinB,ENABLE);
					digitalWrite(this->pinC,ENABLE);
					digitalWrite(this->pinD,ENABLE);
					digitalWrite(this->pinE,ENABLE);
					digitalWrite(this->pinF,ENABLE);
					digitalWrite(this->pinG,ENABLE);
				  break;
			case 0x09:
					digitalWrite(this->pinA,ENABLE);
					digitalWrite(this->pinB,ENABLE);
					digitalWrite(this->pinC,ENABLE);
					digitalWrite(this->pinD,ENABLE);
					digitalWrite(this->pinE,DISABLE);
					digitalWrite(this->pinF,ENABLE);
					digitalWrite(this->pinG,ENABLE);
				  break;
			case 0x0A:
					digitalWrite(this->pinA,ENABLE);
					digitalWrite(this->pinB,ENABLE);
					digitalWrite(this->pinC,ENABLE);
					digitalWrite(this->pinD,DISABLE);
					digitalWrite(this->pinE,ENABLE);
					digitalWrite(this->pinF,ENABLE);
					digitalWrite(this->pinG,ENABLE);
				  break;
							}
			}
		private:
			void Digits_anode(int number){
				this->number = number;
			switch(this->number){
				case 0x00:
						digitalWrite(this->pinA,DISABLE);
						digitalWrite(this->pinB,DISABLE);
						digitalWrite(this->pinC,DISABLE);
						digitalWrite(this->pinD,DISABLE);
						digitalWrite(this->pinE,DISABLE);
						digitalWrite(this->pinF,DISABLE);
						digitalWrite(this->pinG,ENABLE);
						break;
				case 0x01:
						digitalWrite(this->pinA,ENABLE);
						digitalWrite(this->pinB,DISABLE);
						digitalWrite(this->pinC,DISABLE);
						digitalWrite(this->pinD,ENABLE);
						digitalWrite(this->pinE,ENABLE);
						digitalWrite(this->pinF,ENABLE);
						digitalWrite(this->pinG,ENABLE);
						break;
				case 0x02:
						digitalWrite(this->pinA,DISABLE);
						digitalWrite(this->pinB,DISABLE);
						digitalWrite(this->pinC,ENABLE);
						digitalWrite(this->pinD,DISABLE);
						digitalWrite(this->pinE,DISABLE);
						digitalWrite(this->pinF,ENABLE);
						digitalWrite(this->pinG,DISABLE);
						break;
				case 0x03:
						digitalWrite(this->pinA,DISABLE);
						digitalWrite(this->pinB,DISABLE);
						digitalWrite(this->pinC,DISABLE);
						digitalWrite(this->pinD,DISABLE);
						digitalWrite(this->pinE,ENABLE);
						digitalWrite(this->pinF,ENABLE);
						digitalWrite(this->pinG,DISABLE);
						break;
				case 0x04:
						digitalWrite(this->pinA,ENABLE);
						digitalWrite(this->pinB,DISABLE);
						digitalWrite(this->pinC,DISABLE);
						digitalWrite(this->pinD,ENABLE);
						digitalWrite(this->pinE,ENABLE);
						digitalWrite(this->pinF,DISABLE);
						digitalWrite(this->pinG,DISABLE);
						break;
				case 0x05:
						digitalWrite(this->pinA,DISABLE);
						digitalWrite(this->pinB,ENABLE);
						digitalWrite(this->pinC,DISABLE);
						digitalWrite(this->pinD,DISABLE);
						digitalWrite(this->pinE,ENABLE);
						digitalWrite(this->pinF,DISABLE);
						digitalWrite(this->pinG,DISABLE);
						break;
				case 0x06:
						digitalWrite(this->pinA,DISABLE);
						digitalWrite(this->pinB,ENABLE);
						digitalWrite(this->pinC,DISABLE);
						digitalWrite(this->pinD,DISABLE);
						digitalWrite(this->pinE,DISABLE);
						digitalWrite(this->pinF,DISABLE);
						digitalWrite(this->pinG,DISABLE);
						break;
				case 0x07:
						digitalWrite(this->pinA,DISABLE);
						digitalWrite(this->pinB,DISABLE);
						digitalWrite(this->pinC,DISABLE);
						digitalWrite(this->pinD,ENABLE);
						digitalWrite(this->pinE,ENABLE);
						digitalWrite(this->pinF,ENABLE);
						digitalWrite(this->pinG,ENABLE);
						break;
				case 0x08:
						digitalWrite(this->pinA,DISABLE);
						digitalWrite(this->pinB,DISABLE);
						digitalWrite(this->pinC,DISABLE);
						digitalWrite(this->pinD,DISABLE);
						digitalWrite(this->pinE,DISABLE);
						digitalWrite(this->pinF,DISABLE);
						digitalWrite(this->pinG,DISABLE);
						break;
				case 0x09:
						digitalWrite(this->pinA,DISABLE);
						digitalWrite(this->pinB,DISABLE);
						digitalWrite(this->pinC,DISABLE);
						digitalWrite(this->pinD,DISABLE);
						digitalWrite(this->pinE,ENABLE);
						digitalWrite(this->pinF,DISABLE);
						digitalWrite(this->pinG,DISABLE);
						break;
				case 0x0A:
						digitalWrite(this->pinA,DISABLE);
						digitalWrite(this->pinB,DISABLE);
						digitalWrite(this->pinC,DISABLE);
						digitalWrite(this->pinD,ENABLE);
						digitalWrite(this->pinE,DISABLE);
						digitalWrite(this->pinF,DISABLE);
						digitalWrite(this->pinG,DISABLE);
						break;
								}
				}

		public:
			void Display(int number){
				this->number = number;
				if(SegType()=='A'){
				
					Digits_anode(this->number);
				}
				if(SegType()=='C'){
					
					Digits_cathode(this->number);
				}
			}
};
