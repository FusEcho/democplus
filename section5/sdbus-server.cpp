/*
 * @Description:
 * @Version:
 * @Author: gaofengdeng
 * @Date: 2020-08-20 10:50:20
 * @Company: Deepglint
 */
#include <sdbus-c++/sdbus-c++.h>
#include <string>
#include <vector>

// Yeah, global variable is ugly, but this is just an example and we want to access
// the concatenator instance from within the concatenate method handler to be able
// to emit signals.
sdbus::IObject *g_concatenator{};

std::string concatenate(const std::vector<int> numbers, const std::string &separator)
{
    // Return error if there are no numbers in the collection
    if (numbers.empty())
        throw sdbus::Error("org.sdbuscpp.Concatenator.Error", "No numbers provided");

    std::string result;
    for (auto number : numbers) {
        result += (result.empty() ? std::string() : separator) + std::to_string(number);
    }

    // Emit 'concatenated' signal
    const char *interfaceName = "org.sdbuscpp.Concatenator";
    g_concatenator->emitSignal("concatenated").onInterface(interfaceName).withArguments(result);

    return result;
}

int main(int argc, char *argv[])
{
    // Create D-Bus connection to the system bus and requests name on it.
    const char *serviceName = "org.sdbuscpp.concatenator";
    auto connection         = sdbus::createSystemBusConnection(serviceName);
    // auto connection = sdbus::createSessionBusConnection(serviceName);

    // Create concatenator D-Bus object.
    const char *objectPath = "/org/sdbuscpp/concatenator";
    auto concatenator      = sdbus::createObject(*connection, objectPath);

    g_concatenator = concatenator.get();

    // Register D-Bus methods and signals on the concatenator object, and exports the object.
    const char *interfaceName = "org.sdbuscpp.Concatenator";
    concatenator->registerMethod("concatenate").onInterface(interfaceName).implementedAs(&concatenate);
    concatenator->registerSignal("concatenated").onInterface(interfaceName).withParameters<std::string>();
    concatenator->finishRegistration();

    // Run the loop on the connection.
    connection->enterEventLoop();
}