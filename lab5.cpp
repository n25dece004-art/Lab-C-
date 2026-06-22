// Subject to Programming With C++
// In this test, some function prototypes are provided without implementation.
// You should complete them by adding code for the missing implementation.

// DO NOT MAKE CHANGE in any provided prototype and comment.
// DO NOT USE CIN>>, COUT<<, (or scanf(), printf()) in class function members.
// You can add support funtions 1)for F01(), F02(): put in global scope, 2)for function members of a class:put in its private scope.

#include <iostream>
#include <vector>
using namespace std;

bool SumMul(unsigned m){
    if(m == 0) return false; 
    unsigned sum = 0; 
    unsigned mul = 1; 
    unsigned temp = m; 

    while(temp > 0){ 
        unsigned digit = temp % 10; 
        sum += digit; 
        mul *= digit; 
        temp /= 10;
    }
    return mul == 2 * sum;
}

unsigned F01(unsigned N)
{	// m is a number with k digits a1,a2,...,ak.
	// F01(N) returns the largest number m <= N such that: a1*a2*...*ak = 2*(a1+a2+...+ak)
	// that is: the product of the digits of m is twice the sum of the digits of m.
	// If m cannot be found that satisfies the above condition then returns m = 0.
	// (3 marks)

    for(unsigned m = N; m >= 1; m--){ 
        if(SumMul(m)){ 
            return m;
        }
    }
    return 0;
}

unsigned GCD(unsigned a, unsigned b){ 
    while(b != 0){ 
        unsigned temp = a % b; 
        a = b; 
        b = temp;
    }
    return a;
}

unsigned LCM(unsigned a, unsigned b){ 
    if(a == 0 || b == 0) return 0;
    return (a / GCD(a,b)) * b;
}

unsigned F02(unsigned A[],unsigned n)
{	// n is the number of elements in array A
	// Function F02() finds number U which is the least common multiple of n numbers in A
	// returns U;
	// (2 marks)
    if(n == 0) return 0; 

    unsigned U = A[0]; 
    for(unsigned i = 1; i < n; i++){ 
        U = LCM(U, A[i]);
    } 
    return U;
}

class Monomial // don thuc, for only one variable x, such as x^2
{   
	public:
    int Co; // Coefficient, he so cua don thuc
    int Po; // Power of x, so mu cua bien x
    Monomial(int an=0, int n=0) {  Co = an; Po = n; }
};

class Polynomial // da thuc, for example, P(x) = 1 +2x +3x^2
{   
	private:
    vector <Monomial> P; // P is a polynomial, is a set of monomial
    
	public:
	
	// Constructors
    Polynomial() { P = {}; }
    Polynomial(Monomial m)
    {   P = {};  P.push_back(m);
    }
	
	// Getters
	vector <Monomial> GetThis() { return P; }
	
	// OVERLOAD
    Polynomial operator + (Monomial m) // operator overload
    {   // this obj = 1 + 2x, m = 3x : --> 1 + 5x
        // (2 marks)
        Polynomial result = *this; 
        bool isMerged = false; 

        for(unsigned i = 0; i < result.P.size(); i++){ 
            if(result.P[i].Po == m.Po){ 
                result.P[i].Co += m.Po; 
                isMerged = true; 
                break;
            }
        }
        if(!isMerged && m.Co != 0){ 
            result.P.push_back(m);
        }
        return result;
    }
	
    Polynomial operator + (Polynomial u) // operator overload
    {
        // this obj = 1 + 2x, u = 3x + 4x^2 : --> 1 + 5x + 4x^2
        // (1 mark)
        Polynomial result = *this; 
        for(unsigned i = 0; i < u.P.size(); i++){ 
            result = result + u.P[i]; 
        }
        return result;
    }
    
    Polynomial operator * (Monomial m) // operator overload
    {   // multiply this object by m, and return the new polynomial
        // this obj = 1 + 2x, m = 3x :--> 3x + 6x^2
        // (1 mark)
        Polynomial result; 
        if(m.Co == 0) return result; 

        for(unsigned i = 0; i < P.size(); i++){ 
            Monomial tempM(P[i].Co * m.Co, P[i].Po + m.Po);
            result = result + tempM; 
        }
        return result;
    }
	
    Polynomial operator * (Polynomial u) // operator overload
    {   // multiply this object by u, and return the new polynomial
        // this obj = 1 + 2x, u = 3x + 4x^2 : --> 3x + 10x^2 + 8x^3
        // (1 mark)
        Polynomial result; 

        for(unsigned i = 0; i < u.P.size(); i++){ 
            result = result + (*this * u.P[i]); 
        }
        return result;
    }
};

int main()
{
	// you can write testcode here freely.
    cout << "--- Test F01 ---" << endl;
    cout << "F01(40) = " << F01(40) << " (Expected: 36. Vi 3*6 = 18 = 2*(3+6))" << endl;

    cout << "\n--- Test F02 ---" << endl;
    unsigned A[] = {12, 15, 75};
    cout << "LCM cua mang A: " << F02(A, 3) << " (Expected: 300)" << endl;

    cout << "\n--- Test Polynomial ---" << endl;
    Polynomial p1(Monomial(2, 1)); 
    p1 = p1 + Monomial(1, 0);     
    
    Polynomial p2(Monomial(4, 2)); 
    p2 = p2 + Monomial(3, 1);      
    
    Polynomial sum = p1 + p2;      
    Polynomial prod = p1 * p2;     
    
    cout << "Test cong da thuc (Kiem tra he so cua tung don thuc):" << endl;
    for(auto m : sum.GetThis()) {
        cout << m.Co << "x^" << m.Po << "  ";
    }
    
    cout << "\nTest nhan da thuc:" << endl;
    for(auto m : prod.GetThis()) {
        cout << m.Co << "x^" << m.Po << "  ";
    }
    cout << endl;

    return 0;
}