
#include <curl/curl.h>
#include <string>
#include <iostream>

class Shiki {
public:
    Shiki(std::string user);
    ~Shiki();
    std::string api_users_id_anime_rates(std::string status = "watching", int limit = 5000,
            int page = 1, bool censored = false);
private:
    CURL* curl;
    const std::string shiki_api_domain = "https://shikimori.one/";
    std::string shiki_api_user;
};
