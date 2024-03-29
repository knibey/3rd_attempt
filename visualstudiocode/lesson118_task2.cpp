#include <algorithm>
#include <array>
#include <iostream>
#include <string_view>

struct Season
{
    std::string_view name{};
    double averageTemperature{};
};

int mainlesson118_task2()
{
    std::array<Season, 4> seasons{
      { { "Spring", 285.0 },
        { "Summer", 296.0 },
        { "Fall", 288.0 },
        { "Winter", 263.0 } }
    };

    std::sort(seasons.begin(), seasons.end(),
        [](const auto& x, const auto& y){
            return (x.averageTemperature < y.averageTemperature);
        });

    for (const auto& season : seasons)
    {
        std::cout << season.name << '\n';
    }

    return 0;
}