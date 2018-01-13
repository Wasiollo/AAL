//
// Created by Wasiollo on 07.11.17.
//

#include "Alghoritms.h"

#include <iostream>
#include <unordered_map>

using Edges = std::unordered_map<int, int>;
using Graph = std::vector<Edges>;


int Alghoritms::min(int x, int y) {
    if (x < y)
        return x;
    else
        return y;
}

int Alghoritms::brutalAlgoritm(std::vector<char> buffer) {
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

int Alghoritms::fourTreeChange(std::vector<char> buffer, int i, Worker worker, char letter) {
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

int Alghoritms::alternativeAlghoritm(std::vector<char> buffer) {

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

Alghoritms::Alghoritms() {};

bool Alghoritms::isWorkerLetter(int i, char letter) {
    switch (letter) {
        case 'A':
            return i == 0 || i == 1 || i == 2;
        case 'B':
            return i == 0 || i == 3 || i == 4;
        case 'C':
            return i == 1 || i == 3 || i == 5;
        case 'D':
            return i == 2 || i == 4 || i == 5;
    }
}

void Alghoritms::dynamicProgramming(std::vector<char> buffer) {
    int n = 6 * buffer.size() + 2;
    int weight;

    Graph graph = Graph(n);

    if (buffer[0] == 'A' || buffer[0] == 'B')
        weight = 5;
    else
        weight = 10;
    graph[0].emplace(1, weight);
    for (int i = 2; i <= 6; ++i)
        graph[0].emplace(i, 10);


    for (int i = 1, l = 1; i < (buffer.size() - 1) * 6; i += 6, ++l) {
        for (int j = 0; j < 6; ++j)
            for (int k = 0; k < 6; ++k) {
                if (j == k && isWorkerLetter(j, buffer[l]))
                    weight = 5;
                else
                    weight = 10;
                graph[i + j].emplace(i + 6 + k, weight);
            }

    }

    for (int i = 7; i > 1; --i)
        graph[n - i].emplace(n - 1, 0);

//Budowanie grafu z kosztem liniowym

    std::vector<int> optPathCosts(n, 0);
    std::vector<int> optPathReconstruct(n, 0);
    optPathCosts[n - 1] = 0;


    for (int i = n - 2; i >= 0; --i) {
        const Edges &edges = graph[i]; // dla optymalności, żeby nie wyłuskiwac cały czas po indeksie

        auto iterator = edges.begin();

        int mincost = optPathCosts[iterator->first]; // pobieramy koszt pierwszego sąsiada z brzegu
        int best_neighbor = iterator->first; // ... i jego numer

        ++iterator;

        for (; iterator != edges.end(); ++iterator) {
            //second to wartość kosztu krawędzi z mapy
            int cost = optPathCosts[iterator->first] + iterator->second;

            if (cost < mincost) {
                mincost = cost;
                best_neighbor = iterator->first;

            }
        }

        optPathCosts[i] = mincost;
        optPathReconstruct[i] = best_neighbor;
    }
    for (int optPathCost : optPathCosts)
        std::cout << optPathCost << std::endl;

}
