#ifndef JEOPARDY_PLAYER_H
#define JEOPARDY_PLAYER_H

#include <string>
#include <chrono>

#include <rapidjson/document.h>

#include "color.hpp"
#include "mediator/buzzer.hpp"

class player
{
private:
    std::string id;
    std::string name;
    color c;
    int score;
    bool connected;
    buzzer mybuzzer;
    bool buzzed;
    std::chrono::duration<int, std::milli> buzztime;
public:
    player(std::string id, std::string name, color, const buzzer &);
    player(const rapidjson::GenericValue<rapidjson::UTF8<>> &);
    void set_buzztime(const std::chrono::duration<int, std::milli> &);
    void reset_buzztime();
    void add_score(int score);
    void set_score(int score);
    void set_buzzer(const buzzer &);
    void disconnect();
    const std::string & get_id() const;
    const std::string & get_name() const;
    const color & get_color() const;
    int get_score() const;
    bool is_connected() const;
    const buzzer & get_buzzer() const;
    bool has_buzzed() const;
    const std::chrono::duration<int, std::milli> & get_buzztime() const;
    rapidjson::GenericValue<rapidjson::UTF8<>> buzzed_value() const;
    void store_state(rapidjson::GenericValue<rapidjson::UTF8<>> &, rapidjson::GenericValue<rapidjson::UTF8<>>::AllocatorType &) const;
};

#endif //JEOPARDY_PLAYER_H
