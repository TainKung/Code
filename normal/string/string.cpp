#include <iostream>
#include <string>
using namespace std;

int main() {
    string s1, s2;
    cin.sync_with_stdio(false);
    // cin >> s1 >> s2;
    getline(cin, s1);
    getline(cin, s2);
    cout << s1.find(s2) << endl;
    return 0;
}
