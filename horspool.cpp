// horspool's algorithm for string matching
// input only alphabets

#include <iostream>
#include <string>

using namespace std;

class horspool {
private:
    string pat;
    string txt;
	static const int CHARS = 300; // 256 actually.
    int shiftTable[CHARS];
    void shift();
    int match();
public:
    void read();
    void write();
};

void horspool::read() {
    cout << "Enter the text: " << endl;
    getline(cin , txt);
    cout << "Enter the pattern to search:" << endl;
    getline(cin, pat);
}
void horspool::write() {
    int f = match();
    if(f == -1)
        cout << "Search string not found!" << endl;
    else
        cout << "Found at " << f << endl;
}

void horspool::shift() {
    for(int i = 0; i < CHARS; i++)
        shiftTable[i] = pat.size();
    for(int i = 0; i < pat.size()-1; i++)
        shiftTable[pat[i]] = pat.size()-1-i;
}

int horspool::match() {
    shift();
    int m = pat.size();
    int n = txt.size();
    int i = m-1;
    while(i <= n-1) {
        int k = 0;
        while(k <= m-1 && pat[m- 1 -k] == txt[i-k])
            k++;
        if(k == m)
            return i - m + 1;
        else
            i = i + shiftTable[txt[i]];
    }
    return -1;
}


int main(void) {
    horspool h = horspool();
    h.read();
    h.write();
    return 0;
}
