#include "stats.h"

Stats::Stats() {
    methods = {
            {"GET", 0},
            {"PUT", 0},
            {"POST", 0},
            {"DELETE", 0},
            {"UNKNOWN", 0}
    };

    uries = {
            {"/", 0},
            {"/order", 0},
            {"/product", 0},
            {"/basket", 0},
            {"/help", 0},
            {"unknown", 0}
    };
}

void Stats::AddMethod(string_view method) {
    if (methods.find(method) != methods.end()) {
        methods[method]++;
    } else {
        methods[string_view("UNKNOWN")]++;
    }
}

void Stats::AddUri(string_view uri) {
    if (uries.find(uri) != uries.end()) {
        uries[uri]++;

    } else {
        uries[string_view("unknown")]++;
    }
}

const map<string_view, int>& Stats::GetMethodStats() const {
    return methods;
}

const map<string_view, int>& Stats::GetUriStats() const {
    return uries;
}

HttpRequest ParseRequest(string_view line) {
    HttpRequest request;

    size_t pos = 0;
    while (line[pos] == ' ' && pos != std::string_view::npos) {
        ++pos;
    }
    line.remove_prefix(pos);

    size_t delimiter = line.find(' ');
    request.method = line.substr(0, delimiter);

    line.remove_prefix(++delimiter);
    delimiter = line.find(' ');
    request.uri = line.substr(0, delimiter);

    line.remove_prefix(++delimiter);
    request.protocol = line;

    return request;
}