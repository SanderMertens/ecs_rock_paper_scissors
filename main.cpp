#include <iostream>
#include "flecs.h"

int main() {    
    flecs::world ecs;

    srand (time(NULL));

    auto beats    = ecs.entity();
    auto rock     = ecs.entity("rock");
    auto paper    = ecs.entity("paper").add(beats, rock);
    auto scissors = ecs.entity("scissors").add(beats, paper);
    rock.add(beats, scissors);

    std::string in; std::cout << "rock, paper, scissors? "; std::cin >> in;

    auto player = ecs.lookup(in.c_str());
    if (!player) {
        std::cout << "invalid input!" << std::endl;
        return 0;
    }

    auto ai = ((flecs::entity[]){rock, paper, scissors})[rand() % 3];
    if (player == ai) {
        std::cout << "AI is " << ai.name() << ", tie!" << std::endl;
    } else if (player.has(beats, ai)) {
        std::cout << "AI is " << ai.name() << ", you win!" << std::endl;
    } else {
        std::cout << "AI is " << ai.name() << ", you lose!" << std::endl;
    }

    return 0;
}
