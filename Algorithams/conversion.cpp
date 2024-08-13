#include <bits/stdc++.h>
#include <iostream>
#define lb "\n"

using namespace std;

class Conversion {
private:
  string hex_from_number(char c)
  {
    switch (c)
    {
    case 10:
      return "A";
    case 11:
      return "B";
    case 12:
      return "C";
    case 13:
      return "D";
    case 14:
      return "E";
    case 15:
      return "F";
    default:
      return to_string(c);
    }
  }

  int number_from_hex(char c)
  {
    switch (c)
    {
    case 'A':
      return 10;
    case 'B':
      return 11;
    case 'C':
      return 12;
    case 'D':
      return 13;
    case 'E':
      return 14;
    case 'F':
      return 15;
    default:
      return c - '0';
    }
  }

public:
  int binary_to_decimal(string binary_str)
  {
    int size = binary_str.length();
    int decimal = 0;

    for (int i = size - 1, multiplier = 1; i >= 0; --i, multiplier *= 2)
    {
      decimal += (binary_str[i] - '0') * multiplier;
    }

    return decimal;
  }

  int octal_to_decimal(int octal)
  {
    int decimal = 0, multiplier = 1;

    while (octal > 0)
    {
      decimal += (octal % 10) * multiplier;
      octal /= 10;

      multiplier *= 8;
    }

    return decimal;
  }

  int decimal_to_octal(int decimal)
  {
    string octal = "";

    while (decimal > 0)
    {
      octal.append(to_string(decimal % 8));
      decimal /= 8;
    }

    reverse_str(octal);
    return stoi(octal);
  }

  int hexadecimal_to_decimal(string hexadecimal)
  {
    int size = hexadecimal.length();
    int decimal = 0;

    for (int i = size - 1, multiplier = 1; i >= 0; --i, multiplier *= 16)
    {
      decimal += number_from_hex(hexadecimal[i]) * multiplier;
    }

    return decimal;
  }

  string decimal_to_hexadecimal(int decimal)
  {
    string hexadecimal = "";

    while (decimal > 0)
    {
      int remainder = decimal % 16;
      hexadecimal.append(hex_from_number(remainder));
      decimal /= 16;
    }

    reverse_str(hexadecimal);
    return hexadecimal;
  }

  string decimal_to_binary(int decimal)
  {
    string binary = "";
    while (decimal != 0)
    {
      binary.append(to_string(decimal % 2));
      decimal /= 2;
    }

    reverse_str(binary);
    return binary;
  }
}