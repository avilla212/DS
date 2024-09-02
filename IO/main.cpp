// #include <string>
// #include <iostream>
// #include <sstream>

// using namespace std;

// int main(void){
    
//     string sentence;
//     string word;

//     cout << "Enter a sentence: ";
//     getline (cin, sentence);
    
//     stringstream stream;
//     // here we are using the stringstream object to read from the string
//     stream.str(sentence);

//     while (stream >> word){
//         // we can also use istringstream to read from the string
//         istringstream iss(word);
//         double number;

//         // if the word is a number, we can convert it to a number
//         if (iss >> number){
//             cout << number * 2 << endl;
//         } else {
//             cout << word << endl;
//         }
//     }

//     return 0;
// }

#include <string>
#include <iostream>
#include <sstream>

using namespace std;

int main(void){

    string sentence;
    string word;
    stringstream stream;

    cout << "Enter a sentence: ";
    getline(cin, sentence);


    return 0;
}