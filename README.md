# Cezar's cipher breaker in C++

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


## An example

You can place "Uf ime ftq nqef ar fuyqe, uf ime ftq iadef ar fuyqe, uf ime ftq msq ar iuepay, uf ime ftq msq ar raaxuetzqee, uf ime ftq qbaot ar nqxuqr, uf ime ftq qbaot ar uzodqpgxufk, uf ime ftq eqmeaz ar xustf, uf ime ftq eqmeaz ar pmdwzqee, uf ime ftq ebduzs ar tabq, uf ime ftq iuzfqd ar pqebmud." in the "input.in" file.

The answer should be: "It was the best of times, it was the worst of times, it was the age of wisdom, it was the age of foolishness, it was the epoch of belief,it was the epoch of incredulity, it was the season of light, it was the season of darkness, it was the spring of hope, it was the winter of despair."

##
### Feel free to use the code and try to improve it

