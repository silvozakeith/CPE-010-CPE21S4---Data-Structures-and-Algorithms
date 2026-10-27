#include <iostream>
#include <string>
#include <utility>

// Class Job
class Job {
public:
    int id;
    std::string userName;
    int pages;

    explicit Job(int jobId = 0, std::string name = "", int numPages = 0)
        : id(jobId), userName(std::move(name)), pages(numPages) {}
};

// Custom Node for Linked List
struct Node {
    Job job;
    Node* next;

    explicit Node(Job j) : job(std::move(j)), next(nullptr) {}
};

// Class Printer using First-Come, First-Served strategy
class Printer {
private:
    Node* frontPtr{nullptr};
    Node* backPtr{nullptr};
    int jobCount{0};

public:
    Printer() = default;

    ~Printer() {
        while (!isEmpty()) {
            processNextJob();
        }
    }

    Printer(const Printer&) = delete;
    Printer& operator=(const Printer&) = delete;

    bool isEmpty() const {
        return frontPtr == nullptr;
    }

    void addJob(int id, const std::string& userName, int pages) {
        Job newJob(id, userName, pages);
        auto* newNode = new Node(newJob);

        if (isEmpty()) {
            frontPtr = newNode;
            backPtr = newNode;
        } else {
            backPtr->next = newNode;
            backPtr = newNode;
        }
        jobCount++;

        std::cout << "[JOB SUBMITTED] ID: " << id 
                  << " | User: " << userName 
                  << " | Pages: " << pages 
                  << " (Pending in queue: " << jobCount << ")\n";
    }

    void processNextJob() {
        if (isEmpty()) {
            std::cout << "[PRINTER IDLE] No pending jobs to process.\n";
            return;
        }

        Node* tempPtr = frontPtr;
        Job j = tempPtr->job;

        std::cout << "[PRINTING...] Processing Job ID: " << j.id 
                  << " | User: " << j.userName 
                  << " | Printing " << j.pages << " page(s)... [COMPLETED]\n";

        if (frontPtr == backPtr) {
            frontPtr = nullptr;
            backPtr = nullptr;
        } else {
            frontPtr = frontPtr->next;
        }

        delete tempPtr;
        jobCount--;
    }

    void processAllJobs() {
        std::cout << "\n--- Starting Batch Job Processing ---\n";
        if (isEmpty()) {
            std::cout << "Queue is empty. Printer is idle.\n";
            return;
        }

        while (!isEmpty()) {
            processNextJob();
        }
        std::cout << "--- All Print Jobs Successfully Completed ---\n\n";
    }

    void displayQueue() const {
        if (isEmpty()) {
            std::cout << "\n[QUEUE STATUS] Queue is empty.\n\n";
            return;
        }

        std::cout << "\n--- Current Pending Print Queue ---\n";
        Node* curr = frontPtr;
        int pos = 1;
        while (curr != nullptr) {
            std::cout << pos++ << ". Job ID: " << curr->job.id 
                      << " | User: " << curr->job.userName 
                      << " | Pages: " << curr->job.pages << "\n";
            curr = curr->next;
        }
        std::cout << "Total pending jobs: " << jobCount << "\n-----------------------------------\n\n";
    }
};

int main() {
    Printer sharedPrinter;

    std::cout << "=====================================================\n";
    std::cout << "    ILO C: SHARED PRINTER SIMULATION USING QUEUE     \n";
    std::cout << "=====================================================\n\n";

    // 1. Multiple users submit jobs
    std::cout << "--- Phase 1: Users submitting initial print requests ---\n";
    sharedPrinter.addJob(101, "KEITH", 12);
    sharedPrinter.addJob(102, "NICOLE", 5);
    sharedPrinter.addJob(103, "BONDOC", 25);
    sharedPrinter.addJob(104, "SILVOZA", 3);

    // 2. View queue status
    sharedPrinter.displayQueue();

    // 3. Printer processes jobs one by one
    std::cout << "--- Phase 2: Printer begins servicing jobs ---\n";
    sharedPrinter.processNextJob();
    sharedPrinter.processNextJob();

    // 4. View queue status after initial processing
    sharedPrinter.displayQueue();

    // 5. New user submits job mid-operation
    std::cout << "--- Phase 3: New incoming print request ---\n";
    sharedPrinter.addJob(105, "STAR", 8);

    // 6. Printer processes remaining batch
    sharedPrinter.processAllJobs();

    return 0;
}