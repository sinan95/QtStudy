#ifndef SIMILARITY_H
#define SIMILARITY_H

#include "generalalgorithm_global.h"

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
extern "C" GENERALALGORITHMSHARED_EXPORT float SimilarityMatrix(const char *str1, const char *str2);


/**
 * @brief SimilarityED
 * 字符串编辑距离算法
 * 相似度计算:
 * int ed = SimilarityED(str1, str2);
 * float similarity = 1.0-(float)ed/max(strlen(str1),strlen(str1))
 */
extern "C" GENERALALGORITHMSHARED_EXPORT int SimilarityED(const char *str1, const char *str2);


#endif // SIMILARITY_H
