#include <stdio.h>
#include <stdbool.h>

int n, m;
int predictions[10][11]; // 存储每个围观党的预测
bool used[10]; // 用于标记运动员是否已经被使用
int current_ranking[10]; // 当前正在生成的排名
int possible_rankings[20000][10]; // 存储所有可能的排名
int count = 0; // 记录可能的排名数量

// 检查当前排名是否满足所有围观党的预测
bool is_valid_ranking() {
    for (int i = 0; i < m; i++) {
        int c = predictions[i][0];
        int expected_correct = predictions[i][c + 1];
        int idx = 0;
        bool is_subsequence = true;

        // 检查预测是否是当前排名的子序列
        for (int j = 0; j < n; j++) {
            if (current_ranking[j] == predictions[i][idx + 1]) {
                idx++;
                if (idx == c) break;
            }
        }

        // 根据预测的正确性判断是否满足条件
        if ((expected_correct == 1 && idx != c) || (expected_correct == 0 && idx == c)) {
            return false;
        }
    }
    return true;
}

// 深度优先搜索生成所有可能的排名
void dfs(int depth) {
    if (depth == n) {
        if (is_valid_ranking()) {
            for (int i = 0; i < n; i++) {
                possible_rankings[count][i] = current_ranking[i];
            }
            count++;
        }
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            used[i] = true;
            current_ranking[depth] = i;
            dfs(depth + 1);
            used[i] = false;
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++) {
        int c;
        scanf("%d", &c);
        predictions[i][0] = c;
        for (int j = 1; j <= c; j++) {
            scanf("%d", &predictions[i][j]);
        }
        scanf("%d", &predictions[i][c + 1]);
    }

    dfs(0);

    printf("%d\n", count);
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", possible_rankings[i][j]);
        }
        printf("\n");
    }

    return 0;
}