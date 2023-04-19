//
// Created by Bret Thex on 4/16/23.
//
#include <iostream>
#include <fstream>
#include <sstream>


using namespace std;

//============================================================================
// Global definitions visible to all methods and classes
//============================================================================

// Structure to hold course information
struct Course {
    string courseId;
    string courseName;
    string coursePrereq;

    Course() {
        courseId = "";
        courseName = "";
        coursePrereq = "";
    }

    Course(string &csvId, string &csvName, string &csvPrereq) {
        courseId = csvId;
        courseName = csvName;
        coursePrereq = csvPrereq;
    }
};

// Tree node structure
struct Node {
    Course course;
    Node *left;
    Node *right;

    // Default Constructor
    Node() {
        left = nullptr;
        right = nullptr;
    }

    // initialize with a course
    explicit Node(Course &aCourse) :
            Node() {
        course = aCourse;
    }
};

//============================================================================
// Binary Search Tree class definition
//============================================================================

class BinarySearchTree {

private:
    Node* root;

    void addNode(Node* node, Course course);
    void inOrder(Node* node);

public:
    BinarySearchTree();
    virtual ~BinarySearchTree();
    void InOrder();
    void Insert(Course course);
    Course Search(string courseId);
};

/**
 * Default constructor
 */
BinarySearchTree::BinarySearchTree() {
    root = nullptr;
}

/**
 * Destructor
 */
BinarySearchTree::~BinarySearchTree() {
    // recurse from root deleting every node
}

/**
 * Traverse the tree in order
 */
void BinarySearchTree::InOrder() {
    this->inOrder(root);
}

/**
 * Insert a course
 */
void BinarySearchTree::Insert(Course course) {
    // If root equal to null ptr
    if (root == nullptr) {
        // Create new node
        root = new Node(course);
    }
    else {
        // Call addNode
        this->addNode(root, course);
    }
}

/**
 * Search for a course
 */
Course BinarySearchTree::Search(string courseId) {

    Node* current = root;

    while (current != nullptr) {
        // If current node matches
        if (current->course.courseId == courseId) {
            return current->course;
        }
        // If current is smaller
        if (current->course.courseId.compare(courseId) < 0) {
            current = current->left;
        }
            // Current is larger
        else {
            current = current->right;
        }
    }

    Course course;
    return course;
}

/**
 * Add a bid to some node (recursive)
 *
 * @param node Current node in tree
 * @param course Course to be added
 */
void BinarySearchTree::addNode(Node* node, Course course) {
    // If node is smaller
    if (course.courseId.compare(node->course.courseId) < 0) {
        if (node->left == nullptr) {
            node->left = new Node(course);
        }
            //Node exists call method with node->left
        else {
            this->addNode(node->left, course);
        }
    }
        // Node is larger
    else if (course.courseId.compare(node->course.courseId) > 0) {
        if (node->right == nullptr) {
            node->right = new Node(course);
        }
            //Node exists call method with node->right
        else {
            this->addNode(node->right, course);
        }
    }

}

void BinarySearchTree::inOrder(Node* node) {

    if (node == nullptr)
        return;

    inOrder(node->left);

    cout << node->course.courseId << "," << node->course.courseName << endl;

    inOrder(node->right);

}

/**
 * Display the bid information to the console (std::out)
 *
 * @param bid struct containing the bid info
 */
void displayCourse(Course &course) {
    cout << course.courseId << ", " << course.courseName << endl;
    cout << "Prerequisites: " << course.coursePrereq << endl;
}

int main() {

    // Define a binary search tree to hold all bids
    BinarySearchTree* bst;
    bst = new BinarySearchTree();
    Course course;
    string courseKey;

    string csvCourseId;
    string csvCourseName;
    string csvCoursePrereq;
    ifstream courseFile;

    int choice = 0;
    while (choice != 9) {
        cout << "Menu:" << endl;
        cout << "  1. Load Data Structure" << endl;
        cout << "  2. Print Course List" << endl;
        cout << "  3. Print Course" << endl;
        cout << "  9. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

            case 1:

                courseFile.open("course_list.csv");

                if (courseFile.is_open()) {

                    while (!courseFile.eof()) {
                        string line;
                        getline(courseFile, line);
                        stringstream lineStream(line);
                        string courseInfo;

                        while (lineStream.good()) {
                            getline(lineStream, csvCourseId, ',');
                            getline(lineStream, csvCourseName);

                            size_t pos = 0;
                            string splitPoint = ",";

                            if ((pos = csvCourseName.find(splitPoint)) != string::npos) {
                                csvCourseName = csvCourseName.substr(0, pos);
                                csvCoursePrereq = csvCourseName.substr(0, pos + splitPoint.length());
                            }
                            else {
                                csvCoursePrereq = "";
                            }

                            Course csvCourse(csvCourseId, csvCourseName, csvCoursePrereq);
                            bst->Insert(csvCourse);
                        }
                    }
                }

                courseFile.close();
                break;

            case 2:
                bst->InOrder();
                break;

            case 3:

                cout << "What course do you want to know about?  ";
                cin >> courseKey;
                course = bst->Search(courseKey);

                if (!course.courseId.empty()) {
                    displayCourse(course);
                } else {
                    cout << "Course Id " << courseKey << " not found." << endl;
                }
                break;

            default:

                cout << "Incorrect Menu Choice." << endl;

                break;

        }
    }

    cout << "Good bye." << endl;

    return 0;
}