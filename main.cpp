#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;
  

int main() {
    int e;
    int n;

    unordered_map<int, char> alphabet;

    // A-Z
    alphabet[7] = 'A';
    alphabet[8] = 'B';
    alphabet[9] = 'C';
    alphabet[10] = 'D';
    alphabet[11] = 'E';
    alphabet[12] = 'F';
    alphabet[13] = 'G';
    alphabet[14] = 'H';
    alphabet[15] = 'I';
    alphabet[16] = 'J';
    alphabet[17] = 'K';
    alphabet[18] = 'L';
    alphabet[19] = 'M';
    alphabet[20] = 'N';
    alphabet[21] = 'O';
    alphabet[22] = 'P';
    alphabet[23] = 'Q';
    alphabet[24] = 'R';
    alphabet[25] = 'S';
    alphabet[26] = 'T';
    alphabet[27] = 'U';
    alphabet[28] = 'V';
    alphabet[29] = 'W';
    alphabet[30] = 'X';
    alphabet[31] = 'Y';
    alphabet[32] = 'Z';

    // Special Character
    alphabet[33] = ' ';  // blank
    alphabet[34] = '"';  // quotation marks
    alphabet[35] = ',';  // comma
    alphabet[36] = '.';  // period
    alphabet[37] = '\''; // apostrophe
    
    

    cout << "Enter e" << endl;
    cin >> e;
    cout << "Enter n" << endl;
    cin >> n;

    cout << e << ", " << n << endl;

    // find p and q 

    // find phi(n)
    // check if gcd(e, phi(n) == 1)
    // while loop to take in each crypted letter and decrypt

    // output final decrypted message
    return 0;
}
