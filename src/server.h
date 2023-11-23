#pragma once
#include <string>

#define MAXARR 10

struct Server
{
    struct Domain
    {
        std::string subject = "";
        std::string alternate = "";
    };

    struct Https
    {
        bool active = false;
        std::string include = "/etc/nginx/extra/default.https.conf";
        std::string filename = "site";
        std::string path = "var/local/step";
    };

    struct Location
    {

        bool active = false;
        std::string include = "";
        std::string path = "/";
        std::string type = "try_files";
        std::string value = "index.html";
        std::string other[MAXARR] = {};
    };

    struct Redirect
    {
        bool active = false;
        int value = 80;
        std::string other = "https://$host$request_uri";
    };

    int port = 80;
    std::string index = "";
    std::string root = "";
    std::string log = "";
    struct Domain domain;
    struct Https https;
    struct Redirect redirect;
    struct Location locations[MAXARR] = {};

    void print();
};
