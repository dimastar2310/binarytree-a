#pragma once
#include <iostream>
#include <vector>

namespace ariel{

    template<typename T> class BinaryTree{
        private:
            struct Node{
                T value;
                Node* left;
                Node* right;
                Node(T& v,Node* l = nullptr, Node* r = nullptr):value(v),left(l),right(r) {}
            };
            Node* head;
            int size = 0;
        public:
            BinaryTree():head(nullptr),size(0){}
            BinaryTree& add_root(T root);
            BinaryTree& add_left(T exsist, T add);
            BinaryTree& add_right(T exsist, T add);
            friend std::ostream& operator<<(std::ostream& out, const BinaryTree<T>& b){
                return out;
            }
    
            class iterator{
                private:
		            Node* pointer_to_current_node;
                    std::vector<Node*> tree_in_vector;
                    unsigned int i = 0;
                    int flag;

                public:    
                    iterator(Node* ptr = nullptr): pointer_to_current_node(ptr){
                        // tree_in_vector.resize(_size);
                        
                    }
                    void Inorder(Node* node);
                    void Preoder(Node* node);
                    void Postorder(Node* node);
                    T& operator*() const {return pointer_to_current_node->value;}
		            T* operator->() const {return &(pointer_to_current_node->value);}
		            iterator& operator++() {
			            pointer_to_current_node = tree_in_vector.at(++i);
			            return *this;
		            }
		            const iterator operator++(int) {
			            iterator tmp = *this;
			            pointer_to_current_node = tree_in_vector.at(++i);
			            return tmp;
		            }

		            bool operator==(const iterator& rhs) const {return pointer_to_current_node == rhs.pointer_to_current_node;}
		            bool operator!=(const iterator& rhs) const {return pointer_to_current_node != rhs.pointer_to_current_node;}
            };

            class const_iterator {

	            private:
		            Node* pointer_to_current_node;

	            public:

		        const_iterator(Node* ptr = nullptr): pointer_to_current_node(ptr) {}

		        const T& operator*() const {return pointer_to_current_node->value;}

		        const T* operator->() const {return &(pointer_to_current_node->value);}

		        const_iterator& operator++() {
			        // pointer_to_current_node = pointer_to_current_node->m_next;
			        return *this;
		        }

		        const const_iterator operator++(int) {
			        const_iterator tmp= *this;
			        // pointer_to_current_node= pointer_to_current_node->m_next;
			        return tmp;
		        }

		        bool operator==(const const_iterator& rhs) const {return pointer_to_current_node == rhs.pointer_to_current_node;}

		        bool operator!=(const const_iterator& rhs) const {return pointer_to_current_node != rhs.pointer_to_current_node;}
	        };  // END OF CLASS const_iterator

            iterator begin_inorder();
            iterator end_inorder();
            iterator begin_preorder();
            iterator end_preorder();
            iterator begin_postorder();
            iterator end_postorder();
            const_iterator begin();
            const_iterator end();

    };
    template<typename T>
    BinaryTree<T>& BinaryTree<T>::add_root(T root){
        return *this;
    }

    template<typename T>
    BinaryTree<T>& BinaryTree<T>::add_left(T exsist, T add){
        return *this;
    }

    template<typename T>
    BinaryTree<T>& BinaryTree<T>::add_right(T exsist, T add){
        return *this;
    }

    template<typename T>
    typename BinaryTree<T>::iterator BinaryTree<T>::begin_inorder(){
        return iterator();
    }

    template<typename T>
    typename BinaryTree<T>::iterator BinaryTree<T>::end_inorder(){
        return iterator();
    }

    template<typename T>
    typename BinaryTree<T>::iterator BinaryTree<T>::begin_preorder(){
        return iterator();
    }

    template<typename T>
    typename BinaryTree<T>::iterator BinaryTree<T>::end_preorder(){
        return iterator();
    }

    template<typename T>
    typename BinaryTree<T>::iterator BinaryTree<T>::begin_postorder(){
        return iterator();
    }

    template<typename T>
    typename BinaryTree<T>::iterator BinaryTree<T>::end_postorder(){
        return iterator();
    }

    template<typename T>
    typename BinaryTree<T>::const_iterator BinaryTree<T>::begin(){
        return const_iterator();
    }

    template<typename T>
    typename BinaryTree<T>::const_iterator BinaryTree<T>::end(){
        return const_iterator();
    }

    template<typename T>
    void BinaryTree<T>::iterator::Inorder(Node* node){
        if (node == nullptr)
            return;
 
        Inorder(node->left);
        tree_in_vector.insert(node);
        Inorder(node);
    }

    template<typename T>
    void BinaryTree<T>::iterator::Preoder(Node* node){
        if (node == nullptr)
            return;

        tree_in_vector.insert(node);
        Inorder(node->left);
        Inorder(node->right);
    }

    template<typename T>
    void BinaryTree<T>::iterator::Postorder(Node* node){
        if (node == nullptr)
            return;
 
        Postorder(node->left);
        Postorder(node->right);
        tree_in_vector.insert(node);
    }

}