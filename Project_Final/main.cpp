/* 
 * File:   main.cpp
 * Author: wsturner
 *
 * Created on December 2, 2013, 10:53 AM
 */
/* 
 * File:   main.cpp
 * Author: wsturner
 *
 * Created on October 1, 2013, 1:02 PM
 */

#include <iostream>
#include <string>
#include "Token.h"
#include "Expression.h"
using namespace std;

vector<Expression> judgement(string);
vector<Expression> break_apart(string);
void menu();

int main() 
{
    string input;
    char action = 's';
    vector<Expression> exps;
    vector<Expression> temp;


    menu();
   
    while(action != 'q')
    {
        if(action == 's')
        {
            cout << "Input: ";
            cin >> input;//cin.getline(input,256);
            exps = judgement(input);
        }
        
        else if(action == 'c')
        {
            int i = 0;
            cout << "Input: ";
            cin >> input;//cin.getline(input,256);
            temp = judgement(input);
            while(i < temp.size())
            {
                exps.push_back(temp[i]);
                i++;
            }
        }
        
        else if(action == '=')
        {
            cout << "Hello from inside =" << endl;
        }
        
        else if(action == '>')
        {
            cout << "Hello from inside >" << endl;
        }
        
        else if(action == '<')
        {
            int inc = 0;
            while(inc < exps.size())
            {
                exps.at(inc).display(action);
                cout << endl;
                inc++;
            }
        }
           
        else if(action == 'f')
        {
            int i = 0;
            while(i<exps.size())
            {
                exps[i].parenth();
                i++;
            }
        }
        
        else if(action == 'm')
        {
            menu();
        }
    
        else
        {
            cout << "ERROR: Invalid action input. Please try again." << endl;
            cout << "Press m for the menu." << endl;
        }
        cout << "Action: ";
        cin >> action;
    }
    return 0;
}

void menu()
{
    cout << " __________________________________________________________________________ " << endl;
    cout << "| Hello, and welcome to the expression evaluator, code name The Dark Night |" << endl;
    cout << "| Please input expressions followed by a semicolon and press [ENTER]       |" << endl;
    cout << "| Actions used for the Expression Evaluator 3000 are as follows:           |" << endl;
    cout << "|                                                                          |" << endl;
    cout << "|\t= : evaluates each expression in the sequence of expressions.      |" << endl;
    cout << "|\t> : converts each expression in the sequence to the prefix.        |" << endl;
    cout << "|\t< : converts each expression in the sequence to the postfix.       |" << endl;
    cout << "|\tf : converts each expression in the sequence to have parentheses.  |" << endl;
    cout << "|\tq : quits the program.                                             |" << endl;
    cout << "|\tc : appends new expressions to the the previous sequence           |" << endl;
    cout << "|\ts : starts over for a new sequence of expressions.                 |" << endl;
    cout << "|                                                                          |" << endl;
    cout << "| Input values must be in the format a+2+(C*2);                            |" << endl;
    cout << "| Use no spaces and follow all expressions with a semi-colon.              |" << endl;
    cout << "| Multiple expressions may be entered in one input using their semi-colon  |" << endl;
    cout << "|\tas seperation.                                                     |" << endl;
    cout << "|__________________________________________________________________________|" << endl << endl;
}

vector<Expression> judgement(string s)
{
    vector<Expression> Final;
    cout << "A";
    if(s[s.length()-1] != ';')
    {
        cout << "The input expression was invalid!" << endl;
        return Final;
    }
    
    if(s.find_last_of(";",s.length()) == s.find_first_of(";",0))
    {
        cout << "C";
        Expression a;
        a.set(s);
        if(a.correct())
        {
            Final.push_back(a);
            return Final;
        }
        else
            cout << "The input expression was invalid. Please try again." << endl;
    }
    
    else
    {
        cout << "D";
        Final = break_apart(s);
        cout << "E";
        if(Final.size()>0)
            return Final;
        else
            cout << "The input expressions were invalid! Please try again." << endl;
    }
}

vector<Expression> break_apart(string s)
{
    vector<Expression> works;
    
    int pos1 = 0;
    int pos2 = 0;
    int inc = 0;
    int good = 0;
    string temp;
    Expression temp2;
    
    cout << "M";
    while(pos1 < s.length())
    {
        cout << "N";
        pos2 = s.find_first_of(';',pos1+1);
        temp.assign(s, pos1, pos2-pos1+1);
        temp2.set(temp);
        
        if(temp2.correct())
        {
            cout << "P";
            works.push_back(temp2);
            good++;
        }
        
        cout << "Q";
        pos1 = pos2+1;
        inc++;
        temp = "";
    }
    cout << "R";
    if(good > 0 && good < inc)
        cout << "One or more of the expressions was invalid, however the correct expressions will be added." << endl;
    return works;
}