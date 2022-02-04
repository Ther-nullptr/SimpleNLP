#include "../include/simple_nlp.h"
#include <iostream>

int edit_distance(std::string s1, std::string s2)
{
    int len_s1 = s1.length();
    int len_s2 = s2.length();

    std::vector<std::vector<int>> dp(len_s1 + 1, std::vector<int>(len_s2 + 1));

    // initialize the dp array
    for (int i = 0; i <= len_s1; i++)
    {
        dp[i][0] = i;
    }

    for (int j = 0; j <= len_s2; j++)
    {
        dp[0][j] = j;
    }

    // core code of dp
    for (int i = 1; i <= len_s1; i++)
    {
        for (int j = 1; j <= len_s2; j++)
        {

            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                int insertation = dp[i - 1][j] + 1;
                int deletion = dp[i][j - 1] + 1;
                int substitution = dp[i - 1][j - 1] + 1;
                dp[i][j] = std::min(insertation, std::min(deletion, substitution));
            }
        }
    }

    int answer = dp[len_s1][len_s2];
    return answer;
}

double CER(std::string hyp, std::string ref)
{
    int W = edit_distance(hyp, ref);
    int N = ref.length();
    double cer = double(W) / double(N);
    return cer;
}

NLP_Info get_details(std::string hyp, std::string ref)
{
    NLP_Info info;

    int len_s1 = hyp.length();
    int len_s2 = ref.length();

    // dp array
    std::vector<std::vector<int>> dp(len_s1 + 1, std::vector<int>(len_s2 + 1, 0));

    // the array to record the operations
    std::vector<std::vector<int>> op(len_s1 + 1, std::vector<int>(len_s2 + 1, 0));

    // initialize the dp array
    for (int i = 0; i <= len_s1; i++)
    {
        dp[i][0] = i;
    }

    for (int j = 0; j <= len_s2; j++)
    {
        dp[0][j] = j;
    }

    // core code of dp
    for (int i = 1; i <= len_s1; i++)
    {
        for (int j = 1; j <= len_s2; j++)
        {

            if (hyp[i - 1] == ref[j - 1])
            {
                // no operations
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                // with a operation
                int insertation = dp[i - 1][j] + 1;
                int deletion = dp[i][j - 1] + 1;
                int substitution = dp[i - 1][j - 1] + 1;
                dp[i][j] = std::min(insertation, std::min(deletion, substitution));

                // Priority Level: ins->del->sub
                int min_operation = dp[i][j];
                if (insertation == min_operation)
                {
                    op[i][j] = INSERTATION;
                }
                else if (deletion == min_operation)
                {
                    op[i][j] = DELETATION;
                }
                else if (substitution == min_operation)
                {
                    op[i][j] = SUBSTITUTION;
                }
            }
        }
    }

    // calculate the num of 3 operations
    int m = len_s1;
    int n = len_s2;
    while (m >= 0 && n >= 0)
    {
        switch (op[m][n])
        {
        case EQUAL:
            if (m >= 1 && n >= 1)
            {
                info.C++;
            }
            m--;
            n--; // jump to the last status
            break;

        case INSERTATION:
            info.I++;
            m--;
            break;

        case DELETATION:
            info.D++;
            n--;
            break;

        case SUBSTITUTION:
            info.S++;
            m--;
            n--;
            break;
        }
    }
    if (m < 0)
    {
        while (n >= 0)
        {
            info.D++;
            n--;
        }
    }
    else if (n < 0)
    {
        while (m >= 0)
        {
            info.I++;
            m--;
        }
    }

    info.edit_distance = dp[len_s1][len_s2];
    info.W = info.S + info.D + info.I;
    info.N = len_s2;
    info.hyp = hyp;
    info.ref = ref;
    info.CER = double(info.W) / double(len_s2);
    
    return info;
}