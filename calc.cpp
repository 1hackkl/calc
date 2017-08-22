#include "includes.h"
using namespace std;

int main(int argc, char const *argv[]) {
	
	string input;

	getline(cin, input);
	cout << parse(Lexer(input)) << endl;

	return 0;
}