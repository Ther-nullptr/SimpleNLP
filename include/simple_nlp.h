#ifndef SIMPLE_NLP_H
#define SIMPLE_NLP_H
#include <string>
#include <vector>

#define EQUAL 0
#define INSERTATION 1
#define DELETATION 2
#define SUBSTITUTION 3

// record the info
struct NLP_Info
{
    std::string hyp;   /* hypo string */
    std::string ref;   /* ref string  */
    int edit_distance; /* edit distance */
    double CER;        /* CER */
    int S;             /* substitution characters */
    int D;             /* deletion characters */
    int I;             /* insertion characters */
    int C;             /* correct characters */
    int W;             /* wrong characters */
    int N;             /* length of ref */

    NLP_Info() : edit_distance(0), CER(0), S(0), D(0), I(0), C(0), W(0), N(0) {}
};

// lemma 1: if the length of one string is 0, then edit-distance is length of another string.
// which means dp[i][0] = i dp[0][j] = j
// lemma 2: the order of the transform operation doesn't matter.
// which means we only have to insert/change at the end of one string
// So we can use the dynamic planning.
// we have only 3 methods to transform 1 step:
// 1. insert a letter in s1
// 2. delete a letter in s1
// 3. change a letter in s1
// for the first method, we can get dp[i][j] = dp[i-1][j] + 1 (insert a letter at the end of s1)
// for the second method, we can get dp[i][j] = dp[i][j-1] + 1 (delete a letter at the end of s1)
// for the third method, we can get dp[i][j] = dp[i-1][j-1] (if s1[i-1]=s2[j-1]) or dp[i][j] = dp[i-1][j-1] (if s1[i-1]!=s2[j-1], we have to change s1[i])
int edit_distance(std::string s1, std::string s2);

// CER(Character Error Rate), usually used in Chinese
// CER = (S+D+I)/N
// S: substitution characters
// D: deletion characters
// I: insertation characters
// N: reference characters
double CER(std::string hyp, std::string ref);

// WER(Word Error Rate), usually used in English
// WER = (S+D+I)/N
// S: substitution words
// D: deletion words
// I: insertation words
// N: reference words
double WER(std::string hyp, std::string ref);

// get the details of calculate result
NLP_Info get_details(std::string hyp, std::string ref);

#endif // SIMPLE_NLP_H