#include "cdbuild.h"

json data;
std::string name_cache_file;
void load(std::string language){
    std::string path_msg_cli = "language/package_" + language + "/cmd/message_cli.json";
    std::ifstream package_msg_cli(path_msg_cli);
    if(!package_msg_cli.is_open()){
        std::cerr << "[DEBUG | LOAD DATA] ERROR: Core cannot open json file data! PATH: " << path_msg_cli << std::endl;
        return;
    }else{
        std::cout << "[DEBUG | LOAD DATA] Core loaded json file data! PATH: " << path_msg_cli << std::endl;
    }
    package_msg_cli >> data;
}

void createCache(){
    json creCache;

    if(!std::filesystem::exists(name_cache_file)){
        // Prepare data
        creCache["core-language"] = "en"; // default mode

        std::ofstream filecache(name_cache_file);
        if(filecache.is_open()){
            filecache << creCache.dump();
            load("en");
            filecache.close();
        }else{
            std::cout << "[DEBUG | Create Cache] ERROR: Core created '" << name_cache_file << "' file but cannot open it!" << std::endl;
            return;
        }
    }else{
        std::cout << "[DEBUG | Create Cache] Cache file '" << name_cache_file << "' is exists. stop created!" << std::endl;
    }
    std::cout << "[DEBUG | Create Cache] Cache file '" << name_cache_file << "' is created!" << std::endl;
}

void ReCache(std::string language){
    json recache;

    if(std::filesystem::exists(name_cache_file)){
        std::ifstream readcache(name_cache_file);
        if(!readcache.is_open()){
            std::cout << "[DEBUG | Read & Change Cache] ERROR: Core cannot read '" << name_cache_file << "' file." << std::endl;
            return;
        }else{
            readcache >> recache;
            readcache.close();
        }

        recache["core-language"] = language;

        std::ofstream writecache(name_cache_file);
        writecache << recache.dump();
        writecache.close();
    }else{
        std::cout << "[DEBUG | Read & Change Cache] ERROR: Core cannot find '" << name_cache_file << "' file." << std::endl;
        std::cout << "[DEBUG | Read & Change Cache] AUTOMATIC REPAIR: Core will create '" << name_cache_file << "' file..." << std::endl;
        createCache();
    }
    std::cout << "[DEBUG | Read & Change Cache] Core rewrited '" << name_cache_file << "' file." << std::endl;
}

std::string readCache(){
    json readfile;
    if(std::filesystem::exists(name_cache_file)){
        std::ifstream readcache(name_cache_file);
        if(!readcache.is_open()){
            std::cerr << "[DEBUG | Read & Change Cache] ERROR: Core cannot read '" << name_cache_file << "' file." << std::endl;
            return "";
        }else{
            readcache >> readfile;
            readcache.close();
        }

        return readfile["core-language"].get<std::string>();
    }else{
        std::cout << "[DEBUG | Read & Change Cache] ERROR: Core cannot find '" << name_cache_file << "' file." << std::endl;
        std::cout << "[DEBUG | Read & Change Cache] AUTOMATIC REPAIR: Core will create '" << name_cache_file << "' file..." << std::endl;
        createCache();
        return "";
    }
}

void setupLang(const char* ARGV[]){
    std::string exeDir = std::filesystem::path(ARGV[0]).parent_path().string();
    name_cache_file = exeDir + "/CoreCache.json";

    load(readCache());
}

void setLanguage(const SetLanguage LS){
    switch(LS){
        case SetLanguage::EN:
            load("en");
            ReCache("en");
            break;
        case SetLanguage::VN:
            load("vi");
            ReCache("vi");
            break;
    }
}