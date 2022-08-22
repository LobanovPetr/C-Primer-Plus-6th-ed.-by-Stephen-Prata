#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <string>

using namespace std;

int main()
{
    cout << "Enter Mat friends (\"q\" to stop)\n";
    vector<string> MatFr;
    string s;
    while (cin >> s, s != "q")
        MatFr.push_back(std::move(s));
    sort(MatFr.begin(), MatFr.end());
    cout << "Mat friends:\n";
    copy(MatFr.begin(), MatFr.end(), ostream_iterator<string, char>(cout, " "));
    cout << endl;
    cout << "Enter Pat friends (\"q\" to stop)\n";
    vector<string> PatFr;
    while(cin >> s, s != "q")
        PatFr.push_back(std::move(s));
    sort(PatFr.begin(), PatFr.end());
    cout << "Pat friends:\n";
    copy(PatFr.begin(), PatFr.end(), ostream_iterator<string, char>(cout, " "));
    cout << endl;
    vector<string> result;

    merge(MatFr.begin(), MatFr.end(), PatFr.begin(), PatFr.end(), back_insert_iterator<vector<string>>(result));

    unique(result.begin(), result.end());

    cout << "Result list of friends\n";
    copy(result.begin(), result.end(), ostream_iterator<string, char>(cout, " "));
    cout << endl;
    
    return 0;
}
