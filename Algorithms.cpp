//
// Created by Wasiollo on 07.11.17.
//

#include "Algorithms.h"


Algorithms::Algorithms() = default;

int Algorithms::brutalAlgorithm(std::vector<char> buffer) {
    Worker worker('A', 'B');
    int i = 0;
    int countA, countB, countC, countD, minCount;
    countA = fourTreeChange(buffer, i, worker, 'A');
    countB = fourTreeChange(buffer, i, worker, 'B');
    countC = fourTreeChange(buffer, i, worker, 'C');
    countD = fourTreeChange(buffer, i, worker, 'D');
    minCount = min(min(min(countA, countB), countC), countD);
    return minCount;
}

int Algorithms::alternativeAlgorithm(std::vector<char> buffer) {

    Worker worker('A', 'B');
    int i, count, no, j;
    char firstMyLetter, firstNotMyLetter;
    count = i = 0;
    while (i < buffer.size()) {
        if (worker.isMyLetter(buffer.at(i))) {
            count += 5;
            ++i;

            continue;
        }
        no = 0;
        if (i + 1 < buffer.size())
            if (!worker.isMyLetter(buffer.at(i + 1))) {

                count += 10;
                firstNotMyLetter = buffer.at(i);
                ++i;

                while (buffer.at(i) == firstNotMyLetter) {
                    ++no;
                    ++i;
                    if (i >= buffer.size()) {
                        count += no * 5;
                        return count;
                    }
                }
                count += no * 5;

                worker.callWorker(firstNotMyLetter, buffer.at(i));
                continue;
            }

        if (i + 1 >= buffer.size()) {
            count += 10;
            break;
        }

        firstNotMyLetter = buffer.at(i);
        firstMyLetter = buffer.at(i + 1);

        count += 15;
        no = 0;
        i += 2;

        if (i < buffer.size()) {
            while (buffer.at(i) == firstMyLetter) {
                ++no;
                ++i;
                if (i >= buffer.size()) {
                    count += no * 5;
                    return count;
                }
            }
        } else {
            break;
        }

        count += no * 5;

        if (worker.isMyLetter(buffer.at(i)))
            continue;

        if (buffer.at(i) == firstNotMyLetter)
            worker.callWorker(firstMyLetter, firstNotMyLetter);
        else {
            j = 1;

            while (i + j < buffer.size()) {
                if (buffer.at(i + j) == firstMyLetter) {
                    ++j;
                    continue;
                }
                if (buffer.at(i + j) == firstNotMyLetter) {
                    worker.callWorker(firstMyLetter, firstNotMyLetter);
                    break;
                }
                if (!worker.isMyLetter(buffer.at(i + j)))
                    break;
                if (worker.isMyLetter(buffer.at(i + 1)) && buffer.at(i) != firstMyLetter)
                    break;
            }


        }

    }
    return count;

}

int Algorithms::dynamicProgramming(std::vector<char> buffer) {
    int n = 6 * buffer.size() + 2;

    Graph graph = this->generateGraph(buffer);

// Generating graph with linear (n) cost

    std::vector<int> optPathCosts(n, 0);
    std::vector<int> optPathReconstruct(n, 0);

    for (int i = n - 2; i >= 0; --i) {
        const Edges &edges = graph[i]; // for optimality, not to get the entire time by the index

        if (!edges.empty()) {

            auto iterator = edges.begin();

            int minCost = optPathCosts[iterator->first] + iterator->second; // cost of first neighbour
            int best_neighbor = iterator->first; // number of first neighbour

            ++iterator;

            for (; iterator != edges.end(); ++iterator) {
                int cost = optPathCosts[iterator->first] + iterator->second;

                if (cost < minCost) {
                    minCost = cost;
                    best_neighbor = iterator->first;
                }
            }

            optPathCosts[i] = minCost;
            optPathReconstruct[i] = best_neighbor;
        }
    }

    return optPathCosts[0];
}

int Algorithms::fourTreeChange(std::vector<char> buffer, int i, Worker worker, char letter) {
    int count, countA, countB, countC, countD;

    count = countA = countB = countC = countD = 0;

    while (i < buffer.size()) {
        if (worker.isMyLetter(buffer.at(i))) {
            count += 5;
            ++i;
            continue;
        }

        count += 10;
        ++i;
        if (buffer.at(i - 1) != letter) {
            worker.callWorker(buffer.at(i - 1), letter);
        }
        countA = fourTreeChange(buffer, i, worker, 'A');
        countB = fourTreeChange(buffer, i, worker, 'B');
        countC = fourTreeChange(buffer, i, worker, 'C');
        countD = fourTreeChange(buffer, i, worker, 'D');

        count += min(min(min(countA, countB), countC), countD);
        return count;
    }
    return count;
}

int Algorithms::min(int x, int y) {
    if (x < y)
        return x;
    else
        return y;
}

bool Algorithms::isWorkerLetter(int i, char letter) {
    switch (letter) {
        case 'A':
            return i == 0 || i == 1 || i == 2;
        case 'B':
            return i == 0 || i == 3 || i == 4;
        case 'C':
            return i == 1 || i == 3 || i == 5;
        case 'D':
            return i == 2 || i == 4 || i == 5;
        default:
            break;
    }
}

Graph Algorithms::generateGraph(std::vector<char> buffer) {
    int n = 6 * buffer.size() + 2;

    Graph graph = Graph(n);

    bool notFull = true;
    bool notFullLoop = false;

    if (buffer[0] == 'A' || buffer[0] == 'B')
        graph[0].emplace(1, 5);
    else {
        graph[0].emplace(1, 10);
        for (int i = 2; i <= 6; ++i)
            graph[0].emplace(i, 10);
        notFull = false;
    }

    std::vector<int> temp;
    for (int i = 1, l = 1; i < (buffer.size() - 1) * 6; i += 6, ++l) {
        for (int j = 0; j < 6; ++j) {
            if (notFullLoop)
                notFull = false;
            temp.clear();

            for (int k = 0; k < 6; ++k) {

                if (j == k && isWorkerLetter(j, buffer[l])) {
                    temp.clear();
                    graph[i + j].emplace(i + 6 + k, 5);
                    break;
                } else {
                    notFullLoop = true;
                    temp.push_back(10);
                }
            }
            if (!temp.empty())
                for (int k = 0; k < 6; ++k)
                    graph[i + j].emplace(i + 6 + k, 10);

            if (notFull)
                break;


        }
    }

    for (int i = 7; i > 1; --i)
        graph[n - i].emplace(n - 1, 0);

    return graph;
}
