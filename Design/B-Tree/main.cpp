#include "BPlusTree.h"
#include "BTree.h"
#include "Context.h"
#include <cstdio>

int main()
{

    BTree bt;
    BPlusTree bpt;

    int arr[] = {18, 31, 12, 10, 15, 48, 45, 47, 50, 52, 23, 30, 20};
    // 1.从键盘输入一组关键字插入B_树中；
    for (int i: arr)
    {
        // 2.向B-树中插入一个关键字；
        bt.insert(i);
        bpt.insert(i);
    }
    printf("INFO: No Pending Delete Data\n");
    printf("INFO: Display B-Tree:\n");
    bt.level_display();
    bt.inorder_print();
    printf("\n\n");

    printf("INFO: Display B+ Tree:\n");
    bt.level_display();
    bt.inorder_print();
    printf("\n");
    bpt.linear_print();
    printf("\n");
    bt.NodeNum_print();
    bpt.NodeNum_print();
    printf("WARN: Deleting Data!\n");
    int todel[] = {15, 18, 23, 30, 31, 52, 50};

    for (int i: todel)
    {
        // 3.从B_树中删除一个关键字；
        bt.del(i);
        bpt.del(i);
        printf("DEBUG: Deleted %d\n", i);
    }

    // 7.求出一棵B_树的节点数；
    bt.NodeNum_print();
    bpt.NodeNum_print();

    printf("\n\nINFO: Delete After Data:\n");
    printf("INFO: Display B-Tree:\n");
    // 5.遍历输出B_树中所有关键字；
    bt.level_display();
    bt.inorder_print();
    printf("\n\n");

    printf("INFO: Display B+ Tree:\n");
    bpt.level_display();
    bpt.inorder_print();
    printf("\n");
    bpt.linear_print();
    printf("\n");


    printf("INFO: Strategy Method Start\n");

    auto *Context_A = new Context(new BTree()),
         *Context_B = new Context(new BPlusTree());

    int arrnum[] = {10, 2, 3, 4, 5, 9, 8, 7, 6, 1};
    for (int i: arrnum)
    {
        Context_A->Insert(i);
        Context_B->Insert(i);
    }
    Context_A->Inorder_Print();
    printf("\n\n");
    Context_B->LevelDisplay();

    return 0;
}
