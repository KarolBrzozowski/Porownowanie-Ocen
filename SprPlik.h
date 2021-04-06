#include<iostream>
#include<string>
#include<fstream>
#include<math.h>
#include<vector>

#define liczbaPodcech 258+50+1
#define liczbaPodcechID 26


using namespace std;
inline void wypiszOcena(int kol, int wiersz, int *ileE, float (*Dane)[7], string typ,string rodzaj, ostream &wyj, string *ind, string &podind);
inline void wypiszOcena(int kol, int *ileE, float *Dane, string typ,string rodzaj, ostream &wyp, string *ind);



//=============================================================================================================================================================
class NazwaCech{
public:
    string *indeks;
    string *podIndeks;

};


class StructPliku{


public:

    string WartoscStringPop[liczbaPodcech], WartoscStringBie[liczbaPodcech];
    int WartoscfloatPop[liczbaPodcech], WartoscfloatBie[liczbaPodcech];
    string Nazwa[liczbaPodcech];
    int LiczbaZnakow[liczbaPodcech];
    int OdZnaku[liczbaPodcech];
    int DoZnaku[liczbaPodcech];
    bool WartoscPopNull[liczbaPodcech], WartoscBieNull[liczbaPodcech];
    float WynikFloat[liczbaPodcech];
    string TabWynikowaString[liczbaPodcech];
    long long TabWynikowaInt[liczbaPodcech];




    inline void PuplikujTabWynikowa(fstream &plk)
    {
        for(int i=0; i<liczbaPodcechID; i++)
        {
            plk<<TabWynikowaString[i]+";";
        }
        for(int i=liczbaPodcechID; i<liczbaPodcech; i++)
        {
            if(TabWynikowaInt[i] != -999999)
                plk<<TabWynikowaInt[i]<<";";
        }
        plk<<endl;
    }




     inline void Zerowanie()
     {
        for(int i=0; i<liczbaPodcech-1; i++)
        {
            this->WartoscStringPop[i] = "";
             this->WartoscStringBie[i] = "";
             this->WartoscfloatPop[i] =  -999999;
             this->WartoscfloatBie[i] =  -999999;



             this->TabWynikowaInt[i] = -999999;
             this->TabWynikowaString[i] = "";
        }
     }
  // inline string wytnij(string dane,int p1, int p2);

    inline void NazwyKolumn(fstream &plk, int Od, int Do)
    {
        if(Od > 0) plk<<Nazwa[0]+";";
        for(int i=Od; i<Do; i++)
        {
            plk<<Nazwa[i]+" Pop. ;"<<Nazwa[i]+" Bie. ;"<< Nazwa[i]+" Spr. ;";
        }
        plk<<endl;
    }


    inline bool sprawdz(string p1, string p2);

    inline int pow(int lb,int pot);

    //inline int SprawdzPoprawnoscString(string &nazwa);

inline int SprawdzPoprawnoscString(string nazwa)
{
    int licz=0;
    for(int i=0; i<nazwa.length(); i++)
    {
        if(nazwa[i]==' ')nazwa[i]='*';

        if(nazwa[i] != '*') return 1;
    }

    return 0;
    /*if(nazwa.length() == licz) return 0;
    else
        return 1;*/
}

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


inline int NaInt(string lb)
{
    int cyfra=0, wynik=0, licznik=0;
    char znak;
    int zz =1;
    for(int i=lb.length()-1; i>=0; i--)
    {
        znak = lb[i];
        if(znak =='*' || znak ==' ')continue;
        if(znak <48 || znak >57) return 9999999;
        cyfra = znak - 48;
        wynik = wynik + (cyfra *zz);
        zz=zz*10;
        licznik++;

    }
    if(licznik ==0) return 9999999;
    return wynik;
}




    inline void Ustaw(fstream &plikNazw, fstream &plikPozycji)
    {

        string buf;
        getline(plikNazw,buf);
        //cout<<buf<<"=========================="<<endl;
        UstawNazwa(buf);
        UstawLiczbaZnakow(plikPozycji);


    }


    inline void UstawNazwa(string NazwaZPlk)
    {
        string buf;
        int ind =0;

        for(int i=0; i<NazwaZPlk.size(); i++)
        {
            if(NazwaZPlk[i] != ';')
            {
                Nazwa[ind] += NazwaZPlk[i];
            }
            else
            {
                //cout<<ind<<" "<<Nazwa[ind]<<"<=====>"<<endl;
                ind++;
            }
        }

    }

    inline void UstawLiczbaZnakow(fstream & plk)
    {



        int sumator=15;
        OdZnaku[0]=0;
        DoZnaku[0]=15;
        LiczbaZnakow[0]=16;

        for(int i=0; i<liczbaPodcech; i++)
        {
            //OdZnaku[i] =0;
            //DoZnaku[i] =0;
            plk>>LiczbaZnakow[i];

            if(i>0)
            {

                sumator += LiczbaZnakow[i];
                DoZnaku[i] = sumator;

                OdZnaku[i] = DoZnaku[i] - LiczbaZnakow[i]+1;
            }
        }
    }



    inline void wyswietl()
    {
        for(int i=0; i<liczbaPodcech; i++)
        {
            cout<<Nazwa[i]<<""<<this->LiczbaZnakow[i]<<"     "<<this->OdZnaku[i]<<"      "<<this->DoZnaku[i]<<endl;

        }
    }


    inline void WczytajDane(string OcenaPop, string OcenaBie)
    {
        for(int i=0; i<liczbaPodcechID; i++)
        {
             this->TabWynikowaInt[i] = -999999;
             this->TabWynikowaString[i] = "";


            WartoscStringPop[i] = wytnij(OcenaPop,OdZnaku[i],DoZnaku[i]);
            ZmienLiteryNaDuze(WartoscStringPop[i]);
            WartoscPopNull[i] = SprawdzPoprawnoscString(WartoscStringPop[i]);

            WartoscStringBie[i] = wytnij(OcenaBie,OdZnaku[i],DoZnaku[i]);
            ZmienLiteryNaDuze(WartoscStringBie[i]);
            WartoscBieNull[i] = SprawdzPoprawnoscString(WartoscStringBie[i]);


            if(WartoscPopNull[i] ==1 && WartoscBieNull[i] ==0)
            {
                TabWynikowaString[i] = "Brak Bie";
            }
            else if(WartoscPopNull[i] ==1 && WartoscBieNull[i] ==1)
            {
                if(WartoscStringPop[i] != WartoscStringBie[i])
                {
                    TabWynikowaString[i] = "Rozny";

                }

            }



        }
        for(int i=liczbaPodcechID; i<liczbaPodcech; i++)
        {
            this->TabWynikowaInt[i] = -999999;
            this->TabWynikowaString[i] = "";
            WartoscStringPop[i] = wytnij(OcenaPop,OdZnaku[i],DoZnaku[i]);  //
            //WartoscPopNull[i] = SprawdzPoprawnoscString(WartoscStringPop[i]);

            WartoscStringBie[i] = wytnij(OcenaBie,OdZnaku[i],DoZnaku[i]);
            //WartoscBieNull[i] = SprawdzPoprawnoscString(WartoscStringBie[i]);


            WartoscfloatPop[i] = NaInt(WartoscStringPop[i]); // zmiana ze string na float
            WartoscfloatBie[i] = NaInt(WartoscStringBie[i]);
//cout<<"<==================================================>"<<WartoscfloatPop[i]<<"<============================================>"<<WartoscfloatBie[i]<<endl;



            if(WartoscfloatPop[i] !=9999999 && WartoscfloatBie[i] ==9999999)
            {
                if(WartoscfloatPop[i] != 0)
                {
                    TabWynikowaString[i] = "Brak Bie";
                    TabWynikowaInt[i]=-9999999;
                }
            }
            else if(WartoscfloatPop[i] !=9999999 && WartoscfloatBie[i] !=9999999)
            {
                if(WartoscfloatPop[i]==0)
                {
                    WartoscfloatPop[i]+=1;
                    WartoscfloatBie[i]+=1;
                }

                float procent;
                //if(i>=26 && i<=69)
                    procent = ((WartoscfloatBie[i]- WartoscfloatPop[i])/(WartoscfloatPop[i]))*100;
                //else
                  //  procent = (WartoscfloatBie[i]- WartoscfloatPop[i])/100;


                if(WartoscfloatPop[i] !=  WartoscfloatBie[i])
                {
                    TabWynikowaString[i] = "Rozny";
                }
                if(procent > 6 || procent < -6)
                {
                    TabWynikowaInt[i] = long(procent);
                    //cout<<WartoscStringBie[0]<<"   ==>"<<WartoscfloatPop[i]<<"   ==>"<<WartoscfloatBie[i]<<"   == ==>"<<procent<<  " ==  ====>"<<WartoscStringPop[i]<<" ===>>>"<< WartoscStringBie[i]<<endl;
                }

            }


        }
       // cout<<endl;
          //  cout<<endl;
          //  cout<<endl;
    }


   /* Frontenac
    Leon Millot
    Marechal Foch
    Regent
    Sabrevois*/


    inline void Publikuj(fstream &plk, int Od, int Do, string rodzaj)
    {

        if(rodzaj == "ID")
        {
            if(SprawdzNULL(Od,Do,rodzaj) == 1)
            {

                for(int i=Od; i<Do; i++)
                {
                    plk<<WartoscStringPop[i]<<";"<<WartoscStringBie[i]<<";"<<TabWynikowaString[i]<<";";
                }
                plk<<endl;
            }
        }
        else
        {
            if(SprawdzNULL(Od,Do,rodzaj) == 1)
            {
                plk<<WartoscStringPop[0]+";";
                for(int i=Od; i<Do; i++)
                {
                    if(TabWynikowaInt[i] == -999999)
                        plk<<";;;";
                    else
                    {
                        if(TabWynikowaInt[i]==-9999999)
                            plk<<WartoscfloatPop[i]<<";"<<WartoscfloatBie[i]<<";"<<TabWynikowaString[i]<<";";
                        else
                        {
                                plk<<WartoscfloatPop[i]<<";"<<WartoscfloatBie[i]<<";"<<TabWynikowaInt[i]<<";";

                        }
                    }
                }
                plk<<endl;
            }
        }




    }











    inline void ZmienLiteryNaDuze(string &Napis)
    {
        for(int i=0; i<Napis.size(); i++)
        {
            if(Napis[i] >= 97 && Napis[i] <= 122) Napis[i] = Napis[i] -32;
        }
    }

    inline bool SprawdzNULL(int Od , int Do, string rodzaj)
    {
        int ile = Do - Od;
        int licz=0;


       if(rodzaj=="ID")
       {
          for(int i=Od; i<=Do ; i++)
          {
             if(TabWynikowaString[i] != "") return 1;
          }
       }
       else
       {
           for(int i=Od; i<=Do ; i++)
           {
             if(TabWynikowaInt[i] != -999999)return 1;
           }
       }


        return 0;

    }
//    jhg555fhginline void PublikujM12322   jhgfjkjhddghnkjhjhggjhhgjhflhhkjggvgjhg vvvvvvvgvg hgdkddhgk11111111214100lkllk hjghjgfuuuuu hghghgtf  ygcrvveko









};

/*inline string wytnij(string dane,int p1, int p2)
{
    string zm;
    int dl = dane.length();
    for(int i=p1; i<=p2; i++)
    {

        zm += dane[i];
        if(i == dl-1) break;
    }
    return zm;

}*/
//=======================================================================================================================


struct year{
    int rok;
    int ile;
    int ileK[6],ileG[6],ileGK[6];
    int ilePoK[22], ilePoG[22], ilePoGK[22];
    int ilePlK[4], ilePlG[4], ilePlGK[4];
    int ileDyCB[10], ileDyBe[10], ilePrzez[3], ileIndek[9];

    float MlekoK[6][7],MlekoG[6][7],MlekoGK[6][7];
   // std::vector<short>VekMlekoK[6], VekMlekoG[6], VekMlekoGK[6];
    float PokrojK[22][7], PokrojG[22][7], PokrojGK[22][7];
    float PlodnoscK[4][7], PlodnoscG[4][7], PlodnoscGK[4][7];
    float DystocjaCorekBuhaja[10];
    float DystocjaBezposrednia[10];
    float PrzezywalnoscP[3];
    float IndeksyI[9];
    inline void zerowanie()
    {
        rok = 0;
        ile = 0;
        for(int i=0; i<6; i++)
        {
            ileK[i]=0;
            ileG[i]=0;
            ileGK[i]=0;
            for(int j=0; j<7; j++)
            {
                 MlekoK[i][j]=0;
                 MlekoG[i][j]=0;
                 MlekoGK[i][j]=0;
            }
        }

        for(int i=0; i<22; i++)
        {
            ilePoK[i]=0;
            ilePoG[i]=0;
            ilePoGK[i]=0;
            for(int j=0; j<6; j++)
            {
                 PokrojK[i][j]=0;
                 PokrojG[i][j]=0;
                 PokrojGK[i][j]=0;
            }
        }

        for(int i=0; i<4; i++)
        {
            ilePlK[i]=0;
            ilePlG[i]=0;
            ilePlGK[i]=0;
            for(int j=0; j<6; j++)
            {
                 PlodnoscK[i][j]=0;
                 PlodnoscG[i][j]=0;
                 PlodnoscGK[i][j]=0;
            }
        }

        for(int i=0; i<10; i++)
        {
            ileDyCB[i]=0;
            ileDyBe[i]=0;
            DystocjaCorekBuhaja[i]=0;
            DystocjaBezposrednia[i]=0;
        }
        for(int i=0; i<3; i++)
        {
            ilePrzez[i]=0;
            PrzezywalnoscP[i]=0;
        }
        for(int i=0; i<9; i++)
        {
            ileIndek[i]=0;
            IndeksyI[i]=0;
        }


    }
    void fun(int wiersz, int kolumn, float *dana, int *ile)
        {
            for(int i=0; i<wiersz; i++)
            {
                ile[i] =0;

                for(int j=0; j<kolumn; j++)
                {

                }
            }
        };
     friend ostream & operator<< (ostream &wyjscie, const year &s);
    //friend void SprawdzDaneMleko(WartoscMleko &OcenaPop, WartoscMleko &OcenaBie, fstream &RaportMleko, string nr1, string nr2, year TabelaRocznikowPop, year TabelaRocznikowBiez, int rok );

};






// Dodano !!!!
class OdchylenieSt{

   public:
   int rok;
   std::vector<int>VekMlekoK[6], VekMlekoG[6], VekMlekoGK[6],VekPokrojK[22], VekPokrojG[22], VekPokrojGK[22],
                    VekPlodnoscK[4],VekPlodnoscG[4],VekPlodnoscGK[4], VekDystocjaCB[10], VekDystocjaBezp[10], VekPrzezywalnosc[3],VekIndeksy[10];


   double DSMlekoK[6], DSMlekoG[6], DSMlekoGK[6],DSPokrojK[22], DSPokrojG[22], DSPokrojGK[22],DSPlodnoscK[4],
           DSPlodnoscG[4],DSPlodnoscGK[4], DSDystocjaCB[10], DSDystocjaBezp[10],DSPrzezywalnosc[3], DSIndeksy[10];



   inline void LiczDSMleko(year &Roki) // rodzaj 1-Mleko, 2-Pokroj, 3-Plodnosc,
   {


        this->rok = Roki.rok;
       for(int i=0; i<6; i++)
       {

           DSMlekoK[i] =0;
           DSMlekoG[i]=0;
           DSMlekoGK[i]=0;

            int dlugoscK = (VekMlekoK[i]).size();
            int dlugoscG = (VekMlekoG[i]).size();
            int dlugoscGK = (VekMlekoGK[i]).size();


           float sredniaK = Roki.MlekoK[i][6]/Roki.ileK[i];
           float sredniaG = Roki.MlekoG[i][6]/Roki.ileG[i];
           float sredniaGK = Roki.MlekoGK[i][6]/Roki.ileGK[i];


           if(dlugoscK >0 && Roki.ileK[i] >0)
           {
               for(int j=0; j<dlugoscK; j++)
               {

                   int liczba = VekMlekoK[i][j];

                   DSMlekoK[i] += ((liczba - sredniaK)*(liczba - sredniaK));
               }
               DSMlekoK[i] = sqrt((1*DSMlekoK[i])/(Roki.ileK[i]-1));
               cout<<"  Konwenc  "<<i<<"   " <<int(DSMlekoK[i])<<"   "<<Roki.ileK[i]<<"   "<<dlugoscK<<"    "<<sredniaK<<endl;
           }

           if(dlugoscG >0 && Roki.ileG[i] >0)
           {
               for(int j=0; j<dlugoscG; j++)
               {
                   int liczba = VekMlekoG[i][j];
                   DSMlekoG[i] += ( liczba - sredniaG )*( liczba -sredniaG );

               }
               DSMlekoG[i] = sqrt((1*DSMlekoG[i])/(Roki.ileG[i]-1));
               cout<<"  Genom  "<<i<<"   "<<int(DSMlekoG[i])<<"   "<<Roki.ileG[i]<<"   "<<dlugoscG<<"    "<<sredniaG<<endl;
           }

        if(dlugoscGK >0 && Roki.ileGK[i] >0)
        {

           for(int j=0; j<dlugoscGK; j++)
           {

               int liczba = VekMlekoGK[i][j];
               DSMlekoGK[i] += ( liczba - sredniaGK )*( liczba - sredniaGK);

           }
           DSMlekoGK[i] = sqrt((1*DSMlekoGK[i])/(Roki.ileGK[i]-1));
	       cout<<"  Geno-Konwenc  "<<i<<"   "<<int(DSMlekoGK[i])<<"   "<<Roki.ileGK[i]<<"   "<<dlugoscGK<<"    "<<sredniaGK<<endl;

        }

       }

    };

   inline void LiczDSPokroj(year &Roki)
   {
       this->rok = Roki.rok;
       for(int i=0; i<22; i++)
       {

           DSPokrojK[i] =0;
           DSPokrojG[i]=0;
           DSPokrojGK[i]=0;

            int dlugoscK = (VekPokrojK[i]).size();
            int dlugoscG = (VekPokrojG[i]).size();
            int dlugoscGK = (VekPokrojGK[i]).size();


           float sredniaK = Roki.PokrojK[i][5]/Roki.ilePoK[i];
           float sredniaG = Roki.PokrojG[i][5]/Roki.ilePoG[i];
           float sredniaGK = Roki.PokrojGK[i][5]/Roki.ilePoGK[i];


           if(dlugoscK >1 && Roki.ilePoK[i] >1)
           {
               for(int j=0; j<dlugoscK; j++)
               {

                   int liczba = VekPokrojK[i][j];

                   DSPokrojK[i] += ((liczba - sredniaK)*(liczba - sredniaK));
               }
               DSPokrojK[i] = sqrt((1*DSPokrojK[i])/(Roki.ilePoK[i]-1));
               cout<<" PPP Konwenc  "<<i<<"   "<<int(DSPokrojK[i])<<"   "<<Roki.ilePoK[i]<<"   "<<dlugoscK<<"    "<<sredniaK<<endl;
           }

           if(dlugoscG >1 && Roki.ilePoG[i] >1)
           {
               for(int j=0; j<dlugoscG; j++)
               {
                   int liczba = VekPokrojG[i][j];
                   DSPokrojG[i] += ( liczba - sredniaG )*( liczba -sredniaG );

               }
               DSPokrojG[i] = sqrt((1*DSPokrojG[i])/(Roki.ilePoG[i]-1));
               cout<<" PPP Genom  "<<i<<"   "<<int(DSPokrojG[i])<<"   "<<Roki.ilePoG[i]<<"   "<<dlugoscG<<"    "<<sredniaG<<endl;
           }

        if(dlugoscGK >1 && Roki.ilePoGK[i] >1)
        {

           for(int j=0; j<dlugoscGK; j++)
           {

               int liczba = VekPokrojGK[i][j];
               DSPokrojGK[i] += ( liczba - sredniaGK )*( liczba - sredniaGK);

           }
           DSPokrojGK[i] = sqrt((1*DSPokrojGK[i])/(Roki.ilePoGK[i]-1));
	       cout<<"PPP  Grno-Konwenc  "<<i<<"   "<<int(DSPokrojGK[i])<<"   "<<Roki.ilePoGK[i]<<"   "<<dlugoscGK<<"    "<<sredniaGK<<endl;

        }

       }
   };


   inline void LiczDSPlodnosc(year &Roki) // rodzaj 1-Plodnosc, 2-Pokroj, 3-Plodnosc,
   {


        this->rok = Roki.rok;
       for(int i=0; i<4; i++)
       {

           DSPlodnoscK[i] =0;
           DSPlodnoscG[i]=0;
           DSPlodnoscGK[i]=0;

            int dlugoscK = (VekPlodnoscK[i]).size();
            int dlugoscG = (VekPlodnoscG[i]).size();
            int dlugoscGK = (VekPlodnoscGK[i]).size();


           float sredniaK = Roki.PlodnoscK[i][5]/Roki.ilePlK[i];
           float sredniaG = Roki.PlodnoscG[i][5]/Roki.ilePlG[i];
           float sredniaGK = Roki.PlodnoscGK[i][5]/Roki.ilePlGK[i];


           if(dlugoscK >0 && Roki.ilePlK[i] >0)
           {
               for(int j=0; j<dlugoscK; j++)
               {

                   int liczba = VekPlodnoscK[i][j];

                   DSPlodnoscK[i] += ((liczba - sredniaK)*(liczba - sredniaK));
               }
               DSPlodnoscK[i] = sqrt((1*DSPlodnoscK[i])/(Roki.ilePlK[i]-1));
               cout<<"  Konwenc  "<<i<<"   " <<int(DSPlodnoscK[i])<<"   "<<Roki.ilePlK[i]<<"   "<<dlugoscK<<"    "<<sredniaK<<endl;
           }

           if(dlugoscG >0 && Roki.ilePlG[i] >0)
           {
               for(int j=0; j<dlugoscG; j++)
               {
                   int liczba = VekPlodnoscG[i][j];
                   DSPlodnoscG[i] += ( liczba - sredniaG )*( liczba -sredniaG );

               }
               DSPlodnoscG[i] = sqrt((1*DSPlodnoscG[i])/(Roki.ilePlG[i]-1));
               cout<<"  Genom  "<<i<<"   "<<int(DSPlodnoscG[i])<<"   "<<Roki.ilePlG[i]<<"   "<<dlugoscG<<"    "<<sredniaG<<endl;
           }

        if(dlugoscGK >0 && Roki.ilePlGK[i] >0)
        {

           for(int j=0; j<dlugoscGK; j++)
           {

               int liczba = VekPlodnoscGK[i][j];
               DSPlodnoscGK[i] += ( liczba - sredniaGK )*( liczba - sredniaGK);

           }
           DSPlodnoscGK[i] = sqrt((1*DSPlodnoscGK[i])/(Roki.ilePlGK[i]-1));
	       cout<<"  Grno-Konwenc  "<<i<<"   "<<int(DSPlodnoscGK[i])<<"   "<<Roki.ilePlGK[i]<<"   "<<dlugoscGK<<"    "<<sredniaGK<<endl;

        }

       }

    };



   inline void LiczDSDystocjaCB(year &Roki) // rodzaj 1-Plodnosc, 2-Pokroj, 3-Plodnosc,
   {


        this->rok = Roki.rok;
       for(int i=0; i<10; i++)
       {

           DSDystocjaCB[i] =0;


            int dlugosc = (VekDystocjaCB[i]).size();


           float srednia = Roki.DystocjaCorekBuhaja[i]/Roki.ileDyCB[i];


           if(dlugosc >0 && Roki.ileDyCB[i] >0)
           {
               for(int j=0; j<dlugosc; j++)
               {

                   int liczba = VekDystocjaCB[i][j];

                   DSDystocjaCB[i] += ((liczba - srednia)*(liczba - srednia));
               }
               DSDystocjaCB[i] = sqrt((1*DSDystocjaCB[i])/(Roki.ileDyCB[i]-1));
               cout<<"  *  "<<i<<"   " <<int(DSDystocjaCB[i])<<"   "<<Roki.ileDyCB[i]<<"   "<<dlugosc<<"   "<<srednia<<endl;
           }

       }

    };


    inline void LiczDSDystocjaBezp(year &Roki) // rodzaj 1-Plodnosc, 2-Pokroj, 3-Plodnosc,
   {


        this->rok = Roki.rok;
       for(int i=0; i<10; i++)
       {

           DSDystocjaBezp[i] =0;


            int dlugosc = (VekDystocjaBezp[i]).size();


           float srednia = Roki.DystocjaBezposrednia[i]/Roki.ileDyBe[i];


           if(dlugosc >0 && Roki.ileDyBe[i] >0)
           {
               for(int j=0; j<dlugosc; j++)
               {

                   int liczba = VekDystocjaBezp[i][j];

                   DSDystocjaBezp[i] += ((liczba - srednia)*(liczba - srednia));
               }
               DSDystocjaBezp[i] = sqrt((1*DSDystocjaBezp[i])/(Roki.ileDyBe[i]-1));
               cout<<"  **  "<<i<<"   " <<int(DSDystocjaBezp[i])<<"   "<<Roki.ileDyBe[i]<<"   "<<dlugosc<<"   "<<srednia<<endl;
           }

       }

    };



    inline void LiczDSPrzezywalnosc(year &Roki) // rodzaj 1-Plodnosc, 2-Pokroj, 3-Plodnosc,
   {


       this->rok = Roki.rok;
       for(int i=0; i<3; i++)
       {

           DSPrzezywalnosc[i] =0;


            int dlugosc = (VekPrzezywalnosc[i]).size();


           float srednia = Roki.PrzezywalnoscP[i]/Roki.ilePrzez[i];


           if(dlugosc >0 && Roki.ilePrzez[i] >0)
           {
               for(int j=0; j<dlugosc; j++)
               {

                   int liczba = VekPrzezywalnosc[i][j];

                   DSPrzezywalnosc[i] += ((liczba - srednia)*(liczba - srednia));
               }
               DSPrzezywalnosc[i] = sqrt((1*DSPrzezywalnosc[i])/(Roki.ilePrzez[i]-1));
               cout<<"  ***  "<<i<<"   " <<int(DSPrzezywalnosc[i])<<"   "<<Roki.ilePrzez[i]<<"   "<<dlugosc<<"   "<<srednia<<endl;
           }

       }

    };

    inline void LiczDSIndeksy(year &Roki) // rodzaj 1-Plodnosc, 2-Pokroj, 3-Plodnosc,
   {


        this->rok = Roki.rok;
       for(int i=0; i<10; i++)
       {

           DSIndeksy[i] =0;


            int dlugosc = (VekIndeksy[i]).size();


           float srednia = Roki.IndeksyI[i]/Roki.ileIndek[i];


           if(dlugosc >0 && Roki.ileIndek[i] >0)
           {
               for(int j=0; j<dlugosc; j++)
               {

                   int liczba = VekIndeksy[i][j];

                   DSIndeksy[i] += ((liczba - srednia)*(liczba - srednia));
               }
               DSIndeksy[i] = sqrt((1*DSIndeksy[i])/(Roki.ileIndek[i]-1));
               cout<<"  ****  "<<i<<"   " <<int(DSIndeksy[i])<<"   "<<Roki.ileIndek[i]<<"   "<<dlugosc<<"   "<<srednia<<endl;
           }

       }

    };
   inline void wyswietl()
   {
       for(int i=0; i<6; i++)
       {
           cout<<rok<<" i "<<i <<" "<<DSMlekoK[i]<<" "<<DSMlekoG[i]<<" "<<DSMlekoGK[i]<<endl;
       }
   };


};


ostream & operator<< (ostream &wyjscie, year &s)
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

    //string WartoscDystocjaCB[10]={"Liczba Ocielonych Corek","Porody Samodzielne *100%","Porody Latwe *100%","Porody Trudne *100%",
                                 // "Porody Ciezkie *100%","Poronienia *100%","Cesarskie Ciecia *100%","Liczba cielat buhaja","Zywo Urodzone *100%","Martwo Urodzone *100%"};


    wypiszOcena(6,7,s.ileK,s.MlekoK,"EBV/MACE","Mleko",wyjscie, WartMleko,PodindWM );

    wypiszOcena(6,7,s.ileG,s.MlekoG,"GPI/GMACE","Mleko",wyjscie, WartMleko,PodindWM );

    wypiszOcena(6,7,s.ileGK,s.MlekoGK,"GPI/EBV","Mleko",wyjscie, WartMleko,PodindWM );
    wyjscie<<endl;

    wypiszOcena(22,6,s.ilePoK,s.PokrojK,"EBV/MACE","Pokroj",wyjscie, WartoscPokroj,PodindPoz);

    wypiszOcena(22,6,s.ilePoG,s.PokrojG,"GPI/GMACE","Pokroj",wyjscie, WartoscPokroj,PodindPoz);

    wypiszOcena(22,6,s.ilePoGK,s.PokrojGK,"GPI/EBV","Pokroj",wyjscie, WartoscPokroj,PodindPoz);
    wyjscie<<endl;

    wypiszOcena(4,6,s.ilePlK,s.PlodnoscK,"EBV/MACE","Plodnosc",wyjscie, WartoscPlod, PodindPoz);

    wypiszOcena(4,6,s.ilePlG,s.PlodnoscG,"GPI/GMACE","Plodnosc",wyjscie, WartoscPlod, PodindPoz);

    wypiszOcena(4,6,s.ilePlGK,s.PlodnoscGK,"GPI/EBV","Plodnosc",wyjscie, WartoscPlod, PodindPoz);
    wyjscie<<endl;

    wypiszOcena(10,s.ileDyCB,s.DystocjaCorekBuhaja,"","DystocjaCB",wyjscie,WartoscDystocjaCB);
    wypiszOcena(10,s.ileDyBe,s.DystocjaBezposrednia,"","DystocjaBE",wyjscie,WartoscDystocjaCB);
    wypiszOcena(3,s.ilePrzez,s.PrzezywalnoscP,"","Przezywalnosc",wyjscie,WartoscPrze);
    wypiszOcena(9,s.ileIndek,s.IndeksyI,"","Indeksy",wyjscie,WartoscIn);




   return wyjscie;
}

inline void wypiszOcena(int kol, int wiersz, int *ileE, float (*Dane)[7], string typ,string rodzaj, ostream &wyp, string *ind, string &podind)
{


    for(int i=0; i<kol; i++)
    {
        if(ileE[i]>0)
        {
            wyp<<rodzaj<<";Liczba Osobnkow;"<<podind<<endl;
            break;
        }

    }

     for(int i=0; i<kol; i++)
    {
        int ile = ileE[i];
        if(ile>0)
        {
            wyp<<ind[i]<<";"<<ile<<";"<<typ<<";";

            if(rodzaj != "Mleko")
                wyp<<Dane[i][1]/ile<<";"<<Dane[i][2]/ile<<";"<<Dane[i][4]/ile<<";"<<Dane[i][5]/ile<<";";
            else
                wyp<<Dane[i][1]/ile<<";"<<Dane[i][2]/ile<<";"<<Dane[i][5]/ile<<";"<<Dane[i][6]/ile<<";";

            wyp<<endl;
        }
    }
    wyp<<endl;
}


inline void wypiszOcena(int kol, int *ileE, float *Dane, string typ,string rodzaj, ostream &wyp, string *ind)
{

   // cout<<"DDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDD"<<endl;
   for(int i=0; i<kol; i++)
    {
        if(ileE[i]>0)
        {
            wyp<<rodzaj<<";Liczba Osobnkow;Wartosci;"<<endl;
            break;
        }

    }

     for(int i=0; i<kol; i++)
    {
        int ile = ileE[i];
        if(ile>0)
        {

            wyp<<ind[i]<<";"<<ile<<";"<<Dane[i]/ile<<";"<<endl;
            //cout<<ind[i]<<";"<<ile<<";"<<Dane[i]/ile<<";"<<endl;


        }
    }
    wyp<<endl;

}
//===========================================================================================================================================================
//===========================================================================================================================================================
//===========================================================================================================================================================

class Komorka{

    public:
    int dane;
    bool dlaWH;
    int PlusZnakow;
    int DoZnaku;

    void UstawKomorka(int PZ,int DZ)
    {
        this->PlusZnakow =PZ;
        this->DoZnaku =DZ;
    };

    inline void wycinanie(string &wiersz)
    {
        this->dlaWH =0;
        string napis;
        string zm;
        int dl = wiersz.length();
        bool Minus =0;
        int ii=0;
        int licz=0;
        int jjj=0;
        for(ii=PlusZnakow; ii<=DoZnaku; ii++)
        {
            if(wiersz[ii]=='-') Minus =1;
            if(wiersz[ii]>=48 && wiersz[ii]<=57)
                zm += wiersz[ii];
            else
               licz++;
            if(ii == dl-1) break;
            //cout<<wiersz[i];
            jjj++;
        }

        if(jjj == licz)dlaWH =1;
        //cout<<zm<<" ========kkk=======>"<<PlusZnakow<<"=========="<<DoZnaku<<"================" <<jjj<<"======"<<licz<<endl;
        int cyfra=0, wynik=0;
        char znak;
        int zz =1;
        for(int i=zm.length()-1; i>=0; i--)
        {
            znak = zm[i];
            if(znak <48 || znak >57)
            {
                wynik =0;
                break;
            }
            cyfra = znak - 48;
            wynik = wynik + (cyfra *zz);
            zz=zz*10;

        }
        if(Minus ==1) wynik=wynik*(-1);
        this->dane = wynik;
    };

    friend ostream & operator<< (ostream &wyjscie, const Komorka &s);
    bool operator == (const Komorka &q) {return dane==q.dane;}
    bool operator == (const int &q) {return dane==q;}

    bool operator < (Komorka const &q) const {return dane < q.dane;};
    bool operator < (int const &q) const {return dane < q;};

    bool operator <= (Komorka const &q) const {return dane <= q.dane;};
    bool operator <= (int const &q) const {return dane <= q;};

    bool operator > (Komorka const &q) const {return dane > q.dane;};
    bool operator > (int const &q) const {return dane > q;};

    bool operator >= (Komorka const &q) const {return dane >= q.dane;};
    bool operator >= (int const &q) const {return dane >= q;};


    bool operator != (Komorka const &q) const {return dane != q.dane;};
    bool operator != (int const &q) const {return dane != q;};



};

ostream & operator<< (ostream &wyjscie, const Komorka &s)
{
   return wyjscie <<s.dane;
}

//============================================================================================================================================================




//===========================================================================================================================================================


//===========================================================================================================================================================================================


//***************************************************************************************************
//***************************************************************************************************
//***************************************************************************************************
//***************************************************************************************************
//***************************************************************************************************
//***************************************************************************************************
//***************************************************************************************************
//***************************************************************************************************
//***************************************************************************************************
//********************ZMIANA 02,03-20201*************************************************************
//***************************************************************************************************
//***************************************************************************************************
//***************************************************************************************************
//***************************************************************************************************
//***************************************************************************************************
//***************************************************************************************************
//***************************************************************************************************
//***************************************************************************************************
//***************************************************************************************************
//***************************************************************************************************
//***************************************************************************************************


class Wartosc{

    public:
    int odZnaku;
    int ileElementow;

    Komorka *Podindeksy;




    /*Wartosc(int odZ, int ileE )
    {
        odZnaku = odZ;
        ileElementow = ileE;
        Podindeksy = new Komorka[ileE];


    }*/


    inline void UstawWartosc(int *tabPodindeks, int odZ, int ileE)
    {
         odZnaku = odZ;
        ileElementow = ileE;
        Podindeksy = new Komorka[ileE];
        int n=0;



        // 1,5,6,2,6      Laktoza, Workability, Calving,  Pokroj(lokomotinon, body condy)
        // 1,5,6,6,2,6    Pokroj, plodnosc,
        // 1,5,6,6,6,2,6  Mleko


        int doZnaku=odZnaku;


        if(ileE >1){
            Podindeksy[0].UstawKomorka(odZnaku,doZnaku);       // jeœli mamy przypadek z brakiem podech np dystocja
            n=1;
        }
        for(int i=n; i<ileElementow; i++){

            doZnaku = odZnaku+tabPodindeks[i]; //(0+5)(=5)  ,,,(5+6)(=11) ,,, (11+6)(=17)
            if(ileE>1)odZnaku++;                          //(0+1)(=1) ,,,(5+1)(=6) ,,, // jezel brak podcech
            Podindeksy[i].UstawKomorka(odZnaku, doZnaku);
            odZnaku += tabPodindeks[i];             //(1+5)(=6) ,,,(6+6)(=12)
            odZnaku--;                              //(6-1)(5)  ,,,(12-1)(=11)
        }

    };

    ~Wartosc(){
        delete [] Podindeksy;
    }

    inline void wycinanie(string &wiersz, int ileElementow)
    {
        string napis;

        for(int j=0; j<ileElementow; j++)
        {
            Podindeksy[j].wycinanie(wiersz);
        }
        //if(Podindeksy[4].dane !=0) Podindeksy[4].dane = (Podindeksy[4].dane)/100;
        //if(Podindeksy[5].dane !=0) Podindeksy[5].dane = (Podindeksy[5].dane)/100;
    };




    void wyjscie(int ile)
    {
        for(int i=0; i<ileElementow; i++)
        {
            cout<<Podindeksy[i].dane<<" ";
        }
    }

};



//==========================================================================================================================================================
//==========================================================================================================================================================
//==========================================================================================================================================================
//***************************************************************************************************
//***************************************************************************************************
//***************************************************************************************************
//***************************************************************************************************
//***************************************************************************************************
//***************************************************************************************************
//***************************************************************************************************
//***************************************************************************************************
//***************************************************************************************************
//********************ZMIANA 02,03-20201*************************************************************
//***************************************************************************************************
//***************************************************************************************************
//***************************************************************************************************
//***************************************************************************************************
//***************************************************************************************************
//***************************************************************************************************
//***************************************************************************************************
//***************************************************************************************************
//***************************************************************************************************
//***************************************************************************************************

class Ocena{
    //======= Ocena Mleczna ======
    public:
    Wartosc *Cechy;
    int lbCech;
    int lbPodCech;
    string rodzaj;


    void UstawZakres(int odZnaku, string rodzaj, int lbCech, int lbPodCech)
    {
        this->lbCech = lbCech;
        this->lbPodCech = lbPodCech;
        this->rodzaj = rodzaj;

        this->Cechy = new Wartosc[lbCech];
        // mleko 213,246,278,310,342,374
        //pokroj

        int odZnakuWew = odZnaku;
        int liczbaZnakow = 0;
        int tabElementow0[] = {1,2,6};
        int tabElementow1[] = {1,5,6,2,6,0,0};
        int tabElementow2[] = {1,5,6,6,2,6,0};
        int tabElementow3[] = {1,5,6,6,6,2,6};


        int *tabElementow = &tabElementow1[1];
        if(lbPodCech ==3) tabElementow = tabElementow0;
        else if(lbPodCech ==5)tabElementow =tabElementow1;
        else if(lbPodCech ==6)  tabElementow = tabElementow2;
        else if(lbPodCech ==7)  tabElementow =tabElementow3;      // Tworzenie tabel przechowujacych liczbe znakow dla kazdej podcechy



        for(int i=0; i<lbPodCech; i++)
            liczbaZnakow +=tabElementow[i];                        // Wyliczenie skoku znakowego pomiedzy cechami




        for(int i=0; i<lbCech; i++)
        {

            this->Cechy[i].UstawWartosc( tabElementow,odZnaku,lbPodCech);   //Ustawienie wartosci dla kazdej cechy

            if(rodzaj =="mleko" && i==0) {this->Cechy[0].Podindeksy[6].DoZnaku =213+32;odZnaku++;}  // Ustawienie wartosci tylko dla mleko kg wartosc hodowlana zapisana na 7 znakach

            odZnaku += liczbaZnakow;

        }

    };






    inline void UstawDane(string &dane)
    {
        for(int i=0; i<lbCech; i++)
        {
            this->Cechy[i].wycinanie(dane,lbPodCech);
        }
    };



    ~Ocena(){
        delete[] Cechy;
    };



    void wyswietl()
    {
        for(int i=0; i<lbCech; i++)
        {
            Cechy[i].wyjscie(lbPodCech);
            cout<<endl;
        }
    };

    inline friend void SprawdzDane(Ocena &OcenaPop, Ocena &OcenaBie, fstream &RaportMleko, string nr1, string nr2, year &TabelaRocznikowPop, year &TabelaRocznikowBiez, const string &OcenionyWKraju, OdchylenieSt &DSPop, OdchylenieSt &DSBie);
    inline friend void NazwaCechIPc (string rodzaj, string &wartosc, string &podindeksWartosc);



};


inline void SprawdzDane(Ocena &OcenaPop, Ocena &OcenaBie, fstream &RaportMleko, string nr1, string nr2, year &TabelaRocznikowPop, year &TabelaRocznikowBiez,const string &OcenionyWKraju, OdchylenieSt &DSPop, OdchylenieSt &DSBie)
{


        string wartoscMleko[6]= {"Mleko[Kg]","Tluszcz[Kg]","Tluszcz[%]","Bialko[Kg]","Bialko[%]","Komorki Somatyczne"};

        string wartoscPokroj[22]={"Kaliber","Typ i budowa","Nogi i racice","Ocena ogolna wymiona","Budowa Ogolna","Wysokosc w krzyzu","Glebokosc tulowia","Szerokosc klati piersiowej",
                                   "Ustawienie zadu","Szerokosc zadu","Nogi tylne - widoku z boku","Racice","Nogi tylne - widok z tylu","Zawieszenie przednie wymiona","Zawieszenie tylne wymiona",
                                   "Wiezadlo srodkowe wymiona","Polozenie wymiona","Szerokosc wymiona","Ustawienie strzykow","Dlugosc sztrzykow","Ustawienie strzykow tylnych","Charakter mleczny"};

        string wartoscPlodnosc[4]={"Wskaznik nie powtarzalnosci unasiennienia jalowek (NRj)","Wskaznik nie powtarzalnosci unasiennienia krow (NRk)","Przestoj poporodowy (PP)","Odstep miedzyciazowy (OMC)"};

        string wartoscPrzezywalnosc[1]={"Przezywalnosc"};

        string wartoscLaktoza[2] = {"Laktoza kg","Laktoza %"};

        string wartoscWorkability[2] = {"Szybkosc oddawania mleka","Temperament"};

        string wartoscCalving[4] = {"Przebieg porodu bezposredni","Przebieg Porodu Mateczny","Przezywalnosc cielont bezp.","Przezywalnosc cielat mateczna"};

        string wartoscPokroj2[2] = {"Locomotion","Body Condition Score"};


        string podindeksWartoscMleko[7] = {"Typ Oceny","Liczba Obor","Liczba Corek","Liczba Corek Efektywnych","EDC","Powtarzalnosc","Wartosc Hodowlana"};

        string podindeksWartoscPP1[6] = {"Typ Oceny","Liczba Obor","Liczba Corek","EDC","Powtarzalnosc","Wartosc Hodowlana"};
        string podindeksPrzezywalnosc[3] = {"Typ Oceny","Powtarzalnosc","Wartosc Hodowlana"};
        string podindeksWartoscPP2[5] = {"Typ Oceny","Liczba Obor","Liczba Corek","Powtarzalnosc","Wartosc Hodowlana"};


        string wartoscDystocjaCB[10]={"Liczba Ocielonych Corek","Porody Samodzielne Proc100x","Porody Latwe Proc100x","Porody Trudne Proc100x","Porody Ciezkie Proc100x","Poronienia Proc 100x",
                                      "Cesarskie Ciecia Proc100x","Liczba Urodzonych Cielat","Zywo Urodzone Proc100x","Martwo Urodzone Proc100x"};









    int lbCach = OcenaPop.lbCech;
    int lbPodCech = OcenaPop.lbPodCech;
    string rodzaj = OcenaPop.rodzaj;
    string *wartosc, *podindeksWartosc;
    int wartoscDlaLbObora = 10;
    if(rodzaj =="mleko") wartoscDlaLbObora = 0;
    int liczK=0;
    int liczG=0;
    int liczGK=0;

    TabelaRocznikowPop.ile++;
    TabelaRocznikowBiez.ile++;
    int ile =0;



             if (rodzaj == "mleko"){
                wartosc = wartoscMleko;
                podindeksWartosc = podindeksWartoscMleko;
                }
        else if (rodzaj == "pokroj"){
                wartosc = wartoscPokroj;
                podindeksWartosc = podindeksWartoscPP1;
                }
        else if (rodzaj == "plodnosc"){
                wartosc = wartoscPlodnosc;
                podindeksWartosc = podindeksWartoscPP1;
                }
        else if (rodzaj == "przezywalnosc"){
                wartosc = wartoscPrzezywalnosc;
                podindeksWartosc = podindeksPrzezywalnosc;
                }
        else if (rodzaj == "laktoza"){
                wartosc = wartoscLaktoza;
                podindeksWartosc = podindeksWartoscPP2;
                }
        else if (rodzaj == "workability"){
                wartosc = wartoscWorkability;
                podindeksWartosc = podindeksWartoscPP2;
                }
        else if (rodzaj == "calving"){
                wartosc = wartoscCalving;
                podindeksWartosc=podindeksWartoscPP2;
                }
        else if (rodzaj == "pokroj2"){
                wartosc = wartoscPokroj2;
                podindeksWartosc=podindeksWartoscPP2;
                }

    for(int i=0; i<lbCach; i++)
    {


            int GenoKonwPop = OcenaPop.Cechy[i].Podindeksy[0].dane;
            int GenoKonwBie = OcenaBie.Cechy[i].Podindeksy[0].dane;

            if((OcenaPop.Cechy[i].Podindeksy[0] == OcenaBie.Cechy[i].Podindeksy[0])||
              ((OcenaPop.Cechy[i].Podindeksy[0]==5 && OcenaBie.Cechy[i].Podindeksy[0]==2 )||
               (OcenaPop.Cechy[i].Podindeksy[0]==6 && OcenaBie.Cechy[i].Podindeksy[0]==3 )))
            {


                if((OcenaPop.Cechy[i].Podindeksy[1] > wartoscDlaLbObora && OcenaBie.Cechy[i].Podindeksy[1] > wartoscDlaLbObora) &&
                (OcenaPop.Cechy[i].Podindeksy[2] > 20 && OcenaBie.Cechy[i].Podindeksy[2] > 20) &&
                (OcenaPop.Cechy[i].Podindeksy[lbPodCech-2] > 0 && OcenaBie.Cechy[i].Podindeksy[lbPodCech-2] > 0))
                {
                    liczK++;
                }

                if((OcenaPop.Cechy[i].Podindeksy[1] == 0 && OcenaBie.Cechy[i].Podindeksy[1] == 0) &&
                (OcenaPop.Cechy[i].Podindeksy[2] == 0 && OcenaBie.Cechy[i].Podindeksy[2] == 0) &&
                (OcenaPop.Cechy[i].Podindeksy[lbPodCech-2] > 0 && OcenaBie.Cechy[i].Podindeksy[lbPodCech-2] > 0))
                {
                    liczG++;
                }

                //RaportMleko<<"Typ Oceny"<<GenoKonwPop<<"    "<<GenoKonwBie<<endl;
                if((OcenaPop.Cechy[i].Podindeksy[0]==5 && OcenaBie.Cechy[i].Podindeksy[0]==2 )||
                   (OcenaPop.Cechy[i].Podindeksy[0]==6 && OcenaBie.Cechy[i].Podindeksy[0]==3 ))
                {
                    RaportMleko<<nr1<<";"<<nr2<<";"<<OcenionyWKraju<<";"<<GenoKonwPop<<";"<<GenoKonwBie<<";;;"<<wartosc[i]<<";"<<podindeksWartosc[0]<<";;;Oceniony gonomowo i konwencjonalnie;"<<endl;
                }


                for(int j=1; j<lbPodCech-1; j++)
                {
                    float liczbaPop = OcenaPop.Cechy[i].Podindeksy[j].dane;
                    float liczbaBie = OcenaBie.Cechy[i].Podindeksy[j].dane;
                    float liczbaPopP = liczbaPop;
                    float liczbaBieB = liczbaBie;
                    if(liczbaPop==0)
                    {
                        liczbaPopP+=1;
                        liczbaBieB+=1;
                    }
                    float Procent = ((liczbaBieB-liczbaPopP)/liczbaPopP)*100;
                    int ProcentWl = Procent;
                    string SpadekWzrost="Wzrost";

                    if(Procent<0)
                    {
                        SpadekWzrost = "Spadek";
                        ProcentWl = ProcentWl*(-1);
                    }


                    if(liczbaPop > 0 && liczbaBie >0)
                    {

                        if(ProcentWl > 5)
                        {
                             RaportMleko<<nr1<<";"<<nr2<<";"<<OcenionyWKraju<<";"<<GenoKonwPop<<";"<<GenoKonwBie<<";"<<liczbaPop<<";"<<liczbaBie<<";"<<wartosc[i]<<";"<<podindeksWartosc[j]<<";"<<SpadekWzrost<<";"<<ProcentWl<<";% w stosunku do oceny Poprzedniej!!!;"<<endl;
                        }

                    }
                    else
                    {


                        if(liczbaBie==0 && liczbaPop >0)
                        {
                            RaportMleko<<nr1<<";"<<nr2<<";"<<OcenionyWKraju<<";"<<GenoKonwPop<<";"<<GenoKonwBie<<";"<<liczbaPop<<";"<<liczbaBie<<";"<<wartosc[i]<<";"<<podindeksWartosc[j]<<";;;brak danych dla ocena bierzaca!!!;"<<endl;

                        }
                    }
                }

                float liczbaPop = OcenaPop.Cechy[i].Podindeksy[lbPodCech-1].dane;
                float liczbaBie = OcenaBie.Cechy[i].Podindeksy[lbPodCech-1].dane;
                float liczbaPopP = liczbaPop;
                float liczbaBieB = liczbaBie;


                if(liczbaPopP <0 && liczbaBieB >0)
                {
                    liczbaPopP *=(-1);
                    liczbaBieB +=liczbaPopP+1;
                    liczbaPop =1;
                }
                if(liczbaPopP >0 && liczbaBieB <0)
                {
                    liczbaBieB *=(-1);
                    liczbaPopP +=liczbaPopP+1;
                    liczbaBieB =1;
                }

                if(liczbaPop==0)
                {
                    liczbaPopP+=1;
                    liczbaBieB+=1;
                }
                float Procent = ((liczbaBieB-liczbaPopP)/liczbaPopP)*100;
                int ProcentWl = Procent;

                string SpadekWzrost="Wzrost";
                if(Procent<0)
                {
                    SpadekWzrost = "Spadek";
                    ProcentWl = ProcentWl*(-1);
                }

                if(OcenaPop.Cechy[i].Podindeksy[lbPodCech-1].dlaWH != 1 && OcenaBie.Cechy[i].Podindeksy[lbPodCech-1].dlaWH != 1)
                {
                    if(ProcentWl > 5)
                    {
                        //RaportMleko<<nr1<<"<========>"<<nr2<<";"<<liczbaPop<<";"<<liczbaBie<<";"<<WartMleko[i]<<";"<<PodindeksWartoscMleko[6]<<";"<<SpadekWzrost<<";"<<ProcentWl<<";% w stosunku do oceny Poprzedniej!!!;"<<endl;
                        RaportMleko<<nr1<<";"<<nr2<<";"<<OcenionyWKraju<<";"<<GenoKonwPop<<";"<<GenoKonwBie<<";"<<liczbaPop<<";"<<liczbaBie<<";"<<wartosc[i]<<";"<<podindeksWartosc[6]<<";"<<SpadekWzrost<<";"<<ProcentWl<<";% w stosunku do oceny Poprzedniej!!!;"<<endl;

                    }

                       liczG++;
                       liczK++;
                       ile++;

                }
                else
                {

                    if(OcenaBie.Cechy[i].Podindeksy[lbPodCech-1].dlaWH == 1 && OcenaPop.Cechy[i].Podindeksy[lbPodCech-1].dlaWH == 0)
                    {
                        //RaportMleko<<nr1<<"<========>"<<nr2<<"   '"<<liczbaPop<<"'  '"<<liczbaBie<<"'   "<<WartMleko[i]<<"   "<<PodindeksWartoscMleko[6]<<" brak danych dla ocena bierzaca!!!"<<endl;
                        RaportMleko<<nr1<<";"<<nr2<<";"<<OcenionyWKraju<<";"<<GenoKonwPop<<";"<<GenoKonwBie<<";"<<liczbaPop<<";"<<liczbaBie<<";"<<wartosc[i]<<";"<<podindeksWartosc[6]<<";;;brak danych dla ocena bierzaca!!!;"<<endl;
                    }
                }

            }
           else
           {
                //RaportMleko<<nr1<<"<========>"<<nr2<<"   Niewlasciew wartosc w Typie oceny  '"<<OcenaPop.Cechy[i].Podindeksy[0]<<"'  '"<<OcenaBie.Cechy[i].Podindeksy[0]<<"'   "<<WartMleko[i]<<"  "<<PodindeksWartoscMleko[0]<<endl;
                RaportMleko<<nr1<<";"<<nr2<<";"<<OcenionyWKraju<<";"<<GenoKonwPop<<";"<<GenoKonwBie<<";;;"<<wartosc[i]<<";"<<podindeksWartosc[0]<<";;;Niewlasciew wartosc w Typie oceny;"<<endl;

           }



               //Ocena Konw.





           if(((GenoKonwPop==2 && GenoKonwBie==2)||(GenoKonwPop==3 && GenoKonwBie==3)) && liczK==2)
           {
               (TabelaRocznikowPop.ileK[i])++;
               (TabelaRocznikowBiez.ileK[i])++;



                //cout<<maxi<<"      "<<mini<<endl;
                //cout<<OcenaBie.Cechy[i].Podindeksy[1].dane<<endl;
               for(int j=0; j<lbPodCech; j++)
               {
                  TabelaRocznikowPop.MlekoK[i][j] += OcenaPop.Cechy[i].Podindeksy[j].dane;
                  TabelaRocznikowBiez.MlekoK[i][j]+= OcenaBie.Cechy[i].Podindeksy[j].dane;
               }
                //DS[LRok].MlekoPopK[i] = OcenaPop.Cechy[i].Podindeksy[6].dane;
                //DS[LRok].MlekoBieK[i] = OcenaBie.Cechy[i].Podindeksy[6].dane;
                (DSPop.VekMlekoK[i]).push_back(OcenaPop.Cechy[i].Podindeksy[lbPodCech-1].dane);
                (DSBie.VekMlekoK[i]).push_back(OcenaBie.Cechy[i].Podindeksy[lbPodCech-1].dane);
               }



           // Ocena Genom
           if(((GenoKonwPop==5 && GenoKonwBie==5)||(GenoKonwPop==6 && GenoKonwBie==6)) && liczG==2)
           {
               (TabelaRocznikowPop.ileG[i])++;
               (TabelaRocznikowBiez.ileG[i])++;

               for(int j=0; j<lbPodCech; j++)
               {
                   TabelaRocznikowPop.MlekoG[i][j] += OcenaPop.Cechy[i].Podindeksy[j].dane;
                   TabelaRocznikowBiez.MlekoG[i][j]+= OcenaBie.Cechy[i].Podindeksy[j].dane;
               }
               (DSPop.VekMlekoG[i]).push_back(OcenaPop.Cechy[i].Podindeksy[lbPodCech-1].dane);
               (DSBie.VekMlekoG[i]).push_back(OcenaBie.Cechy[i].Podindeksy[lbPodCech-1].dane);
           }

           // Ocena GenoKonw.
           if(((GenoKonwPop==5 && GenoKonwBie==2)||(GenoKonwPop==6 && GenoKonwBie==3) ||
               (GenoKonwPop==5 && GenoKonwBie==5) || (GenoKonwPop==6 && GenoKonwBie==6)) && liczK ==2)
           {
               (TabelaRocznikowPop.ileGK[i])++;
               (TabelaRocznikowBiez.ileGK[i])++;

               for(int j=0; j<lbPodCech; j++)
               {
                   TabelaRocznikowPop.MlekoGK[i][j] += OcenaPop.Cechy[i].Podindeksy[j].dane;
                   TabelaRocznikowBiez.MlekoGK[i][j]+= OcenaBie.Cechy[i].Podindeksy[j].dane;
               }
               (DSPop.VekMlekoGK[i]).push_back(OcenaPop.Cechy[i].Podindeksy[lbPodCech-1].dane);
               (DSBie.VekMlekoGK[i]).push_back(OcenaBie.Cechy[i].Podindeksy[lbPodCech-1].dane);
           }


           liczK = 0;
           liczG = 0;

           //RaportMleko<<";;;;;;;;;;;;;;;"<<endl;

    }
    //cout<<ile<<endl;

};
//===========



//===============================================================================================================================================================



//================================================================================================================================================================

struct DystocjaCorekBuhaja{

    Komorka Cechy[10];

    inline void UstawZakres(int lb)
    {
        Cechy[0].PlusZnakow = lb;
        Cechy[0].DoZnaku =lb+4;
       // cout<<Cechy[0].PlusZnakow<<"================="<<Cechy[0].DoZnaku<<endl;
        for(int i=1; i<10 ;i++)
        {
            Cechy[i].DoZnaku = Cechy[i-1].DoZnaku + 5;
            Cechy[i].PlusZnakow = Cechy[i-1].PlusZnakow + 5;
           // cout<<Cechy[i].PlusZnakow<<"================="<<Cechy[i].DoZnaku<<endl;
        }
    }
    inline void UstawDane(string &dane)
    {
        for(int i=0; i<10; i++)
        {
            Cechy[i].wycinanie(dane);
        }
    }

    void wyswietl()
    {
        for(int i=0; i<10; i++)
        {
            cout<<Cechy[i].dane<<endl;
        }
    }
   inline friend void SprawdzDaneDystCurekBuh(DystocjaCorekBuhaja &OcenaPop, DystocjaCorekBuhaja &OcenaBie, fstream &RaportDystocjaCB, string nr1, string nr2, year &TabelaRocznikowPop, year &TabelaRocznikowBiez,  const string &OcenionyWKraju, OdchylenieSt &DSPop, OdchylenieSt &DSBie );

};


inline void SprawdzDaneDystCurekBuh(DystocjaCorekBuhaja &OcenaPop, DystocjaCorekBuhaja &OcenaBie, fstream &RaportDystocjaCB, string nr1, string nr2, year &TabelaRocznikowPop, year &TabelaRocznikowBiez, const string &OcenionyWKraju,OdchylenieSt &DSPop, OdchylenieSt &DSBie )
{
    string WartoscDystocjaCB[10]={"Liczba Ocielonych Corek","Porody Samodzielne Proc100x","Porody Latwe Proc100x","Porody Trudne Proc100x","Porody Ciezkie Proc100x","Poronienia Proc 100x",
                                  "Cesarskie Ciecia Proc100x","Liczba Urodzonych Cielat","Zywo Urodzone Proc100x","Martwo Urodzone Proc100x"};

    for(int i=0; i<10; i++)
    {

        float liczbaPop = OcenaPop.Cechy[i].dane;
        float liczbaBie = OcenaBie.Cechy[i].dane;

        float liczbaPopP = liczbaPop;
        float liczbaBieB = liczbaBie;
        if(liczbaPopP==0)
        {
            liczbaPopP+=1;
            liczbaBieB+=1;
        }
        float Procent = ((liczbaBieB-liczbaPopP)/liczbaPopP)*100;
        int ProcentWl = Procent;
        string SpadekWzrost="Wzrost";

        if(Procent<0)
        {
            SpadekWzrost = "Spadek";
            ProcentWl = ProcentWl*(-1);
        }


        if(OcenaBie.Cechy[i].dane > 0 && OcenaPop.Cechy[i].dane >0)
        {
            if(ProcentWl > 5)
            {
                //RaportDystocjaCB<<nr1<<"<========>"<<nr2<<"   '"<<liczbaPop<<"'  '"<<liczbaBie<<"'   Cecha '"<<WartoscDystocjaCB[i]<<"' "<<SpadekWzrost<<" o "<<ProcentWl<<"% w stosunku do oceny Poprzedniej!!!"<<endl;
                RaportDystocjaCB<<nr1<<";"<<nr2<<";"<<OcenionyWKraju<<";;;"<<liczbaPop<<";"<<liczbaBie<<";"<<WartoscDystocjaCB[i]<<";"<<SpadekWzrost<<";"<<ProcentWl<<";% w stosunku do oceny Poprzedniej!!!;"<<endl;

            }
            TabelaRocznikowPop.DystocjaCorekBuhaja[i] += liczbaPop;
            TabelaRocznikowBiez.DystocjaCorekBuhaja[i] +=liczbaBie;
            TabelaRocznikowBiez.ileDyCB[i]++;
            TabelaRocznikowPop.ileDyCB[i]++;
            (DSPop.VekDystocjaCB[i]).push_back(liczbaPop);
            (DSBie.VekDystocjaCB[i]).push_back(liczbaBie);

        }
        else
        {

            if(OcenaPop.Cechy[i].dane == 0 && OcenaBie.Cechy[i].dane > 0)
            {
                //RaportDystocjaCB<<nr1<<"<========>"<<nr2<<"   '"<<liczbaPop<<"'  '"<<liczbaBie<<"'   Cecha '"<<WartoscDystocjaCB[i]<<"' brak danych dla ocena poprzedniej!!!"<<endl;
                RaportDystocjaCB<<nr1<<";"<<nr2<<";"<<OcenionyWKraju<<";;;"<<liczbaPop<<";"<<liczbaBie<<";"<<WartoscDystocjaCB[i]<<";;;brak danych dla ocena poprzedniej!!!;"<<endl;
            }

            if(OcenaPop.Cechy[i].dane > 0 && OcenaBie.Cechy[i].dane == 0)
            {
                //RaportDystocjaCB<<nr1<<"<========>"<<nr2<<"   '"<<liczbaPop<<"'  '"<<liczbaBie<<"'   Cecha'"<<WartoscDystocjaCB[i]<<"' brak danych dla ocena bierzaca!!!"<<endl;
                RaportDystocjaCB<<nr1<<";"<<nr2<<";"<<OcenionyWKraju<<";;;"<<liczbaPop<<";"<<liczbaBie<<";"<<WartoscDystocjaCB[i]<<";;;brak danych dla ocena bierzaca!!!;"<<endl;
            }
        }


    }
};


//==============================================================================================================================================================

struct DystocjaBezposrednia{

    //===== Dystocja Bezposrednia =====

     Komorka Cechy[10];

    inline void UstawZakres(int lb)
    {
        Cechy[0].PlusZnakow = lb;
        Cechy[0].DoZnaku =lb+4;
        //cout<<Cechy[0].PlusZnakow<<"================="<<Cechy[0].DoZnaku<<endl;
        for(int i=1; i<10 ;i++)
        {
            Cechy[i].DoZnaku = Cechy[i-1].DoZnaku + 5;
            Cechy[i].PlusZnakow = Cechy[i-1].PlusZnakow + 5;
           // cout<<Cechy[i].PlusZnakow<<"================="<<Cechy[i].DoZnaku<<endl;

        }
    }
    inline void UstawDane(string &dane)
    {
        for(int i=0; i<10; i++)
        {
            Cechy[i].wycinanie(dane);
        }
    }

    void wyswietl()
    {
        for(int i=0; i<10; i++)
        {
            cout<<Cechy[i].dane<<endl;
        }
    }

    inline friend void SprawdzDaneDystBezposrednia(DystocjaBezposrednia &OcenaPop, DystocjaBezposrednia &OcenaBie, fstream &RaportDystocjaCB, string nr1, string nr2, year &TabelaRocznikowPop, year &TabelaRocznikowBiez, const string &OcenionyWKraju, OdchylenieSt &DSPop, OdchylenieSt &DSBie );

};
inline void SprawdzDaneDystBezposrednia(DystocjaBezposrednia &OcenaPop, DystocjaBezposrednia &OcenaBie, fstream &RaportDystocjaCB, string nr1, string nr2, year &TabelaRocznikowPop, year &TabelaRocznikowBiez, const string &OcenionyWKraju, OdchylenieSt &DSPop, OdchylenieSt &DSBie  )
{
    string WartoscDystocjaCB[10]={"Liczba Ocielonych Corek","Porody Samodzielne *100%","Porody Latwe *100%","Porody Trudne *100%",
                                  "Porody Ciezkie *100%","Poronienia *100%","Cesarskie Ciecia *100%","Liczba cielat buhaja","Zywo Urodzone *100%","Martwo Urodzone *100%"};

    for(int i=0; i<10; i++)
    {

       float liczbaPop = OcenaPop.Cechy[i].dane;
        float liczbaBie = OcenaBie.Cechy[i].dane;

        float liczbaPopP = liczbaPop;
        float liczbaBieB = liczbaBie;
        if(liczbaPopP==0)
        {
            liczbaPopP+=1;
            liczbaBieB+=1;
        }
        float Procent = ((liczbaBieB-liczbaPopP)/liczbaPopP)*100;
        int ProcentWl = Procent;
        string SpadekWzrost="Wzrost";

        if(Procent<0)
        {
            SpadekWzrost = "Spadek";
            ProcentWl = ProcentWl*(-1);
        }


        if(OcenaBie.Cechy[i].dane > 0 && OcenaPop.Cechy[i].dane >0)
        {
            if(ProcentWl > 5)
            {
                //RaportDystocjaCB<<nr1<<"<========>"<<nr2<<"   '"<<liczbaPop<<"'  '"<<liczbaBie<<"'   Cecha '"<<WartoscDystocjaCB[i]<<"' "<<SpadekWzrost<<" o "<<ProcentWl<<"% w stosunku do oceny Poprzedniej!!!"<<endl;
                RaportDystocjaCB<<nr1<<";"<<nr2<<";"<<OcenionyWKraju<<";;;"<<liczbaPop<<";"<<liczbaBie<<";"<<WartoscDystocjaCB[i]<<";"<<SpadekWzrost<<";"<<ProcentWl<<";% w stosunku do oceny Poprzedniej!!!;"<<endl;

            }
                TabelaRocznikowPop.DystocjaBezposrednia[i] += liczbaPop;
                TabelaRocznikowBiez.DystocjaBezposrednia[i] +=liczbaBie;
                TabelaRocznikowBiez.ileDyBe[i]++;
                TabelaRocznikowPop.ileDyBe[i]++;
                (DSPop.VekDystocjaBezp[i]).push_back(liczbaPop);
                (DSBie.VekDystocjaBezp[i]).push_back(liczbaBie);
        }
        else
        {

            if(OcenaPop.Cechy[i].dane == 0 && OcenaBie.Cechy[i].dane > 0)
            {
                //RaportDystocjaCB<<nr1<<"<========>"<<nr2<<"   '"<<liczbaPop<<"'  '"<<liczbaBie<<"'   Cecha '"<<WartoscDystocjaCB[i]<<"' brak danych dla ocena poprzedniej!!!"<<endl;
                RaportDystocjaCB<<nr1<<";"<<nr2<<";"<<OcenionyWKraju<<";;;"<<liczbaPop<<";"<<liczbaBie<<";"<<WartoscDystocjaCB[i]<<";;;brak danych dla ocena poprzedniej!!!;"<<endl;
            }

            if(OcenaPop.Cechy[i].dane > 0 && OcenaBie.Cechy[i].dane == 0)
            {
                //RaportDystocjaCB<<nr1<<"<========>"<<nr2<<"   '"<<liczbaPop<<"'  '"<<liczbaBie<<"'   Cecha'"<<WartoscDystocjaCB[i]<<"' brak danych dla ocena bierzaca!!!"<<endl;
                RaportDystocjaCB<<nr1<<";"<<nr2<<";"<<OcenionyWKraju<<";;;"<<liczbaPop<<";"<<liczbaBie<<";"<<WartoscDystocjaCB[i]<<";;;brak danych dla ocena bierzaca!!!;"<<endl;
            }
        }


    }
};


//==============================================================================================================================================================

struct Przezywalnosc{
    //===Przezywalnosc =====
    int TypOceny;
    int Powtarzelnosc100x;
    int WartoscHodowlana100x;

    Komorka Cechy[3];

    inline void UstawZakres(int lb)
    {
        Cechy[0].PlusZnakow = lb;
        Cechy[0].DoZnaku =lb;
        Cechy[1].PlusZnakow =lb+1;
        Cechy[1].DoZnaku = Cechy[1].PlusZnakow +1;
        Cechy[2].PlusZnakow =Cechy[1].DoZnaku+1;
        Cechy[2].DoZnaku = Cechy[2].PlusZnakow +5;

    }
    inline void UstawDane(string &dane)
    {
        for(int i=0; i<3; i++)
        {
            Cechy[i].wycinanie(dane);
        }
    }

    void wyswietl()
    {
        for(int i=0; i<3; i++)
        {
            cout<<Cechy[i].dane<<endl;
        }
    }
    inline void SprawdzDanePrzezywalnosc(Przezywalnosc &OcenaPop, Przezywalnosc &OcenaBie, fstream &RaportPrzezywalnosc, string nr1, string nr2, year &TabelaRocznikowPop, year &TabelaRocznikowBiez, const string &OcenionyWKraju, OdchylenieSt &DSPop, OdchylenieSt &DSBie );

};


inline void SprawdzDanePrzezywalnosc(Przezywalnosc &OcenaPop, Przezywalnosc &OcenaBie, fstream &RaportPrzezywalnosc, string nr1, string nr2, year &TabelaRocznikowPop, year &TabelaRocznikowBiez, const string &OcenionyWKraju, OdchylenieSt &DSPop, OdchylenieSt &DSBie  )
{
    string WartoscDystocjaCB[3]={"Typ oceny","Powtarzalnosc","Wartosc hodowlana*100"};

    for(int i=0; i<3; i++)
    {

        float liczbaPop = OcenaPop.Cechy[i].dane;
        float liczbaBie = OcenaBie.Cechy[i].dane;

        float liczbaPopP = liczbaPop;
        float liczbaBieB = liczbaBie;
        if(liczbaPopP==0)
        {
            liczbaPopP+=1;
            liczbaBieB+=1;
        }
        float Procent = ((liczbaBieB-liczbaPopP)/liczbaPopP)*100;
        int ProcentWl = Procent;
        string SpadekWzrost="Wzrost";

        if(Procent<0)
        {
            SpadekWzrost = "Spadek";
            ProcentWl = ProcentWl*(-1);
        }



        if(OcenaBie.Cechy[i].dane > 0 && OcenaPop.Cechy[i].dane >0)
        {
            if(ProcentWl > 5)
            {
                //RaportDystocjaCB<<nr1<<"<========>"<<nr2<<"   '"<<liczbaPop<<"'  '"<<liczbaBie<<"'   Cecha '"<<WartoscDystocjaCB[i]<<"' "<<SpadekWzrost<<" o "<<ProcentWl<<"% w stosunku do oceny Poprzedniej!!!"<<endl;
                RaportPrzezywalnosc<<nr1<<";"<<nr2<<";"<<OcenionyWKraju<<";;;"<<liczbaPop<<";"<<liczbaBie<<";"<<WartoscDystocjaCB[i]<<";"<<SpadekWzrost<<";"<<ProcentWl<<";% w stosunku do oceny Poprzedniej!!!;"<<endl;

            }
             TabelaRocznikowPop.PrzezywalnoscP[i] += liczbaPop;
            TabelaRocznikowBiez.PrzezywalnoscP[i] +=liczbaBie;
            TabelaRocznikowBiez.ilePrzez[i]++;
            TabelaRocznikowPop.ilePrzez[i]++;
            (DSPop.VekPrzezywalnosc[i]).push_back(liczbaPop);
            (DSBie.VekPrzezywalnosc[i]).push_back(liczbaBie);

        }
        else
        {

            if(OcenaPop.Cechy[i].dane == 0 && OcenaBie.Cechy[i].dane > 0)
            {
                //RaportDystocjaCB<<nr1<<"<========>"<<nr2<<"   '"<<liczbaPop<<"'  '"<<liczbaBie<<"'   Cecha '"<<WartoscDystocjaCB[i]<<"' brak danych dla ocena poprzedniej!!!"<<endl;
                RaportPrzezywalnosc<<nr1<<";"<<nr2<<";"<<OcenionyWKraju<<";;;"<<liczbaPop<<";"<<liczbaBie<<";"<<WartoscDystocjaCB[i]<<";;;brak danych dla ocena poprzedniej!!!;"<<endl;
            }

            if(OcenaPop.Cechy[i].dane > 0 && OcenaBie.Cechy[i].dane == 0)
            {
                //RaportDystocjaCB<<nr1<<"<========>"<<nr2<<"   '"<<liczbaPop<<"'  '"<<liczbaBie<<"'   Cecha'"<<WartoscDystocjaCB[i]<<"' brak danych dla ocena bierzaca!!!"<<endl;
                RaportPrzezywalnosc<<nr1<<";"<<nr2<<";"<<OcenionyWKraju<<";;;"<<liczbaPop<<";"<<liczbaBie<<";"<<WartoscDystocjaCB[i]<<";;;brak danych dla ocena bierzaca!!!;"<<endl;
            }
        }


    }
};

//==============================================================================================================================================================

struct Indeksy{

    // =======Indeks Prod ======

    Komorka Cechy[9];

    inline void UstawZakres(int lb)
    {
        Cechy[0].PlusZnakow = lb;
        Cechy[0].DoZnaku =lb+4;
       // cout<<Cechy[0].PlusZnakow<<"================="<<Cechy[0].DoZnaku<<endl;
        for(int i=1; i<9 ;i++)
        {
            Cechy[i].DoZnaku = Cechy[i-1].DoZnaku + 5;
            Cechy[i].PlusZnakow = Cechy[i-1].PlusZnakow + 5;
           // cout<<Cechy[i].PlusZnakow<<"================="<<Cechy[i].DoZnaku<<endl;

        }
    }
    inline void UstawDane(string &dane)
    {
        for(int i=0; i<9; i++)
        {
            Cechy[i].wycinanie(dane);
        }
    }

    void wyswietl()
    {
        for(int i=0; i<9; i++)
        {
            cout<<Cechy[i].dane<<endl;
        }
    }
    inline void SprawdzDaneIndeksy(Indeksy &OcenaPop, Indeksy &OcenaBie, fstream &RaportIndeksy, string nr1, string nr2, year &TabelaRocznikowPop, year &TabelaRocznikowBiez, const string &OcenionyWKraju, OdchylenieSt &DSPop, OdchylenieSt &DSBie );


};



inline void SprawdzDaneIndeksy(Indeksy &OcenaPop, Indeksy &OcenaBie, fstream &RaportIndeksy, string nr1, string nr2, year &TabelaRocznikowPop, year &TabelaRocznikowBiez, const string &OcenionyWKraju, OdchylenieSt &DSPop, OdchylenieSt &DSBie )
{
    string WartoscDystocjaCB[9]={"Indeks Produkcyjny Stary *10[kg]","Podindeks Produkcyjny *100","Podindeks Kalibru *100","Podindeks Typu I Budowy *100","Podindeks Nog I Racic *100","Podindeks Wymienia *100",
    "Podindeks Ogolny Pokroju *100","Podindeks Plodnosci *100","Indeks PF *100x"};


        float liczbaPop = OcenaPop.Cechy[0].dane;
        float liczbaBie = OcenaBie.Cechy[0].dane;

        float liczbaPopP = liczbaPop;
        float liczbaBieB = liczbaBie;
        if(liczbaPopP <0 && liczbaBieB >0)
        {
            liczbaPopP *=(-1);
            liczbaBieB +=liczbaPopP+1;
            liczbaPop =1;
        }
        if(liczbaPopP >0 && liczbaBieB <0)
        {
            liczbaBieB *=(-1);
            liczbaPopP +=liczbaPopP+1;
            liczbaBieB =1;
        }

        if(liczbaPopP==0)
        {
            liczbaPopP+=1;
            liczbaBieB+=1;
        }
        float Procent = ((liczbaBieB-liczbaPopP)/liczbaPopP)*100;
        int ProcentWl = Procent;
        string SpadekWzrost="Wzrost";

        if(Procent<0)
        {
            SpadekWzrost = "Spadek";
            ProcentWl = ProcentWl*(-1);
        }

        if(OcenaBie.Cechy[0].dlaWH != 1 && OcenaPop.Cechy[0].dlaWH != 1)
        {
            if(ProcentWl > 5)
            {
                //RaportIndeksy<<nr1<<"<========>"<<nr2<<"   '"<<liczbaPop<<"'  '"<<liczbaBie<<"'   Cecha '"<<WartoscDystocjaCB[0]<<"' "<<SpadekWzrost<<" o "<<ProcentWl<<"% w stosunku do oceny Poprzedniej!!!"<<endl;
                RaportIndeksy<<nr1<<";"<<nr2<<";"<<OcenionyWKraju<<";;;"<<liczbaPop<<";"<<liczbaBie<<";"<<WartoscDystocjaCB[0]<<";"<<SpadekWzrost<<";"<<ProcentWl<<";% w stosunku do oceny Poprzedniej!!!;"<<endl;

            }
            TabelaRocznikowPop.IndeksyI[0] += liczbaPop;
            TabelaRocznikowBiez.IndeksyI[0] +=liczbaBie;
            TabelaRocznikowBiez.ileIndek[0]++;
            TabelaRocznikowPop.ileIndek[0]++;
            (DSPop.VekIndeksy[0]).push_back(liczbaPop);
            (DSBie.VekIndeksy[0]).push_back(liczbaBie);

        }
        else
        {

            if(OcenaPop.Cechy[0].dlaWH == 1 && OcenaBie.Cechy[0].dlaWH == 0)
            {
                //RaportIndeksy<<nr1<<"<========>"<<nr2<<"   '"<<liczbaPop<<"'  '"<<liczbaBie<<"'   Cecha '"<<WartoscDystocjaCB[0]<<"' brak danych dla ocena poprzedniej!!!"<<endl;
                RaportIndeksy<<nr1<<";"<<nr2<<";"<<OcenionyWKraju<<";;;"<<liczbaPop<<";"<<liczbaBie<<";"<<WartoscDystocjaCB[0]<<";;;brak danych dla ocena poprzedniej!!!;"<<endl;

            }

            if(OcenaPop.Cechy[0].dane == 0 && OcenaBie.Cechy[0].dlaWH == 1)
            {
                //RaportIndeksy<<nr1<<"<========>"<<nr2<<"   '"<<liczbaPop<<"'  '"<<liczbaBie<<"'   Cecha'"<<WartoscDystocjaCB[0]<<"' brak danych dla ocena bierzaca!!!"<<endl;
                RaportIndeksy<<nr1<<";"<<nr2<<";"<<OcenionyWKraju<<";;;"<<liczbaPop<<";"<<liczbaBie<<";"<<WartoscDystocjaCB[0]<<";;;brak danych dla ocena bierzaca!!!;"<<endl;

            }
        }


    for(int i=1; i<9; i++)
    {


        float liczbaPop = OcenaPop.Cechy[i].dane;
        float liczbaBie = OcenaBie.Cechy[i].dane;

        float liczbaPopP = liczbaPop;
        float liczbaBieB = liczbaBie;
        if(liczbaPopP==0)
        {
            liczbaPopP+=1;
            liczbaBieB+=1;
        }
        float Procent = ((liczbaBieB-liczbaPopP)/liczbaPopP)*100;
        int ProcentWl = Procent;
        string SpadekWzrost="Wzrost";

        if(Procent<0)
        {
            SpadekWzrost = "Spadek";
            ProcentWl = ProcentWl*(-1);
        }



        if(OcenaBie.Cechy[i].dane > 0 && OcenaPop.Cechy[i].dane >0)
        {
            if(ProcentWl > 5)
            {
                //RaportDystocjaCB<<nr1<<"<========>"<<nr2<<"   '"<<liczbaPop<<"'  '"<<liczbaBie<<"'   Cecha '"<<WartoscDystocjaCB[i]<<"' "<<SpadekWzrost<<" o "<<ProcentWl<<"% w stosunku do oceny Poprzedniej!!!"<<endl;
                RaportIndeksy<<nr1<<";"<<nr2<<";"<<OcenionyWKraju<<";;;"<<liczbaPop<<";"<<liczbaBie<<";"<<WartoscDystocjaCB[i]<<";"<<SpadekWzrost<<";"<<ProcentWl<<";% w stosunku do oceny Poprzedniej!!!;"<<endl;
            }
            TabelaRocznikowPop.IndeksyI[i] += liczbaPop;
            TabelaRocznikowBiez.IndeksyI[i] +=liczbaBie;
            TabelaRocznikowBiez.ileIndek[i]++;
            TabelaRocznikowPop.ileIndek[i]++;

            (DSPop.VekIndeksy[i]).push_back(liczbaPop);
            (DSBie.VekIndeksy[i]).push_back(liczbaBie);
        }
        else
        {

            if(OcenaPop.Cechy[i].dane == 0 && OcenaBie.Cechy[i].dane > 0)
            {
                //RaportDystocjaCB<<nr1<<"<========>"<<nr2<<"   '"<<liczbaPop<<"'  '"<<liczbaBie<<"'   Cecha '"<<WartoscDystocjaCB[i]<<"' brak danych dla ocena poprzedniej!!!"<<endl;
                RaportIndeksy<<nr1<<";"<<nr2<<";"<<OcenionyWKraju<<";;;"<<liczbaPop<<";"<<liczbaBie<<";"<<WartoscDystocjaCB[i]<<";;;brak danych dla ocena poprzedniej!!!;"<<endl;
            }

            if(OcenaPop.Cechy[i].dane > 0 && OcenaBie.Cechy[i].dane == 0)
            {
                //RaportDystocjaCB<<nr1<<"<========>"<<nr2<<"   '"<<liczbaPop<<"'  '"<<liczbaBie<<"'   Cecha'"<<WartoscDystocjaCB[i]<<"' brak danych dla ocena bierzaca!!!"<<endl;
                RaportIndeksy<<nr1<<";"<<nr2<<";"<<OcenionyWKraju<<";;;"<<liczbaPop<<";"<<liczbaBie<<";"<<WartoscDystocjaCB[i]<<";;;brak danych dla ocena bierzaca!!!;"<<endl;
            }
        }




    }
};





















//=====================================================================================================================================================
//=====================================================================================================================================================
//=====================================================================================================================================================


