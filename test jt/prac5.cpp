#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 14 // 最大数字长度
#define MAX_QUEUE_SIZE 100000 // 队列最大容量

typedef struct {
    char sequence[MAX_N]; // 当前数字序列
    int steps; // 交换次数
} State;

State queue[MAX_QUEUE_SIZE]; // 队列
int front = 0, rear = 0; // 队列的头和尾

// 检查队列是否为空
int is_queue_empty() {
    return front == rear;
}

// 入队
void enqueue(State state) {
    queue[rear++] = state;
}

// 出队
State dequeue() {
    return queue[front++];
}

// 检查是否包含目标子串 "2012"
int contains_target(const char* sequence) {
    return strstr(sequence, "2012") != NULL;
}

// 交换相邻字符
void swap(char* sequence, int i, int j) {
    char temp = sequence[i];
    sequence[i] = sequence[j];
    sequence[j] = temp;
}

// BFS 求解最小交换次数
int min_swaps_to_open_lock(int N, char* initial_sequence) {
    char visited[MAX_QUEUE_SIZE][MAX_N]; // 记录访问过的状态
    int visited_count = 0; // 已访问状态的数量

    // 初始状态入队
    State initial_state;
    strcpy(initial_state.sequence, initial_sequence);
    initial_state.steps = 0;
    enqueue(initial_state);

    // 标记初始状态为已访问
    strcpy(visited[visited_count++], initial_sequence);

    while (!is_queue_empty()) {
        State current = dequeue();

        // 如果当前状态包含目标子串，返回交换次数
        if (contains_target(current.sequence)) {
            return current.steps;
        }

        // 尝试交换相邻字符
        for (int i = 0; i < N - 1; i++) {
            char new_sequence[MAX_N];
            strcpy(new_sequence, current.sequence);
            swap(new_sequence, i, i + 1); // 交换第 i 和第 i+1 个字符

            // 检查新状态是否已经访问过
            int is_visited = 0;
            for (int j = 0; j < visited_count; j++) {
                if (strcmp(visited[j], new_sequence) == 0) {
                    is_visited = 1;
                    break;
                }
            }

            // 如果未访问过，加入队列并标记为已访问
            if (!is_visited) {
                State new_state;
                strcpy(new_state.sequence, new_sequence);
                new_state.steps = current.steps + 1;
                enqueue(new_state);
                strcpy(visited[visited_count++], new_sequence);
            }
        }
    }

    // 如果队列为空且未找到目标状态，返回 -1
    return -1;
}

int main() {
    int N;
    char sequence[MAX_N];

    // 输入处理
    scanf("%d", &N);
    scanf("%s", sequence);

    // 输出结果
    int result = min_swaps_to_open_lock(N, sequence);
    printf("%d\n", result);

    return 0;
}