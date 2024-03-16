/*
This program does the Ceaser Cipher Decryption.
It reads the input from the file "input.in" and then it calculates the frequency of each character. 
Then it calculates the chi-square distance and finds the minimum distance. 
Then it shifts the characters by the shift distance and prints the decoded message.

Feel free to make it better.
*/
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

// Function to read the input from the file
void read(char *raw)
{
    ifstream fin("input.in"); // We read from "input.in" file

    char c;

    int i = 0;
    while (fin.get(c))
    {
        if (c != '\n') // We ignore the newline character
            raw[i++] = c;
    }
    raw[i] = '\0';
    fin.close();
}

// Function to get the frequency of each character
void get_frequency(char *raw, int *freq)
{
    for (int i = 0; i < strlen(raw); i++)
    {
        // We don't need to worry about the uppser case characters as we are converting them to lower case
        raw[i] = tolower(raw[i]);
        if (raw[i] >= 'a' && raw[i] <= 'z')
        {
            freq[raw[i] - 'a']++;
        }
    }
}

// Function to calculate the sum of chi-square
int sum_chi_square(int *freq_encrypted, double *freq_english)
{
    int sum = 0;
    for (int i = 0; i < 26; i++)
    {
        // We are using the formula of chi-square
        sum += (freq_encrypted[i] - freq_english[i]) * (freq_encrypted[i] - freq_english[i]) / freq_english[i];
    }
    return sum;
}

// Function to shift the characters
void shift(char *raw, int shift)
{
    for (int i = 0; i < strlen(raw); i++)
    {
        if (raw[i] >= 'a' && raw[i] <= 'z')
        {
            raw[i] = (raw[i] - 'a' + shift) % 26 + 'a';
        }
        else if (raw[i] >= 'A' && raw[i] <= 'Z')
        {
            raw[i] = (raw[i] - 'A' + shift) % 26 + 'A';
        }
    }
}

// Function to find the minimum chi-square distance
int min_chi_square_distance(char *raw, double *englishFrequency)
{
    // We initialize the shift distance to 0
    int sh = 0;

    // We perform the shift operation and calculate the chi-square distance in order to have a minimum distance
    int freq[26] = {0};
    get_frequency(raw, freq);
    int min = sum_chi_square(freq, englishFrequency);
    // We shift the characters from 1 to 25, b -> z, because we already have done a shift of 0 above
    for (int i = 1; i < 26; i++)
    {
        // Each time we shift we need to bring the frequency to 0
        int freq[26] = {0};

        shift(raw, 1);
        get_frequency(raw, freq);
        int x = sum_chi_square(freq, englishFrequency);
        // We find the minimum chi-square distance
        if (x < min)
        {
            min = x;
            // We store the shift distance
            sh = i;
        }
    }
    return sh;
}

int main()
{
    // We store the text in the raw array
    char raw[1000];
    // We store the frequency of each character of the english language in the array a->z
    double englishFrequency[26] = {8.167, 1.492, 2.782, 4.253, 12.702, 2.228, 2.015,
                                   6.094, 6.966, 0.153, 0.772, 4.025, 2.406, 6.749,
                                   7.507, 1.929, 0.095, 5.987, 6.327, 9.056, 2.758,
                                   0.978, 2.360, 0.150, 1.974, 0.074};
    // We read the input from the file
    read(raw);

    // We make a copy of the raw array in order to use it in the min_chi_square_distance function
    // We do this because the shift function will change the raw array
    char raw_copy[1000];
    strcpy(raw_copy, raw);

    // We search for the shift distance in order to decode the message
    int shift_distance = min_chi_square_distance(raw_copy, englishFrequency);

    // We decode the message by shifting the characters
    shift(raw, shift_distance);
    cout << raw << endl;

    return 0;
}
