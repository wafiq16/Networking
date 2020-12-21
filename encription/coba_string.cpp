#include <math.h>
#include <unistd.h> 
#include <stdio.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <string.h> 
#include <iostream>

using namespace std;

int main()
{
    string pesan;
    char input[99],output[99][99];
    long wafiq[99];
    // cin >> noskipws >> huda;
    // cin.getline(input,sizeof(input));
    // pesan = string(input);
    cin >> input;
    // const char *pesanku = pesan.c_str();

    char myData[99][3];
    for(int i = 0; input[i] != '\0';i++)
    {
        // sprintf(myData[i],"%d",input[i]);
        wafiq[i] = input[i];
        printf("waf[%d]\n",wafiq[i]);
        // cout << myData[i][j] << endl;
        // cout << wafiq << endl;    
    }
    // enkripsi pesan menggunakan rsa
    int p = 11,q = 13,n = p*q; // n = 21
    int m = (p-1)*(q-1); //m = 12
    int e = 7,d = 103;
    // e = GCD(12,7) = 1 // e = 7
    // d = (d * e) mod m = 1 // d = 15
    // d = (1 + (2*m))/e;
    // public key = (e,n) e = 7 n = 21
    // private key = (d,n) d = 15 n = 21
    long long int tampungValue[100]; 
    long long int hasil = 1,temp,buset;
    int z = 0;
    long int hasilEn[99],hasilDe[99],toDes[99];
    // cout << "dataawal = " << wafiq << " e = " << e << endl;
    // Proses Enkripsi (X) //  C = A ^ e mod n 	 
    // Proses Dekripsi (Y) //  Y = C ^ d mod n
    for(int i=0 ; wafiq[i] != '\0'; i++){
        // for(int j=0; j<3; j++){
            // printf("\nwafiq  = %d \n",wafiq[i]); 
            temp = wafiq[i] - 96;
            // printf("\ntemp  = %d \n", temp);
            hasil = 1;
            while(z<e)
            {
                hasil = hasil*temp;
                // cout << "hasil = " << hasil << endl;
                tampungValue[i] = hasil % n;
                z++;
                // cout << "hasil = " << hasil << " wafiq = " << wafiq[i] << endl;
                // cout << "tampung = " << tampungValue[i] << endl;
            }
            z=0;
            // cout << "tamp = "<< tampungValue[i] << endl;
            toDes[i] = tampungValue[i];
            hasilEn[i] = tampungValue[i] + 96;       
            // cout << "hasilEn = "<< hasilEn[i] << endl;
            // if(j>0){
                // tampungValue[i][j] *= 0.1;
            // }
            // else if(j>1){ 
                // tampungValue[i][j] *= 0.01;
            // }
            // cout << hasil << " " <<tampungValue[i][j]<< " " << myData[i][j] << endl;
            // cout << "hasil =  " << hasil << "   tampung = " << tampungValue[i] << endl;
            // cout << "hasil en= " << hasil << " " << (int)input[i] << endl;
            // printf("data terenkripsi[%d] = %d\n", i,input[i]);
            // cout << "tampung = " << tampungValue[i][j] << " hasil = " << hasilEn[i] << endl;
        // cout << "myData = " << myData[i][j] << " hasilEn = " << hasilEn[i][j] << endl;
        // }
    hasilEn[i+1] = -1;
    }
    z = 0;
    for(int i=0 ; hasilEn[i] != -1; i++){
            // printf("wafiq  = %ld \n",wafiq[i]); 
            temp = toDes[i];
            cout << "temp = " << temp << endl;
            hasil = 1;
            while(z<d)
            {
                hasil = hasil*temp; 
                hasil = hasil % n;
                z++;
                // cout << "hasil = " << hasil << endl;
            }
            // buset = hasil;
            z = 0;        
            // cout << "buset = " << buset<< endl;
            hasilDe[i] = hasil + 96;
            // if(j>0){
                // output[i][j] *= 10;
            // }
            // else if(j>1){ 
                // output[i][j] *= 100;
            // }
        // printf("data terdekripsi[%d][%d] = %c\n", i,j,(char)output[i][j]);
        // cout << "hasil =  " << hasil << " n = " << n <<endl;
        // cout << "hasil de= " << (char)output[i] << " " << tampungValue[i]<< endl;
        hasilDe[i+1] = -1;
    }
    for(int i = 0; hasilDe[i] != -1 ; i++){
        printf("%c %d\n",hasilDe[i],hasilDe[i]);
    }
    return 0;
}

