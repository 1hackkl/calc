#ifndef INCLUDES_H
#define INCLUDES_H

#include <iostream>
#include <string>
#include <vector>

// the types of tokens
typedef enum {

	NUMBER,
	PLUS, MINUS, STAR, SLASH,
	LPAREN, RPAREN

} TT;

class Token {
private:
	TT type;
	std::string val;
public:
	Token();
	Token(TT, std::string);

	TT get_t();
	std::string get_s();

	~Token();
};

std::vector<Token> Lexer(std::string input);

double parse(std::vector<Token>);
double expression();
double additive();
double multiplicative();
double unary();
double primary();

#endif