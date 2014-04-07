#include <iostream>

using namespace std;

bool isPrime(unsigned nr) {
	if(nr == 1 && nr == 2) return true;
	if(nr % 2 == 0)return false;
	for(size_t d = 3; d < nr/2; d+=2) {
		if(nr%d == 0) return false;
	}
	return true;
}

unsigned nextPrime(unsigned st) {
	while(!isPrime(st))st++;
	return st;
}

int main() {
	size_t t;
	cin >> t;
	while(t--) {
		unsigned a,b;
		cin >> a >> b;
		cout << nextPrime(a+b+1)-(a+b) << '\n';
	}
}
