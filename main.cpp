#include <iostream>
#include<fstream>
#include<vector>
#include<string>
#include"SprPlik.h"
//#define liczbaPodcech 258;

//#include"Przebudowa.h"

using namespace std;


inline string wytnij(char *dane, int p1, int p2);
inline string wytnij(string dane,int p1, int p2);
inline bool sprawdz(string p1, string p2);
inline bool sprawdz(char *p1, char *p2);
inline int LiczZnaki(char *t);
inline int NaInt(string lb);
inline int pow(int lb,int pot);
inline void Zerowanie(year *tab);
inline int ZapiszRok(year *tab, int rokk);
inline int SprawdzNazwe(const string &, const string &, string, string, int&, int&, int&, fstream &);
inline int SprawdzNumerPolski(const string &, const string &, string, string, int&, int&, int&, fstream &);
inline int SprawdzDane(const string &, const string &, string, string, int&, int&, int&, fstream &,int,int, string);
inline int SprawdzPoprawnoscString(string nazwa);
inline void WczytanieDoTabeli(char **tab, int LWierszy, fstream &plk, char **tab840, char **tabUSA, int &licz840, int &liczUSA, int LiczbaZnakow);
//void Sprawdz840USA(fstream plk1, fstream plk2);
inline int Sprawdz840USA(const char *tab1, const char *tab2);
inline void SprWystepowaniaOsobnika(char **tabSN, char **tab1, char **tab2, int LwierszyI, int LwierszyJ, fstream &plk, int &licz);
inline void SprWystepowaniaOsobnika830USA(char **tab830, char **tabUSA, int Lwierszy830, int LwierszyUSA, fstream &plk, int &licz);
inline void WypiszSrednie(year *RokiPop, year *RokiBiez, int ileWierszy, int ileKolumn, string TypOceny, string Rodzaj, fstream &plkSrednie );
inline void RokiRokiRoki(year *Pop, year *Biez, int w, int k, string typ,string rodzaj, fstream &plkSrednie, OdchylenieSt *DSPop, OdchylenieSt *DSBie);
inline void podfunkcja(int i,int z,int k,string typ, int *ile, string rodzaj, float *wskPoP, float *wskBiez, fstream &plkSrednie, OdchylenieSt *DSPop, OdchylenieSt *DSBie);
inline void StworzTab(char **tab, int  n, int w);
inline void UsonTab(char **tab, int n);



inline void wypisz(char *);


int main()
{
    int k;
    //cin>>k;

    string ddane =  "840M003000247244LOUMAR AIRRA**************20071026HOUSAM000131688542*******************************************************************************************************************************************0*****3   69   115************73 -309713   69   115************75  -3503   69   115************75    133   69   115************69 -14903   69   115************69    -73   69   115************71  9370****************************3   16    17******46 102003   16    17******42 105003   16    17******45 10500**************************3   16    17******62  99003   16    17******53 106003   16    17******52  99003   16    17******62  97003   16    17******51  96003   16    17******51  95003   16    17******40  98003   16    17******40 105003   16    17******48 104003   16    17******46 105003   16    17******42 102003   16    17******60 10100**************************3   16    17******55 105003   16    17******59  94003   16    17******51  96003   16    17******45 100003   28    60******34  94403   63   104******50  99703   63   104******50 108003   65   108******51 10660****************************************************************************************************340  8400 -333 8593 980010000103001050010400 9500 8600********************************************************************************3   83   22947  93003   51    8637  94003   75   21837  97003   48    8247  89003   16    1740 105003   16    1749  9800";
    string ddanePoP ="840M003000247244LOUMAR AIRRA**************20071026HOUSAM000131688542*******************************************************************************************************************************************0*****3   69   115************73 -309003   69   115************75  -3303   69   115************75    133   69   115************69 -14903   69   115************69    -73   69   115************71  9400  **************************3   16    17******49 102003   16    17******43 105003   16    17******45 10500**************************3   16    17******62  99003   16    17******53 106003   16    17******52  99003   16    17******62  97003   16    17******51  96003   16    17******51  95003   16    17******40  98003   16    17******40 105003   16    17******48 104003   16    17******46 105003   16    17******42 102003   16    17******60 10100**************************3   16    17******55 105003   16    17******59  94003   16    17******51  96003   16    17******45 100003   28    60******38  92003   63   104******58  96003   63   104******55 110003   66   109******53 10700****************************************************************************************************340  8400 -331 8600 980010000103001050010400 9300 8600****************************************3  381  151092 117003  381  151089  98003  768  685395 105003  384  128288  96003  762  677191  96003  365  120090  89003  203   77867 106003  223   76490  9400";


     Ocena MlekoBiez,MlekoPop ;
    cout<<"==========================Mleko"<<endl;
    MlekoBiez.UstawZakres(213,"mleko",6,7);
    MlekoBiez.UstawDane(ddane);
    MlekoBiez.wyswietl();
    MlekoPop.UstawZakres(213,"mleko",6,7);
    MlekoPop.UstawDane(ddanePoP);
    MlekoPop.wyswietl();

    Ocena PokrojPop, PokrojBie ;
    cout<<"==========================Pokroj"<<endl;
    PokrojPop.UstawZakres(408,"pokroj",22,6);
    PokrojPop.UstawDane(ddanePoP);
    PokrojPop.wyswietl();
    PokrojBie.UstawZakres(408,"pokroj",22,6);
    PokrojBie.UstawDane(ddane);
    PokrojBie.wyswietl();

    Ocena PlodnoscPop, PlodnoscBie;
    cout<<"=========================Plodnosc"<<endl;
    PlodnoscPop.UstawZakres(980,"plodnosc",4,6);
    PlodnoscPop.UstawDane(ddanePoP);
    PlodnoscPop.wyswietl();
    PlodnoscBie.UstawZakres(980,"plodnosc",4,6);
    PlodnoscBie.UstawDane(ddane);
    PlodnoscBie.wyswietl();

    cout<<"=========================DystocjaCorekBuhaja"<<endl;
    Ocena DystocjaCBie, DystocjaCBPOP;
    DystocjaCBie.UstawZakres(1084,"dystocjaCB",10,1);

    DystocjaCBie.UstawDane(ddane);
    DystocjaCBie.wyswietl();


    DystocjaCBPOP.UstawZakres(1084,"dystocjaCB",10,1);
    DystocjaCBPOP.UstawDane(ddanePoP);
    DystocjaCBPOP.wyswietl();
    cout<<"=========================DystocjaBezposrednia"<<endl;
    Ocena DystocjaBBie, DystocjaBPop;
    DystocjaBBie.UstawZakres(1134,"dystocjaBB",10,1);
    DystocjaBBie.UstawDane(ddane);
    DystocjaBBie.wyswietl();

    DystocjaBPop.UstawZakres(1134,"dystocjaBB",10,1);
    DystocjaBPop.UstawDane(ddanePoP);
    DystocjaBPop.wyswietl();

    cout<<"=========================Przezywalnosc"<<endl;
    Ocena PrzeBie, PrzePop;

    PrzeBie.UstawZakres(1184,"przezywalnosc",1,3);
    PrzeBie.UstawDane(ddane);
    PrzeBie.wyswietl();

    PrzePop.UstawZakres(1184,"przezywalnosc",1,3);
    PrzePop.UstawDane(ddanePoP);
    PrzePop.wyswietl();
    cout<<"=========================Indeksy"<<endl;

    Ocena IndeksyIBie, IndeksyIPop;

    IndeksyIBie.UstawZakres(1193,"indeksy",9,1);
    IndeksyIBie.UstawDane(ddane);
    IndeksyIBie.wyswietl();

    IndeksyIPop.UstawZakres(1193,"indeksy",9,1);
    IndeksyIPop.UstawDane(ddanePoP);
    IndeksyIPop.wyswietl();








    int z;
    //cin>>z;
    fstream plk1,plk2,plkN1,plkN2,plkNowe, plkStar, plkRaportSzcz, plkRaport, plkNazwa,plkNumerPolski, plkDataUr, plkRasaOdmiana, plkNumerMOjca
    ,plkNazwaOjca, plkNumerOjcaWP,plkRasaOjca,  plkStatusBuhWPL, plk840USA, plkStar840USA, plkNowe840USA, plkRaportMleko,plkRaportPokroj,plkRaportPlodnosc,
    plkRaportDystocjaCB, plkRaportDystocjaBezp,plkRaportPrzezywalnosc, plkRaportIndeksy, plkRaportSrednie, plkRaportSrednieRocznikami, plkStrukturaPliku, plkNazwyKolumn;
    string zm1, zm2,zmw1,zmw2;
    bool z1=1,z2=1;
    int licznik=0, n=0,liczStar=0, liczNowe=0, StaraNazwa=0,NowaNazwa=0, RozneNazwa =0, StaryNumer=0,NowyNumer=0,RozneNumer=0
    ,NowaDataUr=0, StaraDataUr=0, RozneDatyUr=0, NowaRasaOdmiana=0,StaraRasaOdmiana=0,RoznaRasaOdmiana=0,NowyNumerMOjca=0
    ,StaryNumerMOjca=0,RoznyNumerMojca=0, NowaNazwaOjca=0, StaraNazwaOjca=0,RoznaNazwaOjca=0,NowyNumerOjcaWP=0, StaryNumerOjcaWP=0, RoznyNumerOjcaWP=0
    ,NowaRasaOjca=0,StaraRasaOjca=0,RoznaRasaOjca=0, NowyStatusBuhWPL=0,StaryStatusBuhWPL=0,RoznyStatusBuhWPL=0, Liczba840USA=0, liczStarUSA=0,liczStar840=0,
    liczNoweUSA=0,liczNowe840=0, liczStar840USA=0,liczNowe840USA=0;
    year RocznikiP[100], RocznikiB[100];
    char *buf1;
    char *buf2;
    char **tabStar = new char*[20000];
    char **tabNowe = new char*[20000];
    char **tabStar840= new char*[30000];
    char **tabStarUSA = new char*[50000];
    char **tabNowe840 = new char*[30000];
    char **tabNoweUSA = new char*[50000];

    /*StworzTab(tabStar, 20000,17);
    StworzTab(tabNowe, 20000,17);
    StworzTab(tabStar840, 5000,17);
    StworzTab(tabNowe840, 5000,17);
    StworzTab(tabStarUSA, 50000,17);
    StworzTab(tabNoweUSA, 50000,17);*/






    // Wstawka testowa programu clasy StructPliku. !!!!!!!!!!!!
    StructPliku StrPliku;

    plkStrukturaPliku.open("Pozycje.txt", ios::in);
    plkNazwyKolumn.open("Nazwy.txt", ios::in);

    StrPliku.Ustaw(plkNazwyKolumn,plkStrukturaPliku);
    StrPliku.wyswietl();
    int NaszaKlasa;
    cin>>NaszaKlasa;
    // Koniec programu testowego !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!








    string NrStary = "163", NrNowy="171";
    cout<<"Podaj  numer oceny poprzedniej i biezacej w postaci np. 163,171... w kolejnosci 1.ocena poprzednia, 2. ocena biezaca. UWAGA !!! zbiory musza byc posortowane !!!"<<endl;
    cin>>NrStary>>NrNowy;

    int lata1, lata2;

    cout<<"Podaj przedzia³ roczników od do "<<endl;
    cin>>lata1>>lata2;
    string OcenaPoprzednia = "pisz_iz_"+NrStary+".tst";
    string OcenaBizaca = "pisz_iz_"+NrNowy+".tst";
    string OcenaPoprzedniaN = OcenaPoprzednia+"N";
    string OcenaBizacaN = OcenaBizaca+"N";
    string Raprot ="Raport.txt", RaportSzcz = "RaportSzcz.txt";
    int ilosc840USA1=0, ilosc840USA2=0;


    cout<<OcenaBizaca<<" "<<OcenaPoprzednia<<" "<<OcenaBizacaN<<" "<<OcenaPoprzedniaN<<endl;
    //cin>>NrStary;

    //string a = "12345";
    //int klk = NaInt(a);
    //cout<<klk<<"to jest ta liczba"<<endl;


    plk1.open(OcenaPoprzednia.c_str(), ios::in);
    plk2.open(OcenaBizaca.c_str(), ios::in);
    plkN1.open(OcenaPoprzedniaN.c_str(), ios::out);
    plkN2.open(OcenaBizacaN.c_str(), ios::out);
    plkNowe.open("RaportNoweOsobniki", ios::out);
    plkStar.open("RaportStareOsobniki", ios::out);
    plkRaportSzcz.open(RaportSzcz.c_str(),ios::out);
    plkRaport.open(Raprot.c_str(),ios::out);
    plkNazwa.open("RaportNazwa", ios::out);
    plkNumerPolski.open("RaportNumerPolski",ios::out);
    plkDataUr.open("RaportDataUr",ios::out);
    plkRasaOdmiana.open("RaportRasaOdmiana", ios::out);
    plkNumerMOjca.open("RaportNumerMiedzyNarOjca", ios::out);
    plkNazwaOjca.open("RaportNazwaOjca", ios::out);
    plkNumerOjcaWP.open("RaportNumerOjcaWPolsce", ios::out);
    plkRasaOjca.open("RaportRasaOdmianaOjca", ios::out);
    plkStatusBuhWPL.open("RaportStatusBuhWPolsce",ios::out);
    plk840USA.open("Raport840USA", ios::out);
    plkStar840USA.open("RaportPoprzednie840USA", ios::out);
    plkNowe840USA.open("RaportBiezace840USA", ios::out);

    plkRaportMleko.open("RaportMleko.csv", ios::out);
    plkRaportPokroj.open("RaportPokroj.csv", ios::out);
    plkRaportPlodnosc.open("RaportPlodnosc.csv", ios::out);
    plkRaportDystocjaCB.open("RaportDystocjaCB.csv", ios::out);
    plkRaportDystocjaBezp.open("RaportDystocjaBezp.csv", ios::out);
    plkRaportPrzezywalnosc.open("RaportPrzezywalnosc.csv", ios::out);
    plkRaportIndeksy.open("RaportIndeksy.csv", ios::out);

    plkRaportSrednie.open("RaportSrednieDlaRocznikow.csv", ios::out);
    plkRaportSrednieRocznikami.open("RaportySrednieDlaRocznikowII.csv",ios::out);

    if(plk1.good()==true && plk2.good()==true)
    {
        string zzm2;
        plk1.seekg(0,ios::end);
        int wiersze1=plk1.tellg();
        plk1.seekg(0,ios::beg);

        plk2.seekg(0,ios::end);
        int wiersze2=plk2.tellg();
        plk2.seekg(0,ios::beg);

        getline(plk1,zm1);
        getline(plk2,zzm2);
        plk1.close();
        plk2.close();

        plk1.open(OcenaPoprzednia.c_str(), ios::in);
        plk2.open(OcenaBizaca.c_str(), ios::in);

        int siz11 = zm1.length();
        int siz22 = zzm2.length();
        int Lwierszy1 =wiersze1/(siz11+1);
        int Lwierszy2 =wiersze2/(siz22+1);

        cout<<"Liczba wierszy w "<<OcenaPoprzednia.c_str()<<" = "<<Lwierszy1<<" znakow = "<<siz11<<endl;
        cout<<"Liczba wierszy w "<<OcenaBizaca.c_str()<<" = "<<Lwierszy2<<endl;
        plkRaport<<"Liczba wierszy w pliku  "<<OcenaPoprzednia<<"   =   "<<Lwierszy1<<" ,liczba znakow w wierszu    =   "<<siz11<<endl;
        plkRaport<<"Liczba wierszy w pliku  "<<OcenaBizaca<<"   =   "<<Lwierszy2<<" ,liczba znakow w wierszu    =   "<<siz22<<endl;
        char **tab1 = new char*[Lwierszy1];
        char **tab2 = new char*[Lwierszy2];


       //StworzTab(tab1, Lwierszy1,17);
        //StworzTab(tab2, Lwierszy2,17);
        //for(int i=0; ;i++ )
        //{
        vector<char*> myvector;
            //if(plk1.eof()== true)break;
            //if(z1==1) getline(plk1,zm1);
            //if(z2==1) getline(plk2,zm2);
            //==================================================================================================================
            int eee;
            cout<<"etap 1.1 wczytytywanie do tabeli osobników z poprzedniej oceny"<<endl;
            WczytanieDoTabeli(tab1,Lwierszy1,plk1,tabStar840, tabStarUSA, liczStar840, liczStarUSA,siz11+1 );
            cin>>eee;
            cout<<"etap 1.2 wczytytywanie do tabeli osobników z biezacej oceny"<<endl;
            WczytanieDoTabeli(tab2,Lwierszy2,plk2, tabNowe840, tabNoweUSA, liczNowe840, liczNoweUSA,siz22+1 );
            cin>> eee;
            cout<<"Stare ==================="<<liczStar840<<"===="<<liczStarUSA<<" Nowe ======="<<liczNowe840<<"===="<<liczNoweUSA<<endl;

            //===================================================================================================================
            cout<<"etap 2.1 porownanie danych poprzednich z biezacymi"<<endl;
            SprWystepowaniaOsobnika(tabStar, tab1,tab2,Lwierszy1,Lwierszy2,plkStar,liczStar);

            cout<<"etap 2.2 porownanie danych biezacych z poprzednimi"<<endl;
            SprWystepowaniaOsobnika(tabNowe, tab2,tab1,Lwierszy2,Lwierszy1,plkNowe,liczNowe);

            cout<<"etap 2.3 sprawdzenie wystepowania tych samych osobnikow 840/USA w ocenie poprzedniej"<< OcenaPoprzednia<<endl;
            SprWystepowaniaOsobnika830USA(tabStar840,tabStarUSA,liczStar840,liczStarUSA,plkStar840USA, liczStar840USA);

            cout<<"etap 2.4 sprawdzenie wystepowania tych samych osobnikow 840/USA w ocenie biezacej"<< OcenaBizaca<<endl;
            SprWystepowaniaOsobnika830USA(tabNowe840,tabNoweUSA,liczNowe840,liczNowe840USA,plkNowe840USA, liczNowe840USA);



            //====================================================================================================================
            plkRaport<<"Liczba osobników z oceny poprzedniej "<<OcenaPoprzednia<<" ktorych numer powtarza sie 840/USA = "<<liczStar840USA<<endl;
            plkRaport<<"Liczba osobników z oceny biezacej "<<OcenaBizaca<<" ktorych numer powtarza sie 840/USA = "<<liczNowe840USA<<endl;
            plkRaport<<"Liczba osobnikow z pliku    "<<OcenaPoprzednia<<"   nie wystêpuj¹ce w pliku "<<OcenaBizaca<<"   =   "<<liczStar<<endl;
            plkRaport<<"Liczba osobnikow z pliku "<<OcenaBizaca<<"   nie wystêpuj¹ce w pliku "<<OcenaPoprzednia<<"   =   "<<liczNowe<<endl;

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

            cout<<" Osobniki ze zmienionym symbolem kraju 840 USA w ocenie poprzedniej i biezacej"<<endl;
            for(int i=0; i<liczStar; i++)
            {
                for(int j=0; j<liczNowe; j++)
                {

                    if((Sprawdz840USA(tabStar[i], tabNowe[j])==1))
                    {
                        plk840USA<<tabStar[i]<<"<<<==========>>>"<<tabNowe[j]<<endl;
                        cout<<tabStar[i]<<"<<<==========>>>"<<tabNowe[j]<<endl;
                        Liczba840USA++;
                        break;

                    }
                }
            }
            plkRaport<<"Liczba Osobników ze zmienionym oznaczeniem kraju 840 USA w obydwu ocenach = "<<Liczba840USA<<endl;

            //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
            //=================================================================================================



            cout<<"etap 3 utworzenie nowych plikow, z takimi samymi danymi, w takiej samej kolejnosci, numery z poprzedniej oceny == z nr z biezacej + sprawdzenie roczników"<<endl;
            Zerowanie(RocznikiP);
            Zerowanie(RocznikiB);
            n=0;
            buf1 = new char[siz11+1];
            buf2 = new char[siz22+1];
            liczNowe =0;
            liczStar =0;
            for(int i=0; i<Lwierszy1; i++)
            {
                //cout<<i<<"   <>"<<Lwierszy1<<endl;
                plk1.seekg(n,ios::beg);
                plk1.read(buf1,siz11);
                buf1[siz11] = '\0';
                //cout<<tab1[i]<<"<<<<<========>>>>>"<<tabStar[liczStar]<<"<===========>"<<wytnij(buf1,0,16)<<endl;
                if(sprawdz(tab1[i],tabStar[liczStar])==1)
                {
                    liczStar++;
                }
                else
                {
                    plkN1<<buf1<<endl;
                    string rok = wytnij(buf1,42,45);
                    int RokInt = NaInt(rok);
                    ZapiszRok(RocznikiP,RokInt);
                    //cout<<RokInt<<endl;
                }
                n = n+siz11+1;
            }

            n=0;
            //cout<<"etap 3.2"<<endl;

            for(int i=0; i<Lwierszy2; i++)
            {

                plk2.seekg(n,ios::beg);
                plk2.read(buf2,siz22);
                buf2[siz22] = '\0';
                if(sprawdz(tab2[i],tabNowe[liczNowe])==1)
                {
                    liczNowe++;
                }
                else
                {
                    plkN2<<buf2<<endl;
                    string rok = wytnij(buf2,42,45);
                    int RokInt = NaInt(rok);
                    ZapiszRok(RocznikiB,RokInt);
                }

                n = n+siz22+1;
            }

            cout<<"Sprawdzenie roczników" <<endl;
            plkRaport<<"Wykaz rocznikow"<<endl;


            plkRaport<<endl;
            //================================================================================================================================================
            cout<<" Sprawdzenie poprawnosci danych"<<endl;
            year RokiPop[200],RokiBiez[200];
            OdchylenieSt *DSPop = new OdchylenieSt[200];
            OdchylenieSt *DSBie = new OdchylenieSt[200];
            int LRok=0;




            //=============================================================================================================================================
            //=============================================================================================================================================

            fstream plkDaneID, plkDameMleko, plkDanePokroj, plkDanePlodnosc, plkDaneDystocjaCB;
            fstream plkDaneDystocjaBez, plkDanePrzezywalnosc, plkDaneIndeksy, plkTabWynikowa;
            fstream plkDaneLaktoza, plkDaneWorkability, plkDaneCalving; //plkDaneLocomotion


                plkDaneID.open("RaportDaneID.csv",ios::out);
                StrPliku.NazwyKolumn(plkDaneID,0,9);

                plkDameMleko.open("RaportDameMleko.csv",ios::out);
                StrPliku.NazwyKolumn(plkDameMleko,26,69);

                plkDanePokroj.open("RaportDanePokroj.csv",ios::out);
                StrPliku.NazwyKolumn(plkDanePokroj,69,202);

                plkDanePlodnosc.open("RaportDanePlodnosc.csv",ios::out);
                StrPliku.NazwyKolumn(plkDanePlodnosc,202,226);

                plkDaneDystocjaCB.open("RaportDaneDystocjaCB.csv",ios::out);
                StrPliku.NazwyKolumn(plkDaneDystocjaCB,226,236);

                plkDaneDystocjaBez.open("RaportDaneDystocjaBez.csv",ios::out);
                StrPliku.NazwyKolumn(plkDaneDystocjaBez,236,246);

                plkDanePrzezywalnosc.open("RaportDanePrzezywalnosc.csv",ios::out);
                StrPliku.NazwyKolumn(plkDanePrzezywalnosc,246,249);

                plkDaneIndeksy.open("RaportDaneIndeksy.csv",ios::out);
                StrPliku.NazwyKolumn(plkDaneIndeksy,249,258);


                // Nowe cechy dodano 02-03.2021

                plkDaneLaktoza.open("RaportDaneLaktoza.csv",ios::out);
                StrPliku.NazwyKolumn(plkDaneLaktoza,259,269);

                plkDaneWorkability.open("RaportDaneWorkability.csv",ios::out);
                StrPliku.NazwyKolumn(plkDaneWorkability,269,279);

                plkDaneCalving.open("RaportDaneCalving.csv",ios::out);
                StrPliku.NazwyKolumn(plkDaneCalving,279,299);


                //plkDaneLocomotion.open("RaportDaneLocomotion.csv",ios::out);
                //StrPliku.NazwyKolumn(plkDaneLocomotion,299,310)


                plkTabWynikowa.open("TablicaWynikowaIS", ios::out);







            //=============================================================================================================================================
            //=============================================================================================================================================





            cout<<Lwierszy1-liczStar<<endl;
            fstream Dom;
            Dom.open("RapDom", ios::out);
            //year tab[20];

            for(int i=0; i<200; i++)
            {
                RokiPop[i].zerowanie();
                RokiBiez[i].zerowanie();
            }

            plkN1.close();
            plkN2.close();
            plkN1.open(OcenaPoprzedniaN.c_str(), ios::in);
            plkN2.open(OcenaBizacaN.c_str(), ios::in);
            for(int i=0; ; i++)
            {

                string dane1, dane2;

                getline(plkN1,dane1);
                getline(plkN2,dane2);
                if(plkN1.eof() == true || plkN2.eof() ==  true ) break;
                string nr1 = wytnij(dane1,0,15);
                string nr2 = wytnij(dane2,0,15);
                string OcenionyWKraju = wytnij(dane2,207,207);
                string Rrok = wytnij(dane1,42,45);
                int rok = NaInt(Rrok);
                if(rok < 1900 || rok >2025) rok = 1900;
                rok = rok-1900;
                //cout<<dane1<<"HAHA"<<endl;

                //cout<<rok<<"============"<<nr1<<endl;

                //============================================================================================================================
                //============================================================================================================================

                 StrPliku.Zerowanie();

                 StrPliku.WczytajDane(dane1, dane2);

                 StrPliku.Publikuj(plkDaneID,0,9,"ID");
                 StrPliku.Publikuj(plkDameMleko,26,69,"Mleko");
                 StrPliku.Publikuj(plkDanePokroj,69,202,"Pokroj");
                 StrPliku.Publikuj(plkDanePlodnosc,202,226,"Plodnosc");
                 StrPliku.Publikuj(plkDaneDystocjaCB,226,236,"DystocjaCB");
                 StrPliku.Publikuj(plkDaneDystocjaBez,236,246,"DystocjaBB");
                 StrPliku.Publikuj(plkDanePrzezywalnosc,246,249,"Przezywalnosc");
                 StrPliku.Publikuj(plkDaneIndeksy,249,258,"Indeksy");

                StrPliku.Publikuj(plkDaneLaktoza,259,269,"Laktoza");

                StrPliku.Publikuj(plkDaneWorkability,269,279,"Workability");

                StrPliku.Publikuj(plkDaneCalving,279,299,"Calving");


                //StrPliku.Publikuj(plkDaneLocomotion,299,310,"Locomotion")


                 StrPliku.PuplikujTabWynikowa(plkTabWynikowa);







                 //============================================================================================================================
                //============================================================================================================================

                SprawdzDane(dane1,dane2,nr1,nr2, StaraNazwa, NowaNazwa,RozneNazwa,plkNazwa,16,27, "'Nazwa'");
                SprawdzDane(dane1,dane2,nr1,nr2, StaryNumer, NowyNumer,RozneNumer,plkNumerPolski,28,41,"'Numer w Polsce'");
                SprawdzDane(dane1,dane2,nr1,nr2, StaraDataUr, NowaDataUr,RozneDatyUr,plkDataUr,42,49,"'Data Urodzenia'");
                SprawdzDane(dane1,dane2,nr1,nr2, StaraRasaOdmiana, NowaRasaOdmiana,RoznaRasaOdmiana,plkRasaOdmiana,50,51,"'Rasa/Odmiana'");
                SprawdzDane(dane1,dane2,nr1,nr2, StaryNumerMOjca, NowyNumerMOjca,RoznyNumerMojca,plkNumerMOjca,52,67,"'Numer Miedzynarodowy Ojca'");
                SprawdzDane(dane1,dane2,nr1,nr2, StaraNazwaOjca, NowaNazwaOjca,RoznaNazwaOjca,plkNazwaOjca,68,79,"'Nazwa Ojca'");
                SprawdzDane(dane1,dane2,nr1,nr2, StaryNumerOjcaWP, NowyNumerOjcaWP,RoznyNumerOjcaWP,plkNumerOjcaWP,80,93,"'Numer Ojca w Polsce'");
                SprawdzDane(dane1,dane2,nr1,nr2, StaraRasaOjca, NowaRasaOjca,RoznaRasaOjca,plkRasaOjca,94,95,"'Rasa Ojca'");
                SprawdzDane(dane1,dane2,nr1,nr2, StaryStatusBuhWPL, NowyStatusBuhWPL,RoznyStatusBuhWPL,plkStatusBuhWPL,192,193,"'Status Buhaja w Polsce'");

                MlekoBiez.UstawDane(dane1);
                MlekoPop.UstawDane(dane2);
                //SprawdzDane(MlekoPop,MlekoBiez,plkRaportMleko,nr1,nr2,RokiPop[rok],RokiBiez[rok],OcenionyWKraju, DSPop[rok], DSBie[rok]);
                //Dom<<LRok<<"<=====>"<<DS[LRok-1].rok<<"<===>"<<DS[LRok-1].MlekoPopK[0]<<"<===>"<<DS[LRok-1].MlekoBieK[0]<<endl;
                PokrojBie.UstawDane(dane1);
                PokrojPop.UstawDane(dane2);
                //SprawdzDane(PokrojPop,PokrojBie,plkRaportPokroj,nr1,nr2,RokiPop[rok],RokiBiez[rok],OcenionyWKraju, DSPop[rok], DSBie[rok]);

                PlodnoscBie.UstawDane(dane1);
                PlodnoscPop.UstawDane(dane2);
                //SprawdzDane(PlodnoscPop,PlodnoscBie,plkRaportPlodnosc,nr1,nr2,RokiPop[rok],RokiBiez[rok],OcenionyWKraju, DSPop[rok], DSBie[rok]);

                DystocjaCBie.UstawDane(dane1);
                DystocjaCBPOP.UstawDane(dane2);
                //SprawdzDaneDystCurekBuh(DystocjaCBPOP,DystocjaCBie,plkRaportDystocjaCB,nr1,nr2,RokiPop[rok],RokiBiez[rok],OcenionyWKraju, DSPop[rok], DSBie[rok]);

                DystocjaBBie.UstawDane(dane1);
                DystocjaBPop.UstawDane(dane2);
               // SprawdzDaneDystBezposrednia(DystocjaBBie,DystocjaBPop,plkRaportDystocjaBezp,nr1,nr2,RokiPop[rok],RokiBiez[rok],OcenionyWKraju, DSPop[rok], DSBie[rok]);

                PrzeBie.UstawDane(dane1);
                PrzePop.UstawDane(dane2);
               // SprawdzDanePrzezywalnosc(PrzeBie,PrzePop,plkRaportPrzezywalnosc,nr1,nr2,RokiPop[rok],RokiBiez[rok],OcenionyWKraju, DSPop[rok], DSBie[rok]);

                IndeksyIBie.UstawDane(dane1);
                IndeksyIPop.UstawDane(dane2);
                //SprawdzDaneIndeksy(IndeksyIBie,IndeksyIPop,plkRaportIndeksy,nr1,nr2,RokiPop[rok],RokiBiez[rok],OcenionyWKraju, DSPop[rok], DSBie[rok]);


            }



            cout<<StaraNazwa<<"<=========>"<<NowaNazwa<<endl;
            plkRaport<<"******************************************Nazwa*********************************************************** "<<endl;
            plkRaport<<"Liczba osobnikow dla ktorych brak nazwy w pliku "<<OcenaPoprzednia<<"   =   "<<NowaNazwa<<endl;
            plkRaport<<"Liczba osobnikow dla ktorych brak nazwy w pliku "<<OcenaBizaca<<"   =   "<<StaraNazwa<<endl;
            plkRaport<<"Liczba osobnikow dla ktorych nazwy roznia sie "<<"   =   "<<RozneNazwa<<endl;
            plkRaport<<endl;
            plkRaport<<"**************************************Numer w Polsce******************************************************* "<<endl;
            plkRaport<<"Liczba osobnikow dla ktorych brak numeru Polskiego w pliku "<<OcenaPoprzednia<<"   =   "<<NowyNumer<<endl;
            plkRaport<<"Liczba osobnikow dla ktorych brak numeru Polskieg w pliku "<<OcenaBizaca<<"   =   "<<StaryNumer<<endl;
            plkRaport<<"Liczba osobnikow dla ktorych numery Poskie roznia sie "<<"   =   "<<RozneNumer<<endl;
            plkRaport<<endl;
            plkRaport<<"**************************************Data Urodzenia******************************************************* "<<endl;
            plkRaport<<"Liczba osobnikow dla ktorych brak daty urodzenia w pliku "<<OcenaPoprzednia<<"   =   "<<NowaDataUr<<endl;
            plkRaport<<"Liczba osobnikow dla ktorych brak daty urodzenia w pliku "<<OcenaBizaca<<"   =   "<<StaraDataUr<<endl;
            plkRaport<<"Liczba osobnikow dla ktorych daty urodzenia roznia sie "<<"   =   "<<RozneDatyUr<<endl;
            plkRaport<<endl;
            plkRaport<<"**************************************rasa/odmiana********************************************************* "<<endl;
            plkRaport<<"Liczba osobnikow dla ktorych brak rasay/odmiany w pliku "<<OcenaPoprzednia<<"   =   "<<NowaRasaOdmiana<<endl;
            plkRaport<<"Liczba osobnikow dla ktorych brak rasy/odmiany w pliku "<<OcenaBizaca<<"   =   "<<StaraRasaOdmiana<<endl;
            plkRaport<<"Liczba osobnikow dla ktorych rasa/odmiana roznia sie "<<"   =   "<<RoznaRasaOdmiana<<endl;
            plkRaport<<endl;
            plkRaport<<"*********************************Numer miedzynarodowy ojca************************************************** "<<endl;
            plkRaport<<"Liczba osobnikow dla ktorych brak numeru miedzynarodowego ojca w pliku "<<OcenaPoprzednia<<"   =   "<<NowyNumerMOjca<<endl;
            plkRaport<<"Liczba osobnikow dla ktorych brak numeru miedzynarodowego ojca w pliku "<<OcenaBizaca<<"   =   "<<StaryNumerMOjca<<endl;
            plkRaport<<"Liczba osobnikow dla ktorych numeru miedzynarodowego ojca roznia sie "<<"   =   "<<RoznyNumerMojca<<endl;
            plkRaport<<endl;
            plkRaport<<"***************************************Nazwa ojca*********************************************************** "<<endl;
            plkRaport<<"Liczba osobnikow dla ktorych brak nazwy ojca w pliku "<<OcenaPoprzednia<<"   =   "<<NowaNazwaOjca<<endl;
            plkRaport<<"Liczba osobnikow dla ktorych brak nazwy ojca w pliku "<<OcenaBizaca<<"   =   "<<StaraNazwaOjca<<endl;
            plkRaport<<"Liczba osobnikow dla ktorych nazwa ojca rozni sie "<<"   =   "<<RoznaNazwaOjca<<endl;
            plkRaport<<endl;
            plkRaport<<"***********************************Numer Ojca Polsce******************************************************** "<<endl;
            plkRaport<<"Liczba osobnikow dla ktorych brak numeru ojca w polsce w pliku "<<OcenaPoprzednia<<"   =   "<<NowyNumerOjcaWP<<endl;
            plkRaport<<"Liczba osobnikow dla ktorych brak numeru ojca w polsce w pliku "<<OcenaBizaca<<"   =   "<<StaryNumerOjcaWP<<endl;
            plkRaport<<"Liczba osobnikow dla ktorych numer ojca w polsce rozni sie "<<"   =   "<<RoznyNumerOjcaWP<<endl;
            plkRaport<<endl;
            plkRaport<<"*************************************rasa/odmiana ojca****************************************************** "<<endl;
            plkRaport<<"Liczba osobnikow dla ktorych brak rasy/odmiany ojca w polsce w pliku "<<OcenaPoprzednia<<"   =   "<<NowaRasaOjca<<endl;
            plkRaport<<"Liczba osobnikow dla ktorych brak rasy/odmiany ojca w polsce w pliku "<<OcenaBizaca<<"   =   "<<StaraRasaOjca<<endl;
            plkRaport<<"Liczba osobnikow dla ktorych rasa/odmiana ojca w polsce rozni sie "<<"   =   "<<RoznaRasaOjca<<endl;
            plkRaport<<endl;
            plkRaport<<"***********************************Status Buhaja w Polsce**************************************************** "<<endl;
            plkRaport<<"Liczba osobnikow dla ktorych brak statusu buhaja w polsce w pliku "<<OcenaPoprzednia<<"   =   "<<NowyStatusBuhWPL<<endl;
            plkRaport<<"Liczba osobnikow dla ktorych brak statusu buhaja w polsce w pliku "<<OcenaBizaca<<"   =   "<<StaryStatusBuhWPL<<endl;
            plkRaport<<"Liczba osobnikow dla ktorych statusu buhaja w polsce rozni sie "<<"   =   "<<RoznyStatusBuhWPL<<endl;
            plkRaport<<"***************************************************************************************************** "<<endl;


            WypiszSrednie(RokiPop,RokiBiez,6,7,"K","Mleko",plkRaportSrednie);
            plkRaportSrednieRocznikami<<"******Mleko*******"<<endl;
            RokiRokiRoki(RokiPop,RokiBiez,6,7,"Mleko","K",plkRaportSrednieRocznikami, DSPop, DSBie);
            plkRaportSrednieRocznikami<<"******Pokroj*******"<<endl;
            RokiRokiRoki(RokiPop,RokiBiez,22,6,"Pokroj","K",plkRaportSrednieRocznikami, DSPop, DSBie);
            plkRaportSrednieRocznikami<<"******Plodnosc*******"<<endl;
            RokiRokiRoki(RokiPop,RokiBiez,4,6,"Plodnosc","K",plkRaportSrednieRocznikami, DSPop, DSBie);
            plkRaportSrednieRocznikami<<"******Dystocja Corek Buhaja*******"<<endl;
            RokiRokiRoki(RokiPop,RokiBiez,10,1,"DystocjaCB","G",plkRaportSrednieRocznikami, DSPop, DSBie);
            plkRaportSrednieRocznikami<<"******Dystocja Brzposrednia*******"<<endl;
            RokiRokiRoki(RokiPop,RokiBiez,10,1,"Dystocja Bezposrednia","G",plkRaportSrednieRocznikami, DSPop, DSBie);
            plkRaportSrednieRocznikami<<"******Przezywalnosc*******"<<endl;
            RokiRokiRoki(RokiPop,RokiBiez,3,1,"Przezywalnosc","G",plkRaportSrednieRocznikami, DSPop, DSBie);
            plkRaportSrednieRocznikami<<"******Indeksy*******"<<endl;
            RokiRokiRoki(RokiPop,RokiBiez,9,1,"Indeksy","G",plkRaportSrednieRocznikami, DSPop, DSBie);

            for(int i=100; i<200; i++)
            {
                cout<<i+1900<<" III "<<endl;
                DSPop[i].LiczDSMleko(RokiPop[i]);
                DSBie[i].LiczDSMleko(RokiBiez[i]);
                cout<<"**************************Pokroj*********************************"<<endl;
                DSPop[i].LiczDSPokroj(RokiPop[i]);
                DSBie[i].LiczDSPokroj(RokiBiez[i]);
                cout<<"*************************Plodnosc**********************************"<<endl;
                DSPop[i].LiczDSPlodnosc(RokiPop[i]);
                DSBie[i].LiczDSPlodnosc(RokiBiez[i]);
                cout<<"*************************DystocjaCB**********************************"<<endl;
                DSPop[i].LiczDSDystocjaCB(RokiPop[i]);
                DSBie[i].LiczDSDystocjaCB(RokiBiez[i]);
                cout<<"*************************DystocjaBezp**********************************"<<endl;
                DSPop[i].LiczDSDystocjaBezp(RokiPop[i]);
                DSBie[i].LiczDSDystocjaBezp(RokiBiez[i]);
                cout<<"*************************Przezywalnosc**********************************"<<endl;
                DSPop[i].LiczDSPrzezywalnosc(RokiPop[i]);
                DSBie[i].LiczDSPrzezywalnosc(RokiBiez[i]);
                cout<<"*************************Indeksy**********************************"<<endl;
                DSPop[i].LiczDSIndeksy(RokiPop[i]);
                DSBie[i].LiczDSIndeksy(RokiBiez[i]);
                //DSPop[i].wyswietl();
                //DSBie[i].wyswietl();
            }


            //=====================================Czyszczenie pamiêci dla pliku startego=======================================================
            for(int i=0; i<Lwierszy1; i++)
            {
                delete tab1[i];
            }
            delete [] tab1;
            //=====================================Czyszczenie pamiêic dla pliku nowego=====================
            for(int i=0; i<Lwierszy2; i++)
            {
                delete tab2[i];
            }
            delete [] tab2;
            //===============================================================================================
            delete [] buf1;
            delete [] DSPop;
            delete [] DSBie;
            delete [] buf2;

        }





    cout << "Hello world!" << endl;
    return 0;
}
//==========================================================================================================================================================
//==========================================================================================================================================================
inline void RokiRokiRoki(year *Pop, year *Biez, int w, int k, string typ,string rodzaj, fstream &plkSrednie, OdchylenieSt *DSPop, OdchylenieSt *DSBie)
{
    string WartMleko[6]={"Mleko[Kg]","Tluszcz[Kg]","Tluszcz[%]","Bialko[Kg]","Bialko[%]","Komorki Somatyczne"};
    string PodindWM = "Typ Oceny;Liczba Obor;Liczba Corek;Powtarzalnosc;Wartosc Hodowlana";
    string WartoscPokroj[22]={"Kaliber","Typ i budowa","Nogi i racice","Ocena ogolna wymiona","Budowa Ogolna","Wysokosc w krzyzu","Glebokosc tulowia","Szerokosc klati piersiowej",
                        "Ustawienie zadu","Szerokosc zadu","Nogi tylne - widoku z boku","Racice","Nogi tylne - widok z tylu","Zawieszenie przednie wymiona","Zawieszenie tylne wymiona",
                        "Wiezadlo srodkowe wymiona","Polozenie wymiona","Szerokosc wymiona","Ustawienie strzykow","Dlugosc sztrzykow","Ustawienie strzykow tylnych","Charakter mleczny"};
    string PodindPoz = "Typ Oceny;Liczba Obor;Liczba Corek;Powtarzalnosc;Wartosc Hodowlana";
    string WartoscPlod[4]={"Wskaznik nie powtarzalnosci unasiennienia jalowek (NRj)","Wskaznik ie powtarzalnosci unasiennienia krow (NRk)","Przestoj poporodowy (PP)","Odstep miedzyciazowy (OMC)"};
    string WartoscDystocjaCB[10]={"Liczba Ocielonych Corek","Porody Samodzielne Proc100x","Porody Latwe Proc100x","Porody Trudne Proc100x","Porody Ciezkie Proc100x","Poronienia Proc 100x",
                                  "Cesarskie Ciecia Proc100x","Liczba Urodzonych Cielat","Zywo Urodzone Proc100x","Martwo Urodzone Proc100x"};
    string WartoscPrze[3]={"Typ oceny","Powtarzalnosc","Wartosc hodowlana*100"};
    string WartoscIn[9]={"Indeks Produkcyjny Stary *10[kg]","Podindeks Produkcyjny *100","Podindeks Kalibru *100","Podindeks Typu I Budowy *100","Podindeks Nog I Racic *100","Podindeks Wymienia *100",
    "Podindeks Ogolny Pokroju *100","Podindeks Plodnosci *100","Indeks PF *100x"};
    string wartosc = "Wartosc";


    for(int z=0; z<w; z++)
    {
        float *wskPoPK, *wskBiezK,*wskPoPG, *wskBiezG, *wskPoPGK, *wskBiezGK ;
        string *indeks,  *podind, typOceny;
        int *ileK, *ileG, *ileGK;
        podind = &wartosc;
         if(typ =="Mleko")
         {
            indeks = WartMleko;
            podind = &PodindWM;
         }
         if(typ =="Pokroj")
         {
            indeks = WartoscPokroj;
            podind = &PodindPoz;
         }

         if(typ =="Plodnosc")
         {
            indeks = WartoscPlod;
            podind = &PodindPoz;
         }
         if(typ == "DystocjaCB" || typ == "Dystocja Bezposrednia")
         {
             indeks = WartoscDystocjaCB;
         }

         if(typ == "Przezywalnosc")
         {
             indeks = WartoscPrze;
         }
         if(typ == "Indeksy")
         {
             indeks = WartoscIn;
         }

        plkSrednie<<";;;;;  "<<indeks[z]<<";;;;;;"<<endl;
        if(typ=="Mleko" || typ=="Plodnosc" || typ=="Pokroj")
            plkSrednie<<";;Ocena Poprzednia;;;;;;;Ocena Biezaca;;;"<<endl;


         plkSrednie<<"Rocznik;liczba osobnikow;"<<*podind<<" Poprzednia;"<<*podind<<" Biezaca"<<endl;
         int n =1;
         if(typ =="Mleko" || typ =="Pokroj" || typ =="Plodnosc") n=3;

         for(int o=0; o<n; o++)
         {


            for(int i=100; i<200; i++)
            {


                if(typ =="Mleko")
                {

                    wskPoPK = Pop[i].MlekoK[z];
                    wskBiezK = Biez[i].MlekoK[z];
                    ileK = Pop[i].ileK;


                    wskPoPG = Pop[i].MlekoG[z];
                    wskBiezG = Biez[i].MlekoG[z];
                    ileG = Pop[i].ileG;

                    wskPoPGK = Pop[i].MlekoGK[z];
                    wskBiezGK = Biez[i].MlekoGK[z];
                    ileGK = Pop[i].ileGK;

                }
                 if(typ =="Pokroj")
                 {

                    wskPoPK = Pop[i].PokrojK[z];
                    wskBiezK = Biez[i].PokrojK[z];
                    ileK = Pop[i].ilePoK;

                    wskPoPG = Pop[i].PokrojG[z];
                    wskBiezG = Biez[i].PokrojG[z];
                    ileG = Pop[i].ilePoG;

                    wskPoPGK = Pop[i].PokrojGK[z];
                    wskBiezGK = Biez[i].PokrojGK[z];
                    ileGK = Pop[i].ilePoGK;

                 }

                 if(typ =="Plodnosc")
                 {

                    wskPoPK = Pop[i].PlodnoscK[z];
                    wskBiezK = Biez[i].PlodnoscK[z];
                    ileK = Pop[i].ilePlK;

                    wskPoPG = Pop[i].PlodnoscG[z];
                    wskBiezG = Biez[i].PlodnoscG[z];
                    ileG = Pop[i].ilePlG;

                    wskPoPGK = Pop[i].PlodnoscGK[z];
                    wskBiezGK = Biez[i].PlodnoscGK[z];
                    ileGK = Pop[i].ilePlGK;

                 }
                 if(typ == "DystocjaCB")
                 {
                    wskPoPK = Pop[i].DystocjaCorekBuhaja;
                    wskBiezK = Biez[i].DystocjaCorekBuhaja;
                    ileK = Pop[i].ileDyCB;

                 }

                 if(typ == "Dystocja Bezposrednia")
                 {
                    wskPoPK = Pop[i].DystocjaBezposrednia;
                    wskBiezK = Biez[i].DystocjaBezposrednia;
                    ileK = Pop[i].ileDyBe;

                 }

                 if(typ == "Przezywalnosc")
                 {
                    wskPoPK = Pop[i].PrzezywalnoscP;
                    wskBiezK = Biez[i].PrzezywalnoscP;
                    ileK = Pop[i].ilePrzez;

                 }

                 if(typ == "Indeksy")
                 {
                    wskPoPK = Pop[i].IndeksyI;
                    wskBiezK = Biez[i].IndeksyI;
                    ileK = Pop[i].ileIndek;

                 }




                if(o==0) podfunkcja(i,z,k,typ,ileK,"K",wskPoPK,wskBiezK,plkSrednie, DSPop, DSBie);
                else if(o==1) podfunkcja(i,z,k,typ,ileG,"G",wskPoPG,wskBiezG,plkSrednie, DSPop, DSBie);
                else podfunkcja(i,z,k,typ,ileGK,"GK",wskPoPGK,wskBiezGK,plkSrednie, DSPop, DSBie);




            }
         }
         plkSrednie<<";;;;;;;;"<<endl;
    }
}

inline void podfunkcja(int i,int z,int k,string typ, int *ile, string rodzaj, float *wskPoP, float *wskBiez, fstream &plkSrednie, OdchylenieSt *DSPop, OdchylenieSt *DSBie)
{
    string typOceny;
    int p;
    int jj=1;
    int o = 0;
    if( typ == "Mleko" || typ =="Plodnosc" || typ == "Pokroj")
    {
        if(rodzaj =="K") typOceny = "EBV/MACE;";
        else if(rodzaj =="G") typOceny= "GPI/GMACE;";
        else typOceny= "GPI/EBV;";
    }
    else
    {
        typOceny="";
        jj=0;
    }

    if(ile[z] >0)
    {
        plkSrednie<<i+1900<<";"<<ile[z]<<";"<<typOceny<<";SD";
        for(int j=jj; j<k; j++)
        {
            if( typ == "Mleko" || typ =="Plodnosc" || typ == "Pokroj") p =j;
            else p = z;

            if(typ == "Mleko" && (j ==3||j==4))continue;
            if(typ !="Mleko" && (j==3)) continue;
            //plkSrednie<<indeks[z]<<wskPoP[j];
            plkSrednie<<wskPoP[p]/ile[z]<<";";

        }
        //plkSrednie<<DSPop[z]<<";";

        plkSrednie<<typOceny;
        for(int j=jj; j<k; j++)
        {

            if( typ == "Mleko" || typ =="Plodnosc" || typ == "Pokroj") p =j;
            else p = z;

            if(typ == "Mleko" && (j ==3||j==4))continue;
            if(typ !="Mleko" && (j==3)) continue;
            plkSrednie<<wskBiez[p]/ile[z]<<";";
        }
        //plkSrednie<<DSBie[z]<<";"<<endl;

        //plkSrednie<<endl;
    }
}
inline void WypiszSrednie(year *RokiPop, year *RokiBiez, int ileWierszy, int ileKolumn, string TypOceny, string Rodzaj, fstream &plkSrednie )
{
    plkSrednie<<Rodzaj<<endl;
    plkSrednie<<endl;

    for(int i=100; i<200; i++)
    {
        int *wskP, *wskB;

        if(TypOceny=="K")
        {
            wskP = RokiPop[i].ileK;
            wskB = RokiBiez[i].ileK;
        }
        else
        if(TypOceny=="G")
        {
            wskP = RokiPop[i].ileG;
            wskB = RokiBiez[i].ileG;
        }
        else
        if(TypOceny=="GK")
        {
            wskP = RokiPop[i].ileGK;
            wskB = RokiBiez[i].ileGK;
        }


        cout<<RokiPop[i].ile<<endl;
        if(RokiPop[i].ile >0)
        {
            plkSrednie<<"Dla roku "<<i+1900<<endl;
            plkSrednie<<endl;
            plkSrednie<<endl;

            plkSrednie<<"Ocena PoP"<<endl;

            plkSrednie<<RokiPop[i]<<endl;

            plkSrednie<<"Ocena Biez"<<endl;

            plkSrednie<<RokiBiez[i]<<endl;

        }
    }
}


//==========================================================================================================================================================
inline string wytnij(char *dane, int p1, int p2)
{
     string zm;
    for(int i=p1; i<=p2; i++)
    {

        zm += dane[i];
        if(dane[i] == '\0')break;
    }
    return zm;
}

//==========================================================================================================================================================

inline string wytnij(string dane,int p1, int p2)
{
    string zm;
    int dl = dane.length();
    for(int i=p1; i<=p2; i++)
    {

        zm += dane[i];
        if(i == dl-1) break;
    }
    return zm;

}
//=======================================================================================================================
inline int ZapiszRok(year *tab, int rokk)
{
    for(int i=0; i<100; i++)
    {
        if(tab[i].rok == rokk)
        {
            tab[i].ile++;
            break;
        }
        if(tab[i].rok ==0)
        {
            tab[i].rok =rokk;
            break;
        }
    }
    return 0;
}
inline void Zerowanie(year *tab)
{
    for(int i=0; i<100; i++)
    {
        tab[i].ile =1;
        tab[i].rok =0;
    }
}
//=======================================================================================================================
inline bool sprawdz(string p1, string p2)
{
    int i=0;
    char z1;
    char z2;
    for(i=0; i<p1.length(); i++)
    {
        z1 = p1[i];
        z2 = p2[i];
        if(z1>96 && z1<123) z1 = z1-32;
        if(z2>96 && z2<123) z2 = z2-32;
        if(z1 != z2)break;
    }
    if(z1 == z2) return 1;
    else           return 0;
}
//=====================================================================================================================
inline int LiczZnaki(char *t)
{
    int i=0;
    char *wsk = t;
    for(i=0; ; i++)
    {
        if(*wsk =='\0')break;
        wsk++;
    }
    return i;
}
//====================================================================================================================
inline bool sprawdz(char *p1, char *p2)
{
    int i=0;
    for(i=0;; i++)
    {
        if(p1[i]=='\0' || p2[i] =='\0') break;
        if(p1[i] != p2[i])break;
    }
    if(p1[i] == p2[i]) return 1;
    else           return 0;
}
//=====================================================================================================================
inline int NaInt(string lb)
{
    int cyfra=0, wynik=0;
    char znak;
    int zz =1;
    for(int i=lb.length()-1; i>=0; i--)
    {
        znak = lb[i];
        if(znak <48 || znak >57) return 0;
        cyfra = znak - 48;
        wynik = wynik + (cyfra *zz);
        zz=zz*10;

    }
    return wynik;
}

inline int pow(int lb,int pot)
{
    if(pot ==0) return 1;
    int x=1;
    for(int i=0; i<pot; i++)
    {
        x=x *lb;
    }
    return x;
}


//============================================================================================================================================================
inline int SprawdzDane(const string &dane1, const string &dane2, string nr1, string nr2, int &Stara, int &Nowa, int &Rozne, fstream &plik,int od,int doo, string rodzaj)
{
    string wycinek1 = wytnij(dane1,od,doo);
    string wycinek2 = wytnij(dane2,od,doo);

    int wynik1 = SprawdzPoprawnoscString(wycinek1);
    int wynik2 = SprawdzPoprawnoscString(wycinek2);

    if(wynik1 ==1 && wynik2 ==1)
    {
        int zmienna =sprawdz(wycinek1,wycinek2);
        if(zmienna ==0)
        {
            //cout<<nr1<<"    "<<"'"<<nazwa1<<"'   <===>   '"<<nazwa2<<"'  Rozna nazwa!!!"<<endl;
            plik<<nr1<<"   "<<nr2<<"    '"<<wycinek1<<"'   <===>   '"<<wycinek2<<"'  Rozny "<<rodzaj<<"!!!"<<endl;
            Rozne++;

        }
        return zmienna;
    }
    if(wynik1==1 && wynik2==0)
    {
        Stara++;
        //cout<<nr1<<"    "<<"'"<<nazwa1<<"'   <===>   '"<<nazwa2<<"'  Brak nazwy dla oceny biezacej!!!"<<endl;
        plik<<nr1<<"    "<<nr2<<"   '"<<wycinek1<<"'   <===>   '"<<wycinek2<<"'  Brak "<<rodzaj<<" dla oceny biezacej!!!"<<endl;
        return 0;
    }
    /*if(wynik1==0 && wynik2==1)
    {
        Nowa++;
        //cout<<nr1<<"    "<<"'"<<nazwa1<<"'   <===>   '"<<nazwa2<<"'  Brak nazwy dla oceny poprzedniej!!!"<<endl;
        plik<<nr1<<"    "<<nr2<<"   '"<<wycinek1<<"'   <===>   '"<<wycinek2<<"'  Brak "<<rodzaj<<" dla oceny poprzedniej!!!"<<endl;
        return 0;
    }*/

}
//===============================================================================================================================================


inline int SprawdzPoprawnoscString(string nazwa)
{
    int licz=0;
    for(int i=0; i<nazwa.length(); i++)
    {
        if(nazwa[i] == '*' || nazwa[i]==' ') licz++;
    }
    if(nazwa.length() == licz) return 0;
    else
        return 1;
}
//==============================================================================================================================================
inline void WczytanieDoTabeli(char **tab, int Lwierszy, fstream &plk, char **tab840, char **tabUSA, int &licz840, int &liczUSA, int LiczbaZnakow)
{
    int n =0;
    //liczUSA=0;
    //licz840 =0;
    for(int i=0; i<Lwierszy; i++)
    {
        tab[i] = new char[17];
        plk.seekg(n,ios::beg);
        plk.read(tab[i],17);
        tab[i][16] = '\0';
        cout<<tab[i]<<endl;
        if((tab[i][0]=='U')&&(tab[i][1]=='S')&&(tab[i][2]=='A'))
        {
            tabUSA[liczUSA] = tab[i];
            liczUSA++;
        }
        if((tab[i][0]=='8')&& (tab[i][1]=='4')&& (tab[i][2]=='0'))
        {
            tab840[licz840] = tab[i];
            licz840++;
        }
        //plkN1<<tab1[i]<<endl;
        n = n+LiczbaZnakow;

    }
}
//================================================================================================================================================
inline int Sprawdz840USA(const char *p1, const char *p2)
{


    int i=0;
    char z1;
    char z2;
    char U,S,A, U8,S8,A8;
    U = p1[0];
    S = p1[1];
    A = p1[2];
    U8 = p2[0];
    S8 = p2[1];
    A8 = p2[2];
    int USA=0, U88=0;

    if(U =='U' && S =='S' && A =='A' && U8 =='8' && S8 =='4' && A8 =='0') USA=1;
    else
    if(U =='8' && S =='4' && A =='0' && U8 =='U' && S8 =='S' && A8 =='A') U88=1;
    else return 0;

    if(USA==1 || U88 ==1)
        for(i=0;; i++)
        {

            z1 = p1[i];
            z2 = p2[i];
            if(z1 =='\0' || z2 =='\0') break;
            if((i==0 || i==1 || i==2) && USA==1)
            {
                if(i==0) z2 = 'U';
                if(i==1) z2 = 'S';
                if(i==2) z2 = 'A';
            }

            if((i==0 || i==1 || i==2) && U88==1)
            {
                if(i==0) z2 = '8';
                if(i==1) z2 = '4';
                if(i==2) z2 = '0';
            }

            if(z1>96 && z1<123) z1 = z1-32;
            if(z2>96 && z2<123) z2 = z2-32;
            if(z1 != z2)break;
        }
    else return 0;

    if(z1 == z2) return 1;
    else         return 0;

}
//=======================================================================================================================================
inline void SprWystepowaniaOsobnika(char **tabSN, char **tab1, char **tab2, int LwierszyI, int LwierszyJ, fstream &plk, int &licz)
{
    fstream ddd;
    ddd.open("NowaG", ios::out);
    int param=0;
    for(int i=0; i<LwierszyI; i++)
    {
        for(int j=param; j<LwierszyJ; j++)
        {
            //cout<<tab1[i]<<"====="<<tab2[j]<<endl;
            if(sprawdz(tab1[i], tab2[j])==1)        // Sprawdzenie czy nr. osobika z poprzedniej oceny == z Biezacej
            {
                param = j;
                break;
            }

            if(j==LwierszyJ-1)                      // Jeœli nie ma osobnika z poprzedniej oceny w biezacej oznacza to iz dany osobnik zosta³ wycofany
            {
                plk<<tab1[i]<<endl;             // zapis do pliku osobników tzw "starych" których nie ma w biezacej ocenie.
                tabSN[licz]=tab1[i];
                licz++;
            }
        }
    }
   tabSN[licz] = tab1[0]; // Uwaga
}
//========================================================================================================================================
inline void SprWystepowaniaOsobnika830USA(char **tab830, char **tabUSA, int Lwierszy830, int LwierszyUSA, fstream &plk, int &licz)
{
    for(int i=0; i<Lwierszy830; i++)
    {
        //cout<<"TAK"<<endl;
        for(int j=0; j<LwierszyUSA; j++)
        {
            if(sprawdz(&tab830[i][3], &tabUSA[j][3])==1)
            {
                plk<<tab830[i]<<"============="<<tabUSA[j]<<endl;
                licz++;
            }
        }
    }
}

//=========================================================================================================================================
inline void wypisz(char *t)
{
    for(int i=0; i<15; i++)
    {
        cout<<t[i];
    }
}
//========================================================================================================================================
inline void StworzTab(char **tab, int  n, int w)
{
    tab = new char*[n];

    for(int i=0; i<n; i++)
    {
        tab[i] = new char[w];
    }
}
//========================================================================================================================================
inline void UsonTab(char **tab, int  n)
{
    for(int i=0; i <n; i++)
    {
        delete [] tab[i];
    }
}


