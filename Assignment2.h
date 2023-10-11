#ifndef Assignment2_H
#define Assignment2_H

#include <iostream>

// ----------- Single_Linked_List Declaration --------------
template <typename Item_Type>
class Single_Linked_List {
private:
    // Node structure for Single Linked List
    struct Node {
        Item_Type data;
        Node* next;
        Node(const Item_Type& data_item, Node* next_ptr = nullptr)
            : data(data_item), next(next_ptr) {}
    };
    Node* head;
    Node* tail;
    size_t num_items;

public:
    // Constructor
    Single_Linked_List();

    // Destructor
    ~Single_Linked_List();

    // Insert element at the beginning
    void push_front(const Item_Type& item);

    // Insert element at the end
    void push_back(const Item_Type& item);

    // Remove first element
    bool pop_front();

    // Remove last element
    bool pop_back();

    // Get the first element
    Item_Type front() const;

    // Get the last element
    Item_Type back() const;

    // Check if list is empty
    bool empty() const;

    // Insert item at specific index
    void insert(size_t index, const Item_Type& item);

    // Remove item at specific index
    bool remove(size_t index);

    // Find the first occurrence of an item
    size_t find(const Item_Type& item) const;

    // Get the number of elements in the list
    size_t size() const;
};

// ----------- Single_Linked_List Implementation --------------

template <typename Item_Type>
Single_Linked_List<Item_Type>::Single_Linked_List() : head(nullptr), tail(nullptr), num_items(0) {}

template <typename Item_Type>
Single_Linked_List<Item_Type>::~Single_Linked_List() {
    while (!empty()) {
        pop_front();
    }
}

template <typename Item_Type>
void Single_Linked_List<Item_Type>::push_front(const Item_Type& item) {
    head = new Node(item, head);
    if (!tail) {
        tail = head;
    }
    num_items++;
}

template <typename Item_Type>
void Single_Linked_List<Item_Type>::push_back(const Item_Type& item) {
    Node* new_tail = new Node(item);
    if (tail) {
        tail->next = new_tail;
    }
    else {
        head = new_tail;
    }
    tail = new_tail;
    num_items++;
}

template <typename Item_Type>
bool Single_Linked_List<Item_Type>::pop_front() {
    if (!head) return false;
    Node* temp = head;
    head = head->next;
    delete temp;
    --num_items;
    if (!head) tail = nullptr;
    return true;
}

template <typename Item_Type>
bool Single_Linked_List<Item_Type>::pop_back() {
    if (!tail) return false;
    if (head == tail) {
        delete head;
        head = tail = nullptr;
    }
    else {
        Node* prev = head;
        while (prev->next != tail) {
            prev = prev->next;
        }
        delete tail;
        tail = prev;
        tail->next = nullptr;
    }
    --num_items;
    return true;
}

template <typename Item_Type>
Item_Type Single_Linked_List<Item_Type>::front() const {
    return head->data;
}

template <typename Item_Type>
Item_Type Single_Linked_List<Item_Type>::back() const {
    return tail->data;
}

template <typename Item_Type>
bool Single_Linked_List<Item_Type>::empty() const {
    return head == nullptr;
}

template <typename Item_Type>
void Single_Linked_List<Item_Type>::insert(size_t index, const Item_Type& item) {
    if (index == 0) {
        push_front(item);
    }
    else if (index >= num_items) {
        push_back(item);
    }
    else {
        Node* prev = head;
        for (size_t i = 1; i < index; ++i) {
            prev = prev->next;
        }
        prev->next = new Node(item, prev->next);
        num_items++;
    }
}

template <typename Item_Type>
bool Single_Linked_List<Item_Type>::remove(size_t index) {
    if (index == 0) {
        return pop_front();
    }
    else if (index >= num_items) {
        return false;
    }
    else {
        Node* prev = head;
        for (size_t i = 1; i < index; ++i) {
            prev = prev->next;
        }
        Node* to_remove = prev->next;
        prev->next = to_remove->next;
        delete to_remove;
        if (prev->next == nullptr) {
            tail = prev;
        }
        --num_items;
        return true;
    }
}

template <typename Item_Type>
size_t Single_Linked_List<Item_Type>::find(const Item_Type& item) const {
    Node* current = head;
    size_t index = 0;
    while (current) {
        if (current->data == item) {
            return index;
        }
        current = current->next;
        index++;
    }
    return num_items;
}

template <typename Item_Type>
size_t Single_Linked_List<Item_Type>::size() const {
    return num_items;
}


// ----------- Employee Declaration --------------

class Employee {
protected:
    double hourly_rate;
    double weekly_hours;

public:
    Employee(double rate, double hours);
    virtual ~Employee() {}

    virtual double calculate_weekly_salary() const = 0;
    virtual double health_care_contributions() const = 0;
    virtual double vacation_days_earned() = 0;
};

class Professional : public Employee {
private:
    double monthly_salary;
    double days_of_vacation;

public:
    Professional(double salary, double vacationDays);

    double calculate_weekly_salary() const override;
    double health_care_contributions() const override;
    double vacation_days_earned() override;
};

class NonProfessional : public Employee {
private:
    double total_worked_hours;

public:
    NonProfessional(double rate, double hours);

    double calculate_weekly_salary() const override;
    double health_care_contributions() const override;
    double vacation_days_earned() override;
};

#endif
