#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>
#include <cmath>
#include <nlohmann/json.hpp>

using namespace std;
using json = nlohmann::json;

typedef long long ll;

struct Point {
    ll x;
    __int128 y;
};

// Convert base-n string to decimal (__int128 for big numbers)
__int128 baseToDecimal(string val, int base) {
    __int128 result = 0;
    for (char ch : val) {
        int digit;
        if (isdigit(ch)) digit = ch - '0';
        else digit = ch - 'a' + 10;
        result = result * base + digit;
    }
    return result;
}

// Convert __int128 to string for output
string int128ToString(__int128 n) {
    if (n == 0) return "0";
    string result;
    while (n > 0) {
        result = char('0' + n % 10) + result;
        n /= 10;
    }
    return result;
}

// Lagrange interpolation to get f(0)
__int128 lagrangeInterpolation(vector<Point>& points) {
    __int128 secret = 0;
    int k = points.size();

    for (int i = 0; i < k; ++i) {
        __int128 xi = points[i].x;
        __int128 yi = points[i].y;

        __int128 num = 1, den = 1;

        for (int j = 0; j < k; ++j) {
            if (i == j) continue;
            __int128 xj = points[j].x;
            num *= -xj;
            den *= (xi - xj);
        }

        __int128 term = yi * num / den;
        secret += term;
    }

    return secret;
}

// Parse JSON and return decoded points
vector<Point> parseFile(const string& filename, int& k) {
    ifstream f(filename);
    json j;
    f >> j;

    k = j["keys"]["k"];
    j.erase("keys");

    vector<Point> points;
    for (auto& [key, val] : j.items()) {
        ll x = stoll(key);
        int base = stoi(val["base"].get<string>());
        string val_str = val["value"];
        __int128 y = baseToDecimal(val_str, base);
        points.push_back({x, y});
    }

    return points;
}

int main() {
    vector<string> files = {"testcase1.json", "testcase2.json"};
    for (const auto& file : files) {
        int k;
        vector<Point> points = parseFile(file, k);

        // Use only first k points
        vector<Point> subset(points.begin(), points.begin() + k);
        __int128 secret = lagrangeInterpolation(subset);
        cout << "Secret from " << file << ": " << int128ToString(secret) << endl;
    }

    return 0;
}