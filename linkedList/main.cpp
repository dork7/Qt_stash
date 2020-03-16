#include "mainwindow.h"
#include <QApplication>
#include <QDebug>

class Node {
public:
    int data;
    Node* next;
};

void nodeTraversal(Node * n){
    while (n!= NULL) {
        qDebug() << n->data << " ";
        n = n->next;
    }
}

// function to create and return a Node
Node* getNode(int data)
{
    // allocating space
    Node* newNode = new Node();

    // inserting the required data
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //    MainWindow w;
    //    w.show();

    Node* head = NULL;
    Node* second = NULL;
    Node* third = NULL;

    // allocate 3 nodes in the heap
    head = new Node();
    second = new Node();
    third = new Node();

    head->data = 1; // assign data in first node
    head->next = second;

    // assign data to second node
    second->data = 2;

    // Link second node with the third node
    second->next = third;

    third->data = 3; // assign data to third node
    third->next = NULL;

    Node* head2 = NULL;
    head2 = getNode(3);
    head2->next = getNode(5);
    head2->next->next = getNode(8);
    head2->next->next->next = getNode(10);




    // adding node
//    nodeAdd();
    //


    // Traversal
    //    while (head!= NULL) {
    //        qDebug() << head->data << " ";
    //        head = head->next;
    //    }
    // using function
    nodeTraversal(head2);
    //



    //    qDebug() << "head->data" << head->data;

    return a.exec();
}
