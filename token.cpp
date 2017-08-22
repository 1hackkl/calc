#ifndef TOKEN_CPP
#define TOKEN_CPP

#include "includes.h"

Token::Token(){}
Token::Token(TT t, std::string v):type(std::move(t)), val(std::move(v)) {}

TT Token::get_t(){
	return this->type;
}
std::string Token::get_s(){
	return this->val;
}

Token::~Token(){}

#endif