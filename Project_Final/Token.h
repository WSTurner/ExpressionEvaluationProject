


/* 
 * File:   Token.h
 * Author: wsturner
 *
 * Created on December 2, 2013, 10:54 AM
 */

/* 
 * File:   Token.h
 * Author: wsturner
 *
 * Created on October 1, 2013, 1:04 PM
 */

#ifndef TOKEN_H
#define TOKEN_H
#include <iostream>
using namespace std;

enum token_type {letter, integer, op, eq, openbrace, closebrace, invalid, last};

class Token
{
private:
    // variables
    token_type type;
    string token;
    int priority;
    
public:
    // functions of the Token class
    Token();
    Token(string);
    void set(string);
    int value() const;
    void display() const;
    token_type get_type() const;
    string get_token() const;
    int get_priority() const;
    
};
#endif /* TOKEN_H */
