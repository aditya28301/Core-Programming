#include <string>
#include <mutex>

class Player {
    std::string name;
    int score;
    std::mutex mtx;

public:
    Player(const std::string& name) : name(name), score(0) {}

    std::string getName() const { return name; }

    int getScore() {
        std::lock_guard<std::mutex> lock(mtx);
        return score;
    }

    void incrementScore() {
        std::lock_guard<std::mutex> lock(mtx);
        score++;
    }
};

#include <iostream>
#include <vector>
#include <random>
#include <thread>
#include <algorithm>
#include <chrono>

class Game {
    std::vector<Player*> players;
    std::mt19937 rng;

public:
    Game() {
        rng.seed(std::random_device{}());
    }

    void addPlayer(Player* p) {
        players.push_back(p);
    }

    void playRound(int roundNum) {
        std::uniform_int_distribution<int> dist(0, 4);
        int correctNumber = dist(rng);
        std::cout << "\n🎯 Round " << roundNum + 1 << " - Number to guess: [HIDDEN]\n";

        std::vector<std::thread> threads;

        for (auto& player : players) {
            threads.emplace_back([player, correctNumber]() {
                std::this_thread::sleep_for(std::chrono::milliseconds(1000)); // Simulate time
                int guess = rand() % 5;
                std::cout << "🧑 " << player->getName() << " guessed: " << guess << "\n";
                if (guess == correctNumber) {
                    player->incrementScore();
                    std::cout << "✅ Correct!\n";
                } else {
                    std::cout << "❌ Wrong\n";
                }
            });
        }

        for (auto& t : threads) {
            t.join();  // Wait for all player threads to finish
        }
    }

    void playGame() {
        for (int round = 0; round < 5; ++round) {
            playRound(round);
        }
    }

    void showLeaderboard() {
        std::vector<Player*> leaderboard = players;
        std::sort(leaderboard.begin(), leaderboard.end(), [](Player* a, Player* b) {
            return a->getScore() > b->getScore();
        });

        std::cout << "\n🏆 Leaderboard:\n";
        for (auto& p : leaderboard) {
            std::cout << p->getName() << " : " << p->getScore() << " points\n";
        }
    }
};

int main() {
    Game game;

    Player p1("Alice");
    Player p2("Bob");
    Player p3("Charlie");

    game.addPlayer(&p1);
    game.addPlayer(&p2);
    game.addPlayer(&p3);

    game.playGame();
    game.showLeaderboard();

    return 0;
}

