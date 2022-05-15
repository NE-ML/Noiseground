#include <iostream>
#include <fstream>

#include "httpClientManager.h"

int main() {
    const std::string domainExample;
    const std::string ipExample = "0.0.0.0";
    const std::string savedPathExample = "../saved_sounds/";
    const unsigned short portExample = 80;

    HttpClientManager clientManager(domainExample, ipExample, portExample, savedPathExample);

    std::cout << "GET /sound/standard" << "\n";
    unsigned int res = clientManager.getStdSounds();
    std::cout << res;

    std::cout << "\n------------\n";

    std::cout << "GET /user/auth?login=a&password=b" << "\n";
    res = clientManager.loginUser("a", "b");
    std::cout << res << "\n";

    std::cout << "GET /user/auth?login=h&password=i" << "\n";
    res = clientManager.loginUser("h", "i");
    std::cout << res;

    std::cout << "\n------------\n";

    const std::string targetExample3 = "/user/register";

    std::cout << "POST /user/register" << "\n";
    res = clientManager.registerUser("f", "g");
    std::cout << res;

    std::cout << "\nAgain";
    res = clientManager.registerUser("f", "g");
    std::cout << "\n" << res;

    std::cout << "\n------------\n";

    std::cout << "POST /sound/upload forest1.mp3" << "\n";
    res = clientManager.uploadSound("a", "../sound_to_upload/forest1.mp3");
    std::cout << res;

    std::cout << "\nPOST /sound/upload forest2.mp3" << "\n";
    res = clientManager.uploadSound("a", "../sound_to_upload/forest2.mp3");
    std::cout << res;

    std::cout << "\n------------\n";

    std::cout << "GET /sound/get?username=a" << "\n";
    res = clientManager.getUserSounds("a");
    std::cout << res;

    std::cout << "\n------------\n";

    std::cout << "DELETE /sound/ forest1.mp3" << "\n";
    res = clientManager.deleteSound("a", "forest1.mp3");
    std::cout << res;

    return 0;
}
