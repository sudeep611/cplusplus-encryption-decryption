/*
Encryption and Decryption Program (Written in C++)
By Sudeep Acharya
http://twitter.com/acsudeep

Encryption and decryption is done by the method of letter shifting.
*/

#include<iostream>
#include<iomanip>
#include<string.h>
#include<dos.h>


using namespace std;

class EncryptionDecryption {
	private:
		string outputstring;
		string inputstring;
		string encpass;
		string decpass;
		int enckey;
		int deckey;
		int temp;
		char tempc;
		void doEncryption(); //function to do Encryption
		void doDecryption(); //function to do Decryption
	public:
		EncryptionDecryption(); //initializer Default Constructor
		EncryptionDecryption(string); //parameterized constructor	
		void setInputString(string); //
		~EncryptionDecryption();
		int checkEncPass(string);
		int checkDecPass(string);
		void getOutputString(); //get the encrypted string

};

//Use this function to do Encryption
void EncryptionDecryption::doEncryption() {
	for(int i=0;i<inputstring.size();i++) {
		temp = (int)inputstring[i];
		temp = temp + enckey;
		tempc = (char)temp;
		outputstring += tempc; 
		}

}
//End of encryption function

//Use this function to do Decryption
void EncryptionDecryption::doDecryption() {
	for(int i=0;i<inputstring.size();i++) {
		temp = (int)inputstring[i];
		temp = temp + deckey;
		tempc = (char)temp;
		outputstring += tempc;
		}
	

}
//End of decryption function

void EncryptionDecryption::getOutputString() {
	outputstring += '\0';
	cout << "The Encrypted/Decrypted string is"  <<" : "<<outputstring;	
	outputstring="";
}

//first check the password
int EncryptionDecryption::checkEncPass(string pass) {
	//check password before encrypting
	if(pass!=encpass)
	{	
		cout << endl << "The password you entered is Incorrect the, Encryption will not proceed.\nTry Again \n";
		return 0;
	}	
	else {
		doEncryption();
		return 1;
	}	
}

//first check the password
int EncryptionDecryption::checkDecPass(string pass) {
	//check password before encrypting
	if(pass!=decpass)
	{	
		cout << endl << "The password you entered is Incorrect the, Decryption will not proceed.\nTry Again \n";
		return 0;
	}	
	else {
		doDecryption();
		return 1;
	}	
}

//Initializer
EncryptionDecryption::EncryptionDecryption() {
	inputstring = "";
	outputstring = "";
	encpass= "111"; //this is the password
	decpass= "000";
	enckey= 5; //this is the key
	deckey= -1 * enckey;
	temp= 0;
	tempc='\0';
}


EncryptionDecryption::EncryptionDecryption(string e) { 
	inputstring = e;
}

void EncryptionDecryption::setInputString(string f) {
	inputstring=f;
}

EncryptionDecryption::~EncryptionDecryption() {
}

//The program begins here
int main() 

{

	string inputstring;
	string pass;
	char ch;
	bool quit=false;
	EncryptionDecryption O1; //creating object

	//Which operation you want to perform
		cout << "\n******************************************";
		cout << "\nMenu\n";
		cout << "1. Encryption\n";
		cout << "2. Decryption\n";
		cout << "3. Quit\n";
		cout << "******************************************";
		

	while(!quit)
	{
		quit = false;
		cout << "\nEnter the choice to perform the task";
		cout << "\nEnter 1 or 2 or 3: ";	
		cin >> ch;
		

		switch(ch)
		{

				case '1':
					cout << "Enter word to Encrypt: ";
					cin.ignore();
					getline(cin, inputstring);
						
					O1.setInputString(inputstring); //set the encryption text
					
					cout << "Enter the password to proceed Encryption: ";
					getline(cin, pass);
					
					if(O1.checkEncPass(pass)==1) { //check encryption password and then do encryption if the password is correct
						O1.getOutputString();
					}
					else {
						break;
					}
		
					break;

				case '2':
					cout << "Enter word to Decrypt: ";
					cin.ignore();
					getline(cin, inputstring);

					O1.setInputString(inputstring); //set the decryption string

					cout << "Enter the password to proceed Decryption: ";
					getline(cin, pass);
					
					if(O1.checkDecPass(pass)==1) { //check decryption password and then do decryption if the password is correct
						O1.getOutputString();
					}
					else {
						break;
					} 		
					break;

				case '3':
						cout<< "Exiting the program";
						quit=true;
						break;
				case '\n':
        		case '\t':
        		case ' ':
            			break;			   
				default:
						cout<<"Wrong Choice";
						quit=false;
						break;	
			}
		cout << "\n\n";
	}

	return 0;
}

