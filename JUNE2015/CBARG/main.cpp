#include <iostream>
#include <fstream>

using namespace std;

int main() {
	#ifndef ONLINE_JUDGE
		ifstream cin("input");
	#endif

	int T;
	cin >> T;

	while(T--) {
		int n;
		cin >> n;

		long long current_mem = 0, allocated_mem = 0;

		for(int i = 0; i < n; ++i) {
			int m;
			cin >> m;
			if(m > current_mem) {
				allocated_mem += m - current_mem;
				current_mem = m;
			}
			else {
				current_mem = m;
			}
		}

		cout << allocated_mem << '\n';
	}
}