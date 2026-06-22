#include <bits/stdc++.h> 
using namespace std; 

class Animal { 
    protected:
        string type;
        string name; 
        unsigned age; 
        float weight; 
        float length; 
    public: 
        Animal(string n, string t, unsigned a, float w = 0.0f, float l = 0.0f) 
        : name(n), type(t), age(a), weight(w), length(l){}

        virtual ~Animal() {} 
        void setName(string n) {name = n;} 
        void setAge(unsigned a) {age = a;} 
        void setWeight(float w) {weight = w;} 
        void setLenght(float l) {length = l;} 
        void setType(string t) {type = t;}

        string getName() const{return name;}
        unsigned getAge() const{return age;}
        float getWeight() const{return weight;}
        float getLength() const{return length;}
        string getType() const{return type;}
        
        virtual string SelfIntroduce() const = 0;
        virtual string tag() const {return type;}    
};

class Lion : public Animal{
    public: 
        Lion(string name, string type, unsigned age, float weight = 190.0f, float length = 2.0f) 
            : Animal(name, type, age, weight, length){}
        
        string SelfIntroduce() const override{ 
            return name + ", The Lion King.";
        }   
};

class Dog : public Animal{
    public: 
        Dog(string name, string type, unsigned age, float weight = 60.0f, float length = 1.8f)
            : Animal(name, type, age, weight, length){}

        string SelfIntroduce() const override{ 
            return name + ", The Disney Famous Dog."; 
        }
};

class Cat : public Animal{ 
    public: 
        Cat(string name, string type, unsigned age, float weight = 20.0f, float length = 1.0f)
            : Animal(name, type, age, weight, length){} 

        string SelfIntroduce() const override{ 
            return name + ", Lady The Cat."; 
        }
};

class Zoo{ 
    private: 
        Animal*  List[20]; 
        unsigned Ln; 
        bool Feed[20][7]; 
        int CurrentDay; 

    public: 
        Zoo() : Ln(0), CurrentDay(0){ 
            for(int i = 0; i < 20; i++){ 
                for(int j = 0; j < 7; j++){ 
                    Feed[i][j] = false; 
                }
            }
        }
    
    ~Zoo(){ 
        for(unsigned i = 0; i < Ln; i++){
            delete List[i];
        }
    }

    bool addAnimal(Animal* animal){ 
        if(Ln >= 20){ 
            cout << "So ngay da day, khong the them!" << endl; 
            return false; 
        }

        List[Ln] = animal; 
        Ln++; 
        return true;
    }

    void showAnimal(){ 
        if(Ln == 0){ 
            cout << "So ngay dang trong." << endl; 
            return; 
        }

        for(unsigned i = 0; i < Ln; i++){ 
            for(unsigned j = i + 1; j < Ln; j++){ 
                if(List[i]->getAge() > List[j]->getAge()){ 
                    swap(List[i], List[j]);
                }
            }
        }

        for(unsigned i = 0; i < Ln; i++){ 
            cout << "- Loai: " << List[i]->getType() 
                 << " | Ten: " << List[i]->getName()
                 << " | Tuoi: " << List[i]->getAge()
                 << " | Gioi thieu: " << List[i]->SelfIntroduce() << endl;
        }

        showAgeReport();
    }

    void feedAnimal(string nameortype){ 
            bool found = false; 
            for(unsigned i = 0; i < Ln; i++){ 
                if(List[i]->getName() == nameortype || List[i]->getType() == nameortype){ 
                    Feed[i][CurrentDay] = true; 
                    cout << "Da cho " << List[i]->getName() << " (" << List[i]->getType() << ") an." << endl; 
                    found = true; 
                }
            }

            if(!found){ 
                cout << "Khong tinm thay dong vat co ten/loai: " << nameortype << " de cho an." << endl;
            }
        }

    void editAnimal(string name, unsigned newAge){ 
        for(unsigned i = 0; i < Ln; i++){ 
            if(List[i]->getName() == name){
                List[i]->setAge(newAge);
                cout << "Da cap nhat tuoi cua " << name << " thanh " << newAge << endl;
                return;
            }
        }
        cout << "Khong tim thay dong vat co ten " << name << endl;
    }

    void showAgeReport(){ 
        cout << "\n --- BAO CAO THONG KE TUOI ---" << endl; 
        vector<string> type; 

        for(unsigned i = 0; i < Ln; i++){ 
            if(find(type.begin(), type.end(), List[i]->getType()) == type.end()){ 
                type.push_back(List[i]->getType());
            }
        }

        for(const auto& t : type){ 
            float sumArithmetic = 0; 
            float sumHarmony = 0; 
            int count = 0; 

            for(unsigned i = 0; i < Ln; i++){ 
                if(List[i]->getType() == t){ 
                    sumArithmetic += List[i]->getAge(); 
                    sumHarmony += (1.0f / List[i]->getAge());
                    count++;
                }
            }

            if(count > 0){ 
                float arithmeticMean = sumArithmetic / count; 
                float harmonicMean = count / sumHarmony;
                cout << "Loai [ " << t << " ]:\n" 
                     << "  + Trung binh cong (Arithmetic Mean): " << arithmeticMean << "\n" 
                     << "  + Trung binh dieu hoa (Harmony Mean): " << harmonicMean << endl;
            }
        }
    }

};


int main(){ 
    Animal *lion1 = new Lion("Simba", "Aslan", 5, 180.0f, 2.1f);
    Animal *lion2 = new Lion("Mufasa", "Aslan", 8, 220.0f, 2.5f);
    Animal *zebra1 = new Dog("Marty", "Puddle", 3, 20.0f, 1.5f);
    Animal *zebra2 = new Dog("Alex", "Puddle", 4, 25.0f, 1.8f);
    Animal *eagle1 = new Cat("Eagle", "Moon", 2, 10.0f, 1.0f);
    Animal *eagle2 = new Cat("Hawk", "Moon", 3, 170.0f, 2.0f);

    Zoo zoo;
    zoo.addAnimal(lion1); // <---- implement code
    zoo.addAnimal(lion2);
    zoo.addAnimal(zebra1);
    zoo.addAnimal(zebra2);
    zoo.addAnimal(eagle1);
    zoo.addAnimal(eagle2);


    std::cout << "----- ANIMALS -----" << std::endl;
    zoo.showAnimal(); // <---- implement code
    std::cout << std::endl;

    std::cout << "----- FEEDING ANIMALS -----" << std::endl;
    zoo.feedAnimal("Simba"); // <---- implement code
    zoo.feedAnimal("Marty");
    zoo.feedAnimal("Eagle");
    std::cout << std::endl;

    std::cout << "----- EDITTING ANIMALS -----" << std::endl;
    zoo.editAnimal("Simba", 6); // <---- implement code
    zoo.editAnimal("Marty", 4);
    zoo.editAnimal("Eagle", 3);
    std::cout << std::endl;

    return 0;

}