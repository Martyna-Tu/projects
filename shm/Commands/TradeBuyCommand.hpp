#pragma once

#include "Command.hpp"
#include "../GeneralPrint.hpp"

class TradeBuy : public Command {
public:
    TradeBuy() = default;
    void operator()(Player& player, Store& store) override {
        while (true) {
            size_t limit = 0;

            printStoreCargoList(store);
            printPlayerStatus(player);

            std::cout << "Which Cargo want to Buy from store?\n";
            limit = store.getCargoVec().size();
            auto chose = ChoseOption(limit);
            if (chose >= limit) {
                return;
            }
            const Cargo* const cargo = ChoseCargoFromStore(chose, store);

            std::cout << "Amount:\n";
            limit = player.getMoney() / cargo->getPrice();
            limit = std::min(limit, cargo->getAmount()) + 1;
            size_t amount = ChoseOption(limit);
            if (amount >= limit) {
                return;
            }
            
            Response response = store.sell(cargo, amount, &player);
            printResponse(response);
        }
    }

    std::string getName() const override { return "Buy"; }
};
