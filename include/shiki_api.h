
#include <curl/curl.h>
#include <string>
#include <iostream>

class Shiki {
public:
    Shiki();
    ~Shiki();
    std::string api_users_id_anime_rates(int page, int limit, std::string status, bool censored);
};

