//#ifndef SHIELD_H
//#define SHIELD_H
#pragma once

class Shield{
	public:
		Shield() ;
		Shield(int s, int p)  ;
		int block() ;
		void destruction() ;
		void repair() ;
		int getSize() ;
		int getProtection() ;
		void getShieldInfo() ;
	private:
		int size ;
		int protection ;	
};

//#endif