#ifndef PARSER_CPP
#define PARSER_CPP

#include "includes.h"
using namespace std;

vector<Token> tokens;
int pos;

double parse(vector<Token> ts){
	tokens.clear();
	tokens = ts;
	pos = 0;
	return expression();
}

double expression(){
	return additive();
}

double additive(){
	double result = multiplicative();
	while(true){
		if(tokens[pos].get_t() == TT::PLUS) { ++pos; result += multiplicative(); continue; }
		if(tokens[pos].get_t() == TT::MINUS) { ++pos; result -= multiplicative(); continue; }
		break;
	}
	return result;
}

double multiplicative(){
	double result = unary();
	while(true){
		if(tokens[pos].get_t() == TT::STAR) { ++pos; result *= unary(); continue; }
		if(tokens[pos].get_t() == TT::SLASH) { ++pos; result /= unary(); continue; }
		break;
	}
	return result;
}

double unary(){
	if(tokens[pos].get_t() == TT::MINUS){
		++pos;
		return -1 * primary();
	}
	return primary();
}

double primary(){

	if(tokens[pos].get_t() == TT::NUMBER){
		double num = stod(tokens[pos].get_s());
		++pos;
		return num;
	}

	if(tokens[pos].get_t() == TT::LPAREN){
		++pos;
		double expr = expression();
		if(tokens[pos].get_t() != TT::RPAREN){
			cout << "Was expected ')'" << endl; exit(1);
		}
		++pos;
		return expr;
	}

	cout << "Error :)" << endl; exit(1);
}

#endif