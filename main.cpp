#include <iostream>
#include <cassert>
using namespace std;
char nibble_to_hex (uint8_t i)
{
    assert(0x0 <= i && i <= 0xf);
    char digits[] = "0123456789abcdef";
    return digits[i];
}
void print_in_hex (uint8_t byte)
{
    cout << nibble_to_hex(byte >> 4)
            << nibble_to_hex(byte & 0xf);
}
const uint8_t* as_bytes(const void* data)
{
    return reinterpret_cast<const uint8_t*>(data);
}
void print_in_hex(const void* data, size_t size) {
    const uint8_t* bytes = as_bytes(data);
    for (size_t i = 0; i < size; i++) {
        print_in_hex(bytes[i]);
        if ((i + 1) % 16 == 0) {
            cout << '\n';
        }
        else {
            cout << ' ';
        }
    }
}
char bit_digit(uint8_t byte, uint8_t bit) {
    if (byte & (0x1 << bit)) {
        return '1';
    }
    return '0';
}
void print_in_binary(uint8_t byte) {
    for (uint8_t bit = 7; bit > 0; bit--) {
        cout << bit_digit(byte, bit);
    }
    cout << bit_digit(byte, 0);
}
void print_in_binary(const void* data, size_t size) {
    const uint8_t* bytes = as_bytes(data);
    for (size_t i = 0; i < size; i++) {
        print_in_binary(bytes[i]);
        if ((i + 1) % 4 == 0) {
            cout << '\n';
        }
        else {
            cout << ' ';
        }
    }
}
struct Student {
    char name[17];
    uint32_t year;
    float sred_ball;
    int sex:1;
    uint8_t courses;
    Student*starosta;
};
int main(){
    assert(nibble_to_hex(0x0) == '0');
    assert(nibble_to_hex(0x1) == '1');
    assert(nibble_to_hex(0x2) == '2');
    assert(nibble_to_hex(0x3) == '3');
    assert(nibble_to_hex(0x4) == '4');
    assert(nibble_to_hex(0x5) == '5');
    assert(nibble_to_hex(0x6) == '6');
    assert(nibble_to_hex(0x7) == '7');
    assert(nibble_to_hex(0x8) == '8');
    assert(nibble_to_hex(0x9) == '9');
    assert(nibble_to_hex(0xa) == 'a');
    assert(nibble_to_hex(0xb) == 'b');
    assert(nibble_to_hex(0xc) == 'c');
    assert(nibble_to_hex(0xd) == 'd');
    assert(nibble_to_hex(0xe) == 'e');
    assert(nibble_to_hex(0xf) == 'f');
    Student studarray[3]={
            {"anya", 2017, 4.3, 0, 7, &studarray[1]},
            {"sasha", 2017, 4.0, 1, 7, nullptr },
            {"Alik", 2017, 3.4, 1, 7, &studarray[1]}
    };
    cout<<"Address of array: "<< &studarray<<'\n';
    cout<<"Size of array: "<< sizeof(studarray)<<'\n';
    cout<<"\t Address of elem:\t Size of elem:\n";
    for (int i=0; i<3; i++){
        cout<<i<<":\t   "<<&studarray[i]<<"\t\t      "<< sizeof(studarray[i])<<'\n';
    }
    return 0;
}


