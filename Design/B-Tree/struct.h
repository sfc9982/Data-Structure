#pragma once
// the degree of btree
#define M 2
// actually M = 4

typedef struct btree_nodes {
    int k[2 * M - 1];
    struct btree_nodes *p[2 * M];
    int num;
    bool is_leaf;
    [[maybe_unused]] struct btree_nodes *prev; // use one struct just for simple, these are for B+Tree used
    struct btree_nodes *next;                  // for B+Tree used

} btree_node;


typedef struct StorageNode {
    [[maybe_unused]] btree_node bnode;
    [[maybe_unused]] int index[M]; // 索引单重集: index_set
} storage_node;

[[maybe_unused]] typedef struct StorageStruct {
    [[maybe_unused]] storage_node *snode;
    [[maybe_unused]] int len;
} storage_struct;
