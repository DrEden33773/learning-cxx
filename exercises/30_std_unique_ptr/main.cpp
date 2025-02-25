﻿#include "../exercise.h"
#include <algorithm>
#include <cstring>
#include <memory>
#include <string>
#include <vector>


// READ: `std::unique_ptr` <https://zh.cppreference.com/w/cpp/memory/unique_ptr>

std::vector<std::string> RECORDS;

class Resource {
    std::string _records;

public:
    void record(char record) {
        _records.push_back(record);
    }

    ~Resource() {
        RECORDS.push_back(_records);
    }
};

using Unique = std::unique_ptr<Resource>;
Unique reset(Unique ptr) {
    if (ptr) {
        ptr->record('r');
    }
    return std::make_unique<Resource>();
}
Unique drop(Unique ptr) {
    if (ptr) {
        ptr->record('d');
    }
    return nullptr;
}
Unique forward(Unique ptr) {
    if (ptr) {
        ptr->record('f');
    }
    return ptr;
}

int main(int argc, char **argv) {
    std::vector<std::string> problems[3];

    drop(
        forward(
            reset(nullptr)// A
            )             // A."f"
    );                    // A."d" -> x
    // {"fd"}
    problems[0] = std::move(RECORDS);

    forward(
        drop(
            reset(
                forward(
                    forward(
                        reset(nullptr)// B
                        )             // B."f"
                    )                 // B."f"
                )                     // B."r" -> C
            )                         // C."d" -> D
    );                                // D."f"
    // {"ffr", "d"}.reverse()
    problems[1] = std::move(RECORDS);

    drop(
        drop(
            reset(
                drop(
                    reset(
                        reset(nullptr)// E
                        )             // E."r" -> F
                    )                 // F."d" -> nullptr
                )                     // G
            )                         // G."d" -> nullptr
    );                                // nullptr
    // {"r", "d", "d"}.reverse()
    problems[2] = std::move(RECORDS);

    // 上面的 `.reverse()` 是必要的, 因为析构顺序与构造顺序相反

    // ---- 不要修改以上代码 ----

    std::vector<const char *> answers[]{
        {
            "fd",
        },
        // TODO: 分析 problems[1] 中资源的生命周期，将记录填入 `std::vector`
        {
            "d",
            "ffr",
        },
        {
            "d",
            "d",
            "r",
        },
    };

    // ---- 不要修改以下代码 ----

    for (auto i = 0; i < 3; ++i) {
        ASSERT(problems[i].size() == answers[i].size(), "wrong size");
        for (auto j = 0; j < problems[i].size(); ++j) {
            ASSERT(std::strcmp(problems[i][j].c_str(), answers[i][j]) == 0, "wrong location");
        }
    }

    // D -> x

    return 0;
}
