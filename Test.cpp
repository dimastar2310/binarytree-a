#include "doctest.h"
#include "BinaryTree.hpp"
#include <array>

using namespace ariel;
using namespace std;

TEST_CASE("Integer BinaryTree"){
    BinaryTree<int> tree_of_ints;
    tree_of_ints.add_root(1);
    for(int i = 3, j = 1; i < 12;++j,i+=2){
        CHECK_NOTHROW(tree_of_ints.add_left(j,i-1));
        CHECK_NOTHROW(tree_of_ints.add_right(j,i));
    }
    CHECK_THROWS(tree_of_ints.add_right(12,1));
    CHECK_THROWS(tree_of_ints.add_left(12,1));

    array<int,11> inorder{8,4,9,2,10,5,11,0,6,3,7};
    array<int,11> postorder{8,9,4,10,11,5,2,6,7,3,0};
    array<int,11> preoder{1,2,4,8,9,5,40,30,3,6,7};

    unsigned int i = 0;
    for (auto it=tree_of_ints.begin_preorder(); it!=tree_of_ints.end_preorder(); ++it) {
        CHECK_EQ((*it),preoder.at(i));
        ++i;
    }
    tree_of_ints.add_root(0);
    i = 0;
    for (auto it=tree_of_ints.begin_inorder(); it!=tree_of_ints.end_inorder(); ++it) {
        CHECK_EQ((*it),inorder.at(i));
        ++i;
    }
    CHECK_NOTHROW(tree_of_ints.add_right(5,30));
    CHECK_NOTHROW(tree_of_ints.add_left(5,40));
    i=0;
    for (auto it=tree_of_ints.begin_postorder(); it!=tree_of_ints.end_postorder(); ++it) {
        CHECK_EQ((*it),postorder.at(i));
        ++i;
    }

}

TEST_CASE("String BinaryTree"){
    BinaryTree<string> tree_of_strings;
    tree_of_strings.add_root("Israel");
    CHECK_NOTHROW(tree_of_strings.add_right("Israel","Jerusalem"));
    CHECK_NOTHROW(tree_of_strings.add_left("Israel","Tel-Aviv"));
    CHECK_NOTHROW(tree_of_strings.add_right("Tel-Aviv","Rehovot"));
    CHECK_NOTHROW(tree_of_strings.add_left("Jerusalem","Raanana"));
    CHECK_NOTHROW(tree_of_strings.add_right("Raanana","Herzliya"));
    
    CHECK_THROWS(tree_of_strings.add_left("Ashdod","Ashkelon"));
    CHECK_THROWS(tree_of_strings.add_right("Bat-yam","Ariel"));

    array<string,6> inorder{"Tel-Aviv","Rehovot","Israel","Raanana","Herzliya","Jerusalim"};
    array<string,6> postorder{"Rehovot","Tel-Aviv","Herzliya","Raanana","Jerusalim","Israel"};
    array<string,16> preoder{"Israel","Tel-Aviv","Rehovot","Jerusalim","Raanana","Herzliya"};

    unsigned int i = 0;
    for (const string& element : tree_of_strings) {
        CHECK_EQ(element,inorder.at(i));
        i++;
    }

    i = 0;
    for (auto it=tree_of_strings.begin_preorder(); it!=tree_of_strings.end_preorder(); ++it) {
        CHECK_EQ((*it),preoder.at(i));
        ++i;
    }

    for (auto it=tree_of_strings.begin_postorder(); it!=tree_of_strings.end_postorder(); ++it) {
        CHECK_EQ((*it),postorder.at(i));
        ++i;
    }


}