#include "similarity.h"
#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

/**
 * @brief SimilarityMatrix
 * 矩阵相似度
 * 1、n:两个字符串的最大长度
 * 2、m:相同的字符串
 * 3、r:获取m时的两个字符串的重叠部分长度
 *
 * 重叠率： L = r/n
 * 匹配率： M = m/n
 * 相似度： Q = M^2*L = (m^2/n^2)*(r/n)
 * 将Q变形：Q = (m^2/r^2)*(r/n) = m^2/(r*n)
 */
float SimilarityMatrix(const char *str1, const char *str2)
{
    // 字符串的长度
    int n = 0;
    // 相同的字符串个数
    int m = 0;
    // 两个字符串重叠的部分--最大相同时获取
    int r = 0;

    int len1 = strlen(str1);
    int len2 = strlen(str2);
    n = max(len1, len2);

    int temp = 0;
    for (int i=0; i<len1; i++) {
        // 遍历字符串重叠部分
        temp = 0;
        for (int j=i; j<min(len1-i, len2); j++) {
            if (str1[j] == str2[j]) {
                temp++;
                if (temp > m) {
                    m = temp;
                    r = min(len1-i, len2);
                }
            } else {
                temp = 0;
            }
        }
    }
    // 如果没有重叠部分或者最大长度为0则相似度为0
    if (r == 0 || n == 0) {
        return 0.0f;
    }

    return (float)m*m/(r*n);
}

/**
 * @brief SimilarityED
 * 字符串编辑距离算法
 * 相似度计算:
 * int ed = SimilarityED(str1, str2);
 * float similarity = 1.0-(float)ed/max(strlen(str1),strlen(str1))
 */
int SimilarityED(const char *str1, const char *str2)
{
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int **p = (int **)malloc(sizeof(int *)*(len1+1));
    for (int i=0; i<=len1; i++) {
        p[i] = (int *)malloc(sizeof(int) * (len2+1));
    }
    for (int i=0; i<=len1; i++) {
        p[i][0] = i;
    }
    for (int i=0; i<=len2; i++) {
        p[0][i] = i;
    }
    for (int i=1; i<=len1; i++) {
        for (int j=1; j<=len2; j++) {
            if (str1[i-1] == str2[j-1]) {
                p[i][j] = p[i-1][j-1];
            } else {
                p[i][j] = min(p[i-1][j-1], min(p[i][j-1], p[i-1][j]))+1;
            }
        }
    }
    int ed = p[len1][len2];
    for (int i=0; i<=len1; i++) {
        free(p[i]);
    }
    free(p);
    return ed;
}



