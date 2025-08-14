/*
   We can use bitwise operators the manipulate the bits of data types. Here some
   examples:

   Jose Antonio Abreu Alvarez
*/

#include <bitset>
#include <iostream>

using std::bitset;
using std::cout;

int main() {
    unsigned int x = 0x0001;

    cout << "Shift operations\n";
    cout << bitset<16>(x) << '\n';
    x <<= 4;  // Shift bits 4 times to the left
    cout << bitset<16>(x) << '\n';
    x >>= 4;  // Shift bits 4 times to the right
    cout << bitset<16>(x) << '\n';
    // Also we can perform fast mult and div by 2 with shift operations

    cout << "\n\n";

    cout << "Logical operations\n";
    x = 0x0F0F;

    cout << "And\n";
    cout << bitset<16>(x) << '\n';
    cout << bitset<16>(x << 2) << '\n';
    cout << bitset<16>(x & (x << 2)) << "\n\n";

    cout << "Or\n";
    cout << bitset<16>(x) << '\n';
    cout << bitset<16>(x << 2) << '\n';
    cout << bitset<16>(x | (x << 2)) << "\n\n";

    cout << "Xor\n";
    cout << bitset<16>(x) << '\n';
    cout << bitset<16>(x << 2) << '\n';
    cout << bitset<16>(x ^ (x << 2)) << "\n\n";
    // One cool property of xor is that b ^ a ^ a = a ^ b ^ a = a ^ a ^ b = b

    cout << "Not\n";
    cout << bitset<16>(x) << '\n';
    cout << bitset<16>(~x) << "\n\n";

    cout << "\n\n";

    // Now a aplication of some of this operations to get the hamming weight of
    // a 16 bit integer
    cout << "Hamming weight\n";
    cout << bitset<16>(x) << '\n';
    x = (x & 0x5555) + ((x >> 1) & 0x5555);
    x = (x & 0x3333) + ((x >> 2) & 0x3333);
    x = (x & 0x0F0F) + ((x >> 4) & 0x0F0F);
    x = (x & 0x00FF) + ((x >> 8) & 0x00FF);
    cout << x << '\n';

    return 0;
}
