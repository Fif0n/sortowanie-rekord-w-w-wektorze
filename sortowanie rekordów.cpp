#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include<ctime>
#include<algorithm>

using namespace std;

struct gracz{
        string imie, nazwisko;
        int miejsce;
};

class ranking{
                vector <struct gracz> spis;
                ifstream plik1;
                ofstream plik2;
       
        public:
                ranking();
                ~ranking();
                
                void wprowadz();
                void sortuj();             
};

ranking::ranking(){
	plik1.open("c:\\od.txt");
    plik2.open("c:\\do.txt");
}

	int compare(const void *a, const void *b){
		return ( (*(gracz*)a).miejsce - (*(gracz*)b).miejsce );
	}

void ranking::wprowadz(){
	struct gracz wprowadzany;
	while(!plik1.eof()){
		plik1>>wprowadzany.imie>>wprowadzany.nazwisko>>wprowadzany.miejsce;
		
		spis.push_back(wprowadzany);
		
	}
	
	
}

void ranking::sortuj(){
	qsort(&spis[0], spis.size(), sizeof(gracz),compare);
	plik2<<"["<<endl;
	for(vector<struct gracz>::iterator it = spis.begin(); it != spis.end(); ++it){
        	plik2<<"{\"miejsce\":\""<<it->miejsce<<"\", \"imie\":\""<<it->imie<<"\", \"nazwisko\":\""<<it->nazwisko<<"\"},"<<endl;

    }
    plik2<<"]";
	
		
}

ranking::~ranking(){
    plik1.close();
    plik2.close();
}


int main(int argc, char** argv) {
        ranking r1;
        r1.wprowadz();
        r1.sortuj();

        
        return 0;
}
