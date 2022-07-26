// CSCI41Lab7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

int sum(int n)
{
    if (n != 0)
    {
        return n + sum(n - 1);

    }
    else
        return n;
}

int power(int base, int exponent)
{
    if (exponent == 0)
    {
        return 1;

    }
    return base * power(base, exponent - 1);
}

bool palindrome(string word)
{
    int length = word.length();

    string first = word.substr(0, 1);
    string last = word.substr((length - 1), 1);

    if (first == last)
    {
        word = word.substr((0 + 1), (length - 2));
        if (word.length() <= 1) return true;
        else
            return palindrome(word);
    }
    else
        return false;
}

void reverse(string str)
{
    if (str.size() == 0)
    {
        return;
    }
    reverse(str.substr(1));
    cout << str[0];
}

int binarySearch(vector<int> &vec, int start, int end, int val)
{
    if (start > end)
    {
        return -1;
    }
    int mid;
    mid = start + (end - start) / 2;

    if (vec[mid] == val)
    {
        return mid;
    }
    else if (vec[mid] < val)
    {
        return binarySearch(vec, mid + 1, end, val);
    }
    else
    {
        return binarySearch(vec, start, mid - 1, val);
    }
}

int fibRecursive(int n)
{
    if (n <= 1)
        return n;
    return fibRecursive(n - 1) + fibRecursive(n - 2);
}

int fib(int e) 
{
    int n1 = 0;
    int n2 = 1;
    int next = 1;

    for (int i = 0; i < e - 1; ++i)
    {
        next = n1 + n2;
        n1 = n2;
        n2 = next;
    }
    return next;
}

int main()
{
    //sums
    int n;
    cout << "\n enter a number(for sum of n numbers):";
    cin >> n;
    cout << "\n The sum of " << n << " numbers is = " << sum(n);

    //power
    int base = 2, exponent = 3;
    cout << "\n " << base << "^" << exponent << " is = " << power(base, exponent);

    //palindrome
    string word = "abba";
    string word2 = "abbc";

    if (palindrome(word) == true)
        cout << "\n The String " << word <<" is a palindrome.";
    else
        cout << "\n The String " << word <<" is not a palindrome.";

    if (palindrome(word2) == true)
        cout << "\n The String " << word2 << " is a palindrome.";
    else
        cout << "\n The String " << word2 << " is not a palindrome.";

    cout << endl;
    //reverse
    string a = "Fresno";
    reverse(a);

    cout << endl;
    //binary search
    vector<int> vec;
    int vecsize = 5;
    int elem;

    for (int i = 0; i < vecsize; i++)
    {
        cout << "Element #" << i + 1 << ": ";
        cin >>elem;
        vec.push_back(elem);
    }

    int val;
    cout << "Enter value you are searching for: ";
    cin >> val;
    
    int loc;
    loc = binarySearch(vec, 0, vec.size() - 1, val);
    if (loc >= 0)
    {
        cout << "The number you are searching for is Element #" << loc + 1;
    }
    else
    {
        cout << "Not found";
    }
    cout << endl;

    //Fibonacci with recursion
    int d = 9;
    cout << fibRecursive(d);

    cout << endl;

    //Fibonacci without recursion
    int e = 9;
    cout << fib(e);
    return 0;
}



