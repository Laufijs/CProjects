#include <iostream>
#include <ctime>
#include <conio.h>
#include <cctype>

using namespace std;

string minamaisVards[20] = {
    "Avengers",
	"IronMan",
	"Loki",
	"Thor",
	"Hulk",
	"BlackWidow",
	"CaptainAmerica",
	"Thanos",
	"Wakanda",
	"SpiderMan",
	"Vision",
	"Wanda",
	"Hawkeye",
	"AntMan",
	"DoctorStrange",
	"Guardians",
	"Gamora",
	"Falcon",
	"WinterSoldier",
	"StarLord",
};

void visiAtmineti(bool atminetieVardi[], int izmers);

void atminetaisVards(bool& atminets, int& atminetie, int& sodapunkti, string& x, bool atminetieVardi[], int izmers){
		if(atminets){
		atminetie ++ ;
		sodapunkti -= 5 ;
		cout<<"Apsveicam! Minamais vards bija : " << x << endl ;
			if(sodapunkti < 0 ){
				sodapunkti = 0 ;
			}
			if(sodapunkti ==1){
			cout << "Jums sobrid ir " << sodapunkti <<" sodapunkts." << endl ;
			}else{
			cout << "Jums sobrid ir " << sodapunkti <<" sodapunkti." << endl ;
			}
			visiAtmineti(atminetieVardi, izmers);
			}
		}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void spelesBeigas(char minamaisBurts, string& x, int atminetie){
	if(minamaisBurts == '0'){
        	cout << "Veiksmi nakamreiz!" <<endl;
        	cout << "Minamais vards bija : " << x <<endl;
			if(atminetie == 0){
				cout<< "Jus neatminejat nevienu vardu." ;
			}else if(atminetie == 1){
				cout<< "Jus atminejat vienu vardu" ;
			}else{
				cout << "Jus atminejat : "<< atminetie <<" vardus!" ;
			}
			exit(0);
		}
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void visiAtmineti(bool atminetieVardi[], int izmers){
	for(int i=0;i<izmers;i++){
		if(!atminetieVardi[i]){
			return;
		}
	}
	cout << "Apsveicu! Tika atmineti visi vardi!" ;
	exit(0) ;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool sodaPunktParb(int sodapunkti, int atminetie, string& x){
	  if(sodapunkti == 5){
        	cout << "Jums sobrid ir 5 soda punkti!" << endl ;
		} else if(sodapunkti == 10){
			cout << "Jums ir 10 soda punkti, spele beigusies!" << endl ;
			cout << "Minamais vards bija : " << x <<endl;
			if(atminetie == 0){
				cout<< "Jus neatminejat nevienu vardu." ;
			}else if(atminetie == 1){
				cout<< "Jus atminejat vienu vardu." ;
			}else{
				cout << "Jus atminejat : "<< atminetie <<" vardus!" ;
			}
			return true ;
		}
	return false;	
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void toLower(string vardi[], int izmers){
	for(int i=0 ; i<izmers ; i++){
		for(int j=0 ; j < vardi[i].length();j++){
		vardi[i][j] = tolower(vardi[i][j]) ;
	}
}
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void aizklatsVards(string& vards, bool minejums[], int izmers){
    for(int i = 0; i < izmers; i++) {
        if(minejums[i]) {
            cout<< vards[i];  
        }else{
            cout<< ".";  
        }
    }
    cout<<endl ;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main(){
    	time_t t;
    	srand((unsigned)time(&t));
		toLower(minamaisVards, sizeof(minamaisVards)/sizeof(minamaisVards[0])) ;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		bool atminetieVardi[20] = {false} ;
		int sodapunkti = 0 ;
		int atminetie = 0 ;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    while(true){
		int random;
		string x ;
		int vardaGarums ;
		bool minejums[20] = {false};  
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    do{
    	random = rand()%20 ; 
	}while(atminetieVardi[random]) ;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		visiAtmineti(atminetieVardi, sizeof(minamaisVards)/sizeof(minamaisVards[0]));
		x = minamaisVards[random] ;
		vardaGarums =x.length() ;
		fill(minejums, minejums+vardaGarums, false) ;
		atminetieVardi[random] = true ;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		while(true){
        aizklatsVards(x, minejums, vardaGarums);  
        char minamaisBurts = tolower(getch());  
        bool uzminets = false;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      if(sodaPunktParb(sodapunkti, atminetie, x)){
      	return 0;
	  }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        for (int i = 0; i < vardaGarums; i++) {
            if (x[i] == minamaisBurts) {
                minejums[i] = true;  
                uzminets = true;
            }
        }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        spelesBeigas(minamaisBurts, x , atminetie) ;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////		
        if(!uzminets){
            cout<<minamaisBurts<< " - burta varda nav." << endl;
            sodapunkti++ ;
        }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        bool atminets =true;
        for(int i =0 ; i <vardaGarums ;i++){
        	if(!minejums[i]){
        		atminets = false ;
        		break ;
			}
		}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		if(atminets){
        atminetaisVards(atminets, atminetie, sodapunkti, x, atminetieVardi, sizeof(minamaisVards) / sizeof(minamaisVards[0]));
        break; 
        }
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
return 0;
}
