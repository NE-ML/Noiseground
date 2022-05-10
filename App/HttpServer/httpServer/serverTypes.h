#ifndef HTTPCLIENT_SERVERTYPES_H
#define HTTPCLIENT_SERVERTYPES_H

#include <string>
#include <vector>

struct UserModel {};
struct SoundModel {};

struct Header
{
    std::string name;
    std::string value;
};

struct Request
{
    std::string method;
    std::string uri;
    int http_version_major;
    int http_version_minor;
    std::vector<Header> headers;
};

struct mapping {
    const char* extension;
    const char* mime_type;
} mappings[] = {
                { "gif", "image/gif" },
                { "htm", "text/html" },
                { "html", "text/html" },
                { "jpg", "image/jpeg" },
                { "png", "image/png" },
                { nullptr, nullptr } // Marks end of list.
        };

std::string extension_to_type(const std::string& extension) {
    for (mapping* m = mappings; m->extension; ++m) {
        if (m->extension == extension) {
            return m->mime_type;
        }
    }

    return "text/plain";
}

#endif //HTTPCLIENT_SERVERTYPES_H
