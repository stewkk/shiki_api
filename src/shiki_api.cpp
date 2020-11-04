
#include "shiki_api.h"

Shiki::Shiki() {
    std::cout << "shiki_api init" << std::endl;
}

Shiki::~Shiki() {

}

std::string Shiki::api_users_id_anime_rates(int page, int limit, std::string status, bool censored) {
    std::cout << "get anime rated" << std::endl; 
    return "test";
}


