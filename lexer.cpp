#ifndef LEXER_CPP
#define LEXER_CPP

#include "includes.h"
using namespace std;

vector<Token> Lexer(string input){
	vector<Token> tokens;
	int size = input.length();
	char curr;

	for (int i = 0; i < size; ++i) {
		curr = input[i];
		if(isdigit(curr) || curr == '.'){
			string buffer;
			while(true){
				if(!isdigit(curr) && curr != '.') break;
				buffer.push_back(curr);
				++i;
				curr = input[i];
			}
			--i;
			tokens.push_back(Token(TT::NUMBER, buffer));
		}
		else if(curr == '+') tokens.push_back(Token(TT::PLUS, "+"));
		else if(curr == '-') tokens.push_back(Token(TT::MINUS, "-"));
		else if(curr == '*') tokens.push_back(Token(TT::STAR, "*"));
		else if(curr == '/') tokens.push_back(Token(TT::SLASH, "/"));
		else if(curr == '(') tokens.push_back(Token(TT::LPAREN, "("));
		else if(curr == ')') tokens.push_back(Token(TT::RPAREN, ")"));
		
	}

	return tokens;
}

#endif