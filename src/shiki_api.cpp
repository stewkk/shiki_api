
#include "shiki_api.h"

Shiki::Shiki(std::string user) {
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    shiki_api_user = user;
}

Shiki::~Shiki() {
    curl_easy_cleanup(curl);
    curl_global_cleanup();
}

std::string Shiki::api_users_id_anime_rates(int page, int limit, std::string status, bool censored) {
    std::string ans;
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &ans);
    curl_easy_setopt(curl, CURLOPT_URL, (shiki_api_domain + "api/users/" + shiki_api_user + "/anime_rates" + 
            "?page=" + std::to_string(page) + "&limit=" + std::to_string(limit) + "&status=" + status + 
            "&censored=" + (censored ? "true" : "false")).c_str());
    curl_easy_perform(curl);
    return ans;
}

