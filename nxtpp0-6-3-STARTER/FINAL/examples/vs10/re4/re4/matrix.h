#include <iostream>
#include <sstream>
#include <string>
#include <stdexcept>
using namespace std;

 
//******************************************************************** 
 //funkcja zapisywania informacji z tablicy do pliku tekstowego;
inline void zapis(unsigned int rows , unsigned int cols , std::string **tablica,const char* str)
{
//cout <<"\nZapisywanie macierzy Ga do pliku";
 std::string __str(str);
// __str += ".tab";
      std::ofstream plik2(__str.c_str());
      
      for (unsigned int i=1; i<rows+1; i++) 
      {  
           for(unsigned int j=1; j<cols+1; j++) 
           {
               plik2 << tablica[i][j];
               
               if(j<cols)
                 {   
                  plik2 << " ";
                 }
           }
       if(i<rows)
         {    
          plik2 <<std::endl; 
         }
      }
//cout <<"... zapisano jako "<<__str<<"\n\n";
plik2.close();
}


//******************************************************************** 
 //funkcja zapisywania informacji z tablicy do pliku tekstowego;
inline void zapis_double(unsigned int rows , unsigned int cols , double **tablica,const char* str)
{
//cout <<"\nZapisywanie macierzy Ga do pliku";
 std::string __str(str);
 __str += ".txt";
      std::ofstream plik2(__str.c_str());
      
      for (unsigned int i=1; i<rows+1; i++) 
      {  
           for(unsigned int j=1; j<cols+1; j++) 
           {
               plik2 << tablica[i][j]<<" ";
           }
       plik2 <<std::endl; 
      }
//cout <<"... zapisano jako "<<__str<<"\n\n";
plik2.close();
}

//******************************************************************** 
 //funkcja zapisywania informacji z tablicy do pliku tekstowego;
inline void zapis_double2(unsigned int rows , unsigned int cols , double tablica,const char* str)
{
//cout <<"\nZapisywanie macierzy Ga do pliku";
 std::string __str(str);
 __str += ".txt";
      std::ofstream plik2(__str.c_str());
      
      for (unsigned int i=1; i<rows+1; i++) 
      {  
           for(unsigned int j=1; j<cols+1; j++) 
           {
               plik2 << tablica[i][j]<<" ";
           }
       plik2 <<std::endl; 
      }
//cout <<"... zapisano jako "<<__str<<"\n\n";
plik2.close();
}

//******************************************************************** 
 //funkcja zapisywania informacji z tablicy trojwymiarowej do pliku tekstowego;
inline void zapis_3_wymiar(unsigned int dim1,unsigned int dim2 , unsigned int dim3 , float tablica [][102][3],const char* str)
{
      std::ofstream plik5(str);
      
   for(unsigned int i=0;i<dim1+1;i++)
    {
      for (unsigned int j=1;j<dim2+1;j++)
      {  
           for(unsigned int k=1;k<dim3+1;k++) 
           {
             plik5 <<tablica[i][j][k]<<" ";
           }
       plik5 <<std::endl; 
      }
    }
//cout <<"... zapisano jako "<<__str<<"\n\n";
plik5.close();
}



//******************************************************************** 
inline void wypisz_macierz_string(unsigned int rows , unsigned int cols , std::string **tablica)
{   
    //std::cout<<"\n";  
      for (unsigned int i=1; i<rows+1; i++) 
      {  
          //std::cout<<i<<" ";
           for(unsigned int j=1; j<cols+1; j++) 
           {
               //std::cout <<" "<< tablica[i][j];
           }
           //std::cout<<"\n";
      }
////getchar();
}

//******************************************************************** 
inline void wypisz_macierz_int(unsigned int rows , unsigned int cols , int **tablica)
{     
      for (unsigned int i=1; i<rows+1; i++) 
      {  
           for(unsigned int j=1; j<cols+1; j++) 
           {
               //std::cout <<" "<< tablica[i][j];
           }
           //std::cout<<"\n";
      }
////getchar();
}

//******************************************************************** 
//funkcja wczytywania informacji z pliku tekstowego do tablicy;
void wczytywanie(unsigned int rows, unsigned int cols, std::string **tablica, const char* str)
{
 std::string __str(str);
    std::ifstream plik(__str.c_str());
   
   //sprawdzanie czy otwierany plik istnieje
   if (!plik) {
        std::cerr << "Nie udalo sie otworzyc pliku do odczytu ";
              //std::cout <<""<<wsk;
              //getchar();   
    }
    //koniec sprawdzania czy otwierany plik istnieje;

    if (!plik.is_open())
    throw-1;   
//cout <<'\n'<<"Otwieranie pliku o nazwie "<<wsk<<"\n";
//cout <<"\npo nacisnieciu entera\n";
////getchar();
//cout << "Wczytuje:\n";
for ( unsigned int j=1;j<rows+1;j++)    
  {
//cout <<"\nx"<<j<<" = ";                      
    for ( unsigned int i=1;i<cols+1;i++) 
    {
         plik >> tablica[j][i];
         //std::cout <<" "<< tablica[j][i];
    }
//std::cout <<"\n";
  }  
//std::cout <<'\n'<<'\n';
plik.close();
}

//******************************************************************** 

//******************************************************************** 
//funkcja wczytywania informacji z pliku tekstowego do tablicy, nazwa wczytywanego pliku moze byc zmienna;
void wczytywanie2(unsigned int rows, unsigned int cols, std::string **tablica, const char* str)
{

 std::string __str(str);
 __str += ".txt";
      std::ifstream plik21(__str.c_str());
   
   //sprawdzanie czy otwierany plik istnieje
   if (!plik21) {
        std::cerr << "Nie udalo sie otworzyc pliku do odczytu ";
              //std::cout <<""<<__str.c_str();
              ////getchar();   
    }
    //koniec sprawdzania czy otwierany plik istnieje;

    if (!plik21.is_open())
    throw-1;   
//cout <<'\n'<<"Otwieranie pliku o nazwie "<<wsk<<"\n";
//cout <<"\npo nacisnieciu entera\n";
//////getchar();
//cout << "Wczytuje:\n";
for ( unsigned int j=1;j<rows+1;j++)    
  {
//cout <<"\nx"<<j<<" = ";                      
    for ( unsigned int i=1;i<cols+1;i++) 
    {
         plik21 >> tablica[j][i];
         std::cout <<" "<< tablica[j][i];
    }
    std::cout <<"\n";
  }  
std::cout <<'\n'<<'\n';
plik21.close();
}

//******************************************************************** 


//funkcja laczenia plikow tekstowych(tablic) i zapis do pliku;
void palacz_zapisz(unsigned int rows,unsigned int rows2 ,unsigned int cols,unsigned int cols2 ,std::string **tablica, std::string **tablica2,const char* str)
{
//cout <<"\nZapisywanie macierzy Ga do pliku";
//cout <<"\npo nacisnieciu entera\n";
////getchar(); 
 std::string __str(str);
 __str += ".tab";
      std::ofstream plik2(__str.c_str());
      
      for (unsigned int i=1; i<rows; i++) 
      {  
           for(unsigned int j=0; j<cols; j++) 
           {
               plik2 << tablica[i][j]<<"";
           }
       plik2 <<std::endl; 
      }
      
      for (unsigned int i=1; i<rows2; i++) 
      {  
           for(unsigned int j=0; j<cols2; j++) 
           {
               plik2 << tablica2[i][j]<<" ";
           }
       plik2 <<std::endl; 
      }
//cout <<"... zapisano jako "<<__str<<"\n\n";
 
plik2.close(); 
}

//******************************************************************** 
//funkcja tworzenia tablicy regul;
void zapis_tablicy_regul(unsigned int rows,unsigned int rows2 ,unsigned int cols,unsigned int cols2 ,std::string **tablica, std::string **tablica2,const char* str)
{
//cout <<"\nZapisywanie macierzy Ga do pliku";
//cout <<"\npo nacisnieciu entera\n";
////getchar(); 
//char *wsk = *string;
 std::string __str(str);
 __str += ".rul";
      std::ofstream plik2(__str.c_str());
      
      for (unsigned int i=1; i<rows; i++) 
      {  
           for(unsigned int j=0; j<cols; j++) 
           {
               plik2 << tablica[i][j]<<"";
           }
       plik2 <<std::endl; 
      }
      
      for (unsigned int i=1; i<rows2; i++) 
      {  
           for(unsigned int j=0; j<cols2; j++) 
           {
               plik2 << tablica2[i][j]<<"";
           }
       plik2 <<std::endl; 
      }
//cout <<"... zapisano jako "<<__str<<"\n\n";
plik2.close(); 
}

//******************************************************************** 
 //funkcja wypelnia tablice ustalonym znakiem;
inline void wypelnianie_tablicy_znakiem(unsigned int rows, unsigned int cols,std::string **tablica,const char x)
{
   //zaznaczanie tabl_reg
for(int i=1;i<rows;i++)
  {
   for(int j=1;j<cols;j++)
     {
     tablica[i][j]=x;              
     } 
   }  
}
//******************************************************************** 


//******************************************************************** 
//funkcja wczytywania informacji z pliku tekstowego do tablicy;
void wczytywanie_Tab1Wym(unsigned int rows, std::string *tablica, const char* str)
{
 std::string __str(str);
    std::ifstream plik(__str.c_str());
   
   //sprawdzanie czy otwierany plik istnieje
   if (!plik) {
        std::cerr << "Nie udalo sie otworzyc pliku do odczytu ";
    }
    //koniec sprawdzania czy otwierany plik istnieje;

    if (!plik.is_open())
    throw-1;   
//std::cout <<'\n'<<"Otwieranie pliku o nazwie "<<str<<"\n";
//std::cout <<"\npo nacisnieciu entera\n";
//getchar();
//std::cout << "Wczytuje:\n";
for ( unsigned int j=1;j<rows+1;j++)    
  {
//std::cout <<"\nx"<<j<<" = ";                      
         plik >> tablica[j];
         //std::cout <<" "<< tablica[j];
//std::cout <<"\n";
  }  
//std::cout <<'\n'<<'\n';
plik.close();
}

//******************************************************************** 

