// CSCI41Lab2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

double calVolume(double L, double W, double H) {
    return L * W * H;
}

void factorial_reference(int* x)
{
    int fact = 1;
    for(int i = 1; i <= *x; i++)
    {
        fact = fact * i;
    }
    cout << fact << endl;
}

void factorial_pointer(int x, int *fact)
{
    *fact = 1;

    for (int i =1; i <=x; i++)
    {
        *fact =*fact*i;
    }
}

void rev(vector<int> &v) 
{
    int i = 0, n = v.size() - 1;
    while (i <= n) 
    {
        swap(v[i], v[n]);
        i++;
        n--;
    }
}

bool ispali(vector<int>& v) {
    int i = 0, n = v.size() - 1;
    while (i <= n) {
        if (v[i] != v[n]) {
            return false;
        }
        i++;
        n--;
    }

    return true;

}
int main() 
{
    cout << "volume =" << calVolume(1, 2.3, 5) << endl;

    int x = 4;
    int fact;

    factorial_reference(&x);

    factorial_pointer(x, &fact);
    cout << fact << endl;

    vector<int> v1 = { 1,2,3,4,5};
    rev(v1);

    for (auto i : v1) {
        cout << i << " ";
    }
    cout << endl;
    
    vector<int> v = { 1,2,2,1 };
    cout << (ispali(v) ? "palindrome" : "not palindrome") << endl;
}

//cout << &b << endl;  print address a of ie 1000
//cout << c << endl; print pointer c which store address of a
//cout << *c << endl;  prints value of a   
//cout << cPtrPtr << endl;  prints 5000 ie address of pointer of a
//cout << *dPtr << endl;  prints address of d
//cout << dPtrPtr << endl;  prints address of dptr
//cout << d << endl;  prints value of d