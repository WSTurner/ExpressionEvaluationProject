/* 
 * File:   Expression.h
 * Author: wsturner
 *
 * Created on December 2, 2013, 10:54 AM
 */

/* 
 * File:   Expression.h
 * Author: wsturner
 *
 * Created on October 1, 2013, 2:41 PM
 */

#ifndef EXPRESSION_H
#define EXPRESSION_H
#include <vector>
#include "Token.h"

enum exp_type {assignment, arithmetic, illegal};

class Expression
{
private:
    // variables
    exp_type type;
    string original;
    vector<Token> tokenized;
    vector<Token> postfix;
    vector<Token> prefix;
    string parenthesized;
    bool valid;
    
    
public:
    // functions of the Expression class
    Expression();
    Expression(const string& s);
    void set(const string& s);
    void display(char) const;
    bool correct();
    string get_original() const;
    vector<Token> get_tokenized() const;
    void get_postfix();
    void get_prefix() ;
    void parenth() ;
    int solve() ;
    bool get_valid() const;
    exp_type get_type() const;
    
};

#endif /* EXPRESSION_H */