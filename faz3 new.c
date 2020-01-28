


#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<windows.h>
void colorrized(int k)
{
	HANDLE hConsole=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole,k);
}
unsigned char count[99999];

struct impor{
	
	unsigned char note_on;
	
	unsigned char note ;
	
	unsigned char note_off;
	
	unsigned char deltatime;
	
	unsigned char temsem;
	
}im[9999999];

struct event {
	
       	unsigned char KeyPressureorAftertouch ; 
       	
       	unsigned char BankSelect ;
       	
       	unsigned char ModulationWheel ;
       	
       	unsigned char BreathController ;
       	
      
       	
       	unsigned char FootController ;
       	
       	unsigned char PortamentoTime ;
       	
       	unsigned char DataEntrySliderMSB ;
       	
       	unsigned char MainVolume;
       	
       	unsigned char Balance ;
       	
       	unsigned char Pan ;
       	
       	unsigned char ExpressionController ;
       	
       	unsigned char EffectControl1 ;
       	
       	unsigned char tEffectControl2 ;
		      	
       	unsigned char GeneraPurposeController1;
       	
       	unsigned char tGeneralPurposeControllers2 ;
       	
       	unsigned char t1GeneralPurposeControllers3 ;
       	
       	unsigned char t2GeneralPurposeControllers4 ;
       	
       	unsigned char LSBforcontrollers0 ;
       	
       	unsigned char tLSBforcontrollers1 ;
       	
       	unsigned char t1LSBforcontrollers2 ;
       	
       	unsigned char t2LSBforcontrollers3 ;
       	
       	unsigned char t3LSBforcontrollers4 ;
       	
       	unsigned char t4LSBforcontrollers5 ;
       	
       	unsigned char  t5LSBforcontrollers17 ;
       	
       	unsigned char t6LSBforcontrollers18;
       	
       	unsigned char t7LSBforcontrollers19 ;
       	
       	unsigned char t8LSBforcontrollers20 ;
       	
       	unsigned char t9LSBforcontrollers21 ;
       	
       	unsigned char Portamento;
       	
       	unsigned char SostenatoPedal;
       	
       	unsigned char SoftPedal ;
       	
       	unsigned char LegatoFootswitch;
       	
       	unsigned char Hold2;
       	
       	unsigned char  SoundController1 ; 	
       	
       	unsigned char SoundController2 ;
       	
       	unsigned char PortamentoControl ;
       	
       	unsigned char Effect1Depth ;
       	
       	unsigned char  Effects2Depth ;
       	
       	unsigned char DataIncrement;
       	
       	unsigned char NonRegisteredParameterNumber ; 
       	
       	unsigned char RegisteredParameterNumber ;
       	
       	unsigned char ModeMessages ;
       	
       
       	
      

}ev[9999999];

struct meta {
	
		unsigned char SetTempoinmicrosecondsperquarternote ;
	
	unsigned char endofthetrack ;
	
	unsigned char SequenceNumber ;
	
	unsigned char TextEvent ;
	
	unsigned char CopyrightNotice ;
	
	unsigned char SequenceTrackName;
	
	unsigned char InstrumentName ;
	
	unsigned char Lyric;
	
	unsigned char Marker ;
	
	unsigned char CuePoint;
	
	unsigned char MIDIChannelPrefix ;
	
//	unsigned char SetTempoinmicrosecondsperquarternote ;
	
	unsigned char SMPTEOffset ;
	
	unsigned char TimeSignature ;
	
	unsigned char KeySignature ;
	
	unsigned char SequencerSpecifiMetaEvent ;

}meta[999999];


unsigned int length;
	
	unsigned char D_format[2];
	
	unsigned char D_tracks[2];
	
	unsigned char D_division[2];
	
	char Chank_type[5];
	char v[100];
	unsigned int   k2 ,ii;
int main(){
	int u;
	

			colorrized(94);  //we have a graphic in this section
	
	
	

	system("cls");
		printf("        In The Name Of God          ");

	printf("\n");
	printf("\n");
	

	struct im ;
	
	FILE *fp;

	printf("\n");
	printf("please write your file  :    ");
    gets(v);
	printf("\n\n");
	
	
	
	fp=fopen(v,"rb");
	
	
	
	
	fread(&Chank_type , 4 , 1 , fp);

	printf("the chunk type is :   ");
	
	printf("%s",Chank_type);
	
	
	printf("\n");
	printf("\n");
	
	fread(&length , 4 , 1 , fp);

  // (((length>>24) & 0length000000ff) | ((length>>8) & 0length0000ff00) | ((length<<8) & 0length00ff0000) |((length<<24) & 0lengthff0000));
   
   	printf("the lenth is :    ");
   	
	
	printf("%d",changeEndian(length));
	
	printf("\n");
	printf("\n");
	
	
	
	fread(&D_format , 2 , 1 , fp);
	
	//0001
	printf("the format is :  ");
	
	int format=D_format[1] | D_format[0] << 8;
	
	printf("%d",format);
	
	printf("\n");
	printf("\n");



	fread(&D_tracks , 2 , 1 , fp);
	int track =D_tracks[1] | D_tracks[0] << 8;
	printf("the tracks is :   ");
	
	printf("%d",track)	;
	
	printf("\n");
	printf("\n");



	fread( &D_division, 2 , 1 , fp);
	int d =D_division[1] | D_division[0] << 8;
	printf("the division is :   ");

	printf("%d",d);

	printf("\n");
	printf("\n");

	printf("The End of the faz 2 in this section");
	printf("\n");
	printf("\n");
    int counter = 0;
    
    int counter1 =0 ;
		
		// in this section we pour the bits in array count
		
	while( counter1 != track){
		
		if(count[counter]== 0x2f && count[counter-1] == 0xff){
			counter1 = counter1 + 1 ;
		}
	counter = counter +1 ;
		
		
			fread(&count[counter] , 1  ,1 ,fp);
    	
		   
    		
    		
	}
	printf("Events  :    \n\n");
	checktheevents(counter);

  


}	//end of the main function


int changeEndian(int  x){

       return (((x>>24) & 0x000000ff) | ((x>>8) & 0x0000ff00) | ((x<<8) & 0x00ff0000) | ((x<<24) & 0xff000000));
}
int checktheevents(counter){
		int i;
	//we want to check events
	int t,t1; t=0;t1=0;
	for( i = 0 ; i < counter ; i++) {
		
		if(count[i] < 0xa0 && count[i]>=0x90){
			t=t+1 ;
    	im[t].note_on = count[i];
    	
    	im[t].note = count[i+1];
    	printf("note on "); 
    	printf("and its note is  %x \n", count[i+1]);
		    // in this section we find and store notes and notes on from our midi file
	
		}
		if(count[i] < 0x90 && count[i] >= 0x80 && (count[i-3] >= 0xa0 || count[i-3] < 0x90)  && (count[i+2] >= 0xa0 || count[i+2] < 0x90 ))  {
			
			im[t1].note_off = count[i];
			
			im[t1].deltatime = count[i-1];
			printf(" note off \n");
			
			
			//in this sectin we find and store nots off and delta times  from our midi file
			
		}
	
		if(count[i] >= 0xa0 && count[i] <= 0xa9 ){
			
	  	ev[i].KeyPressureorAftertouch = count[i] ;
		  		
		  		printf("Key Pressure or Aftertouch is %x and its note is %x " , count[i] , count[i+1]);
		  		printf("\n");
		  		
		  		//now we store the key pressure and print its note
		}
		
		if(count[i] >= 0xb0 && count[i] <= 0xb9 && count[i+1] == 0x00 ){
			
			ev[i].BankSelect = count[i] ;
			
			ev[i+1].BankSelect=count[i+1];
			
			ev[i+2].BankSelect = count[i+2];//store the varieble of bank select
			
			printf("the event of bank select is %x %x ", count[i], count[i+1]);
			printf("\n");
			//now we store and printf the event of bank select
			
		}
		
		if(count[i] >= 0xb0 && count[i] <= 0xb9 && count[i+1] == 0x01){
			
			ev[i].ModulationWheel = count[i];
			
			ev[i+1].ModulationWheel = count[i+1];
			
			ev[i+2].ModulationWheel = count [i+2];//store of ModulationWheel
			
			printf("the event of ModulationWheel is %x %x",count[i], count[i+1]);
			printf("\n");
			
			//now we store and print ModulationWheel
		}
		
		if(count[i] >= 0xb0 && count[i] <= 0xb9 && count[i+1] == 0x02){
			
			ev[i].BreathController =count[i] ;
			 
			ev[i+1].BreathController =count[i+1];
			
			ev[i+2].BreathController = count[i+2];//store the varieble of BreathController
			
			printf("the of BreathController is %x %x  ", count [i], count [i+1]);
			printf("\n");
			//we store and print BreathController
			
		}
		
		if(count[i] >= 0xb0 && count[i] <= 0xb9 && count[i+1] == 0x04){
			
			ev[i].FootController = count [i];
			
			ev[i+1].FootController = count[i+1]; 
			
			ev[i+2].FootController =count[i+2];//store the varieble 
			
			printf("the event of FootController is %x %x ",count[i] , count [i+1]);
						//stor and print the event 
		}
		
		if(count[i] >= 0xb0 && count[i] <= 0xb9 && count[i+1] == 0x05){
			
			ev[i].PortamentoTime =count[i] ;
			
			ev[i+1].PortamentoTime =count[i+1];
			
			ev[i+2].PortamentoTime = count[i+2];//store the varieble 
			
			printf("the event of PortamentoTime is %x %x ");
			printf("\n");
			
			//store the event 
		}
		
		if(count[i] >= 0xb0 && count[i] <= 0xb9 && count[i+1] == 0x06){
			
			ev[i].DataEntrySliderMSB = count[i]; 
			
			 ev[i+1].DataEntrySliderMSB = count[i+1];
			 
			 ev[i+2].DataEntrySliderMSB =count[i+2];
			 
			 printf("yhe event of DataEntrySliderMSB is %x %x ",count[i] , count[i+1]);
			 printf("\n");
			
		}
		
		if(count[i] >= 0xb0 && count[i] <= 0xb9 && count[i+1] == 0x07){
			
			ev[i].MainVolume = count[i]; 
			
			ev[i+1].MainVolume =count[i+1];
			
			ev[i+2].MainVolume =count[i+2];
			
			printf("the eevnt of Main Volume is %x %x ",count[i] , count[i]);
			printf("\n");
					}
					
		if(count[i] >= 0xb0 && count[i] <= 0xb9 && count[i+1] == 0x08){
			
			ev[i].Balance =count[i];
			
			ev[i+1].Balance =count[i+1] ;
			
			ev[i+2].Balance =count[i+2];
			
			printf("the event of Balance is %x %x ",count[i] , count[i+1]);
			printf("\n");
			
		}
		
		if(count[i] >= 0xb0 && count[i] <= 0xb9 && count[i+1] == 0x0a){
			
			ev[i].Pan = count [i];
			
			ev[i+1].ModulationWheel = count [i+1];
			 
			 ev[i+2].Pan = count[i+2];
			 
			 printf("the event of Pan is %x %X ",count[i], count[i+1]);
			 printf("\n");
			 			
		}
		
		if(count[i] >= 0xb0 && count[i] <= 0xb9 && count[i+1] == 0x0b){
			
			ev[i].ExpressionController = count[i];
			 
			ev[i+1].ExpressionController = count[i+1]; 
			
			ev[i+2].ExpressionController = count[i+2];
			
			printf("the event of Expression Controller is %x %x ",count[i] , count[i+1]);
			printf("\n");
		
		}
		
		if(count[i] >= 0xb0 && count[i] <= 0xb9 && count[i+1] == 0x0c){
			
			ev[i].EffectControl1 = count[i] ;
			
			ev[i+1].EffectControl1 =count [i+1];
			
            ev[i+2].EffectControl1 =count[i+2];
			
			printf("the event of Effect Control 1 is %x %x ",count[i] , count[i+1]);
			printf("\n");		
		
		}
		
		if(count[i] >= 0xb0 && count[i] <= 0xb9 && count[i+1] == 0x0d){
			
			ev[i].tEffectControl2 = count[i] ;
			
			ev[i+1].tEffectControl2 = count[i+1];
			
			ev[i+2].tEffectControl2 =count[i+2];
			
			printf("the event of Effect Control 2 is %x %x ",count[i], count[i+1]);
			printf("\n");
			
		}
		
		if(count[i] >= 0xb0 && count[i] <= 0xb9 && count[i+1] == 0x10){
			
			ev[i].GeneraPurposeController1 =count[i] ;
			
			ev[i+1].GeneraPurposeController1 =count[i=1];
			
			ev[i+2].GeneraPurposeController1 =count[i+2];
			
			printf("the event of General-Purpose Controllers 1 is %x %x ",count[i], count[i+1]);
			printf("\n");
			
		}
		
		if(count[i] >= 0xb0 && count[i] <= 0xb9 && count[i+1] == 0x11){
			
			ev[i].tGeneralPurposeControllers2 =count[i];
			
			ev[i+1].tGeneralPurposeControllers2 =count[i+1];
			
			ev[i+2].tGeneralPurposeControllers2 =count[i+2];
			
			printf("the event of General-Purpose Controllers 2 is %x %x ",count[i] , count[i+1]);
			
	
		}
		
		if(count[i] >= 0xb0 && count[i] <= 0xb9 && count[i+1] == 0x12){
			
			ev[i].t1GeneralPurposeControllers3 = count[i] ;
			
			ev[i+1].t1GeneralPurposeControllers3= count[i+1] ;
			
			ev[i+2].t1GeneralPurposeControllers3 =count[i+2] ;
			
			printf("the event of General-Purpose Controllers 3 is %x %x ",count[i], count[i+1]);
			printf("\n");
		}
		
		if(count[i] >= 0xb0 && count[i] <= 0xb9 && count[i+1] == 0x13){
			
			ev[i].t2GeneralPurposeControllers4 = count[i] ;
			
			ev[i+1].t2GeneralPurposeControllers4 = count[i+1];
			
			ev[i+2].t2GeneralPurposeControllers4 =count[i+2] ;
			
			printf("the event of General-Purpose Controllers 4 is %x %x ",count[i], count[i+1]);
			printf("\n");
					}
					
		if(count[i] >= 0xb0 && count[i] <= 0xb9 && count[i+1] == 0x20){
			
			ev[i].LSBforcontrollers0 =count[i];
			
			ev[i+1].LSBforcontrollers0 =count[i+1];
			
			ev[i+2].LSBforcontrollers0 =count[i+2];
			
			printf("the event of LSB for controllers 0 is %x %x ",count[i] , count[i+1]);
			printf("\n");
			
		}		
		
		if(count[i] >= 0xb0 && count[i] <= 0xb9 && count[i+1] == 0x21){
			
			ev[i].tLSBforcontrollers1 =count[i] ;
			
			ev[i+1].tLSBforcontrollers1 =count[i+1]; 
			
			ev[i+2].tLSBforcontrollers1 =count[i+2] ;
			
			printf("the eventf of LSB for controllers 1 is %x %x ",count[i] , count[i+1]);
			printf("\n") ;
			
		}	
		
		if(count[i] >= 0xb0 && count[i] <= 0xb9 && count[i+1] == 0x22){
			
			ev[i].t1LSBforcontrollers2 =count[i] ;
			
			ev[i+1].t1LSBforcontrollers2 =count[i+1];
			
			ev[i+2].t1LSBforcontrollers2 =count[i+2];
			
			printf("the event of LSB for controllers 2 is %x %x ",count[i] ,count[i+1]);
			printf("\n");
		
		}
		
		if(count[i] >= 0xb0 && count[i] <= 0xb9 && count[i+1] == 0x23){
			
			ev[i].t2LSBforcontrollers3 = count[i] ;
			
			ev[i+1].t2LSBforcontrollers3 =count[i+1];
			
			ev[i+2].t2LSBforcontrollers3=count[i+2] ;
			
			printf("the event of LSB for controllers 3 is %x %x ",count[i], count [i+1]);
			printf("\n");			
			
		}
		
		if(count[i] >= 0xb0 && count[i] <= 0xb9 && count[i+1] == 0x24){
			
			ev[i].t3LSBforcontrollers4 =count[i];
			
			ev[i+1].t3LSBforcontrollers4 =count[i+1];
			
			ev[i+2].t3LSBforcontrollers4 =count[i+2];
			
			printf("the event of LSB for controllers 4 is %x %x ",count[i], count[i+1]);
			
		}
		if(count[i] >= 0xb0 && count[i] <= 0xb9 && count[i+1] == 0x25){
			
			ev[i].t4LSBforcontrollers5 =count[i] ;
			
			ev[i+1].t4LSBforcontrollers5 =count[i+1];
			
			ev[i+2].t4LSBforcontrollers5 =count[i+2];
			
			printf("the event of LSB for controllers 5 is %x %x ",count[i] ,count[i+1]);
			printf("\n");
			
		}
		
		if(count[i] >= 0xb0 && count[i] <= 0xb9 && count[i+1] == 0x31){
			
			ev[i].t4LSBforcontrollers5 =count[i] ;
			
			ev[i+1].t5LSBforcontrollers17 = count[i+1];
			
			ev[i+2].t5LSBforcontrollers17 =count[i+2];
			
			printf("the event of LSB for controllers 17 is %x %x ",count[i] ,count[i+1]);
			printf("\n");
		}
		if(count[i] >= 0xb0 && count[i] <= 0xb9 && count[i+1] == 0x32){
			ev[i].t6LSBforcontrollers18 = count[i ];
			
			ev[i+1].t6LSBforcontrollers18 =count[i+1];
			
			ev[i+2].t6LSBforcontrollers18 =count[i+2];
			
			printf("the event of LSB for controllers 18 is %x %x ",count[i], count[i+1]);
			printf("\n");
		}
		if(count[i] >= 0xb0 && count[i] <= 0xb9 && count[i+1] == 0x33){
			
			ev[i].t7LSBforcontrollers19 =count[i] ;
			
			ev[i+1].t7LSBforcontrollers19 =count[i+1];
			
			ev[i+2].t7LSBforcontrollers19 =count[i+2];
			printf("the event of LSB for controllers 19 is %x %x ",count[i] , count[i+2]);
			printf("\n") ;
			
		}
		if(count[i] >= 0xb0 && count[i] <= 0xb9 && count[i+1] == 0x34){
			ev[i].t8LSBforcontrollers20 =count[i];
			
			ev[i+1].t8LSBforcontrollers20 = count[i+1];
			
			ev[i+2].t8LSBforcontrollers20 = count[i+2];
			printf("the event of LSB for controllers 20 is %x %x ",count[i] ,count[i+1]);
			printf("\n");
		}
		if(count[i] >= 0xb0 && count[i] <= 0xb9 && count[i+1] == 0x35){
			ev[i].t9LSBforcontrollers21 = count[i] ;
			
			ev[i+1].t9LSBforcontrollers21=count[i+1];
			
			ev[i+2].t9LSBforcontrollers21 =count[i+2];
			printf("the event of LSB for controllers 21 is %x %x ",count[i] ,count[i+1]);
			printf("\n");
			
		}
		
		if(count[i] >= 0xb0 && count[i] <= 0xb9 && count[i+1] == 0x41){
			ev[i].Portamento = count[i] ;
			
			ev[i+1].Portamento =count[i+1];
			
			ev[i+2].Portamento =count[i+2];
			printf("the event of Portamento is %x %x ",count[i], count[i+1]);
			printf("\n");
		}
		if(count[i] >= 0xb0 && count[i] <= 0xb9 && count[i+1] == 0x42){
			ev[i].SostenatoPedal = count[i];
			
			ev[i+1].SostenatoPedal =count[i+1];
			
			ev[i+2].SostenatoPedal =count[i+2];
			printf("the event if Sostenato Pedal is %x %x ",count[i], count[i+1]);
			printf("\n");
		}
		if(count[i] >= 0xb0 && count[i] <= 0xb9 && count[i+1] == 0x43){
			ev[i].SoftPedal =count[i];
			  ev[i+1].SoftPedal = count[i+1] ;
			  ev[i+2].SoftPedal =count[i+2] ;
			  printf("the event of Soft Pedal is %x %x ",count[i] , count[i+1]);
			  printf("\n");
		}
		if(count[i] >= 0xb0 && count[i] <= 0xb9 && count[i+1] == 0x44){
			
			ev[i].LegatoFootswitch = count[i] ;
			
			ev[i+1].LegatoFootswitch =count[i+1];
			
			ev[i+2].LegatoFootswitch =count[i+2] ;
			
			printf("the event of Legato Footswitch is %x %x ",count[i], count[i+1]);
			printf("\n");
		}
		if(count[i] >= 0xb0 && count[i] <= 0xb9 && count[i+1] == 0x45){
			ev[i].Hold2=count[i] ;
			
			ev[i+1].Hold2 =count[i+1];
			
			ev[i+2].Hold2 =count[i+2];
			printf("thr event of Hold 2 is %x %x \n",count[i], count[i+1]);
				
		}
		if(count[i] >= 0xb0 && count[i] <= 0xb9 && count[i+1] == 0x46){
			ev[i].SoundController1 =count[i] ,
			
			ev[i+1].SostenatoPedal =count[i+1];
			
			ev[i+2].SostenatoPedal =count[i+2];
			
			printf("the event of Sound Controller 1 (default: Timber Variation)	 is %x %x \n");
		}
		if(count[i] >= 0xb0 && count[i] <= 0xb9 && count[i+1] == 0x47){
			ev[i].SoundController2 =count[i];
			 
			 ev[i+1].SoundController2 =count[i+1] ;
			 ev[i+2].SoundController2 =count[i+2];
			 
			 printf("the evnt of the Sound Controller 2 is %x %x \n");
		}
		if(count[i] >= 0xb0 && count[i] <= 0xb9 && count[i+1] == 0x54){
			ev[i].PortamentoControl =count[i] ;
			 ev[i+1].PortamentoControl =count[i+1];
			 ev[i+2].PortamentoControl =count[i+2] ;
			 printf("the event of Portamento Control is %x %x \n",count[i], count[i+1]);			
		}
		if(count[i] >= 0xb0 && count[i] <= 0xb9 && count[i+1] == 0x5b){
			ev[i].Effect1Depth =count[i] ;
			ev[i+1].Effect1Depth =count[i+1];
			ev[i+2].EffectControl1 =count[i+2];\
			printf("the event of Effects 1 Depth is %x %x  \n",count[i] ,count[i+1])	;		
		}
		if(count[i] >= 0xb0 && count[i] <= 0xb9 && count[i+1] == 0x5c){
			ev[i].Effects2Depth =count[i] ;
			
			ev[i+1].Effects2Depth =count[i+1];
			
			ev[i+2].Effects2Depth =count[i+1];
			printf("the event of Effects 2 Depth is %x %x \n",count[i], count[i+1]);
			
		}
		if(count[i] >= 0xb0 && count[i] <= 0xb9 && count[i+1] == 0x60){
			ev[i].DataIncrement =count[i];
			ev[i+1].DataIncrement =count[i+1];
			ev[i+2].DataIncrement =count[i+2];
			printf("the event is Data Increment is %x %x \n",count[i],count[i+1]);
			
		}
		if(count[i] >= 0xb0 && count[i] <= 0xb9 && count[i+1] == 0x62)
{
	ev[i].NonRegisteredParameterNumber =count[i];
	
	ev[i+1].NonRegisteredParameterNumber =count[i+1];
	
	ev[i+2].NonRegisteredParameterNumber =count[i+2];
	
	printf("the events of Non-Registered Parameter Number  is %x %x \n",count[i], count[i+1]);
	
		}		
	
	if(count[i] >= 0xb0 && count[i] <= 0xb9 && count[i+1] == 0x64){
		ev[i].RegisteredParameterNumber =count[i]; 
		
		ev[i+1].RegisteredParameterNumber =count[i+1];
		
		ev[i+2].RegisteredParameterNumber =count[i+2];
		
		printf("the events of Registered Parameter Number  is %x %x \n",count[i], count[i+1]);
		
	}	
	if(count[i] >= 0xb0 && count[i] <= 0xb9 && (count[i+1] == 0x79 || count[i+1] == 0x7a || count[i+1] == 0x7b || count[i+1] == 0x7c || count[i] == 0x7d || count[i] == 0x7e || count[i] == 0x7f)){
		
		ev[i].ModeMessages =count[i];
		
		ev[i+1].ModeMessages =count[i+1];
		
		ev[i+2].ModeMessages = count[i+2]; 
		
		printf("the events of Mode Messages is %x %x \n",count[i], count[i+1]);
		
	}	
		
	if(count[i] == 0xff && count[i+1] == 0x2f ){
		
		meta[i].endofthetrack =count[i];
		
		meta[i+1].endofthetrack =count[i+1];
		
		printf("end of the track");
		printf("\n");
		
	}
	if(count[i] == 0xff && count[i+1] == 0x00  ){
		
		meta[i].SequenceNumber = count[i];
		
		meta[i+1].SequenceNumber =count[i+1];
		
		printf("Sequence Number");
		printf("\n");
	}
		
	if(count[i] == 0xff && count[i+1] == 0x01){
		meta[i].TextEvent = count[i];
		
		meta[i+1].TextEvent =count[i+1];
		
		printf("Text Event");
		printf("\n");
	}	
	if( count[i] == 0xff && count[i+1] ==0x02 ){
		meta[i].CopyrightNotice ==count[i] ;
		
		meta[i+1].CopyrightNotice == count[i+1];
		printf("Copyright Notice");
		printf("\n");
		
	}
	if(count[i] == 0xff && count[i+1] == 0x03){
	
	meta[i].SequenceTrackName =count[i] ;
	
	meta[i+1].SequenceTrackName == count[i+1];
	
	printf("Sequence/Track Name");
	printf("\n");	
	}
	if(count[i] == 0xff && count[i+1] == 0x04){
		
		meta[i].InstrumentName =count[i] ;
		
		meta[i+1].InstrumentName = count[i+1];
		printf("Instrument Name");
		printf("\n");
	}
	
	if(count[i] == 0xff && count[i+1] == 0x05 ){
		
		meta[i].Lyric =count[i] ;
		meta[i+1].Lyric = count[i+1];
		printf("Lyric");
		printf("\n");
	}
	if(count[i] == 0xff && count[i+1] == 0x06){
		meta[i].Marker = count[i] ;
		meta[i+1].Marker = count [i+1]  ;
		printf("Marker");
		printf("\n");
	}
	if(count[i] == 0xff && count[i+1] == 0x07){
		
		meta[i].CuePoint =count[i] ;
		meta[i+1].CuePoint = count[i+1] ;
		printf("Cue Point");
		printf("\n");
	}
	if(count[i] == 0xff && count[i+1] == 0x20){
		meta[i].MIDIChannelPrefix = count[i] ;
		meta[i+1].MIDIChannelPrefix = count[i+1];
		printf("MIDI Channel Prefix");
		printf("\n");
	}
	if(count[i] == 0xff && count[i+1] == 0x51){
		meta[i].SetTempoinmicrosecondsperquarternote = count[i] ;
		meta[i+1].SetTempoinmicrosecondsperquarternote =count[i+1]  ;
		printf("Set Tempo in microseconds per quarter note  : ");
		printf("%x %x %x  ",count[i+3] , count[i+4] , count[i+5]);
		
	printf("\n");
		}
	if(count[i] == 0xff && count[i+1] == 0x54){
		
		meta[i].SMPTEOffset = count[i] ;
		meta[i+1].SMPTEOffset = count[i+1] ;
		printf("SMPTE Offset") ;
		printf("\n");
	}
	if(count[i] == 0xff && count[i+1] == 0x54){
		meta[i].TimeSignature =count[i] ;
		meta[i+1].TimeSignature =count[i+1]  ;
		printf("Time Signature") ;
		printf("\n") ;
	}
	if(count[i] == 0xff && count[i+1] == 0x59 ){
		meta[i].KeySignature = count[i] ;
		meta[i+1].KeySignature =count[i+1]  ;
		printf("Key Signature") ;
		printf("\n");
	}
	if(count[i] == 0xff && count[i+1] == 0x7f ){
		meta[i].SequencerSpecifiMetaEvent =count[i] ;
		meta[i+1].SequencerSpecifiMetaEvent =count[i+1];
		printf("Sequencer Specific Meta Event");
		printf("\n");
	}
	//end of the events 
		
	}//end of the (if) of the events
}







float h(char * g){

	if(strcmp(g ,"C0" )==0) return 16.35 ;
	else  if (strcmp(g , " Cs0"  )==0) return  17.32  ; 
	    
	else  if (strcmp(g ,"D0"  )==0) return   18.35 ;   
	
	else  if (strcmp(g , "Ds0" )==0) return  19.45  ;  
	 
	else  if (strcmp(g , "E0" )==0) return  20.60  ;   
	
	else  if (strcmp(g , "F0" )==0) return  21.83  ;   
	
	else  if (strcmp(g , "Fs0" )==0) return 23.12   ;  
	 
    else  if (strcmp(g , "G0" )==0) return  24.5  ;   
    
    else  if (strcmp(g , "Gs0" )==0) return  16.35  ;   
    
	else  if (strcmp(g ,"A0"  )==0) return  27.5  ;   
	
	else  if (strcmp(g , "As0" )==0) return  29.14  ;  
	 
	else  if (strcmp(g ,"B0"  )==0) return  30.87  ;   
	
	else  if (strcmp(g ,"C1"  )==0) return 32.7   ;  
	 
	else  if (strcmp(g , "Cs1" )==0) return 34.65   ;  
	 
	else  if (strcmp(g ,"D1"  )==0) return  36.71  ;  
	 
	else  if (strcmp(g ,"Ds1"  )==0) return  38.89  ;  
	  
	else  if (strcmp(g , "E1" )==0) return  41.2  ;  
	 
	else  if (strcmp(g , "F1" )==0) return  43.65  ;   
	
	else  if (strcmp(g ,"Fs1"  )==0) return  46.25  ;   
	
	else  if (strcmp(g ,"G1"  )==0) return  49  ;   
	
	else  if (strcmp(g , "Gs1" )==0) return  51.91  ;  
	 
	else  if (strcmp(g ,"A1"  )==0) return 55   ; 
	  
	else  if (strcmp(g , "As1" )==0) return 58.27   ;   
	
	else  if (strcmp(g , "B1" )==0) return 61.74    ; 
	  
	else  if (strcmp(g ,"C2"  )==0) return  65.41  ;   
	
	else  if (strcmp(g ,"Cs2"  )==0) return  69.30   ;  
	 
	else  if (strcmp(g , "D2" )==0) return  73.42  ;   
	
	else  if (strcmp(g ,"Ds2"  )==0) return   77.78 ;   
	
	else  if (strcmp(g ," E2"  )==0) return 82.41   ;  
	 
	else  if (strcmp(g , "F2" )==0) return   87.31 ;   
	
	else  if (strcmp(g , "Fs2" )==0) return  92.5  ;   
	
	else  if (strcmp(g , "G2" )==0) return 98   ;   
	
	else  if (strcmp(g , "Gs2" )==0) return  103.83  ; 
	  
	else  if (strcmp(g , "A2" )==0) return  110  ;   
	
	else  if (strcmp(g , "As2" )==0) return  116.54  ;  
	 
	else  if (strcmp(g , "B2" )==0) return  123.47  ;   
	
	else  if (strcmp(g , "C3" )==0) return   130.81 ;   
	
	else  if (strcmp(g , "Cs3" )==0) return  138.59  ;  
	 
	else  if (strcmp(g , "D3" )==0) return  146.83  ;   
		
	else  if (strcmp(g , "Ds3" )==0) return  155.56  ;  
	 
	else  if (strcmp(g , "E3" )==0) return 164.81   ;   
	
	else  if (strcmp(g ,"F3"  )==0) return  174.61  ;  
	 
	else  if (strcmp(g ,"Fs3"  )==0) return  185  ;   
	
	else  if (strcmp(g ,"G3"  )==0) return 196   ;   
	
	else  if (strcmp(g ,"Gs3"  )==0) return  207.65  ;   
	
	else  if (strcmp(g ,"A3"  )==0) return  220  ;   
	
	else  if (strcmp(g , "As3" )==0) return  233.08  ;   
	
	else  if (strcmp(g , "B3" )==0) return  246.94  ;  
	
	else  if (strcmp(g , "C4" )==0) return   261.63 ;  
	
	else  if (strcmp(g ,"Cs4"  )==0) return  277.18  ;  
	
	else  if (strcmp(g ,"D4"  )==0) return  293.66  ;  
	
	else  if (strcmp(g , "Ds4" )==0) return  311.13  ;  
	
	else  if (strcmp(g , "E4" )==0) return  329.63  ;  
	
	else  if (strcmp(g , "F4" )==0) return  349.23  ; 
	 
	else  if (strcmp(g , "Fs4" )==0) return 369.99   ; 
	 
	else  if (strcmp(g ,"G4"  )==0) return  392  ;  
	
	else  if (strcmp(g , "Gs4" )==0) return  415.30  ; 
	 
	else  if (strcmp(g ,"A4"  )==0) return  440  ;  
	
	else  if (strcmp(g , " As4" )==0) return   416.66 ; 
	 
	else  if (strcmp(g , "B4" )==0) return  493.88  ;  
	
	else  if (strcmp(g , "C5" )==0) return  523.25   ;  
	
	else  if (strcmp(g ,"Cs5"  )==0) return  554.37  ;  
	
	else  if (strcmp(g , "D5" )==0) return 587.33    ;  
	
	else  if (strcmp(g , "Ds5" )==0) return  622.25  ; 
	 
	else  if (strcmp(g ,"E5"  )==0) return  659.25  ; 
	 
	else  if (strcmp(g , "F5" )==0) return   698.46 ;  
	
	else  if (strcmp(g , "G5" )==0) return 783.77   ; 
	 
	else  if (strcmp(g ,"Gs5"  )==0) return 830.61   ;
	  																					
	else  if (strcmp(g , " A5" )==0) return 880   ; 
	
	else  if (strcmp(g , "As5 " )==0) return 932.33   ; 
	
	else  if (strcmp(g ,"B5"  )==0) return  987.77  ; 
	
	else  if (strcmp(g ,"C6"  )==0) return  1046.5  ; 
	
	else  if (strcmp(g ,"Cs6"  )==0) return  1108.73  ;
	 
	else  if (strcmp(g , "D6" )==0) return  1174.66  ; 
	
	else  if (strcmp(g , "Ds6" )==0) return  1244.51  ;
	 
	else  if (strcmp(g ,"E6"  )==0) return 1318.51   ; 
	
	else  if (strcmp(g , "F6" )==0) return 1396.91   ; 
	
	else  if (strcmp(g ,"Fs6"  )==0) return   1499.78 ;
	
	else  if (strcmp(g ," G6"  )==0) return  1569.98  ; 
	
	else  if (strcmp(g ," Gs6"  )==0) return 1661.26   ;
	 
	else  if (strcmp(g , "A6" )==0) return 1760   ; 
	
	else  if (strcmp(g ," As6"  )==0) return 1846.66   ; 
	
	else  if (strcmp(g ,"B6"  )==0) return   1975.53 ;
	
	else  if (strcmp(g , "C7" )==0) return 2093   ;
	
	else  if (strcmp(g , "Cs7" )==0) return  2217.43  ;
	
	else  if (strcmp(g , "D7" )==0) return  2349.32  ;
	
	else  if (strcmp(g ,"Ds7"  )==0) return  2489.02  ;
	
	else  if (strcmp(g ,"E7"  )==0) return  2637.02 ;
	
	else  if (strcmp(g , "F7" )==0) return  2793.87  ;
	
	else  if (strcmp(g , "Fs7" )==0) return  2959.96  ;
	
	else  if (strcmp(g , "G7" )==0) return  3135.96  ;
	
	else  if (strcmp(g ,"Gs7"  )==0) return  3322.44  ;
	
	else  if (strcmp(g , "A7" )==0) return 3520   ;
	
	else  if (strcmp(g , "As7" )==0) return 3729.31   ;	
																																																
	else  if (strcmp(g , "B7" )==0) return 3951.07   ;
	
	else  if (strcmp(g , "C8" )==0) return 4671.01   ;
	
	else  if (strcmp(g , "Cs8" )==0) return 4434.92   ;
	
	else  if (strcmp(g , " D8" )==0) return 4698.63   ;
	
	else  if (strcmp(g , "Ds8" )==0) return   4978.03 ;
	
	else  if (strcmp(g , " F8" )==0) return 5587   ;
																							
	else  if (strcmp(g , "Fs8" )==0) return 5919.91   ;
	
	else  if (strcmp(g , "G8" )==0) return 6271.93   ;
	
	else  if (strcmp(g , "Gs8" )==0) return  6644.88  ;
	
	else  if (strcmp(g , "Fs5" )==0) return 739.99   ;
	
	else  if (strcmp(g , "E8" )==0) return 5274.04   ;
	
	
	
}






int faz4(){
	char g1[97][4],y[97][4];
	float l[97],u[97];
	int i,j,v,o,r;
	for(v=0;v<=96;v++){
	scanf("%f",&u[v]);
}
	
for(i=0;i<=96;i++){
scanf("%s",&g1[i]);
}


printf("%s",g1[8]);


for(j=0;j<=96;j++){
	
	l[j]=h(g1[j]);
}
	for(r=0;r<=96;r++){
		Beep(l[r],u[r]);
	}
	
	
	
}

