#pragma once
#include "Tree.h"

class Context {
private:
    Tree *strategyChild;

public:
    explicit Context(Tree *child)
    {
        strategyChild = child;
    }

    void Insert(int target)
    {
        strategyChild->insert(target);
    }
    void LevelDisplay()
    {
        strategyChild->level_display();
    };

    [[maybe_unused]] void Del(int target)
    {
        strategyChild->del(target);
    };

    void Inorder_Print()
    {
        strategyChild->inorder_print();
    };

    // tree node num
    [[maybe_unused]] void NodeNum_Print()
    {
        strategyChild->NodeNum_print();
    };
};
