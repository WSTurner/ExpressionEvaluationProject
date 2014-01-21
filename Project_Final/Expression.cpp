#include <cstdlib>
#include <iostream>
#include "Expression.h"

using namespace std;


template <class T>
class stack{
public:
    stack();
    ~stack();
    bool empty() const;
    unsigned int size() const;
    T& top();
    const T& top() const;
    void push(const T& x);
    void pop();
    void display();
private:
    T * arr;
    unsigned int cap; //capacity
    int index;        //index of array
};


//STACKS/////////////////////////////////////////////////////////////////////||
template <class T>
stack<T>::stack() {

    cap = 4;
    index = 0;
    arr = new T[cap];
}
template <class T>
stack<T>::~stack() {

    delete [] arr;
    //cout << "destructed stack" << endl;
}
template <class T>
bool stack<T>::empty() const {

    return (index == 0);
}
template <class T>
unsigned int stack<T>::size() const {
    
    return index;
}
template <class T>
T& stack<T>::top() {

    if (!empty())
    {
        return arr[index-1];
    }
}
template <class T>
const T& stack<T>::top() const {

    if (!empty())
    {
        return arr[index-1];
    }

}
template <class T>
void stack<T>::push(const T& x)
{
    if (index > cap-1) {
        cap = cap*4;
        T * newarr = new T[cap];
        for (int i = 0; i < index;i++) {
            newarr[i] = arr[i];
        }
        delete arr;
        arr = newarr;
        cout << "capacity doubled" << endl;
    }
    arr[index]= x;
    index++;
}
template <class T>
void stack<T>::pop() 
{
    if (!empty())
    {
        index--;
    }
}
template <class T>
void stack<T>::display()
{
    if (!empty()) {
        for (int i = index-1; i >= 0;i--) {
            cout << "index : " << i << " : val : " << arr[i] << endl;
        }
    }
    else {
        cout << "empty stack" << endl;
    }
}



// Default constructor
Expression::Expression()
    {
    type = illegal;
    valid = false;
    original = "";
    tokenized;
    postfix;
    prefix;
    
    }

// Copy constructor
Expression::Expression(const string& s)
    {
       set(s); 
    }

// Setter for all variables of type Expression
void Expression::set(const string& s)
    {  
    tokenized.clear();
      original = s;
      int iterator = 0;
      int afterSpace, delim;
      
      // loop to progress down the string and separate each token within it
      while (iterator < s.length())
        {
            // sets the temporary string tok_be_tok to empty and finds the first
            // non space as well as the first operator or space
            string to_be_tok = "";
            afterSpace = s.find_first_not_of(" ",iterator);
            delim = s.find_first_of("*;+-=()/% ",iterator);
          
            // this statement increments the loop by one if the first character
            // is a space or if there are only spaces left in the string
            if ((afterSpace-1) == iterator || (afterSpace == string::npos && iterator != s.length()))
                {
                    iterator++;
                } 
            // this statement checks to see if the location of the first 
            // operator is greater than the position the string is beginning at.
            // If this is true the string is tokenized for the difference 
            // between the two and the position in the string is increased by 
            // that amount.
            else if(delim > iterator)
                {
                    tokenized.push_back(Token(to_be_tok.assign(s, iterator, delim-iterator)));
                    iterator += (delim-iterator);
                }
            // if there are no operators or spaces left then the string is 
            // tokenized for the rest of its length and the position in the 
            // string is set to its length to break the loop
            else if(delim == string::npos)
                {
                    tokenized.push_back(Token(to_be_tok.assign(s, iterator, s.length())));
                    iterator = s.length();
                } 
            // if there is an operator at the position that the loop starts at 
            // then that operator is tokenized and the loop increments by 1
            else if (delim==iterator)
                {
                    tokenized.push_back(Token(to_be_tok.assign(s, iterator, 1)));
                    iterator++;
                }
        }
    }

// Displays the original expression as well as all of its tokens, and their 
// types and values using a loop and calling the token display function
void Expression::display(char disp) const
    {
    string temp;
    temp.assign(original, 0, original.length()-1);
    
    if(disp == '<')
    {
        int inc = 0;
            int pos = 0;
            cout << "Postfix of " << temp << " is : ";
            while(pos < postfix.size())
            {
                cout << postfix.at(pos).get_token() << " ";
                pos++;
            }
            cout << endl;
    }
    
//    int i = 0;    
//    
//    cout << "The original string is: " << original << endl << endl;
////    
////    while(i < tokenized.size())
////        {
////        tokenized.at(i).display();
////        cout << endl;
////        i++;
////        }    
    }
// possible mod awaiting email from matt about = sign=============================================================================
bool Expression::correct()
    {
    
    int i = 0; 
    int truth = 0;
    int parenth_C = 0;
    int parenth_O = 0;
    
    if(original[original.length()-1] != ';')
        return false;
    else if(original.length() < 4)
        return false;

    while(i < tokenized.size())
        {
        if(i == 0)
        {
            cout << "1";
            if(tokenized.at(i).get_type() == integer)
            {
                if(tokenized.at(i+1).get_type() != op && tokenized.at(i+1).get_type() != closebrace && tokenized.at(i+1).get_type() != last)
                    return false;
            }
            else if(tokenized.at(i).get_type() == letter)
            {
                if(tokenized.at(i+1).get_type() != op && tokenized.at(i+1).get_type() != closebrace && tokenized.at(i+1).get_type() != eq && tokenized.at(i+1).get_type() != last)
                    return false;
            }
            else if(tokenized.at(i).get_type() == openbrace)
            {
                parenth_O++;
                if(tokenized.at(i+1).get_type() != letter && tokenized.at(i+1).get_type() != integer && tokenized.at(i+1).get_type() != openbrace)
                    return false;
            }
            else
                return false;
        }
        
        else if(tokenized.at(i).get_type() == invalid)
        {
            cout << "2";
            tokenized.at(i).display();
            return false;
            //truth++;
        }
        else if(tokenized.at(i).get_type() == eq)
        {
            cout << "3";
            if(tokenized.at(i-1).get_type() != letter)
                return false;
            else if(tokenized.at(i+1).get_type() != integer)
                return false;
        }
        else if(tokenized.at(i).get_type() == integer)
        {
            cout << "4";
            if(tokenized.at(i-1).get_type() == letter || tokenized.at(i-1).get_type() == integer  || tokenized.at(i-1).get_type() == closebrace)
                return false;
            if(tokenized.at(i+1).get_type() != op && tokenized.at(i+1).get_type() != closebrace && tokenized.at(i+1).get_type() != last)
                return false;
        }
        else if(tokenized.at(i).get_type() == letter)
        {
            cout << "5";
            if(tokenized.at(i-1).get_type() == letter || tokenized.at(i-1).get_type() == closebrace || tokenized.at(i-1).get_type() == integer || tokenized.at(i-1).get_type() == eq)
                return false;
            else if(tokenized.at(i+1).get_type() != op && tokenized.at(i+1).get_type() != closebrace && tokenized.at(i+1).get_type() != eq && tokenized.at(i+1).get_type() != last)
                return false;
        }
        else if(tokenized.at(i).get_type() == closebrace)
        {
            cout << "6";
            parenth_C++;
            if(tokenized.at(i-1).get_type() != letter && tokenized.at(i-1).get_type() != integer && tokenized.at(i-1).get_type() != closebrace)
                return false;
            else if(tokenized.at(i+1).get_type() != op && tokenized.at(i+1).get_type() != closebrace && tokenized.at(i+1).get_type() != last)
                return false;
        }
        else if(tokenized.at(i).get_type() == openbrace)
        {
            cout << "7";
            parenth_O++;
            if(tokenized.at(i-1).get_type() == letter || tokenized.at(i-1).get_type() == closebrace || tokenized.at(i-1).get_type() == integer)
                return false;
            else if(tokenized.at(i+1).get_type() != letter && tokenized.at(i+1).get_type() != integer && tokenized.at(i+1).get_type() != openbrace)
                return false;
        }
        else if(tokenized.at(i).get_type() == op)
        {
            cout << "8";
            if(tokenized.at(i-1).get_type() != letter && tokenized.at(i-1).get_type() != integer && tokenized.at(i-1).get_type() != closebrace)
                return false;
            else if(tokenized.at(i+1).get_type() == eq || tokenized.at(i+1).get_type() == op || tokenized.at(i+1).get_type() == closebrace || tokenized.at(i+1).get_type() == last)
                return false;/*this is where it calls invalid*/
        }
        else if(tokenized.at(i).get_type() == last)
        {
            cout << "9";
            if(tokenized.at(i-1).get_type() == op || tokenized.at(i-1).get_type() == eq || tokenized.at(i-1).get_type() == openbrace)
                return false;
        }
        else if(parenth_O < parenth_C)
            return false;
        i++;
        }
    cout << "10";
    if(/*truth == 0 &&*/ parenth_C == parenth_O)
    {
        return true;
    }
    else 
        return false;
    }

// Getter for the original string
string Expression::get_original() const
    {
       return original;
    }

// Getter for the Tokenized expression stored within a vector
vector<Token> Expression::get_tokenized() const
    {
    return tokenized;
    }

// Getter for postfix
void Expression::get_postfix()
    {
    stack<Token> ops;
    int i = 0;
    while(i < tokenized.size())
        {
        if(tokenized.at(i).get_type() == letter || tokenized.at(i).get_type() == integer)
        {
            postfix.push_back(tokenized.at(i));
        }
        else if(tokenized.at(i).get_type() == last)
        {
            while(!ops.empty())
            {
                postfix.push_back(ops.top());
                ops.pop();
            }
        }
        if(tokenized.at(i).get_type() == openbrace)
        {
            ops.push(tokenized.at(i));
        }
        if(tokenized.at(i).get_type() == closebrace)
        {
            while(ops.top().get_type() != openbrace)
            {
                postfix.push_back(ops.top());
                ops.pop();
            }
            ops.pop();
        }
        else if((tokenized.at(i).get_priority() == 2 || tokenized.at(i).get_priority() == 3) && ops.empty())
        {
            ops.push(tokenized.at(i));
        }
        else if(tokenized.at(i).get_priority() == 2 && ops.top().get_priority() == 3)
        {
            ops.push(tokenized.at(i));
        }
        else if(tokenized.at(i).get_priority() == 2 && ops.top().get_priority() == 2)
        {
            while(ops.top().get_priority() == 2)
            {
                postfix.push_back(ops.top());
                ops.pop();
            }
            ops.push(tokenized.at(i));
        }
        else if(tokenized.at(i).get_priority() == 3 && ops.top().get_priority() == 2)
        {
            ops.push(tokenized.at(i));
        }
        else if(tokenized.at(i).get_priority() == 3 && ops.top().get_priority() == 3)
        {
            while(!ops.empty() || ops.top().get_type() != openbrace)
            {
                postfix.push_back(ops.top());
                ops.pop();
            }
            ops.push(tokenized.at(i));
        }
        i++;
    }
}


void Expression::get_prefix()
    {
    
    }


void Expression::parenth()
    {
    stack<string> pair;
    string right;
    string left;
    string temp;
    
    int i = 0;
    while(i < postfix.size())
        {
        if(postfix.at(i).get_type() == letter || postfix.at(i).get_type() == integer)
            {
            pair.push(postfix.at(i).get_token());
            }
        else if(postfix.at(i).get_type() == op)
            {
            if(pair.size() >= 2)
                {
                right = pair.top();
                pair.pop();
                left = pair.top();
                pair.pop();
                pair.push("("+left+postfix.at(i).get_token()+right+")");
                }
            
            else 
                cout << "The input expression is invalid!";
            }
        }
        parenthesized = pair.top();
    }
int Expression::solve()
    {
    int solved;
    return solved;
    }

// Getter for validity of the expression
bool Expression::get_valid() const
    {
    return valid;
    }

// Getter for the type of expression
exp_type Expression::get_type() const
    {
    return type;
    }
