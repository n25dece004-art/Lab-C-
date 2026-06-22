// Subject to Programming With C++
// In this test, some function prototypes are provided without implementation.
// You should complete them by adding code for the missing implementation.

// DO NOT MAKE CHANGE in any provided prototype and comment.
// DO NOT USE CIN>>, COUT<<, (or scanf(), printf()) in class function members.
// You can add support funtions 1)for F01(), F02(): put in global scope, 2)for function members of a class:put in its private scope.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool isFibonacci(unsigned x){
	unsigned a = 1, b = 1; 
	if(x == 1) return true; 
	while(b < x){
		unsigned temp = a + b; 
		a = b; 
		b = temp;
	}
	return b == x;
}

unsigned F01(unsigned n)
{	// 111 <= n <= 999 and n does not contain digit 0.
	// Fibonacci number F: F0=1,F1=1,..,F[n]=F[n-1]+F[n-2]
	// F01(n) tries to permute (hoán vị) the digits of n so that
	// n is the largest possible Fibonacci number, then returns n; otherwise returns 0.
	// ex: n=160 -> F1(n) returns 610.
	// (3 marks)

	string s = to_string(n); 
	sort(s.begin(), s.end()); 

	unsigned max_fib = 0; 
	bool found = false;

	do{ 
		unsigned val = stoi(s); 
		if(isFibonacci(val)){ 
			if(!found || val > max_fib){ 
				max_fib = val; 
				found = true; 
			}
		}
	} while (next_permutation(s.begin(), s.end()));

	return found ? max_fib : 0; 
}

unsigned F02(unsigned A[],unsigned n, unsigned& k)
{	// n is the number of elements in array A
	// find the element x that appears the most times in A (k times)
	// update k = number of occurrences of x
	// return x;
	// (2 marks)

	unsigned maxCount = 0; 
	unsigned mostFreq = A[0]; 

	for(unsigned i = 0; i < n; i++){ 
		unsigned count = 0; 
		for(unsigned j = 0; j < n; j++){ 
			if(A[i] == A[j]){ 
				count++;
			}
		}
		if(count > maxCount){ 
			maxCount = count; 
			mostFreq = A[i];
		}
	}
}

class Animal
{	protected:
		string name;
		string AniType;
	public:
	Animal(string Name, string Type){   this->name = Name; this->AniType = Type;}
	string Getname() {return this->name;}
	string GetType() {return this->AniType;}

	virtual int Speed(int seconds) = 0;
	friend Animal& Winner(Animal &a, Animal &b, int Distance);
};

class Tiger: public Animal
{	public:
	// implement constructor Tiger(string Name) with default AniType="Tiger"
	// implement int Speed(int s): S = 18m/s last for 30s, down to 12m/s 
	// (1 mark)
	Tiger(string Name) : Animal(Name, "Tiger"){}

	int Speed(int s) override{ 
		if(s <= 30) return 18; 
		return 12;
	}
};

class Panther: public Animal
{	public:
    // implement constructor Panther(string Name) with default AniType="Panther"
	// implement int Speed(int s): S = 17m/s last for 20s, down to 15m/s 
	// (1 mark)
	Panther(string Name) : Animal(Name, "Panther"){}

	int Speed(int s) override{ 
		if(s <= 17) return 20; 
		return 15;
 	}
};

Animal& Winner(Animal &a, Animal &b, int Distance)
{	// returns the one that takes shorter time to win the race
	// hint: canculate D(t) using Speed(t) for t=1,2,3...ti seconds until D(ti) = Distance,
	// then compare each running time t1 and t2.
	// (3 marks)
	int tA = 0, disA = 0; 
	while(disA < Distance){ 
		tA++;
		disA += a.Speed(tA);  
 	}

	int tB = 0, disB = 0; 
	while(disB < Distance){ 
		tB++; 
		disB += b.Speed(tB); 
	}

	if(tA <= tB){ 
		return a;
	} else { 
		return b;
	}
}


int main(){
	cout << "TEST F01" << endl; 
	cout << F01(160) << endl; 
	cout << F01(332) << endl; 
	cout << F01(123) << endl;

	cout << "TEST F02" << endl; 
	unsigned A[] = {1, 3, 2, 4, 3, 2, 2, 2}; 
	unsigned k = 0; 
	unsigned n = sizeof(A) / sizeof(A[0]); 
	unsigned x = F02(A, n, k); 
	cout << "Phan tu xuat hien nhieu nhat:" << x << ", so lan: " << k << endl;

	cout << "TEST CLASS AND WINNER" << endl; 
	Tiger t("Richard Parker"); 
	Panther p("Banana"); 

	int dis = 1000; 
	Animal& winner = Winner(t, p, dis); 

	cout << "Nguoi thang o cu ly " << dis << "m la: " << winner.Getname() << "(" << winner.GetType() << ")" << endl;

	return 0;
}