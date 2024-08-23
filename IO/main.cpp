#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    string sentence;
    cout << "Enter a sentence: ";
    getline(cin, sentence);
    cout << "The sentence: " << sentence << endl;

    stringstream str(sentence);
    string buffer;
    while (str >> buffer)
    {
        cout << buffer << endl;

        // if word is a numeric value, print double the value
        if (isdigit(buffer[0]))
        {
            int num = stoi(buffer);
            cout << num * 2 << endl;
        }
    }

    return 0;
}