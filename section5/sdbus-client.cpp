/*
 * @Description:
 * @Version:
 * @Author: gaofengdeng
 * @Date: 2020-08-20 10:50:31
 * @Company: Deepglint
 */
#include <iostream>
#include <sdbus-c++/sdbus-c++.h>
#include <string>
#include <unistd.h>
#include <vector>

void onConcatenated(const std::string &concatenatedString)
{
    std::cout << "Received signal with concatenated string " << concatenatedString << std::endl;
}

int main(int argc, char *argv[])
{
    // Create proxy object for the concatenator object on the server side
    const char *destinationName = "org.sdbuscpp.concatenator";
    const char *objectPath      = "/org/sdbuscpp/concatenator";
    auto concatenatorProxy = sdbus::createProxy(destinationName, objectPath);

    // Let's subscribe for the 'concatenated' signals
    const char *interfaceName = "org.sdbuscpp.Concatenator";
    concatenatorProxy->uponSignal("concatenated").onInterface(interfaceName).call([](const std::string &str) { onConcatenated(str); });
    concatenatorProxy->finishRegistration();

    std::vector<int> numbers = {1, 2, 3};
    std::string separator    = ":";

    // Invoke concatenate on given interface of the object
    {
        std::string concatenatedString;
        concatenatorProxy->callMethod("concatenate")
            .onInterface(interfaceName)
            .withArguments(numbers, separator)
            .storeResultsTo(concatenatedString);
        assert(concatenatedString == "1:2:3");
    }

    // Invoke concatenate again, this time with no numbers and we shall get an error
    {
        try {
            concatenatorProxy->callMethod("concatenate").onInterface(interfaceName).withArguments(std::vector<int>(), separator);
            assert(false);
        } catch (const sdbus::Error &e) {
            std::cerr << "Got concatenate error " << e.getName() << " with message " << e.getMessage() << std::endl;
        }
    }

    // Give sufficient time to receive 'concatenated' signal from the first concatenate invocation
    sleep(1);

    return 0;
}