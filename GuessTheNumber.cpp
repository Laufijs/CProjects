/*
 * Program Name: guessTheNumber ;
 * Author: [Laufy] ;
 * Date: [04/11/2024] ;
 * Description: simple guessing game, where you try to guess the number that program chose. ;
 * Copyright (c) [2024] [Laufy] ;
 * Note: Feel free to modify / share this code as long as credit is given to the original author. ;
 */
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std ;

int main()
{
	time_t t ;
	srand((unsigned) time(&t));
	
	int num = 0, attempt = 10, genNum ;
	genNum = rand()%100  ;
		
	while( num != genNum){
		if(attempt == 0)
		{
	 		cout << "Bad luck, you ran out of attempts. The number was : " << genNum ;
	 		break;
		}	
		cout << "Enter guessing number : " ;
		cin >> num ;
	 	
	 	
		if(num > genNum ){
		 	attempt-- ;
	 		cout<< "Try guessing a LOWER number!" <<endl ;
		}
		else if(num < genNum ){
			attempt-- ;
		 	cout<< "Try guessing a HIGHER number!" << endl;
		} 
		else if (num == genNum)
		{
	 		cout << "CONGRATULATIONS, you found the number on attempt : " << attempt << " , Great Job!" << endl ;
	 	}
	 	 	cout << "Try guessing again." << " You have "<<attempt<<" attempts left." ;
	}
	system("pause") ;
	cout << endl << "Press any key to exit...";
    getchar();
	return 0 ;
}
