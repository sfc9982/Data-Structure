#pragma once
#include "Tree.h"
#include "struct.h"

class BTree : public Tree {
protected:
    btree_node *btree_create() override;
    btree_node *btree_node_new() override;
    int btree_split_child(btree_node *parent, int pos, btree_node *child) override;
    void btree_insert_nonfull(btree_node *node, int target) override;
    void btree_merge_child(btree_node *root, int pos, btree_node *y, btree_node *z) override;
    void btree_delete_nonone(btree_node *root, int target) override;
    int btree_search_successor(btree_node *root) override;
    int btree_search_predecessor(btree_node *root) override;
    void btree_shift_to_left_child(btree_node *root, int pos, btree_node *y, btree_node *z) override;
    void btree_shift_to_right_child(btree_node *root, int pos, btree_node *y, btree_node *z) override;
    btree_node *btree_insert(btree_node *root, int target) override;
    btree_node *btree_delete(btree_node *root, int target) override;
    void btree_inorder_print(btree_node *root) override;
    void btree_level_display(btree_node *root) override;
    void Save(btree_node *root) override;

public:
    BTree();
    ~BTree() override;
};
