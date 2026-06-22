/* LAB-3

Declare an Animal class that has the attributes of Name, Genus, and Weight.
Declare four (4) specific animal classes that inherit attributes from the Animal class.  
In the lab we built two, Duck and Butterfly.  

Implement show() and speak() methods for each subclass.  
These methods will also be virtual classes in Animal and will allow the use of an array of Animal* in the main().

Your program should ask the user for the number of animals they would like in there zoo.  
Allow the user to select each animal from the animal subclasses you have implemented.  
Store the selections in an array of Animal*.  
After the user has selected all the animals, step thru the array and have each animal show() and speak() in a sort of parade of selected animals.

*/

/*
* File: Zoo.cpp
* Course: C++
*
* This program allows the user for the number of animals they would like in there zoo. 
* Allow the user to select each animal from the animal subclasses that's implemented.
*/

#include <bits/stdc++.h>
using namespace std;

class Animal
{
	string name;
	string genus;  // male or female
	double weight; // in grams

	public:
	Animal(string n, string g, double w)
	{
		name = n;
		genus = g;
		weight = w;
	}

    virtual ~Animal() {}

	virtual void show() = 0;
	virtual void speak() = 0;
	
    string getName() const {return name;}
    string getGenus() const {return genus;}
    double getWeight() const {return weight;}
};

class Duck : public Animal
{
	public:
	Duck(string n, string g, double w) : Animal(n,g,w){}

	void show() override
	{
		cout << " .. \n" << endl;
		cout << " ( '`< \n" << endl;
		cout << " )( \n" << endl;
		cout << " ( ----' '. \n" << endl;
		cout << " ( ; \n" << endl;
		cout << " (________,' \n" << endl;
		cout << "~^~^~^~^~^~^~^~^~^~^~ \n" << endl;
		cout << " \n" << endl;
	}
	
	void speak() override 
	{
		cout << " Quack! Quack!\n";
	}

};

class Fox: public Animal
{
	public:
	Fox(string n, string g, double w) : Animal(n, g, w){}

	void show() override
	{
		cout << " /|_/| \n" << endl;
		cout << " / ^ ^(_o \n" << endl;
		cout << " / __.'' \n" << endl;
		cout << " / \\ \n" << endl;
		cout << " (_) (_) '._ \n" << endl;
		cout << " '.__ '. .-''-'. \n" << endl;
		cout << " ( '. ('.____.'' \n" << endl;
		cout << " _) )'_, ) \n" << endl;
		cout << " (__/ (__/ \n" << endl;
	}
	void speak() override
	{
		cout << " ow-wow-wow-wow-wow! \n";
	}
};

class Paraket: public Animal
{
	public:
	Paraket(string n, string g, double w) : Animal(n, g, w){}
	void show() override 
	{
		cout << " \\ \n";
		cout << " \\ (o> \n";
		cout << " (o> //) \n";
		cout << " _(()_____V_/_____ \n";
		cout << " || || \n";
		cout << " || \n";
	}
	void speak() override 
	{
		cout << "Chirp, Chirp!\n";
	}
};

class Koala: public Animal
{
	public:
	Koala(string n, string g, double w) : Animal(n, g, w){}
	void show() override 
	{
		cout << " (\\-'''-/) \n" << endl;
		cout << " | | \n" << endl;
		cout << " \\ ^ ^ / .-. \n" << endl;
		cout << " \\_o_/ / / \n" << endl;
		cout << " /` `\\// | \n" << endl;
		cout << " / \\ | \n" << endl;
		cout << " \\ ( ) / | \n" << endl;
		cout << " /\\_) (_/ \\ / \n" << endl;
		cout << "| (\\-/) | \n" << endl;
		cout << "\\ --^o^-- / \n" << endl;
		cout << " \\ '.___.' / \n" << endl;
		cout << " .' \\-=-/ '. \n" << endl;
		cout <<" / /` `\\ \\ \n" << endl;
		cout <<"(//./ \\.\\) \n" << endl;
		cout << "`'` `'` \n" << endl;
	}
	void speak() override
	{
		cout << "Groo, Groo!\n";
	}
};

int main()
{
	int num; 
    cout << "How many animal would you like in your zoo? "; 
    cin >> num; 

    Animal** zoo = new Animal*[num];

    for(int i = 0; i < num; i++){ 
        cout << "\n------------------------------------\n"; 
        cout << "Animal #" << i + 1 << " Configuration:\n"; 
        cout << "1.Duck\n2.Fox\n3.Paraket\n4.Koala\n"; 
        cout << "Your choice (1-4): "; 
        int choice; 
        cin >> choice;

        string name, genus; double weight;
        cout << "Enter Name: "; 
        cin >> name; 
        cout << "Enter Genus(male/female): "; 
        cin >> genus; 
        cout << "Enter Weight(in grams): "; 
        cin >> weight;

        if(choice == 1){ 
            zoo[i] = new Duck(name, genus, weight);
        } else if(choice == 2){ 
            zoo[i] = new Fox(name, genus, weight);
        } else if(choice == 3){ 
            zoo[i] = new Paraket(name, genus, weight);
        } else if(choice == 4){ 
            zoo[i] = new Koala(name, genus, weight); 
        } else { 
            cout << "Invalid choice! Defaulting to Duck.\n"; 
            zoo[i] = new Duck(name, genus, weight);
        }
    }

    cout << "\n=========================================\n"; 
    cout << "            WELCOME TO THE ZOO             \n"; 
    cout << "===========================================\n"; 

    for(int i = 0; i < num; i++){ 
        cout << "\n"; 
        zoo[i]->show(); 

        cout << ">> Name: " << zoo[i]->getName()
             << " | Genus: " << zoo[i]->getGenus()
             << " | Weight: " << zoo[i]->getWeight() << "g" << endl;
        
        cout << ">> Voice: "; 
        zoo[i]->speak(); 
        cout << "---------------------------------------\n";

    }

    for(int i = 0; i < num; i ++){ 
        delete zoo[i];
    }
    delete[] zoo;

    return 0;

}
