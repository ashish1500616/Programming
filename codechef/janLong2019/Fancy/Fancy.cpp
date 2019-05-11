#include <bits/stdc++.h>

using namespace std;

#define get(x) cin>>x
#define w(x) while(x--)
#define put(x) cout<<x

#define rep(i, begin, end)                                                     \
  for (__typeof(end) i = (begin) - ((begin) > (end));                          \
       i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

void fast() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}

int main() {
	fast();
	int t=0;
	get(t);
    cin.ignore();
	while(t--)
	{
		bool f=false;
		string s;
		getline(cin,s);
		string word="";
		istringstream ss(s);
    do {
        string word;
        ss >> word;
        if(word == "not")
        {
            f=true;
        }
    } while (ss);
    if(f)
    put("Real Fancy\n");
    else
    put("regularly fancy\n");
  }
  return 0;
}
