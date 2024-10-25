#include <iostream>
#include <string>
#include <ctime>
using namespace std;

string LeggiComando(){
    string comm;
    do{
        cout<<"Inserire 'P' per pulire la palestra; Inserire 'E' per far entrare persone; Inserire 'U' per far uscire persone; Inserire 'A' per usare gli attrezzi; Inserire 'R' per resettare la palestra; Inserire 'X' per uscire dal gioco: ";
        cin>>comm;
    }while(comm == "P" && comm == "E" && comm == "E" && comm == "U" && comm == "A" && comm == "R" && comm == "X");

    return comm;
}

void resetPalestra(int & Num_persone_max, int & livello_pulizia){
    Num_persone_max = 0;
    livello_pulizia = 0;
    cout<<"Inserire il numero massimo di persone che posso entrare nella palestra:";
    cin>>Num_persone_max;
    cout<<"Inserire la pulizia iniziale della palestra:";
    cin>>livello_pulizia;
}

int EntrataPersone(int persone, int max){
    int persone_nuove;
    do{
        cout<<"Inserire quante persone sono entrate in palestra: ";
        cin>>persone_nuove;
        if(persone_nuove <= 0){
        cout<<"Inserire un numero di persone maggiore o diverso da 0"<<endl;
        }
        if(persone + persone_nuove > max){
            cout<<"Hai superato il numero massimo di persone; Inserire un numero più piccolo"<<endl;
        }
    }while(persone_nuove<=0 || persone + persone_nuove > max);
    persone = persone + persone_nuove;
    return persone;
    
}

int UscitaPersone(int persone){
    int persone_nuove;
    do{
        cout<<"Inserire quante persone sono uscite dalla palestra: ";
        cin>>persone_nuove;
        if(persone_nuove <= 0){
            cout<<"Inserire un numero di persone maggiore o diverso da 0"<<endl;
        }
        if(persone - persone_nuove < 0){
            cout<<"Non puoi inserire un numero di persone in uscita maggiore di quelle in entrata"<<endl;
        }
    }while(persone_nuove <= 0 || persone - persone_nuove < 0);
    persone = persone - persone_nuove;
    return persone;
}

void UsaAttrezzi(int & pulizia){
    srand(time(NULL));
    pulizia = pulizia - (random()%96 + 5);
}

void PulisciPalestra(int & pulizia){
    pulizia = pulizia + 10;
}

int main() {
    string cond = ""; 
    int pulizia_tot, persone = 0, max;
    pulizia_tot = 100;
    cout<<"Inserire la capacita massima della palestra:"<<endl;
    cin>>max;
    do{
        cout<<"\n Persone in palestra = "<<persone<<"; Livello di pulizia: "<<pulizia_tot<<"; Capacità massima della palestra: "<<max<<";"<<endl;
        cond = LeggiComando();
        if(cond == "P"){
            PulisciPalestra(pulizia_tot);
        }
        if(cond == "E"){
            if(persone < max){
                persone = EntrataPersone(persone, max);
            }
            else{
                cout<<"Ci sono troppe persone"<<endl;
            }
        }
        if(cond == "U"){
            if(persone > 0){
            persone = UscitaPersone(persone);
            }
            else{
                cout<<"La palestra è vuota"<<endl;
            }
        }
        if(cond == "A"){
            UsaAttrezzi(pulizia_tot);
        }
        if(cond == "R"){
            resetPalestra(max, pulizia_tot);
            persone = 0; 
        }
    }while(cond != "X");

    cout<<"Grazie di aver giocato";
    return 0;
}