#include "GameController.h"
#include <iostream>

GameController::GameController(GameMode mode)
    : game_(mode) {}

void GameController::run() {
    while (!game_.isGameOver()) {
        view_.draw(game_);
        handleTurn();
    }

    view_.draw(game_);
}

void GameController::handleTurn() {
    // TODO 6：
    // 1. 根据当前玩家和游戏模式，选择 HumanPlayer 或 AIPlayer
    // 2. 调用 play 获取坐标
    // 3. 调用 game_.makeMove(row, col)
    // 4. 如果落子失败，提示重新输入

    bool moveSuccess = false;

    while (!moveSuccess) {
        Player* player = nullptr;

        if (game_.getCurrentPlayer() == CellState::X) {
            player = &game_.getHumanX();
        }
        else if (game_.getMode() == GameMode::HumanVsAI) {
            player = &game_.getAIPlayer();
        }
        else {
            player = &game_.getHumanO();
        }

        auto [row, col] = player->play(game_.getBoard());

        moveSuccess = game_.makeMove(row, col);

        if (!moveSuccess) {
            std::cout << "落子失败，请重新输入。\n";
        }
    }
}
