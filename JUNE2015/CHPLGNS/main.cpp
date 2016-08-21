#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Point {
	double x,y;
};

struct IdxArea {
	int idx;
	double area;
	bool operator<(const IdxArea& oth) const {
		return area < oth.area;
	}
};

int main() {
	#ifndef ONLINE_JUDGE
		ifstream cin("input");
	#endif

	int T;
	cin >> T;

	while(T--) {
		int no_poly;
		cin >> no_poly;

		vector<IdxArea> areas;
		for(int i = 0; i < no_poly; ++i) {
			int no_points;
			cin >> no_points;
			vector<Point> poly(no_points+1);
			for(int i = 0; i < no_points; ++i) {
				cin >> poly[i].x >> poly[i].y;
			}
			poly.back() = poly.front();

			double area = 0;
			for(int i = 0; i < no_points; ++i) {
				area += (poly[i].x * poly[i+1].y - poly[i+1].x * poly[i].y);
			}
			area = abs(area);
			areas.push_back({i,area});
		}
		sort(areas.begin(), areas.end());

		vector<int> result(no_poly);

		for(int i = 0; i < areas.size(); ++i) {
			result[areas[i].idx] = i;
		}
		for(int i = 0; i < no_poly; ++i) {
			cout << result[i] << ' ';
		}
		cout << '\n';
	}


	return 0;
}