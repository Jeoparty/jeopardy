#include "invalid_json.hpp"

using namespace std;

invalid_json::invalid_json(valijson::ValidationResults results)
    : errors(results.numErrors())
{
    for (size_t i = 0;i < results.numErrors();i++)
    {
        results.popError(errors[i]);
    }
}

invalid_json::invalid_json(valijson::ValidationResults::Error error)
    : errors({error})
{
    // Nothing to do
}

invalid_json::invalid_json(string error_message)
    : errors({valijson::ValidationResults::Error({"no context"}, error_message)})
{
    // Noting to do
}

const char* invalid_json::what() const noexcept
{
    string what_data = "";
    for (const valijson::ValidationResults::Error &error : errors)
    {
        what_data += error.description + "\nin\n";
        for (const std::string &context : error.context)
        {
            what_data += context + "\n";
        }
        what_data += "\n";
    }
    what_data.pop_back();
    what_data.pop_back();
    return what_data.c_str();
}

const std::vector<valijson::ValidationResults::Error> & invalid_json::get_errors() const
{
    return errors;
}