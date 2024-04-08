//erstes Programm
//#include <iostream>
//#include <math.h>
using namespace std; //sonst std:: vor cout und endl nötig //->wird von debuger nicht erkannt => auf C eingestellt?

int main(){
    double temp=0;
    unsigned short convMask=0,bin=0;;
    unsigned short data=0x13;

    //Binär in Dez
    for(int i = 0;i<16;i++){
        int produkt=1;
        convMask=1<<i;//wandert von LSB zu MSB
        bin=(data&convMask)>>i;
        for(int k= 0;k<i;k++){//pow(bin*2,i)
            produkt*=(bin*2);//Binärstellen auf summieren
        }
        temp+=produkt;
    }
    //mit *0.125 Dez in Grad wandeln
    temp*=0.125;

    
    //cout << "temp " << temp << endl;
}
//Kompelieren mit: g++ test.cpp -o test 