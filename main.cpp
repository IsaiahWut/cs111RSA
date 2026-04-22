#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <cmath>

using namespace std;
  
// gcd function check
long long gcd(long long a, long long b) {
    // recursively check for the GCD
    if(b == 0){ 
        return a;
    }
    return gcd(b, a % b);
}

// squaring the exponent method to solve
long long decrypt(long long d, long long n, long long c){
    long long answer = 1; // initialize answer as 1
    while(d > 0){ // while exponent d is still not 1 essentially, keep looping and breaking it down
        if(d % 2 == 1){ // odd exponent which means factor out
            answer = answer * c % n; // we do the REM multiplcation already instead of doing it later
        }
        c = c * c % n; // square the base aka c
        d= d/2; // half the exponent to further the algorithm
    }
    return answer;
}   

int main() {
    long long e;
    long long n;

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
    
    
    // what is e
    // what is n
    cin >> e;
    cin >> n;

    long long p = 0;
    long long q = 0;

    // find p and q - only find up to sqrt(n)
    long long sqrt_n = sqrt(n);

    // loop from i to sqrt(n) to find the prime numbers of n
    for(int i = 2; i <= sqrt_n; i++){
        if(n % i == 0){ // if n is divisible by i, then that means we have found one prime
            p = i;
            break;
        }
    }
    if (p == 0){
        cout << "Public key is not valid!" << endl;
        return 0; // if p never found, break
    }
    // to find q, we can divide n/p to find q
    q = n/p;

    if (p == q){
        cout << "Public key is not valid!" << endl;
        return 0; // if p and q are same, break (from lecture)
    } 
    // find phi(n)
    long long phi = (p - 1) * (q - 1);
    
    // check if gcd(e, phi(n) == 1)
    long long gcdCheck = gcd(e, phi);
    
    if(gcdCheck != 1){ // if gcd is not 1, then we cannot find d which throws off our calculations
        // we end up in a circle as per the discussion
        cout << "Public key is not valid!" << endl;
        return 0;
    }


    long long d = 0;
    // while loop to take in each crypted letter and decrypt
    // compute decryption exponent d = e^{-1}(mod phi)) 
    // create a while loop. loop until d is a whole number
    // d = (phi(n)* x + 1)/e) 
    // if (phi(n) * x + 1) % 7 == 0), then d is found, d is this value. 
    // basically if caluclated number is a whole number, then that means d is found, if has remainder, or decimals, then we need to keep searching.
    // try this for all x.
    long long x = 1;
    d = (phi * x + 1) % e;

    while(d != 0){
      x++;
      d = (phi * x + 1) % e;
    }

    // now that we found what x is, we can solve for what d is
    d = (phi * x + 1)/e;


    // the long integers that is Alice's message
    int message; 
    // how long is your message
    cin >> message; 
    // record each message to the vector
    vector< long long> MessageIntegers(message);
    for(int i = 0; i < message; i++){
        cin >> MessageIntegers[i];
    }
    
    // output final decrypted message
    // decrpy the message = M = C^d rem n.
    // code out squaring method
    // add the input strings to the vector
    // c is the input message recorded
    // d is what we calculated
    // n is the n we were given
    vector<long long> decodedMessageIntegers(message);
    for(int i = 0; i < message; i++){
        long long c = MessageIntegers[i];
        decodedMessageIntegers[i] = decrypt(d, n, c);
    }
    
    //
    vector<char> decodedCharacters(message);
    for(int i = 0; i < message; i++){
        decodedCharacters[i] = alphabet[decodedMessageIntegers[i]]; 
        // use alphabet mapping from earlier to map the alphabet A= 7, Z = 32
    }

    // output p q phi and d
    cout << p << " " << q << " " << phi << " " << d << endl;
    // output the message INTEGER vector from the mapped alphabet vector we create
    for(int i = 0; i < message; i++){
        cout << decodedMessageIntegers[i];
        if( i < message - 1){
            cout << " ";
        }
    }
    cout << endl;

    // cout the actual message itself 
    for(int i = 0; i < message; i++){
        cout << decodedCharacters[i];
    }
    cout << endl;
    return 0;
}
