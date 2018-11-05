#include "NXT++.h"
#include <iostream>
#include <conio.h>
#include <cmath>
using namespace std;
using namespace NXT;

Comm::NXTComm comm;

/*//PRZED U¯YCIEM SPRZETU DOK£ADNIE SPRAWDZAMY: 
//DO KTÓRYCH PORTÓW WEJŒCIOWYCH (IN) POD£¥CZONE S¥ SENSORY,\
//DO KTÓRYCH PORTÓW WYJŒCIOWYCH (OUT) POD£¥CZONE S¥ SERVO-MOTORY,
//STARAMY SIÊ PISAC KOD Z MO¯LIWOŒCI¥ ZATRZYMANIA ROBOTA W KA¯DEJ CHWILI,
//ROBOT POWIENIEN BYC PRZEMIESZCZONY W MIEJSCE TESTÓW ZA POŒREDNICTWEM ZDALNEGO STEROWANIA,*/

int main()
{
	srand(time(NULL));

	cout << "Szukanie sygnalu... to moze zajac chwile.\n";
	if(NXT::OpenBT(&comm)) //initialize the NXT and continue if it succeeds
	{
		cout<< "Sygnal znaleziony!";
		cout<<"\nPoziom baterii = "<<NXT::BatteryLevel(&comm);
		cout<<"\nDostepna pamiec flash = "<<NXT::GetAvailableFlash(&comm);
		
		int x=30;//szybkoœæ jazdy w przód i ty³
		int xtemp=30;//potrzebna do sprawdzania czy predkosc sie zmienila

		int y=20;//szybkoœæ obrotu w lewo, prawo
		int ytemp=20;//potrzebna do sprawdzania czy predkosc sie zmienila

		char last_value;//zapamietana ostatnia instrukcja steruj¹ca

        //Przed uzyciem sprawdzamy numer portu do którego jest podl¹czony sensor, 
		NXT::Sensor::SetTouch(&comm, IN_1);//inicjacja sensora dotyku

		//aktywacja czujnika koloru
		NXT::Sensor::SetColor(&comm,IN_3,'n');
		int color;

		//pocz¹tek programu
		NXT::StartProgram(&comm,"program1");

		//zmienna u¿ywana do sterowania
		char decyzja;

		cout<<"\n ___Podstawowe sterowanie do uzupelnienia___";
		cout<<"\n A - jazda w lewo"; 
		cout<<"\n D - jazda w lewo"; 
		cout<<"\n W - jazda na wprost"; 
		cout<<"\n S - jazda do tylu"; 
		cout<<"\n F - sledz linie (po lewej)"; 
		cout<<"\n L - sledz linie (po po prawej)"; 
		cout<<"\n H - Zatrzymanie silnikow";
		cout<<"\nK - Koniec Programu";

		do
		{
           //Przed uzyciem sprawdzamy numer portu do którego jest podl¹czony sensor, 
       /*
		if(NXT::Sensor::GetValue(&comm, IN_1)==1)
		    {
			for(int i=1;i<1000;i=i+10)
			 {
			 NXT::PlayTone(&comm, i, 1);
			 Wait(1);
			 }
		   }
		*/

		 if(kbhit()==true)
         {
            
		   decyzja=getch();
	
		   if(decyzja=='N' || decyzja=='n')
		   {
           x-=10; 
		   }

		   if(decyzja=='M' || decyzja=='m')
		   {
           x+=10; 
		   }

		   if(decyzja=='V' || decyzja=='v')
		   {
           y--; 
		   }

		   if(decyzja=='B' || decyzja=='b')
		   {
           y++; 
		   }
          //Przed uzyciem serwo sprawdzamy numer portu do którego jest podl¹czony,
		   if(decyzja=='A' || decyzja=='a' || (ytemp!=y && last_value=='a'))
		   {
		   ytemp=y;
		   last_value='a';
		   NXT::Motor::SetForward(&comm, OUT_B, y);
		   NXT::Motor::SetReverse(&comm, OUT_C, y);
		   //cout<<"SonarValue = "<<NXT::Sensor::GetSonarValue(&comm, IN_4);
		   }

		  //Przed uzyciem serwo sprawdzamy numer portu do którego jest podl¹czony,
		  if(decyzja=='D' || decyzja=='d' || (ytemp!=y && last_value=='d'))
		   {
		   ytemp=y;
		   last_value='d';
		   NXT::Motor::SetReverse(&comm, OUT_B, y);
		   NXT::Motor::SetForward(&comm, OUT_C, y);
		   }

		   //Przed uzyciem serwo sprawdzamy numer portu do którego jest podl¹czony,
		  if(decyzja=='W' || decyzja=='w' || (xtemp!=x && last_value=='w'))
		   {
		    xtemp=x;
		    last_value='w';
		    NXT::Motor::SetForward(&comm, OUT_B, x);
		    NXT::Motor::SetForward(&comm, OUT_C, x);
		   }

          //Przed uzyciem serwo sprawdzamy numer portu do którego jest podl¹czony,
		  if(decyzja=='S' || decyzja=='s'  || (xtemp!=x && last_value=='s'))
		  {
		   xtemp=x;
		   last_value='s';
		   NXT::Motor::SetReverse(&comm, OUT_B, x);
		   NXT::Motor::SetReverse(&comm, OUT_C, x);
		  }

          //Przed uzyciem serwo sprawdzamy numer portu do którego jest podl¹czony,
		  if(decyzja=='H' || decyzja=='h')
		  {
		   NXT::Motor::SetForward(&comm, OUT_B, 0);
		   NXT::Motor::SetForward(&comm, OUT_C, 0);
		   NXT::Motor::Stop(&comm, OUT_B, 0);
		   NXT::Motor::Stop(&comm, OUT_C, 0);
		  }
       
		  //Przed uzyciem serwo sprawdzamy numer portu do którego jest podl¹czony,
		  if(decyzja=='K' || decyzja=='k')
		  {
			NXT::Motor::Stop(&comm, OUT_B, 0);
		    NXT::Motor::Stop(&comm, OUT_C, 0);
			NXT::Motor::Stop(&comm, OUT_A, 0);
			NXT::Sensor::SetSonarOff(&comm, IN_1);			
			NXT::Sensor::SetColorOff(&comm,IN_3);

			break;
		  }

		  if (decyzja=='F' || decyzja=='f') //linia po prawej
		  {
			  last_value = 'f';
			  while (true){
				  if (kbhit() == true) 
				  {
					  decyzja = getch();
					  if (decyzja == 'h' || decyzja == 'H')
					  {
						  last_value = 'h';
						  NXT::Motor::SetForward(&comm, OUT_B, 0);
							NXT::Motor::SetForward(&comm, OUT_C, 0);
						NXT::Motor::Stop(&comm, OUT_B, 0);
						NXT::Motor::Stop(&comm, OUT_C, 0);
						  break;
					  }
				  }
				color=NXT::Sensor::GetValue(&comm,IN_3);
				  int left, right;
			  if (color <= 60)
			  {
				  
				  NXT::Motor::SetForward(&comm, OUT_B, 2*y);
				  NXT::Motor::SetForward(&comm, OUT_C, y/2);
			  }
			  else if (color <= 105 && color > 150)//color > 60)
			  {
				  left = 2*y* (1 - (color - 60)/90); //150-60=90 <- MAX - MIN
				  right = 2*y - left;
			      NXT::Motor::SetForward(&comm, OUT_B, left);
			      NXT::Motor::SetForward(&comm, OUT_C, right);
			  }
			  else
			  {
				  NXT::Motor::SetForward(&comm, OUT_B, y/2);
				  NXT::Motor::SetForward(&comm, OUT_C, 2*y);
			  }
			  }
			  
			 
		  }

		  if (decyzja == 'l' || decyzja == 'L')
		  {
			  last_value = 'l';
			  while (true){
				  if (kbhit() == true) 
				  {
					  decyzja = getch();
					  if (decyzja == 'h' || decyzja == 'H')
					  {
						  last_value = 'h';
						  NXT::Motor::SetForward(&comm, OUT_B, 0);
							NXT::Motor::SetForward(&comm, OUT_C, 0);
						NXT::Motor::Stop(&comm, OUT_B, 0);
						NXT::Motor::Stop(&comm, OUT_C, 0);
						  break;
					  }
				  }
				color=NXT::Sensor::GetValue(&comm,IN_3);
				  int left, right;

				  if (color <= 60)
				  {
					  NXT::Motor::SetForward(&comm, OUT_B, y/2);
					  NXT::Motor::SetForward(&comm, OUT_C, 2*y);
				  }
				  else if (color <= 105 && color > 150)
				  {
					  left = 2*y* (1 - (color - 60)/90); //150-60=90 <- MAX - MIN
				  right = 2*y - left;
			      NXT::Motor::SetForward(&comm, OUT_B, right);
			      NXT::Motor::SetForward(&comm, OUT_C, left);
				  }
				  else
				  {
					  NXT::Motor::SetForward(&comm, OUT_B, 2*y);
				  NXT::Motor::SetForward(&comm, OUT_C, y/2);
				  }
			  }
		  }
		 
			
          //Przed uzyciem sprawdzamy numer portu do którego jest podl¹czony sensor, 
		  if(decyzja=='U' || decyzja=='u')
		   {
		    NXT::Sensor::SetSonar(&comm, IN_1);
		    cout<<"\nWskazanie kompasu = "<<NXT::Sensor::GetSonarValue(&comm, IN_1);
		    NXT::Sensor::SetSonarOff(&comm, IN_1);
		   }

		  //Przed uzyciem sprawdzamy numer portu do którego jest podl¹czony sensor, 
		  if(decyzja=='C' || decyzja=='c')
		   {
			 color=NXT::Sensor::GetValue(&comm,IN_3);
			 Wait(50) ;
			 cout<<"\nNasycenie swaitla = "<<color;
		   }

            continue;
		 }
		}while(decyzja!='k' && decyzja!='K');

		NXT::StopProgram(&comm);
		
	}
	NXT::Close(&comm); //close communication with NXT

	cout<<"\n\nPress ENTER to close program";
	getchar();

	return 0;
}








//opcje dotyczace Mindstorm NXT v. 1.0

//if(decyzja=='L' || decyzja=='l')
// {
//  NXT::Sensor::SetLight(&comm, IN_3, 1);
//  Wait(50);
//  cout<<"LightValue = "<<NXT::Sensor::GetValue(&comm, IN_3);
//  Wait(50);
//  NXT::Sensor::SetLight(&comm, IN_3, 0);
// }

 //if(decyzja=='O' || decyzja=='o')
// {
// NXT::Sensor::SetSound(&comm, IN_2);
// Wait(50);
// cout<<"SoundValue = "<<NXT::Sensor::GetValue(&comm, IN_2);
// }
/**/