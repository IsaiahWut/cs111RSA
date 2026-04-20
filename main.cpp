#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <cmath>

using namespace std;
  
// gcd function check
int gcd(int a, int b) {
    
}

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
    
    
    cout << "Enter e" << endl; //
    cin >> e;
    cout << "Enter n" << endl; //
    cin >> n;

    cout << e << ", " << n << endl;
    int p = 0;
    int q = 0;

    string decodedMessageIntegers;
    string decodedMessageCharacters;

    // find p and q - only find up to sqrt(n)
    int sqrt_n = sqrt(n);

    // loop from i to sqrt(n) to find the prime numbers of n
    for(int i = 3; i <= sqrt_n; i++){
        if(n % i == 0){ // if n is divisible by i, then that means we have found one prime
            p = i;
            break;
        }
    }
    // to find q, we can divide n/p to find q
    q = n/p;

    // find phi(n)
    int phi = (p - 1) * (q - 1);
    
    bool dFlag = false;
    // check if gcd(e, phi(n) == 1)
    int gcdCheck = gcd(e, phi);
    
    if(gcdCheck == 1){
        dFlag = true;
    }
    else{
        cout << "GCD is not found." << endl;
    }


    int d = 0;
    // while loop to take in each crypted letter and decrypt
    // compute decryption exponent d = e^{-1}(mod phi)) 
    


    // output final decrypted message
    // decrpy the message = M = C^d rem n.


    cout << p << ", " << q << ", " << phi << d << endl;
    cout << decodedMessageIntegers << endl;
    cout << decodedMessageCharacters << endl;
    return 0;
}
