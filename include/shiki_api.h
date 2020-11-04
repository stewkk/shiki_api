
#include <curl/curl.h>
#include <string>
#include <iostream>

class Shiki {
public:
    Shiki(std::string user);
    ~Shiki();
    std::string api_users_id_anime_rates(int page, int limit, std::string status, bool censored);
private:
    CURL* curl;
    std::string shiki_api_domain = "https://shikimori.one/";
    std::string shiki_api_user;
};

