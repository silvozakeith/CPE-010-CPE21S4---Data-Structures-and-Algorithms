#include "Printer.h"
#include <iostream>

Printer::~Printer() {
    while (!isEmpty()) {
        processNextJob();
    }
}

bool Printer::isEmpty() const {
    return frontPtr == nullptr;
}

// Interface to add new print jobs
void Printer::addJob(int id, const std::string& userName, int pages) {
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

// Process a single job at the head of the queue
void Printer::processNextJob() {
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

// Interface to process all remaining jobs added so far
void Printer::processAllJobs() {
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

// Display current status of pending jobs in queue
void Printer::displayQueue() const {
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