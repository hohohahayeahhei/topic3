#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_N 26 // 最大士兵数量

// 邻接表节点
typedef struct Node {
    char vertex;
    struct Node* next;
} Node;

// 图结构
typedef struct {
    Node* adjList[MAX_N]; // 邻接表
    int inDegree[MAX_N];  // 入度
    int nodeCount;        // 节点数量
} Graph;

// 初始化图
void initGraph(Graph* graph) {
    for (int i = 0; i < MAX_N; i++) {
        graph->adjList[i] = NULL;
        graph->inDegree[i] = 0;
    }
    graph->nodeCount = 0;
}

// 添加边
void addEdge(Graph* graph, char u, char v) {
    int uIndex = u - 'A';
    int vIndex = v - 'A';

    // 创建新节点
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = graph->adjList[uIndex];
    graph->adjList[uIndex] = newNode;

    // 更新入度
    graph->inDegree[vIndex]++;
}

// 拓扑排序
int topologicalSort(Graph* graph, char* result) {
    int resultIndex = 0;
    char queue[MAX_N];
    int front = 0, rear = 0;

    // 将所有入度为 0 的节点加入队列
    for (int i = 0; i < MAX_N; i++) {
        if (graph->inDegree[i] == 0 && graph->adjList[i] != NULL) {
            queue[rear++] = 'A' + i;
        }
    }

    // 拓扑排序
    while (front < rear) {
        char u = queue[front++];
        result[resultIndex++] = u;

        int uIndex = u - 'A';
        Node* current = graph->adjList[uIndex];
        while (current != NULL) {
            int vIndex = current->vertex - 'A';
            graph->inDegree[vIndex]--;
            if (graph->inDegree[vIndex] == 0) {
                queue[rear++] = current->vertex;
            }
            current = current->next;
        }
    }

    // 检查是否存在环
    if (resultIndex != graph->nodeCount) {
        return 0; // 存在环
    }
    return 1; // 拓扑排序成功
}

int main() {
    Graph graph;
    initGraph(&graph);

    char input[10];
    while (scanf("%s", input) != EOF) {
        char u = input[0];
        char v = input[2];

        // 添加边
        addEdge(&graph, u, v);

        // 统计节点数量
        if (graph.adjList[u - 'A'] == NULL) {
            graph.nodeCount++;
        }
        if (graph.adjList[v - 'A'] == NULL) {
            graph.nodeCount++;
        }
    }

    char result[MAX_N];
    if (topologicalSort(&graph, result)) {
        for (int i = 0; i < graph.nodeCount; i++) {
            printf("%c", result[i]);
        }
        printf("\n");
    } else {
        printf("No Answer!\n");
    }

    return 0;
}