// CSCI41Lab1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

double findMin(vector<double> a)
{

    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    double min = a[0];
    for (double j = 0; j < 5; j++)
    {
        if (a[j] < min)
            min = a[j];
    }
    return min;
}

int calculate(string exp)
{
    int location = 0;

    for (int i = 0; i < exp.size(); i++) 
    {
        if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/') 
        {
            location = i;
            break;
        }
    }

    int a = stoi(exp.substr(0, location));
    int b = stoi(exp.substr(location + 1));

    if (exp[location] == '+')
    {
        return a + b;
    }
    else if (exp[location] == '-')
    {
        return a - b;
    }
    else if (exp[location] == '*')
    {
        return a * b;
    }
    else
    {
        return a / b;
    }
}
vector<int> transpose(vector<vector<int>> b)
{
    vector<vector<int>> result(b[0].size(), vector<int>(b.size()));
    for (int i = 0; i < b[0].size(); i++)
    {
        for (int j = 0; j < b.size(); j++) 
        {
            result[i][j] = b[j][i];
        }
    }
    return result;
}

int main()
{

    int input;
    cout << "Please input your command. \n";
    cout << "1: To find min value of integer array. \n";
    cout << "2: To find the transpose of b. \n";
    cout << "3: To find the computation of a string expression. \n";
    cout << "4: To read the vector of string and count the frequency of each word. \n";
    cout << "-1: To stop the program. \n";
    cin >> input;

    while (input != -1)
    {
        if (input == 1)
        {
            vector<double> a = { 4.2, 6.5, 12.8, 18.3, 9.1 };
            cout << "The min value of array a is: " << findMin(a) << endl;
        }
        else if (input == 2)
        {
            int vector<b> = { 1,2,3 }, { 4,5,6 };
            vector<int> transpose(vector<vector<int>> b);
        }
        else if (input == 3)
        {
            cout << calculate("54321+222") << endl;
            cout << calculate("120*20") << endl;
            cout << calculate("235/3") << endl;
            cout << calculate("356-32") << endl;
        }
        else if (input == 4)
        {
            //void frequencyCount(vector<string> & words);
        }
        break;
    }
}