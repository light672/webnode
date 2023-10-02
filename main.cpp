#include <iostream>
#include "Component.h"

int main() {
    Component root = Component("body");
    Component child0 = Component("img");
    Component child1 = Component("h3");
    Component child1Child0 = Component("Caption");
    Component child2 = Component("p");
    Component child2Child0 = Component("Sub Caption");
    root.addChild(&child0);
    root.addChild(&child1);
    root.addChild(&child2);

    child1.addChild(&child1Child0);
    child2.addChild(&child2Child0);
    root.printHierarchy("body");
    return 0;
}
