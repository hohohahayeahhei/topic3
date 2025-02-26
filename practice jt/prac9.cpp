#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 100
#define MAX_WORD_LEN 50

// 比较函数，用于排序
int compare(const void *a, const void *b) {
    return *(char *)a - *(char *)b;
}

// 标准化单词（将字母排序）
void normalizeWord(char *word, char *normalized) {
    strcpy(normalized, word);
    qsort(normalized, strlen(normalized), sizeof(char), compare);
}

int main() {
    char keywords[MAX_WORDS][MAX_WORD_LEN]; // 存储关键词
    char normalizedKeywords[MAX_WORDS][MAX_WORD_LEN]; // 存储标准化后的关键词
    char sentence[1000]; // 存储句子
    char word[MAX_WORD_LEN]; // 临时存储单词
    char normalizedWord[MAX_WORD_LEN]; // 临时存储标准化后的单词
    int keywordCount = 0; // 关键词数量
    int found[MAX_WORDS] = {0}; // 记录是否找到关键词

    // 读取关键词列表
    fgets(sentence, sizeof(sentence), stdin);
    // 去掉换行符
    sentence[strcspn(sentence, "\n")] = '\0';
    char *token = strtok(sentence, " ");
    while (token != NULL) {
        strcpy(keywords[keywordCount], token);
        normalizeWord(keywords[keywordCount], normalizedKeywords[keywordCount]);
        keywordCount++;
        token = strtok(NULL, " ");
    }

    // 读取句子
    fgets(sentence, sizeof(sentence), stdin);
    // 去掉换行符
    sentence[strcspn(sentence, "\n")] = '\0';
    token = strtok(sentence, " ");
    while (token != NULL) {
        strcpy(word, token);
        normalizeWord(word, normalizedWord);

        // 检查是否匹配关键词
        for (int i = 0; i < keywordCount; i++) {
            if (strcmp(normalizedWord, normalizedKeywords[i]) == 0) {
                found[i] = 1; // 标记为找到
            }
        }
        token = strtok(NULL, " ");
    }

    // 输出结果
    int first = 1;
    for (int i = 0; i < keywordCount; i++) {
        if (found[i]) {
            if (!first) {
                printf(" ");
            }
            printf("%s", keywords[i]);
            first = 0;
        }
    }
    printf("\n");

    return 0;
}
