#pragma once

#include "Cargo.hpp"

constexpr auto maxPercentage = 96;
constexpr size_t alcoholBasePriceFor96percent = 100u;

class Alcohol : public Cargo {
public:
    static size_t alcoholBasePriceFor96percent_;

    Alcohol(std::string name, size_t amount, unsigned char percentage);
    ~Alcohol() override = default;

    bool operator==(const Cargo& other) const override;

    size_t getPrice() const override;

protected:
    unsigned char percentage_ = 0;

private:
    std::unique_ptr<Cargo> createAmountOfEqual(size_t amount) override;
};
