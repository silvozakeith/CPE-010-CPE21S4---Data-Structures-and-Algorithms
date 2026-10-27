#ifndef PRINTER_H
#define PRINTER_H

#include "Node.h"
#include <string>

// Create a class called Printer using First-Come, First-Served strategy
class Printer {
private:
    Node* frontPtr{nullptr};
    Node* backPtr{nullptr};
    int jobCount{0};

public:
    Printer() = default;
    ~Printer();

    // Prevent copy operations
    Printer(const Printer&) = delete;
    Printer& operator=(const Printer&) = delete;

    bool isEmpty() const;
    void addJob(int id, const std::string& userName, int pages);
    void processNextJob();
    void processAllJobs();
    void displayQueue() const;
};

#endif 