#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

void read(char *raw)
{
    ifstream fin("input.in");

    char c;

    int i = 0;
    while (fin.get(c))
    {
        if (c != '\n')
            raw[i++] = c;
    }
    raw[i] = '\0';
    fin.close();
}

void get_frequency(char *raw, int *freq)
{
    for (int i = 0; i < strlen(raw); i++)
    {
        if (raw[i] >= 'a' && raw[i] <= 'z')
        {
            freq[raw[i] - 'a']++;
        }
    }
}

int sum_chi_square(int *freq_encrypted, double *freq_english)
{
    int sum = 0;
    for (int i = 0; i < 26; i++)
    {
        sum += (freq_encrypted[i] - freq_english[i]) * (freq_encrypted[i] - freq_english[i]) / freq_english[i];
    }
    return sum;
}

void shift(char *raw, int shift)
{
    for (int i = 0; i < strlen(raw); i++)# Cezar's cipher breaker in C++

This C++ program reads from a file and desiphers the Cezar's cipher using the Chi-Square method.

## Functions

### `void read(char *raw)`

This function reads from a file named "input.in" and stores the contents into the `raw` character array. It ignores newline characters (`'\n'`).

### `void get_frequency(char *raw, int *freq)`

This function determines the frequency of each characther in our array.

### `int sum_chi_square(int *freq_encrypted, double *freq_english)`

In this function:
 - we calculate the distance between the frequency of our letter in the encrypted text and the english frequency of the letter the formula used is `(frequency_encrypted - frequency_english)^2/frequency_english`
 - we add all the results to `sum` and we return it

### `void shift(char *raw, int shift)`

In this function we shift all the letters in the alphabet by `shift`  position.

### `int min_chi_square_distance(char *raw, double *englishFrequency)`

In this function we go through each possible shift of the letters and determine the minimum discprepancy between letters.

In the variable `sh` we store the desipher shift, and we return it.

### int main()

In the main fuction we have:
- `raw` in which we store the encrypted text. 
- `englishFrequency` in which we store the frequency of all the english letters
- `raw_copy` is a copy of the `raw` array. 

At the end we get the `shift_distance` from `min_chi_square_distance` function and we perform a `shift` by this distance in order to decipher the text.


## Usage

To use this program, you need to have a file named "input.in" in the same directory as the executable. The file should contain the text you want to analyze. The program will read the file, ignore newline characters, and calculate the frequency of each lowercase letter.


### An example

You can place "Uf ime ftq nqef ar fuyqe, uf ime ftq iadef ar fuyqe, uf ime ftq msq ar iuepay, uf ime ftq msq ar raaxuetzqee, uf ime ftq qbaot ar nqxuqr, uf ime ftq qbaot ar uzodqpgxufk, uf ime ftq eqmeaz ar xustf, uf ime ftq eqmeaz ar pmdwzqee, uf ime ftq ebduzs ar tabq, uf ime ftq iuzfqd ar pqebmud." in the "input.in" file.

The answer should be: "It was the best of times, it was the worst of times, it was the age of wisdom, it was the age of foolishness, it was the epoch of belief,it was the epoch of incredulity, it was the season of light, it was the season of darkness, it was the spring of hope, it was the winter of despair."


### Feel free to use the code and try to improve it


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

int min_chi_square_distance(char *raw, double *englishFrequency)
{
    int freq[26] = {0}, sh = 0;
    get_frequency(raw, freq);
    int min = sum_chi_square(freq, englishFrequency);
    for (int i = 1; i < 26; i++)
    {
        int freq[26] = {0};
        shift(raw, 1);
        get_frequency(raw, freq);
        int x = sum_chi_square(freq, englishFrequency);
        if (x < min)
        {
            min = x;
            sh = i;
        }
    }
    return sh;
}

int main()
{
    char raw[1000];
    double englishFrequency[26] = {8.167, 1.492, 2.782, 4.253, 12.702, 2.228, 2.015,
                                   6.094, 6.966, 0.153, 0.772, 4.025, 2.406, 6.749,
                                   7.507, 1.929, 0.095, 5.987, 6.327, 9.056, 2.758,
                                   0.978, 2.360, 0.150, 1.974, 0.074};
    read(raw);
    char raw_copy[1000];
    strcpy(raw_copy, raw);
    int shift_distance = min_chi_square_distance(raw_copy, englishFrequency);

    shift(raw, shift_distance);
    cout << raw << endl;

    return 0;
}
