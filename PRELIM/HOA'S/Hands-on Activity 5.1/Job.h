#ifndef JOB_H
#define JOB_H

#include <string>
#include <utility>

// Create a class called Job
class Job {
public:
    int id;
    std::string userName;
    int pages;

    explicit Job(int jobId = 0, std::string name = "", int numPages = 0)
        : id(jobId), userName(std::move(name)), pages(numPages) {}
};

#endif 