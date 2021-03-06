#ifndef JEOPARDY_ANSWER_SCREEN_H
#define JEOPARDY_ANSWER_SCREEN_H

#include <chrono>
#include <mutex>

#include "game_state.hpp"

class answer_screen : public game_state
{
private:
    std::list<player*> buzzorder;
    answer *selected_answer;
    std::chrono::time_point<std::chrono::high_resolution_clock> start;
    std::recursive_mutex buzzorder_mutex;
public:
    answer_screen(answer *selected_answer, struct game_state_params *params);
    answer_screen(const rapidjson::GenericValue<rapidjson::UTF8<>> &, struct game_state_params *params);
    virtual ~answer_screen() = default;
    virtual void initialize();
    virtual bool process_event(const rapidjson::GenericValue<rapidjson::UTF8<>> &event);
    virtual bool on_buzz(const buzzer &);
    virtual void current_state(rapidjson::Document &);
    virtual void current_state(rapidjson::Document &, bool send_data);
    virtual void store_state(rapidjson::Document &);
    void make_buzzorder(rapidjson::GenericValue<rapidjson::UTF8<>> &, rapidjson::Document::AllocatorType &);
};

#endif //JEOPARDY_ANSWER_SCREEN_H
