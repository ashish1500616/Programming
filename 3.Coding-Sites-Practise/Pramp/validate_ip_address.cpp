
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*

"123.5.2.1" true
 "4.3.333.1" false
  "3.4.5.opps" false
Validate an IP address (IPv4). An address is valid if and only if it is in the form "X.X.X.X", where each X is a number from 0 to 255.

For example, "12.34.5.6", "0.23.25.0", and "255.255.255.255" are valid IP addresses, while "12.34.56.oops", "1.2.3.4.5", and "123.235.153.425" are invalid IP addresses.

Examples:

ip = '192.168.0.1'
output: true

ip = '0.0.0.0'
output: true

ip = '123.24.59.99'
output: true

ip = '192.168.123.456'
output: false

*/

// Points To Check.
// No of Decimal Points .
// NO raange.
// No. Not starting with 0.
// No consecutive decimal Points..it must separate numbers.
// No alphabets in the string.

// My approach.
bool validateIP(const string &ip)
{
    vector<string> n(4, ""); // size of the string of the ip address.
    string w = "";
    int j = 0;
    int c = 0;
    for (int i = 0; ip[i] != '\0'; i++)
    {
        if (c > 3)
            return false;
        if (ip[i] == '.')
        {
            ++c;
            continue;
        }
        if (ip[i + 1] == '.')
        {
            n[j++] = (w + ip[i]);
            w = "";
        }
        else
        {
            if ((ip[i] - '0') >= 0 && (ip[i] - '0') <= 9)
                w += ip[i];
            else
                return false;
        }
    }
    if (c != 3)
        return false;
    n[j] = w;
    int val = -1;
    for (auto x : n)
    {
        try
        {
            if (x.size() > 1 && x[0] == '0')
                return false;
            val = stoi(x);
        }
        catch (...)
        {
            return false;
        }
        if (val < 0 || val > 255)
            return false;
    }
    return true;
}

// Better Approach
void tokenize(string ip, vector<string> &chunks)
{
    stringstream temp(ip);
    string tempVal;

    while (getline(temp, tempVal, '.'))
    {
        cout << "chunk: " << tempVal << endl;
        chunks.push_back(tempVal);
    }
}
http : //www.cplusplus.com/reference/string/string/getline/
       bool
       valid(string s)
{
    int n = s.size();
    if (n == 0)
        return false;
    int temp = 0;

    for (int i = 0; i < n; i++)
        temp = temp * 10 + (s[i] - '0');

    if (temp < 10 && n > 1)
        return false;
    else if (temp >= 0 && temp <= 255)
        return true;
    return false;
}

bool validate(const vector<string> chunks)
{
    if (chunks.size() < 4 || chunks.size() > 4)
        return false;

    for (auto val : chunks)
        if (!valid(val))
            return false;

    return true;
}

bool validateIP_best(const string &ip)
{
    vector<string> chunks;
    tokenize(ip, chunks);
    return validate(chunks);
}

int main()
{
    string ip = "5.5.05.0";
    cout << validateIP(ip);
    return 0;
}
