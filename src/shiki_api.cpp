
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

static size_t WriteCallbackToString(void* contents, size_t size, size_t nmemb, void* userp) {
	((std::string*)userp)->append((char*)contents, size * nmemb);
	return size * nmemb;
}

std::string Shiki::api_users_id_anime_rates(std::string status, int limit, int page, bool censored) {
    std::string ans;
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &ans);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallbackToString);
    curl_easy_setopt(curl, CURLOPT_URL, (shiki_api_domain + "api/users/" + shiki_api_user + "/anime_rates" + 
            "?page=" + std::to_string(page) + "&limit=" + std::to_string(limit) + "&status=" + status + 
            "&censored=" + (censored ? "true" : "false")).c_str());
    curl_easy_perform(curl);
    return ans;
}

