// Subject to Programming With C++
// In this test, some function prototypes are provided without implementation.
// You should complete them by adding code for the missing implementation.

// DO NOT MAKE CHANGE in any provided prototype and comment.
// DO NOT USE CIN>>, COUT<<, (or scanf(), printf()) in class function members.
// You can add support funtions 1)for F01(), F02(): put in global scope, 2)for function members of a class:put in its private scope.

#include <bits/stdc++.h> 
using namespace std;

bool isSquare(unsigned x){ 
	unsigned r = round(sqrt(x)); 
	return( r * r == x);
}

unsigned F01(unsigned n)
{	// 111 <= n <= 999 and n does not contain digit 0
	// F1(n) tries to permute (hoán vị) the digits of n so that n is a square number : n = k * k
	// then returns n; otherwise returns 0.
	// ex: n = 52 -> F1(n) returns 25 (5*5)
	string s = to_string(n); 
	sort(s.begin(), s.end()); 

	unsigned maxSq = 0; 
	bool found = false; 

	do{
		unsigned val = stoi(s); 
		if(isSquare(val)){
			if(!found || val > maxSq){ 
				maxSq = val; 
				found = true;
			}
		}
	} while (next_permutation(s.begin(), s.end()));

	if(found == true ){ 
		return maxSq; 
	} else { 
		return 0;
	}
	return 0;
}

void F02(unsigned A[], unsigned n)
{	// n is the number of elements in array A
	// Sort array A in descending order according to the number of occurrences of each element
	// If the number of occurrences is the same: sort (ascending) by value of elements
	if(n == 0) return; 

	vector <unsigned> counts(n, 0); 

	for(unsigned i = 0; i < n; i++){ 
		unsigned count = 0; 
		for(unsigned j = 0; j < n; j++){ 
			if(A[i] == A[j]){ 
				count++;
			}
		}
		counts[i] = count; 
	}

	for(unsigned i = 0; i < n; i++ ){ 
		for(unsigned j = i + 1; j < n; j++){ 
			if((counts[i] < counts[j] )|| (counts[i] == counts[j] && A[j] < A[i])){
				swap(A[i], A[j]); 
				swap(counts[i], counts[j]);
			}
		}
	}


}

class Lion
{   private:
    string name;
		int sex;    // 0 for female, 1 for male
		string dob; // date of birth, yyyy/mm/dd
		vector <Lion *> MotherOf; // Lion name list
    public:
	// Constructor
		Lion(string Name, int Sex){ name = Name; sex = Sex; MotherOf ={}; }
	// Getters
		string getName() { return name;}
		int getSex() { return sex;}
		string getDob() { return dob;}
		
		vector <Lion *> getChildren() { return MotherOf; }
		
	// Functions
		bool AddChild(Lion * Li)
		{   // if *this is male : return false (can't have child)
			// Add Li to MotherOf
			if(this->sex == 1) return false; 
			MotherOf.push_back(Li); 
			return false;
		}
};

class Zoo
{	
	// each animal in the zoo has a unique name.
	
	private:
		vector <Lion> LionSet;

    
	public:
		Zoo() { LionSet={}; }
		
		bool ZooDataValidate()
		{	
			// IF Li is a descendant of herself: incorrect -> reurn false
			// IF one of Li'childen has another mother: incorrect -> return false
			vector<string> allChildrenNames;

			for(unsigned i = 0; i < LionSet.size(); i++){ 
				vector<Lion*> kids = LionSet[i].getChildren(); 
				for(unsigned j = 0; j < kids.size(); j++){ 
					if(kids[j] != nullptr){ 
						allChildrenNames.push_back(kids[j]->getName());
					}
				}
			}

			for(unsigned i = 0; i < allChildrenNames.size(); i++){ 
				for(unsigned j = i + 1; j < allChildrenNames.size(); j++){
					if(allChildrenNames[i] == allChildrenNames[j]){ 
						return false; 
					}
				}
			}

			for(unsigned i = 0; i < LionSet.size(); i++){ 
				string currentLionName = LionSet[i].getName(); 

				vector<Lion*> descendants = LionSet[i].getChildren();

				for(unsigned k = 0; k < descendants.size(); k++){ 
					Lion* currentDescendant = descendants[k]; 
					if (currentDescendant == nullptr) continue; 

					if(currentDescendant->getName() == currentLionName){ 
						return false; 
					}
					vector<Lion*> nextGen = currentDescendant->getChildren(); 
					for(unsigned m = 0; m < nextGen.size(); m++){ 
						if(nextGen[m] != nullptr){ 
							descendants.push_back(nextGen[m]);
						}
					}
				}
			}
			return true;
		}
		
		bool AddLion(Lion * li)
		{
			// IF Li.name is already in the zoo: return false 
			for(unsigned i = 0; i < LionSet.size(); i++){ 
				if(LionSet[i].getName() == li->getName()) return false;
			}
			LionSet.push_back(*li);
			return true;
		}
		
		bool AddLionChild(Lion * mother, Lion *child)
		{
			// AddLion (mother), AddLion (child)
			// mother ->AddChild(child)
			AddLion(mother); 
			AddLion(child); 

			bool result = mother->AddChild(child); 

			for(unsigned i = 0; i < LionSet.size(); i++){ 
				if(LionSet[i].getName() == mother->getName()){ 
					LionSet[i].AddChild(child);
				}
			}
			return result;
		}
		
		vector <Lion> getLionSet() { return LionSet;}
		
		void ListLions()
		{
			// List all lions (and her children) from this zoo
			for(unsigned i = 0; i < LionSet.size(); i++){ 
				cout << "- Lion: " << LionSet[i].getName() 
					 << " (Sex: " << (LionSet[i].getSex() == 0 ? "Female" : "Male" ) << endl; 
				vector<Lion*> children = LionSet[i].getChildren(); 
				if(!children.empty()){ 
					cout << " Children: "; 
					for(unsigned j = 0; j < children.size(); j++){ 
						if(children[j] != nullptr){ 
							cout << children[j]->getName() << " ";
						}
					}
					cout << endl;
				}
			}
		}
};

int main()
{
	
    cout << "--- Test F01 ---" << endl;
    cout << "F01(52) = " << F01(52) << " (Expected: 25)" << endl;
    cout << "F01(144) = " << F01(144) << " (Expected: 441)" << endl;

    cout << "\n--- Test F02 ---" << endl;
    unsigned A[] = {2, 5, 2, 8, 5, 6, 8, 8};
    unsigned n = sizeof(A) / sizeof(A[0]);
    F02(A, n);
    cout << "Mang sau khi sort F02: ";
    for(unsigned i = 0; i < n; i++) cout << A[i] << " ";
    cout << "\n(Expected freq sort: 8 8 8 2 2 5 5 6)" << endl;


    cout << "\n--- Test Class Zoo ---" << endl;
    Lion mufasa("Mufasa", 1);
    Lion sarabi("Sarabi", 0);
    Lion simba("Simba", 1);

    Zoo z;
    z.AddLionChild(&sarabi, &simba);
    
    
    bool canAdd = z.AddLionChild(&mufasa, &simba); 
    cout << "Mufasa (Male) add child result: " << (canAdd ? "True" : "False") << endl;
    
    cout << "Data Validated: " << (z.ZooDataValidate() ? "True" : "False") << endl;
    
    cout << "\nDanh sach thu tu:" << endl;
    z.ListLions();

    return 0;
}