//#ifndef SWORD_H
//#define SWORD_H

#pragma once

class Sword {
public:
	Sword()  ;
    Sword(int w, int q, int c) ;  
    int Damage();         
    void WearAndTear();   
    void Sharpen();       
    int getWeight(); 
    int getQuality(); 
    void getSwordInfo(); 
    int getCritChance() ;
private:
    int weight;
    int quality;
    int critChance ;

};

//#endif