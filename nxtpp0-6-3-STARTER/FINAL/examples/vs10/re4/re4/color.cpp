//we made assumption that LEGO color sensor is connected to port IN_3
//example prepared by artem, http://wmii.uwm.edu.pl/~artem
#include "NXT++.h"
#include <conio.h>

Comm::NXTComm comm;

int main()
{
 std::cout << "\naquiring signal ... ";
 int pointer=0;
 if(NXT::OpenBT(&comm))/*initialize the NXT via cable or bluetooth and continue if it succeeds*/
  {
   pointer=1;
   std::cout<< "signal found";
   std::cout<<"\nbattery Level = "<<NXT::BatteryLevel(&comm)/100<<" percent";
   NXT::StartProgram(&comm,"ExemplaryProgram");

   //declaration of variables
   int color;
   char decColor;
   char temp_choice='o';    
   do
	{//the beginning of infinity loop
	std::cout<<"\n\n -----------------------------------------";
	std::cout<<"\n color sensor, commands:";
	std::cout<<"\n press r - to get a red color intensity";
    std::cout<<"\n press g - to get a green color intensity";
	std::cout<<"\n press b - to get a blue color intensity";
	std::cout<<"\n press n - to get a light intensity";
	std::cout<<"\n press f - to detect the full color, considering only:"; 
	std::cout<<"\n           black, blue, green, yellow, red and white)";
	std::cout<<"\n press q - to turn off the sensor\n";	   
    decColor=getch();
	//The first initiation of sensor is delayed by 0.3s, the following condition let to avoid delays in reading.
	if(decColor!=temp_choice)
	 {
	  NXT::Sensor::SetColor(&comm, IN_3, decColor);
	  temp_choice=decColor;
     }
     color=NXT::Sensor::GetValue(&comm, IN_3);
	 if(decColor=='F' || decColor=='f' || decColor=='d')
	   {
	    std::cout<<"\n\nIt looks like ";
		if(color==1){std::cout<<"black\n";}
		if(color==2){std::cout<<"blue\n";}
		if(color==3){std::cout<<"green\n";}
		if(color==4){std::cout<<"yellow\n";}
		if(color==5){std::cout<<"red\n";}
		if(color==6){std::cout<<"white\n";}
    	//NXT::Sensor::SetColor(&comm, IN_3, 'n');
	    }
	  if(decColor=='R' || decColor=='r'){std::cout<<"\nRed light intensity = "<<color;}
	  if(decColor=='G' || decColor=='g'){std::cout<<"\nGreen light intensity = "<<color;}
	  if(decColor=='B' || decColor=='b'){std::cout<<"\nBlue light intensity = "<<color;}
	  if(decColor=='N' || decColor=='n'){std::cout<<"\nLight intensity = "<<color;}
	  if(decColor=='Q' || decColor=='q'){NXT::Sensor::SetColorOff(&comm, IN_3);}
	}//the end of infinity loop 
    while(decColor!='q' && decColor!='Q');
	std::cout<<"\n\nprogram is shutting down";
	NXT::StopProgram(&comm);
  }
	NXT::Close(&comm); //close the NXT
	if(pointer==0){std::cout<<"\n\ncommunication with NXT brick failed";Wait(3000);}
	return 0;
}