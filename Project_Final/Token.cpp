#include "Token.h"

// Defualt constructor
Token::Token()
    {    
    type = invalid;
    token = "";
    priority = -1;   
    }

// Copy constructor
Token::Token(string s)
    {
    set(s);
    }

// Setter for all variables of type Token
void Token::set(string s)
    {
        // if the string is longer than 1 this checks to see if there are any 
        //non numbers in the string or if it begins with a 0 and sets the type 
        if(s.length() > 1)  
            { 
                int k = s.find_first_not_of("0123456789");
          
                if (k != string::npos || s[0] == '0')
                    {
                        type = invalid;
                    }
                else
                    {
                        type = integer;
                    }
                token = s;
            }
        // If the token has a length of 1 then this statement checks each of the
        // operators/symbols and then checks to see if there is a non integer or
        // a non letter determining its type by that lack of other symbols.     
        else if(s.length() == 1)
            {
                if(s == "*" || s == "+" || s == "-" || s == "/" || s == "%")
                    {
                        type = op;
                    }
                else if(s == "=")
                    {
                        type = eq;
                    }
                else if(s == "(")
                    {
                        type = openbrace;
                    }
                else if(s == ")")
                    {
                        type = closebrace;
                    }
                else if(s == ";")
                    {
                        type = last;
                    }
                else
                    {
                        int k = s.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
                        int l = s.find_first_not_of("0123456789");
                        
                        if (k == string::npos)
                            {
                                type = letter;
                            }
                        else if(l == string::npos)
                            {
                                type = integer;
                            }
                        else
                            {
                                type = invalid;
                            }
                    }
                token = s;
            }
        // this statement is activated by a string length 0 and sets the token
        // type to invalid
        else if (s.length() == 0)
            {
                type = invalid;
                token = "";
            }
        // the following if else statements assign a priority to the 
        // predetermined type of token
        if (type == integer || type == letter || type == invalid || type == eq || type == last)
            priority = -1;
        else if (type == openbrace || type == closebrace)
            priority = 1;
        else if (type == op)
            {
                if (s == "*" || s == "/" || s == "%")
                    priority = 2;
                else if (s == "+" || s == "-")
                    priority = 3;         
            }
    }

// Returns the numeric value of the Token if it is an integer or -1 if it is not
int Token::value() const
    {
    if (type == letter)
        return -1;
    else if (type != integer)
    {
        cout << "Invalid token type!" << endl;
        return -1;
    }
    else
    {
        int value = atoi(token.c_str());
        return value;
    }
    }

// Display function outputting the token, type, and priority
void Token::display() const
    {
    cout << token;
//    cout << "Token= " << token << endl;
//    cout << "Type= " << type << endl;
//    cout << "Priority= " << priority << endl;
    }

// getter for type
token_type Token::get_type() const
    {
    return type;
    }

// Getter for token
string Token::get_token() const
    {
    return token;
    }

// Getter for priority
int Token::get_priority() const
    {
    return priority;
    }

