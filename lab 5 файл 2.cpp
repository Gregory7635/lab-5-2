#include <iostream>
#include <string>
struct Book {
    int udcNumber;                  
    std::string author;             
    std::string title;              
    int year;                       
    int copies;                    

    // Конструктор для инициализации объекта книги заданными значениями.
    Book(int udc, std::string auth, std::string t, int y, int c) : udcNumber(udc), author(auth), title(t), year(y), copies(c) {}
};

// Определение класса для бинарного дерева поиска для хранения объектов книг.
class BinarySearchTree {
private:
    // Определение структуры для узла в бинарном дереве поиска, содержащей объект книги и указатели на левого и правого потомков.
    struct Node {
        Book book;                  // Книга, хранящаяся в узле
        Node* left;                 // Указатель на левого потомка
        Node* right;                // Указатель на правого потомка

        // Конструктор для инициализации объекта узла с заданной книгой и nullptr для левого и правого потомков.
        Node(Book b) : book(b), left(nullptr), right(nullptr) {}
    };

    Node* root;                     // Указатель на корневой узел бинарного дерева поиска

    // Функция для вставки книги в бинарное дерево поиска рекурсивно.
    Node* insert(Node* node, Book book) {
        if (node == nullptr) {
            return new Node(book);  // Если узел пуст, создаем новый узел с заданной книгой.
        }

        // Если год книги для вставки меньше года книги в текущем узле, вставляем в левое поддерево.
        if (book.year < node->book.year) {
            node->left = insert(node->left, book);
        }
        else {                    // Иначе вставляем в правое поддерево.
            node->right = insert(node->right, book);
        }

        return node;                
    }

    // Функция для выполнения обхода дерева в порядке "внутренний обход" и вывода книг, отсортированных по году.
    void inOrderTraversal(Node* node) {
        if (node != nullptr) {
            inOrderTraversal(node->left);               // Обходим левое поддерево.
            // Выводим детали книги в текущем узле.
            std::cout << "UDC номер: " << node->book.udcNumber << ", Автор: " << node->book.author << ", Название: " << node->book.title << ", Год: " << node->book.year << ", Копии: " << node->book.copies << std::endl;
            inOrderTraversal(node->right);              // Обходим правое поддерево.
        }
    }

public:
    // Конструктор для инициализации бинарного дерева поиска с нулевым корнем.
    BinarySearchTree() : root(nullptr) {}

    // Функция для добавления книги в бинарное дерево поиска.
    void addBook(Book book) {
        root = insert(root, book);      // Вставляем книгу в бинарное дерево поиска.
    }

    // Функция для отображения книг в библиотеке, отсортированных по году с помощью обхода в порядке "внутренний обход".
    void displayBooksByYear() {
        inOrderTraversal(root);         // Выполняем обход в порядке "внутренний обход" для отображения книг в библиотеке, отсортированных по году.
    }
};

// Главная функция, где создается бинарное дерево поиска, добавляются книги и затем отображаются, отсортированные по году.
int main() {
    setlocale(LC_ALL, "RU");
    BinarySearchTree library;           // Создаем бинарное дерево поиска с именем библиотеки.

    // Создаем объекты книг, представляющие разные книги.
    Book book1(1234, "John Smith", "Programming 101", 2010, 5);
    Book book2(5678, "Alice Johnson", "Data Structures", 2008, 3);
    Book book3(9012, "Emily Brown", "Algorithms", 2015, 7);

    // Добавляем книги в бинарное дерево поиска библиотеки.
    library.addBook(book1);
    library.addBook(book2);
    library.addBook(book3);

    // Выводим заголовок, указывающий список книг, отсортированных по году.
    std::cout << "Книги в библиотеке, отсортированные по году:" << std::endl;
    library.displayBooksByYear();      

    return 0;                           
}
