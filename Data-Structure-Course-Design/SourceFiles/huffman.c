#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../HeaderFiles/huffman.h"

#define MAX_NODES 256

// 辅助函数：创建新的哈夫曼节点
HuffmanNode *create_node(char character, int weight) {
    HuffmanNode *node = (HuffmanNode *) malloc(sizeof(HuffmanNode));
    node->character = character;
    node->weight = weight;
    node->left = node->right = node->parent = NULL;
    return node;
}

// 辅助函数：将节点插入到优先级队列中
void insert_node(HuffmanNode *nodes[], int *size, HuffmanNode *node) {
    nodes[*size] = node;
    int i = *size;
    while (i > 0 && nodes[(i - 1) / 2]->weight > nodes[i]->weight) {
        HuffmanNode *temp = nodes[(i - 1) / 2];
        nodes[(i - 1) / 2] = nodes[i];
        nodes[i] = temp;
        i = (i - 1) / 2;
    }
    (*size)++;
}

// 辅助函数：从优先级队列中提取最小的节点
HuffmanNode *extract_min(HuffmanNode *nodes[], int *size) {
    HuffmanNode *min_node = nodes[0];
    nodes[0] = nodes[--(*size)];
    int i = 0;
    while (2 * i + 1 < *size) {
        int min_child = 2 * i + 1;
        if (min_child + 1 < *size && nodes[min_child + 1]->weight < nodes[min_child]->weight) {
            min_child++;
        }
        if (nodes[i]->weight <= nodes[min_child]->weight) break;
        HuffmanNode *temp = nodes[i];
        nodes[i] = nodes[min_child];
        nodes[min_child] = temp;
        i = min_child;
    }
    return min_node;
}

// 统计字符频率
void calculate_frequency(const char *input_file, const char *output_file) {
    FILE *fin = fopen(input_file, "r");
    FILE *fout = fopen(output_file, "w");
    if (!fin || !fout) {
        perror("File opening failed");
        return;
    }

    int count[256] = {0};
    char ch;
    while ((ch = fgetc(fin)) != EOF) {
        if (isalnum((unsigned char) ch)) {
            count[(unsigned char) ch]++;
        }
    }

    for (int i = 0; i < 256; i++) {
        if (count[i] > 0) {
            fprintf(fout, "%c %d\n", i, count[i]);
        }
    }

    fclose(fin);
    fclose(fout);
}

// 从频率文件中读取频率并建立哈夫曼树
HuffmanTree *build_huffman_tree(const char *freq_file) {
    FILE *fin = fopen(freq_file, "r");
    if (!fin) {
        perror("File opening failed");
        return NULL;
    }

    HuffmanNode *nodes[MAX_NODES];
    int size = 0;

    char character;
    int frequency;
    while (fscanf(fin, " %c %d", &character, &frequency) == 2) {
        nodes[size++] = create_node(character, frequency);
    }
    fclose(fin);

    while (size > 1) {
        HuffmanNode *left = extract_min(nodes, &size);
        HuffmanNode *right = extract_min(nodes, &size);
        HuffmanNode *parent = create_node('\0', left->weight + right->weight);
        parent->left = left;
        parent->right = right;
        left->parent = right->parent = parent;
        insert_node(nodes, &size, parent);
    }

    HuffmanTree *tree = (HuffmanTree *) malloc(sizeof(HuffmanTree));
    tree->nodes = (HuffmanNode **) malloc(sizeof(HuffmanNode *));
    tree->nodes[0] = nodes[0];
    tree->size = 1;

    return tree;
}

// 将哈夫曼树保存到文件
void save_huffman_tree(HuffmanTree *tree, const char *tree_file) {
    FILE *fout = fopen(tree_file, "w");
    if (!fout) {
        perror("File opening failed");
        return;
    }

    HuffmanNode *root = tree->nodes[0];
    HuffmanNode *queue[MAX_NODES];
    int front = 0, rear = 0;
    int index = 1; // 下标从1开始
    int node_indices[MAX_NODES] = {0};

    queue[rear++] = root;
    node_indices[0] = index; // 根节点下标为1

    while (front < rear) {
        HuffmanNode *node = queue[front++];
        int current_index = node_indices[front - 1];
        int left_index = 0, right_index = 0, parent_index = 0;

        if (node->parent) {
            for (int i = 0; i < rear; i++) {
                if (queue[i] == node->parent) {
                    parent_index = node_indices[i];
                    break;
                }
            }
        }

        if (node->left) {
            left_index = ++index;
            queue[rear] = node->left;
            node_indices[rear++] = left_index;
        }

        if (node->right) {
            right_index = ++index;
            queue[rear] = node->right;
            node_indices[rear++] = right_index;
        }

        fprintf(fout, "(%d, %d, %d, %d, %d)\n", current_index, node->weight, parent_index, left_index, right_index);
    }

    fclose(fout);
}

// 辅助函数：递归显示哈夫曼树
void display_huffman_node(HuffmanNode *node, int depth, char *result) {
    if (!node) return;

    char buffer[256];
    for (int i = 0; i < depth; i++) {
        sprintf(buffer, "  ");
        strcat(result, buffer);
    }
    if (node->character) {
        sprintf(buffer, "%c (%d)\n", node->character, node->weight);
        strcat(result, buffer);
    } else {
        sprintf(buffer, "* (%d)\n", node->weight);
        strcat(result, buffer);
    }
    display_huffman_node(node->left, depth + 1, result);
    display_huffman_node(node->right, depth + 1, result);
}

// 显示哈夫曼树
void display_huffman_tree(HuffmanTree *tree, char *result) {
    if (tree && tree->nodes[0]) {
        display_huffman_node(tree->nodes[0], 0, result);
    }
}

// 辅助函数：递归生成哈夫曼编码
void generate_codes(HuffmanNode *node, char *code, int depth, FILE *fout) {
    if (!node) return;
    if (node->left == NULL && node->right == NULL) {
        code[depth] = '\0';
        fprintf(fout, "%c %s\n", node->character, code);
    } else {
        if (node->left) {
            code[depth] = '0';
            generate_codes(node->left, code, depth + 1, fout);
        }
        if (node->right) {
            code[depth] = '1';
            generate_codes(node->right, code, depth + 1, fout);
        }
    }
}

// 生成哈夫曼编码并保存到文件
void generate_huffman_codes(HuffmanTree *tree, const char *code_file) {
    FILE *fout = fopen(code_file, "w");
    if (!fout) {
        perror("File opening failed");
        return;
    }

    char code[MAX_NODES];
    generate_codes(tree->nodes[0], code, 0, fout);

    fclose(fout);
}

// 计算哈夫曼树的WPL值
int calculate_wpl(HuffmanTree *tree) {
    int wpl = 0;
    HuffmanNode *queue[MAX_NODES];
    int front = 0, rear = 0;
    queue[rear++] = tree->nodes[0];

    while (front < rear) {
        HuffmanNode *node = queue[front++];
        if (node->left == NULL && node->right == NULL) {
            int depth = 0;
            HuffmanNode *current = node;
            while (current->parent) {
                depth++;
                current = current->parent;
            }
            wpl += node->weight * depth;
        } else {
            if (node->left) queue[rear++] = node->left;
            if (node->right) queue[rear++] = node->right;
        }
    }

    return wpl;
}

// 对新输入的文本进行哈夫曼编码
void encode_text(const char *code_file, const char *encoding_file, const char *input_file) {
    FILE *fcode = fopen(code_file, "r");
    FILE *fin = fopen(input_file, "r");
    FILE *fout = fopen(encoding_file, "w");
    if (!fcode || !fin || !fout) {
        perror("File opening failed -- function:encode_text");
        return;
    }

    char codes[256][MAX_NODES] = {0};
    char ch, code[MAX_NODES];
    while (fscanf(fcode, " %c %s", &ch, code) == 2) {
        strcpy(codes[(unsigned char) ch], code);
    }
    fclose(fcode);

    // Read and encode each character from input file
    while ((ch = fgetc(fin)) != EOF) {
        if (isalnum((unsigned char) ch) && codes[(unsigned char) ch][0]) {
            fputs(codes[(unsigned char) ch], fout);
            printf("%s", codes[(unsigned char) ch]); // Print encoded character to terminal
        } else if (isalnum((unsigned char) ch)) {
            fputc(ch, fout);
            putchar(ch); // Print the original character to terminal
        }
    }
    printf("\n");

    fclose(fin);
    fclose(fout);
}

// 辅助函数：获取解码后的字符串长度
int get_decoded_length(const char *encoded, HuffmanTree *tree) {
    int length = 0;
    HuffmanNode *current = tree->nodes[0];
    while (*encoded) {
        if (*encoded == '0' || *encoded == '1') {
            if (*encoded == '0') {
                current = current->left;
            } else if (*encoded == '1') {
                current = current->right;
            }
            if (current->left == NULL && current->right == NULL) {
                length++;
                current = tree->nodes[0];
            }
        } else {
            length++;
        }
        encoded++;
    }
    return length;
}

// 解码函数
char* decode_text(const char *encoded, HuffmanTree *tree) {
    int decoded_length = get_decoded_length(encoded, tree);
    char *decoded = (char *)malloc(decoded_length + 1); // 为终止符预留空间

    if (!decoded) {
        perror("Memory allocation failed");
        return NULL;
    }

    HuffmanNode *current = tree->nodes[0];
    int index = 0;
    while (*encoded) {
        if (*encoded == '0' || *encoded == '1') {
            if (*encoded == '0') {
                current = current->left;
            } else if (*encoded == '1') {
                current = current->right;
            }
            if (current->left == NULL && current->right == NULL) {
                decoded[index++] = current->character;
                current = tree->nodes[0];
            }
        } else {
            decoded[index++] = *encoded;
        }
        encoded++;
    }
    decoded[index] = '\0';

    return decoded;
}

// 释放哈夫曼树
void free_huffman_tree(HuffmanTree *tree) {
    if (!tree || !tree->nodes[0]) return;

    HuffmanNode *stack[MAX_NODES];
    int top = 0;
    stack[top++] = tree->nodes[0];

    while (top > 0) {
        HuffmanNode *node = stack[--top];
        if (node->left) stack[top++] = node->left;
        if (node->right) stack[top++] = node->right;
        free(node);
    }

    free(tree->nodes);
    free(tree);
}
