//
// Created by 27574 on 2024/6/20.
//

#ifndef DATASTRUCTURECOURSEDESIGN_HUFFMAN_H
#define DATASTRUCTURECOURSEDESIGN_HUFFMAN_H

typedef struct {  // 存储字符及其出现频率
    char character;
    int frequency;
} CharFreq;

typedef struct HuffmanNode {  // 存储哈夫曼树节点
    int weight;
    char character;
    struct HuffmanNode *left, *right, *parent;
} HuffmanNode;

typedef struct {  // 存储哈夫曼树
    HuffmanNode **nodes;
    int size;
} HuffmanTree;

void calculate_frequency(const char *input_file, const char *output_file);

HuffmanTree *build_huffman_tree(const char *freq_file);

void save_huffman_tree(HuffmanTree *tree, const char *tree_file);

void display_huffman_tree(HuffmanTree *tree, char *result);

void generate_huffman_codes(HuffmanTree *tree, const char *code_file);

int calculate_wpl(HuffmanTree *tree);

void encode_text(const char *code_file, const char *encoding_file, const char *input_file);

char* decode_text(const char *encoded, HuffmanTree *tree);

void free_huffman_tree(HuffmanTree *tree);


#endif //DATASTRUCTURECOURSEDESIGN_HUFFMAN_H
