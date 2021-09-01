#include <iostream>
#include <fstream>
#include <string.h>


int main()
{
    using namespace std;
 char decyzja;
    do{

    string nazwa_pliku;
    int X,Y = 0;
    int kierunek; //1-poziomo , 2-pionowo
    int flaga_kierunek =0;
    int A =0;
    int B =0;
    int skok = 0;
    int predkosc =0;
    int klin,klin_a,klin_b = 0;
    char decyzja='0';
    char cp ='alt+184';
    cout << "NDT GENERATOR 1.0v"<<endl<<"By KAWECKI MATEUSZ 2019"<<"\b\b\b\b\b\b\b\b\b\b\b\b";
    cout    <<endl <<endl;
    cout << "1. PODAJ NAZWE PLIKU: ............"<<"\b\b\b\b\b\b\b\b\b\b\b\b";
    cin>>nazwa_pliku;
    nazwa_pliku = nazwa_pliku + ".GCODE";
    cout <<endl<<endl<< "2. PODAJ WYMIARY POLA ROBOCZEGO"<<endl;
    cout << "      _________________"<<endl;
    cout << "      |               |"<<endl;
    cout << "      |               |"<<endl;
    cout << "      |               |"<<endl;
    cout << "      |               |"<<endl;
    cout << "    A |               |"<<endl;
    cout << "      |               |"<<endl;
    cout << "      |               |"<<endl;
    cout << "      |               |"<<endl;
    cout << "      |_______________|"<<endl;
    cout << "              B"<<endl<<endl<<endl;
    cout << "PODAJ WARTOSC A [mm]: ......."<<"\b\b\b\b\b\b\b";
    cin>>A;
    cout << endl<<endl<< "PODAJ WARTOSC B [mm]: ......."<<"\b\b\b\b\b\b\b";
    cin>>B;
    cout << endl<<endl;
    cout << "      _ _ _ _ _ _ _ ->"<<endl;
    cout << "     |"<<endl;
    cout << "     |       "<<endl;
    cout << "     |"<<endl;
    cout << "     |_ _ _ _ _ _ _ _  _________ "<<endl;
    cout << "                      |"<<endl;
    cout << "                      |       SKOK  "<< endl;
    cout << "                      |"<<endl;
    cout << "      ->_ _ _ _ _ _ _ |_________   "<<endl;
    cout <<endl<<endl<< "3. PODAJ SKOK [mm]: ......."<<"\b\b\b\b\b\b\b";
    cin>>skok;
    cout <<endl<<endl<< "4. PODAJ PREDKOSC [mm/s]: ......."<<"\b\b\b\b\b\b\b";
    cin>>predkosc;
    cout <<endl<<endl<< "5. PODAJ KIERUNEK: [1]-POZIOMO | [2]-PIONOWO  "<<endl<<endl;
    cout << "    Y ^_______________           Y ^_______________"<<endl;
    cout << "      |  <-- _ _ _ _  |            |   _   _   _   |"<<endl;
    cout << "      |  _ _ _ _ _ _| |            |  | | | | | |  |"<<endl;
    cout << "      | |_ _ _ _ _ _  |            |  | | | | | |  |"<<endl;
    cout << "      |  _ _ _ _ _ _| |            |  | | | | | |  |"<<endl;
    cout << "      | |_ _ _ _ _ _  |            |  | | | | | |  |"<<endl;
    cout << "      |  _ _ _ _ _ _| |            |  | | | | | |  |"<<endl;
    cout << "      | |_ _ _ _ _ _  |            | /\\ | | | | \\/ |"<<endl;
    cout << "      |   -->  _ _ _| |            |    |_| |_|    |"<<endl;
    cout << "      |_______________| ->         |_______________| ->  "        <<endl;
    cout << "      0,0     POZIOMO   X           0,0     PIONOWO  X"<<endl<<endl;
    cout<<"                              [ ]\b\b";
    cin>>kierunek;
    cout <<endl<<endl<< "6. WYBIERZ ROZMIAR KLINA: [1]-93x40mm | [2]-66x32mm | [3]-26x32mm "<<endl<<endl;
    cout<<"                              [ ]\b\b";
    cin>>klin;
    if(klin == 1){
        klin_b = 40;
        klin_a = 92;
    }
    else if(klin == 2){
        klin_b = 32;
        klin_a = 66;
    }
    else{
        klin_b = 32;
        klin_a = 26;
    }


    ofstream plik(nazwa_pliku.c_str());


    plik << "G91"<<endl<<"G28"<<endl<<"G01 F"<<predkosc*60<<endl;

    if(kierunek == 1){
        X = B - klin_b;

        for(int a = 1 ; a <= (A - klin_a)/skok; a++ ){
                plik<<"G01 X";
                if (flaga_kierunek == 1){
                    plik<<"-";
                    flaga_kierunek =0;
                }
                else{
                    flaga_kierunek = 1;
                }
                plik<<X<<endl;
                plik<<"G01 Y"<<skok<<endl;
        }
        plik<<"G01 X";
        if (flaga_kierunek == 1){
                plik<<"-";
                flaga_kierunek =0;
        }
        else{
                    flaga_kierunek = 1;
                }
        plik<<X<<endl;
        if( (A-klin_a) % skok != 0){
            plik<<"G01 Y"<<(A-klin_a) % skok<<endl;
            plik<<"G01 X";
                if (flaga_kierunek == 1){
                    plik<<"-";
                    flaga_kierunek =0;
                }
                else{
                    flaga_kierunek = 1;
                }
                plik<<X<<endl;
        }
    }

    if(kierunek == 2){
        Y = A - klin_a;
        for(int b = 1 ; b <= (B - klin_b)/skok; b++ ){
                plik<<"G01 Y";
                if (flaga_kierunek == 1){
                    plik<<"-";
                    flaga_kierunek =0;
                }
                else{
                    flaga_kierunek = 1;
                }
                plik<<Y<<endl;
                plik<<"G01 X"<<skok<<endl;

        }
        plik<<"G01 Y";
        if (flaga_kierunek == 1){
                plik<<"-";
                flaga_kierunek =0;
        }
        else{
                    flaga_kierunek = 1;
                }
        plik<<Y<<endl;
        if( (B-klin_b) % skok != 0){
            plik<<"G01 X"<<(B-klin_b) % skok<<endl;
            plik<<"G01 Y";
                if (flaga_kierunek == 1){
                    plik<<"-";
                    flaga_kierunek =0;
                }
                else{
                    flaga_kierunek = 1;
                }
                plik<<Y<<endl;
        }
    }
     plik <<"M84";
     plik.close();

    cout<<endl<<endl<<"____________________________________________________________________";
    cout <<endl<<endl<< "UTWORZONO NOWY PLIK O NAZWIE \""<<nazwa_pliku<<"\" I NASTEPUJACYCH PARAMETRACH:"<<endl<<endl;
    cout<<"WYMIARY POLA - "<<A<<"x"<<B<<" mm"<<endl<<endl;
    cout<<"SKOK - "<<skok<<" mm"<<endl<<endl;
    cout<<"PREDKSC - "<<predkosc<<" mm/s"<<endl<<endl;
    if(kierunek == 1){
        cout<<"KIERUNEK SKANOWANIA - POZIOMO"<<endl<<endl;
    }
    else{
        cout<<"KIERUNEK SKANOWANIA - PIONOWO"<<endl<<endl;
    }

    if(klin== 1){
        cout<<"WYMIARY KLINA - 93x40 mm"<<endl<<endl;
    }
    else if(klin== 2){
        cout<<"WYMIARY KLINA - 66x32 mm"<<endl<<endl;
    }
    else{
        cout<<"WYMIARY KLINA - 26x32 mm"<<endl<<endl;
    }


    cout<<"____________________________________________________________________"<<endl<<endl;

    while(decyzja!='x' && decyzja != 'n'){
    cout<<"ABY WYJSC WCISNIJ \"X\", NOWY PLIK WCISNIJ \"N\": ";
    cin>>decyzja;
    if(decyzja == 'x' || decyzja == 'n' || decyzja == 'N'|| decyzja == 'X'){
        break;
    }
    else{
        cout<<endl<<"           NIEPRAWIDLOWY ZNAK!"<<endl;
    }
}

    if(decyzja == 'x'|| decyzja == 'X'){
        return 0;
    }
    }
    while(decyzja != 'x'|| decyzja == 'X');
    return 0;

}
