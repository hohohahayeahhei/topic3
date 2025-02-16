#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_DIGITS 10  // 数字 0-9
#define MAX_NUMBERS 100000  // 假设最多生成 100000 个数

int rules[MAX_DIGITS][MAX_DIGITS];  // 变换规则
char numbers[MAX_NUMBERS][31];      // 存储生成的数
int count = 0;                      // 记录生成的数的个数

// 递归生成所有可能的数
void generate_numbers(char *current, int index) {
    if (current[index] == '\0') {
        // 检查是否已经生成过
        for (int i = 0; i < count; i++) {
            if (strcmp(numbers[i], current) == 0) {
                return;
            }
        }
        // 将当前数加入结果
        strcpy(numbers[count], current);
        count++;
        return;
    }

    int digit = current[index] - '0';  // 当前位的数字

    // 不进行变换
    generate_numbers(current, index + 1);

    // 遍历所有可能的变换
    for (int i = 0; i < MAX_DIGITS; i++) {
        if (rules[digit][i]) {
            char next[31];
            strcpy(next, current);
            next[index] = i + '0';  // 替换当前位
            generate_numbers(next, index + 1);
        }
    }
}

int main() {
    char n[31];  // 存储输入的整数（最多 30 位）
    int k;       // 变换规则的数量

    // 读取输入
    scanf("%s %d", n, &k);

    // 初始化变换规则
    for (int i = 0; i < k; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        rules[x][y] = 1;  // 添加变换规则 x -> y
    }

    // 生成所有可能的数
    generate_numbers(n, 0);

    // 输出结果
    printf("%d\n", count);

    return 0;
}