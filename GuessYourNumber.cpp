#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std ;

int main ()
{
	time_t t ;
	srand((unsigned) time(&t)) ;
	
	int guessingNumber,  low = 1, high = 100, attempt = 10 ;
	string userH = "higher", userL = "lower", userAnswer ;
		cout << "I'll try to guess number, which you're thinking, just tell me, if number needs to be 'higher' or 'lower'." << endl ;
		cout << "If I guess your number, just type 'yes'. " << endl ;
	 
			guessingNumber = low + rand() % (high - low + 1);
			cout << "Here we go, is your number : " << guessingNumber << endl;
			cout << "Enter 'higher', 'lower' or 'yes'." << endl ;
	 
	 while(userAnswer != "yes")
	 	{
	 
		cin >> userAnswer ;
		
		if(userAnswer == userH)
		{
			low = guessingNumber + 1 ;
	 		guessingNumber = low + rand() % (high - low + 1) ;
	 		attempt-- ;
			cout << "You have " << attempt << " attempts left."	 << endl ;
		 	cout << "Guessing higher, is your number : " << guessingNumber << " ?" << endl;
	 		
		}
		else if ( userAnswer == userL)
		{
	 		high = guessingNumber - 1;
	 		guessingNumber = low + rand() % (high - low + 1);
	 		attempt--;
	 		cout << "You have " << attempt << " attempts left."	 << endl ;
	 		cout << "Guessing lower, is your number : " << guessingNumber  << " ?" << endl;
		}
		else if(userAnswer == "yes") 
		{
			cout << "I managed to guess your number on attempt : " <<attempt <<" , it was number : " << guessingNumber << endl ;
			break ;
		}
		else if(attempt == 0)
		{
			cout << "You ran out of attempts." << endl ;
			break ;
		}
		else 
		{
	 		cout << "Enter 'higher', 'lower' or 'yes'." << endl ;
		}
		
		
		
	}
	cout << "Press any key, to exit ..." << endl ;
	getchar() ;
	return 0 ;
}
