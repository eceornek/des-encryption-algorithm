#include <stdio.h>
#include <math.h>
#include <string.h>

#define INPUT_LENGTH 64
#define ROUND_NUMBER 16
#define MAX_INPUT_LENGTH 100

int S1[] = {14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7,
            0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8,
            4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0,
            15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13};

int S2[] = {15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10,
            3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5,
            0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15,
            13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9};

int S3[] = {10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8,
            13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1,
            13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7,
            1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12};

int S4[] = {7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15,
            13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9,
            10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4,
            3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14};

int S5[] = {2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9,
            14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6,
            4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14,
            11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3};

int S6[] = {12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11,
            10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8,
            9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6,
            4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13};

int S7[] = {4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1,
            13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6,
            1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2,
            6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12};

int S8[] = {13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7,
            1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2,
            7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8,
            2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11};

int initialPermutationTable[64] = {58, 50, 42, 34, 26, 18, 10, 2, 60, 52, 44,
                                   36, 28, 20, 12, 4, 62, 54, 46, 38, 30, 22,
                                   14, 6, 64, 56, 48, 40, 32, 24, 16, 8, 57,
                                   49, 41, 33, 25, 17, 9, 1, 59, 51, 43, 35,
                                   27, 19, 11, 3, 61, 53, 45, 37, 29, 21, 13,
                                   5, 63, 55, 47, 39, 31, 23, 15, 7};

int finalPermutationTable[64] = {40, 8, 48, 16, 56, 24, 64, 32, 39, 7, 47,
                                 15, 55, 23, 63, 31, 38, 6, 46, 14, 54, 22,
                                 62, 30, 37, 5, 45, 13, 53, 21, 61, 29, 36,
                                 4, 44, 12, 52, 20, 60, 28, 35, 3, 43, 11,
                                 51, 19, 59, 27, 34, 2, 42, 10, 50, 18, 58,
                                 26, 33, 1, 41, 9, 49, 17, 57, 25};

int keyPermutationTable[48] = {14, 17, 11, 24, 1, 5, 3, 28, 15, 6, 21, 10,
                               23, 19, 12, 4, 26, 8, 16, 7, 27, 20, 13, 2,
                               41, 52, 31, 37, 47, 55, 30, 40, 51, 45, 33, 48,
                               44, 49, 39, 56, 34, 53, 46, 42, 50, 36, 29, 32};

int DboxTable[48] = {32, 1, 2, 3, 4, 5, 4, 5,
                     6, 7, 8, 9, 8, 9, 10, 11,
                     12, 13, 12, 13, 14, 15, 16, 17,
                     16, 17, 18, 19, 20, 21, 20, 21,
                     22, 23, 24, 25, 24, 25, 26, 27,
                     28, 29, 28, 29, 30, 31, 32, 1};

int parityBitDropTable[56] = {57, 49, 41, 33, 25, 17, 9,
                              1, 58, 50, 42, 34, 26, 18,
                              10, 2, 59, 51, 43, 35, 27,
                              19, 11, 3, 60, 52, 44, 36,
                              63, 55, 47, 39, 31, 23, 15,
                              7, 62, 54, 46, 38, 30, 22,
                              14, 6, 61, 53, 45, 37, 29,
                              21, 13, 5, 28, 20, 12, 4};

int shiftTable[16] = {1, 1, 2, 2,
                      2, 2, 2, 2,
                      1, 2, 2, 2,
                      2, 2, 2, 1};

char hexadecimalNotation[16][5] = {
    "0000",
    "0001",
    "0010",
    "0011",
    "0100",
    "0101",
    "0110",
    "0111",
    "1000",
    "1001",
    "1010",
    "1011",
    "1100",
    "1101",
    "1110",
    "1111"};

// done
void string2hex(char *plainText, char *hexPlainText) // convert input string to hexadecimal
{
    int loop;
    int i;
    i = 0;
    loop = 0;

    while (plainText[loop] != '\0')
    {
        sprintf((char *)(hexPlainText + i), "%02X", plainText[loop]);
        loop += 1;
        i += 2;
    }
    // insert NULL at the end of the output string
    hexPlainText[i++] = '\0';
}
// done

// done
void paddingToHexString(char *hexPlainText)
{
    int hexLength = strlen(hexPlainText);
    int padSize = (16 - (hexLength % 16)); // 8 hexadecimal

    if (padSize == 0)
    {
        padSize = 16;
    }
    hexPlainText[hexLength] = '8';
    int i = 1;
    while (i < padSize)
    {
        hexPlainText[hexLength + i] = '0';
        i += 1;
    }
    hexPlainText[hexLength + i] = '\0';
}
// done

// done
void binary2hex(char *binaryText, char *hexText)
{
    int binaryLength = strlen(binaryText);
    char *p = hexText;
    int len = binaryLength / 4;
    char temp[4];

    int i = 0;
    while (i < len)
    {
        int hexnum = 0;
        strncpy(temp, binaryText + (i * 4), 4);
        int j = 0;
        while (j < 4)
        {
            hexnum += (temp[j] - '0') << (3 - j);
            j += 1;
        }
        sprintf(hexText + i, "%X", hexnum);
        i += 1;
    }
}
// done

int binary2dec(char *binaryText)
{
    int multiplier = 0;
    int i;
    int sum = 0;
    int length = strlen(binaryText);
    for (i = length - 1; i >= 0; i--)
    {
        if (binaryText[i] == '1')
        {
            sum += (1 << multiplier);
        }
        multiplier++;
    }
    return sum;
}

void combineStrings(char *left, char *right, char *result)
{
    // int length = 56;
    // int i=0;
    // while (i<length){
    //     int k = 0;
    //     int j = 0;
    //     while (k<28){
    //         result[i] = left[k];
    //         k++;
    //     }
    //     while (j<28){
    //         result[i] = right[j];
    //         j++;
    //     }
    //     i++;
    // }
    // result[length] = '\0';
    // printf("burası %s\n", result);
    strcpy(result, left);
    strcat(result, right);
}

void swapStrings(char *left, char *right)
{
    char temp[32];
    strcpy(temp, left);
    strcpy(left, right);
    strcpy(right, temp);
}

void splitString(char *input, char *LPT, char *RPT)
{
    int length = strlen(input);
    int mid = length / 2;
    int i;
    for (i = 0; i < mid; i++)
    {
        LPT[i] = input[i];
    }
    LPT[i] = '\0';
    int k=0;
    for (i = mid, k = 0; i < length; i++, k++)
    {
        RPT[k] = input[i];
    }
    RPT[k] = '\0';
}

// done
void hex2binary(char *hexText, char *binaryText)
{
    int hexLength = strlen(hexText);
    char *p = binaryText;

    int i = 0;
    while (i < hexLength)
    {
        switch (hexText[i])
        {
        case '0':
            strcpy(p, "0000");
            break;
        case '1':
            strcpy(p, "0001");
            break;
        case '2':
            strcpy(p, "0010");
            break;
        case '3':
            strcpy(p, "0011");
            break;
        case '4':
            strcpy(p, "0100");
            break;
        case '5':
            strcpy(p, "0101");
            break;
        case '6':
            strcpy(p, "0110");
            break;
        case '7':
            strcpy(p, "0111");
            break;
        case '8':
            strcpy(p, "1000");
            break;
        case '9':
            strcpy(p, "1001");
            break;
        case 'A':
            strcpy(p, "1010");
            break;
        case 'a':
            strcpy(p, "1010");
            break;
        case 'B':
            strcpy(p, "1011");
            break;
        case 'b':
            strcpy(p, "1011");
            break;
        case 'C':
            strcpy(p, "1100");
            break;
        case 'c':
            strcpy(p, "1100");
            break;
        case 'D':
            strcpy(p, "1101");
            break;
        case 'd':
            strcpy(p, "1101");
            break;
        case 'E':
            strcpy(p, "1110");
            break;
        case 'e':
            strcpy(p, "1110");
            break;
        case 'F':
            strcpy(p, "1111");
            break;
        case 'f':
            strcpy(p, "1110");
            break;
        default:
            break;
        }
        i += 1;
        p += 4;
    }
    strcpy(p, "\0");
}
// done

// done
void permutation(int *permutationTable, char *input, int inputLength, char *output)
{
    for (int i = 0; i < inputLength; i++)
    {
        output[i] = input[permutationTable[i] - 1];
    }
    output[inputLength] = '\0';
}
// done

// done
void XOR(char *left, char *right, char *output)
{
    int len = strlen(left);
    int i = 0;
    while (i < len)
    {
        if (left[i] == right[i])
        {
            output[i] = '0';
        }
        else
        {
            output[i] = '1';
        }
        i += 1;
    }
    output[32] = '\0';
}
// done

// done
void rotateKey(char *key, int nShift)
{
    int length = strlen(key);
    int i = 0;
    while (i < nShift)
    {
        int k = 0;
        char first = key[0];
        while (k < length - 1)
        {
            key[k] = key[k + 1];
            k += 1;
        }
        key[length - 1] = first;
        i += 1;
    }
}
// done

void sBox(char *xorResult, char *Sbox_output)
{
    int i = 0;
    char temp[5];
    temp[4] = '\0';
    // while (i < 8)
    // {
    //     if (xorResult[i * 6] == '0' && xorResult[i * 6 + 5] == '0')
    //     {
    //         strncpy(temp, xorResult + i * 6 + 1, 4);
    //         strncpy(Sbox_output + i * 4, convertToBin[sboxes[i][0 + strtol(temp, NULL, 2)]], 4);
    //     }
    //     else if (xorResult[i * 6] == '0' && xorResult[i * 6 + 5] == '1')
    //     {
    //         strncpy(temp, xorResult + i * 6 + 1, 4);
    //         strncpy(Sbox_output + i * 4, convertToBin[sboxes[i][16 + strtol(temp, NULL, 2)]], 4);
    //     }
    //     else if (xorResult[i * 6] == '1' && xorResult[i * 6 + 5] == '0')
    //     {
    //         strncpy(temp, xorResult + i * 6 + 1, 4);
    //         strncpy(Sbox_output + i * 4, convertToBin[sboxes[i][32 + strtol(temp, NULL, 2)]], 4);
    //     }
    //     else if (xorResult[i * 6] == '1' && xorResult[i * 6 + 5] == '1')
    //     {
    //         strncpy(temp, xorResult + i * 6 + 1, 4);
    //         strncpy(Sbox_output + i * 4, convertToBin[sboxes[i][48 + strtol(temp, NULL, 2)]], 4);
    //     }
    //     j++;
    // }
}

void encrypt(char *plainText, char *roundKey, char *binaryRoundKey, char *cipherText)
{
    // initial permutation

    char plainTextIP[65];
    permutation(initialPermutationTable, plainText, 64, plainTextIP);
    printf("%ld, %s", strlen(plainText), plainText);

    // split string into two
    char LPT[33];
    char RPT[33];
    splitString(plainText, LPT, RPT);

    // round function
    int i = 0;
    while (i < ROUND_NUMBER)
    {
        // expansion from 32bit to 48bit
        char R_expanded[48];
        permutation(DboxTable, RPT, 48, R_expanded);

        // xor R_expanded and ith roundKey
        char xorResult[48];
        XOR(R_expanded, binaryRoundKey, xorResult);

        // S-box
        char Sbox_output[32] = "10101010101010101010101010101010";
        sBox(xorResult, Sbox_output);

        // xor left part and xorResult
        char result[33];
        XOR(LPT, Sbox_output, result);
        strcpy(LPT, result);

        if (i != 15) // swap
        {
            swapStrings(LPT, RPT);
        }
        i += 1;
    }

    // combine left and right part
    char final[64];
    combineStrings(LPT, RPT, final);

    // final permutation
    permutation(finalPermutationTable, final, 64, cipherText);
}

void roundKeyGeneration(char *initialKey, char roundKeys[][13], char binaryRoundKeys[][49])
{
    char binaryKey[(64 * 4) + 1];
    hex2binary(initialKey, binaryKey);

    // Drop parity bits from the 64bit key and permute the remaining according to the parity bit drop table
    char firstPermutedKey[57];
    permutation(parityBitDropTable, binaryKey, 56, firstPermutedKey);

    // split key into two
    char leftKey[29];
    char rightKey[29];

    splitString(firstPermutedKey, leftKey, rightKey);
    // printf("keys: %s %s\n", leftKey, rightKey);
    // printf("lengths: %lu %lu\n", strlen(leftKey), strlen(rightKey));

    int i = 0;
    while (i < ROUND_NUMBER)
    {
        // Shift the keys to left by n from shift table
        rotateKey(leftKey, shiftTable[i]);
        rotateKey(rightKey, shiftTable[i]);
        // printf("keys: %s %s\n", leftKey, rightKey);

        char combinedKey[57];
        combineStrings(leftKey, rightKey, combinedKey);

        char roundKey[49];
        permutation(keyPermutationTable, combinedKey, 48, roundKey);

        char hexRoundKey[13];
        binary2hex(roundKey, hexRoundKey);

        strcpy(binaryRoundKeys[i], roundKey);
        strcpy(roundKeys[i], hexRoundKey);
        i += 1;
    }
}

// done
void generateInputBlocks(char *plainText, int nBlock, char binaryInputBlocks[][65])
{
    int i = 0;
    while (i < nBlock)
    {
        int j = i * 64;
        int k = 0;
        while (k < 64)
        {
            binaryInputBlocks[i][k] = plainText[j];
            j += 1;
            k += 1;
        }
        binaryInputBlocks[i][64] = '\0';
        i += 1;
    }
}
// done

int main()
{
    // deneme
    char hexPlainText[200] = "4e6f772069732074";
    // deneme

    paddingToHexString(hexPlainText);
    int length = strlen(hexPlainText); // multiple of 16
    int nBlock = length / 16;
    char binaryPlainText[INPUT_LENGTH * 8 + 1];
    hex2binary(hexPlainText, binaryPlainText);

    // generate 64 bit block inputs for encryption
    char binaryInputBlocks[nBlock][65];
    generateInputBlocks(binaryPlainText, nBlock, binaryInputBlocks);
    int i;
    for (i = 0; i < nBlock; i++)
    {
        printf("For first text: ");
        printf("Block %d %s\n", i, binaryInputBlocks[i]);
    }

    // take input from stdin and convert to binary string of length multiple of 64 length
    printf("Results for Cihangir Tezcan plain text: \n");
    char *plainText2 = "Cihangir Tezcan"; // max 100 character input
    // scanf(plaintext);
    char hexPlainText2[MAX_INPUT_LENGTH * 2 + 1]; // max 100 character input
    string2hex(plainText2, hexPlainText2);
    paddingToHexString(hexPlainText2);
    printf("Input string with padding %s\n", hexPlainText2);
    length = strlen(hexPlainText2); // multiple of 16
    nBlock = length / 16;
    char binaryPlainText2[INPUT_LENGTH * 8 + 1];
    hex2binary(hexPlainText2, binaryPlainText2);

    // generate 64 bit block inputs for encryption
    char binaryInputBlocks2[nBlock][65];
    generateInputBlocks(binaryPlainText2, nBlock, binaryInputBlocks2);

    for (i = 0; i < nBlock; i++)
    {
        printf("For second text: ");
        printf("Block %d %s\n", i, binaryInputBlocks2[i]);
    }

    // generate round keys
    printf("Results of key generation: \n");
    char roundKeys[ROUND_NUMBER][13];
    char binaryRoundKeys[ROUND_NUMBER][49];
    char *initialKey = "0123456789abcdef";
    roundKeyGeneration(initialKey, roundKeys, binaryRoundKeys);
    for (i = 0; i < 16; i++)
    {
        printf("%s\n", roundKeys[i]);
    }

    char binaryOutputBlocks[nBlock][65];
    

    i=0;
    while (i < nBlock)
    {
        char cipherText[65];
        encrypt(binaryInputBlocks[i], roundKeys[i], binaryRoundKeys[i], cipherText);
        strcpy(binaryInputBlocks[i], cipherText);
        int k;
        for (k = 0; k < 16; k++)
    {
        printf("%s\n", cipherText[k]);
    }
        i += 1;
    }

    return 0;
}
